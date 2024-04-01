//시작
%{
#include <stdio.h>
#include <stdlib.h>
enum number {TEOF, TIDEN, TNUM, TASSIGN, TADD, TSEMI, TDOT,
TBEGIN, TEND, TERROR};
%}
letter	      [a-zA-Z_]
digit		      [0- 9]
%%
begin					                  return(TBEGIN);
end						                  return(TEND);
{letter} ({letter) | {digit})*	return(TIDEN);
":="						                return(TASSIGN);
"+"						                  return (TADD);
{digit} +					              return(TNUM);
“;”						                  return(TSEMI);
\.						                  return(TDOT);
[ It\n]					                ;
.						                    return(TERROR);
%%
void (main)
