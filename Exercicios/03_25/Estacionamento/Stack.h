#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct _pilha Pilha;

Pilha* stackCreate();

bool stackPush(Pilha*, int);

bool stackPop(Pilha*, Pilha*, int*, int);

void stackVer(Pilha*);

void stackRetornar(Pilha*, Pilha*);

#endif