#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct _no
{
    int id;
    struct _no *prox;
} TNo;

struct _pilha
{
    int qty;
    TNo *topo;
};

Pilha *stackCreate()
{
    Pilha *novo = malloc(sizeof(Pilha));
    if (novo != NULL)
    {
        novo->qty = 0;
        novo->topo = NULL;
    }
    return novo;
}

bool stackPush(Pilha *pilha, int id)
{
    if (pilha->qty < 10)
    {
        for (int i = 0; i < pilha->qty; i++)
        {
            TNo *atual = pilha->topo;
            if (atual == NULL)
                break;
            while (atual != NULL)
            {
                if (atual->id == id)
                {
                    printf("\nCarro já existente.\n");
                    return false;
                }
                atual = atual->prox;
            }
        }
        TNo *no = malloc(sizeof(TNo));
        if (no == NULL)
        {
            return false;
        }
        no->id = id;
        no->prox = pilha->topo;
        pilha->topo = no;
        pilha->qty++;
        return true;
    }
    else
        printf("overflow (limite atingido).\n");
    return false;
}

bool stackPop(Pilha *pilha, Pilha *pilha_sec, int *id, int op)
{
    while (pilha->topo != NULL)
    {
        printf("%d, ", pilha->topo->id);
        TNo* no_temp;
        if (pilha->topo->id == op)
        {
            no_temp = pilha->topo;
            *id = no_temp->id;
            pilha->topo = pilha->topo->prox;
            free(no_temp);
            pilha->qty--;
            stackRetornar(pilha, pilha_sec);
            pilha_sec->qty = 0; 
            printf("\n");
            return true;
        }
        no_temp = pilha->topo;
        pilha->topo = pilha->topo->prox;
        no_temp->prox = pilha_sec->topo;
        pilha_sec->topo = no_temp;
        pilha_sec->qty++;
    }
    stackRetornar(pilha, pilha_sec);
    printf("underflow (carro não encontrado).\n");
    return false;
}

void stackVer(Pilha *pilha)
{
    TNo *atual = pilha->topo;
    if (atual == NULL)
    {
        printf("\nPilha vazia\n\n");
        return;
    }
    while (atual != NULL)
    {
        printf("%d, ", atual->id);
        atual = atual->prox;
    }
    printf("\n\n");
}

void stackRetornar(Pilha *pilha, Pilha* pilha_sec)
{
    TNo *no_temp;
    while (pilha_sec->topo != NULL)
    {
        no_temp = pilha_sec->topo->prox;
        pilha_sec->topo->prox = pilha->topo;
        pilha->topo = pilha_sec->topo;
        pilha_sec->topo = no_temp;
    }
    pilha_sec->qty = 0;
}