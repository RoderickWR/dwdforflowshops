/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/zimpl/mmlparse2.y" /* yacc.c:339  */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                           */
/*   File....: mmlparse2.y                                                   */
/*   Name....: MML Parser                                                    */
/*   Author..: Thorsten Koch                                                 */
/*   Copyright by Author, All rights reserved                                */
/*                                                                           */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*
 * Copyright (C) 2001-2022 by Thorsten Koch <koch@zib.de>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#pragma clang diagnostic ignored "-Wconversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#pragma clang diagnostic ignored "-Wunused-macros"
#pragma clang diagnostic ignored "-Wimplicit-function-declaration"
#pragma clang diagnostic ignored "-Wunreachable-code"
#endif
   
#if defined(__GNUC__) && !defined(__clang__) && !defined(__INTEL_COMPILER)
#pragma GCC   diagnostic ignored "-Wstrict-prototypes"
#endif
   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
   
#include "zimpl/lint.h"
#include "zimpl/attribute.h"
#include "zimpl/mshell.h"
#include "zimpl/ratlptypes.h"
#include "zimpl/numb.h"
#include "zimpl/elem.h"
#include "zimpl/tuple.h"
#include "zimpl/mme.h"
#include "zimpl/set.h"
#include "zimpl/symbol.h"
#include "zimpl/entry.h"
#include "zimpl/idxset.h"
#include "zimpl/rdefpar.h"
#include "zimpl/bound.h"
#include "zimpl/define.h"
#include "zimpl/mono.h"
#include "zimpl/term.h"
#include "zimpl/list.h"
#include "zimpl/stmt.h"
#include "zimpl/local.h"
#include "zimpl/code.h"
#include "zimpl/inst.h"
        
#define YYERROR_VERBOSE 1

/* the function is actually getting a YYSTYPE* as argument, but the
 * type isn't available here, so it is decalred to accept any number of
 * arguments, i.e. yylex() and not yylex(void).
 */
extern int yylex();

/*lint -sem(yyerror, 1p, r_no) */ 
extern void yyerror(const char* s) is_NORETURN;
 

#line 149 "src/zimpl/mmlparse2.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "mmlparse2.h".  */
#ifndef YY_YY_SRC_ZIMPL_MMLPARSE2_H_INCLUDED
# define YY_YY_SRC_ZIMPL_MMLPARSE2_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DECLSET = 258,
    DECLPAR = 259,
    DECLVAR = 260,
    DECLMIN = 261,
    DECLMAX = 262,
    DECLSUB = 263,
    DECLSOS = 264,
    DEFNUMB = 265,
    DEFSTRG = 266,
    DEFBOOL = 267,
    DEFSET = 268,
    PRINT = 269,
    CHECK = 270,
    BINARY = 271,
    INTEGER = 272,
    REAL = 273,
    IMPLICIT = 274,
    ASGN = 275,
    DO = 276,
    WITH = 277,
    IN = 278,
    TO = 279,
    UNTIL = 280,
    BY = 281,
    FORALL = 282,
    EXISTS = 283,
    PRIORITY = 284,
    STARTVAL = 285,
    DEFAULT = 286,
    CMP_LE = 287,
    CMP_GE = 288,
    CMP_EQ = 289,
    CMP_LT = 290,
    CMP_GT = 291,
    CMP_NE = 292,
    INFTY = 293,
    AND = 294,
    OR = 295,
    XOR = 296,
    NOT = 297,
    SUM = 298,
    MIN = 299,
    MAX = 300,
    ARGMIN = 301,
    ARGMAX = 302,
    PROD = 303,
    IF = 304,
    THEN = 305,
    ELSE = 306,
    END = 307,
    INTER = 308,
    UNION = 309,
    CROSS = 310,
    SYMDIFF = 311,
    WITHOUT = 312,
    PROJ = 313,
    MOD = 314,
    DIV = 315,
    POW = 316,
    FAC = 317,
    CARD = 318,
    ROUND = 319,
    FLOOR = 320,
    CEIL = 321,
    RANDOM = 322,
    ORD = 323,
    ABS = 324,
    SGN = 325,
    LOG = 326,
    LN = 327,
    EXP = 328,
    SQRT = 329,
    SIN = 330,
    COS = 331,
    TAN = 332,
    ASIN = 333,
    ACOS = 334,
    ATAN = 335,
    POWER = 336,
    SGNPOW = 337,
    READ = 338,
    AS = 339,
    SKIP = 340,
    USE = 341,
    COMMENT = 342,
    MATCH = 343,
    SUBSETS = 344,
    INDEXSET = 345,
    POWERSET = 346,
    VIF = 347,
    VABS = 348,
    TYPE1 = 349,
    TYPE2 = 350,
    LENGTH = 351,
    SUBSTR = 352,
    NUMBSYM = 353,
    STRGSYM = 354,
    VARSYM = 355,
    SETSYM = 356,
    NUMBDEF = 357,
    STRGDEF = 358,
    BOOLDEF = 359,
    SETDEF = 360,
    DEFNAME = 361,
    NAME = 362,
    STRG = 363,
    NUMB = 364,
    SCALE = 365,
    SEPARATE = 366,
    CHECKONLY = 367,
    INDICATOR = 368,
    QUBO = 369
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 87 "src/zimpl/mmlparse2.y" /* yacc.c:355  */

   unsigned int bits;
   Numb*        numb;
   const char*  strg;
   const char*  name;
   Symbol*      sym;
   Define*      def;
   CodeNode*    code;

#line 314 "src/zimpl/mmlparse2.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void);

#endif /* !YY_YY_SRC_ZIMPL_MMLPARSE2_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 330 "src/zimpl/mmlparse2.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3479

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  127
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  310
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  926

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   369

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     122,   123,   117,   115,   121,   116,     2,   124,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   118,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   119,     2,   120,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   125,     2,   126,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   156,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   174,   181,   187,   193,   203,   204,   207,
     210,   213,   219,   228,   237,   246,   255,   264,   267,   277,
     280,   283,   286,   293,   296,   297,   304,   305,   313,   320,
     329,   339,   350,   359,   369,   373,   383,   384,   385,   389,
     392,   393,   394,   399,   407,   408,   409,   410,   415,   423,
     424,   428,   429,   437,   438,   441,   442,   446,   450,   454,
     457,   469,   472,   482,   488,   491,   494,   499,   504,   512,
     515,   520,   525,   532,   536,   541,   545,   551,   554,   559,
     564,   569,   573,   580,   587,   593,   599,   605,   610,   618,
     627,   636,   644,   655,   658,   662,   667,   675,   676,   679,
     682,   683,   686,   689,   690,   693,   696,   697,   700,   703,
     704,   707,   710,   711,   714,   717,   718,   719,   720,   721,
     725,   726,   730,   731,   732,   733,   734,   738,   739,   740,
     744,   745,   746,   747,   748,   751,   752,   760,   761,   762,
     766,   767,   771,   772,   773,   779,   780,   783,   789,   792,
     793,   794,   795,   796,   797,   798,   799,   800,   801,   802,
     805,   808,   811,   819,   825,   828,   834,   835,   836,   844,
     848,   849,   850,   851,   852,   853,   854,   864,   865,   872,
     875,   881,   882,   883,   886,   887,   890,   891,   894,   895,
     899,   900,   901,   904,   908,   911,   916,   917,   920,   923,
     926,   929,   932,   935,   938,   941,   942,   943,   944,   945,
     946,   947,   950,   953,   959,   960,   964,   965,   966,   967,
     971,   974,   977,   981,   982,   983,   984,   985,   986,   987,
     988,   989,   990,   991,   992,   993,   994,   995,   996,   997,
     998,   999,  1000,  1005,  1011,  1012,  1016,  1019,  1025,  1028,
    1034,  1035,  1036,  1040,  1041,  1042,  1043,  1044,  1045,  1051,
    1052,  1053,  1057,  1058,  1059,  1062,  1065,  1068,  1071,  1077,
    1078,  1079,  1082,  1085,  1088,  1093,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    1112,  1113,  1114,  1116,  1117,  1118,  1121,  1124,  1127,  1130,
    1133
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DECLSET", "DECLPAR", "DECLVAR",
  "DECLMIN", "DECLMAX", "DECLSUB", "DECLSOS", "DEFNUMB", "DEFSTRG",
  "DEFBOOL", "DEFSET", "PRINT", "CHECK", "BINARY", "INTEGER", "REAL",
  "IMPLICIT", "ASGN", "DO", "WITH", "IN", "TO", "UNTIL", "BY", "FORALL",
  "EXISTS", "PRIORITY", "STARTVAL", "DEFAULT", "CMP_LE", "CMP_GE",
  "CMP_EQ", "CMP_LT", "CMP_GT", "CMP_NE", "INFTY", "AND", "OR", "XOR",
  "NOT", "SUM", "MIN", "MAX", "ARGMIN", "ARGMAX", "PROD", "IF", "THEN",
  "ELSE", "END", "INTER", "UNION", "CROSS", "SYMDIFF", "WITHOUT", "PROJ",
  "MOD", "DIV", "POW", "FAC", "CARD", "ROUND", "FLOOR", "CEIL", "RANDOM",
  "ORD", "ABS", "SGN", "LOG", "LN", "EXP", "SQRT", "SIN", "COS", "TAN",
  "ASIN", "ACOS", "ATAN", "POWER", "SGNPOW", "READ", "AS", "SKIP", "USE",
  "COMMENT", "MATCH", "SUBSETS", "INDEXSET", "POWERSET", "VIF", "VABS",
  "TYPE1", "TYPE2", "LENGTH", "SUBSTR", "NUMBSYM", "STRGSYM", "VARSYM",
  "SETSYM", "NUMBDEF", "STRGDEF", "BOOLDEF", "SETDEF", "DEFNAME", "NAME",
  "STRG", "NUMB", "SCALE", "SEPARATE", "CHECKONLY", "INDICATOR", "QUBO",
  "'+'", "'-'", "'*'", "';'", "'['", "']'", "','", "'('", "')'", "'/'",
  "'{'", "'}'", "$accept", "stmt", "decl_set", "set_entry_list",
  "set_entry", "def_numb", "def_strg", "def_bool", "def_set", "name_list",
  "decl_par", "par_singleton", "par_default", "decl_var", "var_type",
  "lower", "upper", "priority", "startval", "cexpr_entry_list",
  "cexpr_entry", "matrix_head", "matrix_body", "decl_obj", "decl_sub",
  "constraint_list", "constraint", "vbool", "con_attr_list", "con_attr",
  "con_type", "vexpr", "vproduct", "vfactor", "vexpo", "vval", "decl_sos",
  "soset", "sos_type", "exec_do", "command", "idxset", "pure_idxset",
  "sexpr", "sunion", "sproduct", "sval", "read", "read_par", "tuple_list",
  "lexpr", "tuple", "symidx", "cexpr_list", "cexpr", "cproduct", "cfactor",
  "cexpo", "cval", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,    43,    45,    42,    59,    91,
      93,    44,    40,    41,    47,   123,   125
};
# endif

#define YYPACT_NINF -540

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-540)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1217,   -86,   -53,    26,    30,    54,    70,    73,   -14,    15,
      35,    92,    52,    97,  -540,  -540,  -540,  -540,  -540,  -540,
    -540,  -540,  -540,  -540,  -540,    -1,     3,    12,   103,   195,
     207,   227,   118,   163,   206,   263,  1590,  1747,   481,    -5,
    -540,  1064,   456,  1432,   481,   274,   373,  -540,   715,   481,
     373,  2837,  2837,  1831,    84,   318,   318,   318,   318,   316,
    2136,  1747,   481,     7,    14,   573,  1002,   481,  1747,   481,
     481,   329,   331,   333,   338,   348,   374,   386,   391,   411,
     414,   418,   437,   441,   461,   469,   503,   508,   514,   517,
     526,   534,   572,   364,   364,  -540,   364,   597,   615,   624,
     647,  -540,  -540,  -540,  3357,  3357,  1747,  1914,   727,  -540,
       6,  -540,   561,   412,   582,    40,   258,  -540,  -540,   704,
     727,   561,   412,    40,  1747,  1064,   751,  -540,   950,   759,
    -540,   557,   845,   757,  3028,  1747,  3028,  3028,   769,   768,
    -540,   879,  1373,  3028,   663,   803,  3028,   873,  3097,   895,
     793,  -540,   809,   895,   481,  1747,   833,   852,   860,   875,
     888,   892,   897,   901,   902,   906,   908,   914,   364,  2898,
    2898,  2837,    94,   -30,  -540,  -540,   871,   746,   332,   326,
     481,  1747,  2699,     8,  -540,   256,   366,   481,  -540,  -540,
     887,   274,  -540,   147,   203,   230,   253,   481,  -540,     9,
     663,  -540,  1017,  1998,  1020,  1998,  1025,  2630,  1026,  2630,
    1029,  1032,   972,  1038,  1046,  1064,  1064,  3028,  3028,  3028,
    3028,  1064,  3028,  3028,  3028,  3028,  3028,  3028,  3028,  3028,
    3028,  3028,  3028,  3028,   990,  3028,  3028,  3028,  -540,  -540,
    -540,  3028,  3028,  3028,  3028,  -540,  -540,   304,    24,    49,
    1747,  2630,  -540,    -9,  1373,    18,   759,   283,    34,  1064,
    1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,  1064,
    1064,   783,   783,  1747,  1747,  1747,  1064,  3028,  3028,  3028,
    3028,  3028,  3028,  3028,  3028,  3028,  3296,  3296,  3296,  3296,
    3296,  -540,   977,   542,    52,  1064,  -540,   122,  1075,    17,
    1059,   363,   111,  -540,  1061,  3028,   879,  3028,  3028,  3028,
    3028,  -540,   663,  1086,   663,  3028,   994,  1747,  2429,   663,
    2211,   274,  -540,  1500,   996,  1087,  1102,  2837,  2837,  2837,
    2837,  2837,  2837,  2837,  2837,  2837,  2837,  2837,  2837,  -540,
    1495,  1495,  -540,  -540,   361,   435,  2837,  2837,  -540,  2959,
    3296,  3296,  2837,  2837,  2959,  -540,  1098,  1105,  2699,  2699,
    1110,   313,   618,  2768,  -540,  -540,  -540,  -540,  2837,  2837,
    1100,  -540,  1118,  1016,  1127,  1139,  1141,  1142,  1030,  -540,
    3028,  1043,   295,  3296,  1045,   343,  3296,   501,  3028,   673,
    3028,  3296,  1747,   783,  1015,   581,   652,   763,   777,   781,
     473,   810,   797,   910,   929,  1010,  1013,  1120,  1124,  1129,
    1133,  1135,  1138,  1144,  1047,  1147,   567,   762,   449,   500,
     543,   681,  -540,  -540,  -540,  1117,  2067,  -540,  1061,  -540,
    -540,  3028,  3028,   950,   950,   950,   950,   950,   950,  -540,
    -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  1099,  1099,
     950,   663,   663,   663,   663,   663,   663,   663,   258,   258,
    -540,  -540,  -540,  -540,  -540,  1064,  -540,   106,  1049,  1063,
     -66,  -540,  1064,   368,  -540,  3028,  3028,  -540,    21,  3028,
     663,   663,   663,   663,   893,   663,  -540,  1165,  -540,  -540,
    1747,   663,   873,   274,   373,   882,   373,  -540,  2837,  2837,
    1149,  1158,  1184,  1186,  1188,  1197,  1199,  1201,  1211,  1213,
    1215,  1224,  1226,  1229,  1239,  1253,  1284,  1293,   634,   862,
    1305,   481,  1747,  1068,  1091,  1092,  1112,  1115,  1119,  1155,
    1156,  1157,  2837,  -540,   -30,   332,   -30,   332,  -540,  -540,
    -540,  -540,   -30,   332,   -30,   332,  -540,  1831,  1831,  -540,
     392,   219,   278,  2699,  2699,  2699,  2837,  2837,  2837,  2837,
    2837,  2837,  2837,  2837,  2837,  2837,  2837,  2837,  2837,  -540,
     801,   746,   171,   356,    84,  2837,  -540,  3028,  3028,  1747,
    1064,  -540,   258,  -540,  -540,  -540,  -540,  -540,  -540,   481,
     663,   481,   663,  -540,   330,   280,   610,  -540,     6,  1061,
    -540,  -540,  -540,  -540,  3028,  3028,  -540,  -540,  -540,  -540,
    -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,
    3028,  -540,  -540,  -540,  -540,  -540,  2630,  1140,   489,  -540,
     -12,   -10,   978,  1747,  1064,  1064,  -540,  1061,   950,   -28,
     682,   134,   663,  -540,    22,  3028,   -13,   544,  3166,  1168,
    1128,   873,   895,  1137,   895,   -30,   332,   185,   214,  -540,
    -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  3028,  3028,
    -540,  1196,  1192,  2837,  2837,  2837,  2837,  2837,  2837,  2837,
    2837,  2837,  1243,   181,   346,   379,  -540,  -540,  1259,  1259,
     256,   366,   801,   746,   801,   746,   801,   746,   801,   746,
     801,   746,   801,   746,   801,   801,   801,   801,   801,   801,
    1187,  1187,  3028,  3028,  1187,  3028,  3028,  1187,  -540,   801,
     675,   956,   237,   986,  1289,  1300,  1064,  1747,  3028,  1182,
    1307,   942,  1095,  -540,  -540,  3028,  -540,  3028,  -540,   561,
     865,   791,  -540,  -540,  -540,  -540,  1153,  3028,  1205,  -540,
    2496,   308,  2286,  -540,  1219,   274,  -540,  1228,  2837,  1316,
    1318,  2837,  2837,  1831,  -540,  2837,  2837,  1273,   663,   663,
     663,   663,  -540,  -540,  -540,  -540,  3028,  3028,  1078,   515,
      37,  -540,  -540,  3028,  3028,   574,   627,  3028,  -540,  -540,
     663,  -540,  1297,  3235,  1302,   429,  -540,   873,  -540,   382,
    -540,  -540,   332,    63,   167,   292,   385,   416,  -540,  -540,
    -540,  -540,  -540,  -540,  1187,  1187,  1187,  1187,   663,   663,
    -540,  -540,  -540,  1320,  1329,  -540,  -540,   464,  3028,  2563,
    3028,  2361,  1233,  -540,  -540,  2837,  -540,  2837,  -540,  2837,
    -540,  2837,  -540,  -540,  -540,  3028,  -540,   422,  1281,   433,
    1283,  -540,   256,   366,  1187,   256,   366,  1187,   256,   366,
    1187,   256,   366,  1187,  1333,  -540,  -540,  -540,  -540,  2837,
    2837,  2837,  2837,  2837,  2837,  2837,  2837,  -540,   477,   513,
     525,   555,   629,   655,   658,   661,   670,   756,   779,   794,
     818,   824,   878,   883,  -540,  -540,  -540,  -540,  -540,  -540,
    -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,  -540,
    1187,  1187,  1187,  1187,  1187,  1187,  1187,  1187,  1187,  1187,
    1187,  1187,  1187,  1187,  1187,  1187
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,     8,     9,    10,    11,     3,
       4,     5,     6,     7,    12,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,    59,    49,    47,     0,     0,
      49,     0,     0,     0,   176,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   256,   256,   184,   256,     0,     0,     0,
       0,   281,   280,   279,     0,     0,     0,     0,   182,   191,
     198,   200,   183,   181,   180,   258,   260,   263,   269,   272,
       0,   185,     0,     0,     0,     0,     0,   187,   188,     0,
     179,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      63,     0,    65,     0,    35,     0,     0,    61,     0,    54,
       0,    48,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,     0,
       0,     0,     0,   140,   147,   152,   155,     0,   260,     0,
       0,     0,     0,     0,    74,     0,     0,     0,   177,   178,
       0,    59,    27,     0,     0,     0,     0,     0,   254,     0,
     258,   248,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   282,   283,
     204,     0,     0,     0,     0,   270,   271,     0,     0,     0,
       0,     0,   206,     0,   232,     0,   230,     0,   258,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,     0,    32,     0,     0,    66,     0,     0,     0,
       0,   225,    67,     0,    60,     0,     0,     0,     0,    50,
       0,    59,    41,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   158,
       0,     0,   153,   154,     0,     0,     0,     0,    71,     0,
       0,     0,     0,     0,     0,    72,     0,     0,     0,     0,
       0,     0,     0,     0,    73,   137,   138,   139,     0,     0,
       0,   173,     0,     0,     0,     0,     0,     0,     0,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,   249,   303,     0,     0,   218,     0,   216,
     217,     0,     0,   244,   242,   239,   243,   241,   240,   197,
     192,   194,   196,   193,   195,   201,   202,   245,   246,   247,
     250,   259,   238,   236,   233,   237,   235,   234,   261,   262,
     266,   267,   264,   265,   273,     0,   186,   190,     0,     0,
       0,    17,     0,     0,    68,     0,     0,    64,     0,     0,
     226,   227,   228,   229,     0,    62,    43,     0,    51,    56,
       0,    55,    61,    59,    49,     0,    49,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   172,   141,   143,   142,   144,   151,   148,
     149,   156,   145,   261,   146,   262,   150,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
     130,   130,   130,   130,   176,     0,    28,     0,     0,     0,
       0,   251,   274,   277,   309,   275,   278,   310,   276,     0,
     211,     0,   213,   268,     0,     0,     0,   203,   199,     0,
     287,   290,   291,   292,     0,     0,   288,   289,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   222,   304,
       0,   257,   284,   285,   252,   205,     0,     0,     0,   231,
       0,     0,     0,     0,     0,     0,    16,     0,    22,     0,
       0,     0,   224,    69,     0,     0,    36,     0,     0,     0,
       0,    61,    54,     0,    54,   157,   274,     0,     0,   167,
     168,   161,   163,   162,   160,   164,   165,   166,     0,     0,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,     0,     0,     0,   129,   125,   126,   127,
       0,     0,   113,   115,   116,   118,   110,   112,   119,   121,
     122,   124,   107,   109,   114,   117,   111,   120,   123,   108,
      79,    80,     0,     0,    81,     0,     0,    82,   175,   174,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   219,     0,   208,     0,   210,   189,
       0,     0,    18,    15,    14,    70,     0,     0,     0,    30,
       0,     0,     0,    45,     0,    59,    40,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,     0,   130,   130,
     130,   130,    23,    24,    25,    26,     0,     0,     0,     0,
       0,   221,   306,     0,     0,     0,     0,     0,    21,    31,
      37,    29,     0,     0,     0,     0,    42,    61,    38,     0,
     169,   170,     0,     0,     0,     0,     0,     0,   132,   133,
     134,   135,   136,   131,    83,    85,    84,    86,   212,   214,
     223,   253,   307,     0,     0,   207,   209,     0,     0,     0,
       0,     0,     0,   171,    78,     0,   130,     0,   130,     0,
     130,     0,   130,   308,   305,     0,    19,     0,     0,     0,
       0,    44,     0,     0,   103,     0,     0,   105,     0,     0,
     104,     0,     0,   106,     0,    53,    52,    58,    57,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
      87,    91,    90,    97,    89,    96,    95,   101,    88,    94,
      93,   100,    92,    99,    98,   102
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -540,  -540,  -540,   891,   719,  -540,  -540,  -540,  -540,   770,
    -540,  -540,  -540,  -540,  1042,   -44,  -148,  -189,  -481,   886,
    1067,  -131,  -540,  -540,  -540,  -539,  1012,  -324,   -84,  -540,
    -138,   616,  -296,   -74,  -540,  -540,  -540,   799,  -540,  -540,
    1083,   -29,   924,  1151,  1204,  1009,  -245,  1298,  -540,  -540,
     -15,  1282,   -34,    20,   -36,   522,    19,  -101,  -540
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    13,    14,   470,   471,    15,    16,    17,    18,   193,
      19,   138,   748,    20,    50,   149,   321,   147,   316,   139,
     140,   141,   306,    21,    22,   183,   184,   360,   710,   813,
     368,   361,   173,   174,   175,   176,    23,   190,   191,    24,
      39,   126,   127,   128,   109,   110,   111,   142,   311,   255,
     112,   129,   238,   114,   177,   116,   117,   118,   119
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     115,   123,   372,   245,   246,   324,   153,   144,   682,   683,
     305,   650,   426,   133,   735,   145,   737,   186,   747,    41,
     152,    25,   121,    43,   200,   123,   445,   446,    45,    46,
      47,    48,   123,   202,   549,   550,   208,   210,   211,   474,
     213,   214,    60,   643,   745,   379,   201,   363,   369,    60,
     534,   536,   636,   212,    26,   637,   542,   544,   431,   432,
     239,   271,   240,   273,   274,   275,    36,    37,   245,   246,
     249,   258,   278,   279,   280,   281,   282,   283,   253,    38,
     199,   278,   279,   280,   281,   282,   283,   349,   123,   822,
     743,   248,    32,   637,   350,   342,   343,    40,   200,   123,
     301,   302,   363,   284,   285,   284,   285,   312,   304,   292,
     314,   187,   319,   130,   736,   834,   738,   427,    42,   123,
     300,    33,    44,   272,    51,   325,   364,   257,   633,   203,
     277,    49,   492,    27,   339,   345,   205,    28,   277,   428,
     326,    34,   277,   277,   429,   123,   362,   423,   597,   284,
     285,   356,   284,   285,   299,   284,   285,    60,   370,   265,
     266,    29,   267,   268,   284,   285,   357,   200,   378,   200,
     754,   387,   424,   389,   381,   479,   384,    30,   188,   189,
      31,   397,   398,   399,   400,   728,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,    35,   415,
     416,   200,   655,   712,   713,   200,   200,   200,   200,   346,
     347,   468,   348,   469,   123,   302,    52,   246,   835,   836,
     363,   269,   270,   382,   803,   385,   284,   285,    53,   687,
     688,   689,   763,   764,   424,   425,   758,   123,   123,   123,
      55,   451,   452,   453,   454,   455,   456,   457,    54,   284,
     285,   557,   558,   559,   560,   561,   562,   417,   447,   448,
     449,   418,   419,   420,   421,   728,   342,   343,   373,   200,
     374,   480,   481,   482,   483,   538,   273,   274,   275,   485,
     546,   123,   346,   347,   491,    56,   346,   347,   365,   366,
     367,   501,   503,   505,   507,   509,   511,   513,   515,   517,
     346,   347,   487,   146,   651,   460,   461,   462,   463,   464,
     563,   564,   565,   566,   567,   568,   832,   286,   287,   273,
     274,   275,   362,   552,   373,   478,   375,   186,    57,   352,
     353,   727,   571,   573,   346,   347,   259,   260,   261,   262,
     263,   264,   533,   837,   838,   557,   558,   559,   560,   561,
     562,   373,   590,   376,   592,   774,   596,   265,   266,   793,
     267,   268,   259,   260,   261,   262,   263,   264,   539,   540,
     541,   346,   347,   462,   373,   288,   377,   595,   365,   366,
     367,   726,   289,   265,   266,    58,   267,   268,   715,   716,
     628,   286,   287,   352,   353,   630,   631,   758,   365,   366,
     367,   424,   585,    60,   277,   588,   148,   352,   353,   430,
     593,   365,   366,   367,    65,    66,   277,   124,   584,   269,
     270,    69,    70,   284,   285,   192,    71,   422,   346,   347,
     728,   553,   554,   555,   833,   276,   839,   840,   197,   641,
     642,   346,   347,   200,   355,   269,   270,   476,   647,   354,
     652,   215,   654,   216,   123,   217,   289,   468,    90,   469,
     218,   346,   347,   658,   277,   655,   587,   841,   842,    96,
     219,   352,   353,   100,   865,   649,   346,   347,   284,   285,
     831,   352,   353,   237,   533,   867,   123,   711,   714,   717,
     125,    60,   671,   107,   352,   353,   220,   346,   347,   644,
     346,   347,    65,    66,   755,   124,   757,   672,   221,    69,
      70,   186,   685,   222,    71,   686,    60,   362,   362,   362,
     691,   693,   695,   697,   699,   701,   703,    65,    66,   894,
     124,   352,   353,   223,    69,    70,   224,   284,   285,    71,
     225,   720,   721,   123,   284,   285,    90,   369,   284,   285,
     352,   353,   765,   766,   273,   274,   275,    96,   424,   226,
     724,   100,   725,   227,   722,   895,   797,   821,   730,   731,
     277,    90,   622,   178,   178,   178,   132,   896,   125,   284,
     285,   107,    96,   228,   732,   845,   100,   846,   284,   285,
     641,   229,   346,   347,   604,   265,   266,   123,   267,   268,
     273,   274,   275,   125,   284,   285,   107,   897,    60,   746,
     265,   266,   751,   267,   268,   734,   284,   285,   739,    65,
      66,   277,   124,   623,   589,   230,    69,    70,   352,   353,
     231,    71,   759,   760,   265,   266,   232,   267,   268,   233,
     346,   347,   278,   279,   280,   281,   282,   283,   234,   246,
     563,   564,   565,   566,   567,   568,   235,   269,   270,   284,
     285,   728,   749,    90,   277,   422,   624,   172,   179,   185,
     352,   353,   269,   270,    96,   296,   768,   769,   100,   770,
     771,   898,   284,   285,   814,   815,   816,   817,   620,   284,
     285,   123,   780,   178,   236,   207,   269,   270,   107,   785,
     825,   786,   599,   277,   178,   265,   266,   899,   267,   268,
     900,   790,   779,   901,   869,   870,   795,   871,   872,   241,
     873,   874,   902,   875,   876,   284,   285,   186,   246,   805,
     807,   150,   151,   352,   353,   265,   266,   242,   267,   268,
     818,   819,   284,   285,   346,   347,   243,   823,   824,   346,
     347,   827,   854,   826,   857,   668,   860,   780,   863,   259,
     260,   261,   262,   263,   264,   290,   291,   269,   270,   244,
     352,   353,   294,   346,   347,   600,   352,   353,   284,   285,
     265,   266,   295,   267,   268,   346,   347,   344,   284,   285,
     284,   285,   847,   772,   849,   780,   591,   269,   270,   853,
     744,   856,   277,   859,   625,   862,   458,   459,   903,   864,
     910,   911,   912,   913,   914,   915,   916,   917,   918,   919,
     920,   921,   922,   923,   924,   925,   194,   195,   196,    65,
      66,   904,   124,   879,   881,   883,   885,   887,   889,   891,
     893,    71,   269,   270,   265,   266,   905,   267,   268,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   352,   353,   265,   266,   297,   267,   268,   535,   537,
     906,   352,   353,    90,   543,   545,   907,   298,   284,   285,
     178,   178,   621,   277,    96,   178,   601,   303,   100,   304,
     178,   178,   284,   285,   346,   347,   284,   285,   653,   151,
     602,   134,   582,   315,   603,   125,   269,   270,   107,   352,
     353,   322,   284,   285,   788,   134,   346,   347,   265,   266,
     606,   267,   268,   313,   645,   269,   270,   320,    60,   323,
     908,   605,   351,   346,   347,   909,    62,    63,    64,   352,
     353,    67,   135,   500,   502,   504,   506,   508,   510,   512,
     514,   516,   518,   519,   520,   327,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   328,   551,   136,   346,   347,   185,
     269,   270,   329,   669,   570,   572,   787,   204,   206,    91,
      92,    93,    94,   346,   347,    97,    98,   330,   352,   353,
     101,   102,   103,   265,   266,   371,   267,   268,   104,   105,
     331,   273,   274,   275,   332,   137,   273,   274,   275,   333,
     656,   178,   392,   334,   335,   284,   285,   465,   336,   726,
     337,   265,   266,   607,   267,   268,   338,    60,   380,   265,
     266,   383,   267,   268,   284,   285,   386,   388,    65,    66,
     390,   124,   608,   391,   178,    69,    70,   284,   285,   393,
      71,    65,    66,   783,   124,   269,   270,   394,    69,   178,
     178,   284,   285,    71,   773,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   178,   178,   178,   178,   178,   178,
     178,   414,    90,   269,   270,   473,    60,   178,   273,   274,
     275,   269,   270,    96,   775,    90,   484,   100,   498,   475,
      65,    66,   486,   124,   497,   657,    96,    69,    70,   547,
     100,   574,    71,   576,   209,   284,   285,   107,   284,   285,
     820,   265,   266,   609,   267,   268,   610,   125,   273,   575,
     107,   273,   274,   275,   273,   274,   275,   577,   344,   553,
     554,   555,   499,   581,    90,   548,   273,   274,   275,   578,
     556,   579,   580,   185,   684,    96,   583,   626,   586,   100,
     618,   634,   690,   692,   694,   696,   698,   700,   702,   704,
     705,   706,   707,   708,   709,   635,   125,   108,   120,   107,
     673,   719,   131,   269,   270,   178,   178,   178,   178,   178,
     178,   178,   178,   178,   273,   274,   275,   273,   274,   275,
     284,   285,   120,   674,   675,   648,   784,   761,   752,   120,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   273,   274,   275,   676,   284,   285,   677,    12,   284,
     285,   678,   762,   611,   284,   285,   753,   612,   284,   285,
     284,   285,   613,   284,   285,   756,   614,   247,   615,   284,
     285,   616,   284,   285,   346,   347,   733,   617,   284,   285,
     619,   789,   659,   352,   353,   120,   293,   679,   680,   681,
     178,   606,   363,   802,   178,   178,   120,   178,   178,   500,
     502,   504,   506,   508,   510,   512,   514,   516,   553,   346,
     347,   352,   353,   346,   347,   781,   120,   660,   767,   607,
     776,   661,   352,   353,   346,   347,   352,   353,   113,   122,
     608,   777,   662,   791,   609,   143,   346,   347,   352,   353,
     346,   347,   120,   866,   663,   868,   610,   796,   664,   352,
     353,   346,   347,   122,   352,   353,   798,   611,   828,   665,
     122,   851,   612,   830,   346,   347,   742,   178,   293,   178,
     293,   178,   666,   178,   639,   496,   395,   396,   352,   353,
     646,   477,   401,   718,   799,   569,   613,   466,   657,   185,
       0,   804,   806,   808,   809,   810,   811,   812,   122,   256,
       0,   178,   178,   178,   178,   178,   178,   178,   178,   346,
     347,   120,   293,   598,     0,   254,   122,   667,   352,   353,
     433,   434,   435,   436,   437,   438,   614,   122,     0,     0,
     346,   347,   284,   285,   120,   120,   120,   450,   670,     0,
     782,   284,   285,   284,   285,   284,   285,   122,     0,   800,
       0,   801,     0,   843,   284,   285,   467,     0,   284,   285,
       0,   852,   844,   855,   134,   858,   877,   861,   307,   308,
     309,   310,     0,   122,     0,     0,     0,    60,   120,   439,
     440,   441,   442,   443,   444,    62,    63,    64,     0,     0,
      67,   135,     0,     0,     0,   878,   880,   882,   884,   886,
     888,   890,   892,     0,     0,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,   136,   493,   494,    47,   495,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,   122,     0,    97,    98,     0,     0,   521,   101,
     102,   103,     0,   594,   522,     0,     0,   104,   105,     0,
       0,     0,     0,     0,   137,   122,   122,   122,     0,     0,
       0,     0,     0,     0,   523,   524,   525,   526,   527,   528,
     529,   530,   531,     0,     0,     0,   165,   166,     0,   472,
       0,     0,     0,     0,     0,     0,   143,     0,   167,     0,
       0,     0,     0,     0,     0,   168,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     340,   341,     0,     0,     0,     0,   632,   532,    59,     0,
       0,     0,     0,   638,   640,    60,     0,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,    66,    67,    68,
       0,   120,     0,    69,    70,     0,     0,     0,    71,     0,
       0,     0,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,   120,   122,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,   101,   102,   103,
       0,     0,     0,     0,     0,   104,   105,     0,   627,     0,
     629,     0,   106,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   723,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   472,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,   122,     0,     0,    59,     0,   632,     0,     0,
       0,     0,    60,     0,   120,   740,   741,     0,     0,    61,
      62,    63,    64,    65,    66,    67,    68,     0,     0,     0,
      69,    70,     0,     0,   122,    71,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    96,    97,
      98,    99,   100,     0,   101,   102,   103,     0,   180,     0,
       0,   122,   104,   105,     0,     0,     0,     0,     0,   106,
       0,     0,   107,     0,   154,    63,    64,   778,   120,    67,
     181,   729,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,    77,
     156,   157,   158,   159,   160,   161,   162,   163,   164,    87,
      88,    89,   165,   166,     0,   122,     0,     0,     0,   472,
       0,     0,     0,   182,   167,     0,     0,    91,    92,    93,
      94,   168,     0,    97,    98,     0,     0,     0,   101,   102,
     103,     0,     0,     0,     0,     0,   169,   170,     0,    60,
       0,     0,     0,   171,     0,     0,     0,    62,    63,    64,
      65,    66,    67,   250,     0,     0,     0,    69,    70,     0,
       0,     0,    71,     0,     0,     0,     0,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,   136,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,   122,
      91,    92,    93,    94,     0,    96,    97,    98,     0,   100,
       0,   101,   102,   103,     0,     0,     0,     0,     0,   104,
     105,     0,     0,    60,     0,     0,   251,     0,     0,   107,
     252,    62,    63,    64,    65,    66,    67,   250,     0,     0,
       0,    69,    70,     0,     0,     0,    71,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    96,
      97,    98,    60,   100,     0,   101,   102,   103,     0,     0,
      62,    63,    64,   104,   105,    67,   135,     0,     0,     0,
     251,     0,     0,   107,     0,     0,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,     0,    97,
      98,     0,   198,     0,   101,   102,   103,     0,     0,    62,
      63,    64,   104,   105,    67,   135,     0,     0,     0,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,     0,    97,    98,
       0,     0,     0,   101,   102,   103,     0,     0,     0,   489,
       0,   104,   105,     0,    62,    63,    64,     0,   137,    67,
     490,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,     0,    97,    98,     0,     0,     0,   101,   102,
     103,     0,     0,     0,   794,     0,   104,   105,     0,    62,
      63,    64,     0,   137,    67,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,     0,    97,    98,
       0,     0,     0,   101,   102,   103,     0,     0,     0,   850,
       0,   104,   105,     0,    62,    63,    64,     0,   137,    67,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,     0,    97,    98,     0,     0,   488,   101,   102,
     103,     0,    62,    63,    64,     0,   104,   105,   135,     0,
       0,     0,     0,   137,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
       0,    97,    98,     0,   792,     0,   101,   102,   103,    62,
      63,    64,     0,     0,     0,   135,     0,     0,     0,     0,
       0,   137,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,     0,    97,    98,
       0,   848,     0,   101,   102,   103,    62,    63,    64,     0,
       0,     0,   135,     0,     0,     0,     0,     0,   137,     0,
       0,     0,     0,     0,     0,     0,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,     0,    97,    98,     0,     0,     0,
     101,   102,   103,    62,    63,    64,    65,    66,    67,   250,
       0,     0,     0,    69,    70,   137,     0,     0,    71,     0,
       0,     0,     0,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    96,    97,    98,     0,   100,     0,   101,   102,   103,
       0,   358,   154,    63,    64,   104,   105,    67,   155,     0,
       0,     0,   251,     0,     0,   107,     0,     0,     0,     0,
       0,     0,    72,    73,    74,    75,    76,    77,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    87,    88,    89,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,     0,     0,    91,    92,    93,    94,   168,
       0,    97,    98,     0,     0,     0,   101,   102,   103,     0,
       0,   154,    63,    64,   169,   170,    67,   155,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    77,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    87,    88,    89,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,   167,     0,     0,    91,    92,    93,    94,   168,     0,
      97,    98,     0,     0,     0,   101,   102,   103,     0,     0,
     154,    63,    64,   169,   170,    67,   155,     0,     0,     0,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,   156,   157,   158,   159,
     160,   161,   162,   163,   164,    87,    88,    89,   165,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     167,     0,     0,    91,    92,    93,    94,   168,     0,    97,
      98,   154,    63,    64,   101,   102,   103,   155,     0,     0,
       0,     0,   169,   170,     0,     0,     0,     0,     0,   171,
       0,    72,    73,    74,    75,    76,    77,   156,   157,   158,
     159,   160,   161,   162,   163,   164,    87,    88,    89,   165,
     166,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   167,     0,     0,    91,    92,    93,    94,   168,     0,
      97,    98,   154,    63,    64,   101,   102,   103,   155,     0,
       0,     0,     0,   340,   341,     0,     0,     0,     0,     0,
     171,     0,    72,    73,    74,    75,    76,    77,   156,   157,
     158,   159,   160,   161,   162,   163,   164,    87,    88,    89,
     165,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   167,     0,     0,    91,    92,    93,    94,   168,
       0,    97,    98,     0,     0,     0,   101,   102,   103,     0,
       0,    62,    63,    64,   169,   170,    67,   135,     0,     0,
       0,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,     0,
      97,    98,     0,     0,     0,   101,   102,   103,     0,     0,
      62,    63,    64,   104,   105,    67,   317,     0,     0,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,     0,    97,
      98,     0,     0,     0,   101,   102,   103,     0,     0,    62,
      63,    64,   104,   318,    67,   135,     0,     0,     0,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,     0,    97,    98,
       0,     0,     0,   101,   102,   103,     0,     0,    62,    63,
      64,   104,   750,    67,   135,     0,     0,     0,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,     0,    97,    98,    62,
      63,    64,   101,   102,   103,   135,     0,     0,     0,     0,
     104,   829,     0,     0,     0,     0,     0,   137,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,     0,    97,    98,
      62,    63,    64,   101,   102,   103,   135,     0,     0,     0,
       0,   104,   105,     0,     0,     0,     0,     0,   137,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,     0,    97,
      98,     0,     0,     0,   101,   102,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137
};

static const yytype_int16 yycheck[] =
{
      36,    37,   191,   104,   105,   153,    50,    43,   547,   548,
     141,   492,    21,    42,    26,    44,    26,    53,    31,    20,
      49,   107,    37,    20,    60,    61,   271,   272,    16,    17,
      18,    19,    68,    62,   358,   359,    65,    66,    67,    22,
      69,    70,    35,    22,    22,    36,    61,    39,   186,    35,
     346,   347,   118,    68,   107,   121,   352,   353,    24,    25,
      94,    55,    96,    39,    40,    41,    14,    15,   169,   170,
     106,   107,    32,    33,    34,    35,    36,    37,   107,    27,
      60,    32,    33,    34,    35,    36,    37,   117,   124,    52,
     118,   106,   106,   121,   124,   169,   170,     0,   134,   135,
     136,   137,    39,   115,   116,   115,   116,   143,   121,   124,
     146,    27,   148,   118,   126,    52,   126,   126,   119,   155,
     135,   106,   119,   117,    21,   154,   118,   107,    22,   122,
     121,   119,   321,   107,   168,   171,   122,   107,   121,   121,
     155,   106,   121,   121,   126,   181,   182,   123,   393,   115,
     116,   180,   115,   116,   134,   115,   116,    35,   187,    53,
      54,   107,    56,    57,   115,   116,   181,   203,   197,   205,
     651,   207,   123,   209,   203,   306,   205,   107,    94,    95,
     107,   217,   218,   219,   220,    51,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   106,   235,
     236,   237,   498,    32,    33,   241,   242,   243,   244,   115,
     116,    89,   118,    91,   250,   251,    21,   318,    51,    52,
      39,   115,   116,   203,   763,   205,   115,   116,    21,   553,
     554,   555,    51,    52,   123,   250,    51,   273,   274,   275,
     122,   277,   278,   279,   280,   281,   282,   283,    21,   115,
     116,    32,    33,    34,    35,    36,    37,   237,   273,   274,
     275,   241,   242,   243,   244,    51,   340,   341,   121,   305,
     123,   307,   308,   309,   310,   349,    39,    40,    41,   315,
     354,   317,   115,   116,   320,   122,   115,   116,    32,    33,
      34,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     115,   116,   317,    29,   493,   286,   287,   288,   289,   290,
      32,    33,    34,    35,    36,    37,   797,    59,    60,    39,
      40,    41,   358,   359,   121,   305,   123,   363,   122,   115,
     116,    51,   368,   369,   115,   116,    32,    33,    34,    35,
      36,    37,   123,    51,    52,    32,    33,    34,    35,    36,
      37,   121,   388,   123,   390,   118,   392,    53,    54,    51,
      56,    57,    32,    33,    34,    35,    36,    37,   349,   350,
     351,   115,   116,   354,   121,   117,   123,   392,    32,    33,
      34,    51,   124,    53,    54,   122,    56,    57,    32,    33,
     426,    59,    60,   115,   116,   431,   432,    51,    32,    33,
      34,   123,   383,    35,   121,   386,    33,   115,   116,   126,
     391,    32,    33,    34,    46,    47,   121,    49,   123,   115,
     116,    53,    54,   115,   116,   107,    58,   123,   115,   116,
      51,    39,    40,    41,    52,    23,    51,    52,   122,   475,
     476,   115,   116,   479,   118,   115,   116,    84,   484,   117,
     494,   122,   496,   122,   490,   122,   124,    89,    90,    91,
     122,   115,   116,   499,   121,   761,   123,    51,    52,   101,
     122,   115,   116,   105,    52,   490,   115,   116,   115,   116,
      51,   115,   116,   119,   123,    52,   522,   571,   572,   573,
     122,    35,   521,   125,   115,   116,   122,   115,   116,   479,
     115,   116,    46,    47,   652,    49,   654,   522,   122,    53,
      54,   547,   548,   122,    58,   123,    35,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,    46,    47,    52,
      49,   115,   116,   122,    53,    54,   122,   115,   116,    58,
     122,   577,   578,   579,   115,   116,    90,   685,   115,   116,
     115,   116,   690,   691,    39,    40,    41,   101,   123,   122,
     589,   105,   591,   122,   579,    52,   755,    52,   604,   605,
     121,    90,   123,    51,    52,    53,   120,    52,   122,   115,
     116,   125,   101,   122,   620,   121,   105,   123,   115,   116,
     626,   122,   115,   116,   121,    53,    54,   633,    56,    57,
      39,    40,    41,   122,   115,   116,   125,    52,    35,   645,
      53,    54,   648,    56,    57,   126,   115,   116,   633,    46,
      47,   121,    49,   123,   123,   122,    53,    54,   115,   116,
     122,    58,   668,   669,    53,    54,   122,    56,    57,   122,
     115,   116,    32,    33,    34,    35,    36,    37,   122,   750,
      32,    33,    34,    35,    36,    37,   122,   115,   116,   115,
     116,    51,   118,    90,   121,   123,   123,    51,    52,    53,
     115,   116,   115,   116,   101,   118,   712,   713,   105,   715,
     716,    52,   115,   116,   768,   769,   770,   771,   121,   115,
     116,   727,   728,   171,   122,   122,   115,   116,   125,   735,
     126,   737,   121,   121,   182,    53,    54,    52,    56,    57,
      52,   747,   727,    52,   852,   853,   752,   855,   856,   122,
     858,   859,    52,   861,   862,   115,   116,   763,   829,   765,
     766,    16,    17,   115,   116,    53,    54,   122,    56,    57,
     776,   777,   115,   116,   115,   116,   122,   783,   784,   115,
     116,   787,   836,   126,   838,   121,   840,   793,   842,    32,
      33,    34,    35,    36,    37,    61,    62,   115,   116,   122,
     115,   116,    21,   115,   116,   123,   115,   116,   115,   116,
      53,    54,    23,    56,    57,   115,   116,   171,   115,   116,
     115,   116,   828,   118,   830,   831,   123,   115,   116,   835,
     118,   837,   121,   839,   123,   841,   284,   285,    52,   845,
     894,   895,   896,   897,   898,   899,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,    56,    57,    58,    46,
      47,    52,    49,   869,   870,   871,   872,   873,   874,   875,
     876,    58,   115,   116,    53,    54,    52,    56,    57,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   115,   116,    53,    54,    20,    56,    57,   346,   347,
      52,   115,   116,    90,   352,   353,    52,   120,   115,   116,
     358,   359,   120,   121,   101,   363,   123,   118,   105,   121,
     368,   369,   115,   116,   115,   116,   115,   116,    16,    17,
     123,    22,   380,    30,   123,   122,   115,   116,   125,   115,
     116,   118,   115,   116,   123,    22,   115,   116,    53,    54,
     123,    56,    57,   120,    31,   115,   116,    32,    35,   120,
      52,   121,    61,   115,   116,    52,    43,    44,    45,   115,
     116,    48,    49,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   122,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,   122,   359,    83,   115,   116,   363,
     115,   116,   122,   121,   368,   369,   121,    63,    64,    96,
      97,    98,    99,   115,   116,   102,   103,   122,   115,   116,
     107,   108,   109,    53,    54,   118,    56,    57,   115,   116,
     122,    39,    40,    41,   122,   122,    39,    40,    41,   122,
     498,   499,    50,   122,   122,   115,   116,    50,   122,    51,
     122,    53,    54,   123,    56,    57,   122,    35,    21,    53,
      54,    21,    56,    57,   115,   116,    21,    21,    46,    47,
      21,    49,   123,    21,   532,    53,    54,   115,   116,    21,
      58,    46,    47,   121,    49,   115,   116,    21,    53,   547,
     548,   115,   116,    58,   118,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   101,    90,   115,   116,    20,    35,   575,    39,    40,
      41,   115,   116,   101,   118,    90,    20,   105,    21,    50,
      46,    47,   118,    49,   118,   499,   101,    53,    54,    21,
     105,    21,    58,   107,   122,   115,   116,   125,   115,   116,
      52,    53,    54,   123,    56,    57,   123,   122,    39,    21,
     125,    39,    40,    41,    39,    40,    41,    20,   532,    39,
      40,    41,    50,   123,    90,    50,    39,    40,    41,    20,
      50,    20,    20,   547,   548,   101,   123,    50,   123,   105,
     123,   122,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   122,   122,    36,    37,   125,
     122,   575,    41,   115,   116,   673,   674,   675,   676,   677,
     678,   679,   680,   681,    39,    40,    41,    39,    40,    41,
     115,   116,    61,   122,   122,    50,   121,    21,    50,    68,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    39,    40,    41,   122,   115,   116,   122,    21,   115,
     116,   122,    50,   123,   115,   116,   118,   123,   115,   116,
     115,   116,   123,   115,   116,   118,   123,   106,   123,   115,
     116,   123,   115,   116,   115,   116,   126,   123,   115,   116,
     123,   118,   123,   115,   116,   124,   125,   122,   122,   122,
     758,   123,    39,   761,   762,   763,   135,   765,   766,   673,
     674,   675,   676,   677,   678,   679,   680,   681,    39,   115,
     116,   115,   116,   115,   116,   123,   155,   123,   121,   123,
      21,   123,   115,   116,   115,   116,   115,   116,    36,    37,
     123,    21,   123,   118,   123,    43,   115,   116,   115,   116,
     115,   116,   181,    52,   123,    52,   123,   118,   123,   115,
     116,   115,   116,    61,   115,   116,   118,   123,    51,   123,
      68,   118,   123,    51,   115,   116,   637,   835,   207,   837,
     209,   839,   123,   841,   473,   323,   215,   216,   115,   116,
     484,   304,   221,   574,   758,   363,   123,   294,   762,   763,
      -1,   765,   766,   110,   111,   112,   113,   114,   106,   107,
      -1,   869,   870,   871,   872,   873,   874,   875,   876,   115,
     116,   250,   251,   394,    -1,   107,   124,   123,   115,   116,
     259,   260,   261,   262,   263,   264,   123,   135,    -1,    -1,
     115,   116,   115,   116,   273,   274,   275,   276,   123,    -1,
     123,   115,   116,   115,   116,   115,   116,   155,    -1,   123,
      -1,   123,    -1,   123,   115,   116,   295,    -1,   115,   116,
      -1,   835,   123,   837,    22,   839,   123,   841,    85,    86,
      87,    88,    -1,   181,    -1,    -1,    -1,    35,   317,   265,
     266,   267,   268,   269,   270,    43,    44,    45,    -1,    -1,
      48,    49,    -1,    -1,    -1,   869,   870,   871,   872,   873,
     874,   875,   876,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    -1,    -1,    83,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,
      98,    99,   250,    -1,   102,   103,    -1,    -1,    43,   107,
     108,   109,    -1,   392,    49,    -1,    -1,   115,   116,    -1,
      -1,    -1,    -1,    -1,   122,   273,   274,   275,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    81,    82,    -1,   297,
      -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,   317,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,   116,    -1,    -1,    -1,    -1,   465,   122,    28,    -1,
      -1,    -1,    -1,   472,   473,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    47,    48,    49,
      -1,   490,    -1,    53,    54,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    -1,   522,   392,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    -1,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,   115,   116,    -1,   426,    -1,
     428,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     579,   580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   473,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   484,    -1,    -1,    -1,
      -1,    -1,   490,    -1,    -1,    28,    -1,   626,    -1,    -1,
      -1,    -1,    35,    -1,   633,   634,   635,    -1,    -1,    42,
      43,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    54,    -1,    -1,   522,    58,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,   101,   102,
     103,   104,   105,    -1,   107,   108,   109,    -1,    27,    -1,
      -1,   579,   115,   116,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,   125,    -1,    43,    44,    45,   726,   727,    48,
      49,   599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    -1,   633,    -1,    -1,    -1,   637,
      -1,    -1,    -1,    92,    93,    -1,    -1,    96,    97,    98,
      99,   100,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,    35,
      -1,    -1,    -1,   122,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    53,    54,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    -1,    -1,    -1,    -1,   727,
      96,    97,    98,    99,    -1,   101,   102,   103,    -1,   105,
      -1,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,   115,
     116,    -1,    -1,    35,    -1,    -1,   122,    -1,    -1,   125,
     126,    43,    44,    45,    46,    47,    48,    49,    -1,    -1,
      -1,    53,    54,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,   101,
     102,   103,    35,   105,    -1,   107,   108,   109,    -1,    -1,
      43,    44,    45,   115,   116,    48,    49,    -1,    -1,    -1,
     122,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    36,    -1,   107,   108,   109,    -1,    -1,    43,
      44,    45,   115,   116,    48,    49,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,    38,
      -1,   115,   116,    -1,    43,    44,    45,    -1,   122,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    -1,   107,   108,
     109,    -1,    -1,    -1,    38,    -1,   115,   116,    -1,    43,
      44,    45,    -1,   122,    48,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,    38,
      -1,   115,   116,    -1,    43,    44,    45,    -1,   122,    48,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,    -1,    -1,    38,   107,   108,
     109,    -1,    43,    44,    45,    -1,   115,   116,    49,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
      -1,   102,   103,    -1,    38,    -1,   107,   108,   109,    43,
      44,    45,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
      -1,    38,    -1,   107,   108,   109,    43,    44,    45,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,    -1,    -1,    -1,
     107,   108,   109,    43,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    53,    54,   122,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,   101,   102,   103,    -1,   105,    -1,   107,   108,   109,
      -1,    42,    43,    44,    45,   115,   116,    48,    49,    -1,
      -1,    -1,   122,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    96,    97,    98,    99,   100,
      -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    43,    44,    45,   115,   116,    48,    49,    -1,    -1,
      -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    93,    -1,    -1,    96,    97,    98,    99,   100,    -1,
     102,   103,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      43,    44,    45,   115,   116,    48,    49,    -1,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    96,    97,    98,    99,   100,    -1,   102,
     103,    43,    44,    45,   107,   108,   109,    49,    -1,    -1,
      -1,    -1,   115,   116,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    96,    97,    98,    99,   100,    -1,
     102,   103,    43,    44,    45,   107,   108,   109,    49,    -1,
      -1,    -1,    -1,   115,   116,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    96,    97,    98,    99,   100,
      -1,   102,   103,    -1,    -1,    -1,   107,   108,   109,    -1,
      -1,    43,    44,    45,   115,   116,    48,    49,    -1,    -1,
      -1,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,
      43,    44,    45,   115,   116,    48,    49,    -1,    -1,    -1,
     122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    43,
      44,    45,   115,   116,    48,    49,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,    43,    44,
      45,   115,   116,    48,    49,    -1,    -1,    -1,   122,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,    43,
      44,    45,   107,   108,   109,    49,    -1,    -1,    -1,    -1,
     115,   116,    -1,    -1,    -1,    -1,    -1,   122,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
      43,    44,    45,   107,   108,   109,    49,    -1,    -1,    -1,
      -1,   115,   116,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,    -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    21,   128,   129,   132,   133,   134,   135,   137,
     140,   150,   151,   163,   166,   107,   107,   107,   107,   107,
     107,   107,   106,   106,   106,   106,    14,    15,    27,   167,
       0,    20,   119,    20,   119,    16,    17,    18,    19,   119,
     141,    21,    21,    21,    21,   122,   122,   122,   122,    28,
      35,    42,    43,    44,    45,    46,    47,    48,    49,    53,
      54,    58,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      90,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   107,   108,   109,   115,   116,   122,   125,   170,   171,
     172,   173,   177,   178,   180,   181,   182,   183,   184,   185,
     170,   177,   178,   181,    49,   122,   168,   169,   170,   178,
     118,   170,   120,   168,    22,    49,    83,   122,   138,   146,
     147,   148,   174,   178,   181,   168,    29,   144,    33,   142,
      16,    17,   168,   142,    43,    49,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    81,    82,    93,   100,   115,
     116,   122,   158,   159,   160,   161,   162,   181,   182,   158,
      27,    49,    92,   152,   153,   158,   181,    27,    94,    95,
     164,   165,   107,   136,   136,   136,   136,   122,    36,   180,
     181,   177,   168,   122,   169,   122,   169,   122,   168,   122,
     168,   168,   177,   168,   168,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   119,   179,   179,
     179,   122,   122,   122,   122,   184,   184,   170,   177,   181,
      49,   122,   126,   168,   174,   176,   178,   180,   181,    32,
      33,    34,    35,    36,    37,    53,    54,    56,    57,   115,
     116,    55,   117,    39,    40,    41,    23,   121,    32,    33,
      34,    35,    36,    37,   115,   116,    59,    60,   117,   124,
      61,    62,   177,   170,    21,    23,   118,    20,   120,   180,
     177,   181,   181,   118,   121,   148,   149,    85,    86,    87,
      88,   175,   181,   120,   181,    30,   145,    49,   116,   181,
      32,   143,   118,   120,   143,   168,   177,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   179,
     115,   116,   160,   160,   158,   181,   115,   116,   118,   117,
     124,    61,   115,   116,   117,   118,   168,   177,    42,   122,
     154,   158,   181,    39,   118,    32,    33,    34,   157,   157,
     168,   118,   144,   121,   123,   123,   123,   123,   168,    36,
      21,   168,   180,    21,   168,   180,    21,   181,    21,   181,
      21,    21,    50,    21,    21,   170,   170,   181,   181,   181,
     181,   170,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   101,   181,   181,   180,   180,   180,
     180,   180,   123,   123,   123,   177,    21,   126,   121,   126,
     126,    24,    25,   170,   170,   170,   170,   170,   170,   171,
     171,   171,   171,   171,   171,   173,   173,   177,   177,   177,
     170,   181,   181,   181,   181,   181,   181,   181,   182,   182,
     183,   183,   183,   183,   183,    50,   167,   170,    89,    91,
     130,   131,   178,    20,    22,    50,    84,   147,   180,   148,
     181,   181,   181,   181,    20,   181,   118,   177,    38,    38,
      49,   181,   144,    16,    17,    19,   141,   118,    21,    50,
     158,   181,   158,   181,   158,   181,   158,   181,   158,   181,
     158,   181,   158,   181,   158,   181,   158,   181,   158,   158,
     158,    43,    49,    69,    70,    71,    72,    73,    74,    75,
      76,    77,   122,   123,   159,   182,   159,   182,   160,   183,
     183,   183,   159,   182,   159,   182,   160,    21,    50,   154,
     154,   158,   181,    39,    40,    41,    50,    32,    33,    34,
      35,    36,    37,    32,    33,    34,    35,    36,    37,   153,
     158,   181,   158,   181,    21,    21,   107,    20,    20,    20,
      20,   123,   182,   123,   123,   183,   123,   123,   183,   123,
     181,   123,   181,   183,   170,   177,   181,   173,   172,   121,
     123,   123,   123,   123,   121,   121,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     121,   120,   123,   123,   123,   123,    50,   178,   181,   178,
     181,   181,   170,    22,   122,   122,   118,   121,   170,   130,
     170,   181,   181,    22,   180,    31,   146,   181,    50,   177,
     145,   144,   142,    16,   142,   159,   182,   158,   181,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   121,   121,
     123,   168,   177,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   152,   152,   158,   181,   123,   154,   154,   154,
     158,   181,   158,   181,   158,   181,   158,   181,   158,   181,
     158,   181,   158,   181,   158,   158,   158,   158,   158,   158,
     155,   155,    32,    33,   155,    32,    33,   155,   164,   158,
     181,   181,   177,   170,   168,   168,    51,    51,    51,   178,
     181,   181,   181,   126,   126,    26,   126,    26,   126,   177,
     170,   170,   131,   118,   118,    22,   181,    31,   139,   118,
     116,   181,    50,   118,   145,   143,   118,   143,    51,   181,
     181,    21,    50,    51,    52,   157,   157,   121,   181,   181,
     181,   181,   118,   118,   118,   118,    21,    21,   170,   177,
     181,   123,   123,   121,   121,   181,   181,   121,   123,   118,
     181,   118,    38,    51,    38,   181,   118,   144,   118,   158,
     123,   123,   182,   152,   158,   181,   158,   181,   110,   111,
     112,   113,   114,   156,   155,   155,   155,   155,   181,   181,
      52,    52,    52,   181,   181,   126,   126,   181,    51,   116,
      51,    51,   145,    52,    52,    51,    52,    51,    52,    51,
      52,    51,    52,   123,   123,   121,   123,   181,    38,   181,
      38,   118,   158,   181,   155,   158,   181,   155,   158,   181,
     155,   158,   181,   155,   181,    52,    52,    52,    52,   157,
     157,   157,   157,   157,   157,   157,   157,   123,   158,   181,
     158,   181,   158,   181,   158,   181,   158,   181,   158,   181,
     158,   181,   158,   181,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   129,   129,   129,   129,   130,   130,   130,
     130,   130,   131,   132,   133,   134,   135,   136,   136,   137,
     137,   137,   137,   137,   138,   138,   139,   139,   140,   140,
     140,   140,   140,   140,   140,   140,   141,   141,   141,   142,
     142,   142,   142,   142,   143,   143,   143,   143,   143,   144,
     144,   145,   145,   146,   146,   146,   146,   147,   148,   149,
     149,   150,   150,   151,   152,   152,   152,   152,   152,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     155,   155,   156,   156,   156,   156,   156,   157,   157,   157,
     158,   158,   158,   158,   158,   158,   158,   159,   159,   159,
     159,   159,   160,   160,   160,   161,   161,   161,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   163,   164,   164,   165,   165,   165,   166,
     167,   167,   167,   167,   167,   167,   167,   168,   168,   169,
     169,   170,   170,   170,   170,   170,   170,   170,   171,   171,
     172,   172,   172,   172,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   174,   174,   175,   175,   175,   175,
     176,   176,   176,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   178,   178,   179,   179,   180,   180,
     181,   181,   181,   182,   182,   182,   182,   182,   182,   183,
     183,   183,   184,   184,   184,   184,   184,   184,   184,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     8,     8,     7,     1,     3,     6,
       8,     4,     2,     8,     8,     8,     8,     1,     3,     9,
       8,     9,     5,     1,     1,     1,     0,     2,     9,     6,
       8,     5,     9,     6,    11,     8,     0,     1,     2,     0,
       2,     3,     9,     9,     0,     2,     2,     8,     8,     0,
       2,     0,     2,     1,     3,     1,     2,     2,     3,     3,
       4,     5,     5,     5,     1,     3,     4,     5,     7,     4,
       4,     4,     4,     6,     6,     6,     6,    12,    12,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,     8,     8,     8,     8,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     2,     2,     1,     3,     4,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       6,     7,     3,     5,     4,     4,     0,     1,     1,     3,
       2,     2,     2,     2,     2,     2,     4,     1,     1,     5,
       3,     1,     3,     3,     3,     3,     3,     3,     1,     4,
       1,     3,     3,     4,     2,     4,     2,     7,     5,     7,
       5,     4,     7,     4,     7,     3,     3,     3,     3,     5,
       5,     6,     4,     7,     4,     2,     2,     2,     2,     2,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     4,     4,     7,     2,     3,     0,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     4,     1,
       2,     2,     1,     3,     4,     4,     4,     4,     4,     1,
       1,     1,     2,     2,     4,     4,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     4,     8,     6,     7,     8,     4,
       4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 156 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { code_set_root((yyvsp[0].code)); }
#line 2520 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 3:
#line 157 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { code_set_root((yyvsp[0].code)); }
#line 2526 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 4:
#line 158 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { code_set_root((yyvsp[0].code)); }
#line 2532 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 5:
#line 159 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { code_set_root((yyvsp[0].code)); }
#line 2538 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 6:
#line 160 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { code_set_root((yyvsp[0].code)); }
#line 2544 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 7:
#line 161 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { code_set_root((yyvsp[0].code)); }
#line 2550 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 8:
#line 162 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { code_set_root((yyvsp[0].code)); }
#line 2556 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 9:
#line 163 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { code_set_root((yyvsp[0].code)); }
#line 2562 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 10:
#line 164 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { code_set_root((yyvsp[0].code)); }
#line 2568 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { code_set_root((yyvsp[0].code)); }
#line 2574 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 12:
#line 166 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { code_set_root((yyvsp[0].code)); }
#line 2580 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 13:
#line 174 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_set1, 3,
            code_new_name((yyvsp[-3].name)),                                       /* Name */
            code_new_inst(i_idxset_pseudo_new, 1,               /* index set */
               code_new_inst(i_bool_true, 0)),              
            (yyvsp[-1].code));                                              /* initial set */
      }
#line 2592 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 14:
#line 181 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_set1, 3,
            code_new_name((yyvsp[-6].name)),                                       /* Name */
            (yyvsp[-4].code),                                                 /* index set */
            (yyvsp[-1].code));                                                      /* set */
      }
#line 2603 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 15:
#line 187 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_set2, 3,
            code_new_name((yyvsp[-6].name)),                                       /* Name */
            (yyvsp[-4].code),                                                 /* index set */
            (yyvsp[-1].code));                                   /* initial set_entry_list */
      }
#line 2614 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 16:
#line 193 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_set2, 3,
            code_new_name((yyvsp[-5].name)),                                       /* Name */
            code_new_inst(i_idxset_pseudo_new, 1,               /* index set */
               code_new_inst(i_bool_true, 0)),              
            (yyvsp[-1].code));                                   /* initial set_entry_list */
      }
#line 2626 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 17:
#line 203 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_entry_list_new, 1, (yyvsp[0].code)); }
#line 2632 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 18:
#line 204 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_entry_list_add, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 2640 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 19:
#line 207 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_entry_list_subsets, 3, (yyvsp[-3].code), (yyvsp[-1].code), code_new_numb(numb_new_integer(-1)));
      }
#line 2648 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 20:
#line 210 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_entry_list_subsets, 3, (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code));
      }
#line 2656 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 21:
#line 213 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_entry_list_powerset, 1, (yyvsp[-1].code));
      }
#line 2664 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 22:
#line 219 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_entry, 2, (yyvsp[-1].code), (yyvsp[0].code)); }
#line 2670 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 23:
#line 228 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newdef, 3,
            code_new_define((yyvsp[-6].def)),
            code_new_inst(i_tuple_new, 1, (yyvsp[-4].code)),
            (yyvsp[-1].code));
      }
#line 2681 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 24:
#line 237 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newdef, 3,
            code_new_define((yyvsp[-6].def)),
            code_new_inst(i_tuple_new, 1, (yyvsp[-4].code)),
            (yyvsp[-1].code));
      }
#line 2692 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 25:
#line 246 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newdef, 3,
            code_new_define((yyvsp[-6].def)),
            code_new_inst(i_tuple_new, 1, (yyvsp[-4].code)),
            (yyvsp[-1].code));
      }
#line 2703 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 26:
#line 255 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newdef, 3,
            code_new_define((yyvsp[-6].def)),
            code_new_inst(i_tuple_new, 1, (yyvsp[-4].code)),
            (yyvsp[-1].code));
      }
#line 2714 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 27:
#line 264 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_elem_list_new, 1, code_new_name((yyvsp[0].name)));
      }
#line 2722 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 28:
#line 267 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_elem_list_add, 2, (yyvsp[-2].code), code_new_name((yyvsp[0].name)));
      }
#line 2730 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 29:
#line 277 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_para1, 4, code_new_name((yyvsp[-7].name)), (yyvsp[-5].code), (yyvsp[-2].code), (yyvsp[-1].code));
      }
#line 2738 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 30:
#line 280 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_para2, 4, code_new_name((yyvsp[-6].name)), (yyvsp[-4].code), (yyvsp[-1].code), code_new_inst(i_nop, 0));
      }
#line 2746 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 31:
#line 283 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_para2, 4, code_new_name((yyvsp[-7].name)), (yyvsp[-5].code), (yyvsp[-1].code), code_new_inst(i_nop, 0));
      }
#line 2754 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 32:
#line 286 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_para1, 4,
            code_new_name((yyvsp[-3].name)),
            code_new_inst(i_idxset_pseudo_new, 1, code_new_inst(i_bool_true, 0)),
            (yyvsp[-1].code),
            code_new_inst(i_nop, 0));
      }
#line 2766 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 33:
#line 293 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_nop, 0); }
#line 2772 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 34:
#line 296 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[0].code); }
#line 2778 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 35:
#line 297 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_entry_list_new, 1,
            code_new_inst(i_entry, 2, code_new_inst(i_tuple_empty, 0), (yyvsp[0].code)));
      }
#line 2787 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 36:
#line 304 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_nop, 0); }
#line 2793 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 37:
#line 305 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_entry, 2, code_new_inst(i_tuple_empty, 0), (yyvsp[0].code)); }
#line 2799 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 38:
#line 313 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_var, 7,
            code_new_name((yyvsp[-7].name)),
            (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-2].code), (yyvsp[-1].code),
            code_new_numb(numb_copy(numb_unknown())),
            code_new_numb(numb_copy(numb_unknown())));
      }
#line 2811 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 39:
#line 320 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_var, 7,
            code_new_name((yyvsp[-4].name)),
            code_new_inst(i_idxset_pseudo_new, 1,
               code_new_inst(i_bool_true, 0)),              
            (yyvsp[-3].code), (yyvsp[-2].code), (yyvsp[-1].code),
            code_new_numb(numb_copy(numb_unknown())),
            code_new_numb(numb_copy(numb_unknown())));
      }
#line 2825 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 40:
#line 329 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_var, 7,
            code_new_name((yyvsp[-6].name)),
            (yyvsp[-4].code),
            code_new_varclass(VAR_IMP),
            code_new_inst(i_bound_new, 1, code_new_numb(numb_new_integer(0))),
            code_new_inst(i_bound_new, 1, code_new_numb(numb_new_integer(1))),
            code_new_numb(numb_copy(numb_unknown())),
            code_new_numb(numb_copy(numb_unknown())));
      }
#line 2840 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 41:
#line 339 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_var, 7,
            code_new_name((yyvsp[-3].name)),
            code_new_inst(i_idxset_pseudo_new, 1,
               code_new_inst(i_bool_true, 0)),              
            code_new_varclass(VAR_IMP),
            code_new_inst(i_bound_new, 1, code_new_numb(numb_new_integer(0))),
            code_new_inst(i_bound_new, 1, code_new_numb(numb_new_integer(1))),
            code_new_numb(numb_copy(numb_unknown())),
            code_new_numb(numb_copy(numb_unknown())));
      }
#line 2856 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 42:
#line 350 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_var, 7,
            code_new_name((yyvsp[-7].name)),
            (yyvsp[-5].code),
            code_new_varclass(VAR_INT),
            code_new_inst(i_bound_new, 1, code_new_numb(numb_new_integer(0))),
            code_new_inst(i_bound_new, 1, code_new_numb(numb_new_integer(1))),
            (yyvsp[-2].code), (yyvsp[-1].code));
      }
#line 2870 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 43:
#line 359 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_var, 7,
            code_new_name((yyvsp[-4].name)),
            code_new_inst(i_idxset_pseudo_new, 1,
               code_new_inst(i_bool_true, 0)),              
            code_new_varclass(VAR_INT),
            code_new_inst(i_bound_new, 1, code_new_numb(numb_new_integer(0))),
            code_new_inst(i_bound_new, 1, code_new_numb(numb_new_integer(1))),
            (yyvsp[-2].code), (yyvsp[-1].code));
      }
#line 2885 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 44:
#line 369 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_var, 7,
            code_new_name((yyvsp[-9].name)), (yyvsp[-7].code), code_new_varclass(VAR_INT), (yyvsp[-4].code), (yyvsp[-3].code), (yyvsp[-2].code), (yyvsp[-1].code));
      }
#line 2894 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 45:
#line 373 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_newsym_var, 7,
            code_new_name((yyvsp[-6].name)),
            code_new_inst(i_idxset_pseudo_new, 1,
               code_new_inst(i_bool_true, 0)),              
            code_new_varclass(VAR_INT), (yyvsp[-4].code), (yyvsp[-3].code), (yyvsp[-2].code), (yyvsp[-1].code));
      }
#line 2906 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 46:
#line 383 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_varclass(VAR_CON); }
#line 2912 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 47:
#line 384 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_varclass(VAR_CON); }
#line 2918 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 48:
#line 385 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_varclass(VAR_IMP); }
#line 2924 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 49:
#line 389 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_bound_new, 1, code_new_numb(numb_new_integer(0)));
      }
#line 2932 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 50:
#line 392 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bound_new, 1, (yyvsp[0].code)); }
#line 2938 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 51:
#line 393 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_bound(BOUND_MINUS_INFTY); }
#line 2944 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 52:
#line 394 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_if_else, 3, (yyvsp[-6].code),
            code_new_inst(i_bound_new, 1, (yyvsp[-4].code)),
            code_new_bound(BOUND_MINUS_INFTY));
      }
#line 2954 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 53:
#line 399 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_if_else, 3, (yyvsp[-6].code),
            code_new_bound(BOUND_MINUS_INFTY),
            code_new_inst(i_bound_new, 1, (yyvsp[-1].code)));
      }
#line 2964 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 54:
#line 407 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_bound(BOUND_INFTY); }
#line 2970 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 55:
#line 408 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bound_new, 1, (yyvsp[0].code)); }
#line 2976 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 56:
#line 409 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_bound(BOUND_INFTY); }
#line 2982 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 57:
#line 410 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_if_else, 3, (yyvsp[-5].code),
            code_new_inst(i_bound_new, 1, (yyvsp[-3].code)),
            code_new_bound(BOUND_INFTY));
      }
#line 2992 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 58:
#line 415 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_if_else, 3, (yyvsp[-5].code),
            code_new_bound(BOUND_INFTY),
            code_new_inst(i_bound_new, 1, (yyvsp[-1].code)));
      }
#line 3002 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 59:
#line 423 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_numb(numb_new_integer(0)); }
#line 3008 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 60:
#line 424 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[0].code); }
#line 3014 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 61:
#line 428 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_numb(numb_copy(numb_unknown())); }
#line 3020 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 62:
#line 429 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[0].code); }
#line 3026 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 63:
#line 437 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_entry_list_new, 1, (yyvsp[0].code)); }
#line 3032 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 64:
#line 438 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_entry_list_add, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 3040 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 65:
#line 441 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_read, 1, (yyvsp[0].code)); }
#line 3046 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 66:
#line 442 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_list_matrix, 2, (yyvsp[-1].code), (yyvsp[0].code)); }
#line 3052 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 67:
#line 446 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_entry, 2, (yyvsp[-1].code), (yyvsp[0].code)); }
#line 3058 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 68:
#line 450 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[-1].code); }
#line 3064 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 69:
#line 454 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_matrix_list_new, 2, (yyvsp[-2].code), (yyvsp[-1].code));
      }
#line 3072 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 70:
#line 457 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_matrix_list_add, 3, (yyvsp[-3].code), (yyvsp[-2].code), (yyvsp[-1].code));
      }
#line 3080 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 71:
#line 469 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_object_min, 2, code_new_name((yyvsp[-3].name)), (yyvsp[-1].code));
      }
#line 3088 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 72:
#line 472 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_object_max, 2, code_new_name((yyvsp[-3].name)), (yyvsp[-1].code));
      }
#line 3096 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 73:
#line 482 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_subto, 2, code_new_name((yyvsp[-3].name)), (yyvsp[-1].code));
     }
#line 3104 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 74:
#line 488 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_constraint_list, 2, (yyvsp[0].code), code_new_inst(i_nop, 0));
     }
#line 3112 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 75:
#line 491 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_constraint_list, 2, (yyvsp[-2].code), (yyvsp[0].code));
     }
#line 3120 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 76:
#line 494 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_constraint_list, 2, 
           code_new_inst(i_forall, 2, (yyvsp[-2].code), (yyvsp[0].code)),
           code_new_inst(i_nop, 0));
     }
#line 3130 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 77:
#line 499 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_constraint_list, 2, 
           code_new_inst(i_expr_if_else, 3, (yyvsp[-3].code), (yyvsp[-1].code), code_new_inst(i_nop, 0)),
           code_new_inst(i_nop, 0));
      }
#line 3140 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 78:
#line 504 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_constraint_list, 2, 
           code_new_inst(i_expr_if_else, 3, (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code)),
           code_new_inst(i_nop, 0));
      }
#line 3150 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 79:
#line 512 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_constraint, 4, (yyvsp[-3].code), (yyvsp[-2].code), (yyvsp[-1].code), code_new_bits((yyvsp[0].bits)));
     }
#line 3158 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 80:
#line 515 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_constraint, 4, (yyvsp[-3].code), (yyvsp[-2].code),
           code_new_inst(i_term_expr, 1, (yyvsp[-1].code)),
           code_new_bits((yyvsp[0].bits)));
     }
#line 3168 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 81:
#line 520 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_constraint, 4,
           code_new_inst(i_term_expr, 1, (yyvsp[-3].code)),
           (yyvsp[-2].code), (yyvsp[-1].code), code_new_bits((yyvsp[0].bits)));
     }
#line 3178 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 82:
#line 525 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
        (yyval.code) = code_new_inst(i_constraint, 4,
           code_new_inst(i_term_expr, 1, (yyvsp[-3].code)),
           (yyvsp[-2].code),
           code_new_inst(i_term_expr, 1, (yyvsp[-1].code)),
           code_new_bits((yyvsp[0].bits)));
     }
#line 3190 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 83:
#line 532 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_rangeconst, 6, (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code), (yyvsp[-4].code),
           code_new_contype(CON_RHS), code_new_bits((yyvsp[0].bits))); 
     }
#line 3199 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 84:
#line 536 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_rangeconst, 6, (yyvsp[-5].code),
           code_new_inst(i_term_expr, 1, (yyvsp[-3].code)), (yyvsp[-1].code), (yyvsp[-4].code),
           code_new_contype(CON_RHS), code_new_bits((yyvsp[0].bits))); 
     }
#line 3209 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 85:
#line 541 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_rangeconst, 6, (yyvsp[-1].code), (yyvsp[-3].code), (yyvsp[-5].code), (yyvsp[-4].code),
           code_new_contype(CON_LHS), code_new_bits((yyvsp[0].bits))); 
     }
#line 3218 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 86:
#line 545 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_rangeconst, 6, (yyvsp[-1].code),
           code_new_inst(i_term_expr, 1, (yyvsp[-3].code)),
           (yyvsp[-5].code), (yyvsp[-4].code),
           code_new_contype(CON_LHS), code_new_bits((yyvsp[0].bits))); 
     }
#line 3229 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 87:
#line 551 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code), (yyvsp[-8].code), (yyvsp[-7].code), (yyvsp[-6].code), (yyvsp[-4].code), (yyvsp[-3].code), (yyvsp[-2].code), code_new_bits((yyvsp[0].bits)));
      }
#line 3237 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 88:
#line 554 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-8].code)),
            (yyvsp[-7].code), (yyvsp[-6].code), (yyvsp[-4].code), (yyvsp[-3].code), (yyvsp[-2].code), code_new_bits((yyvsp[0].bits)));
      }
#line 3247 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 89:
#line 559 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code), (yyvsp[-8].code), (yyvsp[-7].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-6].code)),
            (yyvsp[-4].code), (yyvsp[-3].code), (yyvsp[-2].code), code_new_bits((yyvsp[0].bits)));
      }
#line 3257 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 90:
#line 564 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code), (yyvsp[-8].code), (yyvsp[-7].code), (yyvsp[-6].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-4].code)),
            (yyvsp[-3].code), (yyvsp[-2].code), code_new_bits((yyvsp[0].bits)));
      }
#line 3267 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 91:
#line 569 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code), (yyvsp[-8].code), (yyvsp[-7].code), (yyvsp[-6].code), (yyvsp[-4].code), (yyvsp[-3].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), code_new_bits((yyvsp[0].bits)));
      }
#line 3276 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 92:
#line 573 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { /* ??? This is an error */
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-8].code)),
            (yyvsp[-7].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-6].code)),
            (yyvsp[-4].code), (yyvsp[-3].code), (yyvsp[-2].code), code_new_bits((yyvsp[0].bits)));
      }
#line 3288 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 93:
#line 580 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-8].code)),
            (yyvsp[-7].code), (yyvsp[-6].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-4].code)),
            (yyvsp[-3].code), (yyvsp[-2].code), code_new_bits((yyvsp[0].bits)));
      }
#line 3300 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 94:
#line 587 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-8].code)),
            (yyvsp[-7].code), (yyvsp[-6].code), (yyvsp[-4].code), (yyvsp[-3].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), code_new_bits((yyvsp[0].bits)));
      }
#line 3311 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 95:
#line 593 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code), (yyvsp[-8].code), (yyvsp[-7].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-6].code)),
            code_new_inst(i_term_expr, 1, (yyvsp[-4].code)),
            (yyvsp[-3].code), (yyvsp[-2].code), code_new_bits((yyvsp[0].bits)));
      }
#line 3322 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 96:
#line 599 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code), (yyvsp[-8].code), (yyvsp[-7].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-6].code)),
            (yyvsp[-4].code), (yyvsp[-3].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), code_new_bits((yyvsp[0].bits)));
      }
#line 3333 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 97:
#line 605 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { /* ??? This is an error */
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code), (yyvsp[-8].code), (yyvsp[-7].code), (yyvsp[-6].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-4].code)), (yyvsp[-3].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), code_new_bits((yyvsp[0].bits)));
      }
#line 3343 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 98:
#line 610 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { /* ??? This is an error */
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-8].code)),
            (yyvsp[-7].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-6].code)),
            code_new_inst(i_term_expr, 1, (yyvsp[-4].code)),
            (yyvsp[-3].code), (yyvsp[-2].code), code_new_bits((yyvsp[0].bits)));
      }
#line 3356 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 99:
#line 618 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { /* ??? This is an error */
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-8].code)),
            (yyvsp[-7].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-6].code)),
            (yyvsp[-4].code), (yyvsp[-3].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), 
            code_new_bits((yyvsp[0].bits)));
      }
#line 3370 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 100:
#line 627 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { /* ??? This is an error */
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-8].code)),
            (yyvsp[-7].code), (yyvsp[-6].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-4].code)),
            (yyvsp[-3].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), 
            code_new_bits((yyvsp[0].bits)));
      }
#line 3384 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 101:
#line 636 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { /* ??? This is an error */
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code), (yyvsp[-8].code), (yyvsp[-7].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-6].code)),
            code_new_inst(i_term_expr, 1, (yyvsp[-4].code)),
            (yyvsp[-3].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), 
            code_new_bits((yyvsp[0].bits)));
      }
#line 3397 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 102:
#line 644 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { /* ??? This is an error */
         (yyval.code) = code_new_inst(i_vif_else, 8, (yyvsp[-10].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-8].code)),
            (yyvsp[-7].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-6].code)),
            code_new_inst(i_term_expr, 1, (yyvsp[-4].code)),
            (yyvsp[-3].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), 
            code_new_bits((yyvsp[0].bits)));
      }
#line 3412 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 103:
#line 655 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vif, 5, (yyvsp[-6].code), (yyvsp[-4].code), (yyvsp[-3].code), (yyvsp[-2].code), code_new_bits((yyvsp[0].bits)));
      }
#line 3420 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 104:
#line 658 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vif, 5, (yyvsp[-6].code), 
            code_new_inst(i_term_expr, 1, (yyvsp[-4].code)), (yyvsp[-3].code), (yyvsp[-2].code), code_new_bits((yyvsp[0].bits)));
      }
#line 3429 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 105:
#line 662 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vif, 5, (yyvsp[-6].code), 
            (yyvsp[-4].code), (yyvsp[-3].code), code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), 
            code_new_bits((yyvsp[0].bits)));
      }
#line 3439 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 106:
#line 667 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { /* ??? This is an error */
         (yyval.code) = code_new_inst(i_vif, 5, (yyvsp[-6].code),
            code_new_inst(i_term_expr, 1, (yyvsp[-4].code)), (yyvsp[-3].code), 
            code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), code_new_bits((yyvsp[0].bits)));
      }
#line 3449 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 107:
#line 675 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vbool_ne, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3455 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 108:
#line 676 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_ne, 2, code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), (yyvsp[0].code));
      }
#line 3463 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 109:
#line 679 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_ne, 2, (yyvsp[-2].code), code_new_inst(i_term_expr, 1, (yyvsp[0].code)));
      }
#line 3471 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 110:
#line 682 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vbool_eq, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3477 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 111:
#line 683 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_eq, 2, code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), (yyvsp[0].code));
      }
#line 3485 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 112:
#line 686 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_eq, 2, (yyvsp[-2].code), code_new_inst(i_term_expr, 1, (yyvsp[0].code)));
      }
#line 3493 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 113:
#line 689 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vbool_le, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3499 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 114:
#line 690 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_le, 2, code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), (yyvsp[0].code));
      }
#line 3507 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 115:
#line 693 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_le, 2, (yyvsp[-2].code), code_new_inst(i_term_expr, 1, (yyvsp[0].code)));
      }
#line 3515 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 116:
#line 696 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vbool_ge, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3521 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 117:
#line 697 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_ge, 2, code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), (yyvsp[0].code));
      }
#line 3529 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 118:
#line 700 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_ge, 2, (yyvsp[-2].code), code_new_inst(i_term_expr, 1, (yyvsp[0].code)));
      }
#line 3537 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 119:
#line 703 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vbool_lt, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3543 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 120:
#line 704 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_lt, 2, code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), (yyvsp[0].code));
      }
#line 3551 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 121:
#line 707 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_lt, 2, (yyvsp[-2].code), code_new_inst(i_term_expr, 1, (yyvsp[0].code)));
      }
#line 3559 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 122:
#line 710 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vbool_gt, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3565 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 123:
#line 711 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_gt, 2, code_new_inst(i_term_expr, 1, (yyvsp[-2].code)), (yyvsp[0].code));
      }
#line 3573 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 124:
#line 714 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vbool_gt, 2, (yyvsp[-2].code), code_new_inst(i_term_expr, 1, (yyvsp[0].code)));
      }
#line 3581 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 125:
#line 717 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vbool_and, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3587 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 126:
#line 718 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vbool_or,  2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3593 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 127:
#line 719 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vbool_xor, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3599 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 128:
#line 720 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vbool_not, 1, (yyvsp[0].code)); }
#line 3605 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 129:
#line 721 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[-1].code); }
#line 3611 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 130:
#line 725 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.bits) = 0; }
#line 3617 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 131:
#line 726 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.bits) = (yyvsp[-2].bits) | (yyvsp[0].bits); }
#line 3623 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 132:
#line 730 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.bits) = LP_FLAG_CON_SCALE; }
#line 3629 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 133:
#line 731 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.bits) = LP_FLAG_CON_SEPAR; }
#line 3635 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 134:
#line 732 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.bits) = LP_FLAG_CON_CHECK; }
#line 3641 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 135:
#line 733 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.bits) = LP_FLAG_CON_INDIC; }
#line 3647 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 136:
#line 734 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.bits) = LP_FLAG_CON_QUBO;  }
#line 3653 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 137:
#line 738 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_contype(CON_RHS); }
#line 3659 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 138:
#line 739 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_contype(CON_LHS); }
#line 3665 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 139:
#line 740 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_contype(CON_EQUAL); }
#line 3671 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 140:
#line 744 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[0].code); }
#line 3677 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 141:
#line 745 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_term_add, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3683 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 142:
#line 746 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_term_sub, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3689 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 143:
#line 747 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_term_const, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3695 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 144:
#line 748 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_term_sub, 2, (yyvsp[-2].code), code_new_inst(i_term_expr, 1, (yyvsp[0].code)));
      }
#line 3703 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 145:
#line 751 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_term_const, 2, (yyvsp[0].code), (yyvsp[-2].code)); }
#line 3709 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 146:
#line 752 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_term_sub, 2,
            code_new_inst(i_term_expr, 1, (yyvsp[-2].code)),
            (yyvsp[0].code));
      }
#line 3719 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 147:
#line 760 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[0].code); }
#line 3725 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 148:
#line 761 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_term_coeff, 2, (yyvsp[-2].code), (yyvsp[0].code));  }
#line 3731 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 149:
#line 762 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_term_coeff, 2, (yyvsp[-2].code),
            code_new_inst(i_expr_div, 2, code_new_numb(numb_new_integer(1)), (yyvsp[0].code)));
      }
#line 3740 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 150:
#line 766 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_term_coeff, 2, (yyvsp[0].code), (yyvsp[-2].code)); }
#line 3746 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 151:
#line 767 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_term_mul, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 3752 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 153:
#line 772 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[0].code); }
#line 3758 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 154:
#line 773 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
         (yyval.code) = code_new_inst(i_term_coeff, 2, (yyvsp[0].code), code_new_numb(numb_new_integer(-1)));
      }
#line 3766 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 155:
#line 779 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[0].code); }
#line 3772 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 156:
#line 780 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
         (yyval.code) = code_new_inst(i_term_power, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 3780 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 157:
#line 783 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_term_sum, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 3788 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 158:
#line 789 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_symbol_deref, 2, code_new_symbol((yyvsp[-1].sym)), (yyvsp[0].code));
      }
#line 3796 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 159:
#line 792 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vabs, 1, (yyvsp[-1].code)); }
#line 3802 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 160:
#line 793 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vexpr_fun, 2, code_new_numb(numb_new_integer(-2)), (yyvsp[-1].code)); }
#line 3808 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 161:
#line 794 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vexpr_fun, 2, code_new_numb(numb_new_integer(3)), (yyvsp[-1].code)); }
#line 3814 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 162:
#line 795 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vexpr_fun, 2, code_new_numb(numb_new_integer(4)), (yyvsp[-1].code)); }
#line 3820 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 163:
#line 796 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vexpr_fun, 2, code_new_numb(numb_new_integer(5)), (yyvsp[-1].code)); }
#line 3826 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 164:
#line 797 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vexpr_fun, 2, code_new_numb(numb_new_integer(6)), (yyvsp[-1].code)); }
#line 3832 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 165:
#line 798 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vexpr_fun, 2, code_new_numb(numb_new_integer(7)), (yyvsp[-1].code)); }
#line 3838 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 166:
#line 799 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vexpr_fun, 2, code_new_numb(numb_new_integer(8)), (yyvsp[-1].code)); }
#line 3844 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 167:
#line 800 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vexpr_fun, 2, code_new_numb(numb_new_integer(9)), (yyvsp[-1].code)); }
#line 3850 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 168:
#line 801 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_vexpr_fun, 2, code_new_numb(numb_new_integer(10)), (yyvsp[-1].code)); }
#line 3856 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 169:
#line 802 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vexpr_fun, 3, code_new_numb(numb_new_integer(11)), (yyvsp[-3].code), (yyvsp[-1].code));
      }
#line 3864 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 170:
#line 805 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_vexpr_fun, 3, code_new_numb(numb_new_integer(12)), (yyvsp[-3].code), (yyvsp[-1].code));
      }
#line 3872 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 171:
#line 808 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_if_else, 3, (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code));
      }
#line 3880 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 172:
#line 811 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[-1].code); }
#line 3886 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 173:
#line 819 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_sos, 2, code_new_name((yyvsp[-3].name)), (yyvsp[-1].code));
     }
#line 3894 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 174:
#line 825 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_soset, 3, (yyvsp[0].code), (yyvsp[-3].code), (yyvsp[-2].code));
     }
#line 3902 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 175:
#line 828 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_forall, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 3910 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 176:
#line 834 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_numb(numb_new_integer(1)); }
#line 3916 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 177:
#line 835 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_numb(numb_new_integer(1)); }
#line 3922 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 178:
#line 836 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_numb(numb_new_integer(2)); }
#line 3928 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 179:
#line 844 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[-1].code); }
#line 3934 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 180:
#line 848 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_print, 1, (yyvsp[0].code)); }
#line 3940 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 181:
#line 849 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_print, 1, (yyvsp[0].code)); }
#line 3946 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 182:
#line 850 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_print, 1, (yyvsp[0].code)); }
#line 3952 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 183:
#line 851 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_print, 1, (yyvsp[0].code)); }
#line 3958 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 184:
#line 852 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_print, 1, code_new_symbol((yyvsp[0].sym))); }
#line 3964 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 185:
#line 853 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_check, 1, (yyvsp[0].code)); }
#line 3970 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 186:
#line 854 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_forall, 2, (yyvsp[-2].code), (yyvsp[0].code));
     }
#line 3978 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 187:
#line 864 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[0].code); }
#line 3984 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 188:
#line 865 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_idxset_new, 3,
            code_new_inst(i_tuple_empty, 0), (yyvsp[0].code), code_new_inst(i_bool_true, 0));
      }
#line 3993 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 189:
#line 872 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_idxset_new, 3, (yyvsp[-4].code), (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4001 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 190:
#line 875 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_idxset_new, 3, (yyvsp[-2].code), (yyvsp[0].code), code_new_inst(i_bool_true, 0));
      }
#line 4009 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 192:
#line 882 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_union, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4015 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 193:
#line 883 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_union, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4023 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 194:
#line 886 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_sdiff, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4029 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 195:
#line 887 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_minus, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4037 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 196:
#line 890 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_minus, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4043 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 197:
#line 891 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_inter, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4049 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 199:
#line 895 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_union2, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4055 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 201:
#line 900 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_cross, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4061 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 202:
#line 901 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_cross, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4069 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 203:
#line 904 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_inter2, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4075 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 204:
#line 908 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_symbol_deref, 2, code_new_symbol((yyvsp[-1].sym)), (yyvsp[0].code));
      }
#line 4083 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 205:
#line 911 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_define_deref, 2,
            code_new_define((yyvsp[-3].def)),
            code_new_inst(i_tuple_new, 1, (yyvsp[-1].code)));
      }
#line 4093 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 206:
#line 916 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_empty, 1, code_new_size(0)); }
#line 4099 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 207:
#line 917 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_range2, 3, (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code));
      }
#line 4107 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 208:
#line 920 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_range2, 3, (yyvsp[-3].code), (yyvsp[-1].code), code_new_numb(numb_new_integer(1)));
      }
#line 4115 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 209:
#line 923 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_range, 3, (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code));
      }
#line 4123 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 210:
#line 926 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_range, 3, (yyvsp[-3].code), (yyvsp[-1].code), code_new_numb(numb_new_integer(1)));
      }
#line 4131 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 211:
#line 929 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_argmin, 3, code_new_numb(numb_new_integer(1)), (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4139 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 212:
#line 932 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_argmin, 3, (yyvsp[-4].code), (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4147 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 213:
#line 935 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_argmax, 3, code_new_numb(numb_new_integer(1)), (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4155 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 214:
#line 938 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_argmax, 3, (yyvsp[-4].code), (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4163 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 215:
#line 941 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[-1].code); }
#line 4169 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 216:
#line 942 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_new_tuple, 1, (yyvsp[-1].code)); }
#line 4175 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 217:
#line 943 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_new_elem, 1, (yyvsp[-1].code)); }
#line 4181 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 218:
#line 944 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_idxset, 1, (yyvsp[-1].code)); }
#line 4187 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 219:
#line 945 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_expr, 2, (yyvsp[-3].code), (yyvsp[-1].code)); }
#line 4193 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 220:
#line 946 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_set_expr, 2, (yyvsp[-3].code), (yyvsp[-1].code)); }
#line 4199 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 221:
#line 947 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_set_proj, 2, (yyvsp[-3].code), (yyvsp[-1].code));
       }
#line 4207 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 222:
#line 950 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
          (yyval.code) = code_new_inst(i_set_indexset, 1, code_new_symbol((yyvsp[-1].sym)));
       }
#line 4215 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 223:
#line 953 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_if_else, 3, (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code));
      }
#line 4223 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 224:
#line 959 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_read_new, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4229 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 225:
#line 960 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_read_param, 2, (yyvsp[-1].code), (yyvsp[0].code)); }
#line 4235 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 226:
#line 964 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_read_skip, 1, (yyvsp[0].code)); }
#line 4241 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 227:
#line 965 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_read_use, 1, (yyvsp[0].code)); }
#line 4247 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 228:
#line 966 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_read_comment, 1, (yyvsp[0].code)); }
#line 4253 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 229:
#line 967 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_read_match, 1, (yyvsp[0].code)); }
#line 4259 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 230:
#line 971 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_tuple_list_new, 1, (yyvsp[0].code));
      }
#line 4267 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 231:
#line 974 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_tuple_list_add, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4275 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 232:
#line 977 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_read, 1, (yyvsp[0].code)); }
#line 4281 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 233:
#line 981 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_eq, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4287 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 234:
#line 982 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_ne, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4293 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 235:
#line 983 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_gt, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4299 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 236:
#line 984 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_ge, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4305 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 237:
#line 985 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_lt, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4311 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 238:
#line 986 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_le, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4317 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 239:
#line 987 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_seq, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4323 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 240:
#line 988 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_sneq, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4329 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 241:
#line 989 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_subs, 2, (yyvsp[0].code), (yyvsp[-2].code)); }
#line 4335 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 242:
#line 990 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_sseq, 2, (yyvsp[0].code), (yyvsp[-2].code)); }
#line 4341 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 243:
#line 991 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_subs, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4347 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 244:
#line 992 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_sseq, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4353 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 245:
#line 993 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_and, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4359 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 246:
#line 994 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_or,  2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4365 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 247:
#line 995 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_xor, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4371 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 248:
#line 996 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_not, 1, (yyvsp[0].code)); }
#line 4377 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 249:
#line 997 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[-1].code); }
#line 4383 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 250:
#line 998 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_is_elem, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4389 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 251:
#line 999 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_bool_exists, 1, (yyvsp[-1].code)); }
#line 4395 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1000 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_define_deref, 2,
            code_new_define((yyvsp[-3].def)),
            code_new_inst(i_tuple_new, 1, (yyvsp[-1].code)));
      }
#line 4405 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1005 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
        (yyval.code) = code_new_inst(i_expr_if_else, 3, (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code));
     }
#line 4413 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1011 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_tuple_empty, 0); }
#line 4419 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1012 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_tuple_new, 1, (yyvsp[-1].code));  }
#line 4425 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1016 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_tuple_empty, 0);
      }
#line 4433 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1019 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_tuple_new, 1, (yyvsp[-1].code));
      }
#line 4441 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1025 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_elem_list_new, 1, (yyvsp[0].code));
      }
#line 4449 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1028 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_elem_list_add, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4457 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1034 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[0].code); }
#line 4463 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1035 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_add, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4469 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1036 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_sub, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4475 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1040 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[0].code); }
#line 4481 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1041 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_mul, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4487 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1042 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_div, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4493 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1043 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_mod, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4499 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1044 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_intdiv, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4505 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1045 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_prod, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4513 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1052 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[0].code); }
#line 4519 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1053 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_neg, 1, (yyvsp[0].code)); }
#line 4525 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1058 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_pow, 2, (yyvsp[-2].code), (yyvsp[0].code)); }
#line 4531 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1059 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_sum, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4539 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1062 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_min, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4547 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1065 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_max, 2, (yyvsp[-2].code), (yyvsp[0].code));
      }
#line 4555 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1068 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_sglmin, 1, (yyvsp[-1].code));
         }
#line 4563 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1071 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_sglmax, 1, (yyvsp[-1].code));
      }
#line 4571 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1077 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_numb((yyvsp[0].numb)); }
#line 4577 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1078 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_strg((yyvsp[0].strg));  }
#line 4583 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1079 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_local_deref, 1, code_new_name((yyvsp[0].name)));
      }
#line 4591 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1082 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
         (yyval.code) = code_new_inst(i_symbol_deref, 2, code_new_symbol((yyvsp[-1].sym)), (yyvsp[0].code));
      }
#line 4599 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1085 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { 
         (yyval.code) = code_new_inst(i_symbol_deref, 2, code_new_symbol((yyvsp[-1].sym)), (yyvsp[0].code));
      }
#line 4607 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1088 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_define_deref, 2,
            code_new_define((yyvsp[-3].def)),
            code_new_inst(i_tuple_new, 1, (yyvsp[-1].code)));
      }
#line 4617 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1093 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_define_deref, 2,
            code_new_define((yyvsp[-3].def)),
            code_new_inst(i_tuple_new, 1, (yyvsp[-1].code)));
      }
#line 4627 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1098 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_fac, 1, (yyvsp[-1].code)); }
#line 4633 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1099 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_card, 1, (yyvsp[-1].code)); }
#line 4639 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1100 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_abs, 1, (yyvsp[-1].code)); }
#line 4645 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1101 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_sgn, 1, (yyvsp[-1].code)); }
#line 4651 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1102 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_round, 1, (yyvsp[-1].code)); }
#line 4657 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1103 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_floor, 1, (yyvsp[-1].code)); }
#line 4663 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1104 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_ceil, 1, (yyvsp[-1].code)); }
#line 4669 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1105 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_log, 1, (yyvsp[-1].code)); }
#line 4675 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1106 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_ln, 1, (yyvsp[-1].code)); }
#line 4681 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1107 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_exp, 1, (yyvsp[-1].code)); }
#line 4687 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1108 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_sqrt, 1, (yyvsp[-1].code)); }
#line 4693 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1109 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_sin, 1, (yyvsp[-1].code)); }
#line 4699 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1110 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_cos, 1, (yyvsp[-1].code)); }
#line 4705 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1111 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_tan, 1, (yyvsp[-1].code)); }
#line 4711 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1112 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_asin, 1, (yyvsp[-1].code)); }
#line 4717 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1113 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_acos, 1, (yyvsp[-1].code)); }
#line 4723 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1114 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_atan, 1, (yyvsp[-1].code)); }
#line 4729 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1116 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = (yyvsp[-1].code); }
#line 4735 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1117 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    { (yyval.code) = code_new_inst(i_expr_length, 1, (yyvsp[-1].code)); }
#line 4741 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1118 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_substr, 3, (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code));
      }
#line 4749 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1121 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_rand, 2, (yyvsp[-3].code), (yyvsp[-1].code));
      }
#line 4757 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1124 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_if_else, 3, (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code));
      }
#line 4765 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1127 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_ord, 3, (yyvsp[-5].code), (yyvsp[-3].code), (yyvsp[-1].code));
      }
#line 4773 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1130 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_min2, 1, (yyvsp[-1].code));
      }
#line 4781 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1133 "src/zimpl/mmlparse2.y" /* yacc.c:1646  */
    {
         (yyval.code) = code_new_inst(i_expr_max2, 1, (yyvsp[-1].code));
      }
#line 4789 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
    break;


#line 4793 "src/zimpl/mmlparse2.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
