#include "TLList.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    int info;
    struct _no* prox;
} TNo;

struct _list{
    TNo* inicio;
};

TLList* createList() {
    TLList* new = malloc(sizeof(TLList));
    if (!new) return NULL;
    new->inicio = NULL;
    return new;
}

TNo* createNFill(int value) {
    TNo* new = malloc(sizeof(TNo));
    if (new != NULL) {
        new->info = value;
        new->prox = NULL;
    }
    return new;
}

bool TLListInsertBegin(TLList* list, int value) {
    TNo* new = createNFill(value);
    new->prox = list->inicio;
    list->inicio = new;
    return true;
}

bool TLListInsertEnd(TLList* list, int value) {
    TNo* new = createNFill(value);
    if (!new) return false;
    TNo** aux = &(list->inicio);
    while(*aux != NULL) {
        aux = &(*aux)->prox;
    }
    *aux = new;
    return true;
}

void TLListPrint(TLList* list) {
    TNo* temp = list->inicio;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->prox;
    }
    printf("\n");
}