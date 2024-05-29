/*
 * symtable.c - Symbol table & Hash table management
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "glob.h"

void ReportError(ErrorType err);
extern char *yytext;
extern int yyleng;

/*
 * computeHS() - Compute the hash code of identifier by summing the ordinal values of 
 *             its charactors an then taking the sum modulo the size of HT
 */
void ComputeHS(int nid, int nfree)
{
	int code, i;    // ASCII code's sum if identifier
	code = 0;
	for (i = nid; i < nfree - 1; i++) {
		code += (int)ST[i];
	}
	hashcode = code % HTsize;    
}

/*
 * LookupHS() - For each identifier, Look it up in the hashtable for previous occurrence
 *              of the identifier. If fine a match, set the found flag as true. Otherwise flase.
 *              If fine a match, save the starting index of ST in same id
 */
void LookupHS(int nid,int hscode)
{
	HTpointer here;
	int i, j;

	found = FALSE;
	if (HT[hscode] != NULL) {
		here = HT[hscode];
		while (here != NULL && found == FALSE) {  // Check whether identifier already exists in hash table
			found = TRUE;
			i = here->index;
			j = nid;
			sameid = i;

			while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) {
				if (ST[i] != ST[j])
					found = FALSE;
				else {
					i++;
					j++;
				}
			}
			here = here->next;
		}
	}
}

/*
 * ADDHT() - Add a new identifier to the hash table.
 *           If list head ht[hashcode] is null, simply add a list element with
 *           starting index of the identifier in ST.
 *           If list head is not a null, it adds a new identifier to the head of the chain
 */
void ADDHT(int hscode)
{
	HTpointer ptr;
	ptr = (HTpointer)malloc(sizeof(HTentry));
	
	if (HT[hscode] == NULL) {
		ptr->next = NULL;
		ptr->index = nextid;
		ptr->isConst = 0;
		ptr->isFunction = 0;
		ptr->isParam = 0;
		ptr->isArray = 0;
		ptr->spec = NONE;
		ptr->linenum = lineno;
		ptr->error = 0;
		HT[hscode] = ptr;
	}
	else {
		ptr->next = HT[hscode];
		ptr->index = nextid;
		ptr->isConst = 0;
		ptr->isFunction = 0;
		ptr->isParam = 0;
		ptr->isArray = 0;
		ptr->spec = NONE;
		ptr->linenum = lineno;
		ptr->error = 0;
		HT[hscode] = ptr;
	}	
	
	current_id = ptr;
}

/*
 * SymbolTable() - Read the identifier and management symbol table, hash table
 */
int SymbolTable()
{
	err = noerror;
	if((nextfree == STsize) || ((nextfree+yyleng) > STsize)) {
		err = over_st;
		ReportError(err);
	}

	//Read identifier
	for (int i = 0; i<yyleng; i++) {
		ST[nextfree++] = yytext[i];
	}
	ST[nextfree++] = '\0';

	ComputeHS(nextid, nextfree);
	LookupHS(nextid, hashcode);
	if (!found) {
		ADDHT(hashcode);
		nextid = nextfree;
	}
	else {		
		nextfree = nextid;
	}
	
	return 1;
}
