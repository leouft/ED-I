#ifndef CONJ_H
#define CONJ_H
typedef struct _conj Conj;
/**
 * @param size quantidade de elementos do vetor
 * @param v vetor de inteiros
 * @return um ponteiro para um conjunto alocado dinamicamente
 */

Conj* Conj_create(int);
/**
 * Cria um conjunto vazio com capacidade para size elementos.
 * @param size quantidade de elementos do vetor
 */

void Conj_insert(Conj*, int);

void Conj_remove(Conj*, int);

#endif