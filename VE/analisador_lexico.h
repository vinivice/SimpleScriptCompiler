#pragma once

#include<ctype.h>
#include<string.h>
#include "uthash.h"
#include "definitions.h"

t_const vConst[MAX_CONSTS]; 

int count, nNumConsts = 0;
int tokenSecundario;


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
    int value;
    value = atoi(n);
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

char getCharConst(int n) {
    t_const CharConst = vConst[n];
    return CharConst.value.cVal;
}

int getIntConst(int n) {
    t_const IntConst = vConst[n];
    return IntConst.value.nVal;
}

char *getStringConst(int n) {
    t_const element = vConst[n];
    char *StringConst = (char*)  malloc (sizeof(char) * MAX_STR_LEN);
    strcpy(StringConst, element.value.sVal);    
    return StringConst;
}

const char *reserved_words[] = {"array", "boolean", "break", "char", "continue", "do", "else", "false", "function", "if",
                                 "integer", "of", "string", "struct", "true", "type", "var", "while"};

tokens_Secundarios *s, *tS = NULL;

//Busca por palavras reservadas

t_token searchKeyWord(char *name){
    int i;
    for(i = 0;i < 18; i++){
        if (!strcmp(name, reserved_words[i])){
            return (t_token)i;        
        }
    }
    return ID;
}

//Busca um elemento na tabela hash ou o insere caso nao exista, retornando a chave correspondente

int searchName(char *name, int* key) {
    tokens_Secundarios *s;
    HASH_FIND_STR(tS, name, s);
    if (!s) {
        s = (tokens_Secundarios*) malloc(sizeof(tokens_Secundarios));
        strncpy(s->name, name, MAX_ID_LEN + 1);   
        s->key = *key;
        HASH_ADD_STR(tS, name, s);
        (*key)++;
        return s->key;
    } else {
        return s->key;
    }

}

//Lê o próximo caractere

char readChar(FILE *fp) {
    char c = fgetc(fp);
    return c;
}

//Retorna o token corrente

t_token nextToken(FILE *fp) {
    char nextChar = '\x20';
    t_token token;
    while (isspace(nextChar)) {
        nextChar = readChar(fp);
        printf("*%c*", nextChar);
        if ( nextChar == EOF )
            return $;
    }
    if ( isalpha(nextChar) ) {
        char text[MAX_ID_LEN + 1];
        int i = 0;
        while ( isalnum(nextChar) || nextChar == '_' ) {
            text[i++] = nextChar;
            nextChar = readChar(fp);
        }
        fseek(fp, -1, SEEK_CUR);
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
            nextChar = readChar(fp);    
        }           
        fseek(fp, -1, SEEK_CUR);                 
        numeral[i] = '\0';
        token = NUMERAL;
        tokenSecundario = addIntConst(numeral);            

    }
    else if ( nextChar == '"' ){
        char str[MAX_STR_LEN + 1];
        int i = 0;
        nextChar = readChar(fp);
        while ( nextChar != '"' ) {
            str[i++] = nextChar;
            nextChar = readChar(fp);
        }
        fseek(fp, -1, SEEK_CUR);
        str[i] = '\0';
        nextChar = readChar(fp); 
        token = STRINGVAL;
        tokenSecundario = addStringConst(str);
    }
    else {
        switch(nextChar) {
            case '\'':
                nextChar = readChar(fp);
                token = CHARACTER;
                tokenSecundario = addCharConst(nextChar);
                nextChar = readChar(fp);
                break;
            case '+':
                nextChar = readChar(fp);
                if (nextChar == '+') {
                    token = PLUS_PLUS;
                }                                            
                else  
                    token = PLUS;                    
                break;                    
            case ':':
                token = COLON;
                break;
            case ';':
                token = SEMI_COLON;
                break;
            case ',':
                token = COMMA;
                break;
            case '=':
                nextChar = readChar(fp);
                if (nextChar == '=') {
                    token = EQUAL_EQUAL;
                } else 
                    token = EQUALS;                    
                break;
            case '[':   
                token = LEFT_SQUARE;
                break;
            case ']':
                token = RIGHT_SQUARE;
                break;
            case '{':
                token = LEFT_BRACES;
                break;
            case '}':
                token = RIGHT_BRACES;
                break;
            case '(':
                token = LEFT_PARENTHESIS;
                break;
            case ')':
                token = RIGHT_PARENTHESIS;
                break;
            case '&':
                token = AND;
                break;
            case '|':
                token = OR;
                break;
            case '<':
                nextChar = readChar(fp);
                if (nextChar == '=' ) {
                    token = LESS_OR_EQUAL;
                } else 
                    token = LESS_THAN;
                break;                
            case '>':
                nextChar = readChar(fp);
                if (nextChar == '=') {
                    token = GREATER_OR_EQUAL;
                } else
                    token = GREATER_THAN;
                break;
            case '-':
                nextChar = readChar(fp);
                if (nextChar == '-') {
                    token = MINUS_MINUS;
                } else 
                    token = MINUS;
                break;
            case '*':
                token = TIMES;
                break;
            case '/':
                token = DIVIDE;
                break;
            case '.':
                token = DOT;
                break;
            case '!':
                nextChar = readChar(fp);
                if (nextChar == '=') {
                    token = NOT_EQUAL;
                } else 
                    token = NOT;
                break;                 
            default:
                token = UNKNOWN;
                break;
        }
    }
    
        printf("+%d+", tokenSecundario);
    return token;
}   

//Gera o arquivo binario lexico.bin com todos os tokens

void tokens_Generator(char* filename) {
    FILE *fp, *fw;
    t_token token;
    fp = fopen(filename, "r");
    fw = fopen("lexico.bin", "wb");
    if (fw == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    
    while ( !feof(fp) ) {
        token = nextToken(fp);
        if ( token != (t_token) 49 ) {
            fwrite(&token, sizeof(t_token), 1, fw);
            if ( token == ID ) 
                fwrite(&tokenSecundario, 4, 1, fw);        
        }
    }    
    
    fclose(fp);
    fclose(fw);
}

