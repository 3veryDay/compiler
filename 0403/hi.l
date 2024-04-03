%{
/*
*2024 04 03 
*/

#include <stdio.h>
#include <stlib.h>
enum tnumber{ TEOF};

%}

%%

int  printf("integer");
"{"  printf("\nbegin");
"}"  printf("\nend");
.    printf("%s". yytest);
%%
