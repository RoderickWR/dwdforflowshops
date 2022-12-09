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

#include "gnuplot.h" //* stattdessen csv datei schreiben und in python plotten*/

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
   int nbrJobs = 4;
   int nbrMachines = 2;
   int* nvars;
   
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

   /* turn off all separation algorithms */
   SCIP_CALL( SCIPsetSeparating(scip, SCIP_PARAMSETTING_OFF, TRUE) );

   /*execmain(scip);*/
   // show every node in debug mode
   SCIP_CALL( SCIPsetIntParam(scip,"display/freq",1) );
   
   /* initialize singlePattern*/
   sPat sp1 = {0.0, 7.0}; // start time is 0 end time is 7
   sPat sp2 = {7.0, 8.0};
   sPat sp5 = {8.0, 13.0};
   sPat sp6 = {13.0, 17.0};
   sPat sp3 = {7.0, 9.0};
   sPat sp4 = {9.0, 12.0};
   sPat sp7 = {12.0, 14.0};
   sPat sp8 = {14.0, 17.0};
   
   /* ... 2 patterns */
   pat p1 = {.job[0] = sp1, .job[1] = sp2, .job[2] = sp5, .job[3] = sp6, .lastIdx = 3}; // in this pattern job 0 goes from 0 to 7 and job 1 goes from 7 to 8
   pat p2 = {.job[0] = sp3, .job[1] = sp4, .job[2] = sp7, .job[3] = sp8, .lastIdx = 3};
   /* ... and 2 lists à patterns*/
   mPats mp1 = {.mp[0] = p1, .mp[1] = p2, .lastIdx = 1}; 
   mPats mp2 = {.mp[0] = p1, .mp[1] = p2, .lastIdx = 1};

   schedule* s1; // contains a list of patterns for each machine (mp1,...mpI)
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &s1, sizeof(struct schedule)) );
   (*s1).sched[0] = mp1;
   (*s1).sched[1] = mp2;
   (*s1).lastIdx = 1;
   
 
   /* and processing times*/
   processingTimes pt1 = {.machine[0].m[0] = 7, .machine[0].m[1] = 1, .machine[0].m[2] = 5, .machine[0].m[3] = 4,.machine[0].m[4] = 1, .machine[1].m[0] = 2, .machine[1].m[1] = 3, .machine[1].m[2] = 2, .machine[1].m[3] = 3}; 

   SCIP_CALL( SCIPsetObjsense(scip, SCIP_OBJSENSE_MINIMIZE) );

   /* create structs for pointers to all variables*/
   start startTimes;
   end endTimes;
   SCIP_VAR* ptrMakespan;
   SCIP_VAR* offset[nbrMachines];
   SCIP_VARDATA*        vardata;
   int iv;
   SCIP_VAR*** lambArr;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &lambArr, nbrMachines*sizeof(SCIP_VAR**)) );
   for( iv = 0; iv< nbrMachines; ++iv ) {
      SCIP_CALL( SCIPallocBlockMemoryArray(scip, &lambArr[iv], 100*sizeof(SCIP_VAR*)) );
   }

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
      for( i = 0; i < mp1.lastIdx+1; ++i ) {
         sprintf(buf, "lambM%dP%d", iii,i);
         SCIP_VAR* var = NULL;
         // SCIP_CALL(SCIPcreateVarBasic(scip, &var, buf, 0.0, 1.0, 0.0, SCIP_VARTYPE_BINARY)); 
         SCIP_CALL( SCIPvardataCreateBinpacking(scip, &vardata, iii, s1, i) );
         SCIP_CALL( SCIPcreateVarBinpacking(scip, &var, buf, 0.0, FALSE, TRUE, vardata) );
         SCIP_CALL( SCIPaddVar(scip, var) );
         SCIP_CALL( SCIPchgVarUbLazy(scip, var, 1.0) ); // needed to change UB lazy => see binpacking example
         lambArr[iii][i] = var;
         SCIP_CALL( SCIPreleaseVar(scip, &var) );
         nvars[iii]++;
      } 
   }

   SCIP_CALL( probdataCreate(scip, &probdata, lambArr, startTimes, endTimes, nvars, nbrMachines, nbrJobs) );
   SCIP_CALL( SCIPsetProbData(scip, probdata) );

 
   /* create offset variables and set offset pointers*/
   for( iii = 0; iii< s1->lastIdx+1; ++iii ) {
      sprintf(buf, "offsetM%d", iii);
      SCIP_VAR* var = NULL;
      SCIP_CALL(SCIPcreateVarBasic(scip, &var, buf, 0.0, 50.0, 0.0, SCIP_VARTYPE_CONTINUOUS));
      offset[iii] = var;
      SCIP_CALL(SCIPaddVar(scip,var));
      SCIP_CALL( SCIPreleaseVar(scip, &var) );
      
      
   }

   /* create start variables and set start pointers*/
   for( iii = 0; iii < s1->lastIdx+1; ++iii ) {
      for( i = 0; i < nbrJobs; ++i ) {
         sprintf(buf, "startM%dJ%d", iii,i);
         SCIP_VAR* var = NULL;
         SCIP_CALL(SCIPcreateVarBasic(scip, &var, buf, 0.0, 50.0, 0.0, SCIP_VARTYPE_CONTINUOUS));
         startTimes.startOnMachine[iii].ptrStart[i] = var;
         SCIP_CALL(SCIPaddVar(scip,var));
         SCIP_CALL( SCIPreleaseVar(scip, &var) );
      /* create end variables and set end pointers*/
         sprintf(buf, "endM%dJ%d", iii,i);
         SCIP_VAR* var2 = NULL;
         SCIP_CALL(SCIPcreateVarBasic(scip, &var2, buf, 0.0, 50.0, 0.0, SCIP_VARTYPE_CONTINUOUS));
         endTimes.endOnMachine[iii].ptrEnd[i] = var2;
         SCIP_CALL(SCIPaddVar(scip,var2));
         SCIP_CALL( SCIPreleaseVar(scip, &var2) ); 
      } 
   }
   /* create makespan variable*/
   SCIP_VAR* var3 = NULL;
   SCIP_CALL(SCIPcreateVarBasic(scip, &var3, "makespan", 0.0, 50.0, 1.0, SCIP_VARTYPE_CONTINUOUS));
   ptrMakespan = var3;
   SCIP_CALL(SCIPaddVar(scip,var3));
   SCIP_CALL( SCIPreleaseVar(scip, &var3) );
       
   /* add Convexity constraint */ 
   for( iii = 0; iii < s1->lastIdx+1; ++iii ) {   
      SCIP_CONS* cons = NULL;  
      sprintf(buf, "convM%d", iii);
      SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, 1.0, 1.0));
      for( i = 0; i < mp1.lastIdx+1; ++i ) { 
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
         for( ii=0; ii< mp1.lastIdx+1; ii++) {        
            SCIP_CALL( SCIPaddCoefLinear(scip, cons, lambArr[iii][ii], s1->sched[iii].mp[ii].job[i].start) );
         }
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, startTimes.startOnMachine[iii].ptrStart[i], -1));
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
         for( ii=0; ii< mp1.lastIdx+1; ii++) {   
            SCIP_CALL( SCIPaddCoefLinear(scip, cons, lambArr[iii][ii], s1->sched[iii].mp[ii].job[i].end) );
         }
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, endTimes.endOnMachine[iii].ptrEnd[i], -1));
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, offset[iii], 1));
         SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
         SCIP_CALL(SCIPaddCons(scip,cons));
         endCons[iii*nbrJobs + i] = cons;
      }
   }
   /*add processing constraint*/   
   for( iii = 0; iii < s1->lastIdx+1; ++iii ) { 
      for( i = 0; i < nbrJobs; ++i ) {
         sprintf(buf, "processingM%dJ%d", iii,i);
         SCIP_CONS* cons = NULL;  
         SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, -pt1.machine[iii].m[i], -pt1.machine[iii].m[i]));
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, endTimes.endOnMachine[iii].ptrEnd[i], -1));
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, startTimes.startOnMachine[iii].ptrStart[i], 1));
         SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
         SCIP_CALL(SCIPaddCons(scip,cons));
      }
   }

   /*add inter machine constraint*/   
   for( iii = 0; iii < s1->lastIdx; ++iii ) { 
      for( i = 0; i < nbrJobs; ++i ) {
         sprintf(buf, "interMachineM%dJ%d", iii,i);
         SCIP_CONS* cons = NULL;  
         SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, -1e+20, 0));  
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, endTimes.endOnMachine[iii].ptrEnd[i], 1));
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, startTimes.startOnMachine[iii+1].ptrStart[i], -1));
         SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
         SCIP_CALL(SCIPaddCons(scip,cons));
         
      }
   }

   /*add makespan constraint*/   
 
   for( i = 0; i < nbrJobs; ++i ) {
      sprintf(buf, "makespan%d", i);
      SCIP_CONS* cons = NULL;  
      SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, 0, 1e+20));
      SCIP_CALL( SCIPaddCoefLinear(scip, cons, endTimes.endOnMachine[nbrMachines-1].ptrEnd[i], -1));
      SCIP_CALL( SCIPaddCoefLinear(scip, cons, ptrMakespan, 1));
      SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
      SCIP_CALL(SCIPaddCons(scip,cons));
      makespanCons[i] = cons;
   }

   SCIP_CALL( SCIPactivatePricer(scip, pricer)); 
   SCIP_CALL( SCIPpricerBinpackingActivate(scip,pt1,nbrMachines,nbrJobs,convexityCons, startCons, endCons, makespanCons, s1, lambArr,nvars)); 

   SCIPsolve(scip);

   /********************
    * Deinitialization *
    ********************/

   // for( iii = 0; iii< s1->lastIdx+1; ++iii ) {
   //    for( i = 0; i < (*s1).sched[iii].lastIdx+1; ++i ) {
   //       SCIP_CALL( SCIPreleaseVar(scip, &lambArr[iii][i]) );
   //    }
   // }

   SCIP_CALL( SCIPfree(&scip) );

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

