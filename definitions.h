#pragma once


//DEFINIÇÕES ANÁLISE LÉXICA
#include "uthash.h"
#define MAX_ID_LEN 20
#define MAX_CONSTS 200
#define MAX_NUM_LEN 20
#define MAX_STR_LEN 200

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
    ACC = 9000 } t_token;

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
#define $ 10000
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


//DEFINIÇÕES ANÁLISE DE ESCOPO
#define MAX_NEST_LEVEL 10
typedef enum
{
    ERR_REDECL, ERR_NOT_DECL
} t_error;

struct object
{
    int nName;
    struct object *pNext;
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
