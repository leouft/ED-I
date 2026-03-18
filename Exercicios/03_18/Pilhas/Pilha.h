#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>

typedef struct _pilha Pilha;

Pilha *pilha_create(int);

bool pilha_is_full(Pilha*);

void pilha_insert(Pilha*, int);

void pop(Pilha*);

int pilha_acess(Pilha*);

void pilha_destroy(Pilha*);

void pilha_info(Pilha *p);

#endif