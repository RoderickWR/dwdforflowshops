/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*   File....: zlpglue.c                                                     */
/*   Name....: LP Storage Interface Zimpl commandline part                   */
/*   Author..: Thorsten Koch                                                 */
/*   Copyright by Author, All rights reserved                                */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*
 * Copyright (C) 2001-2022 by Thorsten Koch <koch@zib.de>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#include <gmp.h>

#include "zimpl/lint.h"
#include "zimpl/attribute.h"
#include "zimpl/mshell.h"

#include "zimpl/ratlptypes.h"
#include "zimpl/numb.h"
#include "zimpl/elem.h"
#include "zimpl/tuple.h"
#include "zimpl/mme.h"
#include "zimpl/bound.h"
#include "zimpl/mono.h"
#include "zimpl/term.h"
#include "zimpl/ratlp.h"
#include "zimpl/zlpglue.h"

/*lint -esym(818, lp) 'lp' could be declared as pointing to const */

static char const* const title = "This file was automatically generated by Zimpl";

/** Print some statistics about the mathematical program stored.
 */
void zlp_stat(
   Lps const* lp)         /**< Pointer to storage */
{
   assert(lp != NULL);

   lps_stat(lp);
}

/** Set the maximal length for generated variable and constraint names.
 */ 
void zlp_setnamelen(
   Lps* lp,          /**< Pointer to storage */
   int  name_len)    /**< Maximal length for generated variable and constraint names */
{
   assert(lp != NULL);

   lps_setnamelen(lp, name_len);
}

#if 0 /* Not used anymore */
bool zlp_presolve(Lps* lp)
{
   PSResult res;
   
   res = lps_presolve(lp, verbose);

   switch(res)
   {
   case PRESOLVE_INFEASIBLE :
      printf("Model is infeasible\n");
      return false;
   case PRESOLVE_UNBOUNDED :
      printf("Model is unbounded\n");
      return false;
   case PRESOLVE_VANISHED :
      printf("Presolve solved the problem -- see .tbl file for values\n");
      break;
   case PRESOLVE_OKAY :
      break;
   default :
      abort();
   }
   return true;
}

#endif
     

/** Write mathematical program to file.
 */
void zlp_write(
   Lps const*  const lp,         /**< Pointer to storage */
   FILE*       const fp,         /**< File pointer to write to */
   LpFormat    const format,     /**< File format */
   char const* const format_options, /**<< Format option characters if any */
   char const* const text)       /**< Comment to be written into the file */
{  
   assert(lp != NULL);
   assert(fp != NULL);

   lps_scale(lp);
   lps_write(lp, fp, format, format_options, text);
}

/** Write variable and constraint translation table to file.
 *  Depending on the maximal allowed name length, variable and constraint
 *  names will be mangled to keep them unique. This table provied the
 *  necessary translation between the mangled and the original name.
 */
void zlp_transtable(
   Lps const* lp,         /**< Pointer to storage */
   FILE*      fp,         /**< File pointer to write to */
   LpFormat   format)     /**< File format */
{
   assert(lp != NULL);
   assert(fp != NULL);
   
   lps_transtable(lp, fp, format, "zimpl");
}

/** Write branching ordering information to file.
 */
void zlp_orderfile(
   Lps const* lp,         /**< Pointer to storage */
   FILE*      fp,         /**< File pointer to write to */
   LpFormat   format)     /**< File format */
{
   assert(lp != NULL);
   assert(fp != NULL);

   lps_orderfile(lp, fp, format, title);
}

/** Write Mip STart file.
 */
void zlp_mstfile(
   Lps const* lp,         /**< Pointer to storage */
   FILE*      fp,         /**< File pointer to write to */
   LpFormat   format)     /**< File format */
{
   assert(lp != NULL);
   assert(fp != NULL);

   lps_mstfile(lp, fp, format, title);
}

