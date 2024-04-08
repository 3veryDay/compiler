%{
#include <stdio.h>
#include <stdlib.h>
enum tnumber {TEOF, TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE, TEQUAL, TNOTEQU, TLESSE, TGREATE, TAND, TOR, TINC, TDEC, TADDASSIGN, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN, TIDENT, TNUMBER};
%}
%%
"const"	  return(TCONST);
"else"		return(TELSE);
"if"		return (TIF);
"int"		return(TINT);
"return"	return(TRETURN);
"void"		return(TVOID);
"while"		return(TWHILE);
"=="	return(TEQUAL);
"!="	return(TNOTEQU);
"<="	return(TLESSE);
">="	return(TGREATE);
"&&"	return(TAND);
"||"	return(TOR);
"++"	return(TINC);
"--"	return(TDEC);
"+="	return(TADDASSIGN);
"-="	return(TSUBASSIGN);
"*="	return(TMULASSIGN);
"/="	return(TDIVASSIGN);
"%="	return(TMODASSIGN);
[A-Za-z_][A-Za-z0-9_]*	return(TIDENT);
[1-9][0-9]*|0([0-7]+|(x|X)[0-9A-Fa-f]*)?	return(TNUMBER);
"/*"([^*]|\*+[^*/])*\**"*/"	;
"//".*	;
[ \t\n]	;
・	return(yytext[0]);
%%
void main() {
	enum tnumber tn; /* token number */
	while ((tn=yylex()) != TEOF) {
		switch (tn) {
			case TCONST:	printf("TCOSNT\t\tconst\n"); break;
			case TELSE:	printf("TELSE\t\telse\n"); break;
			case TIF:		printf("TIF\t\tif\n");break;
			case TINT:	printf("TINT\tint\n"); break;
			case TRETURN:	printf("TRETURN\treturn\n"); break;
			case TVOID:	printf("TVOID\tvoid\n");break;
			case TWHILE:	printf("TWHILE\twhile\n"); break;
			case TEQUAL:	printf("TEQUAL\t==\n"); break;
			case TNOTEQU:	printf("TNOTEQU\t!=\n"); break;
			case TLESSE:	printf("TLESSE\t<=\n"); break;
			case TGREATE:	printf("TGREATE\t>=\n"); break;
			case TAND:	printf("TAND\t&&\n"); break;
			case TOR:	printf("TOR\t\tor\n"); break;
			case TINC:	printf("TINC\t\tinc\n"); break;
			case TDEC:	printf("TDEC\t\tdec\n"); break;
			case TADDASSIGN:	printf("TADDASSIGN\taddassign\n"); break;
			case TSUBASSIGN:	printf("TSUBASSIGN\tsubassign\n"); break;
			case TMULASSIGN:	printf("TMULASSIGN\tmulassign\n"); break;
			case TDIVASSIGN:	printf("TDIVASSIGN\tdivassign\n"); break;
			case TMODASSIGN:	printf("TMODASSIGN\mulassign\n"); break;
			case TIDENT:	printf("TIDENT\t%s\n", yytext); break;
			case TNUMBER:	printf("TNUMBER\t%s\n", yytext) ; break;
		}
	}
}
int yywrap() {
	printf(" End of Lex\n");
	printf(" 2171047 \n2176143 \n2176365 \n2176368 \n");
	return 1;
}
