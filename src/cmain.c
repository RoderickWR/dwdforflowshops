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
   SCIP_CALL( SCIPincludePricerBinpacking(scip) );

   /* include default SCIP plugins */
   SCIP_CALL( SCIPincludeDefaultPlugins(scip) );
 
   /* for column generation instances, disable restarts */
   SCIP_CALL( SCIPsetIntParam(scip,"presolving/maxrestarts",0) );

   /* turn off all separation algorithms */
   SCIP_CALL( SCIPsetSeparating(scip, SCIP_PARAMSETTING_OFF, TRUE) );


   typedef struct singlePattern {
      double start;
      double end;   
   } singlePattern;
   
   typedef struct machinePatterns {
      singlePattern patterOnMachine1[5];
      int lastPatternIdx1;
      singlePattern patterOnMachine2[5];
      int lastPatternIdx2;
   } machinePatterns;

   
   int nbrJobs = 2;
   singlePattern sp1 = {0.0, 7.0};
   singlePattern sp2 = {7.0, 8.0};

   machinePatterns mp1 = {.patterOnMachine1[0] = sp1, .patterOnMachine1[1] = sp2, .lastPatternIdx1 = 1 , .patterOnMachine2[0] = sp1, .patterOnMachine2[1] = sp2, .lastPatternIdx2 = 1};
 
   SCIP_CALL( SCIPsetObjsense(scip, SCIP_OBJSENSE_MINIMIZE) );

   SCIP_VAR *ptrLamb[5];
   SCIP_VAR *ptrStart[5];
   SCIP_VAR *ptrFinish[5];

   char buf[256];
   char *num; 
   int i = 0;
   for( i = 0; i < mp1.lastPatternIdx1+1; ++i ) {
      asprintf(&num, "%d", i);
      strcat(strcpy(buf, "lamb"), num);
      SCIP_VAR* var = NULL;
      SCIP_CALL(SCIPcreateVarBasic(scip, &var, buf, 0.0, 1.0, 1.0, SCIP_VARTYPE_BINARY));
      ptrLamb[i] = var;
      SCIP_CALL(SCIPaddVar(scip,var));
   } 


   for( i = 0; i < nbrJobs; ++i ) {
      asprintf(&num, "%d", i);
      strcat(strcpy(buf, "start"), num);
      SCIP_VAR* var = NULL;
      SCIP_CALL(SCIPcreateVarBasic(scip, &var, buf, 0.0, 50.0, 0.0, SCIP_VARTYPE_CONTINUOUS));
      ptrStart[i] = var;
      SCIP_CALL(SCIPaddVar(scip,var));

      strcat(strcpy(buf, "finish"), num);
      SCIP_VAR* var2 = NULL;
      SCIP_CALL(SCIPcreateVarBasic(scip, &var2, buf, 0.0, 50.0, 0.0, SCIP_VARTYPE_CONTINUOUS));
      ptrFinish[i] = var2;
      SCIP_CALL(SCIPaddVar(scip,var2));
   } 

   SCIP_VAR* var3 = NULL;
   SCIP_CALL(SCIPcreateVarBasic(scip, &var3, "makespan", 0.0, 50.0, 1.0, SCIP_VARTYPE_CONTINUOUS));
   SCIP_CALL(SCIPaddVar(scip,var3));
       
   /* Convexity constraint */    
   SCIP_CONS* cons = NULL;  
   SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, "conv", 0, NULL, NULL, 1.0, 1.0));
   for( i = 0; i < mp1.lastPatternIdx1+1; ++i ) {
      
      {
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, ptrLamb[i], 1.0) );
      }
      SCIP_CALL(SCIPaddCons(scip,cons));
   }

   /*Start time constraint*/
   
   int ii = 0;
   for( i = 0; i < nbrJobs+1; ++i ) {
      SCIP_CONS* cons = NULL;  
      SCIP_CALL(SCIPcreateConsBasicLinear(scip, &cons, "conv", 0, NULL, NULL, 1.0, 1.0));
      for( ii=0; ii< mp1.lastPatternIdx1+1; ii++) {
         {
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, ptrLamb[ii], mp1.patterOnMachine1[ii].start) );
         SCIP_CALL( SCIPaddCoefLinear(scip, cons, ptrStart[ii], -1));
         }

         
      }
      
      SCIP_CALL(SCIPaddCons(scip,cons));
   }


   SCIPsolve(scip);

   SCIPwriteOrigProblem(scip,"test.lp",NULL,FALSE);



   /**********************************
    * Process command line arguments *
    **********************************/
   SCIP_CALL( SCIPprocessShellArguments(scip, argc, argv, defaultsetname) );

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

