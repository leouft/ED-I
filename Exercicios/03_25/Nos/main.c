#include "Pilha.h"
#include <stdio.h>

void main()
{
    int info;
    int op;
    Pilha *pilha = pilha_create();
    do
    {
        printf("\n[1] Criar nó\n[2] Remover nó\n[3] Acessar nó\n[4-6] Destruir pilha\nOpção: ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                printf("\nElemento pra inserir: ");
                scanf("%d", &info);
                pilha_push(pilha, info);
                break;
            case 2:
                if (pilha_pop(pilha, &info))
                {
                    printf("\nElemento removido: %d\n", info);
                    break;
                }
                printf("\nPilha já está vazia.\n");
                break;
            case 3:
                if (pilha_acess(pilha, &info))
                {
                    printf("\nElemento do topo: %d\n", info);
                    break;
                }
                printf("\nPilha vazia\n");
                break;
            case 4:
                pilha_destroy(pilha);
                printf("\nPilha destruída.\n");
                break;
            case 5:
                pilha_destroy_sem_pop(pilha);
                printf("\nPilha destruída.\n");
                break;
            case 6:
                pilha_destroy_recursivo(pilha);
                printf("\nPilha destruída.\n");
                break;
        }
    } while (op != 0);
    
}