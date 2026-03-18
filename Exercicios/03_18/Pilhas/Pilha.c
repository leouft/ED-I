#include "Pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct _pilha
{
    int index;
    int tamanho;
    int *data;
};

Pilha *pilha_create(int x)
{
    Pilha *p = malloc(sizeof(Pilha));
    if (p == NULL)
        printf("\nErro ao alocar a memória.\n");
    else
    {
        p->data = malloc(x * (sizeof(int)));
        p->index = -1;
        p->tamanho = x;
    }
    return p;
}

bool pilha_is_full(Pilha *p)
{
    return p->index == (p->tamanho - 1);
}

void pilha_insert(Pilha *p, int x)
{
    if (!pilha_is_full(p))
    {
        p->index++;
        p->data[p->index] = x;
        printf("\nElemento inserido com sucesso.\n");
    }
    else
        printf("\nPilha já está cheia.\n");
}

void pop(Pilha *p)
{
    if (p->index > -1)
    {
        p->data[p->index] = 0;
        p->index--;
        printf("\nElemento removido ocm sucesso.\n");
    }
    else
        printf("\nPilha já está vazia.\n");
}

int pilha_acess(Pilha *p)
{
    return p->data[p->index];
}

void pilha_destroy(Pilha *p)
{
    free(p);
    printf("\nPilha destruída.\n");
}

void pilha_info(Pilha *p)
{
    printf("\nTamanho da pilha: %d\n", p->tamanho);
    if (p->index == -1)
        printf("A pilha está vazia.\n");
    else if (pilha_is_full(p))
        printf("A pilha está cheia.\n");
    else
        printf("A pilha tem %d elementos.\n", p->index + 1);
}