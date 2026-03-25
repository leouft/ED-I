#include "Pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _no
{
    int info;
    struct _no *prox;
} TNo;

struct _pilha
{
    unsigned int qty;
    TNo *topo;
};

Pilha *pilha_create()
{
    Pilha *p = malloc(sizeof(Pilha));
    if (p != NULL)
    {
        p->topo = NULL;
        p->qty = 0;
    }
    return p;   
}

bool pilha_push(Pilha *p, int info)
{
    TNo *novo = malloc(sizeof(TNo));
    if (novo == NULL)
        return false;
    novo->info = info;
    novo->prox = p->topo;
    p->topo = novo;
    p->qty++;
    return true;
}

bool pilha_pop(Pilha *p, int *pinfo)
{
    if (p->topo == NULL)
        return false;
    // pinfo vai ser a variável que vai receber o nó
    *pinfo = p->topo->info;
    TNo* topo_antigo = p->topo;
    p->topo = p->topo->prox;
    free(topo_antigo);
    p->qty--;
    return true;
}

bool pilha_acess(Pilha* p, int* pinfo)
{
    if (p->topo == NULL)
        return false;
    *pinfo = p->topo->info;
    return true;
}

unsigned int pilha_size(Pilha* p)
{
    return p->qty;
}

void pilha_destroy(Pilha* p)
{
    int pinfo;
    while (pilha_pop(p, &pinfo));
    free(p);
}

void pilha_destroy_sem_pop(Pilha* p)
{
    while (p->topo->prox != NULL)
    {
        TNo* antigo = p->topo;
        p->topo = p->topo->prox;
        free(antigo);
    }
    free(p);
}

void pilha_destroy_recursivo(Pilha* p)
{
    if (p->topo->prox != NULL)
    {
        TNo* antigo = p->topo;
        p->topo = p->topo->prox;
        free(antigo);
        pilha_destroy_recursivo(p);
    }
    free(p);
}

bool pilha_is_empty(Pilha* p)
{
    return p->qty == 0;
}

bool pilha_is_full(Pilha* p)
{
    return false;
}
