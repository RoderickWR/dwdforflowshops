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
#include <stdbool.h>

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
   double maxTime;
   int numCalls;
   SCIP**                subscip;
   SCIP_VAR***           mergedArr;
   SCIP_VAR**            startVars;
   SCIP_VAR**            endVars;
   SCIP_VAR**            orderVars;
   SCIP_Longint          tempNodeNbr; 
   int**                 pMpats_sizes;
 
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

   assert( scip != NULL );
   assert( subscip != NULL );
   assert( conshdlr != NULL );

   /* collect all branching decision constraints */
   conss = SCIPconshdlrGetConss(conshdlr);
   nconss = SCIPconshdlrGetNConss(conshdlr);

   /* loop over all branching decision constraints and apply the branching decision if the corresponding constraint is
    * active
    */
   int c;
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
         SCIP_CALL( SCIPaddCoefLinear(subscip, cons, orderVars[id1*nbrJobs + id2 + nbrJobs*nbrJobs*mIdx], 1.0) );
         SCIP_CALL(SCIPaddCons(subscip,cons));
         SCIP_CALL( SCIPreleaseCons(subscip, &cons) );
      }
      else if( type == DIFFER )
      {
         sprintf(buf, "no_precedenceJ%dJ%d", id1,id2);
         SCIP_CALL(SCIPcreateConsBasicLinear(subscip, &cons, buf, 0, NULL, NULL, 0.0, 0.0));
         SCIP_CALL( SCIPaddCoefLinear(subscip, cons, orderVars[id1*nbrJobs + id2 + nbrJobs*nbrJobs*mIdx], 1.0) );
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
   printf("Ending addFixedVarsConss()\n");
   fflush(stdout);
   return SCIP_OKAY;
}
// releases all variables of the subproblems
void releaseVars(SCIP* subscip,
               SCIP_VAR**            startVars,
               SCIP_VAR**            endVars,
               SCIP_VAR**            orderVars,
               int nbrJobs,
               int mIdx
               )
{         
   int i;
   int ii;
   for( i = 0; i < nbrJobs; i++ ) {
      SCIPreleaseVar(subscip, &startVars[i + mIdx*nbrJobs]);
      SCIPreleaseVar(subscip, &endVars[i + mIdx*nbrJobs]);
      for( ii = 0; ii < nbrJobs; ii++ ) {
         SCIPreleaseVar(subscip, &orderVars[i*nbrJobs + ii + + mIdx*nbrJobs*nbrJobs]);
      }
   }
}
// concatenates the startVars and endVars of all subproblems into one array, needed for reoptimization
static
void concatArrays(SCIP_VAR*** mergedArr, SCIP_VAR** startVars, SCIP_VAR** endVars, int nbrJobs, int nbrMachines) {
   int i = 0;
   int i2 = 0;
  
   for (i=0; i < nbrMachines; ++i ) { 
      for (i2=0; i2 < nbrJobs; ++i2 ) { 
         mergedArr[i][i2] = startVars[i2 + i*nbrJobs];
      }
      for (i2=0; i2 < nbrJobs; ++i2 ) { 
         mergedArr[i][nbrJobs + i2] = endVars[i2 + i*nbrJobs];
      }
   }
}
// creates a coefficient array from the master constraints, needed for reoptimization to change the sub objectives
static
void getCoefs(SCIP* scip, SCIP_Real* coefs,SCIP_CONS** startConss, SCIP_CONS** endConss,int nbrJobs,int mIdx) {
   int i;
   int ii;
   SCIP_Real dual;
   SCIP_Bool boundconstr;
   SCIP_Bool* pBoundconstr = &boundconstr;
   SCIP_Real* pDual = &dual;

   for( i = 0; i < nbrJobs; ++i ) {
      SCIPgetDualSolVal(scip, startConss[mIdx*nbrJobs + i], pDual, pBoundconstr);
      coefs[i] = -1*dual;
      SCIPgetDualSolVal(scip, endConss[mIdx*nbrJobs + i], pDual, pBoundconstr);
      coefs[i+ nbrJobs] = -1*dual;

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
   double maxTime;
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
   maxTime = pricerdata->maxTime;


   // SCIP_CALL( SCIPallocBufferArray(subscip, &vals, nitems) );
   /* create start and end time variables */
   int i;
   int ii;
   int iii;
   char buf[256];
   char* num; 

   for( i = 0; i < nbrJobs; ++i ) {
         /* dual value in original SCIP */
         
         SCIPgetDualSolVal(scip, startConss[mIdx*nbrJobs + i], pDual, pBoundconstr);
         sprintf(buf, "startM%dJ%d", mIdx,i);
         SCIP_VAR* var = NULL;
         SCIP_CALL(SCIPcreateVarBasic(subscip, &var, buf, 0.0, maxTime, (-1)*dual, SCIP_VARTYPE_CONTINUOUS));
         SCIP_CALL(SCIPaddVar(subscip,var));
         startVars[i+nbrJobs*mIdx] = var;
         //SCIP_CALL( SCIPreleaseVar(subscip, &var) );
      /* create end variables and set end pointers*/
         SCIPgetDualSolVal(scip, endConss[mIdx*nbrJobs + i], pDual, pBoundconstr);
         sprintf(buf, "endM%dJ%d", mIdx,i);
         SCIP_VAR* var2 = NULL;
         SCIP_CALL(SCIPcreateVarBasic(subscip, &var2, buf, 0.0, maxTime, (-1)*dual, SCIP_VARTYPE_CONTINUOUS));
         SCIP_CALL(SCIPaddVar(subscip,var2));
         endVars[i+nbrJobs*mIdx] = var2;
         //SCIP_CALL( SCIPreleaseVar(subscip, &var2) );
         for( ii = 0; ii < nbrJobs; ++ii ) {
            sprintf(buf, "orderM%dJ%dJ%d", mIdx,i,ii);
            SCIP_VAR* var3 = NULL;
            SCIP_CALL(SCIPcreateVarBasic(subscip, &var3, buf, 0.0, 1.0, 0.0, SCIP_VARTYPE_BINARY));
            SCIP_CALL(SCIPaddVar(subscip,var3));
            orderVars[i*nbrJobs + ii + nbrJobs*nbrJobs*mIdx] = var3;
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
      SCIP_CALL(SCIPcreateConsBasicLinear(subscip, &cons, buf, 0, NULL, NULL, -pt1.machine[mIdx].m[i], -pt1.machine[mIdx].m[i]));
      SCIP_CALL( SCIPaddCoefLinear(subscip, cons, startVars[i+nbrJobs*mIdx], 1.0) );
      SCIP_CALL( SCIPaddCoefLinear(subscip, cons, endVars[i+nbrJobs*mIdx], -1.0) );
      SCIP_CALL(SCIPaddCons(subscip,cons));
      SCIP_CALL( SCIPreleaseCons(subscip, &cons) );
   }

   for( i = 0; i < nbrJobs; ++i ) {
      for( ii = 0; ii < nbrJobs; ++ii ) {
         if (i != ii) {
            SCIP_CONS* cons = NULL;
            sprintf(buf, "finishStart%d%d", i,ii);
            SCIP_CALL(SCIPcreateConsBasicLinear(subscip, &cons, buf, 0, NULL, NULL, -maxTime, 1e+20));
            SCIP_CALL( SCIPaddCoefLinear(subscip, cons, startVars[ii+nbrJobs*mIdx], 1.0) );
            SCIP_CALL( SCIPaddCoefLinear(subscip, cons, endVars[i+nbrJobs*mIdx], -1.0) );
            SCIP_CALL( SCIPaddCoefLinear(subscip, cons, orderVars[i*nbrJobs + ii + nbrJobs*nbrJobs*mIdx], -maxTime) );
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
            SCIP_CALL( SCIPaddCoefLinear(subscip, cons, orderVars[i*nbrJobs + ii + nbrJobs*nbrJobs*mIdx], 1.0) );
            SCIP_CALL( SCIPaddCoefLinear(subscip, cons, orderVars[ii*nbrJobs + i + nbrJobs*nbrJobs*mIdx], 1.0) );
            SCIP_CALL(SCIPaddCons(subscip,cons));
            SCIP_CALL( SCIPreleaseCons(subscip, &cons) );
         }
      }
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

static
void writeFinalResult(SCIP* scip, SCIP_PRICERDATA* pricerdata) {
   FILE* fpt;
   SCIP_PROBDATA* probdata;
   SCIP_VAR** startArr;
   SCIP_VAR** endArr;
   int nbrJobs;
   int nbrMachines;
   int i;
   int ii;
   SCIP_SOL* sol;

   assert(scip != NULL);
   probdata = SCIPgetProbData(scip);
   startArr = probdata->startArr;
   endArr = probdata->endArr;
   nbrJobs = probdata->nbrJobs;
   nbrMachines = probdata->nbrMachines;

   sol = SCIPgetBestSol(scip);

   assert(sol != NULL);

   fpt = fopen("GanttRawData.csv", "w+");
   fprintf(fpt,"Machine,Job,Start,Finish\n"); // define header

   for (i=0; i < nbrMachines; i++) {
      for (ii=0; ii < nbrJobs; ii++) {
         // fprintf(fpt,"%d, %d, %f, %f\n", SCIPgetSolVal(scip, sol, startTimes.startOnMachine[i].ptrStart[ii]));    
         // fprintf(fpt,"%f\n", SCIPgetSolVal(scip, sol, startTimes.startOnMachine[i].ptrStart[ii]));    
         fprintf(fpt,"%d, %d, %f, %f\n", i,ii,SCIPgetSolVal(scip, sol, startArr[i*nbrJobs + ii]),SCIPgetSolVal(scip, sol, endArr[i*nbrJobs + ii])); 
      }
   }
   fclose(fpt);

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
   int nbrJobs = pricerdata->nbrJobs;
   int nbrMachines = pricerdata->nbrMachines;

   writeFinalResult(scip, pricerdata);

   /* get release constraints */
   for( c = 0; c < pricerdata->nitems; ++c )
   {
      /* release constraint */
      SCIP_CALL( SCIPreleaseCons(scip, &(pricerdata->conss[c])) );
   }
   // free the variables of the subscips
   SCIPfreeBlockMemoryArray(scip, &(pricerdata->orderVars), nbrJobs*nbrMachines);
   SCIPfreeBlockMemoryArray(scip, &(pricerdata->endVars), nbrJobs*nbrMachines );
   SCIPfreeBlockMemoryArray(scip, &(pricerdata->startVars), nbrJobs*nbrJobs*nbrMachines ); 

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
   SCIP_NODE* cNode = SCIPgetCurrentNode(scip);
   SCIP_Longint nodeNbr = SCIPnodeGetNumber(cNode);
   

   schedule* s1;
   SCIP_VAR*** lambArr;
   int* ids;
   SCIP_Bool addvar = FALSE;
   SCIP_Bool allSubsOptimal = TRUE;
   char buf[256];
   int* nvars;
   int** pMpats_sizes;

   int i = 0;
   int ii = 0;
   int iii = 0;

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
   SCIP** subscip; 
   SCIP_VAR*** mergedArr; //needed for reopt

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
   assert(pricerdata->numCalls != -1);
   pricerdata->numCalls = pricerdata->numCalls + 1;
   // use pointers stored in pricerdata 
   subscip = pricerdata->subscip;
   mergedArr = pricerdata->mergedArr;
   startVars = pricerdata->startVars;
   endVars = pricerdata->endVars;
   orderVars = pricerdata->orderVars;
   pMpats_sizes = pricerdata->pMpats_sizes; // get the pointer to the sizes array of the lambArr


   printf("numCalls: %d \n", pricerdata->numCalls);
   fflush(stdout);
   /* get the remaining time and memory limit */
   SCIP_CALL( SCIPgetRealParam(scip, "limits/time", &timelimit) );
   if( !SCIPisInfinity(scip, timelimit) )
      timelimit -= SCIPgetSolvingTime(scip);
   SCIP_CALL( SCIPgetRealParam(scip, "limits/memory", &memorylimit) );
   if( !SCIPisInfinity(scip, memorylimit) )
      memorylimit -= SCIPgetMemUsed(scip)/1048576.0;

 
   SCIP_CONS** startConss;
   SCIP_CONS** endConss;
   startConss = pricerdata->startCons;
   endConss = pricerdata->endCons;

   // helper function to compare values for quick sort
   int cmp_fnc(const void *a, const void *b) {
      struct job_weights *a1 = (struct job_weights *)a;
      struct job_weights *a2 = (struct job_weights *)b;
      if ((*a1).val < (*a2).val) {
         return 1;
      } 
      else if ((*a1).val > (*a2).val) {
         return -1;
      }
      else {
         return 0;
      } 

   }

   // helper function to make a flat list from branchingList
   bool inBl(branchingList bl1, int job) {
      if (bl1.lastIdx == 0) {
         return FALSE;
      }
      else {
         for (iii=0; iii<bl1.lastIdx+1; iii++) {
            // if (job == bl1.bl[i].id1) {
            //    return TRUE;
            // }
            if (job == bl1.bl[iii].id2) { //job j is dependending on i if of i<j
               return TRUE;
            }
            else {
               return FALSE;
            }
         }
      }
   }

   // helper function to find largest element in job_weights array
   job_weights findLargest(job_weights* list, int len) {
      job_weights max = list[0];
      for (iii=0;iii<len;iii++) {
         if (list[iii].val > max.val) {
            max = list[iii];
         }
      }
      return max;
   }

   // helper function to add element to job_weights array
   job_weights* addJob(job_weights* list, int* size, job_weights job) {
      *size +=1;
      list = (job_weights*) realloc(list,(*size)*sizeof(job_weights));  
      list[*size-1] = job; 
      return list;
   }

   // helper function to forget job in weights array
   job_weights* forgetJob(job_weights* list, int* pCounterInd, int idx) {
      printf("Forget job %d\n",idx);
      fflush(stdout);
      assert(*pCounterInd > 0);
      for (iii = 0; iii< *pCounterInd; iii++) {
         if (list[iii].idx == idx) {
            list[iii].val = -1; // set weight value to negative, so that job will not be scheduled according to Smith rule
         }
      }     
      //*pCounterInd -=1;
      return list;
   }

   // helper function to remove element to job_weights array
   job_weights* addDepJob(job_weights* indJobs, int* pCounterInd, job_weights* orgJobList, branchingList bl1, int addedIdx) {
      if (bl1.lastIdx == 0) {
         return indJobs; // if no branching constraints exist, indJob remains unchanged
      }
      int iii;
      int idxGotInd = -1;
      for (iii=0; i<bl1.lastIdx+1; iii++) {
         if (bl1.bl[iii].id1 == addedIdx) { //found a job that became independent by adding the job addedIdx to the schedule
            idxGotInd = bl1.bl[iii].id2;
         }
      }
      if (idxGotInd != -1) {
         indJobs = addJob(indJobs,pCounterInd, orgJobList[idxGotInd]);
      }
      return indJobs;
   }

   // helper function to compute the objective value given the schedule
   bool computeObj(job_weights* scheduledJobs) {
      return TRUE;
   }

   // start heuristics 
   SCIP_NODE* iterNode = SCIPgetCurrentNode(scip);

   job_weights* indJobs;
   int sizeIndJobs = 1;
   indJobs = (job_weights*) malloc(sizeof(job_weights));
   
   // heuristic computation of new schedules for each machine
   for ( i = 0; i < nbrMachines; i++ ) {
      // populate original job list, independent job list 
      branchingList bl1 = createBL(iterNode, i); // we need the already branched orders
      job_weights orgJobList[nbrJobs];
      int counterInd = 0;
      for( ii = 0; ii < nbrJobs; ii++ ) {        
         SCIPgetDualSolVal(scip, endConss[i*nbrJobs + ii], pDual, pBoundconstr);  
         orgJobList[ii].idx = ii;
         double val = (double) (-1)*dual/pt1.machine[i].m[ii];
         double objCoef = (-1)*dual;
         orgJobList[ii].val = val;
         orgJobList[ii].objCoef = objCoef;
         if  (!(inBl(bl1,ii))) {
            indJobs[counterInd].idx = ii;
            indJobs[counterInd].val = val;
            indJobs[counterInd].objCoef = objCoef;
            counterInd +=1;
            if (ii < nbrJobs -1) { // no need to increase array when last job is reached
               sizeIndJobs += 1;
               indJobs = (job_weights*) realloc(indJobs,(sizeIndJobs)*sizeof(job_weights)); // always augment array by 1 slot
            }
         }
      }
      
      // now order the jobs 
      job_weights scheduledJobs[nbrJobs];
      int addedIdx;
      for (ii=0; ii<nbrJobs; ii++) { 
         qsort(indJobs,counterInd,sizeof(indJobs[0]),cmp_fnc); // sort DESC
         scheduledJobs[ii].idx = indJobs[0].idx; //we add the most important indepent job as the first job in the list
         scheduledJobs[ii].val = indJobs[0].val; 
         scheduledJobs[ii].objCoef = indJobs[0].objCoef; 
         addedIdx = indJobs[0].idx; // we save the index of the job just added
         indJobs = forgetJob(indJobs,&counterInd,addedIdx); // and forget this job in the independent job list
         indJobs = addDepJob(indJobs, &counterInd, orgJobList, bl1, addedIdx); // and add any newly independent job to the list
      }

      // now schedule jobs with start and end times
      pat p1;
      SCIPallocBlockMemoryArray(scip, &p1.job, nbrJobs*sizeof(struct sPat)) ;
      double sum = 0;
      int nextJobIdx = -1;
      for( ii = 0; ii < nbrJobs; ii++ ) {
         nextJobIdx = scheduledJobs[ii].idx; // look up which job is scheduled next using the scheduledJobs list
         p1.job[nextJobIdx].start = sum;
         scheduledJobs[ii].start = p1.job[nextJobIdx].start;
         p1.job[nextJobIdx].end = p1.job[nextJobIdx].start + pt1.machine[i].m[nextJobIdx];
         scheduledJobs[ii].end = p1.job[nextJobIdx].end;
         sum += pt1.machine[i].m[nextJobIdx];
      }
      // this ends the heuristics part
      /* now check if the solution indicates that a new pattern should be added */         
         SCIPgetDualSolVal(scip, convexityCons[i], pDual, pBoundconstr);
         printf("dual %lf \n" , ( dual));
         fflush(stdout);  
         if( computeObj(scheduledJobs) - dual < (double) -1e-5) {
            // then add p1
            // added pattern = true
         }
   }
   // if added pattern for all machines = False
   // then do MIP search

   

   
      
   

   
   // create coefs array, needed for reopt
   SCIP_Real* coefs;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &coefs, 2*nbrJobs*sizeof(SCIP_Real)) );


   if (pricerdata->numCalls == 1 || pricerdata->tempNodeNbr != nodeNbr) {
      for ( i = 0; i < nbrMachines; i++ )
      {
         /* initialize SCIP */
         SCIP_CALL( SCIPcreate(&subscip[i]) );
         SCIP_CALL( SCIPincludeDefaultPlugins(subscip[i]) );

         /* for column generation instances, disable restarts */
         SCIP_CALL( SCIPsetIntParam(subscip[i],"presolving/maxrestarts",0) );
         SCIP_CALL( SCIPsetIntParam(subscip[i],"presolving/maxrounds",0) );
         

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

         /* creating and initializing local pricing problem */
         SCIP_CALL( initPricing(scip, pricerdata, subscip[i], vars, startVars, endVars, orderVars, i) );
      }
      concatArrays(mergedArr, startVars,endVars,nbrJobs, nbrMachines);
      // now we optimize all subs for the first time
      for ( i = 0; i < nbrMachines; i++ ) {
         SCIPdebugMsg(scip, "solve pricer problem\n");
         /* solve sub SCIP */
         SCIP_CALL( SCIPsolve(subscip[i]) );
      }
   }
   else {
      for( i = 0; i < nbrMachines; i++ ) {
         // free subproblem for reopt
         SCIP_CALL( SCIPfreeTransform(subscip[i]));
         /* add constraint of the branching decisions */
         SCIP_CALL( addBranchingDecisionConss(scip, subscip[i], vars, pricerdata->conshdlr, orderVars, nbrJobs,i) );
         // /* avoid to generate columns which are fixed to zero */
         SCIP_CALL( addFixedVarsConss(scip, subscip[i], vars, conss, nitems, i, pricerdata->lambArr, pricerdata->s1) );
         // change objective
         getCoefs(scip, coefs,startCons,endCons,nbrJobs, i);
         SCIP_CALL( SCIPchgReoptObjective(subscip[i],SCIP_OBJSENSE_MINIMIZE,mergedArr[i],coefs,nbrJobs*2));
         /* solve sub SCIP */
         SCIP_CALL( SCIPsolve(subscip[i]) );
      }
   }

   for( i = 0; i < nbrMachines; i++ ) {

      if(SCIPgetStatus(subscip[i]) != SCIP_STATUS_OPTIMAL ) {
         allSubsOptimal = FALSE; // flag if a subproblem is not optimal
         printf("Subproblem for machine %d exits that not optimal \n", i);
         fflush(stdout);
         SCIPwriteTransProblem(subscip[i], "infeasSub_trans.lp",NULL,FALSE);
         SCIPwriteOrigProblem(subscip[i], "infeasSub_org.lp",NULL,FALSE);
      }
  
      {
         SCIP_Bool feasible;
         SCIP_SOL* sol;
         // we only look at the best solution 
         sol = SCIPgetBestSol(subscip[i]);
         assert(sol != NULL);

         /* check if solution is feasible in original sub SCIP */
         SCIP_CALL( SCIPcheckSolOrig(subscip[i], sol, &feasible, FALSE, FALSE ) );

         if( !feasible )
         {
            SCIPwarningMessage(scip, "solution in pricing problem (capacity <%" SCIP_LONGINT_FORMAT ">) is infeasible\n", capacity);
            continue;
         }

         /* check if the solution indicates that a new pattern should be added */         
         SCIPgetDualSolVal(scip, convexityCons[i], pDual, pBoundconstr);
         printf("SolVal %lf \n" , ( SCIPgetSolOrigObj(subscip[i], sol)));
         printf("dual %lf \n" , ( dual));
         fflush(stdout);  
         if( SCIPgetSolOrigObj(subscip[i], sol) - dual < (double) -1e-5)
         {          
            SCIP_VAR* var;
            SCIP_VARDATA* vardata;
            s1 = pricerdata->s1;

            SCIPdebug( SCIP_CALL( SCIPprintSol(subscip[i], sol, NULL, FALSE) ) );     
            
            SCIP_VAR* newVar = NULL;
            s1->sched[i].lastIdx = s1->sched[i].lastIdx + 1; // count up the pattern counter in s1
            SCIP_CALL( SCIPvardataCreateBinpacking(scip, &vardata, i, s1, s1->sched[i].lastIdx) ); 

            sprintf(buf, "lambM%dP%d", i,s1->sched[i].lastIdx); // create name of new pattern var
            
            SCIP_CALL( SCIPcreateVarBinpacking(scip, &newVar, buf, 0.0, FALSE, TRUE, vardata) );
            SCIP_CALL( SCIPaddPricedVar(scip, newVar, 1.0) ); /* add the new variable to the pricer store */
            SCIP_CALL( SCIPchgVarUbLazy(scip, newVar, 1.0) );

            // extend lambArr if needed
            if (*(pMpats_sizes)[i] <= s1->sched[i].lastIdx) {
               SCIPreallocBlockMemoryArray(scip, &lambArr[i], *(pMpats_sizes)[i], *(pMpats_sizes)[i]*2);
               *(pMpats_sizes)[i] = *(pMpats_sizes)[i]*2;
            }
            
            lambArr[i][s1->sched[i].lastIdx] = newVar; // add the new var to the lambdas array
            SCIP_CALL( SCIPreleaseVar(scip, &newVar) );
            nvars[i]++; // increment nvars
            addvar = TRUE;
     
            // modify convexity constr on machine i in master problem
            SCIPaddCoefLinear(scip, convexityCons[i], lambArr[i][s1->sched[i].lastIdx], 1.0);
            // modify start and end time constr in master problem
            // and create new pattern
            pat p1;
            SCIPallocBlockMemoryArray(scip, &p1.job, nbrJobs*sizeof(struct sPat)) ;
            int j;
            for( j = 0; j < nbrJobs; ++j ) {
               SCIPaddCoefLinear(scip, startCons[i*nbrJobs + j], lambArr[i][s1->sched[i].lastIdx], SCIPgetSolVal(subscip[i], sol, startVars[j + i*nbrJobs]));
               p1.job[j].start = (double) SCIPgetSolVal(subscip[i], sol, startVars[j + i*nbrJobs]);
               SCIPaddCoefLinear(scip, endCons[i*nbrJobs + j], lambArr[i][s1->sched[i].lastIdx], SCIPgetSolVal(subscip[i], sol, endVars[j + i*nbrJobs]));
               p1.job[j].end = (double) SCIPgetSolVal(subscip[i], sol, endVars[j + i*nbrJobs]);
            }
            // check if pattern array needs to be extended 
            if (s1->sched[i].size <= s1->sched[i].lastIdx) {
            int newsize = s1->sched[i].size * 2;
            SCIPreallocBlockMemoryArray(scip, &(s1->sched[i].mp), s1->sched[i].size, newsize);
            s1->sched[i].size = newsize;
            }
            s1->sched[i].mp[s1->sched[i].lastIdx] = p1;
            printOutPattern(s1->sched[i].mp[s1->sched[i].lastIdx], nbrJobs);
                     
 
         }
      }
   }


   if( addvar || allSubsOptimal ) {
      // a variable was added by a sub problem or all sub problems are optimal and not variable was added
      (*result) = SCIP_SUCCESS;
      if (allSubsOptimal && !(addvar)) {
         printf("All subs are opt and no var has been added => SCIP_SUCCESS \n");
         fflush(stdout);
         // release vars of subs...[DONT RELEASE SUBSCIPS WHEN REOPT IS USED]
         // for( i = 0; i < nbrMachines; i++ ) {
         //    releaseVars(subscip[i], startVars, endVars, orderVars, nbrJobs,i);  
         //    /* ...free sub SCIPs... */
         //    SCIP_CALL( SCIPfree(&subscip[i]) );
         // }
      }
      
   } 
   // /* free pricer MIP */
   // SCIPfreeBufferArray(scip, &vars);
   pricerdata->tempNodeNbr = nodeNbr;
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
   SCIPwriteTransProblem(scip, "master.lp",NULL,FALSE);
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
   pricerdata->maxTime = 0.0;
   pricerdata->numCalls = -1;
   pricerdata->tempNodeNbr = -1;

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
   int* nvars,
   double maxTime,
   int numCalls,
   int** pMpats_sizes
   
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
   pricerdata->maxTime  = maxTime;
   pricerdata->numCalls = numCalls;
   pricerdata->pMpats_sizes = pMpats_sizes;

   SCIP** subscip;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &subscip, nbrMachines*sizeof(SCIP*)) );
   pricerdata->subscip = subscip;

   /* allocate in orginal scip, since otherwise the buffer counts in subscip are not correct */
   SCIP_VAR** startVars;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &startVars, nbrJobs*nbrMachines) ); /*allocate for start and finish vars */
   pricerdata->startVars = startVars;
   SCIP_VAR** endVars;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &endVars, nbrJobs*nbrMachines) );
   pricerdata->endVars = endVars;
   SCIP_VAR** orderVars;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &orderVars, nbrJobs*nbrJobs*nbrMachines) ); /*allocate for order vars */
   pricerdata->orderVars = orderVars;

   SCIP_VAR*** mergedArr;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &mergedArr, nbrMachines*sizeof(SCIP_VAR**)) );
   int i;
   for( i = 0; i< nbrMachines; ++i ) {
      SCIP_CALL( SCIPallocBlockMemoryArray(scip, &mergedArr[i], 2*nbrJobs*sizeof(SCIP_VAR*)) );
   }
   pricerdata->mergedArr = mergedArr;

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
