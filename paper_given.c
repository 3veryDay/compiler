//박소현님
/*******************************************************************************************************************************
Hashtable Implementation (STsize = 1000)
Programmer : 지현서, 조은혜, 조윤아, 박소현
Date: 03/15/2024

Description :
The input to the program is a file , consisting of identifiers seperated by
spaces,tab characters, newlines and punctuation marks . , , , ; , :, ? , ! .
An identifier is a string of letters and digits,starting with a letter.Case is insignificant.
:
If the ST overflows,prints the hashtable as above and abort by calling 
the function "exit()".
Input :
A file consisting of identifiers seperated by spaces, tab characters,newlines and 
punctuation marks. 
An identifier is a string of letters and digits,starting with a letter.
Output :
The identifier,its index in the stringtable and whether entered or present.
Prints error message for illegal identifier(starting with a digit),illegal seperator and 
:
Restriction:
If the ST overflows, print the hashtable as above, and abort by calling 
the function "exit()". "exit()" terminates the execution of a program.
Global variables : 
ST - Array of string table
HT - Array of list head of hashtable
letters - Set of letters A..Z, a..z, _
digits - Set of digits 0..9
seperators - null , . ; : ? ! \t \n
*****************************************************************************************************************************/
//지현서
//*****************************************************************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "testdata.txt"
#define STsize 1000         //String Table 사이즈
#define HTsize 100          //Hash Table 사이즈
#define FALSE 0
#define TRUE 1


//문자는 a...z, A...Z, _
#define isLetter(x) (  ((x) >= 'a' && (x) <= 'z') || ((x) >= 'A' && (x) <= 'Z') || ((x) == '_'))
//숫자는 1,2 ... 9
#define isDigit(x) ( (x) >= '0' && (x) <= '9')


//HashTable 들어가는
typedef struct HTentry *HTpointer;

typedef struct HTentry {
int index;              //StringTable에서의 인덱스
HTpointer next;         //다음 identifier 포인터
} HTentry;


//에러 타입 정의
enum errorTypes { noerror, illsp, illid, overst };
typedef enum errorTypes ERRORtypes;


//delimeter 정의
char seperators[] = " .,;:?!\t\n";


//HashTable, StringTable 선언
HTpointer HT[HTsize];
char ST[STsize];



int nextid = 0;     //현재 identifier
int nextfree = 0;   // 비어있는 다음 StringTable 인덱스
                    //이 다음부터 nextid 인덱스임.
int hashcode;       // 현재 identifier의 hash code 값
int sameid;         // 해당 identifier의 첫번째 hashtable 인덱스(중복 대비)

int found;          //for the previous occurrence of an identifier
                    //HT 중복하면, 돌아갈 identifier의 인덱스
ERRORtypes err;

FILE *fp;            //hash대상 파일
char input;



//Initialize - input file 열기
void initialize()
{
fp = fopen(FILE_NAME, "r");
input = fgetc( fp );
input = input + " ";
}


//is Seperator - delimeter(seperator) 구별해내기
//seperator이면 1 리턴
int isSeperator(char c )
{
    int i;
    int sep_len;

    sep_len = strlen(seperators);
    for (i = 0; i < sep_len; i ++) {
        if (c == seperators[i] )
            return 1;
    }
    return 0;
}


//PrintHStable - 해쉬테이블 출력.
//맨 위에 [[ HASH TABLE ]] 출력 후
//hascode 와 이에 해당하는 identifiers 출력(단, 비어있지 않은 경우에만)
//String Table에서 쓰인 character 수 출력
//마지막에 팀원들 이름, 학번 출력
void PrintHStable()
{
    int i,j ;
    HTpointer here;

    printf("\n\n\n\n\n [[ HASH TABLE]] \n\n");


    for (i = 0; i <HTsize; i++)
        if (HT[i] != NULL){
            printf(" HashCode %3d :", i);
            for (here = HT[i]; here!=NULL; here = here-> next) {
                j = here-> index;
                while(ST[j] != '\0' && j < STsize)
                    printf("%c", ST[j++]);
                printf("    ");

            }
            printf("\n");
        }
        printf("\n\n\n <%5d characters are used in the string table> \n", nextfree);
        //printf("2176368 지현서, 2176365 조은혜, 2171047 조윤아, 2176143 박소현");
}


//print Heading - HEADING 출력
void PrintHeading()
{
    printf("\n\n");
    printf(" ------------   ------------ \n");
    printf(" Index in ST    Identifier \n");
    printf(" ------------   ------------ \n");
    printf("\n");
}





//*****************************************************************************************************************************
//조은혜님
// 
// PrintError - 에러 메시지 출력 함수
//overst : ST에서의 오버플로우
//해시테이블 출력, abort()함수에 의해 중단
// illid : illegal identifier (올바르지 않은 identifier)
// illsp :illegal seperator (올바르지 않은 seperator)
void PrintError( ERRORtypes err )
{
    switch( err ) {
        case overst :   // ST에서 오버플로우가 발생한 경우
            printf(" ... Error ... OVERFLOW ");
            PrintHStable();
            exit(0);
            break;
        case illsp :    // 올바르지 않은 seperator가 입력된 경우
            printf(" ... Error ... %c is illegal seperator \n ", input);    //입력이 올바르지 않은 seperator임을 출력
            
            break;
        case illid :    // 올바르지 않은 identifier가 입력된 경우
            printf(" ... Error ...");
            while(input != EOF && (isLetter(input) || isDigit(input)) ) {
                printf("%c", input);
                input = fgetc(fp);

            }
            printf(" start with digit \n"); // 숫자로 시작함을 출력
            break;
    }
}


// Skip Seperators - spaces,tabs,newlines, . , ; : ? ! 등의 seperator들을 저장하지 않고 넘어가는 함수
// 만약 올바르지 않은 seperator가 입력된 경우 에러 메시지 출력
void SkipSeperators()
{
    while (input != EOF && !( isLetter(input) || isDigit(input) ) ) {   // 입력된 값이 문자나 숫자가 아닌지 확인
        if (!isSeperator(input) ) {
            err = illsp;
            PrintError(err);
        }
        input = fgetc(fp);
    }
}


//ReadIO - 입력에서 identifier를 읽어 스트링테이블 ST에 저장
// ST(append it to the previous identifier).
// identifier는 문자로 시작하는 문자와 숫자의 문자열
// 첫 글자가 숫자인 경우 에러 메시지 출력 
void ReadID() 
{
    nextid = nextfree ;
    if (isDigit(input)) {
        err = illid;
        PrintError(err);
    }else {
        while(input != EOF && (isLetter(input) || isDigit(input))) {    // 입력된 값이 문자나 숫자인지 확인
            if (nextfree == STsize){    // 오버플로우가 발생한 경우
                err = overst;
                PrintError(err);    // 오버플로우 에러 메시지 출력
            }
            ST[nextfree ++] = input;
            input = fgetc(fp);
        }
    }
}
// ComputeHS - 문자의 ordinal values를 합한 다음 HT 크기로 mod 계산하여 해시 코드를 계산하는 함수
void ComputeHS( int nid, int nfree )
{
    int code, i;
    code = 0;
    for (i = nid;i <nfree -1; i++)
        code += (int)ST[i]; // (int)ST[i]: 해당 문자의 ordinal values
    hashcode = code % HTsize;
}



//*****************************************************************************************************************************
// // LookupHS -For each identifier,Look it up in the hashtable for previous occurrence
// of the identifier.If find a match, set the found flag as true.
// Otherwise flase.
// If find a match, save the starting index of ST in same id. 
//조윤아
void LookupHS( int nid, int hscode )
{
    HTpointer here;
    int i,j;

    found = FALSE;
    if (HT[hscode] != NULL) {
        here = HT[hscode];
        while(here != NULL && found == FALSE){
            found = TRUE;
            i = here-> index;
            j = nid;
            sameid = i;

            while(ST[i] != '\0' && ST[j] != '\0' && found == TRUE){
                if (ST[i] != ST[j])
                    found = FALSE;

                    else{
                    i++;
                    j++;
                    }

            }
            here = here -> next;
        }
    }
}
// ADDHT - Add a new identifier to the hash table.
// If list head ht[hashcode] is null, simply add a list element with
// starting index of the identifier in ST.
// IF list head is not a null , it adds a new identifier to the head of the chain 
void ADDHT( int hscode )
{
    HTpointer ptr ;

    ptr = (HTpointer) malloc(sizeof(ptr));
    ptr -> index = nextid ;
    ptr -> next = HT[hscode];
    HT[hscode] = ptr;
}
// // MAIN - Read the identifier from the file directly into ST.
// Compute its hashcode.
// Look up the idetifier in hashtable HT[hashcode]
// If matched, delete the identifier from ST and print ST-index
// of the matching identifier.
// If not matched , add a new element to the list,pointing to new identifier.
// Print the identifier,its index in ST, and whether it was entered or present.
// Print out the hashtable,and number of characters used up in ST
// //
int main()
{
int i;
PrintHeading();
initialize();

while (input != EOF) {
err = noerror;
SkipSeperators();
ReadID();
if( input != EOF && err != illid ) {
if( nextfree == STsize ) {
    err = overst;
    PrintError( err );
}
ST[nextfree++] = '\0';
ComputeHS( nextid, nextfree );
LookupHS( nextid, hashcode );
if( !found ) {
    printf("%6d     ", nextid);
    for (i = nextid; i < nextfree -1 ; i ++)
        printf("%c", ST[i]);
    printf("        (entered) \n");
    ADDHT(hashcode);
}
else {
    printf("%6d     ", sameid);
    for( i = nextid; i< nextfree -1; i++)
        printf("%c", ST[i]);
    printf("    (alreadyexisted)\n");
    nextfree = nextid;

}
}
}
PrintHStable();
}



