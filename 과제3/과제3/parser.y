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
mini_c 			: translation_unit	{printf("mini_c - translation_unit\n");}
				;

translation_unit 		: external_dcl	{printf("translation_unit - external_dcl\n");}
				| translation_unit external_dcl		{printf("translation_unit - translation_unit external_dcl\n");}
				;

external_dcl 			: function_def	{printf("external_dcl - function_def\n");}
		  		| declaration	{printf("external_dcl - declaration\n");}
				| TIDENT TSEMI	{printf("external_dcl - TIDENT TSEMI\n");}
				| TIDENT error					{yyerrok; printf("external_dcl - TIDENT error\n");
												ReportError(missing_semi);}
				;

function_def 		: function_header compound_st	{printf("function_def - function_header compound_st\n");}
				| function_header error					{yyerrok; printf("function_def - function_header error\n");
												ReportError(missing_semi);}	// 오류 - 세미콜론 없음
				| function_header TSEMI		{printf("function_def - function_header TSEMI\n");}
				| error compound_st					{yyerrok; printf("function_def - error compound_st");
												ReportError(missing_funcheader);}	// 오류 - 함수 헤더 없음
				;

function_header 		: dcl_spec function_name formal_param		{printf("function_header - dcl_spec function_name formal_param\n");}
				;

dcl_spec 			: dcl_specifiers	{printf("dcl_spec - dcl_specifiers\n");}
				;

dcl_specifiers 		: dcl_specifier		{printf("dcl_specifiers - dcl_specifier\n");}
		 		| dcl_specifiers dcl_specifier		{printf("dcl_specifiers - dcl_specifiers dcl_specifier\n");}
				;

dcl_specifier 		: type_qualifier		{printf("dcl_specifier - type_qualifier\n");}
				| type_specifier	{printf("dcl_specifier - type_specifier\n");}
				;

type_qualifier 		: TCONST							{con = 1; printf("type_qualifier - TCONST\n");}
				;

type_specifier 		: TINT								{type = INT; printf("type_specifier - TINT\n");}
		 		| TVOID							{type = VOID; printf("type_specifier - TVOID\n");}
				| TFLOAT							{type = FLOAT; printf("type_specifier - TFLOAT\n");}
				;

function_name 		: TIDENT							{printf("function_name - TIDENT\n");
												func = 1;
												changeHSTable();
												func = 0;
												con = 0;
												param = 0;
												array = 0;
												type = NONE;}
				;

formal_param 		: TLPAREN opt_formal_param TRPAREN	{printf("formal_param - TLPAREN opt_formal_param TRPAREN\n");}
				| TLPAREN opt_formal_param error			{yyerrok; printf("formal_param - TLPAREN opt_formal_param error\n");
												ReportError(missing_rparen);}	// 오류 - 오른쪽 괄호 없음
				;

opt_formal_param 		: formal_param_list						{printf("opt_formal_param - formal_param_list\n");
												param = 1;
												changeHSTable();
												func = 0;
												con = 0;
												param = 0;
												array = 0;
												type = NONE;}
		   		|								{param = 0;}		// 파라미터 작업 후 0으로 초기화
				;

formal_param_list 		: param_dcl							{printf("formal_param_list - param_dcl\n"); param = 1;
												changeHSTable();}
		    		| formal_param_list TCOMMA param_dcl	{printf("formal_param_list - formal_param_list TCOMMA param_dcl\n");}
				| formal_param_list TCOMMA error			{yyerrok; printf("formal_param_list - formal_param_list TCOMMA error\n");
												ReportError(missing_comma);}	// 오류 - 콤마 없음
				| formal_param_list param_dcl				{yyerrok; printf("formal_param_list - formal_param_list param_dcl\n");
												ReportError(missing_comma);}	// 오류 - 콤마 없음
				;

param_dcl 			: dcl_spec declarator					{param = 1; printf("param_dcl - dcl_spec declarator\n");
												changeHSTable();}
				;

compound_st 		: TLCURLY opt_dcl_list opt_stat_list TRCURLY %prec LOWER_THAN_OPT_STAT_LIST	{printf("compound_st - TLCURLY opt_dcl_list opt_stat_list TRCURLY\n");}
				| TLCURLY opt_dcl_list opt_stat_list error		{yyerrok; printf("compound_st - TLCURLY opt_dcl_list opt_stat_list error\n");
												ReportError(missing_rcurly);}	// 오류 - 오른쪽 중괄호 없음
				;

opt_dcl_list 			: declaration_list		{printf("opt_dcl_list - declaration_list\n");}
				|		{printf("opt_dcl_list - \n");}
				;

declaration_list 		: declaration		{printf("declaration_list - declaration\n");}
				| declaration_list declaration		{printf("declaration_list - declaration_list declaration\n");}
				;

// 조윤아

declaration 		: dcl_spec init_dcl_list TSEMI	
					{	printf("declaration - dcl_spec init_dcl_list TSEMI\n");
						con = 0;
						func =0;
						param = 0;
						array = 0;
						type = NONE;
					}
					| dcl_spec init_dcl_list error							
					{yyerrok; printf("declaration - dcl_spec init_dcl_list error\n");
					con = 0;
					func =0;
					param = 0;
					array = 0;
					type = NONE;
					ReportError(missing_semi);}	// 오류 - 세미콜론 없음
					;

init_dcl_list 		: init_declarator	{printf("init_dcl_list - init_declarator\n");}				
					| init_dcl_list TCOMMA init_declarator		{printf("init_dcl_list - init_dcl_list TCOMMA init_declarator\n");}			
					| init_dcl_list init_declarator							{yyerrok; printf("init_dcl_list - init_dcl_list init_declarator\n"); 
															ReportError(missing_comma); current_id -> error =1;}	// 오류 - 콤마 없음
					;

init_declarator 	: declarator		{printf("init_declarator - declarator\n");}					
		 			| declarator TASSIGN TNUMBER		{printf("init_declarator - declarator TASSIGN TNUMBER\n");}
					| declarator TEQUAL TNUMBER								{yyerrok; printf("init_declarator - declarator TEQUAL TNUMBER\n");
													ReportError(declaring_err);}	// 오류 - 변수 선언 에러
					| declarator TASSIGN TREAL	{printf("init_declarator - declarator TASSIGN TREAL\n");}
					| declarator TEQUAL TREAL								{yyerrok; printf("init_declarator - declarator TEQUAL TREAL\n");
															ReportError(declaring_err);}	// 오류 - 변수 선언 에러
					;

declarator 			: TIDENT												{changeHSTable(); printf("declarator - TIDENT\n");}
	     			| TIDENT TLSQUARE opt_number TRSQUARE					{array=1; changeHSTable(); printf("declarator - TIDENT TLSQUARE opt_number TRSQUARE\n");}
					| TIDENT TLSQUARE opt_number error						{yyerrok; printf("declarator - TIDENT TLSQUARE opt_number error\n");
															ReportError(missing_rsquare); }	// 오류 - 오른쪽 대괄호 없음
					;

opt_number 			: TNUMBER	{printf("opt_number - TNUMBER\n");}				
	     				|	{printf("opt_number - \n");}					
					;

opt_stat_list 		: statement_list OPT_STAT_LIST		{printf("opt_stat_list - statement_list OPT_STAT_LIST\n");}
		 			|		{printf("opt_stat_list - \n");}
					;

statement_list 		: statement %prec LOWER_THAN_OPT_STAT_LIST		{printf("statement_list - statemen\n");}				
			        | statement_list error 		{printf("statement_list - statement_list error\n");}
					| statement_list statement 	{printf("statement_list - statement_list statement\n");}		
					;

statement 			: compound_st				{printf("statement - compound_st\n");}
	   				| expression_st				{printf("statement - expression_st\n");}
	   				| if_st					{printf("statement - if_st\n");}	
	   				| while_st					{printf("statement - while_st\n");}
	   				| return_st				{printf("statement - return_st\n");}	
					;

expression_st 		: opt_expression TSEMI				{printf("expression_st - opt_expression TSEMI\n");}
					| expression error										{yyerrok; printf("expression_st - opt_expression TSEMI\n");
																	ReportError(missing_semi);}	// 오류 - 세미콜론 없음
					;


opt_expression 		: expression					{printf("opt_expression - expression\n");}
		 			|					{printf("opt_expression - \n");}	
					;

if_st 				: TIF TLPAREN expression TRPAREN statement %prec LOWER_THAN_ELSE 	{printf("if_st - TIF TLPAREN expression TRPAREN statement\n");}	
					| TIF TLPAREN expression TRPAREN statement TELSE statement	{printf("if_st - TIF TLPAREN expression TRPAREN statement TELSE statement\n");}
					| TIF TLPAREN expression error							{yyerrok; printf("if_st - TIF TLPAREN expression error\n");
															ReportError(missing_rparen);}		// 오류 - 오른쪽 괄호 없음
					| TIF TLPAREN TRPAREN error								{yyerrok; printf("if_st - TIF TLPAREN TRPAREN error\n");
																ReportError(missing_condition);}	// 오류 - 조건문 없음
					| TIF error                                             {yyerrok; printf("if_st - TIF error\n");
													ReportError(missing_lparen);}
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
