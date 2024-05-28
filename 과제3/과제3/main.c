#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "tn.h" 
#include "glob.h" 

extern yylex();
extern char *yytext;
void printHT();

void main()
{
    cLine = 1;
	printf("******************************[[MiniC parsing begins]]\n");
	yyparse();
	printf("[[Parsing Ends]]**************************************\n");
	printf("\n\n%d error(s) detected\n\n", cErrors);
	printf("====================[[Hash Table]]====================\n");

	printHT();
}


void printHT(){
	HTpointer here;
	int i, j;

	for (i = 0; i < HTsize; i++) {
		if (HT[i] != NULL) {
			here = HT[i];			
			while (here != NULL) {
				printf("HashCode %d:	 ", i);
				j = here->index;
				while (ST[j] != '\0') {
					printf("%c", ST[j++]);
				}
				if (here->spec == NONE) {
					printf(" / not defined ");
				}
				else if (!here->error) {
					if (here->isFunction) { 
						switch (here->spec)
						{
						case  INT:
							printf(" / Return Type: Integer ");
							break;
						case  VOID:
							printf(" / Return Type: Void ");
							break;
						case  FLOAT:
							printf(" / Return Type: Float ");
							break;
						}
						printf("Function ");
					}
					else if (!here->isFunction) { 
						if (here->isConst) {
							printf(" / Const ");
						}
						switch (here->spec)
						{
						case  INT:
							printf(" / Integer ");
							break;
						case  FLOAT:
							printf(" / Float ");
							break;
						}
						if (here->isArray) { // Array
							printf("Array ");
						}
						else {
							printf("Scalar ");
						}
						if (here->isParam) {
							printf("Parameter ");
						}

						printf("Variable ");

				}
				
				}
				else if(here->error) {
					printf(" / not defined ");
				}
				printf("/ Linenum: %d \n", here->linenum);
				here = here->next;
			}
		}
	}
	
}
