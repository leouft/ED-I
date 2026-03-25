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

bool pilha_insert(Pilha *p, int x)
{
    if (!pilha_is_full(p))
    {
        p->index++;
        p->data[p->index] = x;
        printf("\nElemento inserido com sucesso.\n");
        return true;
    }
    else
        printf("\nPilha já está cheia.\n");
    return false;
}

bool pop(Pilha *p)
{
    if (p->index > -1)
    {
        p->data[p->index] = 0;
        p->index--;
        printf("\nElemento removido com sucesso.\n");
        return true;
    }
    else
        printf("\nPilha já está vazia.\n");
        return false;
}

bool pilha_is_empty(Pilha *p)
{
    return p->index == -1;
}


bool pilha_acess(Pilha *p, int *valor)
{
    if(pilha_is_empty(p))
        return false;
    int topo = p->data[p->index];
    *valor = topo;
    return true;
}

unsigned int pilha_len(Pilha *p)
{
    return p->index;
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
        printf("A pilha tem %d elementos.\n", pilha_len(p)+1);
}