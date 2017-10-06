#include "definitions.h"
//#include "analisador_lexico.h"
#include "analisador_escopo.h"

void semantics(elementoTabelaAuxiliar r)
{
    int name;
    object obj, *p;

    printf("-*%d*-\n", tokenSecundario);
    switch(r.rule)
    {
        case 69: 
                name = tokenSecundario;
                obj.nName = name;
                obj.pNext = NULL;
                break;
        case 75:
                name = tokenSecundario;
                obj.nName = name;
                if((p=Search(name)) != NULL)
                {
                    Error(ERR_REDECL);
                }
                else
                {
                    p=define(name);
                }
                obj.pNext = p;
                break;
                
        case 76:
                name = tokenSecundario;
                obj.nName = name;
                if((p=find(name)) == NULL)
                {
                    Error(ERR_NOT_DECL);
                    p=define(name);
                }
                obj.pNext = p;
                break;
                
            

        default:
            printf("MOPAMPOAMOPAMOPA\n");
    }
    
}

void PTS()
{
    printf("--%d--\n", tokenSecundario);
}
