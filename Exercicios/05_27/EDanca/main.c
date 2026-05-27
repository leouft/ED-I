#include "TCList.h"
#include <stdio.h>

int main(){
    printf("Quantas cadeiras tem? ");
    int N;
    scanf("%d", &N);

    printf("Número de opções do EDeejay? ");
    int M;
    scanf("%d", &M);

    TCList* lista = TCList_create();
    for (int i = 0; i < N; i++) {
        TCList_insert(lista, i);
    }
    TCList* lista2 = TCList_create();
    for (int i = 0; i < M; i++) {
        int op;
        printf("Opção %d: ", i+1);
        scanf("%d", &op);
        TCList_insert(lista2, op);
    }

    printf("Campeão: %d\n",TCList_danca(lista, lista2));
    return 0;
}