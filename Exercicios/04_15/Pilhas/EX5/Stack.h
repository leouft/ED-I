#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct _stack Stack;

Stack* createStack();

bool stackPush(Stack*, int);

bool stackPop(Stack*, int*);

bool stackIsEmpty(Stack*);

bool stackIsFull(Stack*);   

bool stacksAreEquals(Stack*, Stack*);

#endif