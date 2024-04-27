/*
* main.c - 각 token에 대한 출력
* programmer - 조은혜
* date - 04/28/2024
*/

#include <stdio.h>
#include "tn.h"

extern yylex();
// cErrors: reporterror.c에서 카운팅한 에러 횟수
extern int cErrors;
// Stindex: symtable.c에서 저장한 identifier의 ST-index
extern int STindex;


void main(){
    enum tnumber tn;

    printf(" Start of Lex\n");

    while((tn=yylex()) != EOF){
        // printtoken 함수를 호출하여 토큰에 대한 정보를 출력한다.
        printtoken(tn);
    }
    // 에러가 없는 경우 에러가 없다고 출력한다.
    if(cErrors == 0){
        printf("No errors detected ");
    }
    // 에러가 있는 경우 몇 번의 에러가 있었는지 출력한다.
    else{
        printf("%d errors detected", cErrors);
    }

    printf("End of LEX\n");
}

// printtoken: 토큰을 출력해주는 함수
// yylineno: 렉스 정규표현과 매칭된 문자열이 있는 행 정보
// yytext: 렉스 정규표현과 매칭된 문자열
printtoken(enum tnumber tn) {
	switch(tn)
        case TCOMMENT:  printf("%d\t\tcomment\t\t\t\t%s\n",yylineno,yytext); break;
        case TCONST:        printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TELSE:         printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TIF:           printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TINT:          printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TRETURN:       printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TVOID:         printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TWHILE:	    printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TADD:          printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TSUB:          printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TMUL:          printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TDIV:          printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TMOD:          printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TASSIGN:       printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TADDASSIGN:	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TSUBASSIGN:	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TMULASSIGN:	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TDIVASSIGN:	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TMODASSIGN:	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TNOT:          printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TAND:		    printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TOR:		    printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TEQUAL:	    printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TNOTEQU:	    printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TLESS:	        printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TGREAT:	    printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TLESSEQU:      printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TGREATEQU:     printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TINC:		    printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TDEC:		    printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        case TPAREN:        printf("%d\t\tparenthesis\t\t\t\t%s\n", yylineno, yytext); break;
        case TCOMMA:        printf("%d\t\tcomma\t\t\t\t%s\n", yylineno, yytext); break;
        case TCURLY:        printf("%d\t\tcurly bracket\t\t\t\t%s\n", yylineno, yytext); break;
        case TSQUARE:       printf("%d\t\tsquare bracket\t\t\t\t%s\n", yylineno, yytext); break;
        case TSEMI:         printf("%d\t\tsemicolon\t\t\t\t%s\n", yylineno, yytext); break;
        case TIDENT:		printf("%d\t\tident\t\t%d\t\t%s\n", yylineno, STindex, yytext); break;
        case TNUMBER:		printf("%d\t\tnumber\t\t\t\t%s\n", yylineno, yytext); break;
}