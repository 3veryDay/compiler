/*
	parser.y - MiniC를 위한 YACC 소스
*/


%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

/*yacc source for Mini C*/

int con = 0;			// con: 상수 관리를 위해 사용된 플래그 변수. TCONST 토큰을 만나면 1, 아닐 경우 0
int func = 0;			// func: 함수 관리를 위해 사용된 플래그 변수. 분석중인 구문이 함수일 경우 1, 아닐 경우 0
int param = 0;		// param: 함수의 파라미터 관리를 위해 사용된 플래그 변수. 파라미터가 존재하면 1, 아닐 경우 0
int array = 0;		// array: 배열의 관리를 위해 사용된 플래그 변수. 배열일 경우 1, 아닐 경우 0
int type = NONE;		// type: type을 관리하기 위해 사용된 변수. TINT 토큰을 만나면 INT,TNOID 토큰을 만나면 VOID, TFLOAT 토큰을 만나면 FLOAT

extern int yylex();
extern yyerror(char* s);
void changeHSTable();
%}

%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE
%nonassoc LOWER_THAN_OPT_STAT_LIST	
%nonassoc OPT_STAT_LIST

%token TEOF
%token TIDENT TNUMBER TREAL TCONST TELSE TIF TINT TFLOAT TRETURN TVOID TWHILE
%token TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TAND TOR TEQUAL TNOTEQU TLESS TGREAT TLESSEQU TGREATEQU TINC TDEC
%token TADD TSUB TMUL TDIV TMOD
%token TLPAREN TRPAREN TLCURLY TRCURLY TLSQUARE TRSQUARE TCOMMA TSEMI 



%%
mini_c 			: translation_unit
				;

translation_unit 		: external_dcl
				| translation_unit external_dcl
				;

external_dcl 			: function_def
		  		| declaration
				| TIDENT TSEMI
				| TIDENT error					{yyerrok;
												ReportError(missing_semi);}
				;

function_def 		: function_header compound_st
				| function_header error					{yyerrok;
												ReportError(missing_semi);}	// 오류 - 세미콜론 없음
				| error compound_st					{yyerrok;
												ReportError(missing_funcheader);}	// 오류 - 함수 헤더 없음
				;

function_header 		: dcl_spec function_name formal_param
				;

dcl_spec 			: dcl_specifiers
				;

dcl_specifiers 		: dcl_specifier
		 		| dcl_specifiers dcl_specifier
				;

dcl_specifier 		: type_qualifier
				| type_specifier
				;

type_qualifier 		: TCONST							{con = 1;}
				;

type_specifier 		: TINT								{type = INT;}
		 		| TVOID							{type = VOID;}
				| TFLOAT							{type = FLOAT;}
				;

function_name 		: TIDENT							{func = 1;
												changeHSTable();
												func = 0;
												con = 0;
												param = 0;
												array = 0;
												type = NONE;}
				;

formal_param 		: TLPAREN opt_formal_param TRPAREN
				| TLPAREN opt_formal_param error			{yyerrok;
												ReportError(missing_rparen);}	// 오류 - 오른쪽 괄호 없음
				;

opt_formal_param 		: formal_param_list						{param = 1;
												changeHSTable();
												func = 0;
												con = 0;
												param = 0;
												array = 0;
												type = NONE;}
		   		|								{param = 0;}		// 파라미터 작업 후 0으로 초기화
				;

formal_param_list 		: param_dcl							{param = 1;
												changeHSTable();}
		    		| formal_param_list TCOMMA param_dcl
				| formal_param_list TCOMMA error			{yyerrok;
												ReportError(missing_comma);}	// 오류 - 콤마 없음
				| formal_param_list param_dcl				{yyerrok;
												ReportError(missing_comma);}	// 오류 - 콤마 없음
				;

param_dcl 			: dcl_spec declarator					{param = 1;
												changeHSTable();}
				;

compound_st 		: TLCURLY opt_dcl_list opt_stat_list TRCURLY %prec LOWER_THAN_OPT_STAT_LIST
				| TLCURLY opt_dcl_list opt_stat_list error		{yyerrok;
												ReportError(missing_rcurly);}	// 오류 - 오른쪽 중괄호 없음
				;

opt_dcl_list 			: declaration_list
				|
				;

declaration_list 		: declaration
				| declaration_list declaration
				;

// 조윤아

declaration 		: dcl_spec init_dcl_list TSEMI	
					{
						con = 0;
						func =0;
						param = 0;
						array = 0;
						type = NONE;
					}
					| dcl_spec init_dcl_list error							
					{yyerrok;
					con = 0;
					func =0;
					param = 0;
					array = 0;
					type = NONE;
					ReportError(missing_semi);}	// 오류 - 세미콜론 없음
					;

init_dcl_list 		: init_declarator				
					| init_dcl_list TCOMMA init_declarator				
					| init_dcl_list init_declarator							{yyerrok; ReportError(missing_comma); current_id -> error =1;}	// 오류 - 콤마 없음
					;

init_declarator 	: declarator						
		 			| declarator TASSIGN TNUMBER
					| declarator TEQUAL TNUMBER								{yyerrok; ReportError(declaring_err);}	// 오류 - 변수 선언 에러
					| declarator TASSIGN TREAL
					| declarator TEQUAL TREAL								{yyerrok; ReportError(declaring_err);}	// 오류 - 변수 선언 에러
					;

declarator 			: TIDENT												{changeHSTable(); }
	     			| TIDENT TLSQUARE opt_number TRSQUARE					{array=1; changeHSTable(); }
					| TIDENT TLSQUARE opt_number error						{yyerrok; ReportError(missing_rsquare); }	// 오류 - 오른쪽 대괄호 없음
					;

opt_number 			: TNUMBER					
	     				|						
					;

opt_stat_list 		: statement_list OPT_STAT_LIST
		 			|
					;

statement_list 		: statement %prec LOWER_THAN_OPT_STAT_LIST					
			        | statement_list error 
					| statement_list statement 			
					;

statement 			: compound_st				
	   				| expression_st				
	   				| if_st						
	   				| while_st					
	   				| return_st					
					;

expression_st 		: opt_expression TSEMI
					| expression error										{yyerrok; ReportError(missing_semi);}	// 오류 - 세미콜론 없음
					;


opt_expression 		: expression					
		 			|						
					;

if_st 				: TIF TLPAREN expression TRPAREN statement %prec LOWER_THAN_ELSE 		
					| TIF TLPAREN expression TRPAREN statement TELSE statement
					| TIF TLPAREN expression error							{yyerrok; ReportError(missing_rparen);}		// 오류 - 오른쪽 괄호 없음
					| TIF TLPAREN TRPAREN error								{yyerrok; ReportError(missing_condition);}	// 오류 - 조건문 없음
					| TIF error                                             {yyerrok; ReportError(missing_lparen);}
					;

while_st 			: TWHILE TLPAREN expression TRPAREN TLCURLY  opt_stat_list TRCURLY
					| TWHILE TLPAREN expression TRPAREN TLCURLY  opt_stat_list error 			{yyerrok; ReportError(missing_rcurly);}	// 오류 - 오른쪽 중괄호 없음
					| TWHILE TLPAREN expression error						{yyerrok; ReportError(missing_rparen);}		// 오류 - 오른쪽 괄호 없음
					| TWHILE TLPAREN TRPAREN error							{yyerrok; ReportError(missing_condition);}	// 오류 - 조건문 없음
					| TWHILE error                                        {yyerrok; ReportError(missing_lparen);}
					;

return_st 			: TRETURN opt_expression TSEMI
					| TRETURN opt_expression error							{yyerrok; ReportError(missing_semi);}	// 오류 - 세미콜론 없음
					;

expression 			: assignment_exp;

assignment_exp 		: logical_or_exp				
					| unary_exp TASSIGN assignment_exp 		
					| unary_exp TADDASSIGN assignment_exp 	
					| unary_exp TSUBASSIGN assignment_exp 	
					| unary_exp TMULASSIGN assignment_exp 	
					| unary_exp TDIVASSIGN assignment_exp 	
					| unary_exp TMODASSIGN assignment_exp 	
					| unary_exp TASSIGN										{yyerrok; ReportError(wrong_assign);}	// 오류 - 잘못된 대입
					| unary_exp TADDASSIGN									{yyerrok; ReportError(wrong_assign);}		// 오류 - 잘못된 대입
					| unary_exp TSUBASSIGN				 					{yyerrok; ReportError(wrong_assign);}		// 오류 - 잘못된 대입
					| unary_exp TMULASSIGN				 					{yyerrok; ReportError(wrong_assign);}		// 오류 - 잘못된 대입
					| unary_exp TDIVASSIGN				 					{yyerrok; ReportError(wrong_assign);}		// 오류 - 잘못된 대입
					| unary_exp TMODASSIGN				 					{yyerrok; ReportError(wrong_assign);}	// 오류 - 잘못된 대입
					;

logical_or_exp 		: logical_and_exp				
					| logical_or_exp TOR logical_and_exp 	
					| logical_or_exp TOR error								{yyerrok; ReportError(missing_operand);}	// 오류 - 피연산자 없음
					;

logical_and_exp		: equality_exp					
		 			| logical_and_exp TAND equality_exp 
					| logical_and_exp TAND error							{yyerrok; ReportError(missing_operand);}		// 오류 - 피연산자 없음
					;

equality_exp 		: relational_exp				
					| equality_exp TEQUAL relational_exp 	
					| equality_exp TNOTEQU relational_exp 	
					| equality_exp TEQUAL error								{yyerrok; ReportError(missing_operand);}	// 오류 - 피연산자 없음
					| equality_exp TNOTEQU error							{yyerrok; ReportError(missing_operand);}		// 오류 - 피연산자 없음
					;	

relational_exp 		: additive_exp 				
			| relational_exp TGREAT additive_exp 		
			| relational_exp TLESS additive_exp 		
			| relational_exp TGREATEQU additive_exp 	
			| relational_exp TLESSEQU additive_exp 	
			| relational_exp TGREAT error							{yyerrok; ReportError(missing_operand);}		// 오류 - 피연산자 없음
			| relational_exp TLESS  error							{yyerrok; ReportError(missing_operand);} 		// 오류 - 피연산자 없음
			| relational_exp TGREATEQU error						{yyerrok; ReportError(missing_operand);}		// 오류 - 피연산자 없음
			| relational_exp TLESSEQU error							{yyerrok; ReportError(missing_operand);}		// 오류 - 피연산자 없음
			;

additive_exp 		: multiplicative_exp				
			| additive_exp TADD multiplicative_exp 
			| additive_exp TSUB multiplicative_exp 	
			| additive_exp TADD error							{yyerrok; ReportError(missing_operand);}		// 오류 - 피연산자 없음
			| additive_exp TSUB error							{yyerrok; ReportError(missing_operand);}			// 오류 - 피연산자 없음
			;

multiplicative_exp 	: unary_exp					
		    	| multiplicative_exp TMUL unary_exp 		
		    	| multiplicative_exp TDIV unary_exp 		
		    	| multiplicative_exp TMOD unary_exp 		
			| multiplicative_exp TMUL error							{yyerrok; ReportError(missing_operand);}		// 오류 - 피연산자 없음
		    	| multiplicative_exp TDIV error							{yyerrok; ReportError(missing_operand);}		// 오류 - 피연산자 없음
		    	| multiplicative_exp TMOD error							{yyerrok; ReportError(missing_operand);}		// 오류 - 피연산자 없음
			;

unary_exp 		: postfix_exp					
	   		| TSUB unary_exp				
	   		| TNOT unary_exp				
	   		| TINC unary_exp				
	   		| TDEC unary_exp				
			;

postfix_exp 		: primary_exp
	      		| postfix_exp TLCURLY expression TRCURLY
			| postfix_exp TLCURLY expression error						{yyerrok; ReportError(missing_rcurly);}		// 오류 - 오른쪽 중괄호 없음
	      		| postfix_exp TLPAREN opt_actual_param TRPAREN
			| postfix_exp TLPAREN opt_actual_param error					{yyerrok; ReportError(missing_rparen);}		// 오류 - 오른쪽 괄호 없음
			| postfix_exp TINC
	      		| postfix_exp TDEC
			;

opt_actual_param 	: actual_param	;

actual_param 		: actual_param_list;

actual_param_list 	: assignment_exp				
		   	| actual_param_list TCOMMA assignment_exp 
			;

primary_exp 		: TIDENT		
				{con = 0;
				func =0;
				param = 0;
				array = 0;
				type = NONE;}
	     		| TNUMBER	
			| TREAL
	     		| TLPAREN expression TRPAREN
			| TLPAREN expression error							{yyerrok; ReportError(missing_rparen);}		// 오류 - 오른쪽 괄호 없음
			;
%%

// changeHSTable : 해시테이블 설정 함수

void changeHSTable(){
	current_id->isConst= con;
	current_id->isFunction= func;
	current_id->isParam= param;
	current_id->isArray= array;
	current_id->spec= type;
}
