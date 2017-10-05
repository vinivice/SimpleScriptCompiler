#include "definitions.h"

elementoTabelaAuxiliar rule(int p)
{
	p = -p;
	elementoTabelaAuxiliar eta;
    switch(p)
	{
		case 0:
		{
			eta.rule = 0;
			eta.len = 1;
			eta.left = P ;
			break;
		}
		case 1:
		{
			eta.rule = 1;
			eta.len = 2;
			eta.left = LDE ;
			break;
		}
		case 2:
		{
			eta.rule = 2;
			eta.len = 1;
			eta.left = LDE ;
			break;
		}
		case 3:
		{
			eta.rule = 3;
			eta.len = 1;
			eta.left = DE ;
			break;
		}
		case 4:
		{
			eta.rule = 4;
			eta.len = 1;
			eta.left = DE ;
			break;
		}
		case 5:
		{
			eta.rule = 5;
			eta.len = 1;
			eta.left = T ;
			break;
		}
		case 6:
		{
			eta.rule = 6;
			eta.len = 1;
			eta.left = T ;
			break;
		}
		case 7:
		{
			eta.rule = 7;
			eta.len = 1;
			eta.left = T ;
			break;
		}
		case 8:
		{
			eta.rule = 8;
			eta.len = 1;
			eta.left = T ;
			break;
		}
		case 9:
		{
			eta.rule = 9;
			eta.len = 1;
			eta.left = T ;
			break;
		}
		case 10:
		{
			eta.rule = 10;
			eta.len = 9;
			eta.left = DT ;
			break;
		}
		case 11:
		{
			eta.rule = 11;
			eta.len = 8;
			eta.left = DT ;
			break;
		}
		case 12:
		{
			eta.rule = 12;
			eta.len = 4;
			eta.left = DT ;
			break;
		}
		case 13:
		{
			eta.rule = 13;
			eta.len = 5;
			eta.left = DC ;
			break;
		}
		case 14:
		{
			eta.rule = 14;
			eta.len = 3;
			eta.left = DC ;
			break;
		}
		case 15:
		{
			eta.rule = 15;
			eta.len = 10;
			eta.left = DF ;
			break;
		}
		case 16:
		{
			eta.rule = 16;
			eta.len = 5;
			eta.left = LP ;
			break;
		}
		case 17:
		{
			eta.rule = 17;
			eta.len = 3;
			eta.left = LP ;
			break;
		}
		case 18:
		{
			eta.rule = 18;
			eta.len = 4;
			eta.left = B ;
			break;
		}
		case 19:
		{
			eta.rule = 19;
			eta.len = 2;
			eta.left = LDV ;
			break;
		}
		case 20:
		{
			eta.rule = 20;
			eta.len = 1;
			eta.left = LDV ;
			break;
		}
		case 21:
		{
			eta.rule = 21;
			eta.len = 2;
			eta.left = LS ;
			break;
		}
		case 22:
		{
			eta.rule = 22;
			eta.len = 1;
			eta.left = LS ;
			break;
		}
		case 23:
		{
			eta.rule = 23;
			eta.len = 5;
			eta.left = DV ;
			break;
		}
		case 24:
		{
			eta.rule = 24;
			eta.len = 3;
			eta.left = LI ;
			break;
		}
		case 25:
		{
			eta.rule = 25;
			eta.len = 1;
			eta.left = LI ;
			break;
		}
		case 26:
		{
			eta.rule = 26;
			eta.len = 6;
			eta.left = S ;
			break;
		}
		case 27:
		{
			eta.rule = 27;
			eta.len = 9;
			eta.left = S ;
			break;
		}
		case 28:
		{
			eta.rule = 28;
			eta.len = 6;
			eta.left = S ;
			break;
		}
		case 29:
		{
			eta.rule = 29;
			eta.len = 8;
			eta.left = S ;
			break;
		}
		case 30:
		{
			eta.rule = 30;
			eta.len = 2;
			eta.left = S ;
			break;
		}
		case 31:
		{
			eta.rule = 31;
			eta.len = 4;
			eta.left = S ;
			break;
		}
		case 32:
		{
			eta.rule = 32;
			eta.len = 2;
			eta.left = S ;
			break;
		}
		case 33:
		{
			eta.rule = 33;
			eta.len = 2;
			eta.left = S ;
			break;
		}
		case 34:
		{
			eta.rule = 34;
			eta.len = 3;
			eta.left = E ;
			break;
		}
		case 35:
		{
			eta.rule = 35;
			eta.len = 3;
			eta.left = E ;
			break;
		}
		case 36:
		{
			eta.rule = 36;
			eta.len = 1;
			eta.left = E ;
			break;
		}
		case 37:
		{
			eta.rule = 37;
			eta.len = 3;
			eta.left = L ;
			break;
		}
		case 38:
		{
			eta.rule = 38;
			eta.len = 3;
			eta.left = L ;
			break;
		}
		case 39:
		{
			eta.rule = 39;
			eta.len = 3;
			eta.left = L ;
			break;
		}
		case 40:
		{
			eta.rule = 40;
			eta.len = 3;
			eta.left = L ;
			break;
		}
		case 41:
		{
			eta.rule = 41;
			eta.len = 3;
			eta.left = L ;
			break;
		}
		case 42:
		{
			eta.rule = 42;
			eta.len = 3;
			eta.left = L ;
			break;
		}
		case 43:
		{
			eta.rule = 43;
			eta.len = 1;
			eta.left = L ;
			break;
		}
		case 44:
		{
			eta.rule = 44;
			eta.len = 3;
			eta.left = R ;
			break;
		}
		case 45:
		{
			eta.rule = 45;
			eta.len = 3;
			eta.left = R ;
			break;
		}
		case 46:
		{
			eta.rule = 46;
			eta.len = 1;
			eta.left = R ;
			break;
		}
		case 47:
		{
			eta.rule = 47;
			eta.len = 3;
			eta.left = Y ;
			break;
		}
		case 48:
		{
			eta.rule = 48;
			eta.len = 3;
			eta.left = Y ;
			break;
		}
		case 49:
		{
			eta.rule = 49;
			eta.len = 1;
			eta.left = Y ;
			break;
		}
		case 50:
		{
			eta.rule = 50;
			eta.len = 1;
			eta.left = F ;
			break;
		}
		case 51:
		{
			eta.rule = 51;
			eta.len = 2;
			eta.left = F ;
			break;
		}
		case 52:
		{
			eta.rule = 52;
			eta.len = 2;
			eta.left = F ;
			break;
		}
		case 53:
		{
			eta.rule = 53;
			eta.len = 2;
			eta.left = F ;
			break;
		}
		case 54:
		{
			eta.rule = 54;
			eta.len = 2;
			eta.left = F ;
			break;
		}
		case 55:
		{
			eta.rule = 55;
			eta.len = 3;
			eta.left = F ;
			break;
		}
		case 56:
		{
			eta.rule = 56;
			eta.len = 5;
			eta.left = F ;
			break;
		}
		case 57:
		{
			eta.rule = 57;
			eta.len = 2;
			eta.left = F ;
			break;
		}
		case 58:
		{
			eta.rule = 58;
			eta.len = 2;
			eta.left = F ;
			break;
		}
		case 59:
		{
			eta.rule = 59;
			eta.len = 1;
			eta.left = F ;
			break;
		}
		case 60:
		{
			eta.rule = 60;
			eta.len = 1;
			eta.left = F ;
			break;
		}
		case 61:
		{
			eta.rule = 61;
			eta.len = 1;
			eta.left = F ;
			break;
		}
		case 62:
		{
			eta.rule = 62;
			eta.len = 1;
			eta.left = F ;
			break;
		}
		case 63:
		{
			eta.rule = 63;
			eta.len = 1;
			eta.left = F ;
			break;
		}
		case 64:
		{
			eta.rule = 64;
			eta.len = 3;
			eta.left = LE ;
			break;
		}
		case 65:
		{
			eta.rule = 65;
			eta.len = 1;
			eta.left = LE ;
			break;
		}
		case 66:
		{
			eta.rule = 66;
			eta.len = 3;
			eta.left = LV ;
			break;
		}
		case 67:
		{
			eta.rule = 67;
			eta.len = 4;
			eta.left = LV ;
			break;
		}
		case 68:
		{
			eta.rule = 68;
			eta.len = 1;
			eta.left = LV ;
			break;
		}
		case 69:
		{
			eta.rule = 69;
			eta.len = 1;
			eta.left = ID_N_TERMINAL ;
			break;
		}
		case 70:
		{
			eta.rule = 70;
			eta.len = 1;
			eta.left = TRU ;
			break;
		}
		case 71:
		{
			eta.rule = 71;
			eta.len = 1;
			eta.left = FAL ;
			break;
		}
		case 72:
		{
			eta.rule = 72;
			eta.len = 1;
			eta.left = CHR ;
			break;
		}
		case 73:
		{
			eta.rule = 73;
			eta.len = 1;
			eta.left = STR ;
			break;
		}
		case 74:
		{
			eta.rule = 74;
			eta.len = 1;
			eta.left = NUM ;
			break;
		}
		case 75:
		{
			eta.rule = 75;
			eta.len = 1;
			eta.left = IDD ;
			break;
		}
		case 76:
		{
			eta.rule = 76;
			eta.len = 1;
			eta.left = IDU ;
			break;
		}
		case 77:
		{
			eta.rule = 77;
			eta.len = 0;
			eta.left = NB ;
			break;
		}
		case 78:
		{
			eta.rule = 78;
			eta.len = 0;
			eta.left = MF ;
			break;
		}
		case 79:
		{
			eta.rule = 79;
			eta.len = 0;
			eta.left = MC ;
			break;
		}
		case 80:
		{
			eta.rule = 80;
			eta.len = 0;
			eta.left = NF ;
			break;
		}
		case 81:
		{
			eta.rule = 81;
			eta.len = 0;
			eta.left = MT ;
			break;
		}
		case 82:
		{
			eta.rule = 82;
			eta.len = 0;
			eta.left = ME ;
			break;
		}
		case 83:
		{
			eta.rule = 83;
			eta.len = 0;
			eta.left = MW ;
			break;
		}
	}
    return eta;
}

int action(int state, int input)
{
	switch(state)
	{
		case 0: //CHECK STAGE 0
			switch(input)
			{
				case TYPE: return 6;
				case FUNCTION: return 5;
				case LDE: return 1;
				case DE: return 2;
				case DT: return 4;
				case DF: return 3;
			}
			break;
		case 1: //CHECK STAGE 1
			switch(input)
			{
				case TYPE: return 6;
				case FUNCTION: return 5;
				case $: return ACC;
				case DE: return 7;
				case DT: return 4;
				case DF: return 3;
			}
			break;
		case 2: //CHECK STAGE 2
			switch(input)
			{
				case TYPE: return -2;
				case FUNCTION: return -2;
				case $: return -2;
			}
			break;
		case 3: //CHECK STAGE 3
			switch(input)
			{
				case TYPE: return -3;
				case FUNCTION: return -3;
				case $: return -3;
			}
			break;
		case 4: //CHECK STAGE 4
			switch(input)
			{
				case TYPE: return -4;
				case FUNCTION: return -4;
				case $: return -4;
			}
			break;
		case 5: //CHECK STAGE 5
			switch(input)
			{
				case ID: return 9;
				case IDD: return 8;
			}
			break;
		case 6: //CHECK STAGE 6
			switch(input)
			{
				case ID: return 9;
				case IDD: return 10;
			}
			break;
		case 7: //CHECK STAGE 7
			switch(input)
			{
				case TYPE: return -1;
				case FUNCTION: return -1;
				case $: return -1;
			}
			break;
		case 8: //CHECK STAGE 8
			switch(input)
			{
				case LEFT_PARENTHESIS: return -80;
				case NF: return 11;
			}
			break;
		case 9: //CHECK STAGE 9
			switch(input)
			{
				case TYPE: return -75;
				case EQUALS: return -75;
				case COLON: return -75;
				case FUNCTION: return -75;
				case LEFT_PARENTHESIS: return -75;
				case COMMA: return -75;
				case $: return -75;
			}
			break;
		case 10: //CHECK STAGE 10
			switch(input)
			{
				case EQUALS: return 12;
			}
			break;
		case 11: //CHECK STAGE 11
			switch(input)
			{
				case LEFT_PARENTHESIS: return 13;
			}
			break;
		case 12: //CHECK STAGE 12
			switch(input)
			{
				case INTEGER: return 17;
				case CHAR: return 18;
				case BOOLEAN: return 19;
				case STRING: return 20;
				case ARRAY: return 14;
				case STRUCT: return 15;
				case ID: return 22;
				case T: return 16;
				case IDU: return 21;
			}
			break;
		case 13: //CHECK STAGE 13
			switch(input)
			{
				case ID: return 9;
				case LP: return 23;
				case IDD: return 24;
			}
			break;
		case 14: //CHECK STAGE 14
			switch(input)
			{
				case LEFT_SQUARE: return 25;
			}
			break;
		case 15: //CHECK STAGE 15
			switch(input)
			{
				case LEFT_BRACES: return -77;
				case NB: return 26;
			}
			break;
		case 16: //CHECK STAGE 16
			switch(input)
			{
				case TYPE: return -12;
				case FUNCTION: return -12;
				case $: return -12;
			}
			break;
		case 17: //CHECK STAGE 17
			switch(input)
			{
				case TYPE: return -5;
				case LEFT_BRACES: return -5;
				case RIGHT_BRACES: return -5;
				case SEMI_COLON: return -5;
				case FUNCTION: return -5;
				case RIGHT_PARENTHESIS: return -5;
				case COMMA: return -5;
				case $: return -5;
			}
			break;
		case 18: //CHECK STAGE 18
			switch(input)
			{
				case TYPE: return -6;
				case LEFT_BRACES: return -6;
				case RIGHT_BRACES: return -6;
				case SEMI_COLON: return -6;
				case FUNCTION: return -6;
				case RIGHT_PARENTHESIS: return -6;
				case COMMA: return -6;
				case $: return -6;
			}
			break;
		case 19: //CHECK STAGE 19
			switch(input)
			{
				case TYPE: return -7;
				case LEFT_BRACES: return -7;
				case RIGHT_BRACES: return -7;
				case SEMI_COLON: return -7;
				case FUNCTION: return -7;
				case RIGHT_PARENTHESIS: return -7;
				case COMMA: return -7;
				case $: return -7;
			}
			break;
		case 20: //CHECK STAGE 20
			switch(input)
			{
				case TYPE: return -8;
				case LEFT_BRACES: return -8;
				case RIGHT_BRACES: return -8;
				case SEMI_COLON: return -8;
				case FUNCTION: return -8;
				case RIGHT_PARENTHESIS: return -8;
				case COMMA: return -8;
				case $: return -8;
			}
			break;
		case 21: //CHECK STAGE 21
			switch(input)
			{
				case TYPE: return -9;
				case LEFT_BRACES: return -9;
				case RIGHT_BRACES: return -9;
				case SEMI_COLON: return -9;
				case FUNCTION: return -9;
				case RIGHT_PARENTHESIS: return -9;
				case COMMA: return -9;
				case $: return -9;
			}
			break;
		case 22: //CHECK STAGE 22
			switch(input)
			{
				case TYPE: return -76;
				case EQUALS: return -76;
				case LEFT_SQUARE: return -76;
				case RIGHT_SQUARE: return -76;
				case LEFT_BRACES: return -76;
				case RIGHT_BRACES: return -76;
				case SEMI_COLON: return -76;
				case FUNCTION: return -76;
				case LEFT_PARENTHESIS: return -76;
				case RIGHT_PARENTHESIS: return -76;
				case COMMA: return -76;
				case AND: return -76;
				case OR: return -76;
				case LESS_THAN: return -76;
				case GREATER_THAN: return -76;
				case LESS_OR_EQUAL: return -76;
				case GREATER_OR_EQUAL: return -76;
				case EQUAL_EQUAL: return -76;
				case NOT_EQUAL: return -76;
				case PLUS: return -76;
				case MINUS: return -76;
				case TIMES: return -76;
				case DIVIDE: return -76;
				case PLUS_PLUS: return -76;
				case MINUS_MINUS: return -76;
				case DOT: return -76;
				case $: return -76;
			}
			break;
		case 23: //CHECK STAGE 23
			switch(input)
			{
				case RIGHT_PARENTHESIS: return 27;
				case COMMA: return 28;
			}
			break;
		case 24: //CHECK STAGE 24
			switch(input)
			{
				case COLON: return 29;
			}
			break;
		case 25: //CHECK STAGE 25
			switch(input)
			{
				case NUMERAL: return 31;
				case NUM: return 30;
			}
			break;
		case 26: //CHECK STAGE 26
			switch(input)
			{
				case LEFT_BRACES: return 32;
			}
			break;
		case 27: //CHECK STAGE 27
			switch(input)
			{
				case COLON: return 33;
			}
			break;
		case 28: //CHECK STAGE 28
			switch(input)
			{
				case ID: return 9;
				case IDD: return 34;
			}
			break;
		case 29: //CHECK STAGE 29
			switch(input)
			{
				case INTEGER: return 17;
				case CHAR: return 18;
				case BOOLEAN: return 19;
				case STRING: return 20;
				case ID: return 22;
				case T: return 35;
				case IDU: return 21;
			}
			break;
		case 30: //CHECK STAGE 30
			switch(input)
			{
				case RIGHT_SQUARE: return 36;
			}
			break;
		case 31: //CHECK STAGE 31
			switch(input)
			{
				case RIGHT_SQUARE: return -74;
				case SEMI_COLON: return -74;
				case RIGHT_PARENTHESIS: return -74;
				case COMMA: return -74;
				case AND: return -74;
				case OR: return -74;
				case LESS_THAN: return -74;
				case GREATER_THAN: return -74;
				case LESS_OR_EQUAL: return -74;
				case GREATER_OR_EQUAL: return -74;
				case EQUAL_EQUAL: return -74;
				case NOT_EQUAL: return -74;
				case PLUS: return -74;
				case MINUS: return -74;
				case TIMES: return -74;
				case DIVIDE: return -74;
			}
			break;
		case 32: //CHECK STAGE 32
			switch(input)
			{
				case ID: return 9;
				case DC: return 37;
				case LI: return 38;
				case IDD: return 39;
			}
			break;
		case 33: //CHECK STAGE 33
			switch(input)
			{
				case INTEGER: return 17;
				case CHAR: return 18;
				case BOOLEAN: return 19;
				case STRING: return 20;
				case ID: return 22;
				case T: return 40;
				case IDU: return 21;
			}
			break;
		case 34: //CHECK STAGE 34
			switch(input)
			{
				case COLON: return 41;
			}
			break;
		case 35: //CHECK STAGE 35
			switch(input)
			{
				case RIGHT_PARENTHESIS: return -17;
				case COMMA: return -17;
			}
			break;
		case 36: //CHECK STAGE 36
			switch(input)
			{
				case OF: return 42;
			}
			break;
		case 37: //CHECK STAGE 37
			switch(input)
			{
				case RIGHT_BRACES: return 43;
				case SEMI_COLON: return 44;
			}
			break;
		case 38: //CHECK STAGE 38
			switch(input)
			{
				case COLON: return 45;
				case COMMA: return 46;
			}
			break;
		case 39: //CHECK STAGE 39
			switch(input)
			{
				case COLON: return -25;
				case COMMA: return -25;
			}
			break;
		case 40: //CHECK STAGE 40
			switch(input)
			{
				case LEFT_BRACES: return -78;
				case MF: return 47;
			}
			break;
		case 41: //CHECK STAGE 41
			switch(input)
			{
				case INTEGER: return 17;
				case CHAR: return 18;
				case BOOLEAN: return 19;
				case STRING: return 20;
				case ID: return 22;
				case T: return 48;
				case IDU: return 21;
			}
			break;
		case 42: //CHECK STAGE 42
			switch(input)
			{
				case INTEGER: return 17;
				case CHAR: return 18;
				case BOOLEAN: return 19;
				case STRING: return 20;
				case ID: return 22;
				case T: return 49;
				case IDU: return 21;
			}
			break;
		case 43: //CHECK STAGE 43
			switch(input)
			{
				case TYPE: return -11;
				case FUNCTION: return -11;
				case $: return -11;
			}
			break;
		case 44: //CHECK STAGE 44
			switch(input)
			{
				case ID: return 9;
				case LI: return 50;
				case IDD: return 39;
			}
			break;
		case 45: //CHECK STAGE 45
			switch(input)
			{
				case INTEGER: return 17;
				case CHAR: return 18;
				case BOOLEAN: return 19;
				case STRING: return 20;
				case ID: return 22;
				case T: return 51;
				case IDU: return 21;
			}
			break;
		case 46: //CHECK STAGE 46
			switch(input)
			{
				case ID: return 9;
				case IDD: return 52;
			}
			break;
		case 47: //CHECK STAGE 47
			switch(input)
			{
				case LEFT_BRACES: return 54;
				case B: return 53;
			}
			break;
		case 48: //CHECK STAGE 48
			switch(input)
			{
				case RIGHT_PARENTHESIS: return -16;
				case COMMA: return -16;
			}
			break;
		case 49: //CHECK STAGE 49
			switch(input)
			{
				case TYPE: return -10;
				case FUNCTION: return -10;
				case $: return -10;
			}
			break;
		case 50: //CHECK STAGE 50
			switch(input)
			{
				case COLON: return 55;
				case COMMA: return 46;
			}
			break;
		case 51: //CHECK STAGE 51
			switch(input)
			{
				case RIGHT_BRACES: return -14;
				case SEMI_COLON: return -14;
			}
			break;
		case 52: //CHECK STAGE 52
			switch(input)
			{
				case COLON: return -24;
				case COMMA: return -24;
			}
			break;
		case 53: //CHECK STAGE 53
			switch(input)
			{
				case TYPE: return -15;
				case FUNCTION: return -15;
				case $: return -15;
			}
			break;
		case 54: //CHECK STAGE 54
			switch(input)
			{
				case VAR: return 58;
				case LDV: return 56;
				case DV: return 57;
			}
			break;
		case 55: //CHECK STAGE 55
			switch(input)
			{
				case INTEGER: return 17;
				case CHAR: return 18;
				case BOOLEAN: return 19;
				case STRING: return 20;
				case ID: return 22;
				case T: return 59;
				case IDU: return 21;
			}
			break;
		case 56: //CHECK STAGE 56
			switch(input)
			{
				case LEFT_BRACES: return -77;
				case VAR: return 58;
				case IF: return 63;
				case WHILE: return 64;
				case DO: return 65;
				case BREAK: return 68;
				case CONTINUE: return 69;
				case ID: return 22;
				case LS: return 60;
				case DV: return 61;
				case S: return 62;
				case LV: return 67;
				case IDU: return 70;
				case NB: return 66;
			}
			break;
		case 57: //CHECK STAGE 57
			switch(input)
			{
				case TYPE: return -20;
				case LEFT_BRACES: return -20;
				case RIGHT_BRACES: return -20;
				case FUNCTION: return -20;
				case VAR: return -20;
				case IF: return -20;
				case ELSE: return -20;
				case WHILE: return -20;
				case DO: return -20;
				case BREAK: return -20;
				case CONTINUE: return -20;
				case ID: return -20;
				case $: return -20;
			}
			break;
		case 58: //CHECK STAGE 58
			switch(input)
			{
				case ID: return 9;
				case LI: return 71;
				case IDD: return 39;
			}
			break;
		case 59: //CHECK STAGE 59
			switch(input)
			{
				case RIGHT_BRACES: return -13;
				case SEMI_COLON: return -13;
			}
			break;
		case 60: //CHECK STAGE 60
			switch(input)
			{
				case LEFT_BRACES: return -77;
				case RIGHT_BRACES: return 72;
				case IF: return 63;
				case WHILE: return 64;
				case DO: return 65;
				case BREAK: return 68;
				case CONTINUE: return 69;
				case ID: return 22;
				case S: return 73;
				case LV: return 67;
				case IDU: return 70;
				case NB: return 66;
			}
			break;
		case 61: //CHECK STAGE 61
			switch(input)
			{
				case TYPE: return -19;
				case LEFT_BRACES: return -19;
				case RIGHT_BRACES: return -19;
				case FUNCTION: return -19;
				case VAR: return -19;
				case IF: return -19;
				case ELSE: return -19;
				case WHILE: return -19;
				case DO: return -19;
				case BREAK: return -19;
				case CONTINUE: return -19;
				case ID: return -19;
				case $: return -19;
			}
			break;
		case 62: //CHECK STAGE 62
			switch(input)
			{
				case LEFT_BRACES: return -22;
				case RIGHT_BRACES: return -22;
				case IF: return -22;
				case WHILE: return -22;
				case DO: return -22;
				case BREAK: return -22;
				case CONTINUE: return -22;
				case ID: return -22;
			}
			break;
		case 63: //CHECK STAGE 63
			switch(input)
			{
				case LEFT_PARENTHESIS: return 74;
			}
			break;
		case 64: //CHECK STAGE 64
			switch(input)
			{
				case LEFT_PARENTHESIS: return -83;
				case MW: return 75;
			}
			break;
		case 65: //CHECK STAGE 65
			switch(input)
			{
				case LEFT_BRACES: return -83;
				case RIGHT_BRACES: return -83;
				case IF: return -83;
				case ELSE: return -83;
				case WHILE: return -83;
				case DO: return -83;
				case BREAK: return -83;
				case CONTINUE: return -83;
				case ID: return -83;
				case MW: return 76;
			}
			break;
		case 66: //CHECK STAGE 66
			switch(input)
			{
				case LEFT_BRACES: return 54;
				case B: return 77;
			}
			break;
		case 67: //CHECK STAGE 67
			switch(input)
			{
				case EQUALS: return 78;
				case LEFT_SQUARE: return 80;
				case DOT: return 79;
			}
			break;
		case 68: //CHECK STAGE 68
			switch(input)
			{
				case SEMI_COLON: return 81;
			}
			break;
		case 69: //CHECK STAGE 69
			switch(input)
			{
				case SEMI_COLON: return 82;
			}
			break;
		case 70: //CHECK STAGE 70
			switch(input)
			{
				case EQUALS: return -68;
				case LEFT_SQUARE: return -68;
				case RIGHT_SQUARE: return -68;
				case SEMI_COLON: return -68;
				case RIGHT_PARENTHESIS: return -68;
				case COMMA: return -68;
				case AND: return -68;
				case OR: return -68;
				case LESS_THAN: return -68;
				case GREATER_THAN: return -68;
				case LESS_OR_EQUAL: return -68;
				case GREATER_OR_EQUAL: return -68;
				case EQUAL_EQUAL: return -68;
				case NOT_EQUAL: return -68;
				case PLUS: return -68;
				case MINUS: return -68;
				case TIMES: return -68;
				case DIVIDE: return -68;
				case DOT: return -68;
			}
			break;
		case 71: //CHECK STAGE 71
			switch(input)
			{
				case COLON: return 83;
				case COMMA: return 46;
			}
			break;
		case 72: //CHECK STAGE 72
			switch(input)
			{
				case TYPE: return -18;
				case LEFT_BRACES: return -18;
				case RIGHT_BRACES: return -18;
				case FUNCTION: return -18;
				case IF: return -18;
				case ELSE: return -18;
				case WHILE: return -18;
				case DO: return -18;
				case BREAK: return -18;
				case CONTINUE: return -18;
				case ID: return -18;
				case $: return -18;
			}
			break;
		case 73: //CHECK STAGE 73
			switch(input)
			{
				case LEFT_BRACES: return -21;
				case RIGHT_BRACES: return -21;
				case IF: return -21;
				case WHILE: return -21;
				case DO: return -21;
				case BREAK: return -21;
				case CONTINUE: return -21;
				case ID: return -21;
			}
			break;
		case 74: //CHECK STAGE 74
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case E: return 84;
				case L: return 85;
				case R: return 86;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 75: //CHECK STAGE 75
			switch(input)
			{
				case LEFT_PARENTHESIS: return 105;
			}
			break;
		case 76: //CHECK STAGE 76
			switch(input)
			{
				case LEFT_BRACES: return -77;
				case IF: return 63;
				case WHILE: return 64;
				case DO: return 65;
				case BREAK: return 68;
				case CONTINUE: return 69;
				case ID: return 22;
				case S: return 106;
				case LV: return 67;
				case IDU: return 70;
				case NB: return 66;
			}
			break;
		case 77: //CHECK STAGE 77
			switch(input)
			{
				case LEFT_BRACES: return -30;
				case RIGHT_BRACES: return -30;
				case IF: return -30;
				case ELSE: return -30;
				case WHILE: return -30;
				case DO: return -30;
				case BREAK: return -30;
				case CONTINUE: return -30;
				case ID: return -30;
			}
			break;
		case 78: //CHECK STAGE 78
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case E: return 107;
				case L: return 85;
				case R: return 86;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 79: //CHECK STAGE 79
			switch(input)
			{
				case ID: return 22;
				case IDU: return 108;
			}
			break;
		case 80: //CHECK STAGE 80
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case E: return 109;
				case L: return 85;
				case R: return 86;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 81: //CHECK STAGE 81
			switch(input)
			{
				case LEFT_BRACES: return -32;
				case RIGHT_BRACES: return -32;
				case IF: return -32;
				case ELSE: return -32;
				case WHILE: return -32;
				case DO: return -32;
				case BREAK: return -32;
				case CONTINUE: return -32;
				case ID: return -32;
			}
			break;
		case 82: //CHECK STAGE 82
			switch(input)
			{
				case LEFT_BRACES: return -33;
				case RIGHT_BRACES: return -33;
				case IF: return -33;
				case ELSE: return -33;
				case WHILE: return -33;
				case DO: return -33;
				case BREAK: return -33;
				case CONTINUE: return -33;
				case ID: return -33;
			}
			break;
		case 83: //CHECK STAGE 83
			switch(input)
			{
				case INTEGER: return 17;
				case CHAR: return 18;
				case BOOLEAN: return 19;
				case STRING: return 20;
				case ID: return 22;
				case T: return 110;
				case IDU: return 21;
			}
			break;
		case 84: //CHECK STAGE 84
			switch(input)
			{
				case RIGHT_PARENTHESIS: return 111;
				case AND: return 112;
				case OR: return 113;
			}
			break;
		case 85: //CHECK STAGE 85
			switch(input)
			{
				case RIGHT_SQUARE: return -36;
				case SEMI_COLON: return -36;
				case RIGHT_PARENTHESIS: return -36;
				case COMMA: return -36;
				case AND: return -36;
				case OR: return -36;
				case LESS_THAN: return 114;
				case GREATER_THAN: return 115;
				case LESS_OR_EQUAL: return 116;
				case GREATER_OR_EQUAL: return 117;
				case EQUAL_EQUAL: return 118;
				case NOT_EQUAL: return 119;
			}
			break;
		case 86: //CHECK STAGE 86
			switch(input)
			{
				case RIGHT_SQUARE: return -43;
				case SEMI_COLON: return -43;
				case RIGHT_PARENTHESIS: return -43;
				case COMMA: return -43;
				case AND: return -43;
				case OR: return -43;
				case LESS_THAN: return -43;
				case GREATER_THAN: return -43;
				case LESS_OR_EQUAL: return -43;
				case GREATER_OR_EQUAL: return -43;
				case EQUAL_EQUAL: return -43;
				case NOT_EQUAL: return -43;
				case PLUS: return 120;
				case MINUS: return 121;
			}
			break;
		case 87: //CHECK STAGE 87
			switch(input)
			{
				case RIGHT_SQUARE: return -46;
				case SEMI_COLON: return -46;
				case RIGHT_PARENTHESIS: return -46;
				case COMMA: return -46;
				case AND: return -46;
				case OR: return -46;
				case LESS_THAN: return -46;
				case GREATER_THAN: return -46;
				case LESS_OR_EQUAL: return -46;
				case GREATER_OR_EQUAL: return -46;
				case EQUAL_EQUAL: return -46;
				case NOT_EQUAL: return -46;
				case PLUS: return -46;
				case MINUS: return -46;
				case TIMES: return 122;
				case DIVIDE: return 123;
			}
			break;
		case 88: //CHECK STAGE 88
			switch(input)
			{
				case RIGHT_SQUARE: return -49;
				case SEMI_COLON: return -49;
				case RIGHT_PARENTHESIS: return -49;
				case COMMA: return -49;
				case AND: return -49;
				case OR: return -49;
				case LESS_THAN: return -49;
				case GREATER_THAN: return -49;
				case LESS_OR_EQUAL: return -49;
				case GREATER_OR_EQUAL: return -49;
				case EQUAL_EQUAL: return -49;
				case NOT_EQUAL: return -49;
				case PLUS: return -49;
				case MINUS: return -49;
				case TIMES: return -49;
				case DIVIDE: return -49;
			}
			break;
		case 89: //CHECK STAGE 89
			switch(input)
			{
				case LEFT_SQUARE: return 80;
				case RIGHT_SQUARE: return -50;
				case SEMI_COLON: return -50;
				case RIGHT_PARENTHESIS: return -50;
				case COMMA: return -50;
				case AND: return -50;
				case OR: return -50;
				case LESS_THAN: return -50;
				case GREATER_THAN: return -50;
				case LESS_OR_EQUAL: return -50;
				case GREATER_OR_EQUAL: return -50;
				case EQUAL_EQUAL: return -50;
				case NOT_EQUAL: return -50;
				case PLUS: return -50;
				case MINUS: return -50;
				case TIMES: return -50;
				case DIVIDE: return -50;
				case PLUS_PLUS: return 124;
				case MINUS_MINUS: return 125;
				case DOT: return 79;
			}
			break;
		case 90: //CHECK STAGE 90
			switch(input)
			{
				case ID: return 22;
				case LV: return 126;
				case IDU: return 70;
			}
			break;
		case 91: //CHECK STAGE 91
			switch(input)
			{
				case ID: return 22;
				case LV: return 127;
				case IDU: return 70;
			}
			break;
		case 92: //CHECK STAGE 92
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case E: return 128;
				case L: return 85;
				case R: return 86;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 93: //CHECK STAGE 93
			switch(input)
			{
				case LEFT_SQUARE: return -68;
				case RIGHT_SQUARE: return -68;
				case SEMI_COLON: return -68;
				case LEFT_PARENTHESIS: return -79;
				case RIGHT_PARENTHESIS: return -68;
				case COMMA: return -68;
				case AND: return -68;
				case OR: return -68;
				case LESS_THAN: return -68;
				case GREATER_THAN: return -68;
				case LESS_OR_EQUAL: return -68;
				case GREATER_OR_EQUAL: return -68;
				case EQUAL_EQUAL: return -68;
				case NOT_EQUAL: return -68;
				case PLUS: return -68;
				case MINUS: return -68;
				case TIMES: return -68;
				case DIVIDE: return -68;
				case PLUS_PLUS: return -68;
				case MINUS_MINUS: return -68;
				case DOT: return -68;
				case MC: return 129;
			}
			break;
		case 94: //CHECK STAGE 94
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case F: return 130;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 95: //CHECK STAGE 95
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case F: return 131;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 96: //CHECK STAGE 96
			switch(input)
			{
				case RIGHT_SQUARE: return -59;
				case SEMI_COLON: return -59;
				case RIGHT_PARENTHESIS: return -59;
				case COMMA: return -59;
				case AND: return -59;
				case OR: return -59;
				case LESS_THAN: return -59;
				case GREATER_THAN: return -59;
				case LESS_OR_EQUAL: return -59;
				case GREATER_OR_EQUAL: return -59;
				case EQUAL_EQUAL: return -59;
				case NOT_EQUAL: return -59;
				case PLUS: return -59;
				case MINUS: return -59;
				case TIMES: return -59;
				case DIVIDE: return -59;
			}
			break;
		case 97: //CHECK STAGE 97
			switch(input)
			{
				case RIGHT_SQUARE: return -60;
				case SEMI_COLON: return -60;
				case RIGHT_PARENTHESIS: return -60;
				case COMMA: return -60;
				case AND: return -60;
				case OR: return -60;
				case LESS_THAN: return -60;
				case GREATER_THAN: return -60;
				case LESS_OR_EQUAL: return -60;
				case GREATER_OR_EQUAL: return -60;
				case EQUAL_EQUAL: return -60;
				case NOT_EQUAL: return -60;
				case PLUS: return -60;
				case MINUS: return -60;
				case TIMES: return -60;
				case DIVIDE: return -60;
			}
			break;
		case 98: //CHECK STAGE 98
			switch(input)
			{
				case RIGHT_SQUARE: return -61;
				case SEMI_COLON: return -61;
				case RIGHT_PARENTHESIS: return -61;
				case COMMA: return -61;
				case AND: return -61;
				case OR: return -61;
				case LESS_THAN: return -61;
				case GREATER_THAN: return -61;
				case LESS_OR_EQUAL: return -61;
				case GREATER_OR_EQUAL: return -61;
				case EQUAL_EQUAL: return -61;
				case NOT_EQUAL: return -61;
				case PLUS: return -61;
				case MINUS: return -61;
				case TIMES: return -61;
				case DIVIDE: return -61;
			}
			break;
		case 99: //CHECK STAGE 99
			switch(input)
			{
				case RIGHT_SQUARE: return -62;
				case SEMI_COLON: return -62;
				case RIGHT_PARENTHESIS: return -62;
				case COMMA: return -62;
				case AND: return -62;
				case OR: return -62;
				case LESS_THAN: return -62;
				case GREATER_THAN: return -62;
				case LESS_OR_EQUAL: return -62;
				case GREATER_OR_EQUAL: return -62;
				case EQUAL_EQUAL: return -62;
				case NOT_EQUAL: return -62;
				case PLUS: return -62;
				case MINUS: return -62;
				case TIMES: return -62;
				case DIVIDE: return -62;
			}
			break;
		case 100: //CHECK STAGE 100
			switch(input)
			{
				case RIGHT_SQUARE: return -63;
				case SEMI_COLON: return -63;
				case RIGHT_PARENTHESIS: return -63;
				case COMMA: return -63;
				case AND: return -63;
				case OR: return -63;
				case LESS_THAN: return -63;
				case GREATER_THAN: return -63;
				case LESS_OR_EQUAL: return -63;
				case GREATER_OR_EQUAL: return -63;
				case EQUAL_EQUAL: return -63;
				case NOT_EQUAL: return -63;
				case PLUS: return -63;
				case MINUS: return -63;
				case TIMES: return -63;
				case DIVIDE: return -63;
			}
			break;
		case 101: //CHECK STAGE 101
			switch(input)
			{
				case RIGHT_SQUARE: return -70;
				case SEMI_COLON: return -70;
				case RIGHT_PARENTHESIS: return -70;
				case COMMA: return -70;
				case AND: return -70;
				case OR: return -70;
				case LESS_THAN: return -70;
				case GREATER_THAN: return -70;
				case LESS_OR_EQUAL: return -70;
				case GREATER_OR_EQUAL: return -70;
				case EQUAL_EQUAL: return -70;
				case NOT_EQUAL: return -70;
				case PLUS: return -70;
				case MINUS: return -70;
				case TIMES: return -70;
				case DIVIDE: return -70;
			}
			break;
		case 102: //CHECK STAGE 102
			switch(input)
			{
				case RIGHT_SQUARE: return -71;
				case SEMI_COLON: return -71;
				case RIGHT_PARENTHESIS: return -71;
				case COMMA: return -71;
				case AND: return -71;
				case OR: return -71;
				case LESS_THAN: return -71;
				case GREATER_THAN: return -71;
				case LESS_OR_EQUAL: return -71;
				case GREATER_OR_EQUAL: return -71;
				case EQUAL_EQUAL: return -71;
				case NOT_EQUAL: return -71;
				case PLUS: return -71;
				case MINUS: return -71;
				case TIMES: return -71;
				case DIVIDE: return -71;
			}
			break;
		case 103: //CHECK STAGE 103
			switch(input)
			{
				case RIGHT_SQUARE: return -72;
				case SEMI_COLON: return -72;
				case RIGHT_PARENTHESIS: return -72;
				case COMMA: return -72;
				case AND: return -72;
				case OR: return -72;
				case LESS_THAN: return -72;
				case GREATER_THAN: return -72;
				case LESS_OR_EQUAL: return -72;
				case GREATER_OR_EQUAL: return -72;
				case EQUAL_EQUAL: return -72;
				case NOT_EQUAL: return -72;
				case PLUS: return -72;
				case MINUS: return -72;
				case TIMES: return -72;
				case DIVIDE: return -72;
			}
			break;
		case 104: //CHECK STAGE 104
			switch(input)
			{
				case RIGHT_SQUARE: return -73;
				case SEMI_COLON: return -73;
				case RIGHT_PARENTHESIS: return -73;
				case COMMA: return -73;
				case AND: return -73;
				case OR: return -73;
				case LESS_THAN: return -73;
				case GREATER_THAN: return -73;
				case LESS_OR_EQUAL: return -73;
				case GREATER_OR_EQUAL: return -73;
				case EQUAL_EQUAL: return -73;
				case NOT_EQUAL: return -73;
				case PLUS: return -73;
				case MINUS: return -73;
				case TIMES: return -73;
				case DIVIDE: return -73;
			}
			break;
		case 105: //CHECK STAGE 105
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case E: return 132;
				case L: return 85;
				case R: return 86;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 106: //CHECK STAGE 106
			switch(input)
			{
				case WHILE: return 133;
			}
			break;
		case 107: //CHECK STAGE 107
			switch(input)
			{
				case SEMI_COLON: return 134;
				case AND: return 112;
				case OR: return 113;
			}
			break;
		case 108: //CHECK STAGE 108
			switch(input)
			{
				case EQUALS: return -66;
				case LEFT_SQUARE: return -66;
				case RIGHT_SQUARE: return -66;
				case SEMI_COLON: return -66;
				case RIGHT_PARENTHESIS: return -66;
				case COMMA: return -66;
				case AND: return -66;
				case OR: return -66;
				case LESS_THAN: return -66;
				case GREATER_THAN: return -66;
				case LESS_OR_EQUAL: return -66;
				case GREATER_OR_EQUAL: return -66;
				case EQUAL_EQUAL: return -66;
				case NOT_EQUAL: return -66;
				case PLUS: return -66;
				case MINUS: return -66;
				case TIMES: return -66;
				case DIVIDE: return -66;
				case PLUS_PLUS: return -66;
				case MINUS_MINUS: return -66;
				case DOT: return -66;
			}
			break;
		case 109: //CHECK STAGE 109
			switch(input)
			{
				case RIGHT_SQUARE: return 135;
				case AND: return 112;
				case OR: return 113;
			}
			break;
		case 110: //CHECK STAGE 110
			switch(input)
			{
				case SEMI_COLON: return 136;
			}
			break;
		case 111: //CHECK STAGE 111
			switch(input)
			{
				case LEFT_BRACES: return -81;
				case RIGHT_BRACES: return -81;
				case IF: return -81;
				case ELSE: return -81;
				case WHILE: return -81;
				case DO: return -81;
				case BREAK: return -81;
				case CONTINUE: return -81;
				case ID: return -81;
				case MT: return 137;
			}
			break;
		case 112: //CHECK STAGE 112
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case L: return 138;
				case R: return 86;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 113: //CHECK STAGE 113
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case L: return 139;
				case R: return 86;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 114: //CHECK STAGE 114
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case R: return 140;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 115: //CHECK STAGE 115
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case R: return 141;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 116: //CHECK STAGE 116
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case R: return 142;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 117: //CHECK STAGE 117
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case R: return 143;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 118: //CHECK STAGE 118
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case R: return 144;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 119: //CHECK STAGE 119
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case R: return 145;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 120: //CHECK STAGE 120
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case Y: return 146;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 121: //CHECK STAGE 121
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case Y: return 147;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 122: //CHECK STAGE 122
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case F: return 148;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 123: //CHECK STAGE 123
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case F: return 149;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 124: //CHECK STAGE 124
			switch(input)
			{
				case RIGHT_SQUARE: return -53;
				case SEMI_COLON: return -53;
				case RIGHT_PARENTHESIS: return -53;
				case COMMA: return -53;
				case AND: return -53;
				case OR: return -53;
				case LESS_THAN: return -53;
				case GREATER_THAN: return -53;
				case LESS_OR_EQUAL: return -53;
				case GREATER_OR_EQUAL: return -53;
				case EQUAL_EQUAL: return -53;
				case NOT_EQUAL: return -53;
				case PLUS: return -53;
				case MINUS: return -53;
				case TIMES: return -53;
				case DIVIDE: return -53;
			}
			break;
		case 125: //CHECK STAGE 125
			switch(input)
			{
				case RIGHT_SQUARE: return -54;
				case SEMI_COLON: return -54;
				case RIGHT_PARENTHESIS: return -54;
				case COMMA: return -54;
				case AND: return -54;
				case OR: return -54;
				case LESS_THAN: return -54;
				case GREATER_THAN: return -54;
				case LESS_OR_EQUAL: return -54;
				case GREATER_OR_EQUAL: return -54;
				case EQUAL_EQUAL: return -54;
				case NOT_EQUAL: return -54;
				case PLUS: return -54;
				case MINUS: return -54;
				case TIMES: return -54;
				case DIVIDE: return -54;
			}
			break;
		case 126: //CHECK STAGE 126
			switch(input)
			{
				case LEFT_SQUARE: return 80;
				case RIGHT_SQUARE: return -51;
				case SEMI_COLON: return -51;
				case RIGHT_PARENTHESIS: return -51;
				case COMMA: return -51;
				case AND: return -51;
				case OR: return -51;
				case LESS_THAN: return -51;
				case GREATER_THAN: return -51;
				case LESS_OR_EQUAL: return -51;
				case GREATER_OR_EQUAL: return -51;
				case EQUAL_EQUAL: return -51;
				case NOT_EQUAL: return -51;
				case PLUS: return -51;
				case MINUS: return -51;
				case TIMES: return -51;
				case DIVIDE: return -51;
				case DOT: return 79;
			}
			break;
		case 127: //CHECK STAGE 127
			switch(input)
			{
				case LEFT_SQUARE: return 80;
				case RIGHT_SQUARE: return -52;
				case SEMI_COLON: return -52;
				case RIGHT_PARENTHESIS: return -52;
				case COMMA: return -52;
				case AND: return -52;
				case OR: return -52;
				case LESS_THAN: return -52;
				case GREATER_THAN: return -52;
				case LESS_OR_EQUAL: return -52;
				case GREATER_OR_EQUAL: return -52;
				case EQUAL_EQUAL: return -52;
				case NOT_EQUAL: return -52;
				case PLUS: return -52;
				case MINUS: return -52;
				case TIMES: return -52;
				case DIVIDE: return -52;
				case DOT: return 79;
			}
			break;
		case 128: //CHECK STAGE 128
			switch(input)
			{
				case RIGHT_PARENTHESIS: return 150;
				case AND: return 112;
				case OR: return 113;
			}
			break;
		case 129: //CHECK STAGE 129
			switch(input)
			{
				case LEFT_PARENTHESIS: return 151;
			}
			break;
		case 130: //CHECK STAGE 130
			switch(input)
			{
				case RIGHT_SQUARE: return -57;
				case SEMI_COLON: return -57;
				case RIGHT_PARENTHESIS: return -57;
				case COMMA: return -57;
				case AND: return -57;
				case OR: return -57;
				case LESS_THAN: return -57;
				case GREATER_THAN: return -57;
				case LESS_OR_EQUAL: return -57;
				case GREATER_OR_EQUAL: return -57;
				case EQUAL_EQUAL: return -57;
				case NOT_EQUAL: return -57;
				case PLUS: return -57;
				case MINUS: return -57;
				case TIMES: return -57;
				case DIVIDE: return -57;
			}
			break;
		case 131: //CHECK STAGE 131
			switch(input)
			{
				case RIGHT_SQUARE: return -58;
				case SEMI_COLON: return -58;
				case RIGHT_PARENTHESIS: return -58;
				case COMMA: return -58;
				case AND: return -58;
				case OR: return -58;
				case LESS_THAN: return -58;
				case GREATER_THAN: return -58;
				case LESS_OR_EQUAL: return -58;
				case GREATER_OR_EQUAL: return -58;
				case EQUAL_EQUAL: return -58;
				case NOT_EQUAL: return -58;
				case PLUS: return -58;
				case MINUS: return -58;
				case TIMES: return -58;
				case DIVIDE: return -58;
			}
			break;
		case 132: //CHECK STAGE 132
			switch(input)
			{
				case RIGHT_PARENTHESIS: return 152;
				case AND: return 112;
				case OR: return 113;
			}
			break;
		case 133: //CHECK STAGE 133
			switch(input)
			{
				case LEFT_PARENTHESIS: return 153;
			}
			break;
		case 134: //CHECK STAGE 134
			switch(input)
			{
				case LEFT_BRACES: return -31;
				case RIGHT_BRACES: return -31;
				case IF: return -31;
				case ELSE: return -31;
				case WHILE: return -31;
				case DO: return -31;
				case BREAK: return -31;
				case CONTINUE: return -31;
				case ID: return -31;
			}
			break;
		case 135: //CHECK STAGE 135
			switch(input)
			{
				case EQUALS: return -67;
				case LEFT_SQUARE: return -67;
				case RIGHT_SQUARE: return -67;
				case SEMI_COLON: return -67;
				case RIGHT_PARENTHESIS: return -67;
				case COMMA: return -67;
				case AND: return -67;
				case OR: return -67;
				case LESS_THAN: return -67;
				case GREATER_THAN: return -67;
				case LESS_OR_EQUAL: return -67;
				case GREATER_OR_EQUAL: return -67;
				case EQUAL_EQUAL: return -67;
				case NOT_EQUAL: return -67;
				case PLUS: return -67;
				case MINUS: return -67;
				case TIMES: return -67;
				case DIVIDE: return -67;
				case PLUS_PLUS: return -67;
				case MINUS_MINUS: return -67;
				case DOT: return -67;
			}
			break;
		case 136: //CHECK STAGE 136
			switch(input)
			{
				case TYPE: return -23;
				case LEFT_BRACES: return -23;
				case RIGHT_BRACES: return -23;
				case FUNCTION: return -23;
				case VAR: return -23;
				case IF: return -23;
				case ELSE: return -23;
				case WHILE: return -23;
				case DO: return -23;
				case BREAK: return -23;
				case CONTINUE: return -23;
				case ID: return -23;
				case $: return -23;
			}
			break;
		case 137: //CHECK STAGE 137
			switch(input)
			{
				case LEFT_BRACES: return -77;
				case IF: return 63;
				case WHILE: return 64;
				case DO: return 65;
				case BREAK: return 68;
				case CONTINUE: return 69;
				case ID: return 22;
				case S: return 154;
				case LV: return 67;
				case IDU: return 70;
				case NB: return 66;
			}
			break;
		case 138: //CHECK STAGE 138
			switch(input)
			{
				case RIGHT_SQUARE: return -34;
				case SEMI_COLON: return -34;
				case RIGHT_PARENTHESIS: return -34;
				case COMMA: return -34;
				case AND: return -34;
				case OR: return -34;
				case LESS_THAN: return 114;
				case GREATER_THAN: return 115;
				case LESS_OR_EQUAL: return 116;
				case GREATER_OR_EQUAL: return 117;
				case EQUAL_EQUAL: return 118;
				case NOT_EQUAL: return 119;
			}
			break;
		case 139: //CHECK STAGE 139
			switch(input)
			{
				case RIGHT_SQUARE: return -35;
				case SEMI_COLON: return -35;
				case RIGHT_PARENTHESIS: return -35;
				case COMMA: return -35;
				case AND: return -35;
				case OR: return -35;
				case LESS_THAN: return 114;
				case GREATER_THAN: return 115;
				case LESS_OR_EQUAL: return 116;
				case GREATER_OR_EQUAL: return 117;
				case EQUAL_EQUAL: return 118;
				case NOT_EQUAL: return 119;
			}
			break;
		case 140: //CHECK STAGE 140
			switch(input)
			{
				case RIGHT_SQUARE: return -37;
				case SEMI_COLON: return -37;
				case RIGHT_PARENTHESIS: return -37;
				case COMMA: return -37;
				case AND: return -37;
				case OR: return -37;
				case LESS_THAN: return -37;
				case GREATER_THAN: return -37;
				case LESS_OR_EQUAL: return -37;
				case GREATER_OR_EQUAL: return -37;
				case EQUAL_EQUAL: return -37;
				case NOT_EQUAL: return -37;
				case PLUS: return 120;
				case MINUS: return 121;
			}
			break;
		case 141: //CHECK STAGE 141
			switch(input)
			{
				case RIGHT_SQUARE: return -38;
				case SEMI_COLON: return -38;
				case RIGHT_PARENTHESIS: return -38;
				case COMMA: return -38;
				case AND: return -38;
				case OR: return -38;
				case LESS_THAN: return -38;
				case GREATER_THAN: return -38;
				case LESS_OR_EQUAL: return -38;
				case GREATER_OR_EQUAL: return -38;
				case EQUAL_EQUAL: return -38;
				case NOT_EQUAL: return -38;
				case PLUS: return 120;
				case MINUS: return 121;
			}
			break;
		case 142: //CHECK STAGE 142
			switch(input)
			{
				case RIGHT_SQUARE: return -39;
				case SEMI_COLON: return -39;
				case RIGHT_PARENTHESIS: return -39;
				case COMMA: return -39;
				case AND: return -39;
				case OR: return -39;
				case LESS_THAN: return -39;
				case GREATER_THAN: return -39;
				case LESS_OR_EQUAL: return -39;
				case GREATER_OR_EQUAL: return -39;
				case EQUAL_EQUAL: return -39;
				case NOT_EQUAL: return -39;
				case PLUS: return 120;
				case MINUS: return 121;
			}
			break;
		case 143: //CHECK STAGE 143
			switch(input)
			{
				case RIGHT_SQUARE: return -40;
				case SEMI_COLON: return -40;
				case RIGHT_PARENTHESIS: return -40;
				case COMMA: return -40;
				case AND: return -40;
				case OR: return -40;
				case LESS_THAN: return -40;
				case GREATER_THAN: return -40;
				case LESS_OR_EQUAL: return -40;
				case GREATER_OR_EQUAL: return -40;
				case EQUAL_EQUAL: return -40;
				case NOT_EQUAL: return -40;
				case PLUS: return 120;
				case MINUS: return 121;
			}
			break;
		case 144: //CHECK STAGE 144
			switch(input)
			{
				case RIGHT_SQUARE: return -41;
				case SEMI_COLON: return -41;
				case RIGHT_PARENTHESIS: return -41;
				case COMMA: return -41;
				case AND: return -41;
				case OR: return -41;
				case LESS_THAN: return -41;
				case GREATER_THAN: return -41;
				case LESS_OR_EQUAL: return -41;
				case GREATER_OR_EQUAL: return -41;
				case EQUAL_EQUAL: return -41;
				case NOT_EQUAL: return -41;
				case PLUS: return 120;
				case MINUS: return 121;
			}
			break;
		case 145: //CHECK STAGE 145
			switch(input)
			{
				case RIGHT_SQUARE: return -42;
				case SEMI_COLON: return -42;
				case RIGHT_PARENTHESIS: return -42;
				case COMMA: return -42;
				case AND: return -42;
				case OR: return -42;
				case LESS_THAN: return -42;
				case GREATER_THAN: return -42;
				case LESS_OR_EQUAL: return -42;
				case GREATER_OR_EQUAL: return -42;
				case EQUAL_EQUAL: return -42;
				case NOT_EQUAL: return -42;
				case PLUS: return 120;
				case MINUS: return 121;
			}
			break;
		case 146: //CHECK STAGE 146
			switch(input)
			{
				case RIGHT_SQUARE: return -44;
				case SEMI_COLON: return -44;
				case RIGHT_PARENTHESIS: return -44;
				case COMMA: return -44;
				case AND: return -44;
				case OR: return -44;
				case LESS_THAN: return -44;
				case GREATER_THAN: return -44;
				case LESS_OR_EQUAL: return -44;
				case GREATER_OR_EQUAL: return -44;
				case EQUAL_EQUAL: return -44;
				case NOT_EQUAL: return -44;
				case PLUS: return -44;
				case MINUS: return -44;
				case TIMES: return 122;
				case DIVIDE: return 123;
			}
			break;
		case 147: //CHECK STAGE 147
			switch(input)
			{
				case RIGHT_SQUARE: return -45;
				case SEMI_COLON: return -45;
				case RIGHT_PARENTHESIS: return -45;
				case COMMA: return -45;
				case AND: return -45;
				case OR: return -45;
				case LESS_THAN: return -45;
				case GREATER_THAN: return -45;
				case LESS_OR_EQUAL: return -45;
				case GREATER_OR_EQUAL: return -45;
				case EQUAL_EQUAL: return -45;
				case NOT_EQUAL: return -45;
				case PLUS: return -45;
				case MINUS: return -45;
				case TIMES: return 122;
				case DIVIDE: return 123;
			}
			break;
		case 148: //CHECK STAGE 148
			switch(input)
			{
				case RIGHT_SQUARE: return -47;
				case SEMI_COLON: return -47;
				case RIGHT_PARENTHESIS: return -47;
				case COMMA: return -47;
				case AND: return -47;
				case OR: return -47;
				case LESS_THAN: return -47;
				case GREATER_THAN: return -47;
				case LESS_OR_EQUAL: return -47;
				case GREATER_OR_EQUAL: return -47;
				case EQUAL_EQUAL: return -47;
				case NOT_EQUAL: return -47;
				case PLUS: return -47;
				case MINUS: return -47;
				case TIMES: return -47;
				case DIVIDE: return -47;
			}
			break;
		case 149: //CHECK STAGE 149
			switch(input)
			{
				case RIGHT_SQUARE: return -48;
				case SEMI_COLON: return -48;
				case RIGHT_PARENTHESIS: return -48;
				case COMMA: return -48;
				case AND: return -48;
				case OR: return -48;
				case LESS_THAN: return -48;
				case GREATER_THAN: return -48;
				case LESS_OR_EQUAL: return -48;
				case GREATER_OR_EQUAL: return -48;
				case EQUAL_EQUAL: return -48;
				case NOT_EQUAL: return -48;
				case PLUS: return -48;
				case MINUS: return -48;
				case TIMES: return -48;
				case DIVIDE: return -48;
			}
			break;
		case 150: //CHECK STAGE 150
			switch(input)
			{
				case RIGHT_SQUARE: return -55;
				case SEMI_COLON: return -55;
				case RIGHT_PARENTHESIS: return -55;
				case COMMA: return -55;
				case AND: return -55;
				case OR: return -55;
				case LESS_THAN: return -55;
				case GREATER_THAN: return -55;
				case LESS_OR_EQUAL: return -55;
				case GREATER_OR_EQUAL: return -55;
				case EQUAL_EQUAL: return -55;
				case NOT_EQUAL: return -55;
				case PLUS: return -55;
				case MINUS: return -55;
				case TIMES: return -55;
				case DIVIDE: return -55;
			}
			break;
		case 151: //CHECK STAGE 151
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case E: return 156;
				case L: return 85;
				case R: return 86;
				case Y: return 87;
				case F: return 88;
				case LE: return 155;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 152: //CHECK STAGE 152
			switch(input)
			{
				case LEFT_BRACES: return -77;
				case IF: return 63;
				case WHILE: return 64;
				case DO: return 65;
				case BREAK: return 68;
				case CONTINUE: return 69;
				case ID: return 22;
				case S: return 157;
				case LV: return 67;
				case IDU: return 70;
				case NB: return 66;
			}
			break;
		case 153: //CHECK STAGE 153
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case E: return 158;
				case L: return 85;
				case R: return 86;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 154: //CHECK STAGE 154
			switch(input)
			{
				case LEFT_BRACES: return -26;
				case RIGHT_BRACES: return -26;
				case IF: return -26;
				case ELSE: return 159 / -26;
				case WHILE: return -26;
				case DO: return -26;
				case BREAK: return -26;
				case CONTINUE: return -26;
				case ID: return -26;
			}
			break;
		case 155: //CHECK STAGE 155
			switch(input)
			{
				case RIGHT_PARENTHESIS: return 160;
				case COMMA: return 161;
			}
			break;
		case 156: //CHECK STAGE 156
			switch(input)
			{
				case RIGHT_PARENTHESIS: return -65;
				case COMMA: return -65;
				case AND: return 112;
				case OR: return 113;
			}
			break;
		case 157: //CHECK STAGE 157
			switch(input)
			{
				case LEFT_BRACES: return -28;
				case RIGHT_BRACES: return -28;
				case IF: return -28;
				case ELSE: return -28;
				case WHILE: return -28;
				case DO: return -28;
				case BREAK: return -28;
				case CONTINUE: return -28;
				case ID: return -28;
			}
			break;
		case 158: //CHECK STAGE 158
			switch(input)
			{
				case RIGHT_PARENTHESIS: return 162;
				case AND: return 112;
				case OR: return 113;
			}
			break;
		case 159: //CHECK STAGE 159
			switch(input)
			{
				case LEFT_BRACES: return -82;
				case RIGHT_BRACES: return -82;
				case IF: return -82;
				case ELSE: return -82;
				case WHILE: return -82;
				case DO: return -82;
				case BREAK: return -82;
				case CONTINUE: return -82;
				case ID: return -82;
				case ME: return 163;
			}
			break;
		case 160: //CHECK STAGE 160
			switch(input)
			{
				case RIGHT_SQUARE: return -56;
				case SEMI_COLON: return -56;
				case RIGHT_PARENTHESIS: return -56;
				case COMMA: return -56;
				case AND: return -56;
				case OR: return -56;
				case LESS_THAN: return -56;
				case GREATER_THAN: return -56;
				case LESS_OR_EQUAL: return -56;
				case GREATER_OR_EQUAL: return -56;
				case EQUAL_EQUAL: return -56;
				case NOT_EQUAL: return -56;
				case PLUS: return -56;
				case MINUS: return -56;
				case TIMES: return -56;
				case DIVIDE: return -56;
			}
			break;
		case 161: //CHECK STAGE 161
			switch(input)
			{
				case LEFT_PARENTHESIS: return 92;
				case MINUS: return 94;
				case PLUS_PLUS: return 90;
				case MINUS_MINUS: return 91;
				case NOT: return 95;
				case ID: return 22;
				case TRUE: return 101;
				case FALSE: return 102;
				case CHARACTER: return 103;
				case STRINGVAL: return 104;
				case NUMERAL: return 31;
				case E: return 164;
				case L: return 85;
				case R: return 86;
				case Y: return 87;
				case F: return 88;
				case LV: return 89;
				case TRU: return 96;
				case FAL: return 97;
				case CHR: return 98;
				case STR: return 99;
				case NUM: return 100;
				case IDU: return 93;
			}
			break;
		case 162: //CHECK STAGE 162
			switch(input)
			{
				case SEMI_COLON: return 165;
			}
			break;
		case 163: //CHECK STAGE 163
			switch(input)
			{
				case LEFT_BRACES: return -77;
				case IF: return 63;
				case WHILE: return 64;
				case DO: return 65;
				case BREAK: return 68;
				case CONTINUE: return 69;
				case ID: return 22;
				case S: return 166;
				case LV: return 67;
				case IDU: return 70;
				case NB: return 66;
			}
			break;
		case 164: //CHECK STAGE 164
			switch(input)
			{
				case RIGHT_PARENTHESIS: return -64;
				case COMMA: return -64;
				case AND: return 112;
				case OR: return 113;
			}
			break;
		case 165: //CHECK STAGE 165
			switch(input)
			{
				case LEFT_BRACES: return -29;
				case RIGHT_BRACES: return -29;
				case IF: return -29;
				case ELSE: return -29;
				case WHILE: return -29;
				case DO: return -29;
				case BREAK: return -29;
				case CONTINUE: return -29;
				case ID: return -29;
			}
			break;
		case 166: //CHECK STAGE 166
			switch(input)
			{
				case LEFT_BRACES: return -27;
				case RIGHT_BRACES: return -27;
				case IF: return -27;
				case ELSE: return -27;
				case WHILE: return -27;
				case DO: return -27;
				case BREAK: return -27;
				case CONTINUE: return -27;
				case ID: return -27;
			}
			break;
	}
}
