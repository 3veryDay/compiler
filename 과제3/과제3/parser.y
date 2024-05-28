/*
보충설명용 ..
과제2 에서 report error할 때 text 자체를 보냇던 것과 다르게
error type 정의해서 void ReportError( ErrorType err) 이렇게 바꿔놨습니다
참고 코드의 PrintError(missing_funcheader) 대신에 위에 거 쓰면 되고
glob.h에 참고 코드랑 살짝 다르게 해서 에러 타입 정의해놨어요!! ㅎㅎ

기타 HStable 설정 (con, func 등) 은 일단 그대로 뒀습니다

yylineno 는 parser에선 사용 불가해서 glob.h에 lineno 정의하고 scanner.l에서 처리하는 걸로 바꿨어요
*/


%{
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

/*yacc source for Mini C*/

int con = 0;
int func = 0;
int param = 0;
int array = 0;
int type = NONE;

extern int yylex();
extern yyerror(char* s);
void changeHSTable();
%}

%nonassoc LOWER_THAN_ELSE
%nonassoc TELSE
%nonassoc LOWER_THAN_OPT_STAT_LIST	
%nonassoc OPT_STAT_LIST

%token TEOF
%token TIDENT TNUMBER TFLOAT TCONST TELSE TIF TEIF TINT TRETURN TVOID TWHILE TFLOAT
%token TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TAND TOR TEQUAL TNOTEQU TLESS TGREAT TLESSEQU TGREATEQU TINC TDEC
%token TADD TSUB TMUL TDIV TMOD TERROR
%token TLPAREN TRPAREN TLCURLY TRCURLY TLSQUARE TRSQUARE TCOMMA TSEMI 



%%
mini_c 			: translation_unit
				;

translation_unit 		: external_dcl
				| translation_unit external_dcl
				;

external_dcl 			: function_def
		  		| declaration
				| TIDENT TSEMI						{yyerrok;
												ReportError(missing_semi);}
				| TIDENT error
				;

function_def 		: function_header compound_st
				| function_header error					{yyerrok;
												ReportError(missing_semi);}
				| error compound_st					{yyerrok;
												ReportError(missing_funcheader);}
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

formal_param 		: TLPARAN opt_formal_param TRPAREN
				| TLPAREN opt_formal_param error			{yyerrok;
												ReportError(missing_paren);)}
				;

opt_formal_param 		: formal_param_list						{param = 1;
												changeHSTable();
												func = 0;
												con = 0;
												param = 0;
												array = 0;
												type = NONE;}
		   		|								{param = 0;}
				;

formal_param_list 		: param_dcl							{param = 1;
												changeHSTable();}
		    		| formal_param_list TCOMMA param_dcl
				| formal_param_list TCOMMA error			{yyerrok;
												ReportError(missing_comma);}
				| formal_param_list param_dcl				{yyerrok;
												ReportError(missing_comma);}
				;

param_dcl 			: dcl_spec declarator					{param = 1;
												changeHSTable();}
				;

compound_st 		: TLCURLY opt_dcl_list opt_stat_list TRCURLY
				| TLCURLY opt_dcl_list opt_stat_list error		{yyerrok;
												ReportError(missing_curly);}
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
					ReportError(missing_semi);}
					;

init_dcl_list 		: init_declarator				
					| init_dcl_list TCOMMA init_declarator				
					| init_dcl_list init_declarator							{yyerrok; ReportError(missing_comma); current_id -> error =1;}
					;

init_declarator 	: declarator						
		 			| declarator TASSIGN TNUMBER
					| declarator TEQUAL TNUMBER								{yyerrok; ReportError(declaring_err);}
					| declarator TASSIGN TFLOAT
					| declarator TEQUAL TFLOAT								{yyerrok; ReportError(declaring_err);}
					;

declarator 			: TIDENT												{changeHSTable(); }
	     			| TIDENT TLSQUARE opt_number TRSQUARE					{array=1; changeHSTable(); }
					| TIDENT TLSQUARE opt_number error						{yyerrok; ReportError(missing_square); }
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
					| expression error										{yyerrok; ReportError(missing_semi);}
					;


opt_expression 		: expression					
		 			|						
					;

if_st 				: TIF TLPAREN expression TRPAREN statement %prec LOWER_THAN_ELSE 		
					| TIF TLPAREN expression TRPAREN statement TELSE statement
					| TIF TLPAREN expression error							{yyerrok; ReportError(missing_paren);}
					| TIF TLPAREN TRPAREN error								{yyerrok; ReportError(missing_condition);}
					| TIF error                                             {yyerrok; ReportError(missing_paren);}
					;

while_st 			: TWHILE TLPAREN expression TRPAREN TLCURLY statement TRCURLY
					| TWHILE TLPAREN expression TRPAREN TLCURLY statement error 			{yyerrok; ReportError(missing_curly);}
					| TWHILE TLPAREN expression error						{yyerrok; ReportError(missing_paren);}
					| TWHILE TLPAREN TRPAREN error							{yyerrok; ReportError(missing_condition);}
					| TWHILE error                                        {yyerrok; PrintError(missing_paren);}
					;

return_st 			: TRETURN opt_expression TSEMI
					| TRETURN opt_expression error							{yyerrok; ReportError(missing_semi);}
					;

expression 			: assignment_exp;

assignment_exp 		: logical_or_exp				
					| unary_exp TASSIGN assignment_exp 		
					| unary_exp TADDASSIGN assignment_exp 	
					| unary_exp TSUBASSIGN assignment_exp 	
					| unary_exp TMULASSIGN assignment_exp 	
					| unary_exp TDIVASSIGN assignment_exp 	
					| unary_exp TMODASSIGN assignment_exp 	
					| unary_exp TASSIGN										{yyerrok; ReportError(wrong_assign);}
					| unary_exp TADDASSIGN									{yyerrok; ReportError(wrong_assign);}
					| unary_exp TSUBASSIGN				 					{yyerrok; ReportError(wrong_assign);}
					| unary_exp TMULASSIGN				 					{yyerrok; ReportError(wrong_assign);}
					| unary_exp TDIVASSIGN				 					{yyerrok; ReportError(wrong_assign);}
					| unary_exp TMODASSIGN				 					{yyerrok; ReportError(wrong_assign);}
					;

logical_or_exp 		: logical_and_exp				
					| logical_or_exp TOR logical_and_exp 	
					| logical_or_exp TOR error								{yyerrok; ReportError(missing_operand);}
					;

logical_and_exp		: equality_exp					
		 			| logical_and_exp TAND equality_exp 
					| logical_and_exp TAND error							{yyerrok; ReportError(missing_operand);}
					;

equality_exp 		: relational_exp				
					| equality_exp TEQUAL relational_exp 	
					| equality_exp TNOTEQU relational_exp 	
					| equality_exp TEQUAL error								{yyerrok; ReportError(missing_operand);}
					| equality_exp TNOTEQU error							{yyerrok; ReportError(missing_operand);}
					;



/**********************************************************************************/
//지현서 담당 부분  

relational_exp 		: additive_exp 				
			| relational_exp TGREAT additive_exp 		
			| relational_exp TLESS additive_exp 		
			| relational_exp TGREATEQU additive_exp 	
			| relational_exp TLESSEQU additive_exp 	
			| relational_exp TGREAT error							{yyerrok; ReportError(missing_operand);}
			| relational_exp TLESS  error							{yyerrok; ReportError(missing_operand);} 		
			| relational_exp TGREATEQU error						{yyerrok; ReportError(missing_operand);}
			| relational_exp TLESSEQU error							{yyerrok; ReportError(missing_operand);}
			;

additive_exp 		: multiplicative_exp				
			| additive_exp TADD multiplicative_exp 
			| additive_exp TSUB multiplicative_exp 	
			| additive_exp TADD error							{yyerrok; ReportError(missing_operand);}
			| additive_exp TSUB error							{yyerrok; ReportError(missing_operand);}
			;

multiplicative_exp 	: unary_exp					
		    	| multiplicative_exp TMUL unary_exp 		
		    	| multiplicative_exp TDIV unary_exp 		
		    	| multiplicative_exp TMOD unary_exp 		
			| multiplicative_exp TMUL error							{yyerrok; ReportError(missing_operand);}
		    	| multiplicative_exp TDIV error							{yyerrok; ReportError(missing_operand);}
		    	| multiplicative_exp TMOD error							{yyerrok; ReportError(missing_operand);}
			;

unary_exp 		: postfix_exp					
	   		| TSUB unary_exp				
	   		| TNOT unary_exp				
	   		| TINC unary_exp				
	   		| TDEC unary_exp				
			;

postfix_exp 		: primary_exp
	      		| postfix_exp TLCURLY expression TRCURLY
			| postfix_exp TLCURLY expression error						{yyerrok; ReportError(missing_curly);}
	      		| postfix_exp TLPAREN opt_actual_param TRPAREN
			| postfix_exp TLPAREN opt_actual_param error					{yyerrok; ReportError(missing_paren);}
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
			| TFLOAT
	     		| TLPAREN expression TRPAREN
			| TLPAREN expression error							{yyerrok; ReportError(missing_paren);}
			;
%%

void changeHSTable(){
	current_id->isConst= con;
	current_id->isFunction= func;
	current_id->isParam= param;
	current_id->isArray= array;
	current_id->spec= type;
}
