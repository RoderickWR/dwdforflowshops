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

/**@file   branch_ryanfoster.c
 * @ingroup BRANCHINGRULES
 * @brief  Ryan/Foster branching rule
 * @author Timo Berthold
 * @author Stefan Heinz
 *
 * This file implements the Ryan/Foster branching rule. For more details see \ref BINPACKING_BRANCHING page.
 *
 * @page BINPACKING_BRANCHING Ryan/Foster branching
 *
 * Ryan/Foster branching is a very useful branching rule for the integer program model in use. A
 * standard variable branching has the disadvantage that the zero branch is more or less useless because
 * we only forbid one packing out of exponential many. On the other hand, the branch fixing a packing reduces the problem since
 * certain items are packed. This leads to a very unbalanced search tree.
 *
 * The branching rule of Ryan/Foster was itroduced in@n
 * D. M. Ryan and B. A. Foster: An Integer Programming Approach to Scheduling,
 * In Computer scheduling of public transport: Urban passenger vehicle and crew scheduling, A. Wren editor, North-Holland 1981, 269-280.
 *
 * The idea is to select a pair of items which is either a) forced to be packed together or b)
 * not allowed to be packed together. Note that in both cases, it is allowed to use packings
 * which contain none of the two items.
 *
 * There are two issues to be taken care off:
 * -# How do we select the pair of items?
 * -# How do we realize such a branching within \SCIP?
 *
 * @section BINPACKING_SELECTION How do we select the pair of items?
 *
 * To select a pair of items, we have to know for each packing the items which are contained. Since every packing is a
 * variable and each item is a set covering constraint, we have to know for each variable in which set covering
 * constraints it appears (this means, has a coefficient of 1.0). Since \SCIP is constraint based, it is in general
 * not possible to get this information directly. To overcome this issue, we use the functionality to add
 * \ref vardata_binpacking.c "variable data" to every
 * variable. This variable data contains the constraints in which this variable appears (see vardata_binpacking.c for more details).
 * With the help of the variable data, it is now possible to get the
 * information which items belong to which packing. Therefore, we can use the Ryan/Foster idea to select a pair of
 * items.
 *
 * @section BINPACKING_SAMEDIFFBRANCHING How do we realize such a branching within SCIP?
 *
 * After having selected a pair of items to branch on, the question now is how to realize such a branching with \SCIP.
 * Since \SCIP is
 * constraint based, it is really easy to do that. We implement a constraint handler which handles the
 * information, see cons_samediff.c. This constraint handler does not only store the branching
 * decisions. Furthermore, it also ensures that all packing which are not feasible at a particular node are
 * locally fixed to zero. For more details, we refer to the \ref cons_samediff.c "source code of the constraint handler".
 *
 */

/*---+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0----+----1----+----2*/

#include <assert.h>
#include <string.h>

#include "branch_ryanfoster.h"
#include "cons_samediff.h"
#include "probdata_binpacking.h"
#include "vardata_binpacking.h"

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

/**@name Branching rule properties
 *
 * @{
 */

#define BRANCHRULE_NAME            "RyanFoster"
#define BRANCHRULE_DESC            "Ryan/Foster branching rule"
#define BRANCHRULE_PRIORITY        50000
#define BRANCHRULE_MAXDEPTH        -1
#define BRANCHRULE_MAXBOUNDDIST    1.0

/**@} */

/**@name Callback methods
 *
 * @{
 */


SCIP_Bool checkAlreadyBranched(SCIP* scip, int k, int j, int mIdx) {
   SCIP_Bool alreadyBranched = FALSE;
   SCIP_NODE* iterNode = SCIPgetCurrentNode(scip);
   int iterDepth = SCIPnodeGetDepth(iterNode);
   assert(iterNode != NULL);

   int i;
   for (i=0; i < iterDepth; ++i) {
      if (iterNode->id1 == -1) {
         continue;
      }
      if (iterNode->id1 == k | iterNode->id2 == j) {
         alreadyBranched = TRUE;
         return alreadyBranched;
      }
      iterNode = SCIPnodeGetParent(iterNode);
      
   }
   return alreadyBranched;
   

}



/** branching execution method for fractional LP solutions */
static
SCIP_DECL_BRANCHEXECLP(branchExeclpRyanFoster)
{  /*lint --e{715}*/
   printf("Starting SCIP_DECL_BRANCHEXECLP()\n");
   fflush(stdout);
   SCIP_PROBDATA* probdata;
   int nbrJobs = 4;
   schedule* s1;
   int patternid;
   SCIP_Real** pairweights;
   SCIP_VAR** lpcands;
   SCIP_Real* lpcandsfrac;
   int nlpcands;
   SCIP_Real bestvalue;
   SCIP_Real value;
   SCIP_Bool alreadyBranched;
   SCIP_Bool alreadyBranchedImpl;

   SCIP_NODE* childsame;
   SCIP_NODE* childdiffer;
   SCIP_CONS* conssame;
   SCIP_CONS* consdiffer;

   SCIP_VARDATA* vardata;
   int* consids;
   int nconsids;
   int nconsids_main;
   int nitems;

   int id1;
   int id2;

   int i;
   int ii;
   int j;
   int v;

   assert(scip != NULL);
   assert(branchrule != NULL);
   assert(strcmp(SCIPbranchruleGetName(branchrule), BRANCHRULE_NAME) == 0);
   assert(result != NULL);

   SCIPdebugMsg(scip, "start branching at node %"SCIP_LONGINT_FORMAT", depth %d\n", SCIPgetNNodes(scip), SCIPgetDepth(scip));

   *result = SCIP_DIDNOTRUN;

   probdata = SCIPgetProbData(scip);
   // assert(probdata != NULL);

   // nitems = SCIPprobdataGetNItems(probdata);

   // /* allocate memory for triangle matrix */
   // SCIP_CALL( SCIPallocBufferArray(scip, &pairweights, nitems) );
   // for( i = 0; i < nitems; ++i )
   // {
   //    SCIP_CALL( SCIPallocClearBufferArray(scip, &pairweights[i], i+1) ); /*lint !e866 */
   // }

   /* get fractional LP candidates */
   SCIP_CALL( SCIPgetLPBranchCands(scip, &lpcands, NULL, &lpcandsfrac, NULL, &nlpcands, NULL) );
   assert(nlpcands > 0);
   vardata = SCIPvarGetData(lpcands[0]);
   nconsids_main = SCIPvardataGetNConsids(vardata); // finds out to which machine candidate[0] belongs to => branch on that machine
   float ratio_branches_new = 0;
   float ratio_branches = 0;
   int i_found = -1; // which is the order of jobs i,j to branch on?
   int j_found = -1;

   for( i = 0; i < nbrJobs; ++i ) {
      for( j = 0; j < nbrJobs; ++j ) {
         if( i != j ) {
            alreadyBranched = checkAlreadyBranched(scip, i,j,nconsids_main);
            if(alreadyBranched) {
               printf("alreadyBranchedIsTrue"); //this should not appear since covered by scoring system for branching cands
               fflush(stdout);
            }
            if (!(alreadyBranched)) {
               float sumrequired = 0;
               float sumforbidden = 0;
               for( v = 0; v < nlpcands; ++v ) {
                  assert(lpcands[v] != NULL);
                  vardata = SCIPvarGetData(lpcands[v]);
                  nconsids = SCIPvardataGetNConsids(vardata);
                  s1 = SCIPvardataGetSchedule(vardata);
                  patternid = SCIPvardataGetPatternid(vardata);
                  if( nconsids == nconsids_main ) {
                     SCIP_Real solval;
                     solval = lpcandsfrac[v];
                     if( s1->sched[nconsids_main].mp[patternid].job[i].start < s1->sched[nconsids_main].mp[patternid].job[j].start ) {
                        sumrequired += solval;
                     }
                     else {
                        sumforbidden += solval;
                     }
                     
                     
                  }
               }
               // after lp cands were checked compute ratio
               ratio_branches_new = fmin(sumrequired,sumforbidden)/fmax(sumrequired,sumforbidden);
            }
            if( ratio_branches_new >= ratio_branches ) {
               ratio_branches = ratio_branches_new;
               i_found = i;
               j_found = j;
       
            }
         }

      }
   }

   if (i_found == -1 & j_found == -1) {
      return SCIP_CUTOFF; // CUTOFF this node if no order to branch on
   }
   printf("i_found %d, j_found %d \n", i_found,j_found);
   fflush(stdout);
   /* create the branch-and-bound tree child nodes of the current node */
   SCIP_CALL( SCIPcreateChild(scip, &childsame, 0.0, SCIPgetLocalTransEstimate(scip)) );
   SCIP_CALL( SCIPcreateChild(scip, &childdiffer, 0.0, SCIPgetLocalTransEstimate(scip)) );

   /* create corresponding constraints */
   SCIP_CALL( SCIPcreateConsSamediff(scip, &conssame, "same", i_found, j_found, SAME, childsame, TRUE, nconsids_main) );
   SCIP_CALL( SCIPcreateConsSamediff(scip, &consdiffer, "differ", i_found, j_found, DIFFER, childdiffer, TRUE, nconsids_main) );

   // add ID info to nodes
   SCIPnodeSetIDs(childsame, i_found, j_found);
   SCIPnodeSetIDs(childdiffer, i_found, j_found);

  /* add constraints to nodes */
   SCIP_CALL( SCIPaddConsNode(scip, childsame, conssame, NULL) );
   SCIP_CALL( SCIPaddConsNode(scip, childdiffer, consdiffer, NULL) );

   /* release constraints */
   SCIP_CALL( SCIPreleaseCons(scip, &conssame) );
   SCIP_CALL( SCIPreleaseCons(scip, &consdiffer) );

  *result = SCIP_BRANCHED;
   printf("Ending SCIP_DECL_BRANCHEXECLP()\n");
   fflush(stdout);
   return SCIP_OKAY;
}

/**@} */

/**@name Interface methods
 *
 * @{
 */

/** creates the ryan foster branching rule and includes it in SCIP */
SCIP_RETCODE SCIPincludeBranchruleRyanFoster(
   SCIP*                 scip                /**< SCIP data structure */
   )
{
   SCIP_BRANCHRULEDATA* branchruledata;
   SCIP_BRANCHRULE* branchrule;

   /* create ryan foster branching rule data */
   branchruledata = NULL;
   branchrule = NULL;
   /* include branching rule */
   SCIP_CALL( SCIPincludeBranchruleBasic(scip, &branchrule, BRANCHRULE_NAME, BRANCHRULE_DESC, BRANCHRULE_PRIORITY, BRANCHRULE_MAXDEPTH,
         BRANCHRULE_MAXBOUNDDIST, branchruledata) );
   assert(branchrule != NULL);

   SCIP_CALL( SCIPsetBranchruleExecLp(scip, branchrule, branchExeclpRyanFoster) );

   return SCIP_OKAY;
}

/**@} */
