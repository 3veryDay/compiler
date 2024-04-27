/* report_error.c 
programmer - 11
date - 2024/04/28
*/
#include <stdio.h>
#include <ctype.h>
/* Function to report error for mixed characters */
//report_error 함수(줄 위치 i, yytext에 있는 token s)
void report_error(int i, char *s) {

    //공통 부분 출력 - Line Number 출력
    printf("%d\t\t", i);

    //공통 부분 출력 - Token type - **Error** 출력
    printf("**Error**\t\t");

    //공통 부분 출력 - ST-index - 비어있는 부분
    printf("\t\t\t");

    if(isdigit(s[0])) {
        printf("%s\t\t -> Starts with Digit",s);
    }
    else if (strlen(s) > 12) {
        printf("%s\t -> Too Long Identifier, over 12 characters", s);
    }
    else {
        printf("%s\t\t -> Illegal Character ", s);
    }




}
