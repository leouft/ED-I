#include "TGList.h"
#include <stdio.h>
#include <string.h>

void print_int(const void* info) {
    int* new = (int*)info;
    printf("%d -> ", *new);
}

void print_float(const void* info) {
    float* new = (float*)info;
    printf("%.2f -> ", *new);
}

void print_string(const void *info) {
    char* new = (char*)info;
    printf("%s ", new);
}

int cmp_float(const void* info, const void* info2) {
    float* pf1 = (float*)info;
    float* pf2 = (float*)info2;

    return (*pf1 > *pf2) ? -1 : (*pf1 < *pf2) ? 1 : 0;
}

int cmp_int(const void* info, const void* info2) {
    int* pf1 = (int*)info;
    int* pf2 = (int*)info2;

    return (*pf1 > *pf2) ? -1 : (*pf1 < *pf2) ? 1 : 0;
}

int cmp_str(const void* info, const void* info2) {
    char* pf1 = (char*) info;
    char* pf2 = (char*) info2;

    return strcmp(pf2, pf1); // Retorna -1 se a primeira é menor que a segunda, 1 se a primeira é maior, e 0 se são iguais (então precisa ter as strings ao contrário diferente das funções anteriores).
}

int main(){
    //Float
    TGList* lista_floats = TGList_create(ORDENADA, print_float, sizeof(float), cmp_float);

    float V[] = {4.3, 1.2, 3.45, 6.678, 5.7778};
    for(int i = 0; i<5; i++){
        if(!TGList_insert(lista_floats, &V[i]))
            printf("Ocorreu um erro ao inserir o V[%i]=%f\n", i, V[i]);
    }
    puts("Lista de floats ordenados");
    TGList_print(lista_floats);

    //Int
    TGList* lista_ints = TGList_create(ORDENADA, print_int, sizeof(int), cmp_int);
    int V2[] = {8, 2, 3, 9, 1};
    for(int i = 0; i < 5; i++) {
        if (!TGList_insert(lista_ints, &V2[i]))
            printf("Ocorreu um erro ao inserir o V2[%i]=%d\n", i, V2[i]);
    }
    puts("Lista de ints ordenados");
    TGList_print(lista_ints);

    //String
    TGList* lista_strings = TGList_create(ORDENADA, print_string, 64, cmp_str);
    char V3[][64] = {"Moo", "Ray", "Léo", "Meel"};
    for(int i = 0; i < 4; i++) {
        if(!TGList_insert(lista_strings, &V3[i]))
            printf("Ocorreu um erro ao inserir o V3[%i]=%s\n", i, V3[i]);
    }
    puts("Lista de strings ordenados");
    TGList_print(lista_strings);

    return 0;
}