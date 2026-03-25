#include "Pilha.h"
#include <stdio.h>

void main()
{
    int op;
    int op2;
    printf("Insira o tamanho da pilha: ");
    scanf("%d", &op);
    Pilha *pilha = pilha_create(op);

    do{
        printf("\nInserir elemento no topo da pilha [1]\nRemover elemento do topo da pilha [2]\nAcessar elemento do topo [3]\nInfos da pilha [4]\nOpção: ");
        scanf("%d", &op);
        switch (op)
        {
            case 0:
                printf("\nSaindo...\n");
                pilha_destroy(pilha);
                break;
            case 1:
                printf("\nQual elemento deseja inserir na pilha? ");
                scanf("%d", &op2);
                pilha_insert(pilha, op2);
                break;
            case 2:
                pop(pilha);
                break;
            case 3:
                pilha_acess(pilha, &op2);
                printf("\nElemento do topo da pilha: %d\n", op2);
                break;
            case 4:
                pilha_info(pilha);
                break;
            default:
                printf("\nOpção inexistente.\n");
                break;
        }
    } while (op != 0);
}