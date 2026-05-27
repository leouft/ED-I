#include "TCList.h"
#include <stdio.h>

int main(){
    printf("Quantas pessoas tem? ");
    int N;
    scanf("%d", &N);

    printf("Número sorteado? ");
    int M;
    scanf("%d", &M);

    printf("Pessoa sorteada: %d\n",TCList_sorteio(N, M));
    return 0;
}