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
/**
 * Insere um elemento no conjunto.
 * @param c ponteiro para o conjunto
 * @param x elemento a ser inserido
 */

void Conj_remove(Conj*, int);
/**
 * Remove um elemento do conjunto.
 * @param c ponteiro para o conjunto
 * @param x elemento a ser removido
 */

Conj* Conj_intersection(Conj*, Conj*);
/**
 * Retorna um novo conjunto que é a interseção dos conjuntos c1 e c2.
 * @param c1 ponteiro para o primeiro conjunto
 * @param c2 ponteiro para o segundo conjunto
 * @return um ponteiro para o conjunto interseção
 */
Conj* Conj_difference(Conj*, Conj*);
/**
 * Retorna um novo conjunto que é a diferença dos conjuntos c1 e c2 (c1 - c2).
 * @param c1 ponteiro para o primeiro conjunto
 * @param c2 ponteiro para o segundo conjunto
 * @return um ponteiro para o conjunto diferença
 */

Conj* Conj_union(Conj*, Conj*);
/**
 * Retorna um novo conjunto que é a união dos conjuntos c1 e c2.
 * @param c1 ponteiro para o primeiro conjunto
 * @param c2 ponteiro para o segundo conjunto
 * @return um ponteiro para o conjunto união
 */

int Conj_maior(Conj*);
/**
 * Retorna o maior elemento do conjunto.
 * @param c ponteiro para o conjunto
 * @return o maior elemento do conjunto ou -1 se o conjunto estiver vazio
 */

int Conj_menor(Conj*);
/**
 * Retorna o menor elemento do conjunto.
 * @param c ponteiro para o conjunto
 * @return o menor elemento do conjunto ou -1 se o conjunto estiver vazio
 */

int Conj_equals(Conj*, Conj*);
/**
 * Verifica se dois conjuntos são iguais.
 * @param c1 ponteiro para o primeiro conjunto
 * @param c2 ponteiro para o segundo conjunto
 * @return 1 se os conjuntos forem iguais, 0 caso contrário
 */

int Conj_size(Conj*);
/**
 * Retorna o número de elementos do conjunto.
 * @param c ponteiro para o conjunto
 * @return o número de elementos do conjunto
 */

int Conj_null(Conj*);
/**
 * Verifica se o conjunto é vazio.
 * @param c ponteiro para o conjunto
 * @return 1 se o conjunto for vazio, 0 caso contrário
 */

#endif