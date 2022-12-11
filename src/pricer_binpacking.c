/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*                  This file is part of the program and library             */
/*         SCIP --- Solving Constraint Integer Programs                      */
/*                                                                           */
/*    Copyright (C) 2002-2022 Konrad-Zuse-Zentrum                            */
/*                            fuer Informationstechnik Berlin                */
/*                                                                           */
/*  SCIP is distributed under the terms of the ZIB Academic License.         */
/*                                                                           */
/*  You should have received a copy of the ZIB Academic License              */
/*  along with SCIP; see the file COPYING. If not visit scipopt.org.         */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**@file   pricer_binpacking.c
 * @brief  Binpacking variable pricer
 * @author Timo Berthold
 * @author Stefan Heinz
 *
 * This file implements the variable pricer which check if variables exist with negative reduced cost. See
 * @ref BINPACKING_PRICER for more details.
 *
 * @page BINPACKING_PRICER Pricing new variables
 *
 * The task of the pricer is to search for new variables with negative reduced costs. For this, the following integer
 * program is solved:
 *
 *  \f[
 *  \begin{array}[t]{rll}
 *       \max & \displaystyle \sum_{i=1}^n (\lambda_S)_i y^\star_i\\
 *        & \\
 *        subject \ to & \displaystyle \sum_{i=0}^n (\lambda_S)_i s_i \leq \kappa \\
 *        & \\
 *        & (\lambda_S)_i \in \{0,1\} & \quad \forall i \in \{ 1, \dots , n \} \\
 *  \end{array}
 * \f]
 *
 * where \f$ (\lambda_S)_i \f$ for \f$i\in\{1,\dots,n\}\f$ are binary variables and \f$y^\star_i\f$ given by the dual
 * solution of the restricted master problem. See the \ref BINPACKING_PROBLEM "problem description" for more details.
 *
 * To solve the above integer program, we create a new SCIP instance within SCIP and use the usual functions to create
 * variables and constraints. Besides, we need the current dual solutions to all set covering constraints (each stands
 * for one item) which are the objective coefficients of the binary variables. Therefore, we use the function
 * SCIPgetDualsolSetppc() which returns the dual solutions for the given set covering constraint.
 *
 * Since we also want to generate new variables during search, we have to care that we do not generate variables over
 * and over again. For example, if we branched or fixed a certain packing to zero, we have to make sure that we do not
 * generate the corresponding variables at that node again. For this, we have to add constraints forbidding to generate
 * variables which are locally fixed to zero. See the function addFixedVarsConss() for more details. While using the
 * \ref BINPACKING_BRANCHING "Ryan/Foster branching", we also have to ensure that these branching decisions are respected. This is
 * realized within the function addBranchingDecisionConss().
 *
 * @note In case of this binpacking example, the master LP should not get infeasible after branching, because of the way
 *       branching is performed. Therefore, the Farkas pricing is not implemented.
 *       1. In case of Ryan/Foster branching, the two items are selected in a way such that the sum of the LP values of
 *          all columns/packings containing both items is fractional. Hence, it exists at least one column/packing which
 *          contains both items and also at least one column/packing for each item containing this but not the other
 *          item. That means, branching in the "same" direction stays LP feasible since there exists at least one
 *          column/packing with both items and branching in the "differ" direction stays LP feasible since there exists
 *          at least one column/packing containing one item, but not the other.
 *       2. In case of variable branching, we only branch on fractional variables. If a variable is fixed to one, there
 *          is no issue.  If a variable is fixed to zero, then we know that for each item which is part of that
 *          column/packing, there exists at least one other column/packing containing this particular item due to the
 *          covering constraints.
 */

/*---+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0----+----1----+----2*/

#include <assert.h>
#include <string.h>

#include "scip/cons_knapsack.h"
#include "scip/cons_logicor.h"
#include "scip/cons_setppc.h"
#include "scip/cons_varbound.h"
#include "scip/scipdefplugins.h"

#include "cons_samediff.h"
#include "pricer_binpacking.h"
#include "probdata_binpacking.h"
#include "vardata_binpacking.h"
#include "printOut.h"

/**@name Pricer properties
 *
 * @{
 */

#define PRICER_NAME            "binpacking"
#define PRICER_DESC            "pricer for binpacking tours"
#define PRICER_PRIORITY        0
#define PRICER_DELAY           TRUE     /* only call pricer if all problem variables have non-negative reduced costs */

/**@} */


/*
 * Data structures
 */

/** @brief Variable pricer data used in the \ref pricer_binpacking.c "pricer" */
struct SCIP_PricerData
{
   
   SCIP_CONSHDLR*        conshdlr;           /**< comstraint handler for "same" and "diff" constraints */
   SCIP_CONS**           conss;              /**< set covering constraints for the items */
   SCIP_Longint*         weights;            /**< weight of the items */
   int*                  ids;                /**< array of item ids */
   int                   nitems;             /**< number of items to be packed */
   SCIP_Longint          capacity;           /**< capacity of the bins */
   processingTimes       pt1;                /**< struct of processing times */
   int                   nbrMachines;
   int                   nbrJobs;
   SCIP_CONS**           convexityCons;
   SCIP_CONS**           startCons;
   SCIP_CONS**           endCons;
   SCIP_CONS**           makespanCons;
   schedule* s1;
   SCIP_VAR*** lambArr;
   int* nvars;
 
};


struct SCIP_ConsData
{
   int                   itemid1;            /**< item id one */
   int                   itemid2;            /**< item id two */
   CONSTYPE              type;               /**< stores whether the items have to be in the SAME or DIFFER packing */
   int                   npropagatedvars;    /**< number of variables that existed, the last time, the related node was
                                              *   propagated, used to determine whether the constraint should be
                                              *   repropagated*/
   int                   npropagations;      /**< stores the number propagations runs of this constraint */
   unsigned int          propagated:1;       /**< is constraint already propagated? */
   SCIP_NODE*            node;               /**< the node in the B&B-tree at which the cons is sticking */
   int                   machineIdx;
};
/**@name Local methods
 *
 * @{
 */

/** add branching decisions constraints to the sub SCIP */
static
SCIP_RETCODE addBranchingDecisionConss(
   SCIP*                 scip,               /**< SCIP data structure */
   SCIP*                 subscip,            /**< pricing SCIP data structure */
   SCIP_VAR**            vars,               /**< variable array of the subscuip oder variables */
   SCIP_CONSHDLR*        conshdlr,            /**< constraint handler for branching data */
   SCIP_VAR**            orderVars,
   id_t                  nbrJobs,
   int                   mIdx
   )
{
   printf("Starting addBranchingDecisionConss()\n");
   fflush(stdout);
   SCIP_CONS** conss;
   SCIP_CONS* cons;
   int nconss;
   int id1;
   int id2;
   CONSTYPE type;
   char buf[256];
   SCIP_CONSDATA* consdata;

   SCIP_Real vbdcoef;
   SCIP_Real lhs;
   SCIP_Real rhs;

   int c;

   assert( scip != NULL );
   assert( subscip != NULL );
   assert( conshdlr != NULL );

   /* collect all branching decision constraints */
   conss = SCIPconshdlrGetConss(conshdlr);
   nconss = SCIPconshdlrGetNConss(conshdlr);

   /* loop over all branching decision constraints and apply the branching decision if the corresponding constraint is
    * active
    */
   for( c = 0; c < nconss; ++c )
   {
      cons = conss[c];
      assert(cons != NULL);
      consdata = SCIPconsGetData(cons);
      assert(consdata != NULL);

      
      /* ignore constraints which are not active since these are not laying on the current active path of the search
       * tree and ignore if constraint active but on a different machine 
       */
      if( !SCIPconsIsActive(cons) || (consdata->machineIdx != mIdx))
         continue;

      /* collect the two item ids and the branching type (SAME or DIFFER) on which the constraint branched */
      id1 = SCIPgetItemid1Samediff(scip, cons);
      id2 = SCIPgetItemid2Samediff(scip, cons);
      type = SCIPgetTypeSamediff(scip, cons);

      SCIPdebugMsg(scip, "create varbound for %s(%d,%d)\n", type == SAME ? "same" : "diff",
         SCIPprobdataGetIds(SCIPgetProbData(scip))[id1], SCIPprobdataGetIds(SCIPgetProbData(scip))[id2]);

      /* depending on the branching type select the correct left and right hand side for the linear constraint which
       * enforces this branching decision in the pricing problem MIP
       */
      if( type == SAME )
      {
         
         sprintf(buf, "yes_precedenceJ%dJ%d", id1,id2);
         SCIP_CALL(SCIPcreateConsBasicLinear(subscip, &cons, buf, 0, NULL, NULL, 1.0, 1.0));
         SCIP_CALL( SCIPaddCoefLinear(subscip, cons, orderVars[id1*nbrJobs + id2], 1.0) );
         SCIP_CALL(SCIPaddCons(subscip,cons));
         SCIP_CALL( SCIPreleaseCons(subscip, &cons) );
      }
      else if( type == DIFFER )
      {
         sprintf(buf, "no_precedenceJ%dJ%d", id1,id2);
         SCIP_CALL(SCIPcreateConsBasicLinear(subscip, &cons, buf, 0, NULL, NULL, 0.0, 0.0));
         SCIP_CALL( SCIPaddCoefLinear(subscip, cons, orderVars[id1*nbrJobs + id2], 1.0) );
         SCIP_CALL(SCIPaddCons(subscip,cons));
         SCIP_CALL( SCIPreleaseCons(subscip, &cons) );
      }
      else
      {
         SCIPerrorMessage("unknow constraint type <%d>\n", type);
         return SCIP_INVALIDDATA;
      }
      SCIPdebugPrintCons(subscip, cons, NULL);

   }
   printf("Ending addBranchingDecisionConss()\n");
   fflush(stdout);
   return SCIP_OKAY;
}

/** avoid to generate columns which are fixed to zero; therefore add for each variable which is fixed to zero a
 *  corresponding logicor constraint to forbid this column
 *
 * @note variable which are fixed locally to zero should not be generated again by the pricing MIP
 */
static
SCIP_RETCODE addFixedVarsConss(
   SCIP*                 scip,               /**< SCIP data structure */
   SCIP*                 subscip,            /**< pricing SCIP data structure */
   SCIP_VAR**            vars,               /**< variable array of the subscuip */
   SCIP_CONS**           conss,              /**< array of setppc constraint for each item one */
   int                   nitems,              /**< number of items */
   int                   mIdx,
   SCIP_VAR***           lambArr,
   schedule*             s1
   )
{
   printf("Starting addFixedVarsConss()\n");
   fflush(stdout);
   // not needed since patterns that were fixed to zero should not be generated again due to branching constraints
   // what is needed is the fixToZero function that reduces the pool of patterns in the MP after a branching decision (=> RMP)
   // SCIP_VAR** origvars;
   // int norigvars;

   // SCIP_CONS* cons;
   // int* consids;
   // int nconsids;
   // int consid;
   // int nvars2;

   // SCIP_VAR** logicorvars;
   // SCIP_VAR* var;
   // SCIP_VARDATA* vardata;
   // SCIP_Bool needed;
   // int nlogicorvars;

   // int v;
   // int c;
   // int o;

   // // /* collect all variable which are currently existing */
   // // origvars = SCIPgetVars(scip);
   // // norigvars = SCIPgetNVars(scip);

   // /* loop over all these variables and check if they are fixed to zero */
   // for( v = 0; v < s1->sched[mIdx].lastIdx; ++v )
   // {
   //    assert(SCIPvarGetType(lambArr[mIdx][v]) == SCIP_VARTYPE_BINARY);

   //    /* if the upper bound is smaller than 0.5 if follows due to the integrality that the binary variable is fixed to zero */
   //    if( SCIPvarGetUbLocal(origvars[v]) < 0.5 ) // TODO for those variables add order costraint to sub
   //    {
   //       SCIPdebugMsg(scip, "variable <%s> glb=[%.15g,%.15g] loc=[%.15g,%.15g] is fixed to zero\n",
   //          SCIPvarGetName(lambArr[mIdx][v]), SCIPvarGetLbGlobal(lambArr[mIdx][v]), SCIPvarGetUbGlobal(lambArr[mIdx][v]),
   //          SCIPvarGetLbLocal(lambArr[mIdx][v]), SCIPvarGetUbLocal(lambArr[mIdx][v]) );

   //       /* coolect the constraints/items the variable belongs to */
   //       vardata = SCIPvarGetData(lambArr[mIdx][v]); // DWDforFlowshop implementation ends here for now
   //       nconsids = SCIPvardataGetNConsids(vardata);
   //       consids = SCIPvardataGetConsids(vardata);
   //       needed = TRUE;

   //       SCIP_CALL( SCIPallocBufferArray(subscip, &logicorvars, nitems) );
   //       nlogicorvars = 0;
   //       consid = consids[0];
   //       nvars2 = 0;

   //       /* loop over these items and create a linear (logicor) constraint which forbids this item combination in the
   //        * pricing problem; thereby check if this item combination is already forbidden
   //        */
   //       for( c = 0, o = 0; o < nitems && needed; ++o )
   //       {
   //          assert(o <= consid);
   //          cons = conss[o];

   //          if( SCIPconsIsEnabled(cons) )
   //          {
   //             assert( SCIPgetNFixedonesSetppc(scip, cons) == 0 );

   //             var = vars[nvars2];
   //             nvars2++;
   //             assert(var != NULL);

   //             if( o == consid )
   //             {
   //                SCIP_CALL( SCIPgetNegatedVar(subscip, var, &var) );
   //             }

   //             logicorvars[nlogicorvars] = var;
   //             nlogicorvars++;
   //          }
   //          else if( o == consid )
   //             needed = FALSE;

   //          if( o == consid )
   //          {
   //             c++;
   //             if ( c == nconsids )
   //                consid = nitems + 100;
   //             else
   //             {
   //                assert(consid < consids[c]);
   //                consid = consids[c];
   //             }
   //          }
   //       }

   //       if( needed )
   //       {
   //          SCIP_CALL( SCIPcreateConsBasicLogicor(subscip, &cons, SCIPvarGetName(origvars[v]), nlogicorvars, logicorvars) );
   //          SCIP_CALL( SCIPsetConsInitial(subscip, cons, FALSE) );

   //          SCIP_CALL( SCIPaddCons(subscip, cons) );
   //          SCIP_CALL( SCIPreleaseCons(subscip, &cons) );
   //       }

   //       SCIPfreeBufferArray(subscip, &logicorvars);
   //    }
   // }
   printf("Ending addFixedVarsConss()\n");
   fflush(stdout);
   return SCIP_OKAY;
}

SCIP_Real getPattern(
   SCIP* subscip,
   SCIP_SOL* sol,
   SCIP_Real** sTimes,
   SCIP_Real** cTimes,
   SCIP_VAR**            startVars,
   SCIP_VAR**            endVars,
   int nbrJobs
   )
{
   int i;
   SCIP_Real altStartingTimes;
   for( i = 0; i < nbrJobs; ++i ) {
      SCIP_Real r1;
      r1 = SCIPgetSolVal(subscip, sol, startVars[i]);
      sTimes[i] = &r1;
      altStartingTimes = r1;
      SCIP_Real r2;
      r2 = SCIPgetSolVal(subscip, sol, endVars[i]);
      cTimes[i] = &r2;
   }
   return altStartingTimes;
}

void releaseVars(SCIP* subscip,
               SCIP_VAR**            startVars,
               SCIP_VAR**            endVars,
               SCIP_VAR**            orderVars,
               int nbrJobs)
{         
   int i;
   int ii;
   for( i = 0; i < nbrJobs; i++ ) {
      SCIPreleaseVar(subscip, &startVars[i]);
      SCIPreleaseVar(subscip, &endVars[i]);
      for( ii = 0; ii < nbrJobs; ii++ ) {
         SCIPreleaseVar(subscip, &orderVars[i*nbrJobs + ii]);
      }
   }
}

/** initializes the pricing problem for the given capacity */
static
SCIP_RETCODE initPricing(
   SCIP*                 scip,               /**< SCIP data structure */
   SCIP_PRICERDATA*      pricerdata,         /**< pricer data */
   SCIP*                 subscip,            /**< pricing SCIP data structure */
   SCIP_VAR**            vars,               /**< variable array for the items */
   SCIP_VAR**            startVars,
   SCIP_VAR**            endVars,
   SCIP_VAR**            orderVars,
   int                   mIdx
   )
{
   printf("Starting initPricing()\n");
   fflush(stdout);
   SCIP_CONS** conss;
   SCIP_Longint* vals;
   SCIP_CONS* cons;
   SCIP_VAR* var;
   SCIP_Longint* weights;
   SCIP_Longint capacity;
   SCIP_Real dual;
   SCIP_Bool boundconstr;

   int nitems;
   int nvars2;
   int c;

   SCIP_CONS** convexityConss;
   SCIP_CONS** startConss;
   SCIP_CONS** endConss;
   SCIP_CONS** makespanConss;
   int nbrMachines;
   int nbrJobs;
   SCIP_Bool* pBoundconstr = &boundconstr;
   SCIP_Real* pDual = &dual;

   processingTimes pt1;

   assert( SCIPgetStage(subscip) == SCIP_STAGE_PROBLEM );
   assert(pricerdata != NULL);

   nitems = pricerdata->nitems;
   conss = pricerdata->conss;
   weights = pricerdata->weights;
   capacity = pricerdata->capacity;
   pt1 = pricerdata->pt1;
   nvars2 = 0;
   convexityConss = pricerdata->convexityCons;
   startConss = pricerdata->startCons;
   endConss = pricerdata->endCons;
   makespanConss = pricerdata->makespanCons;
   nbrMachines = pricerdata->nbrMachines;
   nbrJobs = pricerdata->nbrJobs;


   // SCIP_CALL( SCIPallocBufferArray(subscip, &vals, nitems) );
   /* create start and end time variables */
   int i;
   int ii;
   int iii;
   char buf[256];
   char* num; 
   for( i = 0; i < nbrJobs; ++i ) {
         /* dual value in original SCIP */
         
         SCIPgetDualSolVal(scip, startConss[mIdx*nbrMachines + i], pDual, pBoundconstr);
         sprintf(buf, "startM%dJ%d", mIdx,i);
         SCIP_VAR* var = NULL;
         SCIP_CALL(SCIPcreateVarBasic(subscip, &var, buf, 0.0, 50.0, (-1)*dual, SCIP_VARTYPE_CONTINUOUS));
         SCIP_CALL(SCIPaddVar(subscip,var));
         startVars[i] = var;
         //SCIP_CALL( SCIPreleaseVar(subscip, &var) );
      /* create end variables and set end pointers*/
         SCIPgetDualSolVal(scip, endConss[mIdx*nbrMachines + i], pDual, pBoundconstr);
         sprintf(buf, "endM%dJ%d", mIdx,i);
         SCIP_VAR* var2 = NULL;
         SCIP_CALL(SCIPcreateVarBasic(subscip, &var2, buf, 0.0, 50.0, (-1)*dual, SCIP_VARTYPE_CONTINUOUS));
         SCIP_CALL(SCIPaddVar(subscip,var2));
         endVars[i] = var2;
         //SCIP_CALL( SCIPreleaseVar(subscip, &var2) );
         for( ii = 0; ii < nbrJobs; ++ii ) {
            sprintf(buf, "orderM%dJ%dJ%d", mIdx,i,ii);
            SCIP_VAR* var3 = NULL;
            SCIP_CALL(SCIPcreateVarBasic(subscip, &var3, buf, 0.0, 1.0, 0.0, SCIP_VARTYPE_BINARY));
            SCIP_CALL(SCIPaddVar(subscip,var3));
            orderVars[i*nbrJobs + ii] = var3;
            //SCIP_CALL( SCIPreleaseVar(subscip, &var3) );
         }
      }

   /* create costraints */
   SCIP_CONS* startFinish[nbrJobs];
   SCIP_CONS* precedence[nbrJobs][nbrJobs];
   SCIP_CONS* finishStart[nbrJobs];
   for( i = 0; i < nbrJobs; ++i ) {
      SCIP_CONS* cons = NULL;  
      sprintf(buf, "startFinish%d", i);
      SCIP_CALL(SCIPcreateConsBasicLinear(subscip, &cons, buf, 0, NULL, NULL, -1e+20, -pt1.machine[mIdx].m[i]));
      SCIP_CALL( SCIPaddCoefLinear(subscip, cons, startVars[i], 1.0) );
      SCIP_CALL( SCIPaddCoefLinear(subscip, cons, endVars[i], -1.0) );
      SCIP_CALL(SCIPaddCons(subscip,cons));
      SCIP_CALL( SCIPreleaseCons(subscip, &cons) );
   }

   for( i = 0; i < nbrJobs; ++i ) {
      for( ii = 0; ii < nbrJobs; ++ii ) {
         if (i != ii) {
            SCIP_CONS* cons = NULL;
            sprintf(buf, "finishStart%d%d", i,ii);
            SCIP_CALL(SCIPcreateConsBasicLinear(subscip, &cons, buf, 0, NULL, NULL, -50.0, 1e+20));
            SCIP_CALL( SCIPaddCoefLinear(subscip, cons, startVars[ii], 1.0) );
            SCIP_CALL( SCIPaddCoefLinear(subscip, cons, endVars[i], -1.0) );
            SCIP_CALL( SCIPaddCoefLinear(subscip, cons, orderVars[i*nbrJobs + ii], -50.0) );
            SCIP_CALL(SCIPaddCons(subscip,cons));
            SCIP_CALL( SCIPreleaseCons(subscip, &cons) );
         }
         
      }
   }

   for( i = 0; i < nbrJobs; ++i ) {
      for( ii = 0; ii < nbrJobs; ++ii ) {
         if (i != ii) {
            SCIP_CONS* cons = NULL;
            sprintf(buf, "precedence%d", i);
            SCIP_CALL(SCIPcreateConsBasicLinear(subscip, &cons, buf, 0, NULL, NULL, 1.0, 1.0));
            SCIP_CALL( SCIPaddCoefLinear(subscip, cons, orderVars[i*nbrJobs + ii], 1.0) );
            SCIP_CALL( SCIPaddCoefLinear(subscip, cons, orderVars[ii*nbrJobs + i], 1.0) );
            SCIP_CALL(SCIPaddCons(subscip,cons));
            SCIP_CALL( SCIPreleaseCons(subscip, &cons) );
         }
      }
      // SCIP_CONS* cons = NULL;
      // sprintf(buf, "fixAtZero%d", i);
      // SCIP_CALL(SCIPcreateConsBasicLinear(subscip, &cons, buf, 0, NULL, NULL, -(nbrJobs-1)*50, 1e+20));
      // SCIP_CALL( SCIPaddCoefLinear(subscip, cons, startVars[i], -1.0) );
      // for (iii=0; iii < nbrJobs; ++iii) {
      //    if (iii != i) {
      //       SCIP_CALL( SCIPaddCoefLinear(subscip, cons, orderVars[i*nbrJobs + iii], -50.0) );
      //    }
      // }
      // SCIP_CALL(SCIPaddCons(subscip,cons));
      // SCIP_CALL( SCIPreleaseCons(subscip, &cons) );
   }
   
   /* add constraint of the branching decisions */
   SCIP_CALL( addBranchingDecisionConss(scip, subscip, vars, pricerdata->conshdlr, orderVars, nbrJobs,mIdx) );

   // /* avoid to generate columns which are fixed to zero */
   SCIP_CALL( addFixedVarsConss(scip, subscip, vars, conss, nitems, mIdx, pricerdata->lambArr, pricerdata->s1) );

   // SCIPfreeBufferArray(subscip, &vals);
   printf("Ending initPricing()\n");
   fflush(stdout);
   return SCIP_OKAY;
}

/**@} */

/**name Callback methods
 *
 * @{
 */

/** destructor of variable pricer to free user data (called when SCIP is exiting) */
static
SCIP_DECL_PRICERFREE(pricerFreeBinpacking)
{
   printf("Starting SCIP_DECL_PRICERFREE()\n");
   fflush(stdout);
   SCIP_PRICERDATA* pricerdata;

   assert(scip != NULL);
   assert(pricer != NULL);

   pricerdata = SCIPpricerGetData(pricer);

   if( pricerdata != NULL)
   {
      /* free memory */
      SCIPfreeBlockMemoryArrayNull(scip, &pricerdata->conss, pricerdata->nitems);
      SCIPfreeBlockMemoryArrayNull(scip, &pricerdata->weights, pricerdata->nitems);
      SCIPfreeBlockMemoryArrayNull(scip, &pricerdata->ids, pricerdata->nitems);

      SCIPfreeBlockMemory(scip, &pricerdata);
   }
   printf("Ending SCIP_DECL_PRICERFREE()\n");
   fflush(stdout);
   return SCIP_OKAY;
}


/** initialization method of variable pricer (called after problem was transformed, after master scip_solve is triggered) */
static
SCIP_DECL_PRICERINIT(pricerInitBinpacking)
{  /*lint --e{715}*/
   printf("Starting SCIP_DECL_PRICERINIT()\n");
   fflush(stdout);
   SCIP_PRICERDATA* pricerdata;
   SCIP_CONS* cons;
   int c;
   int c2;
   int nbrMachines;
   int nbrJobs;

   assert(scip != NULL);
   assert(pricer != NULL);

   pricerdata = SCIPpricerGetData(pricer);
   assert(pricerdata != NULL);
   /* get all master constraints*/
   nbrMachines = pricerdata->nbrMachines;
   nbrJobs = pricerdata->nbrJobs;
  

   /* get transformed constraints */
   for( c = 0; c < pricerdata->nitems; ++c )
   {
      cons = pricerdata->conss[c];

      /* release original constraint */
      SCIP_CALL( SCIPreleaseCons(scip, &pricerdata->conss[c]) );

      /* get transformed constraint  beim Initialisieren des Pricers muss man auf transformierte Cons umswitchen*/
      SCIP_CALL( SCIPgetTransformedCons(scip, cons, &pricerdata->conss[c]) );

      /* capture transformed constraint */
      SCIP_CALL( SCIPcaptureCons(scip, pricerdata->conss[c]) );
   }

   
   for( c = 0; c < nbrMachines; ++c) {
      cons = pricerdata->convexityCons[c];
      /* release original constraint */
      SCIP_CALL( SCIPreleaseCons(scip, &pricerdata->convexityCons[c]) );
      /* get transformed constraint  beim Initialisieren des Pricers muss man auf transformierte Cons umswitchen*/
      SCIP_CALL( SCIPgetTransformedCons(scip, cons, &pricerdata->convexityCons[c]) );
      /* capture transformed constraint */
      SCIP_CALL( SCIPcaptureCons(scip, pricerdata->convexityCons[c]) );

      for( c2 = 0; c2 < nbrJobs; ++c2) {
         cons = pricerdata->startCons[c*nbrJobs + c2];
         /* release original constraint */
         SCIP_CALL( SCIPreleaseCons(scip, &pricerdata->startCons[c*nbrJobs + c2]) );
         /* get transformed constraint  beim Initialisieren des Pricers muss man auf transformierte Cons umswitchen*/
         SCIP_CALL( SCIPgetTransformedCons(scip, cons, &pricerdata->startCons[c*nbrJobs + c2]) );
         /* capture transformed constraint */
         SCIP_CALL( SCIPcaptureCons(scip, pricerdata->startCons[c*nbrJobs + c2]) );

         cons = pricerdata->endCons[c*nbrJobs + c2];
         /* release original constraint */
         SCIP_CALL( SCIPreleaseCons(scip, &pricerdata->endCons[c*nbrJobs + c2]) );
         /* get transformed constraint  beim Initialisieren des Pricers muss man auf transformierte Cons umswitchen*/
         SCIP_CALL( SCIPgetTransformedCons(scip, cons, &pricerdata->endCons[c*nbrJobs + c2]) );
         /* capture transformed constraint */
         SCIP_CALL( SCIPcaptureCons(scip, pricerdata->endCons[c*nbrJobs + c2]) );
      }
   }
   for( c2 = 0; c2 < nbrJobs; ++c2) {
      cons = pricerdata->makespanCons[c2];
      /* release original constraint */
      SCIP_CALL( SCIPreleaseCons(scip, &pricerdata->makespanCons[c2]) );
      /* get transformed constraint  beim Initialisieren des Pricers muss man auf transformierte Cons umswitchen*/
      SCIP_CALL( SCIPgetTransformedCons(scip, cons, &pricerdata->makespanCons[c2]) );
      /* capture transformed constraint */
      SCIP_CALL( SCIPcaptureCons(scip, pricerdata->makespanCons[c2]) );
   }
   printf("Ending SCIP_DECL_PRICERINIT()\n");
   fflush(stdout);  
   return SCIP_OKAY;
}


/** solving process deinitialization method of variable pricer (called before branch and bound process data is freed) */
/* releast alle transf constraints aus pricer data*/
static
SCIP_DECL_PRICEREXITSOL(pricerExitsolBinpacking)
{
   printf("Starting SCIP_DECL_PRICEREXITSOL()\n");
   fflush(stdout);
   SCIP_PRICERDATA* pricerdata;
   int c;

   assert(scip != NULL);
   assert(pricer != NULL);

   pricerdata = SCIPpricerGetData(pricer);
   assert(pricerdata != NULL);

   /* get release constraints */
   for( c = 0; c < pricerdata->nitems; ++c )
   {
      /* release constraint */
      SCIP_CALL( SCIPreleaseCons(scip, &(pricerdata->conss[c])) );
   }
   printf("Ending SCIP_DECL_PRICEREXITSOL()\n");
   fflush(stdout);
   return SCIP_OKAY;
}


/** reduced cost pricing method of variable pricer for feasible LPs */
/* mehremals in jedem Knoten aufgerufen bis alle Pricer zufrieden sind (keine neg kosten mehr liefern)*/
static
SCIP_DECL_PRICERREDCOST(pricerRedcostBinpacking)
{  /*lint --e{715}*/
   printf("Starting DECL_PRICERREDCOST()\n");
   fflush(stdout);
   SCIP_PRICERDATA* pricerdata;
   SCIP_PROBDATA* probdata;
   SCIP_CONS** conss;
   SCIP_VAR** vars;
   SCIP_VAR** startVars;
   SCIP_VAR** endVars;
   SCIP_VAR** orderVars;
   schedule* s1;
   SCIP_VAR*** lambArr;
   int* ids;
   SCIP_Bool addvar = FALSE;
   SCIP_Bool allSubsOptimal = TRUE;
   char buf[256];

   SCIP_SOL** sols;
   int nsols;
   int s;
   int* nvars;

   int i = 0;

   int nitems;
   SCIP_Longint capacity;

   SCIP_CONS** convexityCons;
   SCIP_CONS** startCons;
   SCIP_CONS** endCons;
   SCIP_CONS** makespanCons;
   int nbrMachines;
   int nbrJobs;
   processingTimes pt1;
   SCIP_Real dual;
   SCIP_Real* pDual = &dual;
   SCIP_Bool boundconstr;
   SCIP_Bool* pBoundconstr = &boundconstr;
   
   SCIP_VAR** SFvars;
   SCIP_VAR** Ovars;

   SCIP_Real timelimit;
   SCIP_Real memorylimit;

   assert(scip != NULL);
   assert(pricer != NULL);

   (*result) = SCIP_DIDNOTRUN;

   /* get the pricer data */
   pricerdata = SCIPpricerGetData(pricer);
   assert(pricerdata != NULL);
   /* get the prob data */
   probdata = SCIPgetProbData(scip);
   assert(probdata != NULL);
   nvars = SCIPprobdataGetNVars(probdata);

   capacity = pricerdata->capacity;
   conss = pricerdata->conss;
   ids = pricerdata->ids;
   nitems = pricerdata->nitems;

   convexityCons = pricerdata->convexityCons;
   startCons = pricerdata->startCons;
   endCons = pricerdata->endCons;
   makespanCons = pricerdata->makespanCons;
   nbrMachines = pricerdata->nbrMachines;
   nbrJobs = pricerdata->nbrJobs;
   pt1 = pricerdata->pt1;
   lambArr = pricerdata->lambArr;

   SCIP* subscip[nbrJobs];
   



   /* get the remaining time and memory limit */
   SCIP_CALL( SCIPgetRealParam(scip, "limits/time", &timelimit) );
   if( !SCIPisInfinity(scip, timelimit) )
      timelimit -= SCIPgetSolvingTime(scip);
   SCIP_CALL( SCIPgetRealParam(scip, "limits/memory", &memorylimit) );
   if( !SCIPisInfinity(scip, memorylimit) )
      memorylimit -= SCIPgetMemUsed(scip)/1048576.0;

   for( i = 0; i < nbrMachines; i++ )
   {
      /* initialize SCIP */
      SCIP_CALL( SCIPcreate(&subscip[i]) );
      SCIP_CALL( SCIPincludeDefaultPlugins(subscip[i]) );

      /* create problem in sub SCIP */
      SCIP_CALL( SCIPcreateProbBasic(subscip[i], "pricing" ));
      SCIP_CALL( SCIPsetObjsense(subscip[i], SCIP_OBJSENSE_MINIMIZE) );

      /* do not abort subproblem on CTRL-C */
      SCIP_CALL( SCIPsetBoolParam(subscip[i], "misc/catchctrlc", FALSE) );

      /* disable output to console */
      SCIP_CALL( SCIPsetIntParam(subscip[i], "display/verblevel", 0) );

      /* set time and memory limit */
      SCIP_CALL( SCIPsetRealParam(subscip[i], "limits/time", timelimit) );
      SCIP_CALL( SCIPsetRealParam(subscip[i], "limits/memory", memorylimit) );
      
      /* allocate in orginal scip, since otherwise the buffer counts in subscip are not correct */
      SCIP_CALL( SCIPallocBufferArray(scip, &startVars, nbrJobs) ); /*allocate for start and finish vars */
      SCIP_CALL( SCIPallocBufferArray(scip, &endVars, nbrJobs) );
      SCIP_CALL( SCIPallocBufferArray(scip, &orderVars, nbrJobs*nbrJobs) ); /*allocate for order vars */
      

      /* creating and initializing local pricing problem */
      SCIP_CALL( initPricing(scip, pricerdata, subscip[i], vars, startVars, endVars, orderVars, i) );
      
      SCIPdebugMsg(scip, "solve pricer problem\n");
      
      /* solve sub SCIP */
      SCIP_CALL( SCIPsolve(subscip[i]) );

      SCIPwriteOrigProblem(subscip[i], "sub.lp",NULL,FALSE);

      if(SCIPgetStatus(subscip[i]) != SCIP_STATUS_OPTIMAL ) {
         allSubsOptimal = FALSE; // flag if a subproblem is not optimal
      }

      sols = SCIPgetSols(subscip[i]);
      nsols = SCIPgetNSols(subscip[i]);
   
      /* loop over all solutions and create the corresponding column to master if the reduced cost are negative for master,
      * that is the objective value i greater than 1.0
      */
      for( s = 0; s < 1; ++s ) // only use best solution 
      {
         SCIP_Bool feasible;
         SCIP_SOL* sol;

         /* the soultion should be sorted w.r.t. the objective function value */
         //assert(s == 0 || SCIPisFeasGE(subscip[i], SCIPgetSolOrigObj(subscip[i], sols[s-1]), SCIPgetSolOrigObj(subscip[i], sols[s])));

         sol = sols[s];
         assert(sol != NULL);

         /* check if solution is feasible in original sub SCIP */
         SCIP_CALL( SCIPcheckSolOrig(subscip[i], sol, &feasible, FALSE, FALSE ) );

         if( !feasible )
         {
            SCIPwarningMessage(scip, "solution in pricing problem (capacity <%" SCIP_LONGINT_FORMAT ">) is infeasible\n", capacity);
            continue;
         }

         /* check if the solution has a value greater than 1.0 */         
         SCIPgetDualSolVal(scip, convexityCons[i], pDual, pBoundconstr);
         printf("SolVal %lf \n" , ( SCIPgetSolOrigObj(subscip[i], sol)));
         printf("dual %lf \n" , ( dual));
         fflush(stdout);  
         if( SCIPgetSolOrigObj(subscip[i], sol) - dual < -1e-5)
         {          
            SCIP_VAR* var;
            SCIP_VARDATA* vardata;
            int* consids;
            SCIP_Real** startingTimes;
            SCIP_Real** completionTimes;
            SCIP_Real altStartingTimes;
            char strtmp[SCIP_MAXSTRLEN];
            char name[SCIP_MAXSTRLEN];
            int nconss;
            int o;
            int v;
            s1 = pricerdata->s1;

            SCIPdebug( SCIP_CALL( SCIPprintSol(subscip[i], sol, NULL, FALSE) ) );

            nconss = 0;
            (void) SCIPsnprintf(name, SCIP_MAXSTRLEN, "items");

            SCIP_CALL( SCIPallocBufferArray(scip, &startingTimes, nbrJobs) ); // allocates memory to store starting times of the patterns
            SCIP_CALL( SCIPallocBufferArray(scip, &completionTimes, nbrJobs) ); // for completion times

            // /* check which variables are fixed -> which item belongs to this packing */
            // for( o = 0, v = 0; o < nitems; ++o )
            // {
            //    if( !SCIPconsIsEnabled(conss[o]) )
            //       continue;
  
            //    assert(SCIPgetNFixedonesSetppc(scip, conss[o]) == 0);

            //    if( SCIPgetSolVal(subscip[i], sol, vars[v]) > 0.5 )
            //    {
            //       (void) SCIPsnprintf(strtmp, SCIP_MAXSTRLEN, "_%d", ids[o]);
            //       strcat(name, strtmp);

            //       consids[nconss] = o;
            //       nconss++;
            //    }
            //    else
            //       assert( SCIPisFeasEQ(subscip[i], SCIPgetSolVal(subscip[i], sol, vars[v]), 0.0) );

            //    v++;
            // }

            // SCIP_CALL( SCIPvardataCreateBinpacking(scip, &vardata, consids, nconss) );

            /* create variable for a new column with objective function coefficient 0.0 */
            // SCIP_CALL( SCIPcreateVarBinpacking(scip, &var, name, 1.0, FALSE, TRUE, vardata) ); /* für neue Patternvarriablen als BIN [0,1] und zusätzliche changVarLazyUB sondern  inf und hier mitteilen */
            // create new variable and adjust params
            SCIP_VAR* newVar = NULL;
            s1->sched[i].lastIdx = s1->sched[i].lastIdx + 1; // count up the pattern counter in s1
            SCIP_CALL( SCIPvardataCreateBinpacking(scip, &vardata, i, s1, s1->sched[i].lastIdx) ); 

            sprintf(buf, "lambM%dP%d", i,s1->sched[i].lastIdx); // create name of new pattern var
            
            SCIP_CALL( SCIPcreateVarBinpacking(scip, &newVar, buf, 0.0, FALSE, TRUE, vardata) );
            SCIP_CALL( SCIPaddPricedVar(scip, newVar, 1.0) ); /* add the new variable to the pricer store */
            SCIP_CALL( SCIPchgVarUbLazy(scip, newVar, 1.0) );

            lambArr[i][s1->sched[i].lastIdx] = newVar; // add the new var to the lambdas array
            SCIP_CALL( SCIPreleaseVar(scip, &newVar) );
            nvars[i]++; // increment nvars
            addvar = TRUE;
     
            // /* check which variable are fixed -> which orders belong to this packing */
            // for( v = 0; v < nconss; ++v )
            // {
            //    assert(SCIPconsIsEnabled(conss[consids[v]]));
            //    SCIP_CALL( SCIPaddCoefSetppc(scip, conss[consids[v]], var) );
            // }
            // use add coeffLinear() 
            // SCIPdebug(SCIPprintVar(scip, var, NULL) );

            // modify convexity constr on machine i in master problem
            SCIPaddCoefLinear(scip, convexityCons[i], lambArr[i][s1->sched[i].lastIdx], 1.0);
            // modify start and end time constr in master problem
            int j;
            for( j = 0; j < nbrJobs; ++j ) {
               SCIPaddCoefLinear(scip, startCons[i*nbrJobs + j], lambArr[i][s1->sched[i].lastIdx], SCIPgetSolVal(subscip[i], sol, startVars[j]));
               s1->sched[i].mp[s1->sched[i].lastIdx].job[j].start = (double) SCIPgetSolVal(subscip[i], sol, startVars[j]);
               SCIPaddCoefLinear(scip, endCons[i*nbrJobs + j], lambArr[i][s1->sched[i].lastIdx], SCIPgetSolVal(subscip[i], sol, endVars[j]));
               s1->sched[i].mp[s1->sched[i].lastIdx].job[j].end = (double) SCIPgetSolVal(subscip[i], sol, endVars[j]);
               
            }
      
            printOutPattern(s1->sched[i].mp[s1->sched[i].lastIdx], nbrJobs);
                     
            SCIPfreeBufferArray(scip, &completionTimes);
            SCIPfreeBufferArray(scip, &startingTimes);
         }
         else
            break;
      }
      // release vars of sub and release their buffers
      releaseVars(subscip[i], startVars, endVars, orderVars, nbrJobs);
      SCIPfreeBufferArray(scip, &orderVars); /*free for order vars */
      SCIPfreeBufferArray(scip, &endVars );
      SCIPfreeBufferArray(scip, &startVars ); /*free for start and finish vars */
      
      /* free sub SCIP */
      SCIP_CALL( SCIPfree(&subscip[i]) );
   }

   if( addvar || allSubsOptimal ) {
      // a variable was added by a sub problem or all sub problems are optimal and not variable was added
      if (allSubsOptimal & !(addvar)) {
      printf("All subs are opt and no var has been added => SCIP_SUCCESS \n");
      fflush(stdout);
      }
      
   } 
   (*result) = SCIP_SUCCESS;
   // /* free pricer MIP */
   // SCIPfreeBufferArray(scip, &vars);
   printf("Ending DECL_PRICERREDCOST()\n");
   fflush(stdout);
   return SCIP_OKAY;
}

/** farkas pricing method of variable pricer for infeasible LPs */ 
static /* schneidet einen Strahl im dualen Problem ab*/
SCIP_DECL_PRICERFARKAS(pricerFarkasBinpacking)
{  /*lint --e{715}*/
   /** @note In case of this binpacking example, the master LP should not get infeasible after branching, because of the
    *        way branching is performed. Therefore, the Farkas pricing is not implemented.
    *        1. In case of Ryan/Foster branching, the two items are selected in a way such that the sum of the LP values
    *           of all columns/packings containing both items is fractional. Hence, it exists at least one
    *           column/packing which contains both items and also at least one column/packing for each item containing
    *           this but not the other item. That means, branching in the "same" direction stays LP feasible since there
    *           exists at least one column/packing with both items and branching in the "differ" direction stays LP
    *           feasible since there exists at least one column/packing containing one item, but not the other.
    *        2. In case of variable branching, we only branch on fractional variables. If a variable is fixed to one,
    *           there is no issue.  If a variable is fixed to zero, then we know that for each item which is part of
    *           that column/packing, there exists at least one other column/packing containing this particular item due
    *           to the covering constraints.
    */
   SCIPwarningMessage(scip, "Current master LP is infeasible, but Farkas pricing was not implemented\n");
   SCIPABORT();

   return SCIP_OKAY; /*lint !e527*/
}

/**@} */


/**@name Interface methods
 *
 * @{
 */

/** creates the binpacking variable pricer and includes it in SCIP */
SCIP_RETCODE SCIPincludePricerBinpacking(
   SCIP*                 scip                /**< SCIP data structure */
   )
{
   SCIP_PRICERDATA* pricerdata;
   SCIP_PRICER* pricer;

   /* create binpacking variable pricer data */
   SCIP_CALL( SCIPallocBlockMemory(scip, &pricerdata) );

   pricerdata->conshdlr = SCIPfindConshdlr(scip, "samediff");
   assert(pricerdata->conshdlr != NULL);

   pricerdata->conss = NULL;
   pricerdata->weights = NULL;
   pricerdata->ids = NULL;
   pricerdata->nitems = 0;
   pricerdata->capacity = 0;
   pricerdata->convexityCons = NULL;
   pricerdata->startCons = NULL;
   pricerdata->endCons = NULL;
   pricerdata->makespanCons = NULL;
   pricerdata->nbrMachines = 0;
   pricerdata->nbrJobs = 0;
   pricerdata->lambArr = NULL;

   /* include variable pricer */
   SCIP_CALL( SCIPincludePricerBasic(scip, &pricer, PRICER_NAME, PRICER_DESC, PRICER_PRIORITY, PRICER_DELAY,
         pricerRedcostBinpacking, pricerFarkasBinpacking, pricerdata) );

   SCIP_CALL( SCIPsetPricerFree(scip, pricer, pricerFreeBinpacking) );
   SCIP_CALL( SCIPsetPricerInit(scip, pricer, pricerInitBinpacking) );
   SCIP_CALL( SCIPsetPricerExitsol(scip, pricer, pricerExitsolBinpacking) );

   /* add binpacking variable pricer parameters */
   /* TODO: (optional) add variable pricer specific parameters with SCIPaddTypeParam() here */

   return SCIP_OKAY;
}


/** added problem specific data to pricer and activates pricer */
SCIP_RETCODE SCIPpricerBinpackingActivate(
   SCIP*                 scip,               /**< SCIP data structure */
   processingTimes       pt1,                /**< struct of processing times */
   int                   nbrMachines,
   int                   nbrJobs,
   SCIP_CONS**           convexityCons,
   SCIP_CONS**           startCons,
   SCIP_CONS**           endCons,
   SCIP_CONS**           makespanCons,
   schedule* s1,
   SCIP_VAR*** lambArr,
   int* nvars
   
   )
{
   SCIP_PRICER* pricer;
   SCIP_PRICERDATA* pricerdata;
   int c;
   int c2;

   assert(scip != NULL);

   pricer = SCIPfindPricer(scip, PRICER_NAME);
   assert(pricer != NULL);

   pricerdata = SCIPpricerGetData(pricer);
   assert(pricerdata != NULL);

   pricerdata->pt1 = pt1;
   pricerdata->convexityCons = convexityCons;
   pricerdata->startCons = startCons;
   pricerdata->endCons = endCons;
   pricerdata->makespanCons = makespanCons;
   pricerdata->nbrMachines  = nbrMachines;
   pricerdata->nbrJobs  = nbrJobs;
   pricerdata->s1  = s1;
   pricerdata->lambArr  = lambArr;
   pricerdata->nvars  = nvars;
   /* capture all constraints */
   for( c = 0; c < nbrMachines; ++c )
   {
      SCIP_CALL( SCIPcaptureCons(scip, convexityCons[c]) );
     
   }

   for( c = 0; c < nbrJobs; ++c )
   {
      for( c2 = 0; c2 < nbrMachines; ++c2 )
      {
         SCIP_CALL( SCIPcaptureCons(scip, startCons[c2*nbrJobs + c]) );
         SCIP_CALL( SCIPcaptureCons(scip, endCons[c2*nbrJobs + c]) );
      }
   }

   /* activate pricer */
   SCIP_CALL( SCIPactivatePricer(scip, pricer) );

   return SCIP_OKAY;
}

/**@} */
