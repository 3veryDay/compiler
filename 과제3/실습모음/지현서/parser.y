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
                             if(look_id -> type=0 || look_id -> type=5)
                            //부분의 코드는 식별자가 함수명인지 확인하고, 해당 식별자를 함수로 설정하는 로직을 포함하고 있습니다                               
                              {
                                 look_id -> type=4 ;
                                 type_int= 0 ;
                                 type_void = 0;
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

/** 이 후에 param_dcl도 있어야 함.**/
