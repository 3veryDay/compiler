#include <stdio.h>
#include <stdlib.h>
#include "tn.h"
extern yylex();
extern char *yytext;
void main() {
	enum tnumber tn; /* token number */
	while ((tn=yylex()) != TEOF) {
		switch (tn) {
			case TCONST:		printf("TCOSNT\t\tconst\n"); break;
			case TELSE:		printf("TELSE\t\telse\n"); break;
			case TIF:			printf("TIF\t\tif\n");break;
			case TINT:		printf("TINT\tint\n"); break;
			case TRETURN:		printf("TRETURN\treturn\n"); break;
			case TVOID:		printf("TVOID\tvoid\n");break;
			case TWHILE:		printf("TWHILE\twhile\n"); break;
			case TEQUAL:		printf("TEQUAL\t==\n"); break;
			case TNOTEQU:		printf("TNOTEQU\t!=\n"); break;
			case TLESSE:		printf("TLESSE\t<=\n"); break;
			case TGREATE:		printf("TGREATE\t>=\n"); break;
			case TAND:		printf("TAND\t&&\n"); break;
			case TOR:		printf("TOR\t\tor\n"); break;
			case TINC:		printf("TINC\t\tinc\n"); break;
			case TDEC:		printf("TDEC\t\tdec\n"); break;
			case TADDASSIGN:		printf("TADDASSIGN\taddassign\n"); break;
			case TSUBASSIGN:		printf("TSUBASSIGN\tsubassign\n"); break;
			case TMULASSIGN:		printf("TMULASSIGN\tmulassign\n"); break;
			case TDIVASSIGN:		printf("TDIVASSIGN\tdivassign\n"); break;
			case TMODASSIGN:	printf("TMODASSIGN\tmodassign\n"); break;
			case TIDENT:		printf("TIDENT\t%s\n", yytext); break;
			case TNUMBER:		printf("TNUMBER\t%s\n", yytext) ; break;
		}
	}
}
