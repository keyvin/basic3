#ifndef TOKENS_H
#define TOKENS_H 1

#include <stdint.h>
#define TOKEN_ERROR_1 "INVALID TOKEN"
//this cannot be less than t_string_info
#define MAX_TOKEN_LENGTH 20
#define MAX_STRING 128
#define MAX_TOKENS 45
#define PLUS 1
#define MINUS 2
#define DIVIDE 3
#define MULTIPLY 4
#define POWER 5
#define OPAREN 6
#define CPAREN 7
#define COMMA 8
#define SEMI 9
#define COLON 10
#define AND 11
#define OR 12
#define NOT 13
#define GT 14
#define LT 15
#define GTE 16
#define LTE 17
#define NOT_EQ 18
#define EQ 19    //flow starts at 20...
#define IF 20
#define THEN 21
#define FOR 22
#define NEXT 23
#define TO 24
#define STEP 25
#define ELSE 26
#define GOTO 27
#define GOSUB 28
#define RETURN 29
#define PRINT 30
#define DIM 31
#define COS 32
#define SIN 33
#define TAN 34
#define LEN 35
#define CHR 36    //built in functions
//#define STR 35 Interferes with variable enum str trypes....
#define LEFT 37
#define RIGHT 38
#define MID 39
#define NEGATE 40
//Other Tokens

#define VAR 101  //next two bytes reference a var
#define STR_TOKEN 102  //references a string

#define FLOW_START 20   //where flow control tokens start
#define STR_MATCH_NUM 15    //number of chars toattempt a match.

static char *TOKEN_CHAR[] = {'\0', "+", "-", "/", "*", "^", "(", ")", ",", ";", ":","AND", "OR", "NOT", ">", "<" , ">=", "<=", "<>", "=", "IF", "THEN", "FOR", "NEXT", "TO", "ELSE", "STEP", "GOTO","GOSUB","RETURN", "PRINT","DIM", "COS", "SIN", "TAN", "LEN", "CHR", "LEFT", "RIGHT", "MID", "NEGATE"};

static char *STR_TO_TOKEN[STR_MATCH_NUM] = { "AND", "OR", "NOT", "IF", "THEN", "ELSE", "FOR", "NEXT", "TO", "GOTO", "GOSUB", "PRINT", "DIM", "RETURN", "STEP"};

static int STR_MATCH[] = {AND, OR, NOT, IF, THEN, ELSE, FOR, NEXT, TO, GOTO, GOSUB, PRINT, DIM, RETURN, STEP};

#define NUM_FUNCTIONS 8
static char *FUNCTION_MATCH[] = {"COS", "SIN", "TAN", "LEN", "RND", "LEFT$", "RIGHT$", "CHR$"};



static int TOKEN_PRECEDENCE[MAX_TOKENS] = {0,1,1,2,2,3,4,4,0,0,0,5,5,5,0,0,0,0,0, 0, 5, 5, 5, 5, 5};

enum t_type {SYMBOL, INTEGER, FLOAT, ERROR, OPERATOR, STRING, EOL, INVALID, DOUBLE, ARRAY, FLOW, FUNCTION};


void dump_stack();


//this could just be start and stop data in the program input!!!!
//for instance
//char *start, int length. use strncmp!
typedef struct TOKEN {
  char value[MAX_TOKEN_LENGTH];
  enum t_type type;
} token;

typedef struct T_STRING_INFO {
  char *start;
  unsigned int length;
} t_string_info;

extern token buffer;
extern char read_buffer[MAX_STRING];
//pass by value

uint8_t is_operator(char);
void read(char **, token *);
void dump_stack();
void dump_token(token);
#endif
