#include "Conj.h"
#include <stdio.h>

void main()
{
    int x;
    int conj;
    int op;
    Conj *c[2] = {Conj_create(), Conj_create()};
    do
    {
        printf("\nO que deseja fazer?\nInserir elemento ao conjunto [1]\nRemover elemento do conjunto [2]\nSair [0]\nOpção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &x);
            printf("\nEm qual conjunto deseja inserir o elemento? [1/2]: ");
            scanf("%d", &conj);
            conj--;
            Conj_insert(c[conj], x);
            break;
        case 2:
            printf("\nDigite o elemento a ser removido: ");
            scanf("%d", &x);
            printf("\nDe qual conjunto deseja remover o elemento? [1/2]: ");
            scanf("%d", &conj); 
            conj--;
            Conj_remove(c[conj], x);
            break;
        case 0:
            printf("\nSaindo...\n");
            break;
        default:
            printf("\nOpção inválida.\n");
            break;
        }
    } while (op != 0);
}