#pragma once

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
    UNKNOWN } t_token;

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

typedef enum {
	P = 1000, LDE, DE, T, DT, DC, DF, LP, B, LDV, LS, DV, LI, S,
	E, L, R, Y, F, LE, LV, ID_TERMINAL, TRU, FAL, CHR, STR, NUM
} t_nonTerminalCode;

typedef struct 
{
    int len;
    int left;
} elementoTabelaAuxiliar;


