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

/**@file   probdata_binpacking.h
 * @brief  Problem data for binpacking problem
 * @author Timo Berthold
 * @author Stefan Heinz
 *
 * This file handles the main problem data used in that project. For more details see \ref BINPACKING_PROBLEMDATA page.
 */

/*---+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0----+----1----+----2*/

#ifndef __SCIP_PROBDATA_BINPACKING__
#define __SCIP_PROBDATA_BINPACKING__

#include "scip/scip.h"


/* typedefs for flowshop*/
/* singlePattern (sPat) struct contains start and end time of one job*/
typedef struct sPat {
   double start;
   double end;   
} sPat;

/* one pattern (pat) contains start and end time pairs of jobs*/
typedef struct pat {
   sPat* job;
   int lastIdx;
} pat;

/* one machine can have up to 50 patterns*/
typedef struct mPats {
   pat* mp;
   int lastIdx;
   int size;
} mPats;

/* all patterns of all machines (here up to 5) are stored in allPats*/
typedef struct schedule {
   mPats* sched;
   int lastIdx;
} schedule;

typedef struct processingTimesOneMachine{
   double* m;
} processingTimesOneMachine;

typedef struct processingTimes{
   processingTimesOneMachine* machine;
} processingTimes;



struct SCIP_ProbData
{
   SCIP_VAR**            vars;         /**< all exiting variables in the problem */
   SCIP_CONS**           conss;        /**< set partitioning constraints for each item exactly one */
   SCIP_Longint*         weights;      /**< array of item weights */
   int*                  ids;          /**< array of item ids */
   int                   nbrMachines;
   int                   nbrJobs;
   double                maxTime;
   int*                  nvars;        /**< number of generated variables */
   int                   varssize;     /**< size of the variable array */
   int                   nitems;       /**< number of items */
   SCIP_Longint          capacity;     /**< bin capacity */
   SCIP_VAR***           lambArr;
   SCIP_VAR**            startArr;
   SCIP_VAR**            endArr;   
   int*                  mPats_sizes;
};

/** sets up the problem data */
SCIP_RETCODE SCIPprobdataCreate(
   SCIP*                 scip,               /**< SCIP data structure */
   const char*           probname,           /**< problem name */
   int*                  ids,                /**< array of item ids */
   SCIP_Longint*         weights,            /**< array containing the item weights */
   int                   nitems,             /**< number of items */
   SCIP_Longint          capacity            /**< bin capacity */
   );

SCIP_RETCODE probdataCreate(
   SCIP*                 scip,               /**< SCIP data structure */
   SCIP_PROBDATA**       probdata,           /**< pointer to problem data */
   // SCIP_VAR**            vars,               /**< all exist variables */
   // SCIP_CONS**           conss,              /**< set partitioning constraints for each job exactly one */
   // SCIP_Longint*         weights,            /**< array containing the item weights */
   // int*                  ids,                /**< array of item ids */
   SCIP_VAR***              lambArr,
   SCIP_VAR**               startArr,
   SCIP_VAR**               endArr,
   int*                    nvars,              /**< number of variables */
   int                     nbrMachines,
   int                     nbrJobs,
   double                  maxTime,
   int*                    mPats_sizes
   // int                   nitems,             /**< number of items */
   // SCIP_Longint          capacity            /**< bin capacity */
   );


SCIP_VAR*** SCIPprobdataGetLambArr(
SCIP_PROBDATA*        probdata            /**< problem data */
);  
/** returns array of item ids */
int* SCIPprobdataGetIds(
   SCIP_PROBDATA*        probdata            /**< problem data */
   );

int  SCIPprobdataGetnbrMachines(
   SCIP_PROBDATA*        probdata            /**< problem data */
   );

/** returns array of item weights */
SCIP_Longint* SCIPprobdataGetWeights(
   SCIP_PROBDATA*        probdata            /**< problem data */
   );

/** returns number of items */
int SCIPprobdataGetNItems(
   SCIP_PROBDATA*        probdata            /**< problem data */
   );

/** returns bin capacity */
SCIP_Longint SCIPprobdataGetCapacity(
   SCIP_PROBDATA*        probdata            /**< problem data */
   );

/** returns array of all variables ordered in the way they got generated */
SCIP_VAR** SCIPprobdataGetVars(
   SCIP_PROBDATA*        probdata            /**< problem data */
   );

/** returns number of variables */
int* SCIPprobdataGetNVars(
   SCIP_PROBDATA*        probdata            /**< problem data */
   );

/** returns number of variables */
int* SCIPprobdataGetmPats_sizes(
   SCIP_PROBDATA*        probdata            /**< problem data */
   );

int SCIPprobdataGetnbrJobs(
   SCIP_PROBDATA*        probdata            /**< problem data */
   );

/** returns array of set partitioning constrains */
SCIP_CONS** SCIPprobdataGetConss(
   SCIP_PROBDATA*        probdata            /**< problem data */
   );

/** adds given variable to the problem data */
SCIP_RETCODE SCIPprobdataAddVar(
   SCIP*                 scip,               /**< SCIP data structure */
   SCIP_PROBDATA*        probdata,           /**< problem data */
   SCIP_VAR*             var                 /**< variables to add */
   );

SCIP_DECL_PROBDELORIG(probdelorigBinpacking);
SCIP_DECL_PROBTRANS(probtransBinpacking);
SCIP_DECL_PROBDELTRANS(probdeltransBinpacking);
SCIP_DECL_PROBINITSOL(probinitsolBinpacking);
SCIP_DECL_PROBEXITSOL(probexitsolBinpacking);

#endif
