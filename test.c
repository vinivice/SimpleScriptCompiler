#include<stdio.h>
#include<stdlib.h>
#include "analisador_lexico.h"
#include "analisador_sintatico.h"
#include "definitions.h"

int main(int argc, char *argv[]){
    if(argc < 2)
    {
        printf("Faltam argumentos!\n");
        return 1;
    }
    tokens_Generator(argv[1]);
    printf("FIM DA LEXICA\n");
//    analiseSintatica();
    return 0;
}
