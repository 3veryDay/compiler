%{
#include <stdio.h>
#include <stdlib.h>
enum tnumber { TINT, TEOF, TIDEN, TNUM, TASSIGN, TADD, TSEMI, TBEGIN, TEND};
%}
letter [a-zA-Z_]
digit [0-9]
%%
"{"	return(TBEGIN);
"}"	return(TEND);
int	return(TINT);
{letter}({letter}|{digit})*	return(TIDEN);
":="	return(TASSIGN);
"+"	return(TADD);
{digit}+	return(TNUM);
";"	return(TSEMI);
[ \t\n]	;
%%
void main() {
	enum tnumber tn; /* token number */
	printf(" Start of Lex\n");
	while ((tn=yylex()) != TEOF) {
		switch (tn) {
      case TINT    :printf("Integer"); break;
			case TBEGIN : printf("Begin\n"); break;
			case TEND : printf("End\n"); break;
			case TIDEN : printf("%c", yytext); break;
			case TASSIGN : printf(" := "); break;
			case TADD : printf(" + "); break;
			case TNUM : printf("%d ", atoi(yytext)); break;
			case TSEMI : printf(";"); break;
		}
	}
}
int yywrap() {
	printf(" End of Lex\n");
	printf(" 2171047 조윤아\n2176143 박소현\n2176365 조은혜\n2176368 지현서\n");
	return 1;
}
