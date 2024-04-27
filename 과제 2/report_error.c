/* report_error.c 
programmer - 11
date - 2024/04/28
*/
#include <stdio.h>
#include <ctype.h>

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
