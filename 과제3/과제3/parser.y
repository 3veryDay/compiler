/*
보충설명용 ..
과제2 에서 report error할 때 text 자체를 보냇던 것과 다르게
error type 정의해서 void ReportError( ErrorType err) 이렇게 바꿔놨습니다
참고 코드의 PrintError(missing_funcheader) 대신에 위에 거 쓰면 되고
glob.h에 참고 코드랑 살짝 다르게 해서 에러 타입 정의해놨어요!! ㅎㅎ

*/


%{
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

/*yacc source for Mini C*/

%}

%nonassoc tlowerthanelse
%nonassoc telse

%token TEOF
%token TIDENT TNUMBER TFLOAT TCONST TELSE TIF TEIF TINT TRETURN TVOID TWHILE TFLOAT
%token TASSIGN TADDASSIGN TSUBASSIGN TMULASSIGN TDIVASSIGN TMODASSIGN
%token TNOT TAND TOR TEQUAL TNOTEQU TLESS TGREAT TLESSEQU TGREATEQU TINC TDEC
%token TADD TSUB TMUL TDIV TMOD TERROR
%token TLPAREN TRPAREN TLCURLY TRCURLY TLSQUARE TRSQUARE TCOMMA TSEMI 



%%
mini_c 			: translation_unit				{semantic(1);};
translation_unit 		: external_dcl				{semantic(2);}
			| translation_unit external_dcl			{semantic(3);};
external_dcl 		: function_def				{semantic(4);}
		  	| declaration				{semantic(5);};
function_def 		: function_header compound_st		{semantic(6);};
function_header 		: dcl_spec function_name formal_param	{semantic(7);};
dcl_spec 			: dcl_specifiers				{semantic(8);};
dcl_specifiers 		: dcl_specifier				{semantic(9);}
		 	| dcl_specifiers dcl_specifier			{semantic(10);};
dcl_specifier 		: type_qualifier				{semantic(11);}
			| type_specifier				{semantic(12);};
type_qualifier 		: tconst					{semantic(13);};
type_specifier 		: tint					{semantic(14);}
		 	| tvoid					{semantic(15);};
function_name 		: tident					{semantic(16);};
formal_param 		: '(' opt_formal_param ')' 			{semantic(17);};
opt_formal_param 		: formal_param_list				{semantic(18);}
		   	|					{semantic(19);};
formal_param_list 		: param_dcl				{semantic(20);}
		    	| formal_param_list ',' param_dcl 		{semantic(21);};
param_dcl 		: dcl_spec declarator			{semantic(22);};
compound_st 		: '{' opt_dcl_list opt_stat_list '}' 		{semantic(23);};
opt_dcl_list 		: declaration_list				{semantic(24);}
			|					{semantic(25);};
declaration_list 		: declaration				{semantic(26);}
			| declaration_list declaration 			{semantic(27);};


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
					(missing_semi);}
					;

init_dcl_list 		: init_declarator				
					| init_dcl_list TCOMMA init_declarator				
					| init_dcl_list init_declarator							{yyerrok; PrintError(missing_comma); current_id -> error =1;}
					;

init_declarator 	: declarator						
		 			| declarator TASSIGN TNUMBER
					| declarator TEQUAL TNUMBER								{yyerrok; PrintError(declaring_err);}
					| declarator TASSIGN TREALNUMBER
					| declarator TEQUAL TREALNUMBER								{yyerrok; PrintError(declaring_err);}
					;

declarator 			: TIDENT												{changeHSTable(); }
	     			| TIDENT TLBRACKET opt_number TRBRACKET					{array=1; changeHSTable(); }
					| TIDENT TLBRACKET opt_number error						{yyerrok; PrintError(missing_lbracket); }
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
					| expression error										{yyerrok; PrintError(missing_semi);}
					;


opt_expression 		: expression					
		 			|						
					;

if_st 				: TIF TLPAREN expression TRPAREN statement %prec LOWER_THAN_ELSE 		
					| TIF TLPAREN expression TRPAREN statement TELSE statement
					| TIF TLPAREN expression error							{yyerrok; PrintError(missing_sbracket);}
					| TIF TLPAREN TRPAREN error								{yyerrok; PrintError(missing_condition);}
					| TIF error                                             {yyerrok; PrintError(missing_sbracket);}
					;

while_st 			: TWHILE TLPAREN expression TRPAREN TLBRACE statement TRBRACE
					| TWHILE TLPAREN expression TRPAREN TLBRACE statement error 			{yyerrok; PrintError(missing_mbracket);}
					| TWHILE TLPAREN expression error						{yyerrok; PrintError(missing_sbracket);}
					| TWHILE TLPAREN TRPAREN error							{yyerrok; PrintError(missing_condition);}
					| TWHILE error                                        {yyerrok; PrintError(missing_sbracket);}
					;

return_st 			: TRETURN opt_expression TSEMI
					| TRETURN opt_expression error							{yyerrok; PrintError(missing_semi);}
					;

expression 			: assignment_exp;

assignment_exp 		: logical_or_exp				
					| unary_exp TASSIGN assignment_exp 		
					| unary_exp TADDASSIGN assignment_exp 	
					| unary_exp TSUBASSIGN assignment_exp 	
					| unary_exp TMULASSIGN assignment_exp 	
					| unary_exp TDIVASSIGN assignment_exp 	
					| unary_exp TMODASSIGN assignment_exp 	
					| unary_exp TASSIGN										{yyerrok; PrintError(wrong_assign);}
					| unary_exp TADDASSIGN									{yyerrok; PrintError(wrong_assign);}
					| unary_exp TSUBASSIGN				 					{yyerrok; PrintError(wrong_assign);}
					| unary_exp TMULASSIGN				 					{yyerrok; PrintError(wrong_assign);}
					| unary_exp TDIVASSIGN				 					{yyerrok; PrintError(wrong_assign);}
					| unary_exp TMODASSIGN				 					{yyerrok; PrintError(wrong_assign);}
					;

logical_or_exp 		: logical_and_exp				
					| logical_or_exp TOR logical_and_exp 	
					| logical_or_exp TOR error								{yyerrok; PrintError(missing_operand);}
					;

logical_and_exp		: equality_exp					
		 			| logical_and_exp TAND equality_exp 
					| logical_and_exp TAND error							{yyerrok; PrintError(missing_operand);}
					;

equality_exp 		: relational_exp				
					| equality_exp TEQUAL relational_exp 	
					| equality_exp TNOTEQU relational_exp 	
					| equality_exp TEQUAL error								{yyerrok; PrintError(missing_operand);}
					| equality_exp TNOTEQU error							{yyerrok; PrintError(missing_operand);}
					;




//

relational_exp 		: additive_exp 				{semantic(68);}
			| relational_exp '>' additive_exp 		{semantic(69);}
			| relational_exp '<' additive_exp 		{semantic(70);}
			| relational_exp tgreate additive_exp 		{semantic(71);}
			| relational_exp tlesse additive_exp 		{semantic(72);};
additive_exp 		: multiplicative_exp				{semantic(73);}
			| additive_exp '+' multiplicative_exp 		{semantic(74);}
			| additive_exp '-' multiplicative_exp 		{semantic(75);};
multiplicative_exp 		: unary_exp				{semantic(76);}
		    	| multiplicative_exp '*' unary_exp 		{semantic(77);}
		    	| multiplicative_exp '/' unary_exp 		{semantic(78);}
		    	| multiplicative_exp '%' unary_exp 		{semantic(79);};
unary_exp 		: postfix_exp				{semantic(80);}
	   		| '-' unary_exp				{semantic(81);}
	   		| '!' unary_exp				{semantic(82);}
	   		| tinc unary_exp				{semantic(83);}
	   		| tdec unary_exp				{semantic(84);};
postfix_exp 		: primary_exp				{semantic(85);}
	      		| postfix_exp '[' expression ']' 		{semantic(86);}
	      		| postfix_exp '(' opt_actual_param ')' 		{semantic(87);}
	      		| postfix_exp tinc				{semantic(88);}
	      		| postfix_exp tdec				{semantic(89);};
opt_actual_param 		: actual_param				{semantic(90);}
		  	|					{semantic(91);};
actual_param 		: actual_param_list				{semantic(92);};
actual_param_list 		: assignment_exp				{semantic(93);}
		   	| actual_param_list ',' assignment_exp 		{semantic(94);};
primary_exp 		: tident					{semantic(95);}
	     		| tnumber				{semantic(96);}
	     		| '(' expression ')'				{semantic(97);};
%%

void semantic(int n)
{	
	printf("reduced rule number = %d\n",n);
}
