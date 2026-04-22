#include "Stack.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct _no
{
    int value;
    struct _no *prox;
} TNo;

struct _stack
{
    unsigned int qty;
    TNo *info;
};

Stack *createStack()
{
    Stack *new = malloc(sizeof(Stack));
    if (!new)
        return NULL;
    new->qty = 0;
    new->info = NULL;
    return new;
}

bool stackPush(Stack *stack, int x)
{
    if (!stackIsFull(stack))
    {
        TNo *new = malloc(sizeof(TNo));
        if (!new)
            return false;
        new->value = x;
        new->prox = stack->info;
        stack->info = new;
        stack->qty++;
        return true;
    }
    return false;
}

bool stackPop(Stack *stack, int *x)
{
    if (!stackIsEmpty(stack))
    {
        TNo *temp = stack->info;
        *x = temp->value;
        stack->info = temp->prox;
        stack->qty--;
        free(temp);
        return true;
    }
    return false;
}

bool stackIsEmpty(Stack *stack)
{
    return stack->info == NULL;
}

bool stackIsFull(Stack *stack)
{
    return false;
}

bool stacksAreEquals(Stack *stack1, Stack *stack2)
{
    if (stack1->qty == stack2->qty)
    {
        bool flag = false;
        int v1[stack1->qty], v2[stack2->qty];
        int i = 0;
        while (stackPop(stack1, &v1[i]))
            i++;
        i = 0;
        while (stackPop(stack2, &v2[i]))
            i++;
        for (int j = 0; j < i; j++)
        {
            if (v1[j] != v2[j])
            {
                flag = true;
                break;
            }
        }
        for (int k = i; k > 0; k--)
        {
            stackPush(stack1, v1[k - 1]);
            stackPush(stack2, v2[k - 1]);
        }
        return !flag;
    }
    return false;
}