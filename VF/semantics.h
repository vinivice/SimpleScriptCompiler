#include "definitions.h"
#include <stdlib.h>
#include "analisador_escopo.h"
#include <stdio.h>
#define IS_TYPE_KIND(k) ((k)==ARRAY_TYPE_ || (k)==STRUCT_TYPE_ || (k)==ALIAS_TYPE_ || (k)==SCALAR_TYPE_)

void semantics(elementoTabelaAuxiliar r)
{
    int name, n, l, l1, l2;
    switch(r.rule)
    {
//05 : T -> 'integer'
        case 5:            
                oT.type = pInt;
                oT._.Type.nSize = 1;
                PushSem(oT);
                break;

//06 : T -> 'char'
        case 6:
                oT.type = pChar;
                oT._.Type.nSize = 1;
                PushSem(oT);
                break;

//07 : T -> 'boolean'
        case 7:
                oT.type = pBool;
                oT._.Type.nSize = 1;
                PushSem(oT);
                break;

//08 : T -> 'string'
        case 8:
                oT.type = pString;
                oT._.Type.nSize = 1;
                PushSem(oT);
                break;

//09 : T -> IDU
        case 9:
                oIDU = TopSem(0);
                PopSem(1);
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

//10 : DT -> 'type' IDD '=' 'array' '[' NUM ']' 'of' T
        case 10:
                oT = TopSem(0);
                oNUM = TopSem(-1);
                oIDD = TopSem(-2);
                PopSem(3);
                p = oIDD.obj;
                n = oNUM.iVal;
                t = oT.type;
                p->eKind = ARRAY_TYPE_;
                p->_.Array.nNumElems = n;
                p->_.Array.pElemType = t;
                p->_.Array.nSize = n * oT._.Type.nSize;
                break;

//11 : DT -> 'type' IDD '=' 'struct' NB '{' DC '}'
         case 11:		
                oDC = TopSem(0);
                oNB = TopSem(-1);
                oIDD = TopSem(-2);
                PopSem(3);
                p = oIDD.obj;
                p->eKind = STRUCT_TYPE_;
                p->_.Struct.pFields = oDC.list;
                p->_.Struct.nSize = oDC._.Type.nSize;
                endBlock();
                break;

//12 : DT -> 'type' IDD '=' T
        case 12:
                oT = TopSem(0);
                oIDD = TopSem(-1);
                PopSem(2);
                p = oIDD.obj;
                t = oT.type;
                p->eKind = ALIAS_TYPE_;
                p->_.Alias.pBaseType = t;
                p->_.Alias.nSize = oT._.Type.nSize;
                break;

//13 : DC -> DC ';' LI ':' T
        case 13:
                oT = TopSem(0);
                oLI = TopSem(-1);
                oDC1 = TopSem(-2);
                PopSem(3);
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

//14 : DC -> LI ':' T
        case 14:
                oT = TopSem(0);
                oLI = TopSem(-1);
                PopSem(2);
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

//15 : DF -> 'function' IDD NF '(' LP ')' ':' T MF B
        case 15: 
                oMF = TopSem(0);
                oT = TopSem(-1);
                oLP = TopSem(-2);
                oIDD = TopSem(-3);              
                PopSem(4);
                o = oIDD.obj;
                offset = oMF.offset;
                myOutputFile << "END_FUNC\n";
                current = myOutputFile.tellp();
                myOutputFile.seekp(offset+1);
                myOutputFile << o->_.Function.nVars;
                myOutputFile.seekp(current);
                break;

//16 : LP -> LP ',' IDD ':' T
        case 16:
                oT = TopSem(0);
                oIDD = TopSem(-1);
                oLP1 = TopSem(-2);
                PopSem(3);
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
         

//17 : LP -> IDD ':' T
        case 17:
                oT = TopSem(0);
                oIDD = TopSem(-1);
                PopSem(2);
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


//18 : B -> '{' LDV LS '}'
        case 18:
               endBlock();
               break;
        

//23 : DV -> 'var' LI ':' T ';'
        case 23:
                oT = TopSem(0);
                oLI = TopSem(-1);
                PopSem(2);
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
                

//24 : LI -> LI ',' IDD
        case 24:
                oIDD = TopSem(0);
                oLI1 = TopSem(-1);
                PopSem(2);
                oLI0.list = oLI1.list;
                PushSem(oLI0);
                break;

//25 : LI -> IDD
        case 25:
                oIDD = TopSem(0);
                PopSem(1);
                oLI.list = oIDD.obj;
                PushSem(oLI);
                break;

//26: S -> 'if' '(' E ')' MT S
        case 26:
                oMT = TopSem(0);
                oE = TopSem(-1);
                PopSem(2);
                t = oE.type;
                l = oMT.label;
                if( !CheckTypes(t, pBool) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                myOutputFile << "L" << l << ":\n";
                break;

//27 : S -> 'if' '(' E ')' MT S 'else' ME S         
        case 27:
                oME = TopSem(0);
                oMT = TopSem(-1);
                oE = TopSem(-2);
                PopSem(3);
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
                oMT = TopSem(0);
                oE = TopSem(-1);
                oMW = TopSem(-2);
                PopSem(3);
                t = oE.type;
                l1 = oMW.label;
                l2 = oMT.label;
                if( !CheckTypes(t, pBool) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                myOutputFile << "\tJMP_BW L" << l1 << "\nL" << l2 << ":\n";
                break;
               
//29 : S -> 'do' MW S 'while' '(' E ')' ';' 
        case 29:
                oE = TopSem(0);
                oMW = TopSem(-1);
                PopSem(2);
                t = oE.type;
                l = oMW.label;
                if( !CheckTypes(t, pBool) )
                {
                    Error( ERR_BOOL_TYPE_EXPECTED );
                }
                myOutputFile << "\tNOT\n\tTJMP_BW L" << l << "\n";
                break;
        
//30 : S -> NB B
        case 30:
                oNB = TopSem(0);
                PopSem(1);                
                endBlock();
                break;


//31 : S -> LV '=' E ';'
        case 31:                
                oE = TopSem(0);
                oLV = TopSem(-1);
                PopSem(2);                
                t1 = oLV.type;
                t2 = oE.type;
                if( ! CheckTypes( t1, t2 ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                myOutputFile << "\tSTORE_REF " << t1->_.Type.nSize << "\n";
                break;

//34 : E -> E '&&' L
        case 34:
                oL = TopSem(0);
                oE1 = TopSem(-1);
                PopSem(2);
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
                oL = TopSem(0);
                oE1 = TopSem(-1);
                PopSem(2);
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
                
//36 : E -> L
        case 36:
                oL = TopSem(0);
                PopSem(1);
                oE.type = oL.type;
                PushSem(oE);
                break;
                
//37 : L -> L '<' R
        case 37:
                oR = TopSem(0);
                oL1 = TopSem(-1);
                PopSem(2);
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
                oR = TopSem(0);
                oL1 = TopSem(-1);
                PopSem(2);
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
                oR = TopSem(0);
                oL1 = TopSem(-1);
                PopSem(2);
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
                oR = TopSem(0);
                oL1 = TopSem(-1);
                PopSem(2);
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
                oR = TopSem(0);
                oL1 = TopSem(-1);
                PopSem(2);
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
                oR = TopSem(0);
                oL1 = TopSem(-1);
                PopSem(2);
                if( !CheckTypes( oL1.type, oR.type ) )
                {
                    Error( ERR_TYPE_MISMATCH );
                }
                oL0.type = pBool;
                PushSem(oL0);
                myOutputFile << "\tNE\n" ;
                break;
                

//43 : L -> R
        case 43:
                oR = TopSem(0);
                PopSem(1);
                oL.type = oR.type;
                PushSem(oL);
                break;

//44 : R -> R '+' Y
        case 44:
                oY = TopSem(0);
                oR1 = TopSem(-1);
                PopSem(2);
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
                oY = TopSem(0);
                oR1 = TopSem(-1);
                PopSem(2);
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
                

//46 : R -> Y
        case 46:
                oY = TopSem(0);
                PopSem(1);
                oR.type = oY.type;
                PushSem(oR);
                break;

//47 : Y -> Y '*' F
        case 47:
                oF = TopSem(0);
                oY1 = TopSem(-1);
                PopSem(2);
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
                oF = TopSem(0);
                oY1 = TopSem(-1);
                PopSem(2);
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
                

//49 : Y -> F
        case 49:
                oF = TopSem(0);
                PopSem(1);
                oY.type = oF.type;
                PushSem(oY);                
                break;

//50 : F -> LV
        case 50:
                oLV = TopSem(0);
                PopSem(1);
                oF.type = oLV.type;
                n = oLV.type->_.Type.nSize;
                myOutputFile << "\tDE_REF " << n << "\n" ;                
                PushSem(oF);
                break;

//51 : F -> '++' LV 
        case 51:
                oLV = TopSem(0);
                PopSem(1);
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                myOutputFile << "\tDUP\n\tDUP\tDE_REF 1\n" ;
                myOutputFile << "\tINC\n\tSTORE_REF 1\tDE_REF 1\n" ;
                PushSem(oF);
                break;

//52 : F -> '--' LV 
        case 52:
                oLV = TopSem(0);
                PopSem(1);
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                myOutputFile << "\tDUP\n\tDUP\tDE_REF 1\n" ;
                myOutputFile << "\tDEC\n\tSTORE_REF 1\tDE_REF 1\n" ;
                PushSem(oF);
                break;
               
//53 : F -> LV '++' 
        case 53:
                oLV = TopSem(0);
                PopSem(1);
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                myOutputFile << "\tDUP\n\tDUP\tDE_REF 1\n\tINC\n" ;
                myOutputFile << "\tSTORE_REF 1\tDE_REF 1\nDEC\n" ;
                PushSem(oF);
                break;
               
//54 : F -> LV '--' 
        case 54:
                oLV = TopSem(0);
                PopSem(1);
                t = oLV.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                myOutputFile << "\tDUP\n\tDUP\tDE_REF 1\n\tDEC\n" ;
                myOutputFile << "\tSTORE_REF 1\tDE_REF 1\nINC\n" ;
                PushSem(oF);
                break;
                

//55 : F -> '(' E ')'
        case 55:
                oE = TopSem(0);
                PopSem(1);
                oF.type = oE.type;
                PushSem(oF);
                break;

//56 : F -> IDU MC '(' LE ')'
        case 56:
                oLE = TopSem(0);
                oMC = TopSem(-1);
                oIDU = TopSem(-2);
                PopSem(3);
                oF.type = oMC.type;
                func = oIDU.obj;
                if( !oMC.err )
                {
                    if( oLE.param != NULL )
                        Error( ERR_TOO_FEW_ARGS );
                }
                myOutputFile << "\tCALL " << func->_.Function.nIndex;
                PushSem(oF);
                break;
        
//57 : F -> '-' F 
        case 57:
                oF1 = TopSem(0);
                PopSem(1);
                t = oF1.type;
                if( !CheckTypes( t, pInt ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF.type = pInt;
                myOutputFile << "\tNEG\n" ;
                PushSem(oF);
                break;
                
//58 : F -> '!' F
        case 58:
                oF1 = TopSem(0);
                PopSem(1);
                t = oF1.type;
                if( !CheckTypes( t, pBool ) )
                {
                    Error( ERR_INVALID_TYPE );
                }
                oF0.type = pBool;
                myOutputFile << "\tNOT\n" ;
                PushSem(oF0);
                break;
               
//59 : F -> TRUE 
        case 59:
                oTRUE = TopSem(0);
                PopSem(1);
                oF.type = pBool;
                n = tokenSecundario;
                myOutputFile << "\tLOAD_CONST " << n << "\n" ;                
                PushSem(oF);
                break;

//60 : F -> FALSE
        case 60:
                oFALSE = TopSem(0);
                PopSem(1);
                oF.type = pBool;
                n = tokenSecundario;
                myOutputFile << "\tLOAD_CONST " << n << "\n" ;                
                PushSem(oF);
                break;
        
//61 : F -> CHR        
        case 61:
                oCHR = TopSem(0);
                PopSem(1);
                oF.type = pChar;
                n = tokenSecundario;
                myOutputFile << "\tLOAD_CONST " << n << "\n" ;                
                PushSem(oF);
                break;
                
//62 : F -> STR
        case 62:
                oSTR = TopSem(0);
                PopSem(1);
                oF.type = pString;
                n = tokenSecundario;
                myOutputFile << "\tLOAD_CONST " << n << "\n" ;                
                PushSem(oF);
                break;
               
//63 : F -> NUM 
        case 63:
                oNUM = TopSem(0);
                PopSem(1);
                oF.type = pInt;
                n = tokenSecundario;
                myOutputFile << "\tLOAD_CONST " << n << "\n" ;                
                PushSem(oF);
                break;

//64 : LE -> LE ',' E
        case 64:
                oE = TopSem(0);
                oLE1 = TopSem(-1);
                PopSem(2);
                oLE0.param = NULL;
                oLE0.err = oLE1.err;
                n = oLE1.n;
                if( !oLE1.err )
                {
                    p = oLE1.param;
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
               
//65 : LE -> E
        case 65:
                oE = TopSem(0);
                oMC = TopSem(-1);
                PopSem(1);
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
                oIDU = TopSem(0);
                oLV1 = TopSem(-1);
                PopSem(2);
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
                oE = TopSem(0);
                oLV1 = TopSem(-1);
                PopSem(2);
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
                oIDU = TopSem(0);
                PopSem(1);
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
                    myOutputFile << "\tLOAD_REF " << p->nName << "\n" ;
                }
                PushSem(oLV);
                break;
         
//69 : ID_N_TERMINAL -> 'Id'
        case 69: 
                name = tokenSecundario;
                oIDU.nName = name;
                oIDU.pNext = NULL;
                PushSem(oIDU);
                break;

//70 : TRU -> 'true'
        case 70:
                oTRUE.type = pBool;
                oTRUE.bVal = true;
                PushSem(oTRUE);
                break; 

//71 : FAL -> 'false'
        case 71:
                oFALSE.type = pBool;
                oFALSE.bVal = false;
                PushSem(oFALSE);
                break; 

//72 : CHR -> 'c'
        case 72:
                oCHR.type = pChar;
                oCHR.pos = tokenSecundario;
                oCHR.cVal = getCharConst(oCHR.pos);
                PushSem(oCHR);
                break;

//73 : STR -> 's'
        case 73:
                oSTR.type = pString;
                oSTR.pos = tokenSecundario;
                oSTR.sVal = getStringConst(oSTR.pos);
                PushSem(oSTR);
                break;

//74 : NUM -> 'n'
        case 74:
                oNUM.type = pInt;
                oNUM.pos = tokenSecundario;
                oNUM.iVal = getIntConst(oNUM.pos);
                PushSem(oNUM);
                break;

//75 : IDD -> 'Id'
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
                
//76 : IDU -> 'Id'
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

//77 : NB -> ''
        case 77:
                PushSem(oNB);
                newBlock();
                break;
                
//78 : MF -> ''
        case 78:
                oT = TopSem(0);
                oLP = TopSem(-1);
                oIDD = TopSem(-2);
                o = oIDD.obj;
                o->_.Function.pRetType = oT.type;
                o->_.Function.pParams = oLP.list;
                o->_.Function.nParams = oLP._.Type.nSize;                
                curFunction = o;
                myOutputFile << "BEGIN_FUNC " << nFuncs - 1 << ", " << o->_.Function.nParams << ", " << 0 << "\n";
                oMF.offset = myOutputFile.tellp() - (long)3;
                PushSem(oMF);
                break;
                
//79 : MC -> ''
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
                PushSem(oMC);
                break;

//80 : NF -> ''
        case 80:   
                oIDD = TopSem(0);
                f = oIDD.obj;
                f->eKind = FUNCTION_;
                f->_.Function.nParams = 0;
                f->_.Function.pVars = 0;
                f->_.Function.nIndex = nFuncs++;
                newBlock();
                break;                   
            
//81 : MT -> ''
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
                myOutputFile << "\tJMP_FW L" << l2 << "\nL" << l1 << ":\n";        
                PushSem(oME);
                break;

//83 : MW -> ''
        case 83:
                l = newLabel();
                oMW.label = l;
                myOutputFile << "L" << l << ":\n";
                PushSem(oMW);

    }
}
