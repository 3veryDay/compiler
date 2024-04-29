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
    for (i = 0; i < STindextail; i++) {  // String Table을 처음부터 끝까지 배열 단위로 확인.i로 카운트
        // Compare each character of yytext with the characters in ST
        for (j = 0; j < yytext_len; j++) {  // 입력된 식별자의 각 문자를 j로 카운트하여 확인.
            if (ST[i + j] != yytext[j]) {  // 만약 문자가 일치하지 않으면
                break; // break the loop
            }
        }
        if (j == yytext_len) {  // 입력된 식별자의 모든 문자가 일치하는 경우
            return i + j; // 일치하는 identifier의 끝 글자와 매치하는 ST 인덱스 반환
        }
    }
    return 0; // 새로운 식별자일 시 0 반환
}

// 새로운 식별자를 심볼 테이블에 추가하거나 이미 있는 식별자의 시작 인덱스를 반환
void symtable(char *yytext) {
    // 기존에 발견된 식별자가 있는 경우, tmp에 저장해두었던 (사용가능한) 다음 인덱스 값을 STindextail에 저장하고 tmp 초기화
    // 이렇게 함으로써 뒤이어 오는 identifier들에 대한 처리가 중복 여부와 관계없이 원활히 수행됨
    if (tmp != 0) { STindextail = tmp; tmp = 0; }  
    int exist = isIdentifierExists(yytext);  // 입력된 식별자가 이미 존재하는지 확인. 
    if (exist == 0) {  // 만약 존재하지 않는 경우 = 새로운 identifier인 경우
        int i = 0;
        while (yytext[i] != '\0') {  // 입력된 식별자의 끝까지 반복
            // ST에 식별자의 각 문자 추가
            if (STindextail < STsize) {  // String Table이 오버플로우되지 않았을 경우
                ST[STindextail++] = yytext[i];  // String Table에 문자 추가하고 다음 인덱스로 이동
            } else {
                printf("Error: String Table overflow\n");  // 오버플로우 발생 시 에러 메시지 출력
                exit(EXIT_FAILURE);  // 프로그램 종료
            }
            i++;
        }
        // 식별자의 끝을 나타내는 널 문자 추가
        if (STindextail < STsize) {  // String Table이 오버플로우되지 않았을 경우
            ST[STindextail++] = '\0';  // 널 문자 추가하고 다음 인덱스로 이동
            STindex = STindextail - (strlen(yytext) + 1);  // 현재 식별자의 시작 인덱스 저장
        } else {
            printf("Error: String Table overflow\n");  // 오버플로우 발생 시 에러 메시지 출력
            exit(EXIT_FAILURE);  // 프로그램 종료
        }
    }
    else {  // 만약 exist != 0, 즉 exist가 위의 i + j 값을 반환하여 이미 존재하는 identifier라는 것이 확인된 경우
        tmp = STindextail;  // (사용가능한) 다음 인덱스를 임시로 저장. 각 identifier 처리를 위한 symtable 함수가 호출될 때마다 if(tmp != 0)을 처리하기 위해 쓰임
        STindextail = exist + 1;  // 다음 인덱스를 중복 식별자의 끝으로 설정
        STindex = STindextail - (strlen(yytext) + 1);  // 현재 식별자의 시작 인덱스 저장
    }
}
