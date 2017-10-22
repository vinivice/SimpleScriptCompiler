#include "definitions.h"
#include <stdlib.h>
//#include "analisador_lexico.h"
#include "analisador_escopo.h"
#include <stdio.h>
#define IS_TYPE_KIND(k) ((k)==ARRAY_TYPE_ || (k)==STRUCT_TYPE_ || (k)==ALIAS_TYPE_ || (k)==SCALAR_TYPE_)

void semantics(elementoTabelaAuxiliar r)
{
    int name, n, l, l1, l2;
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

//26: S -> 'if' '(' E ')' MT S
        case 26:
                t = oE.type;
                l = oMT.label;
                if( !CheckTypes(t, pBool) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                myOutputFile << "L" << l << "\n";
                break;

//27 : S -> 'if' '(' E ')' MT S 'else' ME S         
        case 27:
                t = oE.type;
                l = oME.label;
                if( !CheckTypes(t, pBool) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                myOutputFile << "L" << l << ":\n";
                break;

//28 : S -> 'while' MW '(' E ')' MT S                
        case 28:
                t = oE.type;
                l1 = oMW.label;
                l2 = oMT.label;
                if( !CheckTypes(t, pBool) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                myOutputFile << "\tJMP_BW L" << l1 << "\nL" << l2 << "\n";
                break;
               
//29 : S -> 'do' MW S 'while' '(' E ')' ';' 
        case 29:
                t = oE.type;
                l = oMW.label;
                if( !CheckTypes(t, pBool) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                myOutputFile << "\tNOT\n\tTJMP_BW L" << l << "\n";
                break;
         
        case 30:
                endBlock();
                break;

//31 : S -> LV '=' E ';'
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
                myOutputFile << "\tSTORE_REF " << t->_.Type.nSize << "\n";
                break;

//34 : E -> E '&&' L
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
                myOutputFile << "\tAND\n" ;
                break;

//35 : E -> E '||' L
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
                myOutputFile << "\tOR\n" ;                
                break;
                
        case 36:
                oE.type = oL.type;
                PushSem(oE);
                break;
                
//37 : L -> L '<' R
        case 37:
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                myOutputFile << "\tLT\n" ;
                break;

//38 : L -> L '>' R
        case 38:
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                myOutputFile << "\tGT\n" ;
                break;

//39 : L -> L '<=' R 
        case 39:
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                myOutputFile << "\tLE\n" ;
                break;

//40 : L -> L '>=' R                
        case 40:
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                myOutputFile << "\tGE\n" ;
                break;
                
//41 : L -> L '==' R
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
                PushSem(oL0);
                myOutputFile << "\tEQ\n" ;
                break;
                
//42 : L -> L '!=' R
        case 42:
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                myOutputFile << "\tNE\n" ;
                break;
                
        case 43:
                oL.type = oR.type;
                PushSem(oL);
                break;

//44 : R -> R '+' Y
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
                myOutputFile << "\tADD\n" ;
                break;

//45 : R -> R '-' Y
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
                myOutputFile << "\tSUB\n" ;
                break;
                
        case 46:
                oR.type = oY.type;
                PushSem(oR);
                break;

//47 : Y -> Y '*' F
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
                myOutputFile << "\tMUL\n" ;
                break;

//48 : Y -> Y '/' F
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
                myOutputFile << "\tDIV\n" ;
                break;
                
        case 49:
                oY.type = oF.type;
                PushSem(oY);                
                break;

//50 : F -> LV
        case 50:
                oF.type = oLV.type;
                PushSem(oF);
                n = oLV.type->_.Type.nSize;
                myOutputFile << "\tDE_REF " << n << "\n" ;                
                break;

//51 : F -> '++' LV 
        case 51:
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                PushSem(oF);
                myOutputFile << "\tDUP\n\tDUP\tDE_REF 1\n" ;
                myOutputFile << "\tINC\n\tSTORE_REF 1\tDE_REF 1\n" ;
                break;

//52 : F -> '--' LV 
        case 52:
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                PushSem(oF);
                myOutputFile << "\tDUP\n\tDUP\tDE_REF 1\n" ;
                myOutputFile << "\tDEC\n\tSTORE_REF 1\tDE_REF 1\n" ;
                break;
               
//53 : F -> LV '++' 
        case 53:
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                PushSem(oF);
                myOutputFile << "\tDUP\n\tDUP\tDE_REF 1\n\tINC\n" ;
                myOutputFile << "\tSTORE_REF 1\tDE_REF 1\nDEC\n" ;
                break;
               
//54 : F -> LV '--' 
        case 54:
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                PushSem(oF);
                myOutputFile << "\tDUP\n\tDUP\tDE_REF 1\n\tDEC\n" ;
                myOutputFile << "\tSTORE_REF 1\tDE_REF 1\nINC\n" ;
                break;
                
        case 55:
                oF.type = oE.type;
                PushSem(oF);
                break;

//56 : F -> IDU MC '(' LE ')'
        case 56:
                oF.type = oMC.type;
                func = oIDU.obj;
                if( !oMC.err )
                {
                    if( oLE.param != NULL )
                        Error( ERR_TOO_FEW_ARGS );
                }
                PushSem(oF);
                myOutputFile << "\tCALL " << func->_.Function.nIndex;
                break;
        
//57 : F -> '-' F 
        case 57:
                t = oF1.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                PushSem(oF);
                myOutputFile << "\tNEG\n" ;
                break;
                
//58 : F -> '!' F
        case 58:
                t = oF1.type;
                if( !CheckTypes( t, pBool ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF0.type = pBool;
                PushSem(oF0);
                myOutputFile << "\tNOT\n" ;
                break;
               
//59 : F -> TRUE 
        case 59:
                oF.type = pBool;
                PushSem(oF);
                n = tokenSecundario;
                myOutputFile << "\tLOAD_CONST " << n << "\n" ;                
                break;

//60 : F -> FALSE
        case 60:
                oF.type = pBool;
                PushSem(oF);
                n = tokenSecundario;
                myOutputFile << "\tLOAD_CONST " << n << "\n" ;                
                break;
        
//61 : F -> CHR        
        case 61:
                oF.type = pChar;
                PushSem(oF);
                n = tokenSecundario;
                myOutputFile << "\tLOAD_CONST " << n << "\n" ;                
                break;
                
//62 : F -> STR
        case 62:
                oF.type = pString;
                PushSem(oF);
                n = tokenSecundario;
                myOutputFile << "\tLOAD_CONST " << n << "\n" ;                
                break;
               
//63 : F -> NUM 
        case 63:
                oF.type = pInt;
                PushSem(oF);
                n = tokenSecundario;
                myOutputFile << "\tLOAD_CONST " << n << "\n" ;                
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

//66 : LV -> LV '.' IDU          
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
                        myOutputFile << "\tADD " << p->_.Field.nIndex << "\n" ;
                    }
                }
                PushSem(oLV0);
                break;
               
//67 : LV -> LV '[' E ']' 
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
                    myOutputFile << "\tMUL " << t->_.Array.pElemType->_.Type.nSize << "\n\tADD\n" ;
                }
                if( !CheckTypes( oE.type, pInt ) )
                {
                    Error( ERR_INVALID_INDEX_TYPE );
                }
                PushSem(oLV0);
                break;
               
//68 : LV -> IDU 
        case 68:
                p = oIDU.obj;
                if( p->eKind != VAR_ && p->eKind != PARAM_ )
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
                    myOutputFile << "\tLOAD_REF " << t->_.Var.pType->_.Type.nSize << "\n\tADD\n" ;
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
                printf("\noIDD no topo: %p\n", oIDD.obj);
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

//80 : NF -> ''
        case 80:   
                oIDD = TopSem(0);
                f = oIDD.obj;
                printf("\n\ncase 80: %p\n\n", f);
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
                PushSem(oMT);
                break;

//82 : ME -> ''
        case 82:
                oMT = TopSem(-1);
                l1 = oMT.label;
                l2 = newLabel();
                oME.label = l2;
                myOutputFile << "\tJMP_FW L" << l2 << "\nL" << l1 << "\n";        
                break;

//83 : MW -> ''
        case 83:
                l = newLabel();
                oMW.label = l;
                myOutputFile << "L" << l << "\n";

        default:
            printf("MOPAMPOAMOPAMOPA\n");
    }
    printf("\n\n Go out semantics!!! \n\n");
}

void PTS()
{
    printf("--%d--\n", tokenSecundario);
}
