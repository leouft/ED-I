#ifndef TLLIST_H
#define TLLIST_H
#include <stdbool.h>

typedef struct _list TLList;
/**
 * Cria instâncias da TLList;
 */
TLList* createList();
/**
 * Política de inserção no início da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TLListInsertBegin(TLList*, int);
/**
 * Política de inserção no fim da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TLListInsertEnd(TLList*, int);
/**
 * Imprime a lista do início para o fim.
 */
void TLListPrint(TLList*);

#endif