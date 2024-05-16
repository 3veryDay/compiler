%{
  /* Lex source for calculator program */
  #include <stdio.h>
  #include <stdlib.h>
  #include "tn.h"
%}
%%
[a-z]*  {return NAME;}
[0-9]*  {yylval = atoi(yytext); return NUMBER;}
[ \t]  ;
"\n"  return 0;
.  return yytext[0];
%%
int yywrap()
{
  return 1;
  printf("2171047 JoYoona\n2176143 ParkSohyun\n2176365 JoEunhye\n2176368 JiHyunseo\n");
}
