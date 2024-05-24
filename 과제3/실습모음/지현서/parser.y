{%
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

#include "glob.h"

/********************************************************************************/
/********modified MINIC에 맞게 변형 **********************************************/
int type_int = 0;
int type_void = 0;
int type_char = 0;
int type_float = 0;
int type_double = 0;
int type_long = 0;
int type_short = 0;


void line(int);
extern printError();
extern yylex();
extern yyerror(s);
%}

%token TIDEN TNUMBER TCONST TELSE TIF TINT TRETURN TVOID TWHILE
%token TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TOR TAND TEQUAL TNOTEQU TGREAT TLESS TGREATE TLESSE TINC TDEC
%token TPLUS TMINUS TMULTIPLY TDIVIDE TMOD TNOT TASSIGN TLPAREN TRPAREN TCOMMA TSEMICOLON
%token TLBRACKET TRBRACKET TLBRACE TRBRACE
%nonassoc LOWER_THEN_ELSE
%nonassoc TELSE

%%


mini_c                : translation_unit
                      ;
translation_unit      :external_dcl
                      | translation_unit external_dcl
                      ;
external_dcl          : function_def
                      | declaration
                      | TIDEN TSEMICOLON
                      | TIDEN error
                      {
                         //괜찮은 에러, 그래서 일단 오케이 하고 넘어가
                         // 근데 출력은 해! 뭐에 대해서 에러가 나왔는지
                          yyerrok;
                          printError(wrong_st);
                          // error - wrong statement
                      }
                      ;
function_def          : function_header comound_st
                      | function_header TSEMICOLON
                      | function_header error //비정상적인 삼수 정의
                      {
                           /*에러 발생시 type 수정을 위해 defualt값 '0'세팅*/
                           /* identifier about parse error */
                          look_tmp -> type = 0;
                          yyerrok;
                          /* error - wrong function defintion */
                          printError(wrong_funcdef);
                       }
                       ;
function_header        : dcl_spec funtion_name formal_param
                       ;
dcl_spec               : dcl_specifiers;
                       ;
dcl_specifiers         : dcl_specifier
                       | dcl_specifiers dcl_specifier
                       ;
dcl_specifier          : type_qualifier
                       | type_specifier
                       ;

type_qualifier         : TCONSt
                       ;
//여기서 modified MINI C에 맞게 추가해야됨!!
/*****************************************************************************************************************/
type_specifier         : TINT { type_int = 1; }
                       | TVOID { type_void = 1; }
                       | TCHAR { type_char = 1; }
                       | TFLOAT { type_float = 1; }
                       | TDOUBLE { type_double = 1; }
                       | TLONG { type_long = 1; }
                       | TSHORT { type_short = 1; }
                       ;
function_name          : TIDEN
                        { /* identifier about parse error or not definced identifier/function*/
                             if(look_id -> type==0 || look_id -> type==5)
                            //부분의 코드는 식별자가 함수명인지 확인하고, 해당 식별자를 함수로 설정하는 로직을 포함하고 있습니다                               
                              {
                                 look_id -> type = 4;
                                 type_int = 0;
                                 type_void = 0;
                                 **type_char = 0;**
                                 **type_float = 0;**
                                 **type_double = 0;**
                                 **type_long = 0;**
                                 **type_short = 0;**
                                 look_tmp = look_id;
                               }
                       }
                       ;
formal_param           : TLPAREN opt_formal_param TRPAREN
                       ;
opt_formal_param       : formal_param_list
                       |
                       ;
formal_param_list      : param_dcl
                       |formal_param_list TCOMMA param_dcl
                       ;

param_dcl 		         : dcl_spec declarator
                       ;
compound_st 		       : '{' opt_dcl_list opt_stat_list '}'
                       ;
opt_dcl_list 		       : declaration_list
                       ;
declaration_list 	     : declaration
			                 | declaration_list declaration
                       ;
declaration 		       : dcl_spec init_dcl_list ';'
                       ;
init_dcl_list 		     : init_declarator

                       | init_dcl_list ',' init_declarator
                       ;
init_declarator 	     : declarator
                       | declarator '=' tnumber
                       ;
declarator 		         : tident
                       | tident '[' opt_number ']'
                       ;
opt_number 		         : tnumber
                       ;
opt_stat_list 		     : statement_list
                       ;
statement_list 		     : statement
                       | statement_list statement
                       ;
statement 		         : compound_st
                       | expression_st			{semantic(42);}
                       | if_st					{semantic(43);}
                       | while_st				{semantic(44);}
                       | return_st				{semantic(45);}
                       ;
expression_st 	       : opt_expression ';'
                       ;
opt_expression 	       : expression	
                       |;
if_st 		           	: tif '(' expression ')' statement
                       | tif '(' expression ')' statement telse statement
                       ;
while_st 		           : twhile '(' expression ')' statement;
return_st 		         : treturn opt_expression ';';
expression 		         : assignment_exp;
assignment_exp        	: logical_or_exp
                       | unary_exp '=' assignment_exp 	
                       | unary_exp taddAssign assignment_exp 
                       | unary_exp tsubAssign assignment_exp 
                       | unary_exp tmulAssign assignment_exp 
                       | unary_exp tdivAssign assignment_exp 	
                       | unary_exp tmodAssign assignment_exp 
                       ;
logical_or_exp 	       : logical_and_exp
                       | logical_or_exp tor logical_and_exp
                       ;
logical_and_exp 	     : equality_exp	
                       | logical_and_exp tand equality_exp;
equality_exp 		       : relational_exp
                       | equality_exp tequal relational_exp 
                       | equality_exp tnotequ relational_exp
                       ;
relational_exp 	       : additive_exp 	
                       | relational_exp '>' additive_exp 
                       | relational_exp '<' additive_exp 
                       | relational_exp tgreate additive_exp 
                       | relational_exp tlesse additive_exp 	
                       ;
additive_exp 		: multiplicative_exp	
                       | additive_exp '+' multiplicative_exp 
                       | additive_exp '-' multiplicative_exp
                       ;
multiplicative_exp 	: unary_exp			
                       | multiplicative_exp '*' unary_exp 	
                       | multiplicative_exp '/' unary_exp 	
                       | multiplicative_exp '%' unary_exp 	
                       ;
unary_exp 		: postfix_exp		
                       | '-' unary_exp			
                       | '!' unary_exp			
                       | tinc unary_exp		
                       | tdec unary_exp		
                       ;
postfix_exp 		: primary_exp				
                       | postfix_exp '[' expression ']' 	
                       | postfix_exp '(' opt_actual_param ')' 
                       | postfix_exp tinc			
                       | postfix_exp tdec		
                       ;
opt_actual_param 	     : actual_param;
actual_param 	         : actual_param_list;		
actual_param_list 	   : assignment_exp;	
                       | actual_param_list ',' assignment_exp                        
                       ;
primary_exp 		: tident			
                       | tnumber				
                       | '(' expression ')'			
                       ;
%%

void semantic(int n)
{	
	printf("reduced rule number = %d\n",n);
}

