%{
/* scanner.l_ lexical analyzer for the MiniC
programmer - 조윤아
date - 2024/04/28
*/
#include <stdio.h>
#include "tn.h"`  /* token name definition */
extern symtable
extern report_error
%}
letter  [a-zA-Z_]
digit  [0-9]
%%
"//".*  return(TCOMMENT);
"const"  return(TCONST);
"else"  return(TELSE);
"if"  return(TIF);
"int"  return(TINT);
"return"  return(TRETURN);
"void"  return(TVOID);
"while"  return(TWHILE);
"+"  return(TADD);
"-"   return(TSUB);
"*"  return(TMUL);
"/"  return(TDIV);
"%"  return(TMOD);
"="  return(TASSIGN);
"+="  return(TADDASSIGN);
"-="  return(TSUBASSIGN);
"*="  return(TMULASSIGN);
"/="  return(TDIVASSIGN);
"%="  return(TMODASSIGN);
"!"  return(TNOT);
"&&"  return(TAND);
"||"  return(TOR);
"=="  return(TEQUAL);
"!="  return(TNOTEQU);
"<"  return(TLESS);
">"  return(TGREAT)'
"<="  return(TLESSEQU);
">="  return(TGREATEQU);
"++"  return(TINC);
"--"  return(TDEC);
"("|")"  return(TPAREN);
","  return(TCOMMA);
"{"|"}"  return(TCURLY);
"["|"]"  return(TSQUARE);
";"  return(TSEMI);
[/t/n ]  ;
{letter}({letter}|{digit})*  {
	if (yyleng <= 12) {
		symtable(yytext); 
		return(TIDENT); 
	} else {
		 report_error(yylineno, yytext);
	}
}
{digit}+  return(TNUMBER);
{digit}+"."{digit}+(e[+-]?[0-9]+)?  return(TFLOAT);
[^ /t/n]*  report_error(yylineno, yytext);
%%
int yywrap() {
	printf("2171047 JoYoona\n2176143 ParkSohyun\n2176365 JoEunhye\n2176368 JiHyunseo\n");
	return 1;
}
