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
                
            
            //FIXFIXFIXFIX
            
            case 77: 
		NewBlock();
		break;
		
case 11:		
		p = IDD.obj;
		p->eKind = STRUCT_TYPE_;
		p->_.Struct.pFields = DC.list;
		EndBlock();
		break;
		
case 17:
		p = IDD.obj;
		t = T.type;
		p->eKind = PARAM_;
		p->_.Param.pType = t;
		LP.list = p;
		break;
		
case 16:
		p = IDD.obj;
		t = T.type;
		p->eKind = PARAM_;
		p->_.Param.pType = t;
		LP0.list = LP1.list;
		break;
		
case 78:
		T = TopSem(0);
		LP = TopSem(-1);
		NB = TopSem(-2);
		IDD = TopSem(-3);
		f = IDD.obj;
		f->eKind = FUNCTION_;
		f->_.Function.pRetType = T.type;
		f->_.Function.pParams = LP.list;
		break;
		
case 15:
		EndBlock();
		break;
		
case 30:
		EndBlock();
		break;
		
case 26:
		t = E.type;
		if( !CheckTypes(t, pBool) )
		{
			Error( ERR_BOOL_TYPE_EXPECTED );
		}
		break;
		
case 27:
		t = E.type;
		if( !CheckTypes(t, pBool) )
		{
			Error( ERR_BOOL_TYPE_EXPECTED );
		}
		break;
		
case 28:
		t = E.type;
		if( !CheckTypes(t, pBool) )
		{
			Error( ERR_BOOL_TYPE_EXPECTED );
		}
		break;
		
case 29:
		t = E.type;
		if( !CheckTypes(t, pBool) )
		{
			Error( ERR_BOOL_TYPE_EXPECTED );
		}
		break;
		
case 31:
		t1 = LV.type;
		t2 = E.type;
		if( ! CheckTypes( t1, t2 ) )
		{
			Error( ERR_TYPE_MISMATCH );
		}
		break;
		
case 34:
		if( !CheckTypes( E1.type, pBool ) )
			Error( ERR_BOOL_TYPE_EXPECTED );
		if( !CheckTypes( L.type, pBool ) )
			Error( ERR_BOOL_TYPE_EXPECTED );
		E0.type = pBool;
		break;
		
case 35:
		if( !CheckTypes( E1.type, pBool ) )
			Error( ERR_BOOL_TYPE_EXPECTED );
		if( !CheckTypes( L.type, pBool ) )
			Error( ERR_BOOL_TYPE_EXPECTED );
		E0.type = pBool;
		break;
		
case 36:
		E.type = L.type;
		break;
		
case 37:
		if( !CheckTypes( L1.type, R.type ) )
			Error( ERR_TYPE_MISMATCH );
		L0.type = pBool;
		break;
		
case 38:
		if( !CheckTypes( L1.type, R.type ) )
			Error( ERR_TYPE_MISMATCH );
		L0.type = pBool;
		break;
		
case 39:
		if( !CheckTypes( L1.type, R.type ) )
			Error( ERR_TYPE_MISMATCH );
		L0.type = pBool;
		break;
		
case 40:
		if( !CheckTypes( L1.type, R.type ) )
			Error( ERR_TYPE_MISMATCH );
		L0.type = pBool;
		break;
		
case 41:
		if( !CheckTypes( L1.type, R.type ) )
			Error( ERR_TYPE_MISMATCH );
		L0.type = pBool;
		break;
		
case 42:
		if( !CheckTypes( L1.type, R.type ) )
			Error( ERR_TYPE_MISMATCH );
		L0.type = pBool;
		break;
		
case 43:
		L.type = R.type;
		break;

case 44:
		if( !CheckTypes( R1.type, Y.type ) )
			Error( ERR_TYPE_MISMATCH );
		if( !CheckTypes( R1.type, pInteger )
		&& !CheckTypes( R1.type, pString ))
			Error( ERR_INVALID_TYPE );
		R0.type = R1.type;
		break;
		
case 45:
		if( !CheckTypes( R1.type, Y.type ) )
			Error( ERR_TYPE_MISMATCH );
		if( !CheckTypes( R1.type, pInteger ) )
			Error( ERR_INVALID_TYPE );
		R0.type = R1.type
		break;
		
case 46:
		R.type = Y.type
		break;
		
case 47:
		if( !CheckTypes( Y1.type, F.type ) )
			Error( ERR_TYPE_MISMATCH );
		if( !CheckTypes( Y1.type, pInteger ) )
			Error( ERR_INVALID_TYPE );
		Y0.type = Y1.type
		break;
		
case 48:
		if( !CheckTypes( Y1.type, F.type ) )
			Error( ERR_TYPE_MISMATCH );
		if( !CheckTypes( Y1.type, pInteger ) )
			Error( ERR_INVALID_TYPE );
		Y0.type = Y1.type
		break;
		
case 49:
		Y.type = F.type
		break;
		
case 50:
		F.type = LV.type;
		break;
		
case 51:
		t = LV.type;
		if( !CheckTypes( t, pInteger ) )
			Error( ERR_INVALID_TYPE );
		F.type = pInteger;
		break;
		
case 52:
		t = LV.type;
		if( !CheckTypes( t, pInteger ) )
			Error( ERR_INVALID_TYPE );
		F.type = pInteger;
		break;
		
case 53:
		t = LV.type;
		if( !CheckTypes( t, pInteger ) )
			Error( ERR_INVALID_TYPE );
		F.type = pInteger;
		break;
		
case 54:
		t = LV.type;
		if( !CheckTypes( t, pInteger ) )
			Error( ERR_INVALID_TYPE );
		F.type = pInteger;
		break;
		
case 55:
		F.type = E.type;
		break;
		
case 57:
		t = F1.type;
		if( !CheckTypes( t, pInteger ) )
			Error( ERR_INVALID_TYPE );
		F.type = pInteger;
		break;
		
case 58:
		t = F1.type;
		if( !CheckTypes( t, pBool ) )
			Error( ERR_INVALID_TYPE );
		F0.type = pBool;
		break;
		
case 59:
		F.type = pBool;
		break;
		
case 60:
		F.type = pBool;
		break;
		
case 61:
		F.type = pChar;
		break;
		
case 62:
		F.type = pString;
		break;
		
case 63:
		F.type = pInteger;
		break;
		
case 66:
		t = LV1.type;
		if( t->eKind != STRUCT_TYPE_ )
		{
			if( t->eKind != UNIVERSAL_ )
				Error( ERR_KIND_NOT_STRUCT );
			LV0.type = pUniversal;
		}
		else
		{
			p = t->_.Struct.pFields;
			while( p!= NULL )
			{
				if( p->nName == ID.name )
					break;
				p = p->pNext.
			}
			if( p == NULL )
			{
				Error( ERR_FIELD_NOT_DECL );
				LV0.type = pUniversal;
			}
			else
			{
				LV0.type = p->_.Field.pType;
			}
		}
		break;
		
case 67:
		t = LV1.type;
		if( t == pString )
		{
			LV0.type = pChar;
		}
		else
		if( t->eKind != ARRAY_TYPE_ )
		{
			if( t->eKind != UNIVERSAL_ )
				Error( ERR_KIND_NOT_ARRAY );
			LV0.type = pUniversal;
		}
		else
		{
			LV0.type = t->_.Array.pElemType;
		}
		if( !CheckTypes( E.type, pInteger ) )
		{
			Error( ERR_INVALID_INDEX_TYPE );
		}
		break;
		
case 68:
		p = IDU.obj;
		if( p->eKind != VAR_ &&
		p->eKind != PARAM_ )
		{
			if( p->eKind != UNIVERSAL_ )
				Error( ERR_KIND_NOT_VAR );
			LV.type = pUniversal;
		}
		else
		{
			LV.type = p->_.Var.pType;
		}
		break;
		
case 79:
		IDU = TopSem(0);
		f = IDU.obj;
		if( f->eKind != FUNCTION_ )
		{
			Error( ERR_KIND_NOT_FUNC );
			MC.type = pUniversal;
			MC.param = NULL;
			MC.err = true;
		}
		else
		{
			MC.type = f->_.Function.pRetType;
			MC.param = f->_.Function.pParams;
			MC.err = false;
		}
		break;
		
case 65:
		E = TopSem(0);
		MC = TopSem(-1);
		LE.param = NULL;
		LE.err = MC.err;
		n = 1;
		if( !MC.err )
		{
			p = MC.param;
			if( p == NULL )
			{
				Error(ERR_TOO_MANY_ARGS);
				LE.err = true;
			}
		}
		else
		{
			if( !CheckTypes(
			p->_.Param.pType,
			E.type ) )
			{
				Error( ERR_PARAM_TYPE, n);
			}
			LE.param = p->pNext;
			LE.n = n+1;
		}
		break;
		
case 64:
		LE0.param = NULL;
		LE0.err = LE1.err;
		n = LE1.n;
		if( !LE1.err )
		{
			p = LE.param;
			if( p == NULL )
			{
				Error(ERR_TOO_MANY_ARGS);
				LE0.err = true;
			}
		}
		else
		{
			if( !CheckTypes(
			p->_.Param.pType,
			E.type ) )
			{
				Error( ERR_PARAM_TYPE, n);
			}
			LE0.param = p->pNext;
			LE0.n = n+1;
		}
		break;
		
case 56:
		F.type = MC.type;
		if( !MC.err )
		{
			if( LE.param != NULL )
				Error( ERR_TOO_FEW_ARGS );
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
