#include "definitions.h"
//#include "analisador_lexico.h"
#include "analisador_escopo.h"
#define IS_TYPE_KIND(k) ((k)==ARRAY_TYPE_ || (k)==STRUCT_TYPE_ || (k)==ALIAS_TYPE_ || (k)==SCALAR_TYPE_)

void semantics(elementoTabelaAuxiliar r)
{
    int name, n;
    object oIDD, oIDU, oT, oNUM, oLI, oLI0, oLI1, oDC, oDC0, oDC1, oSTR, oCHR, oTRUE, oFALSE;
    object *p, *t;

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

    printf("-*%d*-\n", tokenSecundario);
    switch(r.rule)
    {
        case 5:
                oT.type = pInt;
                break;
        case 6:
                oT.type = pChar;
                break;
        case 7:
                oT.type = pBool;
                break;
        case 8:
                oT.type = pString;
                break;
        case 9:
                p = oIDU.obj;
                if(IS_TYPE_KIND(p->eKind) || p->eKind == UNIVERSAL_)
                {
                    oT.type = p;
                }
                else
                {
                    oT.type = pUniversal;
                    Error(ERR_TYPE_EXPECTED);
                }
                break;
        case 10:
                p = oIDD.obj;
                n = oNUM.iVal;
                t = oT.type;
                p->eKind = ARRAY_TYPE_;
                p->_.Array.nNumElems = n;
                p->_.Array.pElemType = t;
                break;
        case 12:
                p = oIDD.obj;
                t = oT.type;
                p->eKind - ALIAS_TYPE_;
                p->_.Alias.pBaseType = t;
                break;
        case 13:
                p = oLI.list;
                t = oT.type;
                while(p != NULL && p->eKind == NO_KIND_DEF_)
                {
                    p->eKind = FIELD_;
                    p->_.Field.pType = t;
                    p = p->pNext;
                }
                oDC0.list = oDC1.list;
                break;
        case 14:
                p = oLI.list;
                t = oT.type;
                while(p != NULL && p->eKind == NO_KIND_DEF_)
                {
                    p->eKind = FIELD_;
                    p->_.Field.pType = t;
                    p = p->pNext;
                }
                oDC.list = oLI.list;
                break;
        case 11:
        case 15:
                endBlock();
                break;
        case 23:
                p = oLI.list;
                t = oT.type;
                while(p != NULL && p->eKind == NO_KIND_DEF_)
                {
                    p->eKind = VAR_;
                    p->_.Var.pType = t;
                    p = p->pNext;
                }
                break;
        case 24:
                oLI0.list = oLI1.list;
                break;
        case 25:
                oLI.list = oIDD.obj;
                break;
        case 69: 
                name = tokenSecundario;
                oIDU.nName = name;
                oIDU.pNext = NULL;
                break;
        case 70:
                oTRUE.type = pBool;
                oTRUE.bVal = true;
                break; 
        case 71:
                oFALSE.type = pBool;
                oFALSE.bVal = false;
                break; 
        case 72:
                oCHR.type = pChar;
                oCHR.pos = tokenSecundario;
                oCHR.cVal = getCharConst(oCHR.pos);
                break;
        case 73:
                oSTR.type = pString;
                oSTR.pos = tokenSecundario;
                oSTR.sVal = getStringConst(oSTR.pos);
                break;
        case 74:
                oNUM.type = pInt;
                oNUM.pos = tokenSecundario;
                oNUM.iVal = getIntConst(oNUM.pos);
                break;
        case 75:
                name = tokenSecundario;
                oIDD.nName = name;
                if((p=Search(name)) != NULL)
                {
                    Error(ERR_REDECL);
                }
                else
                {
                    p=define(name);
                }
                p->eKind = NO_KIND_DEF_;
                oIDD.pNext = p;
                break;
                
        case 76:
                name = tokenSecundario;
                oIDU.nName = name;
                if((p=find(name)) == NULL)
                {
                    Error(ERR_NOT_DECL);
                    p=define(name);
                }
                oIDU.pNext = p;
                break;
        case 77:
                newBlock();
                break;
                
            

        default:
            printf("MOPAMPOAMOPAMOPA\n");
    }
    
}

void PTS()
{
    printf("--%d--\n", tokenSecundario);
}
