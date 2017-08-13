typedef struct 
{
    int len;
    int left;
} elementoTabelaAuxiliar;

elementoTabelaAuxiliar rule(int p)
{
    elementoTabelaAuxiliar eta;
    eta.len = 1;
    eta.left = 2;
    //checa na tabela
    return eta;
}

int action(int state, int input)
{
    switch(state)
    {
        case 0: //CHECK STAGE 0
                switch(input)
                {
                    case type: return 6;
                    case function: return 5;
                    case LDE: return 1;
                    case DE: return 2;
                    case DT: return 4;
                    case DF: return 3;
                }
                break;

        case 1: //CHECK STAGE 1
                switch(input)
                {
                    case type: return 6;
                    case function: return 5;
                    case $: return 10000;
                    case DE: return 7;
                    case DT: return 4;
                    case DF: return 3;
                }
                break;

        case 2: //CHECK STAGE 2
                switch(input)
                {
                    case type: 
                    case function: 
                    case $: return -2;
                }
                break;

        case 3: //CHECK STAGE 3
                switch(input)
                {
                    case type: 
                    case function: 
                    case $: return -3;
                }
                break;

        case 4: //CHECK STAGE 4
                switch(input)
                {
                    case type: 
                    case function: 
                    case $: return -4;
                }
                break;
        case 5: //CHECK STAGE 5
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        case 0: //CHECK STAGE 0
                break;
        default:
                return 10001;
    }
    //get from table
    return 0;
}
