#include"tabelaAcao.h"

#include<vector>
#include<stdio.h>
#include<stdlib.h>
#define FINAL 10000

std::vector<int> stateStack;
FILE *fr;
elementoTabelaAuxiliar r;

int nextToken()
{
    int *a;
    fread(a, 4, 1, fr);
    printf("*%d*", *a);
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
        stateStack.pop_back();
    }
}

int top()
{
    return stateStack.back();
}

bool isShift(int input)
{
    if(input >= 0)
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
    printf("Erroooooooo!");
    exit(5);
}


void analiseSintatica()
{
    int q, a, p;
    fr = fopen("lexical.bin", "rb");
    if(!fr)
    {
        exit(2);
    }

    q = 0;
    push(0);
    a = nextToken();

    do 
    {
        //implementado em tabelaAcao
        p = action(q, a);
        if(isShift(p))
        {
            push(p);
            a = nextToken();
        }
        else if (isReduction(p))
        {
            //r e rule em tabelaAcao.h
            r = rule(p);
            pop(r.len);
            push(action(top(), r.left));
        }
        else
        {
            syntaxError();
        }
        q = top();
    } while (q != FINAL);
}

