/*
  symtable.c - symbol table management program
  programmer - 박소현
  date - 2024/04/28
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
