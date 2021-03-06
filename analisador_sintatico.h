#include "tabelaAcao.h"
#include "definitions.h"

#include <vector>
#include <stdio.h>
#include <stdlib.h>

std::vector<int> stateStack;
FILE *fr;
elementoTabelaAuxiliar r;

int nextToken()
{
    int *a;
    a = new int;
    if(fread(a, 4, 1, fr) < 1)
    {
        return $;
    }
    //printf("*%d*", *a);
    return *a;
}

void push(int input)
{
    stateStack.push_back(input);
}

void pop(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("POP\n");
        stateStack.pop_back();
    }
}

int top()
{
    return stateStack.back();
}

bool isShift(int input)
{
    if(input >= 0 && input < 11000)
    {
        return true;
    }
    return false;
}

bool isReduction(int input)
{
    if(input < 0)
    {
        return true;
    }    
    return false;
}

void syntaxError()
{
    printf("Erroooooooo!\n");
    exit(5);
}


void analiseSintatica()
{
    int q, a, p;
    fr = fopen("lexico.bin", "rb");
    if(!fr)
    {
        exit(2);
    }

    q = 0;
    push(0);
    a = nextToken();

    do 
    {
        printf("=============\n");
        printf("q: %d\n", q);
        printf("a: %d\n", a);
        //implementado em tabelaAcao
        p = action(q, a);
        printf("p: %d\n", p);
        printf("=============\n");
        
        if(a == ID)
        {
            //PEGA TOKEN SECUNDARIO
            a = nextToken();
        }

        if(isShift(p))
        {
            push(p);
            a = nextToken();
        }
        else if (isReduction(p))
        {
            //r e rule em tabelaAcao.h
            r = rule(p);
            printf("r.len: %d\n", r.len);
            printf("r.left: %d\n", r.left);
            pop(r.len);
            push(action(top(), r.left));
        }
        else
        {
            syntaxError();
        }
        q = top();
 //       getchar();
    } while (q != ACC);
    printf("\nANALISE SINTATICA OK\n");
}

