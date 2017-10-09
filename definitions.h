#pragma once


//DEFINIÇÕES ANÁLISE LÉXICA
#include "uthash.h"
#define MAX_ID_LEN 20
#define MAX_CONSTS 200
#define MAX_NUM_LEN 20
#define MAX_STR_LEN 200
#define MAX_STACK_SIZE 20

typedef enum {
    //palavras reservadas
    ARRAY = 0, BOOLEAN, BREAK, CHAR, CONTINUE, DO, ELSE, FALSE, FUNCTION, IF, INTEGER,
    OF, STRING, STRUCT, TRUE, TYPE, VAR, WHILE,
    
    //simbolos
    COLON, SEMI_COLON, COMMA, EQUALS, LEFT_SQUARE, RIGHT_SQUARE, LEFT_BRACES, RIGHT_BRACES,
    LEFT_PARENTHESIS, RIGHT_PARENTHESIS, AND, OR, LESS_THAN, GREATER_THAN, LESS_OR_EQUAL, 
    GREATER_OR_EQUAL, NOT_EQUAL, EQUAL_EQUAL, PLUS, PLUS_PLUS, MINUS, MINUS_MINUS, TIMES,
    DIVIDE, DOT, NOT,

    //tokens regulares
    CHARACTER, NUMERAL, STRINGVAL, ID,

    //token desconhecido
    UNKNOWN,

    //token de aceitação
    ACC = 9000, $ = 10000 } t_token;

typedef struct {
    char type;
    union Value {
        char cVal;
        int nVal;
        char sVal[MAX_ID_LEN + 1];
    } value;
} t_const;

typedef struct tokensSecundarios {
    int key;
    char name[MAX_ID_LEN + 1];
    UT_hash_handle hh;
} tokens_Secundarios;


//DEFINIÇÕES ANÁLISE SINTÁTICA
#define ERROR 11001


typedef enum {
	P = 1000, LDE, DE, T, DT, DC, DF, LP, B, LDV, LS, DV, LI, S,
	E, L, R, Y, F, LE, LV, ID_N_TERMINAL, TRU, FAL, CHR, STR, NUM, 
    IDD, IDU, NB, MF, MC, NF, MT, ME, MW
} t_nonTerminalCode;

typedef struct 
{
    int rule;
    int len;
    int left;
} elementoTabelaAuxiliar;

//DEFINIÇÕES ANÁLISE DE TIPO
typedef enum { NO_KIND_DEF_=-1, VAR_, PARAM_, FUNCTION_, FIELD_,
ARRAY_TYPE_, STRUCT_TYPE_, ALIAS_TYPE_, SCALAR_TYPE_ ,
UNIVERSAL_} t_kind;

//DEFINIÇÕES ANÁLISE DE ESCOPO
#define MAX_NEST_LEVEL 10
typedef enum
{
    ERR_REDECL, ERR_NOT_DECL, ERR_TYPE_EXPECTED
} t_error;

struct object
{
    int nName;
    struct object *pNext;
    t_kind eKind;
    union 
    {
	struct 
	{
		struct object *pType;
	} Var, Param, Field;
	struct 
	{
		struct object *pRetType;
		struct object *pParams;
	} Function;
	struct 
	{
		struct object *pElemType;
		int nNumElems;
	} Array;
	struct 
	{
		struct object *pFields;
	} Struct;
	struct 
	{
		struct object *pBaseType;
	} Alias;
    }_;

    struct object *obj, *type, *list;
    bool bVal;
    char cVal, *sVal;
    int iVal, pos;
};

void Error(t_error e)
{
    switch(e)
    {
        case ERR_REDECL:
                        printf("Redeclarado.\n");
                        break;
        case ERR_NOT_DECL:
                        printf("Não declarado.\n");
                        break;
    }
}

boolean CheckTypes(pobject t1, pobject t2)
{
	if( t1 == t2 )
		return true;
	else
		if( t1 == pUniversal || t2 == pUniversal )
			return true;
	else
		if( t1->eKind == UNIVERSAL_ || t2->eKind == UNIVERSAL_ )
			return true;
	else
		return false;
}

struct object StackSem[MAX_STACK_SIZE];

int top_Stack_Sem = -1;

int PushSem( struct object &obj ) {
    StackSem[++top_Stack_Sem] = obj;
    return top_Stack_Sem;
}

int PopSem( int nToPop ) {
    top_Stack_Sem = top_Stack_Sem - nToPop;
    return top_Stack_Sem;
}

struct object TopSem( int offFromTop ) {
    return StackSem[top_Stack_Sem - offFromTop];
}
    
