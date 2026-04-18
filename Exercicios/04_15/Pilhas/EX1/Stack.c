#include "Stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

struct _stack {
    int size;
    int qty;
    char *letras;
};

Stack* createStack() {
    Stack* new = malloc(sizeof(Stack));
    if (!new) return NULL;
    new->qty = 0;
    new->size = 1;
    new->letras = malloc(sizeof(char));
}

bool stackPush(Stack* stack, char c) {
    if (stack->qty == stack->size) {
        stack->size++;
        stack->letras = realloc(stack->letras, stack->size*sizeof(char));
    }
    stack->letras[stack->qty] = c;
    stack->qty++;
    return true;
}

bool stackPop(Stack* stack, char* retorno) {
    if (!stackIsEmpty(stack)) {
        *retorno = stack->letras[stack->qty-1];;
        stack->qty--;
        stack->size--;
        stack->letras = realloc(stack->letras, stack->size*sizeof(char));
        return true;
    }
    return false;
}

bool stackIsEmpty(Stack* stack) {
    if (stack->qty == 0) {
        return true;
    }
    return false;
}

void fraseInvert(char* frase) {
    Stack* stack = createStack();

    char temp[256];

    int i = 0;
    int k = 0;
    
    while(frase[i] != '\0') {
        while(frase[i] != ' ' && frase[i] != '.' && frase[i] !='\0') {
            stackPush(stack, frase[i]);
            i++;
        }
        int start = k;

        while (!stackIsEmpty(stack)) {
            stackPop(stack, &temp[k]);
            k++;
        }

        if (frase[i] == ' ') {
            temp[k++] = ' ';
        }
        else if (frase[i] == '.') {
            temp[k] = '.';
            k++;
            temp[k] = '\0';
            break; 
        }
        i++;
    }

    for (int x = 0; x < k; x++){
        frase[x] = temp[x];
    }   
}