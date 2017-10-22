#pragma once


//DEFINIÇÕES ANÁLISE LÉXICA
#include "uthash.h"
#define MAX_ID_LEN 20
#define MAX_CONSTS 200
#define MAX_NUM_LEN 20
#define MAX_STR_LEN 200
#define MAX_STACK_SIZE 2000

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
    ERR_REDECL, ERR_NOT_DECL, ERR_TYPE_EXPECTED, ERR_TOO_FEW_ARGS, ERR_TOO_MANY_ARGS, ERR_PARAM_TYPE, ERR_KIND_NOT_FUNC, ERR_KIND_NOT_VAR, ERR_INVALID_INDEX_TYPE, ERR_KIND_NOT_ARRAY, ERR_FIELD_NOT_DECL, ERR_KIND_NOT_STRUCT, ERR_INVALID_TYPE, ERR_TYPE_MISMATCH, ERR_BOOL_TYPE_EXPECTED
} t_error;

    
typedef struct object 
{
    int nName;
    struct object *pNext;
    t_kind eKind;
    union 
    {
            struct 
            {
                int nSize;
                struct object *pType;
                int nIndex;
            } Var, Param, Field;
            struct 
            {
                struct object *pRetType;
                struct object *pParams;
                int nIndex;
                int nParams;
                int nVars;
            } Function;
            struct 
            {
                int nSize;
                struct object *pElemType;
                int nNumElems;
            } Array;
            struct 
            {
                int nSize;
                struct object *pFields;
            } Struct;
            struct 
            {
                int nSize;
                struct object *pBaseType;
            } Alias, Type;
    }_;

    struct object *obj, *type, *list, *param;
    bool bVal, err;
    char cVal, *sVal;
    int iVal, pos, n;
} object, *pobject;

object oIDD, oIDU, oT, oNUM, oLI, oLI0, oLI1, oDC, oDC0, oDC1, oSTR, oCHR, oTRUE, oFALSE, oNB, oLV0, oLV1, oID, oLE, oLE0, oLE1, oF0, oF1, oMC, oF, oY0, oY1, oY, oR0, oR1, oR, oL, oL0, oL1, oE0, oE1, oE, oLV, oLP, oLP0, oLP1;
object *p, *t, *f, *t1, *t2;

object int_ = {-1, NULL, SCALAR_TYPE_};
object *pInt = &int_;

object char_ = {-1, NULL, SCALAR_TYPE_};
object *pChar = &char_;

object bool_ = {-1, NULL, SCALAR_TYPE_};
object *pBool = &bool_;

object string_ = {-1, NULL, SCALAR_TYPE_};
object *pString = &string_;

object universal_ = {-1, NULL, SCALAR_TYPE_};
object *pUniversal = &universal_;

void init() {
    p = new object;
    printf("\n\n Pointer: %p \n\n", p);
    


}

void Error(t_error e, int n = 1)
{
    switch(e)
    {
        case ERR_REDECL:
                        printf("Redeclarado.\n");
                        break;
        case ERR_NOT_DECL:
                        printf("Não declarado.\n");
                        break;
        default:
                        printf("Erro desconhecido.\n");
                        break;
    }
}

bool CheckTypes(struct object *t1, struct object *t2)
{
	if( t1 == t2 )
    {
		return true;
    }
	else if( t1 == pUniversal || t2 == pUniversal )
    {
        return true;
    }
	else if( t1->eKind == UNIVERSAL_ || t2->eKind == UNIVERSAL_ )
    {
		return true;
    }
	else
    {
		return false;
    }
}

object StackSem[MAX_STACK_SIZE];

int top_Stack_Sem = -1;

int PushSem(object &anObj ) {
    if ( top_Stack_Sem < MAX_STACK_SIZE ) {
        StackSem[++top_Stack_Sem] = anObj;
        printf("\n\nEntrou na pilha... Topo: %d\nEndereco: %p\n\n", top_Stack_Sem, &StackSem[top_Stack_Sem - 1]);
        return top_Stack_Sem;
    } 
    else 
        printf("\nError: top_Stack_Sem > MAX_STACK_SIZE\n");
        return -2;
}

int PopSem( int nToPop ) {
    top_Stack_Sem = top_Stack_Sem - nToPop;
    return top_Stack_Sem;
}

object TopSem( int offFromTop ) {
    return StackSem[top_Stack_Sem + offFromTop - 1];
}
    
//DEFINIÇÕES GERAÇÃO DE CÓDIGO
#include <fstream>
std::ofstream myOutputFile;
