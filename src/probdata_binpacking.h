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
/* singlePattern struct contains start and end time of a job*/
typedef struct singlePattern {
   double start;
   double end;   
} singlePattern;

/* one pattern contains start and end time pairs of up to 5 jobs*/
typedef struct pat {
   singlePattern patterns[5];
} pat;

/* one machine can have up to 5 patterns*/
typedef struct machinePatterns {
   pat mp[5];
   int lastPatternIdx;
} machinePatterns;

typedef struct processingTimes{
   double m1[5];
   double m2[5];
} processingTimes;



/** sets up the problem data */
SCIP_RETCODE SCIPprobdataCreate(
   SCIP*                 scip,               /**< SCIP data structure */
   const char*           probname,           /**< problem name */
   int*                  ids,                /**< array of item ids */
   SCIP_Longint*         weights,            /**< array containing the item weights */
   int                   nitems,             /**< number of items */
   SCIP_Longint          capacity            /**< bin capacity */
   );

/** returns array of item ids */
int* SCIPprobdataGetIds(
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
int SCIPprobdataGetNVars(
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

#endif
