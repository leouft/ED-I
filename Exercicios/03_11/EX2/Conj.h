#ifndef CONJ_H
#define CONJ_H
typedef struct _conj Conj;
/**
 * @param size quantidade de elementos do vetor
 * @param v vetor de inteiros
 * @return um ponteiro para um conjunto alocado dinamicamente
 */

Conj* Conj_create();
/**
 * Cria um conjunto vazio com capacidade para size elementos.
 * @param size quantidade de elementos do vetor
 */

void Conj_insert(Conj*, int);

void Conj_remove(Conj*, int);

Conj* Conj_intersection(Conj*, Conj*);

Conj* Conj_difference(Conj*, Conj*);

Conj* Conj_union(Conj*, Conj*);

int Conj_maior(Conj*);

int Conj_menor(Conj*);

int Conj_equals(Conj*, Conj*);

int Conj_size(Conj*);

int Conj_null(Conj*);

#endif