#include "TLList.h"
#include <stdio.h>

int main(){
    TLList* lista1 = createList();
    int V[] = {1, 2, 3, 4, 5}, i;
    for(i = 0; i<5; i++)
        if(!TLListInsertBegin(lista1, V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
    int V2[] = {6, 7, 8, 9, 10};
    for(i = 0; i<5; i++)
        if(!TLListInsertEnd(lista1, V2[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V2[i]);
    TLListPrint(lista1);
    return 0;
}