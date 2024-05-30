/*
	ReportError.c - error에 대한 상세한 정보를 출력하는 함수
*/

#include <stdio.h>
#include <stdlib.h>
#include "glob.h"
// 라인 넘버 변수는 lineno , glob.h에 정의되어 있음
// ErrorType 도 glob.h에 정의

extern char* yytext;

// 에러 메시지 출력 함수
//char* s : 에러 메시지
yyerror(char* s)
{

}

// 에러 타입에 따라 에러 메시지 출력
//ErrorType err : 에러 타입

void ReportError(ErrorType err)
{
	switch (err)
	{
		// 에러가 없는 경우
	case noerror:
		break;

		// 식별자가 숫자로 시작하는 경우
	case digit_ident:
		cErrors++;
		printf("line %6d          ERROR!!			  %-10s		start with digit\n", lineno, yytext);
		break;

		// 식별자가 너무 긴 경우(12자 이상)
	case long_ident:
		cErrors++;
		printf("line %6d          ERROR!!			  %-13s	 	too long identifier\n", lineno, yytext);
		break;

		// 잘못된 기호가 들어온 경우
	case ill_symbol:
		cErrors++;
		printf("line %6d          ERROR!!			  %-5c		illegal symbol\n", lineno, yytext[0]);
		break;

		// ST(StringTable)가 넘치는 경우
	case over_st:
		cErrors++;
		printf("\nError : OVERFLOW in ST\n");
		printf("==================================================\n");
		exit(0);
		break;

		// 세미콜론이 빠진 경우
	case missing_semi:
		cErrors++;
		printf("line %6d          ERROR!!			  missing semicolon\n", lineno - 1);
		break;
		// 왼쪽 괄호가 빠진 경우
	case missing_lparen:
		cErrors++;
		printf("line %6d          ERROR!!			  no left parenthesis\n", lineno);
		break;
		// 왼쪽 중괄호가 빠진 경우
	case missing_lcurly:
		cErrors++;
		printf("line %6d          ERROR!!			  no left curly bracket\n", lineno);
		break;
		// 왼쪽 대괄호가 빠진 경우
	case missing_lsquare:
		cErrors++;
		printf("line %6d          ERROR!!			  no left square bracket\n", lineno);
		break;

		// 오른쪽 괄호가 빠진 경우
	case missing_rparen:
		cErrors++;
		printf("line %6d          ERROR!!			  no right parenthesis\n", lineno);
		break;

		// 오른쪽 중괄호가 빠진 경우
	case missing_rcurly:
		cErrors++;
		printf("line %6d          ERROR!!			  no right curly bracket\n", lineno);
		break;

		// 오른쪽 대괄호가 빠진 경우
	case missing_rsquare:
		cErrors++;
		printf("line %6d          ERROR!!			  no right square bracket\n", lineno);
		break;

		// 쉼표가 빠진 경우
	case missing_comma:
		cErrors++;
		printf("line %6d          ERROR!!			  missing comma\n", lineno);
		break;

		// 함수 헤더가 빠진 경우
	case missing_funcheader:
		cErrors++;
		printf("line %6d          ERROR!!			  no function header\n", lineno);
		break;

		// 선언이 잘못된 경우
	case declaring_err:
		cErrors++;
		printf("line %6d          ERROR!!              	wrong declaration\n", lineno);
		break;

		// 조건이 빠진 경우
	case missing_condition:
		cErrors++;
		printf("line %6d          ERROR!!              	missing condition\n", lineno);
		break;

		// 잘못된 대입이 있는 경우
	case wrong_assign:
		cErrors++;
		printf("line %6d          ERROR!!              	wrong assignment\n", lineno);
		break;

		// 피연산자가 빠진 경우
	case missing_operand:
		cErrors++;
		printf("line %6d          ERROR!!              	missing operand\n", lineno);
		break;

	}
}
