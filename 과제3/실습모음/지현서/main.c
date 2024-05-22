/*  
*  main.c - 각 token에 대한 출력 내용 정의
*
*
*
*/
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern int yyparse();
extern void PrintHStable();

void main()
{
  printf("\n\t[Error Report : Error Information]");
  printf("\n============================================\n");

  cLine = 1 ;
  yyparse();

  if(cErrors == 0) printf("\n\t no error detected! \n");
  else printf("\n\t %d error(s) detected!\n", cErrors);

  printf("\n============================================\n");
  PrintHStable();  //identifier와 그 type을 print하는 함수
}
