/*
* main.c - 소스 코드를 파싱 및 파싱된 결과물을 출력
* programmer – 조윤아(2171047), 박소현(2176143), 조은혜(2176365), 지현서(2076368) 
* date – 2024-05-29
*/


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "tn.h" 
#include "glob.h" 

// 외부 함수 및 변수 선언
extern yylex();
extern char *yytext;
void printHSTable();

// main 함수
void main()
{
    lineno = 1; // 행 번호를 1로 초기화
    printf("******************************[[MiniC parsing begins]]\n");
    yyparse(); // 파싱 시작
    printf("[[Parsing Ends]]**************************************\n");
    printf("\n\n%d error(s) detected\n\n", cErrors); // 발견된 에러 수 출력
    printf("====================[[Hash Table]]====================\n");

    printHSTable(); // 해시 테이블 출력
    printf("\n\n2171047 JoYoona\n2176143 ParkSohyun\n2176365 JoEunhye\n2176368 JiHyunseo\n");
}

// 해시 테이블을 출력하는 함수
void printHSTable(){
    HTpointer here;
    int i, j;

    // 해시 테이블을 순회
    for (i = 0; i < HTsize; i++) {
        if (HT[i] != NULL) {
            here = HT[i];            
            // 각 해시 테이블 인덱스의 연결 리스트를 순회
            while (here != NULL) {
                printf("HashCode %d:\t", i);
                j = here->index;
                // String Table(ST)에 저장된 문자열 출력
                while (ST[j] != '\0') {
                    printf("%c", ST[j++]);
                }
                // 변수/함수 타입 및 기타 정보 출력
                if (here->spec == NONE) {
                    printf(" / not defined ");
                } else if (!here->error) {
                    if (here->isFunction) { 
                        // 함수 반환 타입 출력
                        switch (here->spec)
                        {
                        case  INT:
                            printf(" / Return Type: Integer ");
                            break;
                        case  VOID:
                            printf(" / Return Type: Void ");
                            break;
                        case  FLOAT:
                            printf(" / Return Type: Float ");
                            break;
                        }
                        printf("Function ");
                    } else { 
                        // 변수 타입 출력
                        if (here->isConst) {
                            printf(" / Const ");
                        }
                        switch (here->spec)
                        {
                        case  INT:
                            printf(" / Integer ");
                            break;
                        case  FLOAT:
                            printf(" / Float ");
                            break;
                        }
                        if (here->isArray) {
                            printf("Array ");
                        } else {
                            printf("Scalar ");
                        }
                        if (here->isParam) {
                            printf("Parameter ");
                        }
                        printf("Variable ");
                    }
                } else if(here->error) {
                    printf(" / not defined ");
                }
                // 심볼이 나타나는 행 번호 출력
                printf("/ Linenum: %d \n", here->linenum);
                here = here->next; // 연결 리스트의 다음 노드로 이동
            }
        }
    }
}
