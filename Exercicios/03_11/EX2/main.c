#include "Conj.h"
#include <stdio.h>

void main()
{
    int x;
    int conj;
    int op;
    Conj *intersecao;
    Conj *diferenca;
    Conj *uniao;
    Conj *c[2] = {Conj_create(), Conj_create()};
    do
    {
        printf("\nO que deseja fazer?\nInserir elemento ao conjunto [1]\nRemover elemento do conjunto [2]\nIntersecção dos conjuntos [3]\nDiferença dos conjuntos A-B [4]\nUnião dos conjuntos [5]\nMaior valor [6]\nMenor valor [7]\nIgualdade de conjuntos [8]\nTamanho do conjunto [9]\nConjunto vazio [10]\nSair [0]\nOpção: ");
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
        case 3:
            intersecao = Conj_intersection(c[0], c[1]);
            break;
        case 4:
            diferenca = Conj_difference(c[0], c[1]);
            break;
        case 5:
            uniao = Conj_union(c[0], c[1]);
            break;
        case 6:
            printf("\nQual conjunto deseja ver o maior valor? [1/2]: ");
            scanf("%d", &conj);
            conj--;
            if (Conj_maior(c[conj]) != -1)
            {
                printf("\nMaior valor: %d\n", Conj_maior(c[conj]));
            }
            break;
        case 7:
            printf("\nQual conjunto deseja ver o menor valor? [1/2]: ");
            scanf("%d", &conj);
            conj--;
            if (Conj_menor(c[conj]) != -1)
            {
                printf("\nMenor valor: %d\n", Conj_menor(c[conj]));
            }
            break;
        case 8:
            if (Conj_equals(c[0], c[1]))
            {
                printf("\nOs conjuntos são iguais.\n");
            }
            else
            {
                printf("\nOs conjuntos são diferentes.\n");
            }
            break;
        case 9:
            printf("\nTamanho do conjunto 1: %d\n", Conj_size(c[0]));
            printf("\nTamanho do conjunto 2: %d\n", Conj_size(c[1]));
            break;
        case 10:
            if (Conj_null(c[0]))
            {
                printf("\nO conjunto 1 é vazio: Sim\n");
            }
            else
            {
                printf("\nO conjunto 1 é vazio: Não\n");
            }
            if (Conj_null(c[1]))
            {
                printf("\nO conjunto 2 é vazio: Sim\n");
            }
            else
            {
                printf("\nO conjunto 2 é vazio: Não\n");
            }
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