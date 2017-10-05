#include<stdio.h>
#include<stdlib.h>
#include "analisador_lexico.h"

int main(int argc, char *argv[]) {
    FILE *fp;
    int i;
    char c1, c2;
    if (argc < 2) {
        printf("Erro! Nenhum arquivo a ser analisado...\n");
        exit(EXIT_FAILURE);
    } else {
        if (fp = fopen(argv[1], "r")) {
            printf("Tokens: \n");
            while ( !feof(fp) ) {
                i = (int) nextToken(fp);
                printf("%d ",i);
            }
            printf("\n");
            fclose(fp);
//            tokens_Generator(argv[1]);
        }
        
    }

/*    if (fp = fopen("lexico.bin", "rb")){
        printf("Tokens do arquivo: \n");
        //while (!feof(fp)) {
        while (1 == fread(&i, 4, 1, fp)) {
            //fread(&i, 4, 1, fp);
            printf("%d ", i);        
        }
    } else {
        printf("Erro ao abrir o arquivo...\n");
    }
    fclose(fp);
*/
    printf("\nConstantes:\n");
    for (i = 0; i < nNumConsts; i++) {
        if (vConst[i].type == 0) 
            printf("%c\n", vConst[i].value.cVal);
        else if (vConst[i].type == 1)
            printf("%d\n", vConst[i].value.nVal);
        else
            printf("%s\n", vConst[i].value.sVal);
    }
    return 0;
}
