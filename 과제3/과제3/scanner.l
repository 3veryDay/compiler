%{
/* scanner.l_ lexical analyzer for the MiniC
programmer - 조윤아
date - 2024/04/28
*/
#include <stdio.h>
#include "tn.h"  /* token name definition */
extern void symtable(char *yytext);	// ident가 인식된 경우 symbol table에 저장 및 처리하기 위한 함수 불러오기
extern void report_error(int i, char *s);	// 에러가 인식된 경우 에러 처리를 위한 함수 불러오기

%}
letter  [a-zA-Z_]
digit  [0-9]
%option yylineno
%%
"//".*  ;		// 주석은 pass
"const"  return(TCONST);
"else"  return(TELSE);
"if"  return(TIF);
"int"  return(TINT);
"return"  return(TRETURN);
"void"  return(TVOID);
"while"  return(TWHILE);
"+"  return(TADD);
"-"   return(TSUB);
"*"  return(TMUL);
"/"  return(TDIV);
"%"  return(TMOD);
"="  return(TASSIGN);
"+="  return(TADDASSIGN);
"-="  return(TSUBASSIGN);
"*="  return(TMULASSIGN);
"/="  return(TDIVASSIGN);
"%="  return(TMODASSIGN);
"!"  return(TNOT);
"&&"  return(TAND);
"||"  return(TOR);
"=="  return(TEQUAL);
"!="  return(TNOTEQU);
"<"  return(TLESS);
">"  return(TGREAT);
"<="  return(TLESSEQU);
">="  return(TGREATEQU);
"++"  return(TINC);
"--"  return(TDEC);
"(" return(TLPAREN);
")" return(TRPAREN);
"{" return(TLBRACE);
"}" return(TRBRACE);
"[" return(TLSQUARE);
"]" return(TRSQUARE);
"," return(TCOMMA);
";"  return(TSEMI);
" "	return(TBLANK);		// 공백 정의
\t	return(TTAB);		// 탭 정의
\n	return(TNEWLINE);	// 엔터 정의의
{letter}({letter}|{digit})*  {
	if (yyleng <= 12) {
		symtable(yytext);	
		return(TIDENT); 	// 길이가 12자보다 짧으면 ident로 인식
	} else {
		 report_error(yylineno, yytext);	// 그렇지 않으면 에러 처리, Illegal Identifier, Over 12 characters
	}
}
{digit}({letter}|{digit})*{letter}({letter}|{digit})*	report_error(yylineno, yytext);		// 숫자로 시작하는 identifier 에러 처리
{digit}+  return(TNUMBER);
{digit}+"."{digit}+  return(TFLOAT);

.  report_error(yylineno, yytext);	// 인식되지 않는 문자의 경우 에러 처리
%%
int yywrap() {
	return 1;
}
