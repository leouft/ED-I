#include "TLList.h"
#include<stdio.h>
#include <stdlib.h>

//estrutura auxiliar para as ligações dos nós
typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
};
//Funcao auxiliar para preencher um nó
TNo* TNo_createNFill(int info){
    TNo* novo = malloc(sizeof(TNo));
    if(novo != NULL)
    {
        novo->prox = NULL;
        novo->info = info;
    }
    return novo;
}

TLList* TLList_create(){
    TLList* nova = malloc(sizeof(TLList));
    if(nova != NULL){
        nova->inicio = NULL;
    }
    return nova;
}
/**
 * Política de inserção no início da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TLList_insert(TLList* lista, int info){
    //Inicializando um TNo novo para a nova informação
    TNo* novo = TNo_createNFill(info);
    if(novo == NULL) 
        return false; 
    TNo** aux = &(lista->inicio);
    while(*aux!=NULL)
        aux = &(*aux)->prox;
    *aux = novo;
    return true;
}
/**
 * Imprime a lista do início para o fim.
 */
void TLList_print(TLList* lista){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        printf("%d->", aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}

TLList* TLListConca(TLList* list1, TLList* list2) {
    // Criando a nova lista:
    TLList* list3 = malloc(sizeof(TLList));
    if (!list1) return NULL;
    list3->inicio = NULL;

    // Inserindo a primeira lista:
    TNo* aux = list1->inicio;
    while(aux != NULL) {
        // Criando o novo nó:
        TNo* novo = malloc(sizeof(TNo));
        if (!novo) return NULL;
        novo->info = aux->info;
        novo->prox = NULL;

        // Inserindo na nova lista:
        TNo** aux2 = &(list3->inicio);
        while (*aux2 != NULL)
            aux2 = &((*aux2)->prox);
        *aux2 = novo;

        aux = aux->prox;
    }
    // Inserindo segunda lista:
    aux = list2->inicio;
    while(aux != NULL) {
        // Criando o novo nó:
        TNo* novo = malloc(sizeof(TNo));
        if (!novo) return NULL;
        novo->info = aux->info;
        novo->prox = NULL;

        // Inserindo na nova lista:
        TNo** aux2 = &(list3->inicio);
        while (*aux2 != NULL)
            aux2 = &((*aux2)->prox);
        *aux2 = novo;
        
        aux = aux->prox;  
    }
    return list3;
}