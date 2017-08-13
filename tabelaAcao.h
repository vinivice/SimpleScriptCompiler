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
    //get from table
    return 0;
}
