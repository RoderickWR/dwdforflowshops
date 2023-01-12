/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*          This file is part of the program and software framework          */
/*                    UG --- Ubquity Generator Framework                     */
/*                                                                           */
/*  Copyright Written by Yuji Shinano <shinano@zib.de>,                      */
/*            Copyright (C) 2021 by Zuse Institute Berlin,                   */
/*            licensed under LGPL version 3 or later.                        */
/*            Commercial licenses are available through <licenses@zib.de>    */
/*                                                                           */
/* This code is free software; you can redistribute it and/or                */
/* modify it under the terms of the GNU Lesser General Public License        */
/* as published by the Free Software Foundation; either version 3            */
/* of the License, or (at your option) any later version.                    */
/*                                                                           */
/* This program is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/* GNU Lesser General Public License for more details.                       */
/*                                                                           */
/* You should have received a copy of the GNU Lesser General Public License  */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>.     */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/**@file    scipDiffParamSetMpi.h
 * @brief   ScipDiffParamSet extension for MPI communication.
 * @author  Yuji Shinano
 *
 *
 *
 */

/*---+----1----+----2----+----3----+----4----+----5----+----6----+----7----+----8----+----9----+----0----+----1----+----2*/


#ifndef __SCIP_DIFF_PARAM_SET_MPI_H__
#define __SCIP_DIFF_PARAM_SET_MPI_H__

#include <mpi.h>
#include "ug/paraComm.h"
#include "scipDiffParamSet.h"

namespace ParaSCIP
{

/** ScipDiffParamSet class */
class ScipDiffParamSetMpi: public ScipDiffParamSet
{

   /** create scipDiffParamSetPreType */
   MPI_Datatype createDatatype1();
   /** create scipDiffParamSetType */
   MPI_Datatype createDatatype2(bool memAllocNecessary);

public:
   /** constructor */
   ScipDiffParamSetMpi(
         )
	  {
   }

   /** constructor with scip */
   ScipDiffParamSetMpi(
         SCIP *scip
         )
         : ScipDiffParamSet(scip)
   {
   }

   /** destructor */
   ~ScipDiffParamSetMpi(
		   )
   {
   }

   /** broadcast scipDiffParamSet */
   int bcast(UG::ParaComm *comm, int root);

   /** send scipDiffParamSet to the rank */
   int send(UG::ParaComm *comm, int destination);

   /** receive scipDiffParamSet from the source rank */
   int receive(UG::ParaComm *comm, int source);

};

typedef ScipDiffParamSet *ScipDiffParamSetPtr;

}

#endif // _SCIP_DIFF_PARAM_SET_MPI_H__

