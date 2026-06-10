#include "TGList.h"
#include <stdio.h>

void print_int(void* info) {
    int* new = (int*)info;
    printf("%d -> ", *new);
}

void print_float(void* info) {
    float* new = (float*)info;
    printf("%.2f -> ", *new);
}

void print_string(void *info) {
    char* new = (char*)info;
    printf("%s ", new);
}

int main(){
    //A lista1 só insere no início
    TGList* lista1 = TGList_create(NO_INICIO, print_int, sizeof(int));
    //A lista2 só insere no fim
    TGList* lista2 = TGList_create(NO_FIM, print_int, sizeof(int));
    //A lista3 só insere no fim
    TGList* lista3 = TGList_create(NO_FIM, print_float, sizeof(float));
    
    int V[] = {1, 2, 3, 4, 5}, i;
    float V2[] = {1.23, 4.34, 6.32, 7.32, 8.94};
    
    for(i = 0; i<5; i++){
        if(!TGList_insert(lista1, &V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
        if(!TGList_insert(lista2, &V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%i\n", i, V[i]);
        if (!TGList_insert(lista3, &V2[i]))
            printf("Ocorreu um erro ao inserir o V2[%i]=%.2f\n", i, V2[i]);
    
    }

    //A lista4 só insere no fim
    char strings[3][64] = {"ED-I", "É MUITO", "DOIDO"};
    TGList* lista4 = TGList_create(NO_FIM, print_string, sizeof(char)*64);
    
    for (i = 0; i < 3; i++) {
        if (!TGList_insert(lista4, &strings[i]))
            printf("Ocorreu um erro ao inserir o V2[%i]=%s\n", i, strings[i]);
    }

    puts("Lista 1 (politica de insercao no inicio):");
    TGList_print(lista1);
    puts("Lista 2 (politica de insercao no fim):");
    TGList_print(lista2);
    puts("Lista 3 (politica de insercao no fim) com elementos float:");
    TGList_print(lista3);
    puts("Lista 4 (politica de insercao no fim) com elementos string:");
    TGList_print(lista4);
    return 0;
}