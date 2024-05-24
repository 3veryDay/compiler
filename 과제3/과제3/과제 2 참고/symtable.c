/*
* symtable.c - 각 token에 대한 출력
* programmer - 김예지(2176082), 송채원(2076216), 신정화(2271035), 윤하영(2071033)
* date - 2024-04-29
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glob.h"
#include "tn.h"
#define STsize 1000 // size of string table 
#define HTsize 100 // size of hash table
#define FALSE 0
#define TRUE 1
#define MAX_ID_LEN 12 // maximum length for an identifier
typedef struct HTentry* HTpointer;
typedef struct HTentry {
 int index; // index of identifier in ST
 HTpointer next; // pointer to next identifier 
} HTentry;
HTpointer HT[HTsize]; // Array of list head of hashtable 
char ST[STsize]; // Array of string table
int nextid = 0; // the current identifier
int nextfree = 0; // the next available index of ST
int hashcode; // hash code of identifier
int sameid; // first index of identifier
int found; // for the previous ocurrence of a idntifier
int stidx = 0; // index of identifier in String Table
int isOverst = 0; // for overflow error
// Read ID - Read identifier from fileInput file and append it into the string table 
ST.
// An identifier is a string of letters and digits, starting with a letter.
// If first letter is digit, print out error message.
void ReadID() {
 // Check if the identifier fits within the string table
 if (nextfree + yyleng < STsize) {
 // Update indices
 nextid = nextfree;
 // Copy the identifier to the string table
 for (int i = 0; i < yyleng; i++) {
 ST[nextfree++] = yytext[i];
 }
 }
 else {
 isOverst = 1;
 }
}
// Compute HS - Compute the hash code of identifier by summing the ordinal 
values
// of its characters and the taking the sum modulo the size of HT.
void ComputeHS(int nid, int nfree) {
 int code, i;
 code = 0; // identifier의 아스키코드의 합
 for (i = nid; i < nfree - 1; i++) {
 code += (int)ST[i];
 }
 hashcode = code % HTsize; // (아스키코드 합) mod (hash table 크기) -> hashcode
}
// Lookup HS - For each identifier, look it up in the hash table for previous 
occurrence of
// the identifier. If find a match, set the found flag as true. Otherwise 
false.
// If find a match, save the starting index of ST in same id.
void LookupHS(int nid, int hscode) {
 HTpointer here;
 int i, j;
 found = FALSE; // 이미 HT에 존재하는 identifier인 경우 TRUE, 아니면 FALSE
 // 새로운 identifier가 hash table에 저장될 index(위치)가 비어있지 않으면
 if (HT[hscode] != NULL) {
 here = HT[hscode];
 // while loop를 돌면서 이미 존재하는 identifier인지 체크
 while (here != NULL && found == FALSE) {
 found = TRUE;
 i = here->index; // HT[hscode]에서 index 부분에 적힌 값
 j = nid; // identifier의 시작 부분의 index
 sameid = i;
 // identifier와 동일한지 체크
 while (ST[i] != '\0' && ST[j] != '\0' && found == TRUE) { // identifier와 
한글자씩 같은지 비교
 if (ST[i] != ST[j])
 found = FALSE;
 else {
 i++;
 j++;
 }
 }
 here = here->next; // 연결리스트에서 다음 칸으로 이동하며 체크
 }
 }
}
// Add HT - Add a new identifier to the hash table.
// If list head HT[hashcode] is null, simply add a list element with
// starting index of the identifier in ST.
// If list head HT[hashcode] is not null, add a new identifier to the head of 
the chain.
void AddHT(int hscode) {
 HTpointer ptr;
 ptr = (HTpointer)malloc(sizeof(ptr));
 ptr->index = nextid;
 ptr->next = HT[hscode];
 HT[hscode] = ptr;
}
// symbolTable - Read the identifier from the file and directly append it into ST.
// Compute its hash code and look up the identifier in hash table 
HT[hashcode].
// Update stidx(index in String Table).
void symbolTable() {
 int i;
 ReadID(); // identifier 읽음
 ST[nextfree++] = '\0';
 ComputeHS(nextid, nextfree); // identifier의 hashcode 계산 -> hscode
 LookupHS(nextid, hashcode); // hash table에 이미 존재하는 idetifier인지 체크 -> 
found, sameid
 if (!found) { // 처음 입력된 identifier라면 (hash table에 이미 존재하는 idetifier가 아
니라면)
 stidx = nextid;
 AddHT(hashcode);
 }
 else { // hash table에 이미 존재하는 idetifier라면
 stidx = sameid;
 nextfree = nextid;
 }
}
