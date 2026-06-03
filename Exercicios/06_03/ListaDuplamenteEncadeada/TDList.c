#include "TDList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    int info;
    struct _no* prox;
    struct _no* ant;
} TNo;

struct _list {
    TNo* inicio;
    TNo* fim;
};

TDList* TDList_create() {
    TDList* new = malloc(sizeof(TDList));
    if (!new) return NULL;
    new->inicio = NULL;
    new->fim = NULL;
    return new;
}

bool TDList_insert_begin(TDList* list, int value) {
    TNo* new = malloc(sizeof(TNo));
    if (!new) return false;
    new->info = value;
    new->prox = NULL;
    new->ant = NULL;
    if (list->inicio != NULL) {
        list->inicio->ant = new;
        new->prox = list->inicio;
    }
    else
        list->fim = new;
    list->inicio = new;
    return true;
}

bool TDList_insert_end(TDList* list, int value) {
    TNo* new = malloc(sizeof(TNo));
    if (!new) return false;
    new->info = value;
    new->prox = NULL;
    new->ant = NULL;
    if (list->fim != NULL) {
        list->fim->prox = new;
        new->ant = list->fim;
    }
    else
        list->inicio = new;
    list->fim = new;
    return true;
}

void TDList_print(TDList* list) {
    TNo* aux = list->inicio;
    while (aux != NULL) {
        printf("%d -> ", aux->info);
        aux = aux->prox;
    }
}

void TDList_reverse_print(TDList* list) {
    TNo* aux = list->fim;
    while (aux != NULL) {
        printf("%d -> ", aux->info);
        aux = aux->ant;
    }
}