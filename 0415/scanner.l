/*
 lex file
*/
%{
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
%}
%%
"const"	  			return(TCONST);
"else"				return(TELSE);
"if"				return (TIF);
"int"				return(TINT);
"return"				return(TRETURN);
"void"				return(TVOID);
"while"				return(TWHILE);
"=="				return(TEQUAL);
"!="				return(TNOTEQU);
"<="				return(TLESSE);
">="				return(TGREATE);
"&&"				return(TAND);
"||"				return(TOR);
"++"				return(TINC);
"--"				return(TDEC);
"+="				return(TADDASSIGN);
"-="				return(TSUBASSIGN);
"*="				return(TMULASSIGN);
"/="				return(TDIVASSIGN);
"%="				return(TMODASSIGN);
[A-Za-z_][A-Za-z0-9_]*		return(TIDENT);
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TNUMBER);
"/*"([^*]|\*+[^*/])*\**"*/"	;
"//".*	;
[ \t\n]	;
・	return(yytext[0]);
%%
//main 함수는 없어야 함.
int yywrap() {
	printf("2171047 JoYoona\n2176143 ParkSohyun\n2176365 JoEunhye\n2176368 JiHyunseo\n");
	return 1;
}

