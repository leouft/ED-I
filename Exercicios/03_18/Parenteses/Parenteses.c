#include "Parenteses.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct _stack
{
    int *x;
    int index;
    int tamanho;
};

Stack* stack_create(int x)
{
    Stack *s = malloc(sizeof(Stack));
    s->x = malloc(x*(sizeof(int)));
    s->index = -1;
    s->tamanho = x;
}

void vef_stack(Stack* s, int x)
{
    for (int i = 0; i < x-1; i++)
    {
        
    }
}

bool stack_is_full(Stack* s)
{
    return (s->index == s->tamanho);
}