#include "definitions.h"
#include <vector>

object* symbolTable[MAX_NEST_LEVEL];
object* symbolTableLast[MAX_NEST_LEVEL];
int nCurrentLevel = -1;

int newBlock(void)
{
    nCurrentLevel++;
    symbolTable[nCurrentLevel] = NULL;
    symbolTableLast[nCurrentLevel] = NULL;
    return nCurrentLevel;
}

int endBlock(void)
{
    nCurrentLevel--;
    return nCurrentLevel;
}

object* define(int aName)
{
    object *obj = new object;

    obj->nName = aName;
    obj->pNext = NULL;

    if(symbolTable[nCurrentLevel] == NULL)
    {
       symbolTable[nCurrentLevel] = obj; 
       symbolTableLast[nCurrentLevel] = obj; 
    }
    else
    {
       symbolTableLast[nCurrentLevel]->pNext = obj; 
       symbolTableLast[nCurrentLevel] = obj; 
    }
    return obj;
}

object* Search(int aName)
{
    object *obj = symbolTable[nCurrentLevel];

    while(obj != NULL)
    {
        if(obj->nName == aName)
        {
           break;
        }
        else
        {
            obj = obj->pNext;
        }
    }
    return obj;
}

object* find(int aName)
{
    int i;
    object *obj = NULL;

    for(i = nCurrentLevel; i >= 0; i--)
    {
        obj = symbolTable[i];

        while(obj != NULL)
        {
            if(obj->nName == aName)
            {
                break;
            }
            else
            {
                obj = obj->pNext;
            }
        }

        if(obj != NULL)
        {
            break;
        }
    }
    return obj;
}
