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
// 
extern char *yytext;
// yylineno: Line number 출력을 위한 변수
extern int yylineno = 0;


void main(){
    enum tnumber tn;

    PrintHeading();

    while((tn=yylex()) != EOF){
        // PrintToken 함수를 호출하여 토큰에 대한 정보를 출력한다.
        PrintToken(tn);
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
// PrintHeading: 토큰 출력 전 헤딩을 출력해주는 함수
void PrintHeading(){
    printf("Line number\tToken type\tST-index\tToken");
    printf("\n");
}

// printtoken: 토큰을 출력해주는 함수
// yylineno: 렉스 정규표현과 매칭된 문자열이 있는 행 정보
// yytext: 렉스 정규표현과 매칭된 문자열
void PrintToken(enum tnumber tn) {
	switch(tn){
        // 주석
        case TCOMMENT:  printf("%d\t\tcomment\t\t\t\t%s\n",yylineno,yytext); break;
        // Keyword (예약어)
        case TCONST:        printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TELSE:         printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TIF:           printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TINT:          printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TRETURN:       printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TVOID:         printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        case TWHILE:	    printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        // Operator (연산자): 사칙연산자, 배정연산자, 논리연산자, 관계연산자, 증감연산자
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
        // Special Symbols: 괄호, 중괄호, 대괄호, 콤마, 세미콜론
        case TPAREN:        printf("%d\t\tparenthesis\t\t\t\t%s\n", yylineno, yytext); break;
        case TCOMMA:        printf("%d\t\tcomma\t\t\t\t%s\n", yylineno, yytext); break;
        case TCURLY:        printf("%d\t\tcurly bracket\t\t\t\t%s\n", yylineno, yytext); break;
        case TSQUARE:       printf("%d\t\tsquare bracket\t\t\t\t%s\n", yylineno, yytext); break;
        case TSEMI:         printf("%d\t\tsemicolon\t\t\t\t%s\n", yylineno, yytext); break;
        // White Spaces: blank, tab, newline
        case TBLANK:        break;
        case TTAB:          break;
        case TNEWLINE:      break;
        // Identifier (명칭)
        case TIDENT:		printf("%d\t\tident\t\t%d\t\t%s\n", yylineno, STindex, yytext); break;
        // Constant (상수): 정수 상수, 실수
        case TNUMBER:		printf("%d\t\tnumber\t\t\t\t%s\n", yylineno, yytext); break;
        case TFLOAT:        printf("%d\t\tfloat number\t\t\t\t%s\n", yylineno, yytext); break;
    }
}
