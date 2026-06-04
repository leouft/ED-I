#ifndef TDLIST_H
#define TDLIST_H
#include <stdbool.h>
/**
TAD Lista Duplamente Encadeada.
Deve ter o ponteiro inicio e fim
*/
typedef struct _list TDList;
/**
 * Cria instâncias da TDList;
 */
TDList* TDList_create();
/**
 * Política de inserção no início da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TDList_insert_begin(TDList*, int);

/**
 * Política de inserção no fim da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TDList_insert_end(TDList*, int);

/**
 * Imprime a lista do início para o fim.
 */
void TDList_print(TDList*);
/**
 * Imprime a lista do fim para o início.
 */
void TDList_reverse_print(TDList*);

/**
 * Remove o elemento final da lista.
 * @param TDList* Lista com o elemento que será removido.
 * @param int* Ponteiro de quem receberá o elemento removido.
 */
bool TDList_remove_end(TDList*, int*);

/**
 * Remove o elemento inicial da lista.
 * @param TDList* Lista com o elemento que será removido.
 * @param int* Ponteiro de quem receberá o elemento removido.
 */
bool TDList_remove_begin(TDList*, int*);

#endif