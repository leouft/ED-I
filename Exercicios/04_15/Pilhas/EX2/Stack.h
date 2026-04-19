#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct _stack Stack;

Stack* createStack();

bool stackPush(Stack*, char);

bool stackPop(Stack*, char*);

bool stackIsFull(Stack*);

bool stackIsEmpty(Stack*);

void readString(Stack*);

void printStack(Stack* stack);

bool isPalindrome(Stack*);

#endif