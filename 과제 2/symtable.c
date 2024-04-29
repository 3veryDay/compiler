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
int STindextail = 0;   // 다음으로 사용 가능한 ST의 인덱스
int STindex = 0;      // 해당 identifier가 저장된 ST 내 첫번째 주소
int tmp = 0;

// ST에 동일한 identifier가 있는지 확인하는 함수
int isIdentifierExists(char *yytext) {
    int i, j;
    int yytext_len = strlen(yytext);
    for (i = 0; i < STindextail; i++) {
        // Compare each character of yytext with the characters in ST
        for (j = 0; j < yytext_len; j++) {
            if (ST[i + j] != yytext[j]) {
                break; // If any character does not match, break the loop
            }
        }
        if (j == yytext_len) {
            return i + j; // If all characters match, return 1 (Identifier already exists)
        }
    }
    return 0; // Identifier does not exist
}



// 기존의 것과 겹치지 않는 new identifier일 때 실행
void symtable(char *yytext) {
    if (tmp != 0) { STindextail = tmp; tmp = 0; }
    // 존재 여부 확인
    int exist = isIdentifierExists(yytext);
    if (exist == 0) {
        int i = 0;
        while (yytext[i] != '\0') {
            // ST에 식별자의 각 문자 추가
            if (STindextail < STsize) {
                ST[STindextail++] = yytext[i];
            } else {
                printf("Error: String Table overflow\n");
                exit(EXIT_FAILURE); 
            }
            i++;
        }
        // 식별자의 끝을 나타내는 널 문자 추가
        if (STindextail < STsize) {
            ST[STindextail++] = '\0';
            STindex = STindextail - (strlen(yytext) + 1);
        } else {
            printf("Error: String Table overflow\n");
            exit(EXIT_FAILURE);
        }
    }
    else {
        tmp = STindextail;
        STindextail = exist + 1;
        STindex = STindextail - (strlen(yytext) + 1);
    }
}
