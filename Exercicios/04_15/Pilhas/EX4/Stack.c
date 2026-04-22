#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct _no {
    int v;
    struct _no* prox;
} TNo;

struct _stack {
    unsigned int qty;
    TNo* info;
};

Stack* createStack() {
    Stack* new = malloc(sizeof(Stack));
    if (!new) return NULL;
    new->qty = 0;
    new->info = NULL;
}

bool stackPush(Stack* stack, int v) {
    if (!stackIsFull(stack)) {
        TNo* new = malloc(sizeof(TNo));
        if (!new) return false;
        new->v = v;
        new->prox = stack->info;
        stack->info = new;
        stack->qty++;
        return true;
    }
    return false;
}

bool stackPop(Stack* stack, int *v){
    if (!stackIsEmpty(stack)) {
        TNo* temp;
        temp = stack->info;
        stack->info = stack->info->prox;
        *v = temp->v;
        free(temp);
        stack->qty--;
        return true;
    }
    return false;
}

bool stackIsEmpty(Stack* stack) {
    return stack->info == NULL;   
}

bool stackIsFull(Stack* stack) {
    return false;
}

void invertStack(Stack* stack) {
    int temp[stack->qty];

    int i = 0;
    while(stackPop(stack, &temp[i]))
        i++;

    for (int j = 0; j < sizeof(temp)/sizeof(temp[0]); j++)
        stackPush(stack, temp[j]);

}

void printStack(Stack* stack) {
    if (!stackIsEmpty(stack)) {
        printf("\nPilha do topo para o início:\n");
        TNo* atual = stack->info;
        while (atual != NULL) {
            printf("[%d]\n", atual->v);
            atual = atual->prox;
        }
    }
}