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

/**@file   pricer_binpacking.h
 * @brief  Binpacking variable pricer
 * @author Timo Berthold
 * @author Stefan Heinz
 *
 * This file implements the variable pricer which check if variables exist with negative reduced cost. See for more
 * details \ref BINPACKING_PRICER.
 */

/*---+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0----+----1----+----2*/

#ifndef __BIN_PRICER_BINPACKING__
#define __BIN_PRICER_BINPACKING__

#include "scip/scip.h"
#include "probdata_binpacking.h"


/** creates the binpacking variable pricer and includes it in SCIP */
SCIP_RETCODE SCIPincludePricerBinpacking(
   SCIP*                 scip                /**< SCIP data structure */
   );

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

   );

#endif
