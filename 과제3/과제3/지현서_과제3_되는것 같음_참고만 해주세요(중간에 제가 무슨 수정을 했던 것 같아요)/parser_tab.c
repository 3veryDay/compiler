
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
#define	TEIF	268
#define	TINT	269
#define	TFLOAT	270
#define	TRETURN	271
#define	TVOID	272
#define	TWHILE	273
#define	TASSIGN	274
#define	TADDASSIGN	275
#define	TSUBASSIGN	276
#define	TMULASSIGN	277
#define	TDIVASSIGN	278
#define	TMODASSIGN	279
#define	TNOT	280
#define	TAND	281
#define	TOR	282
#define	TEQUAL	283
#define	TNOTEQU	284
#define	TLESS	285
#define	TGREAT	286
#define	TLESSEQU	287
#define	TGREATEQU	288
#define	TINC	289
#define	TDEC	290
#define	TADD	291
#define	TSUB	292
#define	TMUL	293
#define	TDIV	294
#define	TMOD	295
#define	TERROR	296
#define	TLPAREN	297
#define	TRPAREN	298
#define	TLCURLY	299
#define	TRCURLY	300
#define	TLSQUARE	301
#define	TRSQUARE	302
#define	TCOMMA	303
#define	TSEMI	304

#line 14 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

/*yacc source for Mini C*/

int con = 0;
int func = 0;
int param = 0;
int array = 0;
int type = NONE;

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



#define	YYFINAL		205
#define	YYFLAG		-32768
#define	YYNTBASE	50

#define YYTRANSLATE(x) ((unsigned)(x) <= 304 ? yytranslate[x] : 96)

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
    46,    47,    48,    49
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    20,    23,
    26,    30,    32,    34,    37,    39,    41,    43,    45,    47,
    49,    51,    55,    59,    61,    62,    64,    68,    72,    75,
    78,    83,    87,    90,    92,    93,    95,    98,   102,   106,
   108,   112,   115,   117,   121,   125,   129,   133,   135,   140,
   145,   147,   148,   151,   152,   154,   157,   160,   162,   164,
   166,   168,   170,   173,   176,   178,   179,   185,   193,   198,
   203,   206,   214,   222,   227,   232,   235,   239,   243,   245,
   247,   251,   255,   259,   263,   267,   271,   274,   277,   280,
   283,   286,   289,   291,   295,   299,   301,   305,   309,   311,
   315,   319,   323,   327,   329,   333,   337,   341,   345,   349,
   353,   357,   361,   363,   367,   371,   375,   379,   381,   385,
   389,   393,   397,   401,   405,   407,   410,   413,   416,   419,
   421,   426,   431,   436,   441,   444,   447,   449,   451,   453,
   457,   459,   461,   463,   467
};

static const short yyrhs[] = {    51,
     0,    52,     0,    51,    52,     0,    53,     0,    69,     0,
     8,    49,     0,     8,     1,     0,    54,    65,     0,    54,
     1,     0,     1,    65,     0,    55,    60,    61,     0,    56,
     0,    57,     0,    56,    57,     0,    58,     0,    59,     0,
    11,     0,    14,     0,    17,     0,    15,     0,     8,     0,
    42,    62,    43,     0,    42,    62,     1,     0,    63,     0,
     0,    64,     0,    63,    48,    64,     0,    63,    48,     1,
     0,    63,    64,     0,    55,    72,     0,    44,    67,    74,
    45,     0,    44,    66,     1,     0,    67,    74,     0,    68,
     0,     0,    69,     0,    68,    69,     0,    55,    70,    49,
     0,    55,    70,     1,     0,    71,     0,    70,    48,    71,
     0,    70,    71,     0,    72,     0,    72,    19,     9,     0,
    72,    28,     9,     0,    72,    19,    10,     0,    72,    28,
    10,     0,     8,     0,     8,    46,    73,    47,     0,     8,
    46,    73,     1,     0,     9,     0,     0,    75,     6,     0,
     0,    76,     0,    75,     1,     0,    75,    76,     0,    65,
     0,    77,     0,    79,     0,    80,     0,    81,     0,    78,
    49,     0,    82,     1,     0,    82,     0,     0,    12,    42,
    82,    43,    76,     0,    12,    42,    82,    43,    76,     4,
    76,     0,    12,    42,    82,     1,     0,    12,    42,    43,
     1,     0,    12,     1,     0,    18,    42,    82,    43,    44,
    74,    45,     0,    18,    42,    82,    43,    44,    74,     1,
     0,    18,    42,    82,     1,     0,    18,    42,    43,     1,
     0,    18,     1,     0,    16,    78,    49,     0,    16,    78,
     1,     0,    83,     0,    84,     0,    90,    19,    83,     0,
    90,    20,    83,     0,    90,    21,    83,     0,    90,    22,
    83,     0,    90,    23,    83,     0,    90,    24,    83,     0,
    90,    19,     0,    90,    20,     0,    90,    21,     0,    90,
    22,     0,    90,    23,     0,    90,    24,     0,    85,     0,
    84,    27,    85,     0,    84,    27,     1,     0,    86,     0,
    85,    26,    86,     0,    85,    26,     1,     0,    87,     0,
    86,    28,    87,     0,    86,    29,    87,     0,    86,    28,
     1,     0,    86,    29,     1,     0,    88,     0,    87,    31,
    88,     0,    87,    30,    88,     0,    87,    33,    88,     0,
    87,    32,    88,     0,    87,    31,     1,     0,    87,    30,
     1,     0,    87,    33,     1,     0,    87,    32,     1,     0,
    89,     0,    88,    36,    89,     0,    88,    37,    89,     0,
    88,    36,     1,     0,    88,    37,     1,     0,    90,     0,
    89,    38,    90,     0,    89,    39,    90,     0,    89,    40,
    90,     0,    89,    38,     1,     0,    89,    39,     1,     0,
    89,    40,     1,     0,    91,     0,    37,    90,     0,    25,
    90,     0,    34,    90,     0,    35,    90,     0,    95,     0,
    91,    44,    82,    45,     0,    91,    44,    82,     1,     0,
    91,    42,    92,    43,     0,    91,    42,    92,     1,     0,
    91,    34,     0,    91,    35,     0,    93,     0,    94,     0,
    83,     0,    94,    48,    83,     0,     8,     0,     9,     0,
    10,     0,    42,    82,    43,     0,    42,    82,     1,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    49,    52,    53,    56,    57,    58,    59,    63,    64,    66,
    70,    73,    76,    77,    80,    81,    84,    87,    88,    89,
    92,   101,   102,   106,   113,   116,   118,   119,   121,   125,
   129,   130,   133,   135,   136,   139,   140,   145,   153,   163,
   164,   165,   168,   169,   170,   171,   172,   175,   176,   177,
   180,   181,   184,   185,   188,   189,   190,   193,   194,   195,
   196,   197,   200,   201,   205,   206,   209,   210,   211,   212,
   213,   216,   217,   218,   219,   220,   223,   224,   227,   230,
   231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
   241,   242,   245,   246,   247,   250,   251,   252,   255,   256,
   257,   258,   259,   267,   268,   269,   270,   271,   272,   273,
   274,   275,   278,   279,   280,   281,   282,   285,   286,   287,
   288,   289,   290,   291,   294,   295,   296,   297,   298,   301,
   302,   303,   304,   305,   306,   307,   310,   312,   314,   315,
   318,   324,   325,   326,   327
};

static const char * const yytname[] = {   "$","error","$undefined.","LOWER_THAN_ELSE",
"TELSE","LOWER_THAN_OPT_STAT_LIST","OPT_STAT_LIST","TEOF","TIDENT","TNUMBER",
"TREAL","TCONST","TIF","TEIF","TINT","TFLOAT","TRETURN","TVOID","TWHILE","TASSIGN",
"TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN","TMODASSIGN","TNOT","TAND",
"TOR","TEQUAL","TNOTEQU","TLESS","TGREAT","TLESSEQU","TGREATEQU","TINC","TDEC",
"TADD","TSUB","TMUL","TDIV","TMOD","TERROR","TLPAREN","TRPAREN","TLCURLY","TRCURLY",
"TLSQUARE","TRSQUARE","TCOMMA","TSEMI","mini_c","translation_unit","external_dcl",
"function_def","function_header","dcl_spec","dcl_specifiers","dcl_specifier",
"type_qualifier","type_specifier","function_name","formal_param","opt_formal_param",
"formal_param_list","param_dcl","compound_st","compound","opt_dcl_list","declaration_list",
"declaration","init_dcl_list","init_declarator","declarator","opt_number","opt_stat_list",
"statement_list","statement","expression_st","opt_expression","if_st","while_st",
"return_st","expression","assignment_exp","logical_or_exp","logical_and_exp",
"equality_exp","relational_exp","additive_exp","multiplicative_exp","unary_exp",
"postfix_exp","opt_actual_param","actual_param","actual_param_list","primary_exp",
""
};
#endif

static const short yyr1[] = {     0,
    50,    51,    51,    52,    52,    52,    52,    53,    53,    53,
    54,    55,    56,    56,    57,    57,    58,    59,    59,    59,
    60,    61,    61,    62,    62,    63,    63,    63,    63,    64,
    65,    65,    66,    67,    67,    68,    68,    69,    69,    70,
    70,    70,    71,    71,    71,    71,    71,    72,    72,    72,
    73,    73,    74,    74,    75,    75,    75,    76,    76,    76,
    76,    76,    77,    77,    78,    78,    79,    79,    79,    79,
    79,    80,    80,    80,    80,    80,    81,    81,    82,    83,
    83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
    83,    83,    84,    84,    84,    85,    85,    85,    86,    86,
    86,    86,    86,    87,    87,    87,    87,    87,    87,    87,
    87,    87,    88,    88,    88,    88,    88,    89,    89,    89,
    89,    89,    89,    89,    90,    90,    90,    90,    90,    91,
    91,    91,    91,    91,    91,    91,    92,    93,    94,    94,
    95,    95,    95,    95,    95
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
     1,     3,     3,     1,     0,     1,     3,     3,     2,     2,
     4,     3,     2,     1,     0,     1,     2,     3,     3,     1,
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
     1,     1,     1,     3,     3
};

static const short yydefact[] = {     0,
     0,     0,    17,    18,    20,    19,     0,     2,     4,     0,
     0,    12,    13,    15,    16,     5,    35,    10,     7,     6,
     3,     9,     8,    48,     0,     0,    40,    43,    14,     0,
     0,    54,    34,    36,    52,    25,    11,    39,    48,     0,
    38,    42,     0,     0,    32,   141,   142,   143,     0,    66,
     0,     0,     0,     0,     0,     0,    58,    33,     0,    55,
    59,     0,    60,    61,    62,     0,    79,    80,    93,    96,
    99,   104,   113,   118,   125,   130,    37,    51,     0,     0,
     0,    24,    26,    41,    44,    46,    45,    47,    71,     0,
     0,    65,    76,     0,   127,   128,   129,   126,     0,    31,
    56,    53,    57,    63,    64,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,    87,    88,
    89,    90,    91,    92,   135,   136,     0,     0,    50,    49,
    30,    23,    22,     0,    29,     0,     0,    78,    77,     0,
     0,   145,   144,    95,    94,   118,    98,    97,   102,   100,
   103,   101,   110,   106,   109,   105,   112,   108,   111,   107,
   116,   114,   117,   115,   122,   119,   123,   120,   124,   121,
    81,    82,    83,    84,    85,    86,   139,     0,   137,   138,
     0,    28,    27,    70,    69,    66,    75,    74,     0,   134,
   133,     0,   132,   131,    67,    54,   140,    66,     0,    68,
    73,    72,     0,     0,     0
};

static const short yydefgoto[] = {   203,
     7,     8,     9,    10,    80,    12,    13,    14,    15,    25,
    37,    81,    82,    83,    57,    31,    32,    33,    16,    26,
    27,    28,    79,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
    75,   178,   179,   180,    76
};

static const short yypact[] = {   378,
   -17,     5,-32768,-32768,-32768,-32768,   373,-32768,-32768,    34,
    92,   154,-32768,-32768,-32768,-32768,   154,-32768,-32768,-32768,
-32768,-32768,-32768,     2,    88,    22,-32768,     1,-32768,   132,
   141,    94,   154,-32768,   158,   154,-32768,-32768,   134,   132,
-32768,-32768,    28,    86,-32768,-32768,-32768,-32768,    13,   343,
    52,   343,   343,   343,   343,   343,-32768,   138,    74,-32768,
-32768,   168,-32768,-32768,-32768,    23,-32768,   160,   192,   163,
   102,    78,   124,   377,    63,-32768,-32768,-32768,    27,   132,
    42,     4,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   313,
    24,-32768,-32768,   324,-32768,-32768,-32768,-32768,    45,-32768,
-32768,-32768,-32768,-32768,-32768,   112,   116,   147,   151,   165,
   169,   200,   204,   218,   222,   253,   257,   271,   343,   343,
   343,   343,   343,   343,-32768,-32768,   343,   343,-32768,-32768,
-32768,-32768,-32768,    25,-32768,   219,    46,-32768,-32768,   220,
    48,-32768,-32768,-32768,   192,-32768,-32768,   163,-32768,   102,
-32768,   102,-32768,    78,-32768,    78,-32768,    78,-32768,    78,
-32768,   124,-32768,   124,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,    50,-32768,   174,
    31,-32768,-32768,-32768,-32768,   302,-32768,-32768,   180,-32768,
-32768,   343,-32768,-32768,   229,    94,-32768,   302,    32,-32768,
-32768,-32768,   236,   240,-32768
};

static const short yypgoto[] = {-32768,
-32768,   237,-32768,-32768,   268,-32768,   233,-32768,-32768,-32768,
-32768,-32768,-32768,   -65,    21,-32768,-32768,-32768,    17,-32768,
    61,   170,-32768,    53,-32768,   -59,-32768,   198,-32768,-32768,
-32768,   -49,  -111,-32768,   145,   162,    36,    85,   101,   -50,
-32768,-32768,-32768,-32768,-32768
};


#define	YYLAST		401


static const short yytable[] = {   103,
    92,    95,    96,    97,    98,    19,    99,   171,   172,   173,
   174,   175,   176,    89,     3,   177,   135,     4,     5,    43,
     6,    18,    38,   105,   138,   182,    17,   129,    44,    39,
    23,   193,   201,    34,    22,     3,    85,    86,     4,     5,
   137,     6,   132,   -21,   141,   142,   185,    35,   188,    77,
   190,   134,    93,    20,    90,   146,   146,   146,   146,   146,
   146,   146,   146,   146,   146,   166,   168,   170,   183,    40,
    41,   -65,   139,   130,   101,   194,   202,    17,   181,   102,
   197,    46,    47,    48,   133,    49,    42,   143,   186,    50,
   189,    51,   191,    94,    87,    88,   125,   126,    52,    24,
    84,    46,    47,    48,   127,    49,   128,    53,    54,    50,
    55,    51,   144,   114,   115,    56,   147,    17,    52,    46,
    47,    48,   -66,    46,    47,    48,   195,    53,    54,    36,
    55,   110,   111,   112,   113,    56,    52,    17,   200,    39,
    52,    45,   -66,   150,   152,    53,    54,   149,    55,    53,
    54,   151,    55,    56,    46,    47,    48,    56,    46,    47,
    48,   116,   117,   118,     3,   153,    78,     4,     5,   155,
     6,    52,    46,    47,    48,    52,    46,    47,    48,    35,
    53,    54,   100,    55,    53,    54,   106,    55,    56,    52,
   108,   109,    56,    52,   154,   156,   158,   160,    53,    54,
   157,    55,    53,    54,   159,    55,    56,    46,    47,    48,
    56,    46,    47,    48,   162,   164,   104,   107,   161,   184,
   187,   192,   163,   196,    52,    46,    47,    48,    52,    46,
    47,    48,   198,    53,    54,   204,    55,    53,    54,   205,
    55,    56,    52,    21,    29,    56,    52,    91,   199,   131,
   145,    53,    54,   165,    55,    53,    54,   167,    55,    56,
    46,    47,    48,    56,    46,    47,    48,    11,   148,     0,
     0,   169,     0,     0,    11,     0,     0,    52,    46,    47,
    48,    52,     0,     0,    30,     0,    53,    54,     0,    55,
    53,    54,     0,    55,    56,    52,     0,     0,    56,     0,
    30,     0,     0,     0,    53,    54,     0,    55,     0,    46,
    47,    48,    56,    49,     0,     0,     0,    50,     0,    51,
    46,    47,    48,     0,     0,     0,    52,     0,     0,     0,
     0,    46,    47,    48,     0,    53,    54,    52,    55,     0,
     0,     0,     0,    56,     0,    17,    53,    54,    52,    55,
    46,    47,    48,     0,    56,   136,     0,    53,    54,     0,
    55,     0,     0,     0,     0,    56,   140,    52,     0,     0,
     0,     0,    -1,     1,     0,     0,    53,    54,     1,    55,
     2,     0,     0,     3,    56,     2,     4,     5,     3,     6,
     0,     4,     5,     0,     6,   119,   120,   121,   122,   123,
   124
};

static const short yycheck[] = {    59,
    50,    52,    53,    54,    55,     1,    56,   119,   120,   121,
   122,   123,   124,     1,    11,   127,    82,    14,    15,    19,
    17,     1,     1,     1,     1,     1,    44,     1,    28,     8,
    10,     1,     1,    17,     1,    11,     9,    10,    14,    15,
    90,    17,     1,    42,    94,     1,     1,    46,     1,    33,
     1,    48,     1,    49,    42,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   134,    48,
    49,    49,    49,    47,     1,    45,    45,    44,   128,     6,
   192,     8,     9,    10,    43,    12,    26,    43,    43,    16,
    43,    18,    43,    42,     9,    10,    34,    35,    25,     8,
    40,     8,     9,    10,    42,    12,    44,    34,    35,    16,
    37,    18,     1,    36,    37,    42,     1,    44,    25,     8,
     9,    10,    49,     8,     9,    10,   186,    34,    35,    42,
    37,    30,    31,    32,    33,    42,    25,    44,   198,     8,
    25,     1,    49,   108,   109,    34,    35,     1,    37,    34,
    35,     1,    37,    42,     8,     9,    10,    42,     8,     9,
    10,    38,    39,    40,    11,     1,     9,    14,    15,     1,
    17,    25,     8,     9,    10,    25,     8,     9,    10,    46,
    34,    35,    45,    37,    34,    35,    27,    37,    42,    25,
    28,    29,    42,    25,   110,   111,   112,   113,    34,    35,
     1,    37,    34,    35,     1,    37,    42,     8,     9,    10,
    42,     8,     9,    10,   114,   115,    49,    26,     1,     1,
     1,    48,     1,    44,    25,     8,     9,    10,    25,     8,
     9,    10,     4,    34,    35,     0,    37,    34,    35,     0,
    37,    42,    25,     7,    12,    42,    25,    50,   196,    80,
   106,    34,    35,     1,    37,    34,    35,     1,    37,    42,
     8,     9,    10,    42,     8,     9,    10,     0,   107,    -1,
    -1,     1,    -1,    -1,     7,    -1,    -1,    25,     8,     9,
    10,    25,    -1,    -1,    17,    -1,    34,    35,    -1,    37,
    34,    35,    -1,    37,    42,    25,    -1,    -1,    42,    -1,
    33,    -1,    -1,    -1,    34,    35,    -1,    37,    -1,     8,
     9,    10,    42,    12,    -1,    -1,    -1,    16,    -1,    18,
     8,     9,    10,    -1,    -1,    -1,    25,    -1,    -1,    -1,
    -1,     8,     9,    10,    -1,    34,    35,    25,    37,    -1,
    -1,    -1,    -1,    42,    -1,    44,    34,    35,    25,    37,
     8,     9,    10,    -1,    42,    43,    -1,    34,    35,    -1,
    37,    -1,    -1,    -1,    -1,    42,    43,    25,    -1,    -1,
    -1,    -1,     0,     1,    -1,    -1,    34,    35,     1,    37,
     8,    -1,    -1,    11,    42,     8,    14,    15,    11,    17,
    -1,    14,    15,    -1,    17,    19,    20,    21,    22,    23,
    24
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
#line 59 "parser.y"
{yyerrok;
												ReportError(missing_semi);;
    break;}
case 9:
#line 64 "parser.y"
{yyerrok;
												ReportError(missing_rcurly);;
    break;}
case 10:
#line 66 "parser.y"
{yyerrok;
												ReportError(missing_funcheader);;
    break;}
case 17:
#line 84 "parser.y"
{con = 1;;
    break;}
case 18:
#line 87 "parser.y"
{type = INT;;
    break;}
case 19:
#line 88 "parser.y"
{type = VOID;;
    break;}
case 20:
#line 89 "parser.y"
{type = FLOAT;;
    break;}
case 21:
#line 92 "parser.y"
{func = 1;
												changeHSTable();
												func = 0;
												con = 0;
												param = 0;
												array = 0;
												type = NONE;;
    break;}
case 23:
#line 102 "parser.y"
{yyerrok;
												ReportError(missing_rparen);;
    break;}
case 24:
#line 106 "parser.y"
{param = 1;
												changeHSTable();
												func = 0;
												con = 0;
												param = 0;
												array = 0;
												type = NONE;;
    break;}
case 25:
#line 113 "parser.y"
{param = 0;;
    break;}
case 26:
#line 116 "parser.y"
{param = 1;
												changeHSTable();;
    break;}
case 28:
#line 119 "parser.y"
{yyerrok;
												ReportError(missing_comma);;
    break;}
case 29:
#line 121 "parser.y"
{yyerrok;
												ReportError(missing_comma);;
    break;}
case 30:
#line 125 "parser.y"
{param = 1;
												changeHSTable();;
    break;}
case 32:
#line 130 "parser.y"
{yyerrok; ReportError(missing_rcurly);;
    break;}
case 38:
#line 146 "parser.y"
{
						con = 0;
						func =0;
						param = 0;
						array = 0;
						type = NONE;
					;
    break;}
case 39:
#line 154 "parser.y"
{yyerrok;
					con = 0;
					func =0;
					param = 0;
					array = 0;
					type = NONE;
					ReportError(missing_semi);;
    break;}
case 42:
#line 165 "parser.y"
{yyerrok; ReportError(missing_comma); current_id -> error =1;;
    break;}
case 45:
#line 170 "parser.y"
{yyerrok; ReportError(declaring_err);;
    break;}
case 47:
#line 172 "parser.y"
{yyerrok; ReportError(declaring_err);;
    break;}
case 48:
#line 175 "parser.y"
{changeHSTable(); ;
    break;}
case 49:
#line 176 "parser.y"
{array=1; changeHSTable(); ;
    break;}
case 50:
#line 177 "parser.y"
{yyerrok; ReportError(missing_rsquare); ;
    break;}
case 64:
#line 201 "parser.y"
{yyerrok; ReportError(missing_semi);;
    break;}
case 69:
#line 211 "parser.y"
{yyerrok; ReportError(missing_rparen);;
    break;}
case 70:
#line 212 "parser.y"
{yyerrok; ReportError(missing_condition);;
    break;}
case 71:
#line 213 "parser.y"
{yyerrok; ReportError(missing_lparen);;
    break;}
case 73:
#line 217 "parser.y"
{yyerrok; ReportError(missing_rcurly);;
    break;}
case 74:
#line 218 "parser.y"
{yyerrok; ReportError(missing_rparen);;
    break;}
case 75:
#line 219 "parser.y"
{yyerrok; ReportError(missing_condition);;
    break;}
case 76:
#line 220 "parser.y"
{yyerrok; ReportError(missing_lparen);;
    break;}
case 78:
#line 224 "parser.y"
{yyerrok; ReportError(missing_semi);;
    break;}
case 87:
#line 237 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 88:
#line 238 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 89:
#line 239 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 90:
#line 240 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 91:
#line 241 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 92:
#line 242 "parser.y"
{yyerrok; ReportError(wrong_assign);;
    break;}
case 95:
#line 247 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 98:
#line 252 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 102:
#line 258 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 103:
#line 259 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 109:
#line 272 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 110:
#line 273 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 111:
#line 274 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 112:
#line 275 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 116:
#line 281 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 117:
#line 282 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 122:
#line 289 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 123:
#line 290 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 124:
#line 291 "parser.y"
{yyerrok; ReportError(missing_operand);;
    break;}
case 132:
#line 303 "parser.y"
{yyerrok; ReportError(missing_rcurly);;
    break;}
case 134:
#line 305 "parser.y"
{yyerrok; ReportError(missing_rparen);;
    break;}
case 141:
#line 319 "parser.y"
{con = 0;
				func =0;
				param = 0;
				array = 0;
				type = NONE;;
    break;}
case 145:
#line 327 "parser.y"
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
#line 329 "parser.y"


void changeHSTable(){
	current_id->isConst= con;
	current_id->isFunction= func;
	current_id->isParam= param;
	current_id->isArray= array;
	current_id->spec= type;
}
