%{
#include <stdio.h>
#include <stdlib.h>
enum tnumber {TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE, TEQUAL, TNOTEQU, TLESS, TGREATE, TAND, TOR, TINC, TDEC, TADDASSIGN, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN, TIDENT, TNUMBER};
%}

%%

"const"	  return(TCONST);

"else"		return(TELSE);

"if"		return (TIF);

"int"		return(TINT);

"return"	return(TRETURN);

"void"		return(TVOID);

"while"		return(TWHILE);
____________________________________________________________________________________

"=="	return(TEQUAL);

"!="	return(TNOTEQU);

"<="	return(TLESS);

">="	return(TGREATE);

"&&"	return(TAND);

"||"	return(TOR);

"++"	return(TINC);

"--"	return(TDEC);

"+="	return(TADDASSIGN);

"-="	return(TSUBASSIGN);

"*="	return(TMULASSIGN);

"/="	return(TDIVASSIGN);

"%="	return(TMODASSIGN);
-------------------------------------------------------------------------------
[A-Za-z_][A-Za-z0-9_]*	return(TIDENT);

[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TNUMBER);

"/*"(［^*］|\*+[^*/]）*\**"*/"	;

"//".*	;

[ \t\n]	;

・	return(yytext[0]);

%%

int yywrap()
{
  printf("2176143 ParkSohyun 2171047 JoYoona 2176365 JoEunhye 2176368 JiHyunseo\n")
  return 1;
}
