#include "TDList.h"
#include <stdio.h>

int main(){
    TDList* lista1 = TDList_create();
    TDList* lista2 = TDList_create();
    char num1[4096], num2[4096];
    printf("Insira o primeiro número: ");
    scanf("%s", num1);
    printf("Insira o segundo número: ");
    scanf("%s", num2);

    int i = 0;
    while (num1[i] != '\0') { // Insere os elementos na lista como inteiro
        TDList_insert_end(lista1, num1[i]-'0');
        i++;
    }

    i = 0;
    while (num2[i] != '\0') { // Insere os elementos na lista como inteiro
        TDList_insert_end(lista2, num2[i]-'0');
        i++;
    }

    TDList* bigInt = TDList_sum_big_int(lista1, lista2);
    TDList_print(bigInt);
    printf("\n");

    return 0;
}