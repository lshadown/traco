/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 15 "../src/parser.y" /* yacc.c:339  */


#include <basic/Dynamic_Array.h>
#include <basic/Iterator.h>
#include <code_gen/code_gen.h>
#include <code_gen/spmd.h>
#include <omega_calc/AST.h>
#include <omega/hull.h>
#include <omega/closure.h>
#include <omega/reach.h>
#include <code_gen/mmap-codegen.h>
#include <code_gen/mmap-util.h>
#include <string>
#include <iostream>
#include <unistd.h>

#ifdef WIN32
#include <io.h>
#define isatty _isatty
#define alloca _alloca
#endif
#ifndef WIN32
#include <sys/time.h>
#include <sys/resource.h>
#endif
#if !defined(OMIT_GETRUSAGE)
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#endif

#if !defined(OMIT_GETRUSAGE)
#ifdef __sparc__
extern "C" int getrusage (int, struct rusage*);
#endif

using namespace omega;

struct rusage start_time;
bool anyTimingDone = false;

void start_clock( void ) {
  getrusage(RUSAGE_SELF, &start_time);
}

int clock_diff( void ) {
  struct rusage current_time;
  getrusage(RUSAGE_SELF, &current_time);
  return (current_time.ru_utime.tv_sec -start_time.ru_utime.tv_sec)*1000000 + (current_time.ru_utime.tv_usec-start_time.ru_utime.tv_usec);
}
#endif

int omega_calc_debug = 0;

bool is_interactive;
const char *PROMPT_STRING = ">>>";
extern std::string err_msg;
extern FILE *yyin;
bool need_coef;

Map<Const_String,Relation*> relationMap ((Relation *)0);
namespace {
  int redundant_conj_level = 2;  // default maximum 2
  int redundant_constr_level = 4;  // default maximum 4
}

int argCount = 0;
int tuplePos = 0;
Argument_Tuple currentTuple = Input_Tuple;

Relation LexForward(int n);
reachable_information *reachable_info;

int yylex();
void yyerror(const std::string &s);
void flushScanBuffer();


#line 145 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    INT = 259,
    COEF = 260,
    STRING = 261,
    OPEN_BRACE = 262,
    CLOSE_BRACE = 263,
    SYMBOLIC = 264,
    OR = 265,
    AND = 266,
    NOT = 267,
    ST = 268,
    APPROX = 269,
    IS_ASSIGNED = 270,
    FORALL = 271,
    EXISTS = 272,
    DOMAIN = 273,
    RANGE = 274,
    DIFFERENCE = 275,
    DIFFERENCE_TO_RELATION = 276,
    GIST = 277,
    GIVEN = 278,
    HULL = 279,
    WITHIN = 280,
    MAXIMIZE = 281,
    MINIMIZE = 282,
    AFFINE_HULL = 283,
    VENN = 284,
    CONVEX_COMBINATION = 285,
    POSITIVE_COMBINATION = 286,
    LINEAR_COMBINATION = 287,
    AFFINE_COMBINATION = 288,
    CONVEX_HULL = 289,
    CONIC_HULL = 290,
    LINEAR_HULL = 291,
    QUICK_HULL = 292,
    PAIRWISE_CHECK = 293,
    CONVEX_CHECK = 294,
    CONVEX_REPRESENTATION = 295,
    RECT_HULL = 296,
    DECOUPLED_CONVEX_HULL = 297,
    MAXIMIZE_RANGE = 298,
    MINIMIZE_RANGE = 299,
    MAXIMIZE_DOMAIN = 300,
    MINIMIZE_DOMAIN = 301,
    LEQ = 302,
    GEQ = 303,
    NEQ = 304,
    GOES_TO = 305,
    COMPOSE = 306,
    JOIN = 307,
    INVERSE = 308,
    COMPLEMENT = 309,
    IN = 310,
    CARRIED_BY = 311,
    TIME = 312,
    TIMECLOSURE = 313,
    UNION = 314,
    INTERSECTION = 315,
    VERTICAL_BAR = 316,
    SUCH_THAT = 317,
    SUBSET = 318,
    ITERATIONS = 319,
    SPMD = 320,
    CODEGEN = 321,
    DECOUPLED_FARKAS = 322,
    FARKAS = 323,
    TCODEGEN = 324,
    TRANS_IS = 325,
    SET_MMAP = 326,
    UNROLL_IS = 327,
    PEEL_IS = 328,
    MAKE_UPPER_BOUND = 329,
    MAKE_LOWER_BOUND = 330,
    REL_OP = 331,
    RESTRICT_DOMAIN = 332,
    RESTRICT_RANGE = 333,
    SUPERSETOF = 334,
    SUBSETOF = 335,
    SAMPLE = 336,
    SYM_SAMPLE = 337,
    PROJECT_AWAY_SYMBOLS = 338,
    PROJECT_ON_SYMBOLS = 339,
    REACHABLE_FROM = 340,
    REACHABLE_OF = 341,
    ASSERT_UNSAT = 342,
    PARSE_EXPRESSION = 343,
    PARSE_FORMULA = 344,
    PARSE_RELATION = 345,
    ITERATE_CLOSURE = 346,
    APPROX_CLOSURE = 347,
    TRANSITIVE_REDUCTION = 348,
    APPROX_TO_UNIFORM = 349,
    RK = 350,
    TC = 351,
    SEMI_NAIVE_CLOSURE = 352,
    ADVANCED_ITERATE_CLOSURE = 353,
    ALL_IN_REGION = 354,
    MIN_DEPENDENCE_DIST = 355,
    TEST = 356,
    p1 = 357,
    p2 = 358,
    p3 = 359,
    p4 = 360,
    p5 = 361,
    p6 = 362,
    p7 = 363,
    p8 = 364,
    p9 = 365,
    p10 = 366
  };
#endif
/* Tokens.  */
#define VAR 258
#define INT 259
#define COEF 260
#define STRING 261
#define OPEN_BRACE 262
#define CLOSE_BRACE 263
#define SYMBOLIC 264
#define OR 265
#define AND 266
#define NOT 267
#define ST 268
#define APPROX 269
#define IS_ASSIGNED 270
#define FORALL 271
#define EXISTS 272
#define DOMAIN 273
#define RANGE 274
#define DIFFERENCE 275
#define DIFFERENCE_TO_RELATION 276
#define GIST 277
#define GIVEN 278
#define HULL 279
#define WITHIN 280
#define MAXIMIZE 281
#define MINIMIZE 282
#define AFFINE_HULL 283
#define VENN 284
#define CONVEX_COMBINATION 285
#define POSITIVE_COMBINATION 286
#define LINEAR_COMBINATION 287
#define AFFINE_COMBINATION 288
#define CONVEX_HULL 289
#define CONIC_HULL 290
#define LINEAR_HULL 291
#define QUICK_HULL 292
#define PAIRWISE_CHECK 293
#define CONVEX_CHECK 294
#define CONVEX_REPRESENTATION 295
#define RECT_HULL 296
#define DECOUPLED_CONVEX_HULL 297
#define MAXIMIZE_RANGE 298
#define MINIMIZE_RANGE 299
#define MAXIMIZE_DOMAIN 300
#define MINIMIZE_DOMAIN 301
#define LEQ 302
#define GEQ 303
#define NEQ 304
#define GOES_TO 305
#define COMPOSE 306
#define JOIN 307
#define INVERSE 308
#define COMPLEMENT 309
#define IN 310
#define CARRIED_BY 311
#define TIME 312
#define TIMECLOSURE 313
#define UNION 314
#define INTERSECTION 315
#define VERTICAL_BAR 316
#define SUCH_THAT 317
#define SUBSET 318
#define ITERATIONS 319
#define SPMD 320
#define CODEGEN 321
#define DECOUPLED_FARKAS 322
#define FARKAS 323
#define TCODEGEN 324
#define TRANS_IS 325
#define SET_MMAP 326
#define UNROLL_IS 327
#define PEEL_IS 328
#define MAKE_UPPER_BOUND 329
#define MAKE_LOWER_BOUND 330
#define REL_OP 331
#define RESTRICT_DOMAIN 332
#define RESTRICT_RANGE 333
#define SUPERSETOF 334
#define SUBSETOF 335
#define SAMPLE 336
#define SYM_SAMPLE 337
#define PROJECT_AWAY_SYMBOLS 338
#define PROJECT_ON_SYMBOLS 339
#define REACHABLE_FROM 340
#define REACHABLE_OF 341
#define ASSERT_UNSAT 342
#define PARSE_EXPRESSION 343
#define PARSE_FORMULA 344
#define PARSE_RELATION 345
#define ITERATE_CLOSURE 346
#define APPROX_CLOSURE 347
#define TRANSITIVE_REDUCTION 348
#define APPROX_TO_UNIFORM 349
#define RK 350
#define TC 351
#define SEMI_NAIVE_CLOSURE 352
#define ADVANCED_ITERATE_CLOSURE 353
#define ALL_IN_REGION 354
#define MIN_DEPENDENCE_DIST 355
#define TEST 356
#define p1 357
#define p2 358
#define p3 359
#define p4 360
#define p5 361
#define p6 362
#define p7 363
#define p8 364
#define p9 365
#define p10 366

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 94 "../src/parser.y" /* yacc.c:355  */

  int INT_VALUE;
  coef_t COEF_VALUE;
  Rel_Op REL_OPERATOR;
  char *VAR_NAME;
  VarList *VAR_LIST;
  Exp *EXP;
  ExpList *EXP_LIST;
  AST *ASTP;
  Argument_Tuple ARGUMENT_TUPLE;
  AST_constraints *ASTCP;
  Declaration_Site * DECLARATION_SITE;
  Relation * RELATION;
  tupleDescriptor * TUPLE_DESCRIPTOR;
  RelTuplePair * REL_TUPLE_PAIR;
  RelTupleTriple * REL_TUPLE_TRIPLE;
  Dynamic_Array2<Relation> * RELATION_ARRAY_2D;
  Dynamic_Array1<Relation> * RELATION_ARRAY_1D;
  Tuple<std::string> *STRING_TUPLE;
  std::string *STRING_VALUE;
  Tuple<stm_info> *STM_INFO_TUPLE;
  stm_info *STM_INFO;
  Read *READ;
  PartialRead *PREAD;
  MMap *MMAP;
  PartialMMap *PMMAP;

#line 435 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 450 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1058

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  124
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  196
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  404

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   366

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
     115,   122,   107,   103,   118,   104,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   119,   117,
       2,     2,     2,     2,   108,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   120,     2,   121,   123,     2,     2,     2,     2,     2,
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
      95,    96,    97,    98,    99,   100,   101,   102,   105,   106,
     109,   110,   111,   112,   113,   114,   116
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   205,   205,   206,   206,   210,   211,   221,   222,   235,
     241,   318,   404,   420,   431,   443,   464,   496,   514,   523,
     535,   536,   537,   538,   541,   542,   543,   546,   547,   550,
     568,   584,   603,   622,   628,   632,   636,   639,   643,   650,
     655,   662,   668,   676,   681,   688,   694,   702,   703,   706,
     709,   710,   713,   716,   716,   728,   739,   740,   753,   767,
     782,   798,   814,   830,   846,   862,   878,   891,   904,   917,
     930,   943,   956,   969,   982,   995,  1010,  1023,  1036,  1049,
    1062,  1075,  1088,  1101,  1114,  1127,  1140,  1153,  1166,  1179,
    1192,  1205,  1220,  1233,  1246,  1259,  1272,  1285,  1298,  1311,
    1324,  1337,  1350,  1363,  1376,  1389,  1402,  1417,  1432,  1447,
    1461,  1476,  1491,  1506,  1521,  1536,  1551,  1566,  1579,  1592,
    1605,  1618,  1631,  1644,  1645,  1655,  1656,  1655,  1683,  1701,
    1710,  1711,  1714,  1715,  1716,  1719,  1719,  1724,  1725,  1726,
    1729,  1748,  1749,  1753,  1757,  1763,  1764,  1767,  1774,  1775,
    1778,  1779,  1782,  1783,  1789,  1790,  1791,  1792,  1793,  1794,
    1795,  1798,  1799,  1802,  1803,  1804,  1807,  1808,  1811,  1814,
    1817,  1818,  1821,  1822,  1825,  1835,  1835,  1849,  1852,  1868,
    1886,  1887,  1888,  1889,  1890,  1891,  1892,  1896,  1902,  1920,
    1928,  1932,  1940,  1984,  1998,  2023,  2048
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "INT", "COEF", "STRING",
  "OPEN_BRACE", "CLOSE_BRACE", "SYMBOLIC", "OR", "AND", "NOT", "ST",
  "APPROX", "IS_ASSIGNED", "FORALL", "EXISTS", "DOMAIN", "RANGE",
  "DIFFERENCE", "DIFFERENCE_TO_RELATION", "GIST", "GIVEN", "HULL",
  "WITHIN", "MAXIMIZE", "MINIMIZE", "AFFINE_HULL", "VENN",
  "CONVEX_COMBINATION", "POSITIVE_COMBINATION", "LINEAR_COMBINATION",
  "AFFINE_COMBINATION", "CONVEX_HULL", "CONIC_HULL", "LINEAR_HULL",
  "QUICK_HULL", "PAIRWISE_CHECK", "CONVEX_CHECK", "CONVEX_REPRESENTATION",
  "RECT_HULL", "DECOUPLED_CONVEX_HULL", "MAXIMIZE_RANGE", "MINIMIZE_RANGE",
  "MAXIMIZE_DOMAIN", "MINIMIZE_DOMAIN", "LEQ", "GEQ", "NEQ", "GOES_TO",
  "COMPOSE", "JOIN", "INVERSE", "COMPLEMENT", "IN", "CARRIED_BY", "TIME",
  "TIMECLOSURE", "UNION", "INTERSECTION", "VERTICAL_BAR", "SUCH_THAT",
  "SUBSET", "ITERATIONS", "SPMD", "CODEGEN", "DECOUPLED_FARKAS", "FARKAS",
  "TCODEGEN", "TRANS_IS", "SET_MMAP", "UNROLL_IS", "PEEL_IS",
  "MAKE_UPPER_BOUND", "MAKE_LOWER_BOUND", "REL_OP", "RESTRICT_DOMAIN",
  "RESTRICT_RANGE", "SUPERSETOF", "SUBSETOF", "SAMPLE", "SYM_SAMPLE",
  "PROJECT_AWAY_SYMBOLS", "PROJECT_ON_SYMBOLS", "REACHABLE_FROM",
  "REACHABLE_OF", "ASSERT_UNSAT", "PARSE_EXPRESSION", "PARSE_FORMULA",
  "PARSE_RELATION", "ITERATE_CLOSURE", "APPROX_CLOSURE",
  "TRANSITIVE_REDUCTION", "APPROX_TO_UNIFORM", "RK", "TC",
  "SEMI_NAIVE_CLOSURE", "ADVANCED_ITERATE_CLOSURE", "ALL_IN_REGION",
  "MIN_DEPENDENCE_DIST", "TEST", "p1", "'+'", "'-'", "p2", "p3", "'*'",
  "'@'", "p4", "p5", "p6", "p7", "p8", "p9", "'('", "p10", "';'", "','",
  "':'", "'['", "']'", "')'", "'^'", "$accept", "inputSequence", "$@1",
  "inputItem", "relTripList", "blockAndProcsAndEffort", "effort",
  "context", "relPairList", "statementInfoResult", "statementInfoList",
  "statementInfo", "partialwrites", "partialwrite", "reads", "oneread",
  "partials", "partial", "relation", "$@2", "builtRelation", "$@3", "$@4",
  "optionalFormula", "formula_sep", "tupleDeclaration", "$@5",
  "optionalTupleVarList", "tupleVar", "varList", "varDecl",
  "varDeclOptBrackets", "globVarList", "globVar", "formula",
  "start_exists", "exists_sep", "start_forall", "forall_sep", "end_quant",
  "expList", "constraintChain", "simpleExp", "$@6", "argumentList", "exp",
  "reachable", "reachable_of", "nodeNameList", "realNodeNameList",
  "nodeSpecificationList", "realNodeSpecificationList", YY_NULLPTR
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
     355,   356,   357,    43,    45,   358,   359,    42,    64,   360,
     361,   362,   363,   364,   365,    40,   366,    59,    44,    58,
      91,    93,    41,    94
};
# endif

#define YYPACT_NINF -271

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-271)))

#define YYTABLE_NINF -141

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -271,   103,  -271,   367,   -36,   101,  -271,   149,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   188,
     153,    58,   188,   188,    58,   188,   188,   188,   188,   188,
     188,   188,   188,    48,   174,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   188,   188,  -271,  -271,   540,
      62,  -271,  -271,   188,    61,    72,   -48,  -271,  -271,    32,
      32,    32,    32,    32,   241,    36,    32,    32,    32,    38,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,   575,
     608,   193,   188,  -271,   196,   188,    32,    32,   167,    32,
      32,   366,   366,    32,    32,    32,    32,   245,   237,   210,
     935,    32,    32,    32,    32,    32,    32,    32,    32,   935,
      32,   643,   188,   188,   262,   188,   188,   188,   188,   188,
     252,   188,   465,  -271,   188,  -271,   175,  -271,   676,   176,
      68,    61,   179,   180,    81,    71,   281,    69,   170,   122,
      30,    30,   220,  -271,  -271,    18,   300,  -271,   149,   188,
     188,   188,  -271,  -271,   302,   118,   682,  -271,    40,   717,
     188,   304,   307,   308,   310,   291,   207,  -271,  -271,   -43,
     324,  -271,    48,  -271,    32,    32,  -271,   366,    45,   751,
     138,   138,   188,    45,    45,   757,  -271,  -271,  -271,    81,
    -271,  -271,  -271,  -271,  -271,   179,   180,    79,   195,  -271,
    -271,  -271,  -271,  -271,  -271,    61,    77,    61,    61,  -271,
     325,   216,  -271,    37,   218,    81,    81,    81,    81,    81,
     213,  -271,    32,    32,    32,  -271,  -271,   188,   188,   188,
     188,   222,   188,   517,   334,   337,   338,   225,   229,   227,
     347,  -271,    35,    60,   237,  -271,    32,  -271,   348,   -12,
    -271,  -271,  -271,   122,     5,  -271,   -16,  -271,   217,   341,
    -271,   232,   351,  -271,  -271,  -271,    61,  -271,    61,   220,
    -271,   248,   248,  -271,  -271,  -271,   792,   825,   935,   831,
    -271,   935,  -271,    46,   187,  -271,   354,   188,   188,  -271,
    -271,  -271,   356,   188,  -271,   358,  -271,  -271,   125,  -271,
      77,  -271,    81,  -271,  -271,    83,    83,   188,   188,   188,
     188,   188,   334,  -271,   167,   463,   865,   244,   935,    74,
     362,  -271,    51,  -271,   219,  -271,  -271,  -271,   900,   935,
     935,   935,   933,  -271,  -271,   188,  -271,   334,   188,   364,
     188,  -271,  -271,   368,   188,   251,   517,    -7,   935,   253,
     935,  -271,   935,   188,  -271,    54,  -271,   188,   935,   373,
      24,  -271,   935,   260,   155,  -271,   263,  -271,   188,   373,
    -271,  -271,   935,  -271
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     3,     1,     0,     0,    55,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    24,     0,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     4,     0,
       0,   123,     6,     0,   135,   153,     0,   151,    55,    92,
      73,    93,    71,    72,     0,    90,    64,    65,    85,    74,
      81,    78,    79,    80,    76,    86,    87,    88,    82,    83,
      84,    89,    77,    61,    60,    63,    62,    94,    95,     0,
       0,    21,     0,    25,     0,     0,    67,    66,     0,   119,
     120,   117,   118,   121,   122,    69,    70,     0,     0,     0,
     124,    96,   100,   103,   102,   104,    99,    98,    97,    13,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      57,     0,    58,    68,     0,     9,     0,    17,     0,   174,
     180,     0,     0,     0,     0,     0,     0,   131,     0,   129,
       0,     0,     0,   156,   182,   171,     0,     7,     0,     0,
       0,     0,    10,    11,    22,     0,     0,    26,    27,    32,
       0,     0,     0,     0,     0,    27,    33,    39,   191,     0,
       0,   187,     0,    56,   108,   110,   109,   115,   113,     0,
     112,   111,     0,   114,   116,     0,   105,     8,   175,     0,
     181,   158,   167,   162,   183,   166,   161,     0,   171,    54,
     125,   133,   134,   132,   128,     0,   137,     0,     0,   146,
       0,   147,   148,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   106,    91,    75,    23,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   189,     0,     0,     0,    12,    59,   107,     0,     0,
     157,   177,   135,   130,   174,   141,     0,   138,   142,   155,
     154,     0,     0,   164,   165,   163,     0,   168,     0,   172,
     173,   184,   185,   186,   170,   152,     0,     0,    28,    30,
      14,    31,    34,     0,     0,    44,     0,     0,     0,    15,
      40,   190,     0,     0,   192,     0,   188,   179,     0,   126,
       0,   136,     0,   149,   145,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,   196,     0,
       0,   176,   131,   139,   143,   169,   159,   160,     0,    19,
      29,    46,     0,    43,    36,     0,    37,     0,     0,     0,
       0,   178,   127,     0,     0,     0,     0,     0,   195,     0,
     193,   144,    18,     0,    38,     0,    42,     0,    45,     0,
       0,    48,   194,     0,     0,    51,     0,    41,     0,     0,
      49,    47,    52,    50
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -271,  -271,  -271,  -271,  -271,  -271,   327,   185,  -271,  -196,
    -271,   113,    17,  -270,  -271,    -4,  -271,    15,    -8,  -271,
    -271,  -271,  -271,    63,  -271,   134,  -271,  -271,    89,  -271,
     183,   256,  -271,   250,  -129,  -271,  -271,  -271,  -271,    93,
     -46,   186,   270,  -271,  -271,  -119,  -271,  -271,   235,  -271,
     164,  -271
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     3,    68,   185,   112,   115,   261,   188,   195,
     196,   197,   314,   315,   390,   391,   394,   395,    69,    74,
     166,   282,   352,   234,   235,   167,   168,   286,   287,   241,
     242,   243,    76,    77,   169,   170,   296,   171,   298,   356,
     172,   173,   174,   278,   328,   175,    70,    71,   128,   199,
     201,   273
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   221,   239,   116,   117,   227,   119,   120,   121,
     122,   123,   124,   125,   126,   224,   228,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   180,
     313,   181,   113,   259,   159,   158,   160,   312,   324,   177,
     178,   159,   363,   161,   159,   270,   160,   162,   163,   271,
     284,    72,   160,   161,   159,   322,   160,   225,   226,   237,
     238,   246,   247,   237,   238,   248,   142,   143,   293,   294,
     279,   144,   330,     2,   186,   331,   283,   189,   289,   290,
     281,   385,   231,   232,   386,   363,    73,   288,   343,   230,
     218,   246,   247,  -140,   369,   248,  -140,   301,   302,   303,
     231,   232,   237,   238,   204,   205,   249,   207,   208,   209,
     210,   211,   396,   213,   214,   397,   215,   154,   364,   366,
     240,   154,    75,   154,   323,   156,   295,   111,   260,   156,
     154,   156,   114,   127,   340,   164,   341,   335,   156,   336,
     233,   252,   253,   254,   389,   164,   165,   129,   325,   157,
     384,   164,   263,   219,   285,   164,   165,   176,   233,   142,
     143,    78,   219,   370,   144,     6,   219,   184,   146,   299,
     187,   280,     8,   304,   276,   355,     9,    10,    11,    12,
      13,   288,    14,   354,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,   256,   257,   190,   191,   192,
     193,    36,    37,   350,   200,   152,   153,   351,   198,   306,
     307,   308,   309,   154,   311,    42,    43,   190,   191,   192,
     193,   156,    45,    46,   179,   202,   206,    47,    48,    49,
      50,    51,    52,   399,    54,    55,   400,   212,   216,    56,
      57,    58,    59,    60,    61,    62,    63,   194,    65,   229,
     236,   218,   142,   143,   222,   223,   245,   144,   246,   247,
     145,   146,   248,    66,   250,   342,   255,   194,   264,   345,
     346,   265,   266,   249,   259,   348,   267,   281,   148,   149,
     246,   247,   246,   247,   248,   269,   248,   272,   239,   358,
     359,   360,   361,   362,   292,   305,   332,   297,   373,   310,
     313,   316,   317,   318,   150,   151,   319,   194,   152,   153,
     321,   327,   238,   333,   334,   248,   154,   376,   344,   347,
     378,   349,   380,   368,   156,   371,   382,   379,     4,   383,
       5,   118,   387,   381,     6,   388,     7,   393,   398,   392,
     268,     8,   320,   389,   377,     9,    10,    11,    12,    13,
     402,    14,   401,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,   403,   372,   329,   142,   143,   353,
      36,    37,   144,   291,    38,    39,   146,   244,   251,   357,
     220,   300,    40,    41,    42,    43,    44,   274,   326,     0,
       0,    45,    46,   148,   149,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     0,     0,     0,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    78,     0,
       0,     0,     6,   152,   153,     0,     0,     0,     0,     0,
       0,   154,    66,     0,    67,     0,     0,    13,     0,   156,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     0,     0,   142,   143,     0,     0,     0,   144,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,    42,   190,   191,   192,   193,     0,     0,     0,
     148,   149,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    54,     0,     0,     0,     0,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    65,   150,   151,   142,   143,
     152,   153,     0,   144,     0,     0,   145,   146,   154,     0,
      66,   365,     0,   194,     0,     0,   156,   190,   191,   192,
     193,   142,   143,     0,   148,   149,   144,     0,     0,   145,
     146,     0,     0,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   149,     0,
     150,   151,     0,     0,   152,   153,   142,   143,     0,     0,
       0,   144,   154,     0,   145,   146,     0,   194,     0,     0,
     156,     0,     0,   150,   151,     0,     0,   152,   153,     0,
       0,     0,   148,   149,     0,   154,     0,   155,     0,   142,
     143,     0,     0,   156,   144,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   151,
       0,     0,   152,   153,     0,   148,   149,     0,     0,     0,
     154,     0,   182,     0,   142,   143,     0,     0,   156,   144,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,   150,   151,     0,     0,   152,   153,     0,     0,     0,
     148,   149,     0,   154,     0,   183,     0,   142,   143,     0,
       0,   156,   144,   142,   143,   145,   146,     0,   144,     0,
       0,   145,   146,     0,     0,     0,   150,   151,     0,     0,
     152,   153,     0,   148,   149,     0,     0,     0,   154,   148,
     149,     0,     0,     0,     0,   203,   156,     0,   142,   143,
       0,     0,     0,   144,     0,     0,   145,   146,     0,   150,
     151,     0,     0,   152,   153,   150,   151,     0,     0,   152,
     153,   154,     0,   217,   148,   149,     0,   154,     0,   156,
       0,   258,   142,   143,     0,   156,     0,   144,   142,   143,
     145,   146,     0,   144,     0,     0,   145,   146,     0,     0,
     150,   151,     0,     0,   152,   153,     0,     0,   148,   149,
       0,     0,   154,     0,   148,   149,   262,     0,     0,     0,
     156,     0,     0,   142,   143,     0,     0,     0,   144,     0,
       0,   145,   146,     0,   150,   151,     0,     0,   152,   153,
     150,   151,     0,     0,   152,   153,   154,     0,   275,   148,
     149,     0,   154,     0,   156,     0,   142,   143,     0,   277,
     156,   144,   142,   143,   145,   146,     0,   144,     0,     0,
     145,   146,     0,     0,     0,   150,   151,     0,     0,   152,
     153,     0,   148,   149,     0,     0,     0,   154,   148,   149,
       0,   337,     0,     0,     0,   156,   142,   143,     0,     0,
       0,   144,     0,     0,   145,   146,     0,     0,   150,   151,
       0,     0,   152,   153,   150,   151,     0,     0,   152,   153,
     154,     0,   148,   149,   338,     0,   154,     0,   156,     0,
     339,   142,   143,     0,   156,     0,   144,     0,     0,   145,
     146,     0,     0,     0,     0,     0,     0,     0,   150,   151,
       0,     0,   152,   153,     0,     0,     0,   148,   149,     0,
     154,     0,     0,   367,   142,   143,   142,   143,   156,   144,
       0,   144,   145,   146,   145,   146,     0,     0,     0,     0,
       0,     0,     0,   150,   151,     0,     0,   152,   153,     0,
     148,   149,   148,   149,     0,   154,     0,     0,     0,   374,
       0,     0,     0,   156,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   150,   151,   150,   151,
     152,   153,   152,   153,     0,     0,     0,     0,   154,     0,
     154,     0,     0,     0,   375,     0,   156,     0,   156
};

static const yytype_int16 yycheck[] =
{
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   161,     3,    42,    43,   165,    45,    46,    47,
      48,    49,    50,    51,    52,   164,   165,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    23,
       6,    23,     4,    23,     3,    73,     5,   263,     8,   117,
     118,     3,   342,    12,     3,   118,     5,    16,    17,   122,
       3,   117,     5,    12,     3,    50,     5,    16,    17,    10,
      11,   103,   104,    10,    11,   107,    51,    52,    61,    62,
     219,    56,   118,     0,   112,   121,   235,   115,   237,   238,
     122,   118,    61,    62,   121,   385,    15,   236,   314,    50,
     115,   103,   104,   118,    50,   107,   121,   246,   247,   248,
      61,    62,    10,    11,   142,   143,   118,   145,   146,   147,
     148,   149,   118,   151,   152,   121,   154,   115,   344,   345,
     120,   115,     3,   115,   119,   123,   119,     4,   118,   123,
     115,   123,   104,   115,   118,   104,   120,   296,   123,   298,
     119,   179,   180,   181,   120,   104,   115,     3,   118,   117,
     376,   104,   190,   115,   107,   104,   115,   115,   119,    51,
      52,     3,   115,   119,    56,     7,   115,     4,    60,   245,
       4,   122,    14,   249,   212,   122,    18,    19,    20,    21,
      22,   330,    24,   332,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,   117,   118,    70,    71,    72,
      73,    53,    54,   118,     7,   107,   108,   122,     3,   257,
     258,   259,   260,   115,   262,    67,    68,    70,    71,    72,
      73,   123,    74,    75,    23,    55,     4,    79,    80,    81,
      82,    83,    84,   118,    86,    87,   121,    25,   103,    91,
      92,    93,    94,    95,    96,    97,    98,   120,   100,     8,
     120,   115,    51,    52,   115,   115,    76,    56,   103,   104,
      59,    60,   107,   115,     4,   118,     4,   120,     4,   317,
     318,     4,     4,   118,    23,   323,     6,   122,    77,    78,
     103,   104,   103,   104,   107,   118,   107,     3,     3,   337,
     338,   339,   340,   341,   118,   122,   119,   119,   119,   117,
       6,     4,     4,   118,   103,   104,   117,   120,   107,   108,
       3,     3,    11,   121,     3,   107,   115,   365,     4,     3,
     368,     3,   370,   119,   123,     3,   374,     3,     1,   118,
       3,    44,   119,     5,     7,   383,     9,     4,   118,   387,
     195,    14,   269,   120,   367,    18,    19,    20,    21,    22,
     398,    24,   396,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,   399,   352,   282,    51,    52,   330,
      53,    54,    56,   240,    57,    58,    60,   171,   178,   336,
     160,   245,    65,    66,    67,    68,    69,   202,   274,    -1,
      -1,    74,    75,    77,    78,    -1,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    -1,    -1,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,     3,    -1,
      -1,    -1,     7,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,   115,   115,    -1,   117,    -1,    -1,    22,    -1,   123,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    -1,    -1,    51,    52,    -1,    -1,    -1,    56,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    70,    71,    72,    73,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    -1,    -1,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,   100,   103,   104,    51,    52,
     107,   108,    -1,    56,    -1,    -1,    59,    60,   115,    -1,
     115,   118,    -1,   120,    -1,    -1,   123,    70,    71,    72,
      73,    51,    52,    -1,    77,    78,    56,    -1,    -1,    59,
      60,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,
     103,   104,    -1,    -1,   107,   108,    51,    52,    -1,    -1,
      -1,    56,   115,    -1,    59,    60,    -1,   120,    -1,    -1,
     123,    -1,    -1,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,    77,    78,    -1,   115,    -1,   117,    -1,    51,
      52,    -1,    -1,   123,    56,    -1,    -1,    59,    60,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
      -1,    -1,   107,   108,    -1,    77,    78,    -1,    -1,    -1,
     115,    -1,   117,    -1,    51,    52,    -1,    -1,   123,    56,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
      77,    78,    -1,   115,    -1,   117,    -1,    51,    52,    -1,
      -1,   123,    56,    51,    52,    59,    60,    -1,    56,    -1,
      -1,    59,    60,    -1,    -1,    -1,   103,   104,    -1,    -1,
     107,   108,    -1,    77,    78,    -1,    -1,    -1,   115,    77,
      78,    -1,    -1,    -1,    -1,   122,   123,    -1,    51,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    60,    -1,   103,
     104,    -1,    -1,   107,   108,   103,   104,    -1,    -1,   107,
     108,   115,    -1,   117,    77,    78,    -1,   115,    -1,   123,
      -1,   119,    51,    52,    -1,   123,    -1,    56,    51,    52,
      59,    60,    -1,    56,    -1,    -1,    59,    60,    -1,    -1,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    77,    78,
      -1,    -1,   115,    -1,    77,    78,   119,    -1,    -1,    -1,
     123,    -1,    -1,    51,    52,    -1,    -1,    -1,    56,    -1,
      -1,    59,    60,    -1,   103,   104,    -1,    -1,   107,   108,
     103,   104,    -1,    -1,   107,   108,   115,    -1,   117,    77,
      78,    -1,   115,    -1,   123,    -1,    51,    52,    -1,   122,
     123,    56,    51,    52,    59,    60,    -1,    56,    -1,    -1,
      59,    60,    -1,    -1,    -1,   103,   104,    -1,    -1,   107,
     108,    -1,    77,    78,    -1,    -1,    -1,   115,    77,    78,
      -1,   119,    -1,    -1,    -1,   123,    51,    52,    -1,    -1,
      -1,    56,    -1,    -1,    59,    60,    -1,    -1,   103,   104,
      -1,    -1,   107,   108,   103,   104,    -1,    -1,   107,   108,
     115,    -1,    77,    78,   119,    -1,   115,    -1,   123,    -1,
     119,    51,    52,    -1,   123,    -1,    56,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,    77,    78,    -1,
     115,    -1,    -1,   118,    51,    52,    51,    52,   123,    56,
      -1,    56,    59,    60,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,   104,    -1,    -1,   107,   108,    -1,
      77,    78,    77,    78,    -1,   115,    -1,    -1,    -1,   119,
      -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   104,   103,   104,
     107,   108,   107,   108,    -1,    -1,    -1,    -1,   115,    -1,
     115,    -1,    -1,    -1,   121,    -1,   123,    -1,   123
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   125,     0,   126,     1,     3,     7,     9,    14,    18,
      19,    20,    21,    22,    24,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    53,    54,    57,    58,
      65,    66,    67,    68,    69,    74,    75,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   115,   117,   127,   142,
     170,   171,   117,    15,   143,     3,   156,   157,     3,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,     4,   129,     4,   104,   130,   142,   142,   130,   142,
     142,   142,   142,   142,   142,   142,   142,   115,   172,     3,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,    51,    52,    56,    59,    60,    63,    77,    78,
     103,   104,   107,   108,   115,   117,   123,   117,   142,     3,
       5,    12,    16,    17,   104,   115,   144,   149,   150,   158,
     159,   161,   164,   165,   166,   169,   115,   117,   118,    23,
      23,    23,   117,   117,     4,   128,   142,     4,   132,   142,
      70,    71,    72,    73,   120,   133,   134,   135,     3,   173,
       7,   174,    55,   122,   142,   142,     4,   142,   142,   142,
     142,   142,    25,   142,   142,   142,   103,   117,   115,   115,
     166,   158,   115,   115,   169,    16,    17,   158,   169,     8,
      50,    61,    62,   119,   147,   148,   120,    10,    11,     3,
     120,   153,   154,   155,   155,    76,   103,   104,   107,   118,
       4,   157,   142,   142,   142,     4,   117,   118,   119,    23,
     118,   131,   119,   142,     4,     4,     4,     6,   131,   118,
     118,   122,     3,   175,   172,   117,   142,   122,   167,   169,
     122,   122,   145,   158,     3,   107,   151,   152,   169,   158,
     158,   154,   118,    61,    62,   119,   160,   119,   162,   164,
     165,   169,   169,   169,   164,   122,   142,   142,   142,   142,
     117,   142,   133,     6,   136,   137,     4,     4,   118,   117,
     135,     3,    50,   119,     8,   118,   174,     3,   168,   149,
     118,   121,   119,   121,     3,   158,   158,   119,   119,   119,
     118,   120,   118,   133,     4,   142,   142,     3,   142,     3,
     118,   122,   146,   152,   169,   122,   163,   163,   142,   142,
     142,   142,   142,   137,   133,   118,   133,   118,   119,    50,
     119,     3,   147,   119,   119,   121,   142,   136,   142,     3,
     142,     5,   142,   118,   133,   118,   121,   119,   142,   120,
     138,   139,   142,     4,   140,   141,   118,   121,   118,   118,
     121,   139,   142,   141
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   124,   125,   126,   125,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   128,   128,
     129,   129,   129,   129,   130,   130,   130,   131,   131,   132,
     132,   132,   132,   133,   133,   133,   133,   133,   133,   134,
     134,   135,   135,   136,   136,   137,   137,   138,   138,   139,
     140,   140,   141,   143,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   145,   146,   144,   144,   144,
     147,   147,   148,   148,   148,   150,   149,   151,   151,   151,
     152,   152,   152,   152,   152,   153,   153,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   158,   158,   158,   158,
     158,   159,   159,   160,   160,   160,   161,   161,   162,   163,
     164,   164,   165,   165,   166,   167,   166,   166,   168,   168,
     169,   169,   169,   169,   169,   169,   169,   170,   171,   172,
     173,   173,   174,   175,   175,   175,   175
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     3,     1,     2,     3,     4,     2,
       3,     3,     4,     2,     5,     5,     4,     2,     7,     5,
       0,     1,     2,     3,     0,     1,     2,     0,     2,     5,
       3,     3,     1,     1,     3,     4,     5,     5,     7,     1,
       3,     9,     7,     3,     1,     6,     3,     3,     1,     3,
       3,     1,     3,     0,     4,     1,     3,     2,     2,     4,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     4,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     1,     2,     0,     0,     6,     2,     1,
       2,     0,     1,     1,     1,     0,     4,     0,     1,     3,
       1,     1,     1,     3,     5,     3,     1,     1,     1,     3,
       3,     1,     4,     1,     3,     3,     1,     3,     2,     5,
       5,     2,     2,     1,     1,     1,     2,     2,     1,     1,
       3,     1,     3,     3,     1,     0,     5,     3,     3,     1,
       1,     2,     1,     2,     3,     3,     3,     3,     5,     3,
       3,     1,     3,     5,     7,     5,     3
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
  switch (yytype)
    {
          case 3: /* VAR  */
#line 179 "../src/parser.y" /* yacc.c:1257  */
      {delete []((*yyvaluep).VAR_NAME);}
#line 1715 "y.tab.c" /* yacc.c:1257  */
        break;

    case 6: /* STRING  */
#line 180 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).STRING_VALUE);}
#line 1721 "y.tab.c" /* yacc.c:1257  */
        break;

    case 128: /* relTripList  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).REL_TUPLE_TRIPLE);}
#line 1727 "y.tab.c" /* yacc.c:1257  */
        break;

    case 131: /* context  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).RELATION);}
#line 1733 "y.tab.c" /* yacc.c:1257  */
        break;

    case 132: /* relPairList  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).REL_TUPLE_PAIR);}
#line 1739 "y.tab.c" /* yacc.c:1257  */
        break;

    case 133: /* statementInfoResult  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).STM_INFO_TUPLE);}
#line 1745 "y.tab.c" /* yacc.c:1257  */
        break;

    case 134: /* statementInfoList  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).STM_INFO_TUPLE);}
#line 1751 "y.tab.c" /* yacc.c:1257  */
        break;

    case 135: /* statementInfo  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).STM_INFO);}
#line 1757 "y.tab.c" /* yacc.c:1257  */
        break;

    case 136: /* partialwrites  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).MMAP);}
#line 1763 "y.tab.c" /* yacc.c:1257  */
        break;

    case 137: /* partialwrite  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).PMMAP);}
#line 1769 "y.tab.c" /* yacc.c:1257  */
        break;

    case 138: /* reads  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).STM_INFO);}
#line 1775 "y.tab.c" /* yacc.c:1257  */
        break;

    case 139: /* oneread  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).READ);}
#line 1781 "y.tab.c" /* yacc.c:1257  */
        break;

    case 140: /* partials  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).READ);}
#line 1787 "y.tab.c" /* yacc.c:1257  */
        break;

    case 141: /* partial  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).PREAD);}
#line 1793 "y.tab.c" /* yacc.c:1257  */
        break;

    case 142: /* relation  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).RELATION);}
#line 1799 "y.tab.c" /* yacc.c:1257  */
        break;

    case 144: /* builtRelation  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).RELATION);}
#line 1805 "y.tab.c" /* yacc.c:1257  */
        break;

    case 147: /* optionalFormula  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).ASTP);}
#line 1811 "y.tab.c" /* yacc.c:1257  */
        break;

    case 149: /* tupleDeclaration  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).TUPLE_DESCRIPTOR);}
#line 1817 "y.tab.c" /* yacc.c:1257  */
        break;

    case 153: /* varList  */
#line 182 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).VAR_LIST);}
#line 1823 "y.tab.c" /* yacc.c:1257  */
        break;

    case 154: /* varDecl  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).DECLARATION_SITE);}
#line 1829 "y.tab.c" /* yacc.c:1257  */
        break;

    case 155: /* varDeclOptBrackets  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).DECLARATION_SITE);}
#line 1835 "y.tab.c" /* yacc.c:1257  */
        break;

    case 158: /* formula  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).ASTP);}
#line 1841 "y.tab.c" /* yacc.c:1257  */
        break;

    case 164: /* expList  */
#line 183 "../src/parser.y" /* yacc.c:1257  */
      {
  foreach(e, Exp *, *((*yyvaluep).EXP_LIST), delete e);
  delete ((*yyvaluep).EXP_LIST);
 }
#line 1850 "y.tab.c" /* yacc.c:1257  */
        break;

    case 165: /* constraintChain  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).ASTCP);}
#line 1856 "y.tab.c" /* yacc.c:1257  */
        break;

    case 166: /* simpleExp  */
#line 182 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).EXP);}
#line 1862 "y.tab.c" /* yacc.c:1257  */
        break;

    case 169: /* exp  */
#line 182 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).EXP);}
#line 1868 "y.tab.c" /* yacc.c:1257  */
        break;

    case 170: /* reachable  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).RELATION_ARRAY_1D);}
#line 1874 "y.tab.c" /* yacc.c:1257  */
        break;

    case 171: /* reachable_of  */
#line 181 "../src/parser.y" /* yacc.c:1257  */
      {delete ((*yyvaluep).RELATION);}
#line 1880 "y.tab.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
        case 3:
#line 206 "../src/parser.y" /* yacc.c:1646  */
    { assert( current_Declaration_Site == globalDecls);}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 211 "../src/parser.y" /* yacc.c:1646  */
    {
            flushScanBuffer();
            std::cout << err_msg;
            err_msg.clear();
            current_Declaration_Site = globalDecls;
            need_coef = false;
            std::cout << "...skipping to statement end..." << std::endl;
            delete relationDecl;
            relationDecl = NULL;
          }
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 221 "../src/parser.y" /* yacc.c:1646  */
    {flushScanBuffer();}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 222 "../src/parser.y" /* yacc.c:1646  */
    {
            flushScanBuffer();
            try {
              (yyvsp[-1].RELATION)->simplify(redundant_conj_level, redundant_constr_level);
              Relation *r = relationMap((Const_String)(yyvsp[-3].VAR_NAME));
              if (r) delete r;
              relationMap[(Const_String)(yyvsp[-3].VAR_NAME)] = (yyvsp[-1].RELATION);
            }
            catch (const std::exception &e) {
             std::cout << e.what() << std::endl;
            }
            delete [](yyvsp[-3].VAR_NAME);
          }
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 235 "../src/parser.y" /* yacc.c:1646  */
    {
            flushScanBuffer();
            (yyvsp[-1].RELATION)->simplify(redundant_conj_level, redundant_constr_level);
            (yyvsp[-1].RELATION)->print_with_subs(stdout); 
            delete (yyvsp[-1].RELATION);
          }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 241 "../src/parser.y" /* yacc.c:1646  */
    {
#if defined(OMIT_GETRUSAGE)
            printf("'time' requires getrusage, but the omega calclator was compiled with OMIT_GETRUSAGE set!\n");
#else
            flushScanBuffer();
            printf("\n");
            int t;
            Relation R;
            bool SKIP_FULL_CHECK = getenv("OC_TIMING_SKIP_FULL_CHECK");
            ((yyvsp[-1].RELATION))->and_with_GEQ();
            start_clock();
            for (t=1;t<=100;t++) {
              R = *(yyvsp[-1].RELATION);
              R.finalize();
            }
            int copyTime = clock_diff();
            start_clock();
            for (t=1;t<=100;t++) {
              R = *(yyvsp[-1].RELATION);
              R.finalize();
              R.simplify();  /* default simplification effort */
            }
            int simplifyTime = clock_diff() -copyTime;
            Relation R2;
            if (!SKIP_FULL_CHECK) {
              start_clock();
              for (t=1;t<=100;t++) {
                R2 = *(yyvsp[-1].RELATION);
                R2.finalize();
                R2.simplify(2,4); /* maximal simplification effort */
              }
            }
            int excessiveTime = clock_diff() - copyTime;
            printf("Times (in microseconds): \n");
            printf("%5d us to copy original set of constraints\n",copyTime/100);
            printf("%5d us to do the default amount of simplification, obtaining: \n\t", simplifyTime/100);
            R.print_with_subs(stdout); 
            printf("\n"); 
            if (!SKIP_FULL_CHECK) {
              printf("%5d us to do the maximum (i.e., excessive) amount of simplification, obtaining: \n\t", excessiveTime/100);
              R2.print_with_subs(stdout); 
              printf("\n");
            }
            if (!anyTimingDone) {
              bool warn = false;
#ifndef SPEED 
              warn =true;
#endif
#ifndef NDEBUG
              warn = true;
#endif
              if (warn) {
                printf("WARNING: The Omega calculator was compiled with options that force\n");
                printf("it to perform additional consistency and error checks\n");
                printf("that may slow it down substantially\n");
                printf("\n");
              }
              printf("NOTE: These times relect the time of the current _implementation_\n");
              printf("of our algorithms. Performance bugs do exist. If you intend to publish or \n");
              printf("report on the performance on the Omega test, we respectfully but strongly \n");
              printf("request that send your test cases to us to allow us to determine if the \n");
              printf("times are appropriate, and if the way you are using the Omega library to \n"); 
              printf("solve your problem is the most effective way.\n");
              printf("\n");

              printf("Also, please be aware that over the past two years, we have focused our \n");
              printf("efforts on the expressive power of the Omega library, sometimes at the\n");
              printf("expensive of raw speed. Our original implementation of the Omega test\n");
              printf("was substantially faster on the limited domain it handled.\n");
              printf("\n");
              printf("  Thanks, \n");
              printf("  the Omega Team \n");
            }
            anyTimingDone = true;
            delete (yyvsp[-1].RELATION);
#endif
          }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 318 "../src/parser.y" /* yacc.c:1646  */
    {
#if defined(OMIT_GETRUSAGE)
            printf("'timeclosure' requires getrusage, but the omega calclator was compiled with OMIT_GETRUSAGE set!\n");
#else
            flushScanBuffer();
            try {
              int t;
              Relation R;
              ((yyvsp[-1].RELATION))->and_with_GEQ();
              start_clock();
              for (t=1;t<=100;t++) {
                R = *(yyvsp[-1].RELATION);
                R.finalize();
              }
              int copyTime = clock_diff();
              start_clock();
              for (t=1;t<=100;t++) {
                R = *(yyvsp[-1].RELATION);
                R.finalize();
                R.simplify();
              }
              int simplifyTime = clock_diff() -copyTime;
              Relation Rclosed;
              start_clock();
              for (t=1;t<=100;t++) {
                Rclosed = *(yyvsp[-1].RELATION);
                Rclosed.finalize();
                Rclosed = TransitiveClosure(Rclosed, 1,Relation::Null());
              }
              int closureTime = clock_diff() - copyTime;
              Relation R2;
              start_clock();
              for (t=1;t<=100;t++) {
                R2 = *(yyvsp[-1].RELATION);
                R2.finalize();
                R2.simplify(2,4);
              }
              int excessiveTime = clock_diff() - copyTime;
              printf("Times (in microseconds): \n");
              printf("%5d us to copy original set of constraints\n",copyTime/100);
              printf("%5d us to do the default amount of simplification, obtaining: \n\t", simplifyTime/100);
              R.print_with_subs(stdout); 
              printf("\n"); 
              printf("%5d us to do the maximum (i.e., excessive) amount of simplification, obtaining: \n\t", excessiveTime/100);
              R2.print_with_subs(stdout); 
              printf("%5d us to do the transitive closure, obtaining: \n\t", closureTime/100);
              Rclosed.print_with_subs(stdout);
              printf("\n");
              if (!anyTimingDone) {
                bool warn = false;
#ifndef SPEED 
                warn =true;
#endif
#ifndef NDEBUG
                warn = true;
#endif
                if (warn) {
                  printf("WARNING: The Omega calculator was compiled with options that force\n");
                  printf("it to perform additional consistency and error checks\n");
                  printf("that may slow it down substantially\n");
                  printf("\n");
                }
                printf("NOTE: These times relect the time of the current _implementation_\n");
                printf("of our algorithms. Performance bugs do exist. If you intend to publish or \n");
                printf("report on the performance on the Omega test, we respectfully but strongly \n");
                printf("request that send your test cases to us to allow us to determine if the \n");
                printf("times are appropriate, and if the way you are using the Omega library to \n"); 
                printf("solve your problem is the most effective way.\n");
                printf("\n");
              
                printf("Also, please be aware that over the past two years, we have focused our \n");
                printf("efforts on the expressive power of the Omega library, sometimes at the\n");
                printf("expensive of raw speed. Our original implementation of the Omega test\n");
                printf("was substantially faster on the limited domain it handled.\n");
                printf("\n");
                printf("  Thanks, \n");
                printf("  the Omega Team \n");
              }
              anyTimingDone = true;
            }
            catch (const std::exception &e) {
              std::cout << e.what() << std::endl;
            }
            delete (yyvsp[-1].RELATION);
#endif
          }
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 404 "../src/parser.y" /* yacc.c:1646  */
    {
            flushScanBuffer();
            try {
              if (Must_Be_Subset(copy(*(yyvsp[-3].RELATION)), copy(*(yyvsp[-1].RELATION))))
                std::cout << "True" << std::endl;
              else if (Might_Be_Subset(copy(*(yyvsp[-3].RELATION)), copy(*(yyvsp[-1].RELATION))))
                std::cout << "Possible" << std::endl;
              else
                std::cout << "False" << std::endl;
            }
            catch (const std::exception &e) {
              std::cout << e.what() << std::endl;
            }
            delete (yyvsp[-3].RELATION);
            delete (yyvsp[-1].RELATION);
          }
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 420 "../src/parser.y" /* yacc.c:1646  */
    {
          	flushScanBuffer();
            try {
              int c = checkAllInRegion(*(yyvsp[0].RELATION));
              printf("\n%s\n", c ? "True" : "False");
            }
            catch (const std::exception &e) {
              std::cout << e.what() << std::endl;
            }
             delete (yyvsp[0].RELATION);
            }
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 431 "../src/parser.y" /* yacc.c:1646  */
    {
            flushScanBuffer();
            try {
              std::string s = MMGenerateCode((yyvsp[-2].REL_TUPLE_PAIR)->mappings, (yyvsp[-2].REL_TUPLE_PAIR)->ispaces,*(yyvsp[-1].RELATION),(yyvsp[-3].INT_VALUE));
              std::cout << s << std::endl;
            }
            catch (const std::exception &e) {
              std::cout << e.what() << std::endl;
            }
            delete (yyvsp[-1].RELATION);
            delete (yyvsp[-2].REL_TUPLE_PAIR);
          }
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 443 "../src/parser.y" /* yacc.c:1646  */
    {
            flushScanBuffer();
            try {
              std::string s = tcodegen((yyvsp[-3].INT_VALUE), *((yyvsp[-2].STM_INFO_TUPLE)), *((yyvsp[-1].RELATION)));
              std::cout << s << std::endl;
            }
            catch (const std::exception &e) {
              std::cout << e.what() << std::endl;
            }
            delete (yyvsp[-1].RELATION);
            delete (yyvsp[-2].STM_INFO_TUPLE);
          }
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 464 "../src/parser.y" /* yacc.c:1646  */
    {
            flushScanBuffer();
            try {
              Tuple<Free_Var_Decl*> lowerBounds(0), upperBounds(0), my_procs(0);
              Tuple<spmd_stmt_info *> names(0);
            
              int nr_statements = (yyvsp[-1].REL_TUPLE_TRIPLE)->space.size();
            
              for (int i = 1; i<= (yyvsp[-1].REL_TUPLE_TRIPLE)->space[1].n_out(); i++) {
                lowerBounds.append(new Free_Var_Decl("lb" + to_string(i)));
                upperBounds.append(new Free_Var_Decl("ub" + to_string(i)));
                my_procs.append(new Free_Var_Decl("my_proc" + to_string(i)));
              }
            
              for (int p = 1; p <= nr_statements; p++) {
                std::string s = std::string("s") + to_string(p-1);
                names.append(new numbered_stmt_info(p-1, Identity((yyvsp[-1].REL_TUPLE_TRIPLE)->time[p].n_out()),
                                                    (yyvsp[-1].REL_TUPLE_TRIPLE)->space[p], s.c_str()));
              }
              
              std::string s = SPMD_GenerateCode(std::string(""), (yyvsp[-1].REL_TUPLE_TRIPLE)->space, (yyvsp[-1].REL_TUPLE_TRIPLE)->time, (yyvsp[-1].REL_TUPLE_TRIPLE)->ispaces, 
                                           names,
                                           lowerBounds, upperBounds, my_procs,
                                           nr_statements);
              
              std::cout << s << std::endl;
            }
            catch (const std::exception &e) {
              std::cout << e.what() << std::endl;
            }
            delete (yyvsp[-1].REL_TUPLE_TRIPLE);
          }
#line 2475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 496 "../src/parser.y" /* yacc.c:1646  */
    {
            flushScanBuffer();
            Dynamic_Array1<Relation> &final = *(yyvsp[-1].RELATION_ARRAY_1D);
            bool any_sat = false;
            int i,n_nodes = reachable_info->node_names.size();
            for(i = 1; i <= n_nodes; i++)
              if(final[i].is_upper_bound_satisfiable()) {
                any_sat = true;
                std::cout << "Node %s: " << reachable_info->node_names[i];
                final[i].print_with_subs(stdout);
              }
            if(!any_sat)
              std::cout << "No nodes reachable.\n";
            delete (yyvsp[-1].RELATION_ARRAY_1D);
            delete reachable_info;
          }
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 514 "../src/parser.y" /* yacc.c:1646  */
    {
              (yyvsp[-6].REL_TUPLE_TRIPLE)->space.append(*(yyvsp[-4].RELATION));
              (yyvsp[-6].REL_TUPLE_TRIPLE)->time.append(*(yyvsp[-2].RELATION));
              (yyvsp[-6].REL_TUPLE_TRIPLE)->ispaces.append(*(yyvsp[0].RELATION));
              delete (yyvsp[-4].RELATION);
              delete (yyvsp[-2].RELATION);
              delete (yyvsp[0].RELATION);
              (yyval.REL_TUPLE_TRIPLE) = (yyvsp[-6].REL_TUPLE_TRIPLE);
            }
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 523 "../src/parser.y" /* yacc.c:1646  */
    {
              RelTupleTriple *rtt = new RelTupleTriple;
              rtt->space.append(*(yyvsp[-4].RELATION));
              rtt->time.append(*(yyvsp[-2].RELATION));
              rtt->ispaces.append(*(yyvsp[0].RELATION));
              delete (yyvsp[-4].RELATION);
              delete (yyvsp[-2].RELATION);
              delete (yyvsp[0].RELATION);
              (yyval.REL_TUPLE_TRIPLE) = rtt;
            }
#line 2525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 535 "../src/parser.y" /* yacc.c:1646  */
    { Block_Size = 0; Num_Procs = 0; overheadEffort=0; }
#line 2531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 536 "../src/parser.y" /* yacc.c:1646  */
    { Block_Size = (yyvsp[0].INT_VALUE); Num_Procs = 0; overheadEffort=0;}
#line 2537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 537 "../src/parser.y" /* yacc.c:1646  */
    { Block_Size = (yyvsp[-1].INT_VALUE); Num_Procs = (yyvsp[0].INT_VALUE); overheadEffort=0;}
#line 2543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 538 "../src/parser.y" /* yacc.c:1646  */
    { Block_Size = (yyvsp[-2].INT_VALUE); Num_Procs = (yyvsp[-1].INT_VALUE); overheadEffort=(yyvsp[0].INT_VALUE);}
#line 2549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 541 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.INT_VALUE) = 1;}
#line 2555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 542 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.INT_VALUE) = (yyvsp[0].INT_VALUE);}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 543 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.INT_VALUE) = -(yyvsp[0].INT_VALUE);}
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 546 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.RELATION) = new Relation(); *(yyval.RELATION) = Relation::Null();}
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 547 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.RELATION) = (yyvsp[0].RELATION); }
#line 2579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 550 "../src/parser.y" /* yacc.c:1646  */
    {
              try {
                (yyvsp[-4].REL_TUPLE_PAIR)->mappings.append(*(yyvsp[-2].RELATION));
                (yyvsp[-4].REL_TUPLE_PAIR)->mappings[(yyvsp[-4].REL_TUPLE_PAIR)->mappings.size()].compress();
                (yyvsp[-4].REL_TUPLE_PAIR)->ispaces.append(*(yyvsp[0].RELATION));
                (yyvsp[-4].REL_TUPLE_PAIR)->ispaces[(yyvsp[-4].REL_TUPLE_PAIR)->ispaces.size()].compress();
              }
              catch (const std::exception &e) {
                delete (yyvsp[-4].REL_TUPLE_PAIR);
                delete (yyvsp[-2].RELATION);
                delete (yyvsp[0].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[-2].RELATION);
              delete (yyvsp[0].RELATION);
              (yyval.REL_TUPLE_PAIR) = (yyvsp[-4].REL_TUPLE_PAIR);
            }
#line 2602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 568 "../src/parser.y" /* yacc.c:1646  */
    {
              try {
                (yyvsp[-2].REL_TUPLE_PAIR)->mappings.append(Identity((yyvsp[0].RELATION)->n_set()));
                (yyvsp[-2].REL_TUPLE_PAIR)->mappings[(yyvsp[-2].REL_TUPLE_PAIR)->mappings.size()].compress();
                (yyvsp[-2].REL_TUPLE_PAIR)->ispaces.append(*(yyvsp[0].RELATION));
                (yyvsp[-2].REL_TUPLE_PAIR)->ispaces[(yyvsp[-2].REL_TUPLE_PAIR)->ispaces.size()].compress();
              }
              catch (const std::exception &e) {
                delete (yyvsp[-2].REL_TUPLE_PAIR);
                delete (yyvsp[0].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[0].RELATION);
              (yyval.REL_TUPLE_PAIR) = (yyvsp[-2].REL_TUPLE_PAIR);
            }
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 584 "../src/parser.y" /* yacc.c:1646  */
    {
              RelTuplePair *rtp = new RelTuplePair;
              try {
                rtp->mappings.append(*(yyvsp[-2].RELATION));
                rtp->mappings[rtp->mappings.size()].compress();
                rtp->ispaces.append(*(yyvsp[0].RELATION));
                rtp->ispaces[rtp->ispaces.size()].compress();
              }
              catch (const std::exception &e) {
                delete rtp;
                delete (yyvsp[-2].RELATION);
                delete (yyvsp[0].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[-2].RELATION);
              delete (yyvsp[0].RELATION);
              (yyval.REL_TUPLE_PAIR) = rtp;
            }
#line 2647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 603 "../src/parser.y" /* yacc.c:1646  */
    {
              RelTuplePair *rtp = new RelTuplePair;
              try {
                rtp->mappings.append(Identity((yyvsp[0].RELATION)->n_set()));
                rtp->mappings[rtp->mappings.size()].compress();
                rtp->ispaces.append(*(yyvsp[0].RELATION));
                rtp->ispaces[rtp->ispaces.size()].compress();
              }
              catch (const std::exception &e) {
                delete rtp;
                delete (yyvsp[0].RELATION);
                yyerror(e.what());
                YYERROR;
              }
              delete (yyvsp[0].RELATION);
              (yyval.REL_TUPLE_PAIR) = rtp;
            }
#line 2669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 622 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.STM_INFO_TUPLE) = (yyvsp[0].STM_INFO_TUPLE);}
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 628 "../src/parser.y" /* yacc.c:1646  */
    {
                      (yyval.STM_INFO_TUPLE) = &Trans_IS(*((yyvsp[0].STM_INFO_TUPLE)), *((yyvsp[-1].RELATION)));
                      delete (yyvsp[-1].RELATION);
                    }
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 632 "../src/parser.y" /* yacc.c:1646  */
    {
                      (yyval.STM_INFO_TUPLE) = &Set_MMap(*((yyvsp[0].STM_INFO_TUPLE)), (yyvsp[-2].INT_VALUE), *((yyvsp[-1].MMAP)));
                      delete (yyvsp[-1].MMAP);
                    }
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 636 "../src/parser.y" /* yacc.c:1646  */
    {
                      (yyval.STM_INFO_TUPLE) = &Unroll_One_IS(*((yyvsp[0].STM_INFO_TUPLE)), (yyvsp[-3].INT_VALUE), (yyvsp[-2].INT_VALUE), (yyvsp[-1].INT_VALUE));
                    }
#line 2701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 639 "../src/parser.y" /* yacc.c:1646  */
    {
                      (yyval.STM_INFO_TUPLE) = &Peel_One_IS(*((yyvsp[0].STM_INFO_TUPLE)), (yyvsp[-3].INT_VALUE), (yyvsp[-2].INT_VALUE), *((yyvsp[-1].RELATION)));
                      delete (yyvsp[-1].RELATION);
                    }
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 643 "../src/parser.y" /* yacc.c:1646  */
    {
                      (yyval.STM_INFO_TUPLE) = &Peel_One_IS(*((yyvsp[0].STM_INFO_TUPLE)), (yyvsp[-5].INT_VALUE), (yyvsp[-4].INT_VALUE), *((yyvsp[-3].RELATION)), *((yyvsp[-1].RELATION)));
                      delete (yyvsp[-3].RELATION);
                      delete (yyvsp[-1].RELATION);
                    }
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 650 "../src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.STM_INFO_TUPLE) = new Tuple<stm_info>;
                    (yyval.STM_INFO_TUPLE)->append(*((yyvsp[0].STM_INFO)));
                    delete (yyvsp[0].STM_INFO);
                  }
#line 2730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 655 "../src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.STM_INFO_TUPLE) = (yyvsp[-2].STM_INFO_TUPLE);
                    (yyval.STM_INFO_TUPLE)->append(*((yyvsp[0].STM_INFO)));
                    delete (yyvsp[0].STM_INFO);
                  }
#line 2740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 662 "../src/parser.y" /* yacc.c:1646  */
    {
                (yyval.STM_INFO) = (yyvsp[-1].STM_INFO);
                (yyval.STM_INFO)->stm = *((yyvsp[-7].STRING_VALUE)); delete (yyvsp[-7].STRING_VALUE);
                (yyval.STM_INFO)->IS  = *((yyvsp[-5].RELATION)); delete (yyvsp[-5].RELATION);
                (yyval.STM_INFO)->map = *((yyvsp[-3].MMAP)); delete (yyvsp[-3].MMAP);
              }
#line 2751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 668 "../src/parser.y" /* yacc.c:1646  */
    {
                (yyval.STM_INFO) = new stm_info;
                (yyval.STM_INFO)->stm = *((yyvsp[-5].STRING_VALUE)); delete (yyvsp[-5].STRING_VALUE);
                (yyval.STM_INFO)->IS  = *((yyvsp[-3].RELATION)); delete (yyvsp[-3].RELATION);
                (yyval.STM_INFO)->map = *((yyvsp[-1].MMAP)); delete (yyvsp[-1].MMAP);
              }
#line 2762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 676 "../src/parser.y" /* yacc.c:1646  */
    {
                (yyval.MMAP) = (yyvsp[-2].MMAP);
                (yyval.MMAP)->partials.append(*((yyvsp[0].PMMAP)));
                delete (yyvsp[0].PMMAP);
              }
#line 2772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 681 "../src/parser.y" /* yacc.c:1646  */
    {
                (yyval.MMAP) = new MMap;
                (yyval.MMAP)->partials.append(*((yyvsp[0].PMMAP)));
                delete (yyvsp[0].PMMAP);
              }
#line 2782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 688 "../src/parser.y" /* yacc.c:1646  */
    {
               (yyval.PMMAP) = new PartialMMap;
               (yyval.PMMAP)->mapping = *((yyvsp[0].RELATION)); delete (yyvsp[0].RELATION);
               (yyval.PMMAP)->bounds  = *((yyvsp[-3].RELATION)); delete (yyvsp[-3].RELATION);
               (yyval.PMMAP)->var     = *((yyvsp[-5].STRING_VALUE)); delete (yyvsp[-5].STRING_VALUE);
             }
#line 2793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 694 "../src/parser.y" /* yacc.c:1646  */
    {
               (yyval.PMMAP) = new PartialMMap;
               (yyval.PMMAP)->mapping = *((yyvsp[0].RELATION)); delete (yyvsp[0].RELATION);
               (yyval.PMMAP)->bounds  = Relation::True(0);
               (yyval.PMMAP)->var     = *((yyvsp[-2].STRING_VALUE)); delete (yyvsp[-2].STRING_VALUE);
             }
#line 2804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 702 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.STM_INFO) = (yyvsp[-2].STM_INFO); (yyval.STM_INFO)->read.append(*((yyvsp[0].READ))); delete (yyvsp[0].READ);}
#line 2810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 703 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.STM_INFO) = new stm_info; (yyval.STM_INFO)->read.append(*((yyvsp[0].READ))); delete (yyvsp[0].READ);}
#line 2816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 706 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.READ) = (yyvsp[-1].READ); }
#line 2822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 709 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.READ) = (yyvsp[-2].READ); (yyval.READ)->partials.append(*((yyvsp[0].PREAD))); delete (yyvsp[0].PREAD);}
#line 2828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 710 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.READ) = new Read; (yyval.READ)->partials.append(*((yyvsp[0].PREAD))); delete (yyvsp[0].PREAD);}
#line 2834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 713 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.PREAD) = new PartialRead; (yyval.PREAD)->from = (yyvsp[-2].INT_VALUE); (yyval.PREAD)->dataFlow = *((yyvsp[0].RELATION)); delete (yyvsp[0].RELATION);}
#line 2840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 716 "../src/parser.y" /* yacc.c:1646  */
    {need_coef = true; relationDecl = new Declaration_Site();}
#line 2846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 717 "../src/parser.y" /* yacc.c:1646  */
    {
           need_coef = false;
           (yyval.RELATION) = (yyvsp[-1].RELATION); 
           if (omega_calc_debug) {
             fprintf(DebugFile,"Built relation:\n");
             (yyval.RELATION)->prefix_print(DebugFile);
           }
           current_Declaration_Site = globalDecls;
           delete relationDecl;
           relationDecl = NULL;
         }
#line 2862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 728 "../src/parser.y" /* yacc.c:1646  */
    {
           Const_String s = (yyvsp[0].VAR_NAME);
           Relation *r = relationMap(s);
           if (r == NULL) {
             yyerror(std::string("relation ") + to_string((yyvsp[0].VAR_NAME)) + std::string(" not declared"));
             delete [](yyvsp[0].VAR_NAME);
             YYERROR;
           }
           (yyval.RELATION) = new Relation(*r);
           delete [](yyvsp[0].VAR_NAME);
         }
#line 2878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 739 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.RELATION) = (yyvsp[-1].RELATION);}
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 740 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = TransitiveClosure(*(yyvsp[-1].RELATION), 1, Relation::Null());
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-1].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-1].RELATION);
         }
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 753 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             int vars = (yyvsp[-1].RELATION)->n_inp();
             *(yyval.RELATION) = Union(Identity(vars), TransitiveClosure(*(yyvsp[-1].RELATION), 1, Relation::Null()));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-1].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[-1].RELATION);
         }
#line 2921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 767 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION)= TransitiveClosure(*(yyvsp[-3].RELATION), 1, *(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-3].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[-3].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 2941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 782 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             r = Join(r,LexForward((yyvsp[0].RELATION)->n_out()));
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[0].RELATION);
         }
#line 2962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 798 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             r = Join(r,Inverse(LexForward((yyvsp[0].RELATION)->n_out())));
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 2983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 814 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             r = Join(LexForward((yyvsp[0].RELATION)->n_inp()),r);
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 830 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation o(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             r = Join(Inverse(LexForward((yyvsp[0].RELATION)->n_inp())),r);
             *(yyval.RELATION) = Difference(o,r);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 846 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation c(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             *(yyval.RELATION) = Cross_Product(Relation(*(yyvsp[0].RELATION)),c);
             *(yyval.RELATION) = Difference(r,Domain(Intersection(*(yyval.RELATION),LexForward((yyval.RELATION)->n_inp()))));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 862 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             Relation c(*(yyvsp[0].RELATION));
             Relation r(*(yyvsp[0].RELATION));
             *(yyval.RELATION) = Cross_Product(Relation(*(yyvsp[0].RELATION)),c);
             *(yyval.RELATION) = Difference(r,Range(Intersection(*(yyval.RELATION),LexForward((yyval.RELATION)->n_inp()))));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);       
         }
#line 3067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 878 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION), Basic_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 891 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION), Decoupled_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 904 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConicClosure(*(yyvsp[-1].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-1].RELATION);
             yyerror(e.what());
             YYERROR;
           }             
           delete (yyvsp[-1].RELATION);
         }
#line 3121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 917 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Project_Sym(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3139 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 930 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Project_On_Sym(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 943 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Deltas(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 956 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = DeltasToRelation(*(yyvsp[0].RELATION),(yyvsp[0].RELATION)->n_set(),(yyvsp[0].RELATION)->n_set());
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 969 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Domain(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 982 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = VennDiagramForm(*(yyvsp[0].RELATION),Relation::True(*(yyvsp[0].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 995 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = VennDiagramForm(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1010 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConvexHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1023 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = DecoupledConvexHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1036 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION),Positive_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1049 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION),Linear_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1062 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION),Affine_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1075 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Farkas(*(yyvsp[0].RELATION),Convex_Combination_Farkas);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }           
           delete (yyvsp[0].RELATION);
         }
#line 3357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1088 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = CheckForConvexRepresentation(CheckForConvexPairs(*(yyvsp[0].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1101 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = CheckForConvexRepresentation(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1114 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConvexRepresentation(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1127 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = AffineHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1140 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ConicHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1153 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = LinearHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1166 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = QuickHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1179 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = RectHull(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1192 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Hull(*(yyvsp[0].RELATION),false,1,Relation::Null());
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1205 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Hull(*(yyvsp[-2].RELATION),false,1,*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1220 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Approximate(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1233 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Range(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1246 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Inverse(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1259 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Complement(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1272 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = IterateClosure(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 3629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1285 "../src/parser.y" /* yacc.c:1646  */
    {       
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = AdvancedIterateClosure(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);    
	     }
#line 3647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1298 "../src/parser.y" /* yacc.c:1646  */
    {
	       (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = SemiNaiveClosure(*(yyvsp[0].RELATION)); 
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);    
	     }
#line 3665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1311 "../src/parser.y" /* yacc.c:1646  */
    {
	       (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = TransitiveClosure2(*(yyvsp[0].RELATION)); 
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);    
         }
#line 3683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1324 "../src/parser.y" /* yacc.c:1646  */
    {
	       (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ApproxClosure(*(yyvsp[0].RELATION)); 
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);    
         }
#line 3701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1337 "../src/parser.y" /* yacc.c:1646  */
    {
	       (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = MinDependenceDistance(*(yyvsp[0].RELATION)); 
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);    
         }
#line 3719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1350 "../src/parser.y" /* yacc.c:1646  */
    {
	       (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = ApproxToUniform(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);    
         }
#line 3737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1363 "../src/parser.y" /* yacc.c:1646  */
    {
	       (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = TransitiveReduction(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);    
         }
#line 3755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1376 "../src/parser.y" /* yacc.c:1646  */
    {
	       (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Rk(*(yyvsp[0].RELATION)); 
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);    
         }
#line 3773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1389 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = calculateTransitiveClosure(*(yyvsp[-2].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);    
         }
#line 3791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1402 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Gist(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION),1);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1417 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Composition(*(yyvsp[-3].RELATION),*(yyvsp[-1].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-3].RELATION);
             delete (yyvsp[-1].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-3].RELATION);
           delete (yyvsp[-1].RELATION);
         }
#line 3831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1432 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Composition(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1447 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = After(*(yyvsp[-2].RELATION),(yyvsp[0].INT_VALUE),(yyvsp[0].INT_VALUE));
             (*(yyval.RELATION)).prefix_print(stdout);
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
         }
#line 3870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1461 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Composition(*(yyvsp[0].RELATION),*(yyvsp[-2].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1476 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Restrict_Range(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1491 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Restrict_Domain(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1506 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Intersection(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1521 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Difference(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1536 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Union(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 3990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1551 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Cross_Product(*(yyvsp[-2].RELATION),*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[-2].RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[-2].RELATION);
           delete (yyvsp[0].RELATION);
         }
#line 4010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1566 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Union(*(yyvsp[0].RELATION), Relation::Unknown(*(yyvsp[0].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 4028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1579 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Intersection(*(yyvsp[0].RELATION), Relation::Unknown(*(yyvsp[0].RELATION)));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 4046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1592 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Upper_Bound(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 4064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1605 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Lower_Bound(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 4082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1618 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Sample_Solution(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 4100 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1631 "../src/parser.y" /* yacc.c:1646  */
    {
           (yyval.RELATION) = new Relation();
           try {
             *(yyval.RELATION) = Symbolic_Solution(*(yyvsp[0].RELATION));
           }
           catch (const std::exception &e) {
             delete (yyval.RELATION);
             delete (yyvsp[0].RELATION);
             yyerror(e.what());
             YYERROR;
           }
           delete (yyvsp[0].RELATION);
         }
#line 4118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1644 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.RELATION) = (yyvsp[0].RELATION); }
#line 4124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1645 "../src/parser.y" /* yacc.c:1646  */
    {
           if (((yyvsp[0].RELATION))->is_satisfiable()) {
             fprintf(stderr,"assert_unsatisfiable failed on ");
             ((yyvsp[0].RELATION))->print_with_subs(stderr);
             exit(1);
           }
           (yyval.RELATION)=(yyvsp[0].RELATION);
         }
#line 4137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1655 "../src/parser.y" /* yacc.c:1646  */
    {currentTuple = Output_Tuple;}
#line 4143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1656 "../src/parser.y" /* yacc.c:1646  */
    {currentTuple = Input_Tuple;}
#line 4149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1656 "../src/parser.y" /* yacc.c:1646  */
    {
                 Relation * r = new Relation((yyvsp[-5].TUPLE_DESCRIPTOR)->size,(yyvsp[-2].TUPLE_DESCRIPTOR)->size);
                 resetGlobals();
                 F_And *f = r->add_and();
                 for(int i=1;i<=(yyvsp[-5].TUPLE_DESCRIPTOR)->size;i++) {
                   (yyvsp[-5].TUPLE_DESCRIPTOR)->vars[i]->vid = r->input_var(i);
                   if (!(yyvsp[-5].TUPLE_DESCRIPTOR)->vars[i]->anonymous) 
                     r->name_input_var(i,(yyvsp[-5].TUPLE_DESCRIPTOR)->vars[i]->stripped_name);
                 }
                 for(int i=1;i<=(yyvsp[-2].TUPLE_DESCRIPTOR)->size;i++) {
                   (yyvsp[-2].TUPLE_DESCRIPTOR)->vars[i]->vid = r->output_var(i);
                   if (!(yyvsp[-2].TUPLE_DESCRIPTOR)->vars[i]->anonymous) 
                     r->name_output_var(i,(yyvsp[-2].TUPLE_DESCRIPTOR)->vars[i]->stripped_name);
                 }
                 r->setup_names();
                 foreach(e,Exp*,(yyvsp[-5].TUPLE_DESCRIPTOR)->eq_constraints, install_eq(f,e,0));
                 foreach(e,Exp*,(yyvsp[-5].TUPLE_DESCRIPTOR)->geq_constraints, install_geq(f,e,0)); 
                 foreach(c,strideConstraint*,(yyvsp[-5].TUPLE_DESCRIPTOR)->stride_constraints, install_stride(f,c));
                 foreach(e,Exp*,(yyvsp[-2].TUPLE_DESCRIPTOR)->eq_constraints, install_eq(f,e,0));
                 foreach(e,Exp*,(yyvsp[-2].TUPLE_DESCRIPTOR)->geq_constraints, install_geq(f,e,0));
                 foreach(c,strideConstraint*,(yyvsp[-2].TUPLE_DESCRIPTOR)->stride_constraints, install_stride(f,c));
                 if ((yyvsp[0].ASTP)) (yyvsp[0].ASTP)->install(f);
                 delete (yyvsp[-5].TUPLE_DESCRIPTOR);
                 delete (yyvsp[-2].TUPLE_DESCRIPTOR);
                 delete (yyvsp[0].ASTP);
                 (yyval.RELATION) = r;
               }
#line 4181 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1683 "../src/parser.y" /* yacc.c:1646  */
    {
                 Relation * r = new Relation((yyvsp[-1].TUPLE_DESCRIPTOR)->size);
                 resetGlobals();
                 F_And *f = r->add_and();
                 for(int i=1;i<=(yyvsp[-1].TUPLE_DESCRIPTOR)->size;i++) {
                   (yyvsp[-1].TUPLE_DESCRIPTOR)->vars[i]->vid = r->set_var(i);
                   if (!(yyvsp[-1].TUPLE_DESCRIPTOR)->vars[i]->anonymous) 
                     r->name_set_var(i,(yyvsp[-1].TUPLE_DESCRIPTOR)->vars[i]->stripped_name);
                 }
                 r->setup_names();
                 foreach(e,Exp*,(yyvsp[-1].TUPLE_DESCRIPTOR)->eq_constraints, install_eq(f,e,0)); 
                 foreach(e,Exp*,(yyvsp[-1].TUPLE_DESCRIPTOR)->geq_constraints, install_geq(f,e,0));
                 foreach(c,strideConstraint*,(yyvsp[-1].TUPLE_DESCRIPTOR)->stride_constraints, install_stride(f,c));
                 if ((yyvsp[0].ASTP)) (yyvsp[0].ASTP)->install(f);
                 delete (yyvsp[-1].TUPLE_DESCRIPTOR);
                 delete (yyvsp[0].ASTP);
                 (yyval.RELATION) = r;
               }
#line 4204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1701 "../src/parser.y" /* yacc.c:1646  */
    {
                 Relation * r = new Relation(0,0);
                 F_And *f = r->add_and();
                 (yyvsp[0].ASTP)->install(f);
                 delete (yyvsp[0].ASTP);
                 (yyval.RELATION) = r;
               }
#line 4216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1710 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.ASTP) = (yyvsp[0].ASTP);}
#line 4222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1711 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.ASTP) = 0;}
#line 4228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1719 "../src/parser.y" /* yacc.c:1646  */
    {currentTupleDescriptor = new tupleDescriptor; tuplePos = 1;}
#line 4234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1721 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.TUPLE_DESCRIPTOR) = currentTupleDescriptor; tuplePos = 0;}
#line 4240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1729 "../src/parser.y" /* yacc.c:1646  */
    {
           Declaration_Site *ds = defined((yyvsp[0].VAR_NAME));
           if (!ds)
             currentTupleDescriptor->extend((yyvsp[0].VAR_NAME),currentTuple,tuplePos);
           else {
             Variable_Ref *v = lookupScalar((yyvsp[0].VAR_NAME));
             if (v == NULL) {
               yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[0].VAR_NAME)));
               delete [](yyvsp[0].VAR_NAME);
               YYERROR;
             }
             if (ds != globalDecls)
               currentTupleDescriptor->extend((yyvsp[0].VAR_NAME), new Exp(v));
             else
               currentTupleDescriptor->extend(new Exp(v));
           }
           tuplePos++;
           delete [](yyvsp[0].VAR_NAME);
         }
#line 4264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1748 "../src/parser.y" /* yacc.c:1646  */
    {currentTupleDescriptor->extend(); tuplePos++;}
#line 4270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1749 "../src/parser.y" /* yacc.c:1646  */
    {
             currentTupleDescriptor->extend((yyvsp[0].EXP));
             tuplePos++;
         }
#line 4279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1753 "../src/parser.y" /* yacc.c:1646  */
    {
             currentTupleDescriptor->extend((yyvsp[-2].EXP),(yyvsp[0].EXP));
             tuplePos++;
         }
#line 4288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1757 "../src/parser.y" /* yacc.c:1646  */
    {
             currentTupleDescriptor->extend((yyvsp[-4].EXP),(yyvsp[-2].EXP),(yyvsp[0].COEF_VALUE));
             tuplePos++;
         }
#line 4297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1763 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.VAR_LIST) = (yyvsp[-2].VAR_LIST); (yyval.VAR_LIST)->insert((yyvsp[0].VAR_NAME)); (yyvsp[0].VAR_NAME) = NULL;}
#line 4303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1764 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.VAR_LIST) = new VarList; (yyval.VAR_LIST)->insert((yyvsp[0].VAR_NAME)); (yyvsp[0].VAR_NAME) = NULL;}
#line 4309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1767 "../src/parser.y" /* yacc.c:1646  */
    {
          (yyval.DECLARATION_SITE) = current_Declaration_Site = new Declaration_Site((yyvsp[0].VAR_LIST));
          foreach(s,char *, *(yyvsp[0].VAR_LIST), delete []s);
          delete (yyvsp[0].VAR_LIST);
        }
#line 4319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1774 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.DECLARATION_SITE) = (yyvsp[0].DECLARATION_SITE);}
#line 4325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1775 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.DECLARATION_SITE) = (yyvsp[-1].DECLARATION_SITE);}
#line 4331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1782 "../src/parser.y" /* yacc.c:1646  */
    {globalDecls->extend_both_tuples((yyvsp[-3].VAR_NAME), (yyvsp[-1].INT_VALUE)); delete [](yyvsp[-3].VAR_NAME);}
#line 4337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1783 "../src/parser.y" /* yacc.c:1646  */
    {
          globalDecls->extend((yyvsp[0].VAR_NAME));
          delete [](yyvsp[0].VAR_NAME);
        }
#line 4346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1789 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.ASTP) = new AST_And((yyvsp[-2].ASTP),(yyvsp[0].ASTP));}
#line 4352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1790 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.ASTP) = new AST_Or((yyvsp[-2].ASTP),(yyvsp[0].ASTP));}
#line 4358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1791 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.ASTP) = (yyvsp[0].ASTCP);}
#line 4364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1792 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.ASTP) = (yyvsp[-1].ASTP);}
#line 4370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1793 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.ASTP) = new AST_Not((yyvsp[0].ASTP));}
#line 4376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1794 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.ASTP) = new AST_exists((yyvsp[-3].DECLARATION_SITE),(yyvsp[-1].ASTP));}
#line 4382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1795 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.ASTP) = new AST_forall((yyvsp[-3].DECLARATION_SITE),(yyvsp[-1].ASTP));}
#line 4388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1814 "../src/parser.y" /* yacc.c:1646  */
    {popScope();}
#line 4394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1817 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.EXP_LIST) = (yyvsp[0].EXP_LIST); (yyval.EXP_LIST)->insert((yyvsp[-2].EXP));}
#line 4400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1818 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.EXP_LIST) = new ExpList; (yyval.EXP_LIST)->insert((yyvsp[0].EXP));}
#line 4406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1821 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.ASTCP) = new AST_constraints((yyvsp[-2].EXP_LIST),(yyvsp[-1].REL_OPERATOR),(yyvsp[0].EXP_LIST));}
#line 4412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1822 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.ASTCP) = new AST_constraints((yyvsp[-2].EXP_LIST),(yyvsp[-1].REL_OPERATOR),(yyvsp[0].ASTCP));}
#line 4418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1825 "../src/parser.y" /* yacc.c:1646  */
    {
            Variable_Ref *v = lookupScalar((yyvsp[0].VAR_NAME));
            if (v == NULL) {
              yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[0].VAR_NAME)));
              delete [](yyvsp[0].VAR_NAME);
              YYERROR;
            }
            (yyval.EXP) = new Exp(v);
            delete [](yyvsp[0].VAR_NAME);
          }
#line 4433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1835 "../src/parser.y" /* yacc.c:1646  */
    {argCount = 1;}
#line 4439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1835 "../src/parser.y" /* yacc.c:1646  */
    {
            Variable_Ref *v;
            if ((yyvsp[-1].ARGUMENT_TUPLE) == Input_Tuple)
              v = functionOfInput[(yyvsp[-4].VAR_NAME)];
            else
              v = functionOfOutput[(yyvsp[-4].VAR_NAME)];
            if (v == NULL) {
              yyerror(std::string("Function ") + to_string((yyvsp[-4].VAR_NAME)) + std::string(" not declared"));
              delete [](yyvsp[-4].VAR_NAME);
              YYERROR;
            }
            (yyval.EXP) = new Exp(v);
            delete [](yyvsp[-4].VAR_NAME);
          }
#line 4458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1849 "../src/parser.y" /* yacc.c:1646  */
    { (yyval.EXP) = (yyvsp[-1].EXP); }
#line 4464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1852 "../src/parser.y" /* yacc.c:1646  */
    {
               Variable_Ref *v = lookupScalar((yyvsp[0].VAR_NAME));
               if (v == NULL) {
                 yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[-2].ARGUMENT_TUPLE)));
                 delete [](yyvsp[0].VAR_NAME);
                 YYERROR;
               }
               if (v->pos != argCount || v->of != (yyvsp[-2].ARGUMENT_TUPLE) || (v->of != Input_Tuple && v->of != Output_Tuple)) {
                 yyerror("arguments to function must be prefix of input or output tuple");
                 delete [](yyvsp[0].VAR_NAME);
                 YYERROR;
               }
               (yyval.ARGUMENT_TUPLE) = v->of;
               argCount++;
               delete [](yyvsp[0].VAR_NAME);
             }
#line 4485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1868 "../src/parser.y" /* yacc.c:1646  */
    {
               Variable_Ref *v = lookupScalar((yyvsp[0].VAR_NAME));
               if (v == NULL) {
                 yyerror(std::string("cannot find declaration for variable ") + to_string((yyvsp[0].VAR_NAME)));
                 delete [](yyvsp[0].VAR_NAME);
                 YYERROR;
               }
               if (v->pos != argCount || (v->of != Input_Tuple && v->of != Output_Tuple)) {
                 yyerror("arguments to function must be prefix of input or output tuple");
                 delete [](yyvsp[0].VAR_NAME);
                 YYERROR;
               }
               (yyval.ARGUMENT_TUPLE) = v->of;
               argCount++;
               delete [](yyvsp[0].VAR_NAME);
             }
#line 4506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1886 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.EXP) = new Exp((yyvsp[0].COEF_VALUE));}
#line 4512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1887 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.EXP) = multiply((yyvsp[-1].COEF_VALUE),(yyvsp[0].EXP));}
#line 4518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1888 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.EXP) = (yyvsp[0].EXP); }
#line 4524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1889 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.EXP) = negate((yyvsp[0].EXP));}
#line 4530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1890 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.EXP) = add((yyvsp[-2].EXP),(yyvsp[0].EXP));}
#line 4536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1891 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.EXP) = subtract((yyvsp[-2].EXP),(yyvsp[0].EXP));}
#line 4542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1892 "../src/parser.y" /* yacc.c:1646  */
    {(yyval.EXP) = multiply((yyvsp[-2].EXP),(yyvsp[0].EXP));}
#line 4548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1896 "../src/parser.y" /* yacc.c:1646  */
    {
            Dynamic_Array1<Relation> *final = Reachable_Nodes(reachable_info);
            (yyval.RELATION_ARRAY_1D) = final;
          }
#line 4557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1902 "../src/parser.y" /* yacc.c:1646  */
    {
               Dynamic_Array1<Relation> *final = Reachable_Nodes(reachable_info);
               int index = reachable_info->node_names.index(std::string((yyvsp[-3].VAR_NAME)));
               if (index == 0) {
                 yyerror(std::string("no such node ") + to_string((yyvsp[-3].VAR_NAME)));
                 delete [](yyvsp[-3].VAR_NAME);
                 delete final;
                 delete reachable_info;
                 YYERROR;
               }
               (yyval.RELATION) = new Relation; 
               *(yyval.RELATION) = (*final)[index];
               delete final;
               delete reachable_info;
               delete [](yyvsp[-3].VAR_NAME);
             }
#line 4578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1920 "../src/parser.y" /* yacc.c:1646  */
    {
               int sz = reachable_info->node_names.size();
               reachable_info->node_arity.reallocate(sz);
               reachable_info->transitions.resize(sz+1,sz+1);
               reachable_info->start_nodes.resize(sz+1);
             }
#line 4589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1928 "../src/parser.y" /* yacc.c:1646  */
    {
                   reachable_info->node_names.append(std::string((yyvsp[0].VAR_NAME)));
                   delete [](yyvsp[0].VAR_NAME);
                 }
#line 4598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1932 "../src/parser.y" /* yacc.c:1646  */
    {
                   reachable_info = new reachable_information;
                   reachable_info->node_names.append(std::string((yyvsp[0].VAR_NAME)));
                   delete [](yyvsp[0].VAR_NAME);
                 }
#line 4608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1940 "../src/parser.y" /* yacc.c:1646  */
    {  
                        int i,j;
                        int n_nodes = reachable_info->node_names.size();
                        Tuple<int> &arity = reachable_info->node_arity;
                        Dynamic_Array2<Relation> &transitions = reachable_info->transitions;

                        /* fixup unspecified transitions to be false */
                        /* find arity */
                        for(i = 1; i <= n_nodes; i++) arity[i] = -1;
                        for(i = 1; i <= n_nodes; i++)
                          for(j = 1; j <= n_nodes; j++)
                            if(! transitions[i][j].is_null()) {
                              int in_arity = transitions[i][j].n_inp();
                              int out_arity = transitions[i][j].n_out();
                              if(arity[i] < 0) arity[i] = in_arity;
                              if(arity[j] < 0) arity[j] = out_arity;
                              if(in_arity != arity[i] || out_arity != arity[j]) {
                                yyerror(std::string("arity mismatch in node transition: ") + to_string(reachable_info->node_names[i]) + std::string(" -> ") + to_string(reachable_info->node_names[j]));
                                delete reachable_info;
                                YYERROR;
                              }
                            }
                        for(i = 1; i <= n_nodes; i++) 
                          if(arity[i] < 0) arity[i] = 0;
                        /* Fill in false relations */
                        for(i = 1; i <= n_nodes; i++)
                          for(j = 1; j <= n_nodes; j++)
                            if(transitions[i][j].is_null())
                              transitions[i][j] = Relation::False(arity[i],arity[j]);

                        /* fixup unused start node positions */
                        Dynamic_Array1<Relation> &nodes = reachable_info->start_nodes;
                        for(i = 1; i <= n_nodes; i++) 
                          if(nodes[i].is_null()) 
                            nodes[i] = Relation::False(arity[i]);
                          else
                            if(nodes[i].n_set() != arity[i]){
                              yyerror(std::string("arity mismatch in start node ") + to_string(reachable_info->node_names[i]));
                              delete reachable_info;
                              YYERROR;
                            }
                   }
#line 4655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1984 "../src/parser.y" /* yacc.c:1646  */
    {
                            int n_nodes = reachable_info->node_names.size();
                            int index = reachable_info->node_names.index((yyvsp[-2].VAR_NAME));
                            if (!(index > 0 && index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-2].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->start_nodes[index] = *(yyvsp[0].RELATION);
                            delete (yyvsp[0].RELATION);
                            delete [](yyvsp[-2].VAR_NAME);
                          }
#line 4674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1998 "../src/parser.y" /* yacc.c:1646  */
    {
                            int n_nodes = reachable_info->node_names.size();
                            int from_index = reachable_info->node_names.index((yyvsp[-4].VAR_NAME));
                            if (!(from_index > 0 && from_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-4].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-4].VAR_NAME);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            int to_index = reachable_info->node_names.index((yyvsp[-2].VAR_NAME));
                            if (!(to_index > 0 && to_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-2].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-4].VAR_NAME);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->transitions[from_index][to_index] = *(yyvsp[0].RELATION);
                            delete (yyvsp[0].RELATION);
                            delete [](yyvsp[-4].VAR_NAME);
                            delete [](yyvsp[-2].VAR_NAME);
                          }
#line 4704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 2023 "../src/parser.y" /* yacc.c:1646  */
    {
                            int n_nodes = reachable_info->node_names.size();
                            int from_index = reachable_info->node_names.index((yyvsp[-4].VAR_NAME));
                            if (!(from_index > 0 && from_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-4].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-4].VAR_NAME);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            int to_index = reachable_info->node_names.index((yyvsp[-2].VAR_NAME));
                            if (!(to_index > 0 && to_index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-2].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-4].VAR_NAME);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->transitions[from_index][to_index] = *(yyvsp[0].RELATION);
                            delete (yyvsp[0].RELATION);
                            delete [](yyvsp[-4].VAR_NAME);
                            delete [](yyvsp[-2].VAR_NAME);
                          }
#line 4734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 2048 "../src/parser.y" /* yacc.c:1646  */
    {
                            int n_nodes = reachable_info->node_names.size();
                            int index = reachable_info->node_names.index((yyvsp[-2].VAR_NAME));
                            if (!(index > 0 && index <= n_nodes)) {
                              yyerror(std::string("no such node ")+to_string((yyvsp[-2].VAR_NAME)));
                              delete (yyvsp[0].RELATION);
                              delete [](yyvsp[-2].VAR_NAME);
                              delete reachable_info;
                              YYERROR;
                            }
                            reachable_info->start_nodes[index] = *(yyvsp[0].RELATION);
                            delete (yyvsp[0].RELATION);
                            delete [](yyvsp[-2].VAR_NAME);
                          }
#line 4753 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4757 "y.tab.c" /* yacc.c:1646  */
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
#line 2064 "../src/parser.y" /* yacc.c:1906  */



void printUsage(FILE *outf, char **argv) {
  fprintf(outf, "usage: %s {-R} {-D[facility][level]...} infile\n  -R means skip redundant conjunct elimination\n  -D sets debugging level as follows:\n    a = all debugging flags\n    g = code generation\n    l = calculator\n    c = omega core\n    p = presburger functions\n    r = relational operators\n    t = transitive closure\n", argv[0]);
}


bool process_calc_debugging_flags(char *arg,int &j) {
  char debug_type;
  while((debug_type=arg[j]) != 0) {
    j++;
    int level;
    if(isdigit(arg[j]))
      level = (arg[j++]) - '0';
    else
      if(arg[j] == 0 || isalpha(arg[j]))
        level = 1;
      else 
        return false;
    if (level < 0 || level > 4) {
      fprintf(stderr,"Debug level %c out of range: %d\n", debug_type, level);
      return false;
    }
    switch(debug_type) {
    case 'a':
      omega_core_debug = relation_debug = hull_debug =
        closure_presburger_debug = 
        farkas_debug = 
        pres_debug = omega_calc_debug = code_gen_debug = level;
      break;
    case 'g':
      code_gen_debug = level; break;
    case 'f':
      farkas_debug = level; break;
    case 'h':
      hull_debug = level; break;
    case 'c':
      omega_core_debug = level; break;
    case 'r':
      relation_debug = level; break;
    case 'p':
      pres_debug = level; break;
    case 't':
      closure_presburger_debug = level; break;
    case 'l':
      omega_calc_debug = level; break;
#if defined STUDY_EVACUATIONS
    case 'e':
      evac_debug = level; break;
#endif
    default:
      fprintf(stderr, "Unknown debug type %c\n", debug_type);
      return false;
    }
  }
  return true;
}


int main(int argc, char **argv) {
#if YYDEBUG != 0
  yydebug  = 1;
#endif

  /* process flags */
  char *fileName = 0;
  for(int i=1; i<argc; i++) {
    if(argv[i][0] == '-') {
      int j = 1, c;
      while((c=argv[i][j++]) != 0) {
        switch(c) {
        case 'D':
          if (!process_calc_debugging_flags(argv[i],j)) {
            printUsage(stderr, argv);
            exit(1);
          }          
          break;
        case 'G':
          fprintf(stderr,"Note: specifying number of GEQ's is no longer useful.\n");
          while(argv[i][j] != 0) j++;
          break;
        case 'E':
          fprintf(stderr,"Note: specifying number of EQ's is no longer useful.\n");
          while(argv[i][j] != 0) j++;
          break;
        case 'R':
          redundant_conj_level = 1;
          break;
          /* Other future options go here */
        case 'h':
          printUsage(stderr, argv);
          exit(1);
          break;
        default:
          fprintf(stderr, "\nUnknown flag -%c\n", c);
          printUsage(stderr, argv);
          exit(1);
        }
      }
    } 
    else {
      /* Make sure this is a file name */
      if (fileName) {
        fprintf(stderr,"\nCan only handle a single input file\n");
        printUsage(stderr,argv);
        exit(1);
      }
      fileName = argv[i];
      yyin = fopen(fileName, "r");
      if (!yyin) {
        fprintf(stderr, "\nCan't open input file %s\n",fileName);
        printUsage(stderr,argv);
        exit(1);
      }
    }
  }

  if (fileName || !isatty((int)fileno(stdin))) {
    is_interactive = false;
  }
  else {
    is_interactive = true;
    setbuf(DebugFile, NULL);
    printf("Omega calculator for Omega+ v2.1.2 (built on %s)\n", OMEGA_BUILD_DATE);
    printf("Copyright (C) 1994-2000 University of Maryland the Omega Project Team\n");
    printf("Copyright (C) 2008 University of Southern California\n");
    printf("Copyright (C) 2009-2010 University of Utah\n");
    printf("Copyright (C) 2009-2010 West Pomeranian University of Technology, Szczecin\n");
    printf("%s ", PROMPT_STRING);
  }
  need_coef = false;  
  current_Declaration_Site = globalDecls = new Global_Declaration_Site();

  if (yyparse() != 0) {
    if (!is_interactive)
      std::cout << "syntax error at the end of the file, missing ';'" << std::endl;
    else
      std::cout << std::endl;
    delete relationDecl;
    relationDecl = NULL;
  }
  else {
    if (is_interactive)
      std::cout << std::endl;
  }

  foreach_map(cs,Const_String,r,Relation *,relationMap,
              {delete r; relationMap[cs]=0;});
  delete globalDecls;  
  fclose(yyin);
  
  return 0;
}

Relation LexForward(int n) {
  Relation r(n,n);
  F_Or *f = r.add_or();
  for (int i=1; i <= n; i++) {
    F_And *g = f->add_and();
    for(int j=1;j<i;j++) {
      EQ_Handle e = g->add_EQ();
      e.update_coef(r.input_var(j),-1);
      e.update_coef(r.output_var(j),1);
      e.finalize();
    }
    GEQ_Handle e = g->add_GEQ();
    e.update_coef(r.input_var(i),-1);
    e.update_coef(r.output_var(i),1);
    e.update_const(-1);
    e.finalize();
  }
  r.finalize();
  return r;
}
