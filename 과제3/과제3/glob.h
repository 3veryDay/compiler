/*
 * glob.h - global variable for the project
 */
#define STsize 1000
#define HTsize 100
#define FALSE 0
#define TRUE 1

typedef struct HTentry* HTpointer;
typedef struct HTentry {
	int index;
	int isConst;
	int isFunction;
	int isParam;
	int isArray;
	int linenum;
	int error;
	Types spec;
	HTpointer next;
} HTentry;

HTpointer HT[HTsize];
char ST[STsize];
HTpointer current_id;

int nextid; 
int nextfree;
int hashcode; 
int sameid;  //st, ht용

int cErrors;  //number of errors
int lineno;

enum errorType { noerror, digit_ident, long_ident, ill_symbol, over_st, missing_semi, missing_paren, missing_curly, missing_square, missing_comma, missing_funcheader, declaring_err, missing_condition, wrong_assign, missing_operand
};
typedef enum errorType ErrorType;
ErrorType err;

enum Types { INT, VOID, FLOAT, NONE};
typedef enum Types Types;
Types type;
