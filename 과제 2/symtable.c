/*
  symtable.c - symbol table management program
  programmer - 박소현
  date - 2024/04/28
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STsize 1000 // String Table 사이즈

char ST[STsize];   // String Table 정의
int STindex = 0;   // 다음으로 사용 가능한 ST의 인덱스

// ST에 동일한 identifier가 있는지 확인하는 함수
int isIdentifierExists(char *yytext) {
    int i;
    for (i = 0; i < STindex; i++) {
        // 새로운 identifier와 ST 내 기존 identifiers 비교
        if (strcmp(&ST[i], yytext) == 0) {
            return 1; // Identifier 이미 존재
        }
    }
    return 0; // Identifier 겹치지 않음
}

// 기존의 것과 겹치지 않는 new identifier일 때 실행
void symtable(char *yytext) {
    // 존재 여부 확인
    if (!isIdentifierExists(yytext)) {
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
}
