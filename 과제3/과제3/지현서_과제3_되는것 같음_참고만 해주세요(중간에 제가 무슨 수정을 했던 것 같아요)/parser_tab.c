
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

#line 4 "parser.y"

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



#define	YYFINAL		216
#define	YYFLAG		-32768
#define	YYNTBASE	48

#define YYTRANSLATE(x) ((unsigned)(x) <= 302 ? yytranslate[x] : 95)

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
   109,   113,   116,   118,   122,   126,   130,   134,   140,   146,
   148,   152,   154,   156,   158,   163,   168,   170,   171,   174,
   175,   177,   180,   183,   185,   187,   189,   191,   193,   196,
   199,   201,   202,   208,   216,   221,   226,   229,   237,   245,
   250,   255,   258,   262,   266,   268,   270,   274,   278,   282,
   286,   290,   294,   297,   300,   303,   306,   309,   312,   314,
   318,   322,   324,   328,   332,   334,   338,   342,   346,   350,
   352,   356,   360,   364,   368,   372,   376,   380,   384,   386,
   390,   394,   398,   402,   404,   408,   412,   416,   420,   424,
   428,   430,   433,   436,   439,   442,   444,   449,   454,   459,
   464,   467,   470,   472,   474,   476,   480,   482,   484,   486,
   490
};

static const short yyrhs[] = {    49,
     0,    50,     0,    49,    50,     0,    51,     0,    66,     0,
     8,    47,     0,     8,     1,     0,    52,    63,     0,    52,
     1,     0,    52,    47,     0,     1,    63,     0,    53,    58,
    59,     0,    54,     0,    55,     0,    54,    55,     0,    56,
     0,    57,     0,    11,     0,    13,     0,    16,     0,    14,
     0,     8,     0,    40,    60,    41,     0,    40,    60,     1,
     0,    61,     0,     0,    62,     0,    61,    46,    62,     0,
    61,    46,     1,     0,    61,    62,     0,    53,    71,     0,
    42,    64,    73,    43,     0,    42,    64,    73,     1,     0,
    65,     0,     0,    66,     0,    65,    66,     0,    53,    67,
    47,     0,    53,    67,     1,     0,    68,     0,    67,    46,
    68,     0,    67,    68,     0,    71,     0,    71,    18,     9,
     0,    71,    27,     9,     0,    71,    18,    10,     0,    71,
    27,    10,     0,    71,    18,    42,    69,    43,     0,    71,
    27,    42,    69,    43,     0,    70,     0,    69,    46,    70,
     0,     9,     0,    10,     0,     8,     0,     8,    44,    72,
    45,     0,     8,    44,    72,     1,     0,     9,     0,     0,
    74,     6,     0,     0,    75,     0,    74,     1,     0,    74,
    75,     0,    63,     0,    76,     0,    78,     0,    79,     0,
    80,     0,    77,    47,     0,    81,     1,     0,    81,     0,
     0,    12,    40,    81,    41,    75,     0,    12,    40,    81,
    41,    75,     4,    75,     0,    12,    40,    81,     1,     0,
    12,    40,    41,     1,     0,    12,     1,     0,    17,    40,
    81,    41,    42,    73,    43,     0,    17,    40,    81,    41,
    42,    73,     1,     0,    17,    40,    81,     1,     0,    17,
    40,    41,     1,     0,    17,     1,     0,    15,    77,    47,
     0,    15,    77,     1,     0,    82,     0,    83,     0,    89,
    18,    82,     0,    89,    19,    82,     0,    89,    20,    82,
     0,    89,    21,    82,     0,    89,    22,    82,     0,    89,
    23,    82,     0,    89,    18,     0,    89,    19,     0,    89,
    20,     0,    89,    21,     0,    89,    22,     0,    89,    23,
     0,    84,     0,    83,    26,    84,     0,    83,    26,     1,
     0,    85,     0,    84,    25,    85,     0,    84,    25,     1,
     0,    86,     0,    85,    27,    86,     0,    85,    28,    86,
     0,    85,    27,     1,     0,    85,    28,     1,     0,    87,
     0,    86,    30,    87,     0,    86,    29,    87,     0,    86,
    32,    87,     0,    86,    31,    87,     0,    86,    30,     1,
     0,    86,    29,     1,     0,    86,    32,     1,     0,    86,
    31,     1,     0,    88,     0,    87,    35,    88,     0,    87,
    36,    88,     0,    87,    35,     1,     0,    87,    36,     1,
     0,    89,     0,    88,    37,    89,     0,    88,    38,    89,
     0,    88,    39,    89,     0,    88,    37,     1,     0,    88,
    38,     1,     0,    88,    39,     1,     0,    90,     0,    36,
    89,     0,    24,    89,     0,    33,    89,     0,    34,    89,
     0,    94,     0,    90,    42,    81,    43,     0,    90,    42,
    81,     1,     0,    90,    40,    91,    41,     0,    90,    40,
    91,     1,     0,    90,    33,     0,    90,    34,     0,    92,
     0,    93,     0,    82,     0,    93,    46,    82,     0,     8,
     0,     9,     0,    10,     0,    40,    81,    41,     0,    40,
    81,     1,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    39,    42,    43,    46,    47,    48,    49,    53,    54,    56,
    57,    61,    64,    67,    68,    71,    72,    75,    78,    79,
    80,    83,    92,    93,    97,   104,   107,   109,   110,   112,
   116,   120,   121,   125,   126,   129,   130,   135,   143,   153,
   154,   155,   158,   159,   160,   161,   162,   164,   165,   169,
   170,   173,   174,   177,   178,   179,   182,   183,   186,   187,
   190,   191,   192,   195,   196,   197,   198,   199,   202,   203,
   207,   208,   211,   212,   213,   214,   215,   218,   219,   220,
   221,   222,   225,   226,   229,   231,   232,   233,   234,   235,
   236,   237,   238,   239,   240,   241,   242,   243,   246,   247,
   248,   251,   252,   253,   256,   257,   258,   259,   260,   263,
   264,   265,   266,   267,   268,   269,   270,   271,   274,   275,
   276,   277,   278,   281,   282,   283,   284,   285,   286,   287,
   290,   291,   292,   293,   294,   297,   298,   299,   300,   301,
   302,   303,   306,   308,   310,   311,   314,   320,   321,   322,
   323
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
"init_declarator","init_list","initializer","declarator","opt_number","opt_stat_list",
"statement_list","statement","expression_st","opt_expression","if_st","while_st",
"return_st","expression","assignment_exp","logical_or_exp","logical_and_exp",
"equality_exp","relational_exp","additive_exp","multiplicative_exp","unary_exp",
"postfix_exp","opt_actual_param","actual_param","actual_param_list","primary_exp",
""
};
#endif

static const short yyr1[] = {     0,
    48,    49,    49,    50,    50,    50,    50,    51,    51,    51,
    51,    52,    53,    54,    54,    55,    55,    56,    57,    57,
    57,    58,    59,    59,    60,    60,    61,    61,    61,    61,
    62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
    67,    67,    68,    68,    68,    68,    68,    68,    68,    69,
    69,    70,    70,    71,    71,    71,    72,    72,    73,    73,
    74,    74,    74,    75,    75,    75,    75,    75,    76,    76,
    77,    77,    78,    78,    78,    78,    78,    79,    79,    79,
    79,    79,    80,    80,    81,    82,    82,    82,    82,    82,
    82,    82,    82,    82,    82,    82,    82,    82,    83,    83,
    83,    84,    84,    84,    85,    85,    85,    85,    85,    86,
    86,    86,    86,    86,    86,    86,    86,    86,    87,    87,
    87,    87,    87,    88,    88,    88,    88,    88,    88,    88,
    89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
    90,    90,    91,    92,    93,    93,    94,    94,    94,    94,
    94
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     2,     3,     1,     1,     2,     1,     1,     1,     1,     1,
     1,     1,     3,     3,     1,     0,     1,     3,     3,     2,
     2,     4,     4,     1,     0,     1,     2,     3,     3,     1,
     3,     2,     1,     3,     3,     3,     3,     5,     5,     1,
     3,     1,     1,     1,     4,     4,     1,     0,     2,     0,
     1,     2,     2,     1,     1,     1,     1,     1,     2,     2,
     1,     0,     5,     7,     4,     4,     2,     7,     7,     4,
     4,     2,     3,     3,     1,     1,     3,     3,     3,     3,
     3,     3,     2,     2,     2,     2,     2,     2,     1,     3,
     3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
     3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
     3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
     1,     2,     2,     2,     2,     1,     4,     4,     4,     4,
     2,     2,     1,     1,     1,     3,     1,     1,     1,     3,
     3
};

static const short yydefact[] = {     0,
     0,     0,    18,    19,    21,    20,     0,     2,     4,     0,
     0,    13,    14,    16,    17,     5,    35,    11,     7,     6,
     3,     9,    10,     8,    54,     0,     0,    40,    43,    15,
     0,    60,    34,    36,    58,    26,    12,    39,    54,     0,
    38,    42,     0,     0,   147,   148,   149,     0,    72,     0,
     0,     0,     0,     0,     0,    64,     0,     0,    61,    65,
     0,    66,    67,    68,     0,    85,    86,    99,   102,   105,
   110,   119,   124,   131,   136,    37,    57,     0,     0,     0,
    25,    27,    41,    44,    46,     0,    45,    47,     0,    77,
     0,     0,    71,    82,     0,   133,   134,   135,   132,     0,
    33,    32,    62,    59,    63,    69,    70,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    93,    94,    95,    96,    97,    98,   141,   142,     0,     0,
    56,    55,    31,    24,    23,     0,    30,    52,    53,     0,
    50,     0,     0,     0,    84,    83,     0,     0,   151,   150,
   101,   100,   124,   104,   103,   108,   106,   109,   107,   116,
   112,   115,   111,   118,   114,   117,   113,   122,   120,   123,
   121,   128,   125,   129,   126,   130,   127,    87,    88,    89,
    90,    91,    92,   145,     0,   143,   144,     0,    29,    28,
    48,     0,    49,    76,    75,    72,    81,    80,     0,   140,
   139,     0,   138,   137,    51,    73,    60,   146,    72,     0,
    74,    79,    78,     0,     0,     0
};

static const short yydefgoto[] = {   214,
     7,     8,     9,    10,    79,    12,    13,    14,    15,    26,
    37,    80,    81,    82,    56,    32,    33,    16,    27,    28,
   140,   141,    29,    78,    57,    58,    59,    60,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,   185,   186,   187,    75
};

static const short yypact[] = {   419,
     2,    15,-32768,-32768,-32768,-32768,   415,-32768,-32768,    13,
    57,   216,-32768,-32768,-32768,-32768,   216,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,     1,     6,    11,-32768,    60,-32768,
    77,    94,   216,-32768,    62,   216,-32768,-32768,    76,    77,
-32768,-32768,    63,    65,-32768,-32768,-32768,    26,   385,    41,
   385,   385,   385,   385,   385,-32768,     9,    14,-32768,-32768,
    82,-32768,-32768,-32768,    17,-32768,   126,   114,   104,   232,
   137,    87,   141,   322,-32768,-32768,-32768,    24,    77,    10,
    99,-32768,-32768,-32768,-32768,   176,-32768,-32768,   176,-32768,
   350,    20,-32768,-32768,   372,-32768,-32768,-32768,-32768,    35,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   113,   134,   147,
   168,   181,   202,   215,   236,   249,   270,   283,   304,   317,
   385,   385,   385,   385,   385,   385,-32768,-32768,   385,   385,
-32768,-32768,-32768,-32768,-32768,   183,-32768,-32768,-32768,    40,
-32768,    73,   164,    36,-32768,-32768,   174,    38,-32768,-32768,
-32768,   114,-32768,-32768,   104,-32768,   232,-32768,   232,-32768,
   137,-32768,   137,-32768,   137,-32768,   137,-32768,    87,-32768,
    87,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,    39,-32768,   108,    16,-32768,-32768,
-32768,   176,-32768,-32768,-32768,   337,-32768,-32768,   146,-32768,
-32768,   385,-32768,-32768,-32768,   175,    94,-32768,   337,    27,
-32768,-32768,-32768,   193,   195,-32768
};

static const short yypgoto[] = {-32768,
-32768,   191,-32768,-32768,   133,-32768,   188,-32768,-32768,-32768,
-32768,-32768,-32768,   -73,   107,-32768,-32768,    51,-32768,     3,
   120,    21,   143,-32768,    33,-32768,   -58,-32768,   171,-32768,
-32768,-32768,   -42,  -120,-32768,   123,   119,    96,   153,   102,
   -19,-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		435


static const short yytable[] = {   105,
   178,   179,   180,   181,   182,   183,    93,   137,   184,   101,
   134,    38,   100,    22,   103,    19,   203,   107,    39,   104,
   145,    45,    46,    47,   131,    48,    90,   212,    49,    42,
    50,    96,    97,    98,    99,   149,   195,    51,   198,   200,
   -22,    94,    83,    17,    35,    36,    52,    53,   144,    54,
   135,   102,   148,    55,    17,    17,    40,    41,   204,    23,
   -72,    20,   190,   -71,    25,    91,   146,    34,   132,   213,
    77,    84,    85,    87,    88,   150,   196,    43,   199,   201,
    95,   208,   191,    76,    39,   192,    44,   188,   153,   153,
   153,   153,   153,   153,   153,   153,   153,   153,   173,   175,
   177,    45,    46,    47,    86,    48,    89,    18,    49,     3,
    50,     4,     5,   151,     6,   193,    24,    51,   192,    35,
    45,    46,    47,   118,   119,   120,    52,    53,   106,    54,
   110,   111,    11,    55,   154,    17,    51,   206,   109,    11,
   -72,    45,    46,    47,   136,    52,    53,   156,    54,    31,
   211,   108,    55,   202,    45,    46,    47,    51,   121,   122,
   123,   124,   125,   126,   194,    31,    52,    53,   158,    54,
    51,   116,   117,    55,   197,    45,    46,    47,   209,    52,
    53,   160,    54,   189,   138,   139,    55,   207,    45,    46,
    47,    51,   215,     3,   216,     4,     5,    21,     6,    30,
    52,    53,   162,    54,    51,   157,   159,    55,   142,    45,
    46,    47,   205,    52,    53,   164,    54,   169,   171,    92,
    55,   133,    45,    46,    47,    51,     3,   155,     4,     5,
   152,     6,     0,     0,    52,    53,   166,    54,    51,   210,
     0,    55,     0,    45,    46,    47,     0,    52,    53,   168,
    54,     0,     0,     0,    55,     0,    45,    46,    47,    51,
   112,   113,   114,   115,   161,   163,   165,   167,    52,    53,
   170,    54,    51,     0,     0,    55,     0,    45,    46,    47,
     0,    52,    53,   172,    54,     0,     0,     0,    55,     0,
    45,    46,    47,    51,     0,     0,     0,     0,     0,     0,
     0,     0,    52,    53,   174,    54,    51,     0,     0,    55,
     0,    45,    46,    47,     0,    52,    53,   176,    54,     0,
     0,     0,    55,     0,    45,    46,    47,    51,     0,     0,
     0,     0,     0,     0,     0,     0,    52,    53,     0,    54,
    51,     0,     0,    55,    45,    46,    47,     0,    48,    52,
    53,    49,    54,    50,   127,   128,    55,    45,    46,    47,
    51,   129,     0,   130,     0,     0,     0,     0,     0,    52,
    53,     0,    54,    51,     0,     0,    55,     0,    17,    45,
    46,    47,    52,    53,     0,    54,     0,     0,     0,    55,
   143,     0,    45,    46,    47,    51,     0,     0,     0,     0,
     0,     0,     0,     0,    52,    53,     0,    54,    51,     0,
     0,    55,   147,     0,    -1,     1,     0,    52,    53,     1,
    54,     0,     2,     0,    55,     3,     2,     4,     5,     3,
     6,     4,     5,     0,     6
};

static const short yycheck[] = {    58,
   121,   122,   123,   124,   125,   126,    49,    81,   129,     1,
     1,     1,    55,     1,     1,     1,     1,     1,     8,     6,
     1,     8,     9,    10,     1,    12,     1,     1,    15,    27,
    17,    51,    52,    53,    54,     1,     1,    24,     1,     1,
    40,     1,    40,    42,    44,    40,    33,    34,    91,    36,
    41,    43,    95,    40,    42,    42,    46,    47,    43,    47,
    47,    47,   136,    47,     8,    40,    47,    17,    45,    43,
     9,     9,    10,     9,    10,    41,    41,    18,    41,    41,
    40,   202,    43,    33,     8,    46,    27,   130,   108,   109,
   110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
   120,     8,     9,    10,    42,    12,    42,     1,    15,    11,
    17,    13,    14,     1,    16,    43,    10,    24,    46,    44,
     8,     9,    10,    37,    38,    39,    33,    34,    47,    36,
    27,    28,     0,    40,     1,    42,    24,   196,    25,     7,
    47,     8,     9,    10,    46,    33,    34,     1,    36,    17,
   209,    26,    40,    46,     8,     9,    10,    24,    18,    19,
    20,    21,    22,    23,     1,    33,    33,    34,     1,    36,
    24,    35,    36,    40,     1,     8,     9,    10,     4,    33,
    34,     1,    36,     1,     9,    10,    40,    42,     8,     9,
    10,    24,     0,    11,     0,    13,    14,     7,    16,    12,
    33,    34,     1,    36,    24,   110,   111,    40,    89,     8,
     9,    10,   192,    33,    34,     1,    36,   116,   117,    49,
    40,    79,     8,     9,    10,    24,    11,   109,    13,    14,
   108,    16,    -1,    -1,    33,    34,     1,    36,    24,   207,
    -1,    40,    -1,     8,     9,    10,    -1,    33,    34,     1,
    36,    -1,    -1,    -1,    40,    -1,     8,     9,    10,    24,
    29,    30,    31,    32,   112,   113,   114,   115,    33,    34,
     1,    36,    24,    -1,    -1,    40,    -1,     8,     9,    10,
    -1,    33,    34,     1,    36,    -1,    -1,    -1,    40,    -1,
     8,     9,    10,    24,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    33,    34,     1,    36,    24,    -1,    -1,    40,
    -1,     8,     9,    10,    -1,    33,    34,     1,    36,    -1,
    -1,    -1,    40,    -1,     8,     9,    10,    24,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
    24,    -1,    -1,    40,     8,     9,    10,    -1,    12,    33,
    34,    15,    36,    17,    33,    34,    40,     8,     9,    10,
    24,    40,    -1,    42,    -1,    -1,    -1,    -1,    -1,    33,
    34,    -1,    36,    24,    -1,    -1,    40,    -1,    42,     8,
     9,    10,    33,    34,    -1,    36,    -1,    -1,    -1,    40,
    41,    -1,     8,     9,    10,    24,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    24,    -1,
    -1,    40,    41,    -1,     0,     1,    -1,    33,    34,     1,
    36,    -1,     8,    -1,    40,    11,     8,    13,    14,    11,
    16,    13,    14,    -1,    16
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

case 7:
#line 49 "parser.y"
{yyerrok;
												ReportError(missing_semi);;
    break;}
case 9:
#line 54 "parser.y"
{yyerrok;
												ReportError(missing_semi);;
    break;}
case 11:
#line 57 "parser.y"
{yyerrok;
												ReportError(missing_funcheader);;
    break;}
case 18:
#line 75 "parser.y"
{con = 1;;
    break;}
case 19:
#line 78 "parser.y"
{type = INT;;
    break;}
case 20:
#line 79 "parser.y"
{type = VOID;;
    break;}
case 21:
#line 80 "parser.y"
{type = FLOAT;;
    break;}
case 22:
#line 83 "parser.y"
{func = 1;
												changeHSTable();
												func = 0;
												con = 0;
												param = 0;
												array = 0;
												type = NONE;;
    break;}
case 24:
#line 93 "parser.y"
{yyerrok;
												ReportError(missing_rparen);;
    break;}
case 25:
#line 97 "parser.y"
{param = 1;
												changeHSTable();
												func = 0;
												con = 0;
												param = 0;
												array = 0;
												type = NONE;;
    break;}
case 26:
#line 104 "parser.y"
{param = 0;;
    break;}
case 27:
#line 107 "parser.y"
{param = 1;
												changeHSTable();;
    break;}
case 29:
#line 110 "parser.y"
{yyerrok;
												ReportError(missing_comma);;
    break;}
case 30:
#line 112 "parser.y"
{yyerrok;
												ReportError(missing_comma);;
    break;}
case 31:
#line 116 "parser.y"
{param = 1;
												changeHSTable();;
    break;}
case 33:
#line 121 "parser.y"
{yyerrok;
												ReportError(missing_rcurly);;
    break;}
case 38:
#line 136 "parser.y"
{
						con = 0;
						func =0;
						param = 0;
						array = 0;
						type = NONE;
					;
    break;}
case 39:
#line 144 "parser.y"
{yyerrok;
					con = 0;
					func =0;
					param = 0;
					array = 0;
					type = NONE;
					ReportError(missing_semi);;
    break;}
case 42:
#line 155 "parser.y"
{yyerrok; ReportError(missing_comma); current_id -> error =1;;
    break;}
case 45:
#line 160 "parser.y"
{yyerrok; ReportError(declaring_err);;
    break;}
case 47:
#line 162 "parser.y"
{yyerrok; ReportError(declaring_err);;
    break;}
case 49:
#line 165 "parser.y"
{yyerrok; ReportError(declaring_err);;
    break;}
case 54:
#line 177 "parser.y"
{changeHSTable(); ;
    break;}
case 55:
#line 178 "parser.y"
{array=1; changeHSTable(); ;
    break;}
case 56:
#line 179 "parser.y"
{yyerrok; ReportError(missing_rsquare); ;
    break;}
case 70:
#line 203 "parser.y"
{yyerrok; ReportError(missing_semi);;
    break;}
case 75:
#line 213 "parser.y"
{yyerrok; ReportError(missing_rparen);;
    break;}
case 76:
#line 214 "parser.y"
{yyerrok; ReportError(missing_condition);;
    break;}
case 77:
#line 215 "parser.y"
{yyerrok; ReportError(missing_lparen);;
    break;}
case 79:
#line 219 "parser.y"
{yyerrok; ReportError(missing_rcurly);;
    break;}
case 80:
#line 220 "parser.y"
{yyerrok; ReportError(missing_rparen);;
    break;}
case 81:
#line 221 "parser.y"
{yyerrok; ReportError(missing_condition);;
    break;}
case 82:
#line 222 "parser.y"
{yyerrok; ReportError(missing_lparen);;
    break;}
case 84:
#line 226 "parser.y"
{yyerrok; ReportError(missing_semi);;
    break;}
case 93:
#line 238 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 94:
#line 239 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 95:
#line 240 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 96:
#line 241 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 97:
#line 242 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 98:
#line 243 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 101:
#line 248 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 104:
#line 253 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 108:
#line 259 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 109:
#line 260 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 115:
#line 268 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 116:
#line 269 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 117:
#line 270 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 118:
#line 271 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 122:
#line 277 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 123:
#line 278 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 128:
#line 285 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 129:
#line 286 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 130:
#line 287 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 138:
#line 299 "parser.y"
{yyerrok; ReportError(missing_rcurly);;
    break;}
case 140:
#line 301 "parser.y"
{yyerrok; ReportError(missing_rparen);;
    break;}
case 147:
#line 315 "parser.y"
{con = 0;
				func =0;
				param = 0;
				array = 0;
				type = NONE;;
    break;}
case 151:
#line 323 "parser.y"
{yyerrok; ReportError(missing_rparen);;
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
#line 325 "parser.y"


// changeHSTable : 해시테이블 설정 함수

void changeHSTable(){
	current_id->isConst= con;
	current_id->isFunction= func;
	current_id->isParam= param;
	current_id->isArray= array;
	current_id->spec= type;
}
