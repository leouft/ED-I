#include "TLList.h"
#include <stdio.h>

int main(){
    TLList* lista1 = TLList_create();
    int V[] = {1, 2, 3, 4, 5}, i;
    for(i = 0; i<5; i++)
        if(!TLList_insert(lista1, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
    TLList_print(lista1);
    int maior;
    int position;
    TLList_maior(lista1, &maior, &position);
    printf("Maior: %d\n", maior);
    printf("Posição do maior: %d\n", position);
    return 0;
}