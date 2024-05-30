
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	LOWER_THAN_ELSE	258
#define	TELSE	259
#define	LOWER_THAN_OPT_STAT_LIST	260
#define	OPT_STAT_LIST	261
#define	TEOF	262
#define	TIDENT	263
#define	TNUMBER	264
#define	TREAL	265
#define	TCONST	266
#define	TIF	267
#define	TINT	268
#define	TFLOAT	269
#define	TRETURN	270
#define	TVOID	271
#define	TWHILE	272
#define	TASSIGN	273
#define	TADDASSIGN	274
#define	TSUBASSIGN	275
#define	TMULASSIGN	276
#define	TDIVASSIGN	277
#define	TMODASSIGN	278
#define	TNOT	279
#define	TAND	280
#define	TOR	281
#define	TEQUAL	282
#define	TNOTEQU	283
#define	TLESS	284
#define	TGREAT	285
#define	TLESSEQU	286
#define	TGREATEQU	287
#define	TINC	288
#define	TDEC	289
#define	TADD	290
#define	TSUB	291
#define	TMUL	292
#define	TDIV	293
#define	TMOD	294
#define	TLPAREN	295
#define	TRPAREN	296
#define	TLCURLY	297
#define	TRCURLY	298
#define	TLSQUARE	299
#define	TRSQUARE	300
#define	TCOMMA	301
#define	TSEMI	302

#line 6 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

/*yacc source for Mini C*/

int con = 0;			// con: 상수 관리를 위해 사용된 플래그 변수. TCONST 토큰을 만나면 1, 아닐 경우 0
int func = 0;			// func: 함수 관리를 위해 사용된 플래그 변수. 분석중인 구문이 함수일 경우 1, 아닐 경우 0
int param = 0;		// param: 함수의 파라미터 관리를 위해 사용된 플래그 변수. 파라미터가 존재하면 1, 아닐 경우 0
int array = 0;		// array: 배열의 관리를 위해 사용된 플래그 변수. 배열일 경우 1, 아닐 경우 0
int type = NONE;		// type: type을 관리하기 위해 사용된 변수. TINT 토큰을 만나면 INT,TNOID 토큰을 만나면 VOID, TFLOAT 토큰을 만나면 FLOAT

extern int yylex();
extern yyerror(char* s);
void changeHSTable();

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		206
#define	YYFLAG		-32768
#define	YYNTBASE	48

#define YYTRANSLATE(x) ((unsigned)(x) <= 302 ? yytranslate[x] : 94)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    20,    23,
    26,    29,    33,    35,    37,    40,    42,    44,    46,    48,
    50,    52,    54,    58,    62,    64,    65,    67,    71,    75,
    78,    81,    86,    91,    93,    94,    96,    99,   103,   107,
   109,   113,   116,   118,   122,   126,   130,   134,   136,   141,
   146,   148,   149,   152,   153,   155,   158,   161,   163,   165,
   167,   169,   171,   174,   177,   179,   180,   186,   194,   199,
   204,   207,   215,   223,   228,   233,   236,   240,   244,   246,
   248,   252,   256,   260,   264,   268,   272,   275,   278,   281,
   284,   287,   290,   292,   296,   300,   302,   306,   310,   312,
   316,   320,   324,   328,   330,   334,   338,   342,   346,   350,
   354,   358,   362,   364,   368,   372,   376,   380,   382,   386,
   390,   394,   398,   402,   406,   408,   411,   414,   417,   420,
   422,   427,   432,   437,   442,   445,   448,   450,   452,   454,
   458,   459,   462,   464,   466,   470
};

static const short yyrhs[] = {    49,
     0,    50,     0,    49,    50,     0,    51,     0,    66,     0,
     8,    47,     0,     8,     1,     0,    52,    63,     0,    52,
     1,     0,    52,    47,     0,     1,    63,     0,    53,    58,
    59,     0,    54,     0,    55,     0,    54,    55,     0,    56,
     0,    57,     0,    11,     0,    13,     0,    16,     0,    14,
     0,     8,     0,    40,    60,    41,     0,    40,    60,     1,
     0,    61,     0,     0,    62,     0,    61,    46,    62,     0,
    61,    46,     1,     0,    61,    62,     0,    53,    69,     0,
    42,    64,    71,    43,     0,    42,    64,    71,     1,     0,
    65,     0,     0,    66,     0,    65,    66,     0,    53,    67,
    47,     0,    53,    67,     1,     0,    68,     0,    67,    46,
    68,     0,    67,    68,     0,    69,     0,    69,    18,     9,
     0,    69,    27,     9,     0,    69,    18,    10,     0,    69,
    27,    10,     0,     8,     0,     8,    44,    70,    45,     0,
     8,    44,    70,     1,     0,     9,     0,     0,    72,     6,
     0,     0,    73,     0,    72,     1,     0,    72,    73,     0,
    63,     0,    74,     0,    76,     0,    77,     0,    78,     0,
    75,    47,     0,    79,     1,     0,    79,     0,     0,    12,
    40,    79,    41,    73,     0,    12,    40,    79,    41,    73,
     4,    73,     0,    12,    40,    79,     1,     0,    12,    40,
    41,     1,     0,    12,     1,     0,    17,    40,    79,    41,
    42,    71,    43,     0,    17,    40,    79,    41,    42,    71,
     1,     0,    17,    40,    79,     1,     0,    17,    40,    41,
     1,     0,    17,     1,     0,    15,    75,    47,     0,    15,
    75,     1,     0,    80,     0,    81,     0,    87,    18,    80,
     0,    87,    19,    80,     0,    87,    20,    80,     0,    87,
    21,    80,     0,    87,    22,    80,     0,    87,    23,    80,
     0,    87,    18,     0,    87,    19,     0,    87,    20,     0,
    87,    21,     0,    87,    22,     0,    87,    23,     0,    82,
     0,    81,    26,    82,     0,    81,    26,     1,     0,    83,
     0,    82,    25,    83,     0,    82,    25,     1,     0,    84,
     0,    83,    27,    84,     0,    83,    28,    84,     0,    83,
    27,     1,     0,    83,    28,     1,     0,    85,     0,    84,
    30,    85,     0,    84,    29,    85,     0,    84,    32,    85,
     0,    84,    31,    85,     0,    84,    30,     1,     0,    84,
    29,     1,     0,    84,    32,     1,     0,    84,    31,     1,
     0,    86,     0,    85,    35,    86,     0,    85,    36,    86,
     0,    85,    35,     1,     0,    85,    36,     1,     0,    87,
     0,    86,    37,    87,     0,    86,    38,    87,     0,    86,
    39,    87,     0,    86,    37,     1,     0,    86,    38,     1,
     0,    86,    39,     1,     0,    88,     0,    36,    87,     0,
    24,    87,     0,    33,    87,     0,    34,    87,     0,    92,
     0,    88,    42,    79,    43,     0,    88,    42,    79,     1,
     0,    88,    40,    89,    41,     0,    88,    40,    89,     1,
     0,    88,    33,     0,    88,    34,     0,    90,     0,    91,
     0,    80,     0,    91,    46,    80,     0,     0,     8,    93,
     0,     9,     0,    10,     0,    40,    79,    41,     0,    40,
    79,     1,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    41,    44,    45,    48,    49,    50,    51,    55,    56,    58,
    59,    63,    66,    69,    70,    73,    74,    77,    80,    81,
    82,    85,    95,    96,   100,   108,   111,   113,   114,   116,
   120,   124,   125,   129,   130,   133,   134,   139,   147,   157,
   158,   159,   163,   164,   165,   167,   168,   172,   173,   174,
   178,   179,   182,   183,   186,   187,   188,   191,   192,   193,
   194,   195,   198,   199,   204,   205,   208,   209,   210,   211,
   212,   215,   216,   217,   218,   219,   222,   223,   226,   228,
   229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
   239,   240,   243,   244,   245,   248,   249,   250,   253,   254,
   255,   256,   257,   260,   261,   262,   263,   264,   265,   266,
   267,   268,   271,   272,   273,   274,   275,   278,   279,   280,
   281,   282,   283,   284,   287,   288,   289,   290,   291,   294,
   295,   296,   297,   298,   299,   300,   303,   305,   307,   308,
   311,   316,   317,   318,   319,   320
};

static const char * const yytname[] = {   "$","error","$undefined.","LOWER_THAN_ELSE",
"TELSE","LOWER_THAN_OPT_STAT_LIST","OPT_STAT_LIST","TEOF","TIDENT","TNUMBER",
"TREAL","TCONST","TIF","TINT","TFLOAT","TRETURN","TVOID","TWHILE","TASSIGN",
"TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN","TNOT","TAND",
"TOR","TEQUAL","TNOTEQU","TLESS","TGREAT","TLESSEQU","TGREATEQU","TINC","TDEC",
"TADD","TSUB","TMUL","TDIV","TMOD","TLPAREN","TRPAREN","TLCURLY","TRCURLY","TLSQUARE",
"TRSQUARE","TCOMMA","TSEMI","mini_c","translation_unit","external_dcl","function_def",
"function_header","dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier",
"type_specifier","function_name","formal_param","opt_formal_param","formal_param_list",
"param_dcl","compound_st","opt_dcl_list","declaration_list","declaration","init_dcl_list",
"init_declarator","declarator","opt_number","opt_stat_list","statement_list",
"statement","expression_st","opt_expression","if_st","while_st","return_st",
"expression","assignment_exp","logical_or_exp","logical_and_exp","equality_exp",
"relational_exp","additive_exp","multiplicative_exp","unary_exp","postfix_exp",
"opt_actual_param","actual_param","actual_param_list","primary_exp","@1",""
};
#endif

static const short yyr1[] = {     0,
    48,    49,    49,    50,    50,    50,    50,    51,    51,    51,
    51,    52,    53,    54,    54,    55,    55,    56,    57,    57,
    57,    58,    59,    59,    60,    60,    61,    61,    61,    61,
    62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
    67,    67,    68,    68,    68,    68,    68,    69,    69,    69,
    70,    70,    71,    71,    72,    72,    72,    73,    73,    73,
    73,    73,    74,    74,    75,    75,    76,    76,    76,    76,
    76,    77,    77,    77,    77,    77,    78,    78,    79,    80,
    80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
    80,    80,    81,    81,    81,    82,    82,    82,    83,    83,
    83,    83,    83,    84,    84,    84,    84,    84,    84,    84,
    84,    84,    85,    85,    85,    85,    85,    86,    86,    86,
    86,    86,    86,    86,    87,    87,    87,    87,    87,    88,
    88,    88,    88,    88,    88,    88,    89,    90,    91,    91,
    93,    92,    92,    92,    92,    92
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     2,     3,     1,     1,     2,     1,     1,     1,     1,     1,
     1,     1,     3,     3,     1,     0,     1,     3,     3,     2,
     2,     4,     4,     1,     0,     1,     2,     3,     3,     1,
     3,     2,     1,     3,     3,     3,     3,     1,     4,     4,
     1,     0,     2,     0,     1,     2,     2,     1,     1,     1,
     1,     1,     2,     2,     1,     0,     5,     7,     4,     4,
     2,     7,     7,     4,     4,     2,     3,     3,     1,     1,
     3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
     2,     2,     1,     3,     3,     1,     3,     3,     1,     3,
     3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
     3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
     3,     3,     3,     3,     1,     2,     2,     2,     2,     1,
     4,     4,     4,     4,     2,     2,     1,     1,     1,     3,
     0,     2,     1,     1,     3,     3
};

static const short yydefact[] = {     0,
     0,     0,    18,    19,    21,    20,     0,     2,     4,     0,
     0,    13,    14,    16,    17,     5,    35,    11,     7,     6,
     3,     9,    10,     8,    48,     0,     0,    40,    43,    15,
     0,    54,    34,    36,    52,    26,    12,    39,    48,     0,
    38,    42,     0,     0,   141,   143,   144,     0,    66,     0,
     0,     0,     0,     0,     0,    58,     0,     0,    55,    59,
     0,    60,    61,    62,     0,    79,    80,    93,    96,    99,
   104,   113,   118,   125,   130,    37,    51,     0,     0,     0,
    25,    27,    41,    44,    46,    45,    47,   142,    71,     0,
     0,    65,    76,     0,   127,   128,   129,   126,     0,    33,
    32,    56,    53,    57,    63,    64,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
    88,    89,    90,    91,    92,   135,   136,     0,     0,    50,
    49,    31,    24,    23,     0,    30,     0,     0,    78,    77,
     0,     0,   146,   145,    95,    94,   118,    98,    97,   102,
   100,   103,   101,   110,   106,   109,   105,   112,   108,   111,
   107,   116,   114,   117,   115,   122,   119,   123,   120,   124,
   121,    81,    82,    83,    84,    85,    86,   139,     0,   137,
   138,     0,    29,    28,    70,    69,    66,    75,    74,     0,
   134,   133,     0,   132,   131,    67,    54,   140,    66,     0,
    68,    73,    72,     0,     0,     0
};

static const short yydefgoto[] = {   204,
     7,     8,     9,    10,    79,    12,    13,    14,    15,    26,
    37,    80,    81,    82,    56,    32,    33,    16,    27,    28,
    29,    78,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
   179,   180,   181,    75,    88
};

static const short yypact[] = {   371,
   -19,    24,-32768,-32768,-32768,-32768,   367,-32768,-32768,     5,
    18,    84,-32768,-32768,-32768,-32768,    84,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,     1,    -2,     7,-32768,     6,-32768,
    35,    97,    84,-32768,    40,    84,-32768,-32768,    55,    35,
-32768,-32768,   106,   133,-32768,-32768,-32768,    56,   337,    92,
   337,   337,   337,   337,   337,-32768,    33,    77,-32768,-32768,
     4,-32768,-32768,-32768,    26,-32768,    82,    66,   136,   122,
   144,    65,   374,   323,-32768,-32768,-32768,    30,    35,    15,
   109,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   308,
    27,-32768,-32768,   319,-32768,-32768,-32768,-32768,    39,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,   126,   137,   148,   166,
   177,   188,   206,   217,   228,   246,   257,   268,   286,   337,
   337,   337,   337,   337,   337,-32768,-32768,   337,   337,-32768,
-32768,-32768,-32768,-32768,   375,-32768,   117,    43,-32768,-32768,
   125,    47,-32768,-32768,-32768,    66,-32768,-32768,   136,-32768,
   122,-32768,   122,-32768,   144,-32768,   144,-32768,   144,-32768,
   144,-32768,    65,-32768,    65,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,    49,-32768,
    94,    34,-32768,-32768,-32768,-32768,   297,-32768,-32768,    86,
-32768,-32768,   337,-32768,-32768,   161,    97,-32768,   297,    36,
-32768,-32768,-32768,   183,   195,-32768
};

static const short yypgoto[] = {-32768,
-32768,   141,-32768,-32768,    22,-32768,   193,-32768,-32768,-32768,
-32768,-32768,-32768,   -63,    20,-32768,-32768,     3,-32768,    -8,
   129,-32768,    12,-32768,   -58,-32768,   170,-32768,-32768,-32768,
   -48,  -111,-32768,   113,   115,    59,    80,    88,   -49,-32768,
-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		397


static const short yytable[] = {   104,
    92,    95,    96,    97,    98,    22,    99,    38,   172,   173,
   174,   175,   176,   177,    39,   133,   178,   136,    42,    34,
    18,    11,    17,    43,    19,    25,   106,   139,    11,    24,
   130,    83,    44,   100,   194,    76,   202,    36,    31,   143,
   -22,   138,    39,   186,    35,   142,    17,   189,    77,   191,
   105,    23,    40,    41,    31,   134,    89,   147,   147,   147,
   147,   147,   147,   147,   147,   147,   147,   167,   169,   171,
    20,   184,   -65,   140,   131,   101,   195,   102,   203,   144,
   182,   198,   103,   187,    45,    46,    47,   190,    48,   192,
   108,    49,    93,    50,     3,    90,     4,     5,    35,     6,
    51,   117,   118,   119,    45,    46,    47,   107,    48,    52,
    53,    49,    54,    50,    84,    85,    55,   185,    17,     3,
    51,     4,     5,   -66,     6,   188,   145,   197,   196,    52,
    53,    94,    54,    45,    46,    47,    55,   148,    17,   193,
   201,    86,    87,   -66,    45,    46,    47,    21,   150,    51,
   111,   112,   113,   114,   135,    45,    46,    47,    52,    53,
    51,    54,   109,   110,   199,    55,   152,   151,   153,    52,
    53,    51,    54,    45,    46,    47,    55,   154,   115,   116,
    52,    53,   205,    54,    45,    46,    47,    55,   156,    51,
   155,   157,   159,   161,   206,    45,    46,    47,    52,    53,
    51,    54,   163,   165,    30,    55,   158,   132,   200,    52,
    53,    51,    54,    45,    46,    47,    55,   160,    91,   146,
    52,    53,   149,    54,    45,    46,    47,    55,   162,    51,
     0,     0,     0,     0,     0,    45,    46,    47,    52,    53,
    51,    54,     0,     0,     0,    55,   164,     0,     0,    52,
    53,    51,    54,    45,    46,    47,    55,   166,     0,     0,
    52,    53,     0,    54,    45,    46,    47,    55,   168,    51,
     0,     0,     0,     0,     0,    45,    46,    47,    52,    53,
    51,    54,     0,     0,     0,    55,   170,     0,     0,    52,
    53,    51,    54,    45,    46,    47,    55,     0,     0,     0,
    52,    53,     0,    54,    45,    46,    47,    55,    48,    51,
     0,    49,     0,    50,     0,    45,    46,    47,    52,    53,
    51,    54,     0,     0,     0,    55,    45,    46,    47,    52,
    53,    51,    54,     0,     0,     0,    55,     0,    17,     0,
    52,    53,    51,    54,    45,    46,    47,    55,   137,     0,
     0,    52,    53,     0,    54,   126,   127,     0,    55,   141,
    51,     0,   128,     0,   129,     0,    -1,     1,     0,    52,
    53,     1,    54,     0,     2,   183,    55,     3,     2,     4,
     5,     3,     6,     4,     5,     3,     6,     4,     5,     0,
     6,   120,   121,   122,   123,   124,   125
};

static const short yycheck[] = {    58,
    49,    51,    52,    53,    54,     1,    55,     1,   120,   121,
   122,   123,   124,   125,     8,     1,   128,    81,    27,    17,
     1,     0,    42,    18,     1,     8,     1,     1,     7,    10,
     1,    40,    27,     1,     1,    33,     1,    40,    17,     1,
    40,    90,     8,     1,    44,    94,    42,     1,     9,     1,
    47,    47,    46,    47,    33,    41,     1,   107,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
    47,   135,    47,    47,    45,    43,    43,     1,    43,    41,
   129,   193,     6,    41,     8,     9,    10,    41,    12,    41,
    25,    15,     1,    17,    11,    40,    13,    14,    44,    16,
    24,    37,    38,    39,     8,     9,    10,    26,    12,    33,
    34,    15,    36,    17,     9,    10,    40,     1,    42,    11,
    24,    13,    14,    47,    16,     1,     1,    42,   187,    33,
    34,    40,    36,     8,     9,    10,    40,     1,    42,    46,
   199,     9,    10,    47,     8,     9,    10,     7,     1,    24,
    29,    30,    31,    32,    46,     8,     9,    10,    33,    34,
    24,    36,    27,    28,     4,    40,     1,   109,   110,    33,
    34,    24,    36,     8,     9,    10,    40,     1,    35,    36,
    33,    34,     0,    36,     8,     9,    10,    40,     1,    24,
   111,   112,   113,   114,     0,     8,     9,    10,    33,    34,
    24,    36,   115,   116,    12,    40,     1,    79,   197,    33,
    34,    24,    36,     8,     9,    10,    40,     1,    49,   107,
    33,    34,   108,    36,     8,     9,    10,    40,     1,    24,
    -1,    -1,    -1,    -1,    -1,     8,     9,    10,    33,    34,
    24,    36,    -1,    -1,    -1,    40,     1,    -1,    -1,    33,
    34,    24,    36,     8,     9,    10,    40,     1,    -1,    -1,
    33,    34,    -1,    36,     8,     9,    10,    40,     1,    24,
    -1,    -1,    -1,    -1,    -1,     8,     9,    10,    33,    34,
    24,    36,    -1,    -1,    -1,    40,     1,    -1,    -1,    33,
    34,    24,    36,     8,     9,    10,    40,    -1,    -1,    -1,
    33,    34,    -1,    36,     8,     9,    10,    40,    12,    24,
    -1,    15,    -1,    17,    -1,     8,     9,    10,    33,    34,
    24,    36,    -1,    -1,    -1,    40,     8,     9,    10,    33,
    34,    24,    36,    -1,    -1,    -1,    40,    -1,    42,    -1,
    33,    34,    24,    36,     8,     9,    10,    40,    41,    -1,
    -1,    33,    34,    -1,    36,    33,    34,    -1,    40,    41,
    24,    -1,    40,    -1,    42,    -1,     0,     1,    -1,    33,
    34,     1,    36,    -1,     8,     1,    40,    11,     8,    13,
    14,    11,    16,    13,    14,    11,    16,    13,    14,    -1,
    16,    18,    19,    20,    21,    22,    23
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 41 "parser.y"
{printf("mini_c - translation_unit\n");;
    break;}
case 2:
#line 44 "parser.y"
{printf("translation_unit - external_dcl\n");;
    break;}
case 3:
#line 45 "parser.y"
{printf("translation_unit - translation_unit external_dcl\n");;
    break;}
case 4:
#line 48 "parser.y"
{printf("external_dcl - function_def\n");;
    break;}
case 5:
#line 49 "parser.y"
{printf("external_dcl - declaration\n");;
    break;}
case 6:
#line 50 "parser.y"
{printf("external_dcl - TIDENT TSEMI\n");;
    break;}
case 7:
#line 51 "parser.y"
{yyerrok; printf("external_dcl - TIDENT error\n");
												ReportError(missing_semi);;
    break;}
case 8:
#line 55 "parser.y"
{printf("function_def - function_header compound_st\n");;
    break;}
case 9:
#line 56 "parser.y"
{yyerrok; printf("function_def - function_header error\n");
												ReportError(missing_semi);;
    break;}
case 10:
#line 58 "parser.y"
{printf("function_def - function_header TSEMI\n");;
    break;}
case 11:
#line 59 "parser.y"
{yyerrok; printf("function_def - error compound_st");
												ReportError(missing_funcheader);;
    break;}
case 12:
#line 63 "parser.y"
{printf("function_header - dcl_spec function_name formal_param\n");;
    break;}
case 13:
#line 66 "parser.y"
{printf("dcl_spec - dcl_specifiers\n");;
    break;}
case 14:
#line 69 "parser.y"
{printf("dcl_specifiers - dcl_specifier\n");;
    break;}
case 15:
#line 70 "parser.y"
{printf("dcl_specifiers - dcl_specifiers dcl_specifier\n");;
    break;}
case 16:
#line 73 "parser.y"
{printf("dcl_specifier - type_qualifier\n");;
    break;}
case 17:
#line 74 "parser.y"
{printf("dcl_specifier - type_specifier\n");;
    break;}
case 18:
#line 77 "parser.y"
{con = 1; printf("type_qualifier - TCONST\n");;
    break;}
case 19:
#line 80 "parser.y"
{type = INT; printf("type_specifier - TINT\n");;
    break;}
case 20:
#line 81 "parser.y"
{type = VOID; printf("type_specifier - TVOID\n");;
    break;}
case 21:
#line 82 "parser.y"
{type = FLOAT; printf("type_specifier - TFLOAT\n");;
    break;}
case 22:
#line 85 "parser.y"
{printf("function_name - TIDENT\n");
												func = 1;
												changeHSTable();
												func = 0;
												con = 0;
												param = 0;
												array = 0;
												type = NONE;;
    break;}
case 23:
#line 95 "parser.y"
{printf("formal_param - TLPAREN opt_formal_param TRPAREN\n");;
    break;}
case 24:
#line 96 "parser.y"
{yyerrok; printf("formal_param - TLPAREN opt_formal_param error\n");
												ReportError(missing_rparen);;
    break;}
case 25:
#line 100 "parser.y"
{printf("opt_formal_param - formal_param_list\n");
												param = 1;
												changeHSTable();
												func = 0;
												con = 0;
												param = 0;
												array = 0;
												type = NONE;;
    break;}
case 26:
#line 108 "parser.y"
{param = 0;;
    break;}
case 27:
#line 111 "parser.y"
{printf("formal_param_list - param_dcl\n"); param = 1;
												changeHSTable();;
    break;}
case 28:
#line 113 "parser.y"
{printf("formal_param_list - formal_param_list TCOMMA param_dcl\n");;
    break;}
case 29:
#line 114 "parser.y"
{yyerrok; printf("formal_param_list - formal_param_list TCOMMA error\n");
												ReportError(missing_comma);;
    break;}
case 30:
#line 116 "parser.y"
{yyerrok; printf("formal_param_list - formal_param_list param_dcl\n");
												ReportError(missing_comma);;
    break;}
case 31:
#line 120 "parser.y"
{param = 1; printf("param_dcl - dcl_spec declarator\n");
												changeHSTable();;
    break;}
case 32:
#line 124 "parser.y"
{printf("compound_st - TLCURLY opt_dcl_list opt_stat_list TRCURLY\n");;
    break;}
case 33:
#line 125 "parser.y"
{yyerrok; printf("compound_st - TLCURLY opt_dcl_list opt_stat_list error\n");
												ReportError(missing_rcurly);;
    break;}
case 34:
#line 129 "parser.y"
{printf("opt_dcl_list - declaration_list\n");;
    break;}
case 35:
#line 130 "parser.y"
{printf("opt_dcl_list - \n");;
    break;}
case 36:
#line 133 "parser.y"
{printf("declaration_list - declaration\n");;
    break;}
case 37:
#line 134 "parser.y"
{printf("declaration_list - declaration_list declaration\n");;
    break;}
case 38:
#line 140 "parser.y"
{	printf("declaration - dcl_spec init_dcl_list TSEMI\n");
						con = 0;
						func =0;
						param = 0;
						array = 0;
						type = NONE;
					;
    break;}
case 39:
#line 148 "parser.y"
{yyerrok; printf("declaration - dcl_spec init_dcl_list error\n");
					con = 0;
					func =0;
					param = 0;
					array = 0;
					type = NONE;
					ReportError(missing_semi);;
    break;}
case 40:
#line 157 "parser.y"
{printf("init_dcl_list - init_declarator\n");;
    break;}
case 41:
#line 158 "parser.y"
{printf("init_dcl_list - init_dcl_list TCOMMA init_declarator\n");;
    break;}
case 42:
#line 159 "parser.y"
{yyerrok; printf("init_dcl_list - init_dcl_list init_declarator\n"); 
															ReportError(missing_comma); current_id -> error =1;;
    break;}
case 43:
#line 163 "parser.y"
{printf("init_declarator - declarator\n");;
    break;}
case 44:
#line 164 "parser.y"
{printf("init_declarator - declarator TASSIGN TNUMBER\n");;
    break;}
case 45:
#line 165 "parser.y"
{yyerrok; printf("init_declarator - declarator TEQUAL TNUMBER\n");
													ReportError(declaring_err);;
    break;}
case 46:
#line 167 "parser.y"
{printf("init_declarator - declarator TASSIGN TREAL\n");;
    break;}
case 47:
#line 168 "parser.y"
{yyerrok; printf("init_declarator - declarator TEQUAL TREAL\n");
															ReportError(declaring_err);;
    break;}
case 48:
#line 172 "parser.y"
{changeHSTable(); printf("declarator - TIDENT\n");;
    break;}
case 49:
#line 173 "parser.y"
{array=1; changeHSTable(); printf("declarator - TIDENT TLSQUARE opt_number TRSQUARE\n");;
    break;}
case 50:
#line 174 "parser.y"
{yyerrok; printf("declarator - TIDENT TLSQUARE opt_number error\n");
															ReportError(missing_rsquare); ;
    break;}
case 51:
#line 178 "parser.y"
{printf("opt_number - TNUMBER\n");;
    break;}
case 52:
#line 179 "parser.y"
{printf("opt_number - \n");;
    break;}
case 53:
#line 182 "parser.y"
{printf("opt_stat_list - statement_list OPT_STAT_LIST\n");;
    break;}
case 54:
#line 183 "parser.y"
{printf("opt_stat_list - \n");;
    break;}
case 55:
#line 186 "parser.y"
{printf("statement_list - statemen\n");;
    break;}
case 56:
#line 187 "parser.y"
{printf("statement_list - statement_list error\n");;
    break;}
case 57:
#line 188 "parser.y"
{printf("statement_list - statement_list statement\n");;
    break;}
case 58:
#line 191 "parser.y"
{printf("statement - compound_st\n");;
    break;}
case 59:
#line 192 "parser.y"
{printf("statement - expression_st\n");;
    break;}
case 60:
#line 193 "parser.y"
{printf("statement - if_st\n");;
    break;}
case 61:
#line 194 "parser.y"
{printf("statement - while_st\n");;
    break;}
case 62:
#line 195 "parser.y"
{printf("statement - return_st\n");;
    break;}
case 63:
#line 198 "parser.y"
{printf("expression_st - opt_expression TSEMI\n");;
    break;}
case 64:
#line 199 "parser.y"
{yyerrok; printf("expression_st - opt_expression TSEMI\n");
																	ReportError(missing_semi);;
    break;}
case 65:
#line 204 "parser.y"
{printf("opt_expression - expression\n");;
    break;}
case 66:
#line 205 "parser.y"
{printf("opt_expression - \n");;
    break;}
case 67:
#line 208 "parser.y"
{ printf(" if_st 				: TIF TLPAREN expression TRPAREN statement %prec LOWER_THAN_ELSE \n " );;
    break;}
case 68:
#line 209 "parser.y"
{ printf(" if_st | TIF TLPAREN expression TRPAREN statement TELSE statement	\n " );;
    break;}
case 69:
#line 210 "parser.y"
{yyerrok; ReportError(missing_rparen);	printf("if_st | TIF TLPAREN expression error	\n" );;
    break;}
case 70:
#line 211 "parser.y"
{yyerrok; ReportError(missing_condition);	printf("if_st | TIF TLPAREN TRPAREN error	\n" );;
    break;}
case 71:
#line 212 "parser.y"
{yyerrok; ReportError(missing_lparen);	printf("if_st | TIF error  \n" );;
    break;}
case 72:
#line 215 "parser.y"
{printf("while_st 			: TWHILE TLPAREN expression TRPAREN TLCURLY  opt_stat_list TRCURLY \n" );;
    break;}
case 73:
#line 216 "parser.y"
{yyerrok; ReportError(missing_rcurly); printf("while_st 			| TWHILE TLPAREN expression TRPAREN TLCURLY  opt_stat_list error  \n" );;
    break;}
case 74:
#line 217 "parser.y"
{yyerrok; ReportError(missing_rparen); printf("while_st 			| TWHILE TLPAREN expression error	 \n" );;
    break;}
case 75:
#line 218 "parser.y"
{yyerrok; ReportError(missing_condition);printf("while_st 			| TWHILE TLPAREN TRPAREN error \n" );;
    break;}
case 76:
#line 219 "parser.y"
{yyerrok; ReportError(missing_lparen);printf("while_st 			| TWHILE error   \n" );;
    break;}
case 77:
#line 222 "parser.y"
{printf("return_st 			: TRETURN opt_expression TSEMI \n" );;
    break;}
case 78:
#line 223 "parser.y"
{yyerrok; ReportError(missing_semi); 	printf("return_st  | TRETURN opt_expression error\n" );;
    break;}
case 79:
#line 226 "parser.y"
{printf(" \n" );;
    break;}
case 80:
#line 228 "parser.y"
{printf("assignment_exp 		: logical_or_exp	 \n " );;
    break;}
case 81:
#line 229 "parser.y"
{printf("assignment_exp 		:unary_exp TASSIGN assignment_exp  \n" );;
    break;}
case 82:
#line 230 "parser.y"
{printf("assignment_exp 		:| unary_exp TADDASSIGN assignment_exp  \n" );;
    break;}
case 83:
#line 231 "parser.y"
{printf("assignment_exp 		:| unary_exp TSUBASSIGN assignment_exp 	 \n" );;
    break;}
case 84:
#line 232 "parser.y"
{printf("assignment_exp 		: | unary_exp TMULASSIGN assignment_exp \n" );;
    break;}
case 85:
#line 233 "parser.y"
{printf("assignment_exp 		:| unary_exp TDIVASSIGN assignment_exp 	 \n" );;
    break;}
case 86:
#line 234 "parser.y"
{printf("assignment_exp 		:| unary_exp TMODASSIGN assignment_exp 	 \n" );;
    break;}
case 87:
#line 235 "parser.y"
{yyerrok; ReportError(wrong_assign);	printf("assignment_exp 		:| unary_exp TASSIGN	\n " );;
    break;}
case 88:
#line 236 "parser.y"
{yyerrok; ReportError(wrong_assign);	printf("assignment_exp 		: | | unary_exp TADDASSIGN	\n" );;
    break;}
case 89:
#line 237 "parser.y"
{yyerrok; ReportError(wrong_assign);	printf("assignment_exp 		: | unary_exp TSUBASSIGN\n" );;
    break;}
case 90:
#line 238 "parser.y"
{yyerrok; ReportError(wrong_assign);	printf("assignment_exp 		: | unary_exp TMULASSIGN\n" );;
    break;}
case 91:
#line 239 "parser.y"
{yyerrok; ReportError(wrong_assign);	printf("assignment_exp 		:| unary_exp TDIVASSIGN\n " );;
    break;}
case 92:
#line 240 "parser.y"
{yyerrok; ReportError(wrong_assign);	printf("assignment_exp 		: | unary_exp TMODASSIGN\n" );;
    break;}
case 93:
#line 243 "parser.y"
{printf("logical_or_exp 		: logical_and_exp	\n " );;
    break;}
case 94:
#line 244 "parser.y"
{printf("logical_or_exp 	| logical_or_exp TOR logical_and_exp \n " );;
    break;}
case 95:
#line 245 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("logical_or_exp | logical_or_exp TOR error			\n " );;
    break;}
case 96:
#line 248 "parser.y"
{printf("logical_and_exp		: equality_exp \n" );;
    break;}
case 97:
#line 249 "parser.y"
{printf("logical_and_exp		| logical_and_exp TAND equality_exp  \n" );;
    break;}
case 98:
#line 250 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("logical_and_exp| logical_and_exp TAND error			\n " );;
    break;}
case 99:
#line 253 "parser.y"
{printf("equality_exp 		: relational_exp	 \n" );;
    break;}
case 100:
#line 254 "parser.y"
{printf("equality_exp 		: | equality_exp TEQUAL relational_exp\n " );;
    break;}
case 101:
#line 255 "parser.y"
{printf("equality_exp 		:| equality_exp TNOTEQU relational_exp 	\n " );;
    break;}
case 102:
#line 256 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("equality_exp 		: equality_exp TEQUAL error	\n " );;
    break;}
case 103:
#line 257 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("equality_exp 		:| equality_exp TNOTEQU error	\n " );;
    break;}
case 104:
#line 260 "parser.y"
{printf(" relational_exp 		: additive_exp  \n" );;
    break;}
case 105:
#line 261 "parser.y"
{printf("relational_exp 		| relational_exp TGREAT additive_exp   \n" );;
    break;}
case 106:
#line 262 "parser.y"
{printf("relational_exp 	| relational_exp TLESS additive_exp 	 \n " );;
    break;}
case 107:
#line 263 "parser.y"
{printf("relational_exp 	| relational_exp TGREATEQU additive_exp \n " );;
    break;}
case 108:
#line 264 "parser.y"
{printf(" relational_exp 	| relational_exp TLESSEQU additive_exp 	 \n" );;
    break;}
case 109:
#line 265 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("relational_exp 	| relational_exp TGREAT error \n	 " );;
    break;}
case 110:
#line 266 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("relational_exp 	| relational_exp TLESS  error \n " );;
    break;}
case 111:
#line 267 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("relational_exp 	| relational_exp TGREATEQU error	 \n " );;
    break;}
case 112:
#line 268 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("relational_exp | relational_exp TLESSEQU error	 \n " );;
    break;}
case 113:
#line 271 "parser.y"
{printf("additive_exp 		: multiplicative_exp  \n" );;
    break;}
case 114:
#line 272 "parser.y"
{printf(" additive_exp | additive_exp TADD multiplicative_exp 	 \n" );;
    break;}
case 115:
#line 273 "parser.y"
{printf(" additive_exp| additive_exp TSUB multiplicative_exp 	 \n " );;
    break;}
case 116:
#line 274 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("additive_exp | additive_exp TADD error \n " );;
    break;}
case 117:
#line 275 "parser.y"
{yyerrok; ReportError(missing_operand);	printf(" additive_exp | additive_exp TSUB error \n" );;
    break;}
case 118:
#line 278 "parser.y"
{printf("multiplicative_exp  : unary_exp	\n " );;
    break;}
case 119:
#line 279 "parser.y"
{printf("multiplicative_exp  multiplicative_exp TMUL unary_exp  \n " );;
    break;}
case 120:
#line 280 "parser.y"
{printf("multiplicative_exp   multiplicative_exp TDIV unary_exp  \n" );;
    break;}
case 121:
#line 281 "parser.y"
{printf("multiplicative_exp | multiplicative_exp TMOD unary_exp 	 \n " );;
    break;}
case 122:
#line 282 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("multiplicative_exp	| multiplicative_exp TMUL error   \n" );;
    break;}
case 123:
#line 283 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("multiplicative_exp 	| multiplicative_exp TDIV error  \n" );;
    break;}
case 124:
#line 284 "parser.y"
{yyerrok; ReportError(missing_operand);	printf("multiplicative_exp | multiplicative_exp TMOD error \n " );;
    break;}
case 125:
#line 287 "parser.y"
{printf("unary_exp 		: postfix_exp \n" );;
    break;}
case 126:
#line 288 "parser.y"
{printf("unary_exp 	| TSUB unary_exp	\n " );;
    break;}
case 127:
#line 289 "parser.y"
{printf("unary_exp 		| TNOT unary_exp		  " );;
    break;}
case 128:
#line 290 "parser.y"
{printf("unary_exp 		| TINC unary_exp	 \n" );;
    break;}
case 129:
#line 291 "parser.y"
{printf(" unary_exp		| TDEC unary_exp	 	" );;
    break;}
case 130:
#line 294 "parser.y"
{printf("postfix_exp 		: primary_exp			 \n" );;
    break;}
case 131:
#line 295 "parser.y"
{printf("postfix_exp 		| postfix_exp TLCURLY expression TRCURLY			 \n" );;
    break;}
case 132:
#line 296 "parser.y"
{yyerrok; ReportError(missing_rcurly);	printf("postfix_exp 		| postfix_exp TLCURLY expression error	\n " );;
    break;}
case 133:
#line 297 "parser.y"
{printf("postfix_exp 		| postfix_exp TLPAREN opt_actual_param TRPAREN			\n " );;
    break;}
case 134:
#line 298 "parser.y"
{yyerrok; ReportError(missing_rparen);	printf(" postfix_exp | postfix_exp TLPAREN opt_actual_param error\n" );;
    break;}
case 135:
#line 299 "parser.y"
{printf("postfix_exp 		: p| postfix_exp TINC			\n " );;
    break;}
case 136:
#line 300 "parser.y"
{printf("postfix_exp 		| postfix_exp TDEC			\n " );;
    break;}
case 137:
#line 303 "parser.y"
{printf(" opt_actual_param 	: actual_param	 \n");;
    break;}
case 138:
#line 305 "parser.y"
{printf("actual_param 		: actual_param_list;  \n");;
    break;}
case 139:
#line 307 "parser.y"
{printf(" actual_param_list 	: assignment_exp		 \n");	;
    break;}
case 140:
#line 308 "parser.y"
{printf(" actual_param_list | actual_param_list TCOMMA assignment_exp 	\n");	;
    break;}
case 141:
#line 312 "parser.y"
{con = 0;
				func =0;
				param = 0;
				array = 0;
				type = NONE; ;
    break;}
case 142:
#line 316 "parser.y"
{printf(" primary_exp 		: TIDENT \n");	;
    break;}
case 143:
#line 317 "parser.y"
{printf("  primary_exp 		: | TNUMBER	\n");;
    break;}
case 144:
#line 318 "parser.y"
{printf(" primary_exp 		:  | TREAL\n");	;
    break;}
case 145:
#line 319 "parser.y"
{printf(" primary_exp 		: | TLPAREN expression TRPAREN	 \n");	;
    break;}
case 146:
#line 320 "parser.y"
{yyerrok; ReportError(missing_rparen);	printf(" primary_exp 		:| TLPAREN expression error " );;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 322 "parser.y"

// changeHSTable : 해시테이블 설정 함수

void changeHSTable(){
	current_id->isConst= con;
	current_id->isFunction= func;
	current_id->isParam= param;
	current_id->isArray= array;
	current_id->spec= type;
}
