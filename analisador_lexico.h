#include<ctype.h>
#include<string.h>
#include "uthash.h"

#define MAX_ID_LEN 20
#define MAX_CONSTS 200
#define MAX_NUM_LEN 20
#define MAX_STR_LEN 200

typedef enum {
    //palavras reservadas
    ARRAY, BOOLEAN, BREAK, CHAR, CONTINUE, DO, ELSE, FALSE, FUNCTION, IF, INTEGER,
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

t_const vConst[MAX_CONSTS]; 

int nNumConsts = 0;

int addCharConst(char c){
    t_const character;
    character.type = 0;
    character.value.cVal = c;
    vConst[nNumConsts] = character;
    nNumConsts++;    
    return nNumConsts;
}

int addIntConst(char *n) {
    t_const integer;
    int i, value = 0;
    for (i = 0; i < strlen(n); i++) {
        value = 10 * value + (int) n[i];    
    }

    integer.value.nVal = value;
    integer.type = 1;
    
    vConst[nNumConsts] = integer;
    nNumConsts++;
    return nNumConsts;
}

int addStringConst(char *s) {
    t_const string;
    string.type = 2;
    strcpy(string.value.sVal, s);
    vConst[nNumConsts] = string;
    nNumConsts++;
    return nNumConsts;
}

const char *reserved_words[] = {"array", "boolean", "break", "char", "continue", "do", "else", "false", "function", "if",
                                 "integer", "of", "string", "struct", "true", "type", "var", "while"};

typedef struct tokensSecundarios {
    int key;
    char name[MAX_ID_LEN + 1];
    UT_hash_handle hh;
} tokens_Secundarios;

tokens_Secundarios *s, *tS = NULL;

t_token searchKeyWord(char *name){
    int i;
    for(i = 0;i < 18; i++){
        if (!strcmp(name, reserved_words[i])){
            printf("It's a reserved word\n");
            return (t_token)i;        
        }
    }
    printf("It isn't a reserved work\n");
    return ID;
}

int searchName(char *name, int* key) {
    tokens_Secundarios *s;
    HASH_FIND_STR(tS, name, s);
    if (!s) {
        s = (tokens_Secundarios*) malloc(sizeof(tokens_Secundarios));
        strncpy(s->name, name, MAX_ID_LEN + 1);   
        s->key = *key;
        HASH_ADD_STR(tS, name, s);
        (*key)++;
        printf("%s, %d\n", s->name, s->key);
        return s->key;
    } else {
        printf("%s, %d\n", s->name, s->key);
        return s->key;
    }

}

void tokens_Generator(char* filename) {
    char nextChar = '\x20';
    FILE *fp, *fw;
    t_token token;
    int tokenSecundario, count = 0;
    fp = fopen(filename, "r");
    fw = fopen("lexico.bin", "wb");
    if (fw == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    while (nextChar != EOF ) {
        while (isspace(nextChar)) {
            nextChar = fgetc(fp);
        }
        if ( isalpha(nextChar) ) {
            char text[MAX_ID_LEN + 1];
            int i = 0;
            while ( isalnum(nextChar) || nextChar == '_' ) {
                text[i++] = nextChar;
                nextChar = fgetc(fp);
            }
            text[i] = '\0';
            token = searchKeyWord(text);
            
            if ( token == ID  ) {
                tokenSecundario = searchName(text, &count);                
            }
                
        }

        else if ( isdigit(nextChar) ) {
            char numeral[MAX_NUM_LEN + 1];
            int i = 0;
            while (isdigit(nextChar)) {
                numeral[i++] = nextChar;
                nextChar = fgetc(fp);    
            }            
            numeral[i] = '\0';
            token = NUMERAL;
            tokenSecundario = addIntConst(numeral);            

        }
        else if ( nextChar == '"' ){
            char str[MAX_STR_LEN + 1];
            int i = 0;
            nextChar = fgetc(fp);
            while ( nextChar != '"' ) {
                str[i++] = nextChar;
                nextChar = fgetc(fp);

            }
            str[i] = '\0';
            nextChar = fgetc(fp); 
            token = STRING;
            tokenSecundario = addStringConst(str);
        }
        else {
            switch(nextChar) {
                case '\'':
                    nextChar = fgetc(fp);
                    token = CHARACTER;
                    tokenSecundario = addCharConst(nextChar);
                    nextChar = fgetc(fp);
                    nextChar = fgetc(fp);
                    break;
                case '+':
                    nextChar = fgetc(fp);
                    if (nextChar == '+') {
                        token = PLUS_PLUS;
                        nextChar = fgetc(fp);
                    }                                            
                    else  
                        token = PLUS;                    
                    break;                    
                case ':':
                    token = COLON;
                    nextChar = fgetc(fp);
                    break;
                case ';':
                    token = SEMI_COLON;
                    nextChar = fgetc(fp);
                    break;
                case ',':
                    token = COMMA;
                    nextChar = fgetc(fp);
                    break;
                case '=':
                    nextChar = fgetc(fp);
                    if (nextChar == '=') {
                        token = EQUAL_EQUAL;
                        nextChar = fgetc(fp);
                    } else 
                        token = EQUALS;                    
                    break;
                case '[':   
                    token = LEFT_SQUARE;
                    nextChar = fgetc(fp);
                    break;
                case ']':
                    token = RIGHT_SQUARE;
                    nextChar = fgetc(fp);
                    break;
                case '{':
                    token = LEFT_BRACES;
                    nextChar = fgetc(fp);
                    break;
                case '}':
                    token = RIGHT_BRACES;
                    nextChar = fgetc(fp);
                    break;
                case '(':
                    token = LEFT_PARENTHESIS;
                    nextChar = fgetc(fp);
                    break;
                case ')':
                    token = RIGHT_PARENTHESIS;
                    nextChar = fgetc(fp);
                    break;
                case '&':
                    token = AND;
                    nextChar = fgetc(fp);
                    break;
                case '|':
                    token = OR;
                    nextChar = fgetc(fp);
                    break;
                case '<':
                    nextChar = fgetc(fp);
                    if (nextChar == '=' ) {
                        token = LESS_OR_EQUAL;
                        nextChar = fgetc(fp);
                    } else {
                        token = LESS_THAN;
                        break;
                    }
                case '>':
                    nextChar = fgetc(fp);
                    if (nextChar == '=') {
                        token = GREATER_OR_EQUAL;
                        nextChar = fgetc(fp);
                    } else
                        token = GREATER_THAN;
                    break;
                case '-':
                    nextChar = fgetc(fp);
                    if (nextChar == '-') {
                        token = MINUS_MINUS;
                        nextChar = fgetc(fp);
                    } else 
                        token = MINUS;
                    break;
                case '*':
                    token = TIMES;
                    nextChar = fgetc(fp);
                    break;
                case '/':
                    token = DIVIDE;
                    nextChar = fgetc(fp);
                    break;
                case '.':
                    token = DOT;
                    nextChar = fgetc(fp);
                    break;
                case '!':
                    nextChar = fgetc(fp);
                    if (nextChar == '=') {
                        token = NOT_EQUAL;
                        nextChar = fgetc(fp);
                    } else 
                        token = NOT;
                    break;                 
                default:
                    token = UNKNOWN;
                    nextChar = fgetc(fp);
                    break;
            }
        }
        printf("%c \n", nextChar);        

       if ( nextChar != EOF ) {
            fwrite(&token, sizeof(t_token), 1, fw);
            if (token == ID) 
                fwrite(&tokenSecundario, 4, 1, fw);
        }
    }    
    
    fclose(fp);
    fclose(fw);

}

