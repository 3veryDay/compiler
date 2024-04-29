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
    int i, j;
    int yytext_len = strlen(yytext);
    for (i = 0; i < STindex; i++) {
        // Compare each character of yytext with the characters in ST
        for (j = 0; j < yytext_len; j++) {
            if (ST[i + j] != yytext[j]) {
                break; // If any character does not match, break the loop
            }
        }
        if (j == yytext_len) {
            return 1; // If all characters match, return 1 (Identifier already exists)
        }
    }
    return 0; // Identifier does not exist
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
