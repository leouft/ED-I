#include "Stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _stack {
    unsigned int qty;
    char letras[128];
};

Stack* createStack() {
    Stack* new = malloc(sizeof(Stack));
    if (!new) return NULL;
    new->qty = 0;
    return new;
}

bool stackPush(Stack* stack, char c) {
    if(!stackIsFull(stack)) {
        stack->letras[stack->qty] = c;
        stack->qty++;
        return true;
    }
    return false;
}

bool stackPop(Stack* stack, char* c) {
    if(!stackIsEmpty(stack)) {
        *c = stack->letras[stack->qty-1];
        stack->qty--;
        return true;
    }
    return false;
}

bool stackIsFull(Stack* stack) {
    return stack->qty >= 128;
}

bool stackIsEmpty(Stack* stack) {
    return stack->qty == 0;
}

void readString(Stack* stack) {
    char string[128];
    scanf(" %s", string);
    for (int i = 0; i < strlen(string); i++) {
        stackPush(stack, string[i]);
    }
}

void printStack(Stack* stack){
    printf("%s\n", stack->letras);
}

bool isPalindrome(Stack* stack) {
    char temp[128];
    char aux[128];

    strcpy(temp, stack->letras);

    int i = 0;
    while(stackPop(stack, &aux[i])){
        i++;
    }
    aux[i] = '\0';

    for (int j = 0; j < strlen(temp); j++) {
        stackPush(stack, temp[j]);
    }
    return strcmp(temp, aux) == 0;
}