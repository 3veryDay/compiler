%{
#include <stdio.h>
#include "tn.h"  /* token name definition */
extern void symtable(char *yytext);
extern void report_error(int i, char *s);

%}
letter  [a-zA-Z_]
digit  [0-9]
%option yylineno
%%
"//".*  return(TCOMMENT);
"const"  return(TCONST);
"else"  return(TELSE);
"if"  return(TIF);
"int"  return(TINT);
"return"  return(TRETURN);
"void"  return(TVOID);
"while"  return(TWHILE);
"+"  return(TADD);
"-"   return(TSUB);
"*"  return(TMUL);
"/"  return(TDIV);
"%"  return(TMOD);
"="  return(TASSIGN);
"+="  return(TADDASSIGN);
"-="  return(TSUBASSIGN);
"*="  return(TMULASSIGN);
"/="  return(TDIVASSIGN);
"%="  return(TMODASSIGN);
"!"  return(TNOT);
"&&"  return(TAND);
"||"  return(TOR);
"=="  return(TEQUAL);
"!="  return(TNOTEQU);
"<"  return(TLESS);
">"  return(TGREAT);
"<="  return(TLESSEQU);
">="  return(TGREATEQU);
"++"  return(TINC);
"--"  return(TDEC);
"("|")"  return(TPAREN);
","  return(TCOMMA);
"{"|"}"  return(TCURLY);
"["|"]"  return(TSQUARE);
";"  return(TSEMI);
" "	return(TBLANK);
\t	return(TTAB);
\n	{return(TNEWLINE);}
{letter}({letter}|{digit})*  {
	if (yyleng <= 12) {
		symtable(yytext); 
		return(TIDENT); 
	} else {
		 report_error(yylineno, yytext);
	}
}
{digit}+  return(TNUMBER);
{digit}+"."{digit}+(e[+-]?[0-9]+)?  return(TFLOAT);
[^ \t\n]*  report_error(yylineno, yytext);
%%
int yywrap() {
	printf("2171047 JoYoona\n2176143 ParkSohyun\n2176365 JoEunhye\n2176368 JiHyunseo\n");
	return 1;
}


#define STsize 1000 // String Table 사이즈

char ST[STsize];   // String Table 선언
int STindex = 0;   // 다음으로 사용 가능한 ST의 인덱스

// Add Identifier to String Table
void symtable(char *yytext) {
    int i = 0;
    while (yytext[i] != '\0') {
        // ST에 식별자의 각 문자 추가
        if (STindex < STsize) {
            ST[STindex++] = yytext[i];
        } else {
            printf("Error: String Table overflow\n");
            exit(EXIT_FAILURE); 
        }
        i++;
    }
    // 식별자의 끝을 나타내는 널 문자 추가
    if (STindex < STsize) {
        ST[STindex++] = '\0';
    } else {
        printf("Error: String Table overflow\n");
        exit(EXIT_FAILURE);
    }
}

// PrintHeading: 토큰 출력 전 헤딩을 출력해주는 함수
void PrintHeading(){
    printf("Line number\tToken type\tST-index\tToken");
    printf("\n");
}

//에러 카운트(마지막에 출력)
int cErrors = 0;

/* Function to report error for mixed characters */
//report_error 함수(줄 위치 i, yytext에 있는 token s)
void report_error(int i, char *s) {
    
    //토큰 분류에서 오류가 나는 경우(scanner.l에서 . -> TERROR 선언)
    //cErrors 하나 증가
    cErrors ++ ;

    //공통 부분 출력 - Line Number 출력
    printf("%d\t\t", i);

    //공통 부분 출력 - Token type - **Error** 출력
    printf("**Error**\t\t");

    //공통 부분 출력 - ST-index - 비어있는 부분
    printf("\t\t\t");

    //Illegal Identifier - over 12 characters
    //식별자는 12자 이내이어야 함
    if (strlen(s) >= 12) {
        printf("%s\t -> Too Long Identifier, over 12 characters", s);
    }
    //Illegal Identifier - Starts with Digit
    //식별자는 숫자로 시작하면 안됨
    else if(isdigit(s[0])) {
        printf("%s\t\t -> Starts with Digit",s);
    }
    //Illegal Character
    //정의되지 않은 문자를 사용하면 안됨.-
    else {
        printf("%s\t\t -> Illegal Character ", s);
    }
}

// printtoken: 토큰을 출력해주는 함수
// yylineno: 렉스 정규표현과 매칭된 문자열이 있는 행 정보
// yytext: 렉스 정규표현과 매칭된 문자열
void PrintToken(enum tnumber tn) {
	switch(tn){
        	// 주석
        	case TCOMMENT:		printf("%d\t\tcomment\t\t\t\t%s\n",yylineno,yytext); break;
        	// Keyword (예약어)
        	case TCONST:		printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        	case TELSE:         	printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        	case TIF:           	printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        	case TINT:          	printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        	case TRETURN:       	printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        	case TVOID:         	printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        	case TWHILE:	    	printf("%d\t\tkeyword\t\t\t\t%s\n", yylineno, yytext); break;
        	// Operator (연산자): 사칙연산자, 배정연산자, 논리연산자, 관계연산자, 증감연산자
        	case TADD:          	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TSUB:          	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TMUL:          	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TDIV:          	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TMOD:          	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TASSIGN:       	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TADDASSIGN:	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TSUBASSIGN:	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TMULASSIGN:	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TDIVASSIGN:	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TMODASSIGN:	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TNOT:      	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TAND:		printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TOR:		printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TEQUAL:	    	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TNOTEQU:	    	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TLESS:	        printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TGREAT:	    	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TLESSEQU:      	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TGREATEQU:     	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TINC:	    	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	case TDEC:	    	printf("%d\t\toperator\t\t\t\t%s\n", yylineno, yytext); break;
        	// Special Symbols: 괄호, 중괄호, 대괄호, 콤마, 세미콜론
        	case TPAREN:        	printf("%d\t\tparenthesis\t\t\t\t%s\n", yylineno, yytext); break;
        	case TCOMMA:        	printf("%d\t\tcomma\t\t\t\t%s\n", yylineno, yytext); break;
        	case TCURLY:        	printf("%d\t\tcurly bracket\t\t\t\t%s\n", yylineno, yytext); break;
        	case TSQUARE:       	printf("%d\t\tsquare bracket\t\t\t\t%s\n", yylineno, yytext); break;
        	case TSEMI:         	printf("%d\t\tsemicolon\t\t\t\t%s\n", yylineno, yytext); break;
        	// White Spaces: blank, tab, newline
        	case TBLANK:        	break;
        	case TTAB:          	break;
        	case TNEWLINE:      	break;
        	// Identifier (명칭)
        	case TIDENT:		printf("%d\t\tident\t\t%d\t\t%s\n", yylineno, STindex, yytext); break;
        	// Constant (상수): 정수 상수, 실수
        	case TNUMBER:		printf("%d\t\tnumber\t\t\t\t%s\n", yylineno, yytext); break;
        	case TFLOAT:        	printf("%d\t\tfloat number\t\t\t\t%s\n", yylineno, yytext); break;
    }	
}


void main(){
    enum tnumber tn;

    PrintHeading();

    while((tn=yylex()) != TEOF){
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
