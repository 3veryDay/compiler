/*
* ReportError.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"
extern line(int);
extern yylex();

/*
*  yyerror() - error함수
*/
yyerror(s)
char*s ;
{
}

void printError(ERRORtypes err) {
  switch(err) {
    case 0 : // wrong_statement
      line(cLine);
      printf("< Error > => Wrong Statement! \n ");
      cErrors++;
      break;
    case 1 : // wrong_function def
      line(cLine);
      printf("< Error > => Wrong Function definition! \n ");
      cErrors++;
      break;
    case 2:  //no semi colon
      line(cLine);
      printf("< Error > =>Missing semicolon! \n ");
      cErrors++;
      break;
    case 3 : //no brace
      line(cLine);
      printf("< Error > => Missing brace! \n ");
      cErrors++;
      break;
    case 4 : //no bracket
      line(cLine);
      printf("< Error > =>Missing Bracket! \n ");
      cErrors++;
      break;
  }
}
