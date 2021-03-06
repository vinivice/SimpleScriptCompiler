#include "definitions.h"
//#include "analisador_lexico.h"
#include "analisador_escopo.h"
#include <stdio.h>
#define IS_TYPE_KIND(k) ((k)==ARRAY_TYPE_ || (k)==STRUCT_TYPE_ || (k)==ALIAS_TYPE_ || (k)==SCALAR_TYPE_)

void semantics(elementoTabelaAuxiliar r)
{
    int name, n;
    printf("-*%d*-\n", tokenSecundario);
    printf("%d\n", r.rule);
    switch(r.rule)
    {
        case 5:
                oT.type = pInt;
                PushSem(oT);
                break;
        case 6:
                oT.type = pChar;
                PushSem(oT);
                break;
        case 7:
                oT.type = pBool;
                PushSem(oT);
                break;
        case 8:
                oT.type = pString;
                PushSem(oT);
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
                PushSem(oT);
                break;
        case 10:
                p = oIDD.obj;
                n = oNUM.iVal;
                t = oT.type;
                p->eKind = ARRAY_TYPE_;
                p->_.Array.nNumElems = n;
                p->_.Array.pElemType = t;
                break;
         case 11:		
                p = oIDD.obj;
                p->eKind = STRUCT_TYPE_;
                p->_.Struct.pFields = oDC.list;
                endBlock();
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
                PushSem(oDC0);
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
                PushSem(oDC);
                break;
        case 15:
                endBlock();
                break;
        case 16:
                p = oIDD.obj;
                t = oT.type;
                p->eKind = PARAM_;
                p->_.Param.pType = t;
                oLP0.list = oLP1.list;
                PushSem(oLP0);
                break;
         
        case 17:
                p = oIDD.obj;
                t = oT.type;
                p->eKind = PARAM_;
                p->_.Param.pType = t;
                oLP.list = p;
                PushSem(oLP);
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
                PushSem(oLI0);
                break;
        case 25:
                oLI.list = oIDD.obj;
                PushSem(oLI);
                break;
        case 26:
                t = oE.type;
                if( !CheckTypes(t, pBool) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                break;
                
        case 27:
                t = oE.type;
                if( !CheckTypes(t, pBool) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                break;
                
        case 28:
                t = oE.type;
                if( !CheckTypes(t, pBool) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                break;
                
        case 29:
                t = oE.type;
                if( !CheckTypes(t, pBool) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                break;
         
        case 30:
                endBlock();
                break;
        case 31:
                t1 = oLV.type;
                t2 = oE.type;
                if( ! CheckTypes( t1, t2 ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                break;
        case 34:
                if( !CheckTypes( oE1.type, pBool ) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                if( !CheckTypes( oL.type, pBool ) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                oE0.type = pBool;
                PushSem(oE0);
                break;
                
        case 35:
                if( !CheckTypes( oE1.type, pBool ) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                if( !CheckTypes( oL.type, pBool ) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                oE0.type = pBool;
                PushSem(oE0);
                break;
                
        case 36:
                oE.type = oL.type;
                PushSem(oE);
                break;
                
        case 37:
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                break;
                
        case 38:
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                break;
                
        case 39:
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                break;
                
        case 40:
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                break;
                
        case 41:
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                break;
                
        case 42:
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                break;
                
        case 43:
                oL.type = oR.type;
                PushSem(oL);
                break;

        case 44:
                if( !CheckTypes( oR1.type, oY.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                if( !CheckTypes( oR1.type, pInt )
                && !CheckTypes( oR1.type, pString ))
                {
                    Error( ERR_INVALID_TYPE );
                }
                oR0.type = oR1.type;
                PushSem(oR0);
                break;
                
        case 45:
                if( !CheckTypes( oR1.type, oY.type ) )
                {
                   Error( ERR_TYPE_MISMATCH );
                }
                if( !CheckTypes( oR1.type, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oR0.type = oR1.type;
                PushSem(oR0);
                break;
                
        case 46:
                oR.type = oY.type;
                PushSem(oR);
                break;
                
        case 47:
                if( !CheckTypes( oY1.type, oF.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                if( !CheckTypes( oY1.type, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oY0.type = oY1.type;
                PushSem(oY0);
                break;
                
        case 48:
                if( !CheckTypes( oY1.type, oF.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                if( !CheckTypes( oY1.type, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oY0.type = oY1.type;
                PushSem(oY0);
                break;
                
        case 49:
                oY.type = oF.type;
                PushSem(oY);
                break;
                
        case 50:
                oF.type = oLV.type;
                PushSem(oF);
                break;
                
        case 51:
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                PushSem(oF);
                break;
                
        case 52:
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                PushSem(oF);
                break;
                
        case 53:
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                PushSem(oF);
                break;
                
        case 54:
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                PushSem(oF);
                break;
                
        case 55:
                oF.type = oE.type;
                PushSem(oF);
                break;
        case 56:
                oF.type = oMC.type;
                if( !oMC.err )
                {
                    if( oLE.param != NULL )
                        Error( ERR_TOO_FEW_ARGS );
                }
                PushSem(oF);
                break;
         
        case 57:
                t = oF1.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                PushSem(oF);
                break;
                
        case 58:
                t = oF1.type;
                if( !CheckTypes( t, pBool ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF0.type = pBool;
                PushSem(oF0);
                break;
                
        case 59:
                oF.type = pBool;
                PushSem(oF);
                break;
                
        case 60:
                oF.type = pBool;
                PushSem(oF);
                break;
                
        case 61:
                oF.type = pChar;
                PushSem(oF);
                break;
                
        case 62:
                oF.type = pString;
                PushSem(oF);
                break;
                
        case 63:
                oF.type = pInt;
                PushSem(oF);
                break;
        case 64:
                oLE0.param = NULL;
                oLE0.err = oLE1.err;
                n = oLE1.n;
                if( !oLE1.err )
                {
                    p = oLE.param;
                    if( p == NULL )
                    {
                        Error(ERR_TOO_MANY_ARGS);
                        oLE0.err = true;
                    }
                }
                else
                {
                    if( !CheckTypes(
                    p->_.Param.pType,
                    oE.type ) )
                    {
                        Error( ERR_PARAM_TYPE, n);
                    }
                    oLE0.param = p->pNext;
                    oLE0.n = n+1;
                }
                PushSem(oLE0);
                break;
               
        case 65:
                oE = TopSem(0);
                oMC = TopSem(-1);
                oLE.param = NULL;
                oLE.err = oMC.err;
                n = 1;
                if( !oMC.err )
                {
                    p = oMC.param;
                    if( p == NULL )
                    {
                        Error(ERR_TOO_MANY_ARGS);
                        oLE.err = true;
                    }
                }
                else
                {
                    if( !CheckTypes(
                    p->_.Param.pType,
                    oE.type ) )
                    {
                        Error( ERR_PARAM_TYPE, n);
                    }
                    oLE.param = p->pNext;
                    oLE.n = n+1;
                }
                PushSem(oLE);
                break;
          
        case 66:
                t = oLV1.type;
                if( t->eKind != STRUCT_TYPE_ )
                {
                    if( t->eKind != UNIVERSAL_ )
                    {
                        Error( ERR_KIND_NOT_STRUCT );
                    }
                    oLV0.type = pUniversal;
                }
                else
                {
                    p = t->_.Struct.pFields;
                    while( p!= NULL )
                    {
                        if( p->nName == oID.nName )
                        {
                            break;
                        }
                        p = p->pNext;
                    }
                    if( p == NULL )
                    {
                        Error( ERR_FIELD_NOT_DECL );
                        oLV0.type = pUniversal;
                    }
                    else
                    {
                        oLV0.type = p->_.Field.pType;
                    }
                }
                PushSem(oLV0);
                break;
                
        case 67:
                t = oLV1.type;
                if( t == pString )
                {
                    oLV0.type = pChar;
                }
                else
                if( t->eKind != ARRAY_TYPE_ )
                {
                    if( t->eKind != UNIVERSAL_ )
                    {
                        Error( ERR_KIND_NOT_ARRAY );
                    }
                    oLV0.type = pUniversal;
                }
                else
                {
                    oLV0.type = t->_.Array.pElemType;
                }
                if( !CheckTypes( oE.type, pInt ) )
                {
                    Error( ERR_INVALID_INDEX_TYPE );
                }
                PushSem(oLV0);
                break;
                
        case 68:
                p = oIDU.obj;
                if( p->eKind != VAR_ &&
                p->eKind != PARAM_ )
                {
                    if( p->eKind != UNIVERSAL_ )
                    {
                        Error( ERR_KIND_NOT_VAR );
                    }
                    oLV.type = pUniversal;
                }
                else
                {
                    oLV.type = p->_.Var.pType;
                }
                PushSem(oLV);
                break;
         
        case 69: 
                name = tokenSecundario;
                oIDU.nName = name;
                oIDU.pNext = NULL;
                PushSem(oIDU);
                break;
        case 70:
                oTRUE.type = pBool;
                oTRUE.bVal = true;
                PushSem(oTRUE);
                break; 
        case 71:
                oFALSE.type = pBool;
                oFALSE.bVal = false;
                PushSem(oFALSE);
                break; 
        case 72:
                oCHR.type = pChar;
                oCHR.pos = tokenSecundario;
                oCHR.cVal = getCharConst(oCHR.pos);
                PushSem(oCHR);
                break;
        case 73:
                oSTR.type = pString;
                oSTR.pos = tokenSecundario;
                oSTR.sVal = getStringConst(oSTR.pos);
                PushSem(oSTR);
                break;
        case 74:
                oNUM.type = pInt;
                oNUM.pos = tokenSecundario;
                oNUM.iVal = getIntConst(oNUM.pos);
                PushSem(oNUM);
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
                PushSem(oIDD);
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
                PushSem(oIDU);
                break;
        case 77:
                newBlock();
                break;
                
        case 78:
                oT = TopSem(0);
                oLP = TopSem(-1);
                oNB = TopSem(-2);
                oIDD = TopSem(-3);
                f = oIDD.obj;
                f->eKind = FUNCTION_;
                f->_.Function.pRetType = oT.type;
                f->_.Function.pParams = oLP.list;
                break;
                
        case 79:
                oIDU = TopSem(0);
                f = oIDU.obj;
                if( f->eKind != FUNCTION_ )
                {
                    Error( ERR_KIND_NOT_FUNC );
                    oMC.type = pUniversal;
                    oMC.param = NULL;
                    oMC.err = true;
                }
                else
                {
                    oMC.type = f->_.Function.pRetType;
                    oMC.param = f->_.Function.pParams;
                    oMC.err = false;
                }
                break;
                
                   

        default:
            printf("MOPAMPOAMOPAMOPA\n");
    }
    
}

void PTS()
{
    printf("--%d--\n", tokenSecundario);
}
