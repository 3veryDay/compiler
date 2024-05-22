%{
// scanner.l - lexical analyzer for the MODIFIED MiniC
#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
#include "glob.h"

extern ComputeHS(int nid, int nfree);
extern LookupHS(int nid, int nfree);
extern ADDHT(int hscode);
extern PrintHStable();
extern yyerror(char *s);

int i;
%}

%s CMT

%%
"const"    {return(TCONST);}
"else"     {return(TELSE);}
"if"       {return(TIF);}
...

[A-Za-z_][A-Za-z0-0_]* {//identifier의 경우 스트링 테이블 및 해쉬 테이블 관리

  //ST 오버플로우의 경우 
  // 에러 출력, 해쉬 테이블 출력하고 끝
  if(nextfree >= STsize){
    print("/tError >> \tOVERFLOW!\n");
    printHStable();
    exit(1);
    }
  //ST가 남아서 괜찮은 경우
  
  //nextid, nextfree 조정
  nexid = nextfree;
  nextfree = (yyleng + 1);

  //ST에 identifier 집어넣기
  for(i=0; i<yyleng; i++) //identifier를 String 테이블에 넣기
    ST[nextid+i] = yytext[i];

  //기존 HS에 identifier가 있었는지 찾는 거!
  //기존 HS에 있음 => found = 1
  //기존 HS에 없음 => found = 0
  ComputeHS(nextid, nextfree);
  LookupHS(nextid, hashcode);
  

  //없었다면 해쉬 테이블에 추가
  if(!found) {
    ADDHT(hashcode)
    }
  //있었다면 ST에서 없애기? 
  else {
  for(i = nextid;<nextfree-1;i++){
  ST[i] = "/0"
  }
  nextfree = nextid;
  }
  return(TIDEN);
  }
  
  
