%{
/* scanner.l_ lexical analyzer for the MiniC
programmer - 조윤아
date - 2024/04/28
*/
#include <stdio.h>
#include "tn.h"
#include "glob.h"
extern int SymbolTable();	// ident가 인식된 경우 symbol table에 저장 및 처리하기 위한 함수 불러오기
extern void ReportError(ErrorType err);	// 에러가 인식된 경우 에러 처리를 위한 함수 불러오기
%}

letter  [a-zA-Z_]
digit  [0-9]

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
[ \t]	;
\n	lineno ++;
{letter}({letter}|{digit})*  {
	if (yyleng <= 12) {
		SymbolTable();	
		return(TIDENT); 	// 길이가 12자보다 짧으면 ident로 인식
	} else {
		 err = long_ident;
		 ReportError(err);	// 그렇지 않으면 에러 처리, Illegal Identifier, Over 12 characters
	}
}
{digit}({letter}|{digit})*{letter}({letter}|{digit})*	{err = digit_ident; ReportError(err);}  // 숫자로 시작하는 identifier 에러 처리
{digit}+  return(TNUMBER);
{digit}+"."{digit}+  return(TFLOAT);

.  {err = ill_symbol; ReportError(err);}  // 인식되지 않는 문자의 경우 에러 처리
%%
int yywrap() {
	return 1;
}
