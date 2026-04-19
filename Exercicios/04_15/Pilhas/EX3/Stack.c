#include "Stack.h"
#include <stdlib.h>

typedef struct _no {
    char c;
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

bool stackPush(Stack* stack, char c) {
    if (!stackIsFull(stack)) {
        TNo* new = malloc(sizeof(TNo));
        if (!new) return false;
        new->c = c;
        new->prox = stack->info;
        stack->info = new;
        stack->qty++;
        return true;
    }
    return false;
}

bool stackPop(Stack* stack, char *c){
    if (!stackIsEmpty(stack)) {
        TNo* temp;
        if (!temp) return false;
        temp = stack->info;
        stack->info = stack->info->prox;
        *c = temp->c;
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

