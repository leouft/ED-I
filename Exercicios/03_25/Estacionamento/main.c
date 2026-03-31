#include "Stack.h"
#include <stdio.h>

void main(){
    Pilha *pilha = stackCreate();
    Pilha *pilha_sec = stackCreate();
    int id;
    char op;
    int op2;

    do{
        scanf(" %c %d", &op, &op2);
        if (op == 'i')
            stackPush(pilha, op2);
        else if (op == 'r')
            stackPop(pilha, pilha_sec, &id, op2);
        else if (op == 'v' && op2 == 0)
            stackVer(pilha);
    } while (op != '0' || op2 != 0);
}