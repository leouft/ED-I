#include "TGList.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura auxiliar para as ligações dos nós
typedef struct _no{
    void* info;
    struct _no *prox;
}TNo;

struct _list{
    TNo* inicio;
    char policy;//Política de inserção
    void (*ptr_func)(void*);
    size_t info_size;
};


//Funcao auxiliar para preencher um nó
TNo* TNo_createNFill(void* info, size_t info_size){
    TNo* new = malloc(sizeof(TNo));
    if (!new) return NULL;
    new->prox = NULL;

    new->info = malloc(info_size);

    if (!new->info) {
        free(new->info);
        return NULL;
    }

    memcpy(new->info, info, info_size);

    return new;
}
//Headers das funções
bool TGList_insert_begin(TGList* lista, void* info);
bool TGList_insert_end(TGList* lista, void* info);

TGList* TGList_create(char policy, void (*ptr_func)(void*), size_t info_size){
    //if(policy) posso testar se os valores estão de acordo...
    TGList* nova = malloc(sizeof(TGList));
    if(nova != NULL){
        nova->inicio = NULL;
        nova->policy = policy;
        nova->ptr_func = ptr_func;
        nova->info_size = info_size;
    }
    return nova;
}
bool TGList_insert(TGList* lista, void* info){
    switch(lista->policy){
        case NO_INICIO: return TGList_insert_begin(lista, info);
        case NO_FIM: return TGList_insert_end(lista, info);
    }
    return false;
}
/**
 * Política de inserção no início da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TGList_insert_begin(TGList* lista, void* info){
    //Inicializando um TNo novo para a nova informação
    TNo* novo = TNo_createNFill(info, lista->info_size);
    //Se for NULL, nao conseguimos memória
    if(novo == NULL) 
        return false; 
    //Fazendo a ligação do novo no com o inicio da lista (se for null, o prox sera null, apenas nesta ocasiao)
    novo->prox = lista->inicio;	
    //Atualizando o inicio para o novo nó recém inserido
    lista->inicio = novo;
    return true;
}
bool TGList_insert_end(TGList* lista, void* info){
    TNo* novo = TNo_createNFill(info, lista->info_size);
    //Se for NULL, nao conseguimos memória
    if(novo == NULL) 
        return false; 
    if(lista->inicio == NULL)
        lista->inicio = novo;
    else{//a lista nao estah vazia
        TNo* aux = lista->inicio;
        while(aux->prox != NULL)
            aux = aux->prox;
        //Aux é o ultimo elemento da lista
        aux->prox = novo;
    }
    return true;
}
/**
 * Imprime a lista do início para o fim.
 */
void TGList_print(TGList* lista){
    TNo* aux = lista->inicio;
    while(aux!=NULL){
        lista->ptr_func(aux->info);
        aux = aux->prox;
    }
    putchar('\n');
}