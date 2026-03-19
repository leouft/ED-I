#include "Pilha.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void main()
{
    char text[100];
    bool correto = true;
    printf("Insira os parenteses: ");
    scanf("%s", text);
    Pilha *pilha = pilha_create(strlen(text));

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '(')
            pilha_insert(pilha, 1);
        else if (text[i] == ')')
            if (!pop(pilha))
            {
                correto = false;
                break;
            }
    }

    if (correto && pilha_acess(pilha) == 0)
        printf("\nParenteses corretos.\n");
    else
        printf("\nParenteses incorretos.\n");
}