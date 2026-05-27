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

    printf("Pessoa sorteada: %d\n",TCList_sorteio(lista, N, M));
    return 0;
}