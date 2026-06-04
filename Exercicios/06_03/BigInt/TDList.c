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

TNo* TNo_createNFill(int value) {
    TNo* new = malloc(sizeof(TNo));
    if (!new) return NULL;
    new->ant = NULL;
    new->prox = NULL;
    new->info = value;
    return new;
}

bool TDList_insert_begin(TDList* list, int value) {
    TNo* new = TNo_createNFill(value);
    if (!new) return false;
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
    TNo* new = TNo_createNFill(value);
    if (!new) return false;
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
        printf("%d", aux->info);
        aux = aux->prox;
    }
}

void TDList_reverse_print(TDList* list) {
    TNo* aux = list->fim;
    while (aux != NULL) {
        printf("%d", aux->info);
        aux = aux->ant;
    }
}

bool TDList_remove_end(TDList* list, int* info) {
    if (list->inicio != NULL) {
        TNo* temp = list->fim;
        temp->ant->prox = NULL;
        list->fim = temp->ant;
        *info = temp->info;
        free(temp);
        return true;
    }
    return false;
}

bool TDList_remove_begin(TDList* list, int* info) {
    if (list->inicio != NULL) {
        TNo* temp = list->inicio;
        list->inicio = temp->prox;
        list->inicio->ant = NULL;
        *info = temp->info;
        free(temp);
        return true;
    }
    return false;
}

TDList* TDList_sum_big_int(TDList* list, TDList* list2) {
    TDList* new = TDList_create();
    TNo* aux = list->fim;
    TNo* aux2 = list2->fim;
    int queue = 0;
    while (aux != NULL && aux2 != NULL) { // Insere todas as somas até uma das listas acabar
        int sum = aux->info+aux2->info+queue;
        if (sum >= 10) {
            queue = 1;
            sum = sum % 10;
        }
        else
            queue = 0;
        TDList_insert_begin(new, sum);
        aux = aux->ant;
        aux2 = aux2->ant;
    }
    
    TNo* remaining;
    if (aux != NULL) // Procura se alguma das listas tem números restantes
        remaining = aux;
    else if (aux2 != NULL)
        remaining = aux2;
    else
        remaining = NULL;

    while (remaining != NULL) { // Insere os elementos restantes
        int sum = remaining->info+queue;
        if (sum >= 10) {
            queue = 1;
            sum = sum % 10;
        }
        else
            queue = 0;
        TDList_insert_begin(new, sum);
        remaining = remaining->ant;
    }

    if (queue)
        TDList_insert_begin(new, 1);

    return new;
}