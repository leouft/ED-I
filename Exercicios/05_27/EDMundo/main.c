#include "TCList.h"
#include <stdio.h>

int main(){
    printf("Quantas pessoas tem? ");
    int N;
    scanf("%d", &N);

    printf("Número sorteado? ");
    int M;
    scanf("%d", &M);

    TCList* lista = TCList_create();
    for (int i = 0; i < N; i++) {
        TCList_insert(lista, i);
    }

    printf("Pessoa sorteada: %d\n",TCList_sorteio(lista, N, M));
    return 0;
}