#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>

typedef struct _pilha Pilha;

Pilha *pilha_create(int);

bool pilha_is_full(Pilha*);

bool pilha_is_empty(Pilha*);

bool pilha_insert(Pilha*, int);

bool pop(Pilha*);

bool pilha_acess(Pilha*, int*);

unsigned int pilha_len(Pilha*);

void pilha_destroy(Pilha*);

void pilha_info(Pilha*);

#endif