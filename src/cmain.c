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

   /* initialize singlePattern*/
   int nbrJobs = 2;
   int nbrMachines = 2;
   sPat sp1 = {0.0, 7.0};
   sPat sp2 = {7.0, 8.0};
   sPat sp3 = {7.0, 9.0};
   sPat sp4 = {8.0, 11.0};
   /* ... 2 patterns */
   pat p1 = {.job[0] = sp1, .job[1] = sp2, .lastIdx = 1};
   pat p2 = {.job[0] = sp3, .job[1] = sp4, .lastIdx = 1};
   /* ... and 2 lists of patterns*/
   mPats mp1 = {.mp[0] = p1, .mp[1] = p2, .lastIdx = 1};
   mPats mp2 = {.mp[0] = p1, .mp[1] = p2, .lastIdx = 1};

   schedule s1 = {.sched[0] = mp1, .sched[1] = mp2, .lastIdx = 1}; // contains a list of patterns for each machine (mp1,...mpI)
 
   /* and processing times*/
   processingTimes pt1 = {.machine[0].m[0] = 7, .machine[0].m[1] = 1, .machine[0].m[2] = 1, .machine[0].m[3] = 1,.machine[0].m[4] = 1, .machine[1].m[0] = 2, .machine[1].m[1] = 3}; 

   SCIP_CALL( SCIPsetObjsense(scip, SCIP_OBJSENSE_MINIMIZE) );

   /* create structs for pointers to all variables*/
   // lamb lambdas;
   SCIP_VAR** altLambdas[nbrMachines];
   start startTimes;
   end endTimes;
   SCIP_VAR* ptrMakespan;
   SCIP_VAR* offset[nbrMachines];
   SCIP_VARDATA**        vardata;

   /* allocate constraint arrays*/
   SCIP_CONS** convexityCons;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &convexityCons, nbrMachines) );
   SCIP_CONS** startCons;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &startCons, nbrMachines*nbrJobs) );
   SCIP_CONS** endCons;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &endCons, nbrMachines*nbrJobs) );
   SCIP_CONS** makespanCons;
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &makespanCons, nbrJobs) );

   // allocate for lambdas 100 slots per machine
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &altLambdas[0], 100) );
   SCIP_CALL( SCIPallocBlockMemoryArray(scip, &altLambdas[1], 100) );

   /* create lambda variables and set lambda pointers*/
   char buf[256];
   char* num; 
   int i = 0;
   int ii = 0;
   int iii = 0;
   for( iii = 0; iii< s1.lastIdx+1; ++iii ) {
      for( i = 0; i < mp1.lastIdx+1; ++i ) {
         sprintf(buf, "lambM%dP%d", iii,i);
         SCIP_VAR* var = NULL;
         // SCIP_CALL(SCIPcreateVarBasic(scip, &var, buf, 0.0, 1.0, 0.0, SCIP_VARTYPE_BINARY)); 
         SCIP_CALL( SCIPvardataCreateBinpacking(scip, &vardata, iii, &s1, i) );
         SCIP_CALL( SCIPcreateVarBinpacking(scip, &var, buf, 0.0, FALSE, TRUE, vardata) );
         SCIP_CALL( SCIPaddVar(scip, var) );
         SCIP_CALL( SCIPchgVarUbLazy(scip, var, 1.0) ); // needed to change UB lazy => see binpacking example
         // lambdas.lambOnMachine[iii].ptrLamb[i] = var; // NOT USED
         altLambdas[iii][i] = var; // for now we store the lambda vars in altLambda
         SCIP_CALL( SCIPreleaseVar(scip, &var) );
      } 
   }
   

   /* create offset variables and set offset pointers*/
   for( iii = 0; iii< s1.lastIdx+1; ++iii ) {
      sprintf(buf, "offsetM%d", iii);
      SCIP_VAR* var = NULL;
      SCIP_CALL(SCIPcreateVarBasic(scip, &var, buf, 0.0, 50.0, 0.0, SCIP_VARTYPE_CONTINUOUS));
      offset[iii] = var;
      SCIP_CALL(SCIPaddVar(scip,var));
      SCIP_CALL( SCIPreleaseVar(scip, &var) );
      
      
   }

   /* create start variables and set start pointers*/
   for( iii = 0; iii < s1.lastIdx+1; ++iii ) {
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
   for( iii = 0; iii < s1.lastIdx+1; ++iii ) {   
      SCIP_CONS* cons = NULL;  
      sprintf(buf, "convM%d", iii);
      SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, 1.0, 1.0));
      for( i = 0; i < mp1.lastIdx+1; ++i ) { 
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, altLambdas[iii][i], 1.0) );
      }
      SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
      SCIP_CALL(SCIPaddCons(scip,cons));
      convexityCons[iii] = cons;
   }
   /*add start time constraint*/   
   for( iii = 0; iii < s1.lastIdx+1; ++iii ) { 
      for( i = 0; i < nbrJobs; ++i ) {
         sprintf(buf, "startTimeConstrM%dJ%d", iii,i);
         SCIP_CONS* cons = NULL;  
         SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, 0.0, 0.0));
         for( ii=0; ii< mp1.lastIdx+1; ii++) {        
            // SCIP_CALL( SCIPaddCoefLinear(scip, cons, lambdas.lambOnMachine[iii].ptrLamb[ii], s1.sched[iii].mp[ii].job[i].start) );
            SCIP_CALL( SCIPaddCoefLinear(scip, cons, altLambdas[iii][ii], s1.sched[iii].mp[ii].job[i].start) );
         }
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, startTimes.startOnMachine[iii].ptrStart[i], -1));
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, offset[iii], 1));
         SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
         SCIP_CALL(SCIPaddCons(scip,cons));
         startCons[iii*nbrJobs + i] = cons;
      }
   }
   /*add end time constraint*/   
   for( iii = 0; iii < s1.lastIdx+1; ++iii ) { 
      for( i = 0; i < nbrJobs; ++i ) {
         sprintf(buf, "endTimeConstrM%dJ%d", iii,i);
         SCIP_CONS* cons = NULL;  
         SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, buf, 0, NULL, NULL, 0.0, 0.0));
         for( ii=0; ii< mp1.lastIdx+1; ii++) {   
            // SCIP_CALL( SCIPaddCoefLinear(scip, cons, lambdas.lambOnMachine[iii].ptrLamb[ii], s1.sched[iii].mp[ii].job[i].end) );
            SCIP_CALL( SCIPaddCoefLinear(scip, cons, altLambdas[iii][ii], s1.sched[iii].mp[ii].job[i].end) );
         }
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, endTimes.endOnMachine[iii].ptrEnd[i], -1));
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, offset[iii], 1));
         SCIP_CALL( SCIPsetConsModifiable(scip, cons, TRUE) );
         SCIP_CALL(SCIPaddCons(scip,cons));
         endCons[iii*nbrJobs + i] = cons;
      }
   }
   /*add processing constraint*/   
   for( iii = 0; iii < s1.lastIdx+1; ++iii ) { 
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
   for( iii = 0; iii < s1.lastIdx; ++iii ) { 
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
   SCIP_CALL( SCIPpricerBinpackingActivate(scip,pt1,nbrMachines,nbrJobs,convexityCons, startCons, endCons, makespanCons, altLambdas[0], altLambdas[1], &s1)); 


   SCIPsolve(scip);

   /********************
    * Deinitialization *
    ********************/

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

