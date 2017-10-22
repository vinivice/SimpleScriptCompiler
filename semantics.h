#include "definitions.h"
#include <stdlib.h>
//#include "analisador_lexico.h"
#include "analisador_escopo.h"
#include <stdio.h>
#define IS_TYPE_KIND(k) ((k)==ARRAY_TYPE_ || (k)==STRUCT_TYPE_ || (k)==ALIAS_TYPE_ || (k)==SCALAR_TYPE_)

void semantics(elementoTabelaAuxiliar r)
{
    int name, n, l;
    printf("\n\n Run semantics!!! \n\n");    
    printf("\n\nRule: %d\n\n",r.rule);
    //myOutputFile << "SEMANTICS\n";
 /*   object oIDD, oIDU, oT, oNUM, oLI, oLI0, oLI1, oDC, oDC0, oDC1, oSTR, oCHR, oTRUE, oFALSE, oNB, oLV0, oLV1, oID, oLE, oLE0, oLE1, oF0, oF1, oMC, oF, oY0, oY1, oY, oR0, oR1, oR, oL, oL0, oL1, oE0, oE1, oE, oLV, oLP, oLP0, oLP1;
    object *p, *t, *f, *t1, *t2;

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
*/
    printf("-*%d*-\n", tokenSecundario);
    switch(r.rule)
    {
        case 5:            
                oT.type = pInt;
                oT._.Type.nSize = 1;
                PushSem(oT);
                break;
        case 6:
                oT.type = pChar;
                oT._.Type.nSize = 1;
                PushSem(oT);
                break;
        case 7:
                oT.type = pBool;
                oT._.Type.nSize = 1;
                PushSem(oT);
                break;
        case 8:
                oT.type = pString;
                oT._.Type.nSize = 1;
                PushSem(oT);
                break;
        case 9:
                p = oIDU.obj;
                if(IS_TYPE_KIND(p->eKind) || p->eKind == UNIVERSAL_)
                {
                    oT.type = p;
                    oT._.Type.nSize = p->_.Alias.nSize;
                }
                else
                {
                    oT.type = pUniversal;
                    oT._.Type.nSize = 0;
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
                p->_.Array.nSize = n * oT._.Type.nSize;
                break;
         case 11:		
                p = oIDD.obj;
                p->eKind = STRUCT_TYPE_;
                p->_.Struct.pFields = oDC.list;
                p->_.Struct.nSize = oDC._.Type.nSize;
                endBlock();
                break;
        case 12:
                p = oIDD.obj;
                t = oT.type;
                p->eKind = ALIAS_TYPE_;
                p->_.Alias.pBaseType = t;
                p->_.Alias.nSize = oT._.Type.nSize;
                break;
        case 13:
                oDC1 = TopSem(0);
                p = oLI.list;
                t = oT.type;
                n = oDC1._.Type.nSize;
                while(p != NULL && p->eKind == NO_KIND_DEF_)
                {
                    p->eKind = FIELD_;
                    p->_.Field.pType = t;
                    p->_.Field.nIndex = n;
                    p->_.Field.nSize = oT._.Type.nSize;
                    n = n + oT._.Type.nSize;
                    p = p->pNext;
                }
                oDC0.list = oDC1.list;
                oDC0._.Type.nSize = n;
                PushSem(oDC0);
                break;
        case 14:
                p = oLI.list;
                t = oT.type;
                n = 0;
                while(p != NULL && p->eKind == NO_KIND_DEF_)
                {
                    p->eKind = FIELD_;
                    p->_.Field.pType = t;
                    p->_.Field.nIndex = n;
                    p->_.Field.nSize = oT._.Type.nSize;
                    n = n + oT._.Type.nSize;
                    p = p->pNext;
                }
                oDC.list = oLI.list;
                oDC._.Type.nSize = n;
                PushSem(oDC);
                break;
        case 15:
                endBlock();
                break;
        case 16:
                oLP1 = TopSem(0);
                p = oIDD.obj;
                t = oT.type;
                n = oLP1._.Type.nSize;
                p->eKind = PARAM_;
                p->_.Param.pType = t;
                p->_.Param.nIndex = n;
                p->_.Param.nSize = oT._.Type.nSize;
                oLP0.list = oLP1.list;
                oLP0._.Type.nSize = n + oT._.Type.nSize;
                PushSem(oLP0);
                break;
         
        case 17:
                p = oIDD.obj;
                t = oT.type;
                p->eKind = PARAM_;
                p->_.Param.pType = t;
                p->_.Param.nIndex = 0;
                p->_.Param.nSize = oT._.Type.nSize;
                oLP.list = p;
                oLP._.Type.nSize = oT._.Type.nSize;
                PushSem(oLP);
                break;

        case 18:
                oMF = TopSem(-2);
                oIDD = TopSem(-6);              
                o = oIDD.obj;
                offset = oMF.offset;
                myOutputFile << "END_FUNC\n";
                current = myOutputFile.tellp();
                myOutputFile.seekp(offset);
                myOutputFile << o->_.Function.nVars;
                myOutputFile.seekp(current);
                break;
        
        case 23:
                p = oLI.list;
                t = oT.type;
                n = curFunction->_.Function.nVars;
                while(p != NULL && p->eKind == NO_KIND_DEF_)
                {
                    p->eKind = VAR_;
                    p->_.Var.pType = t;
                    p->_.Var.nIndex = n;
                    p->_.Var.nSize = oT._.Type.nSize;
                    n += oT._.Type.nSize;
                    p = p->pNext;
                }
                curFunction->_.Function.nVars = n;
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
                oLV = TopSem(0);
                PopSem(1);                
                t1 = oLV.type;
                t2 = oE.type;
                printf("\n t1, t2: %p, %p\n", t1, t2);
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
                printf("\noL.type, oL1.type: %p, %p\n", oL.type, oL1.type);
                oL1 = TopSem(0);
                PopSem(1);
                printf("\n\nPointers: oL1.type %p - oR.type %p\n\n", oL1.type, oR.type);
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                myOutputFile << "\tEQ\n";
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
                oIDD.obj = p;
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
                oIDU.obj = p;
                PushSem(oIDU);
                break;
        case 77:
                PushSem(oNB);
                newBlock();
                break;
                
        case 78:
                oT = TopSem(0);
                oLP = TopSem(-1);
                oNB = TopSem(-2);
                oIDD = TopSem(-3);
                PopSem(4);
                o = oIDD.obj;
                o->_.Function.pRetType = oT.type;
                o->_.Function.pParams = oLP.list;
                o->_.Function.nParams = oLP._.Type.nSize;                
                curFunction = o;
                myOutputFile << "BEGIN_FUNC " << nFuncs - 1 << ", " << o->_.Function.nParams << ", " << 0 << "\n";
                oMF.offset = myOutputFile.tellp() - (long)3;
                PushSem(oMF);
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

        case 80:   
                oIDD = TopSem(0);
                f = oIDD.obj;
                f->eKind = FUNCTION_;
                f->_.Function.nParams = 0;
                f->_.Function.pVars = 0;
                f->_.Function.nIndex = nFuncs++;
                newBlock();
                break;                   

        case 81:
            l = newLabel();
            oMT.label = l;
            myOutputFile << "\tTJMP_FW L" << l << "\n";
            
        default:
            printf("MOPAMPOAMOPAMOPA\n");
    }
    printf("\n\n Go out semantics!!! \n\n");
}

void PTS()
{
    printf("--%d--\n", tokenSecundario);
}
