#include "TCList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

TCList* TCList_create(){
    TCList* nova = malloc(sizeof(TCList));
    if(nova != NULL){
        nova->inicio = NULL;
    }
    return nova;
}
//TODO: Modifique as funções para funcionar como uma lista circular
/**
 * Política de inserção no fim da lista;
 * @return true|false caso não possa inserir na lista
 */
bool TCList_insert(TCList* lista, int info){
    //Inicializando um TNo novo para a nova informação
    TNo* novo = TNo_createNFill(info);
    if(novo == NULL) 
        return false; 
    if (lista->inicio == NULL)
        lista->inicio = novo;
    else {
        TNo* aux = lista->inicio;
        while (aux->prox != lista->inicio)
            aux = aux->prox;
        aux->prox = novo;
    }
    novo->prox = lista->inicio;
    return true;
}
//TODO: Modifique as funções para funcionar como uma lista circular
/**
 * Imprime a lista do início para o fim.
 */
void TCList_print(TCList* lista){
    TNo* aux = lista->inicio;
    if (aux != NULL)
        do {
            printf("%d->", aux->info);
            aux = aux->prox;
        } while(aux!=lista->inicio);
    putchar('\n');
}

int TCList_sorteio(int N, int M) {
    TCList* lista = TCList_create();

    // Insere os N elementos (ou seja, as pessoas)
    for (int i = 0; i < N; i++) {
        TCList_insert(lista, i);
    }
    TNo* aux = lista->inicio;
    while (lista->inicio->prox != lista->inicio) {
        // Percorrer até a pessoa anterior a que será removida
        for (int i = 0; i < M-1; i++) {
            aux = aux->prox;
        }
        TNo* temp = aux->prox;
        if (temp == lista->inicio)
            lista->inicio = temp->prox;
        aux->prox = aux->prox->prox; // O elemento atual irá apontar pro elemento logo após o que será removido
        aux = aux->prox;
        free (temp);
    }

    int vencedor = lista->inicio->info+1;

    free(lista->inicio);
    free(lista);

    return (vencedor);
}