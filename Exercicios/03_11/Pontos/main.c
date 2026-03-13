#include "TPonto.h"
#include <stdio.h>

void main()
{
    int op2;
    int op;
    float x, y;

    TPonto *ponto1, *ponto2;
    printf("Insira os valores x e y do ponto 1: ");
    scanf("%f %f", &x, &y);
    ponto1 = TPonto_create(x, y);

    printf("Insira os valores x e y do ponto 2: ");
    scanf("%f %f", &x, &y);
    ponto2 = TPonto_create(x, y);

    do
    {
        printf("\nO que deseja fazer?\nImprimir ponto [1]\nModificar os valores dos pontos [2]\nCalcular a distância entre os pontos [3]\nAdquirir os valores do ponto [4]\nSair [0]\nOpção: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nQual ponto deseja ver? [1/2]: ");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                TPonto_print(ponto1);
            }
            else if (op2 == 2)
            {
                TPonto_print(ponto2);
            }
            else
            {
                printf("\nOpção inválida!\n");
            }
            putchar('\n');
            break;
        case 2:
            printf("\nQual ponto deseja modificar? [1/2]: ");
            scanf("%d", &op2);
            if (op2 == 1)
            {
                printf("Insira os novos valores x e y do ponto 1: ");
                scanf("%f %f", &x, &y);
                TPonto_set_x(ponto1, x);
                TPonto_set_y(ponto1, y);
            }
            else if (op2 == 2)
            {
                printf("Insira os novos valores x e y do ponto 2: ");
                scanf("%f %f", &x, &y);
                TPonto_set_x(ponto2, x);
                TPonto_set_y(ponto2, y);
            }
            else
            {
                printf("\nOpção inválida!\n");
            }
            break;
        case 3:
            printf("\nDistância entre os pontos: %0.2f\n", TPonto_dist(ponto1, ponto2));
            break;
        case 4:
            printf("\nQual ponto deseja adquirir os valores? [1/2]: ");
            scanf("%d", &op2);
            if (op2 == 1)            {
                TPonto_get_x(ponto1, &x);
                TPonto_get_y(ponto1, &y);
                printf("\nPonto 1: (%0.2f , %0.2f)\n", x, y);
            }
            else if (op2 == 2)
            {
                TPonto_get_x(ponto2, &x);
                TPonto_get_y(ponto2, &y);
                printf("\nPonto 2: (%0.2f , %0.2f)\n", x, y);
            }
            else
            {
                printf("\nOpção inválida!\n");
            }
            break;
        case 0:
            printf("\nSaindo...\n");
            TPonto_destroy(ponto1);
            TPonto_destroy(ponto2);
            break;
        default:
            printf("\nOpção inválida!\n");
            break;
        }
    } while (op != 0);
}