%{
/*
* scanner.l - lexical analyzer for the MiniC
* programmer - 김예지(2176082), 송채원(2076216), 신정화(2271035), 윤하영(2071033)
* date - 2024-04-29
*/
#include <stdio.h>
#include <stdlib.h>
#include "glob.h"
#include "tn.h"
%}
L [A-Za-z_]
D [0-9]
%%
"const" return(TCONST);
"else" return(TELSE);
"if" return(TIF);
"int" return(TINT);
"return" return(TRETURN);
"void" return(TVOID);
"while" return(TWHILE);
"+" return(TADD);
"-" return(TSUB);
"*" return(TMUL);
"/" return(TDIV);
"%" return(TMOD);
"=" return(TASSIGN);
"+=" return(TADDASSIGN);
"-=" return(TSUBASSIGN);
"*=" return(TMULASSIGN);
"/=" return(TDIVASSIGN);
"%=" return(TMODASSIGN);
"!" return(TNOT);
"&&" return(TAND);
"||" return(TOR);
"==" return(TEQUAL);
"!=" return(TNOTEQU);
"<" return(TLESS);
">" return(TGREAT);
"<=" return(TLESSE);
">=" return(TGREATE);
"++" return(TINC);
"--" return(TDEC);
"(" return(TLPAREN);
")" return(TRPAREN);
"{" return(TLBRACE);
"}" return(TRBRACE);
"[" return(TLSQUARE);
"]" return(TRSQUARE);
"," return(TCOMMA);
";" return(TSEMICOLON);
\n line_num++;
[ \t] ;
"//".* ;
/************* *******************/
//여기 report_error로 일괄 처리하도록 코드 변경
{L}({L}|{D})* { 
if(yyleng > 12) return(TTOOLONG); 
else {
symbolTable();
return(TIDENT);
}
}
/************* *******************/
//여기 report_error로 일괄 처리하도록 코드 변경
{D}+{L}({L}|{D})* return(TILLIDENT);
{D}+ return(TNUMBER);
{D}+"."{D}+ return(TRNUMBER);
. return(TILLCH);
%%
int yywrap() {
printf("\n");
printf("2071033 YOON-HAYEONG\n");
printf("2076216 SONG-CHAEWON\n");
printf("2176082 KIM-YEJI\n");
printf("2271035 SHIN-JUNGHWA\n");
return 1;
}
