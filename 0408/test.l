%{
#include <stdio.h>
#include <stdlib.h>
enum tnumber {TCONST, TELSE, TIF, TINT, TRETURN, TVOID, TWHILE, TEQUAL, TNOTEQU, TLESS, TGREATE, TAND, TOR, TINC, TDEC, TADDASSIGN, TSUBASSIGN, TMULASSIGN, TDIVASSIGN, TMODASSIGN, TIDENT, TNUMBER};
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

"<="	return(TLESS);

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

"/*"(［^*］|\*+[^*/]）*\**"*/"	;

"//".*	;

[ \t\n]	;

・	return(yytext[0]);

%%


void main() {
	enum tnumber tn; /* token number */
	//printf(" Start of Lex\n"); 없어짐
	while ((tn=yylex()) != TEOF) {
		switch (tn) {
			case TCONST 	: printf("TCOSNT\t\tconst"); break;
			case TELSE 	: printf("TELSE\t\telse"); break;
			case TIF		: printf("TIF\t\tif");break;
			case TINT	: printf("TINT\tint); break;
			case TRETURN	:printf("TRETURN\treturn); break;
			case TVOID	:printf("TVOID\tvoid);break;
			case TWHILE	:printf("TWHILE\twhile); break;
			case TEQUAL	:printf("TEQUAL\t=="); break;
			case TNOTEQU	:printf("TNOTEQU\t!="); break;
			case TLESSE 	:printf("TLESSE\t<="); break;
			case TGREATE	:printf("TGREATE\t>="); break;
			case TAND	:printf("TAND\t&&"); break;
			case TOR		:printf("TOR\t\tor"); break;
			case TINC	:printf("TINC\t\tinc "); break;
			case TDEC	:printf("TDEC\t\tdec  "); break;
			case TADDASSIGN	:printf("TADDASSIGN\taddassign"); break;
			case TSUBASSIGN	:printf("TSUBASSIGN\tsubassign"); break;
			case TMULASSIGN	:printf("TMULASSIGN\tmulassign"); break;
			case TDIVASSIGN	:printf("TDIVASSIGN\tdivassign"); break;
			case TMODASSIGN	:printf("TMODASSIGN\mulassign"); break;


			case TIDENT 	:printf("TIDENT\t%s", yytext ); break;
			case TNUMBER 	:printf("TNUMBER\t%s", yytext) ; break;

		}
	}
}
int yywrap() {
	printf(" End of Lex\n");
	printf(" 2171047 조윤아\n2176143 박소현\n2176365 조은혜\n2176368 지현서\n);
	return 1;
}
