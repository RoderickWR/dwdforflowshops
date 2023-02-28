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

/**@file   Binpacking/src/cmain.c
 * @brief  Main file for binpacking pricing example
 * @author Timo Berthold
 * @author Stefan Heinz
 *
 *  This the file contains the \ref main() main function of the projects. This includes all the default plugins of
 *  \SCIP and the once which belong to that projects. After that is starts the interactive shell of \SCIP or processes
 *  the shell arguments if given.
 */
#include <stdio.h>
#include <string.h>

#include "scip/scip.h"
#include "scip/scipshell.h"
#include "scip/scipdefplugins.h"

#include "branch_ryanfoster.h"
#include "cons_samediff.h"
#include "pricer_binpacking.h"
#include "reader_bpa.h"
#include "probdata_binpacking.h"
#include "vardata_binpacking.h"
#include "FSGenerator.h"


void freeArrays(SCIP* scip, int nbrMachines, int nbrJobs, int* mPats_sizes, SCIP_VAR*** lambArr, SCIP_VAR** startArr, SCIP_VAR** endArr, int* nvars, SCIP_CONS** convexityCons, SCIP_CONS** startCons, SCIP_CONS** endCons, SCIP_CONS** makespanCons) {
   SCIPfreeBlockMemoryArray(scip, &startArr, nbrMachines*nbrJobs*sizeof(SCIP_VAR*)) ;
 
   SCIPfreeBlockMemoryArray(scip, &endArr, nbrMachines*nbrJobs*sizeof(SCIP_VAR*)) ;

   SCIPfreeBlockMemoryArray(scip, &nvars, nbrMachines*sizeof(int)) ;

   /* free constraint arrays*/
   SCIPfreeBlockMemoryArray(scip, &convexityCons, nbrMachines*sizeof(SCIP_CONS*)) ;
   SCIPfreeBlockMemoryArray(scip, &startCons, nbrMachines*nbrJobs*sizeof(SCIP_CONS*));
   SCIPfreeBlockMemoryArray(scip, &endCons, nbrMachines*nbrJobs*sizeof(SCIP_CONS*));
   SCIPfreeBlockMemoryArray(scip, &makespanCons, nbrJobs*sizeof(SCIP_CONS*)) ;

   // now free the 2 dynamic arrays for patterns again
   int iv;
   for( iv = 0; iv< nbrMachines; ++iv ) {
      SCIPfreeBlockMemoryArray(scip, &lambArr[iv], mPats_sizes[iv]*sizeof(SCIP_VAR*)) ;
   }
   SCIPfreeBlockMemoryArray(scip, &lambArr, nbrMachines*sizeof(SCIP_VAR**)) ;
   SCIPfreeBlockMemoryArray(scip, &mPats_sizes, nbrMachines*sizeof(int));
}

void releaseConss(SCIP* scip, int nbrMachines, int nbrJobs, int* mPats_sizes, SCIP_VAR*** lambArr, SCIP_VAR** startArr, SCIP_VAR** endArr, int* nvars, SCIP_CONS** convexityCons, SCIP_CONS** startCons, SCIP_CONS** endCons, SCIP_CONS** makespanCons) {
   int i;
   int ii;
   for (i=0;i<nbrMachines;i++) {
      SCIPreleaseCons(scip, &convexityCons[i]);
      for (ii=0;ii<nbrMachines;ii++) {
         SCIPreleaseCons(scip, &startCons[i*nbrJobs + ii]); 
         SCIPreleaseCons(scip, &endCons[i*nbrJobs + ii]); 
      }

   }
   for (ii=0;ii<nbrMachines;ii++) {
      SCIPreleaseCons(scip, &makespanCons[ii]);
   }  
}

/** creates a SCIP instance with default plugins, evaluates command line parameters, runs SCIP appropriately,
 *  and frees the SCIP instance
 */  
static
SCIP_RETCODE runShell(
   int                   argc,               /**< number of shell parameters */
   char**                argv,               /**< array with shell parameters */
   const char*           defaultsetname      /**< name of default settings file */
   )
{
   SCIP* scip = NULL;
   int nbrJobs = 5;
   int nbrMachines = 2;
   int* nvars; // stores the number of lambas for each machine, needed for constraint handler 
   double maxTime = 50.0; // maximum time horizon for the schedule, needed for model formulation, adjust according to nbrJobs and process times
   int mPats_initSize = 2; // initial size of pattern array for each machine
   int pT_lb = 1; // lower bound for random processing time
   int pT_ub = 10; // upper bound for random processing time
   int seed = 1000;
   
   /*********
    * Setup *
    *********/

   /* initialize SCIP */
   SCIP_CALL( SCIPcreate(&scip) );
   
   /* we explicitly enable the use of a debug solution for this main SCIP instance */
   SCIPenableDebugSol(scip);

   /* include binpacking reader */
   /*SCIP_CALL( SCIPincludeReaderBpa(scip) ); */
   /* create problem in SCIP and add non-NULL callbacks via setter functions */
   SCIP_CALL( SCIPcreateProbBasic(scip, "flowshop1") ); 
   SCIP_CALL( SCIPsetProbDelorig(scip, probdelorigBinpacking) );
   // SCIP_CALL( SCIPsetProbTrans(scip, probtransBinpacking) );
   SCIP_CALL( SCIPsetProbDeltrans(scip, probdeltransBinpacking) );
   // SCIP_CALL( SCIPsetProbInitsol(scip, probinitsolBinpacking) );
   // SCIP_CALL( SCIPsetProbExitsol(scip, probexitsolBinpacking) );



   SCIP_PROBDATA* probdata;
   
   /* include binpacking branching and branching data */
   SCIP_CALL( SCIPincludeBranchruleRyanFoster(scip) );
   SCIP_CALL( SCIPincludeConshdlrSamediff(scip) );
   
   /* include binpacking pricer  */
   SCIP_PRICER* pricer;
   SCIP_CALL( SCIPincludePricerBinpacking(scip) );
   /* activate pricer */
   pricer = SCIPfindPricer(scip, "binpacking");
   assert(pricer != NULL);
   
   /* include default SCIP plugins */
   SCIP_CALL( SCIPincludeDefaultPlugins(scip) );
 
   /* for column generation instances, disable restarts */
   SCIP_CALL( SCIPsetIntParam(scip,"presolving/maxrestarts",0) );
   SCIP_CALL( SCIPsetIntParam(scip,"presolving/maxrounds",0) );
   //SCIP_CALL( SCIPsetRealParam(scip,"limits/gap",0.05) );

   /* turn off all separation algorithms */
   SCIP_CALL( SCIPsetSeparating(scip, SCIP_PARAMSETTING_OFF, TRUE) );

   /*execmain(scip);*/
   // show every node in debug mode
   SCIP_CALL( SCIPsetIntParam(scip,"display/freq",1) );
   
   
   
   int* mPats_sizes; // keep track of #lambdas (same as nvars), however only for purpose of memory realloc
   SCIPallocBlockMemoryArray(scip, &mPats_sizes, nbrMachines*sizeof(int));

   // create a random schedule, based on random process times, save it...
   writeInitSched("initProb.txt",nbrJobs, nbrMachines, mPats_initSize, pT_ub, pT_lb, seed); // also pass upper lower bound for proc time and seed
   // and load it again
   schedule sched = readInitSched(scip, "initProb.txt", mPats_initSize, mPats_sizes);;
   processingTimes pt1 = readInitPT(scip, "initProb.txt");

   schedule* s1;
   s1 = &sched;
  
   SCIP_CALL( SCIPsetObjsense(scip, SCIP_OBJSENSE_MINIMIZE) );

   /* create structs for pointers to all variables*/
   SCIP_VAR* ptrMakespan;
   SCIP_VAR* offset[nbrMachines];
   SCIP_VARDATA*        vardata;
   int iv;
   SCIP_VAR*** lambArr;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &lambArr, nbrMachines*sizeof(SCIP_VAR**)) );
   for( iv = 0; iv< nbrMachines; ++iv ) {
      SCIP_CALL( SCIPallocBlockMemoryArray(scip, &lambArr[iv], mPats_sizes[iv]*sizeof(SCIP_VAR*)) );
   }
   SCIP_VAR** startArr;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &startArr, nbrMachines*nbrJobs*sizeof(SCIP_VAR*)) );
   SCIP_VAR** endArr;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &endArr, nbrMachines*nbrJobs*sizeof(SCIP_VAR*)) );

   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &nvars, nbrMachines*sizeof(int)) );

   /* allocate constraint arrays*/
   SCIP_CONS** convexityCons;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &convexityCons, nbrMachines*sizeof(SCIP_CONS*)) );
   SCIP_CONS** startCons;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &startCons, nbrMachines*nbrJobs*sizeof(SCIP_CONS*)) );
   SCIP_CONS** endCons;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &endCons, nbrMachines*nbrJobs*sizeof(SCIP_CONS*)) );
   SCIP_CONS** makespanCons;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &makespanCons, nbrJobs*sizeof(SCIP_CONS*)) );

   /* create lambda variables and set lambda pointers*/
   char buf[256];
   char* num; 
   int i = 0;
   int ii = 0;
   int iii = 0;
   for( iii = 0; iii< s1->lastIdx+1; ++iii ) {
      nvars[iii] = 0; //initialize number of labmdas for each machine to zero, increment in next for loop
      for( i = 0; i < s1->sched[iii].lastIdx+1; ++i ) {
         sprintf(buf, "lambM%dP%d", iii,i);
         SCIP_VAR* var = NULL;
         // SCIP_CALL(SCIPcreateVarBasic(scip, &var, buf, 0.0, 1.0, 0.0, SCIP_VARTYPE_BINARY)); 
         SCIP_CALL( SCIPvardataCreateBinpacking(scip, &vardata, iii, s1, i) );
         SCIP_CALL( SCIPcreateVarBinpacking(scip, &var, buf, 0.0, FALSE, TRUE, vardata) );
         SCIP_CALL( SCIPaddVar(scip, var) );
         SCIP_CALL( SCIPchgVarUbLazy(scip, var, 1.0) ); // needed to change UB lazy => see binpacking example
         // extend size of lambArr if needed
         if (mPats_sizes[iii] <= i) {
            SCIPreallocBlockMemoryArray(scip, &lambArr[iii], mPats_sizes[iii], mPats_sizes[iii]*2);
            mPats_sizes[iii] = mPats_sizes[iii]*2; // always double the size if needed
         }
         lambArr[iii][i] = var;
         SCIP_CALL( SCIPreleaseVar(scip, &var) );
         nvars[iii]++;
      } 
   }

   /* create offset variables and set offset pointers*/
   for( iii = 0; iii< s1->lastIdx+1; ++iii ) {
      sprintf(buf, "offsetM%d", iii);
      SCIP_VAR* var = NULL;
      SCIP_CALL(SCIPcreateVarBasic(scip, &var, buf, 0.0, maxTime, 0.0, SCIP_VARTYPE_CONTINUOUS));
      offset[iii] = var;
      SCIP_CALL(SCIPaddVar(scip,var));
      SCIP_CALL( SCIPreleaseVar(scip, &var) );
      
      
   }

   /* create start variables and set start pointers*/
   for( iii = 0; iii < s1->lastIdx+1; ++iii ) {
      for( i = 0; i < nbrJobs; ++i ) {
         sprintf(buf, "startM%dJ%d", iii,i);
         SCIP_VAR* var = NULL;
         SCIP_CALL(SCIPcreateVarBasic(scip, &var, buf, 0.0, 2*maxTime, 0.0, SCIP_VARTYPE_CONTINUOUS)); //2*maxTime to avoid infeas master
         startArr[iii*nbrJobs + i] = var;
         SCIP_CALL(SCIPaddVar(scip,var));
         SCIP_CALL( SCIPreleaseVar(scip, &var) );
      /* create end variables and set end pointers*/
         sprintf(buf, "endM%dJ%d", iii,i);
         SCIP_VAR* var2 = NULL;
         SCIP_CALL(SCIPcreateVarBasic(scip, &var2, buf, 0.0, 2*maxTime, 0.0, SCIP_VARTYPE_CONTINUOUS));
         endArr[iii*nbrJobs + i] = var2;
         SCIP_CALL(SCIPaddVar(scip,var2));
         SCIP_CALL( SCIPreleaseVar(scip, &var2) ); 
      } 
   }
   /* create makespan variable*/
   SCIP_VAR* var3 = NULL;
   SCIP_CALL(SCIPcreateVarBasic(scip, &var3, "makespan", 0.0, 2*maxTime, 1.0, SCIP_VARTYPE_CONTINUOUS));
   ptrMakespan = var3;
   SCIP_CALL(SCIPaddVar(scip,var3));
   SCIP_CALL( SCIPreleaseVar(scip, &var3) );
       
   /* add Convexity constraint */ 
   for( iii = 0; iii < s1->lastIdx+1; ++iii ) {   
      SCIP_CONS* cons = NULL;  
      sprintf(buf, "convM%d", iii);
      SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, 1.0, 1.0));
      for( i = 0; i < s1->sched[iii].lastIdx+1; ++i ) { 
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, lambArr[iii][i], 1.0) );
      }
      SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
      SCIP_CALL(SCIPaddCons(scip,cons));
      convexityCons[iii] = cons;
   }
   /*add start time constraint*/   
   for( iii = 0; iii < s1->lastIdx+1; ++iii ) { 
      for( i = 0; i < nbrJobs; ++i ) {
         sprintf(buf, "startTimeConstrM%dJ%d", iii,i);
         SCIP_CONS* cons = NULL;  
         SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, 0.0, 0.0));
         for( ii=0; ii< s1->sched[iii].lastIdx+1; ii++) {        
            SCIP_CALL( SCIPaddCoefLinear(scip, cons, lambArr[iii][ii], s1->sched[iii].mp[ii].job[i].start) );
         }
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, startArr[iii*nbrJobs + i], -1));
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, offset[iii], 1));
         SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
         SCIP_CALL(SCIPaddCons(scip,cons));
         startCons[iii*nbrJobs + i] = cons;
      }
   }
   /*add end time constraint*/   
   for( iii = 0; iii < s1->lastIdx+1; ++iii ) { 
      for( i = 0; i < nbrJobs; ++i ) {
         sprintf(buf, "endTimeConstrM%dJ%d", iii,i);
         SCIP_CONS* cons = NULL;  
         SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, 0.0, 0.0));
         for( ii=0; ii< s1->sched[iii].lastIdx+1; ii++) {   
            SCIP_CALL( SCIPaddCoefLinear(scip, cons, lambArr[iii][ii], s1->sched[iii].mp[ii].job[i].end) );
         }
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, endArr[iii*nbrJobs + i], -1));
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, offset[iii], 1));
         SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
         SCIP_CALL(SCIPaddCons(scip,cons));
         endCons[iii*nbrJobs + i] = cons;
      }
   }
   
   /*add inter machine constraint*/   
   for( iii = 0; iii < s1->lastIdx; ++iii ) { 
      for( i = 0; i < nbrJobs; ++i ) {
         sprintf(buf, "interMachineM%dJ%d", iii,i);
         SCIP_CONS* cons = NULL;  
         SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, -1e+20, 0));  
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, endArr[iii*nbrJobs + i], 1));
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, startArr[(iii+1)*nbrJobs + i], -1));
         SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
         SCIP_CALL(SCIPaddCons(scip,cons));
         
      }
   }

   /*add makespan constraint*/   
 
   for( i = 0; i < nbrJobs; ++i ) {
      sprintf(buf, "makespan%d", i);
      SCIP_CONS* cons = NULL;  
      SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, 0, 1e+20));
      SCIP_CALL( SCIPaddCoefLinear(scip, cons, endArr[(nbrMachines-1)*nbrJobs + i], -1));
      SCIP_CALL( SCIPaddCoefLinear(scip, cons, ptrMakespan, 1));
      SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
      SCIP_CALL(SCIPaddCons(scip,cons));
      makespanCons[i] = cons;
   }


   SCIP_CALL( probdataCreate(scip, &probdata, lambArr, startArr, endArr, nvars, nbrMachines, nbrJobs, maxTime, mPats_sizes) );
   SCIP_CALL( SCIPsetProbData(scip, probdata) );

   SCIP_CALL( SCIPactivatePricer(scip, pricer)); 
   SCIP_CALL( SCIPpricerBinpackingActivate(scip,pt1,nbrMachines,nbrJobs,convexityCons, startCons, endCons, makespanCons, s1, lambArr,nvars, maxTime,0,&mPats_sizes)); 

   SCIPsolve(scip);

   /********************
    * Deinitialization *
    ********************/

   // for( iii = 0; iii< s1->lastIdx+1; ++iii ) {
   //    for( i = 0; i < (*s1).sched[iii].lastIdx+1; ++i ) {
   //       SCIP_CALL( SCIPreleaseVar(scip, &lambArr[iii][i]) );
   //    }
   // }

   // print statistics
   //SCIPprintStatistics(scip, NULL);
   // release cons and vars
   releaseConss(scip,nbrMachines,nbrJobs, mPats_sizes, lambArr,startArr, endArr,nvars,convexityCons,startCons, endCons, makespanCons);
   printf("before freeing\n");
   fflush(stdout);  
   SCIP_CALL( SCIPfree(&scip) );
   printf("after freeing\n");
   fflush(stdout);  
   // freeArrays(scip,nbrMachines,nbrJobs, mPats_sizes, lambArr,startArr, endArr,nvars,convexityCons,startCons, endCons, makespanCons);
   
   
   BMScheckEmptyMemory();

   return SCIP_OKAY;
}

int
main(
   int                        argc,
   char**                     argv
   )
{
   SCIP_RETCODE retcode;

   retcode = runShell(argc, argv, "scip.set");
   if( retcode != SCIP_OKAY )
   {
      SCIPprintError(retcode);
      return -1;
   }

   return 0;
}

