#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>

typedef struct _pilha Pilha;

Pilha *pilha_create();

bool pilha_push(Pilha*, int);

bool pilha_pop(Pilha*, int*);

bool pilha_acess(Pilha*, int*);

unsigned int pilha_size(Pilha*);

void pilha_destroy(Pilha*);

void pilha_destroy_sem_pop(Pilha*);

void pilha_destroy_recursivo(Pilha*);

bool pilha_is_empty(Pilha*);

bool pilha_is_full(Pilha*);

#endif