/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 94 "../src/parser.y" /* yacc.c:1909  */

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

#line 304 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
