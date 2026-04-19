#include <stdio.h>
#include "Stack.h"

void main() {
    Stack* stack = createStack();
    printf("Insira a palavra: ");
    readString(stack);

    printStack(stack);

    if (isPalindrome(stack))
        printf("É um palíndromo.\n");
    else
        printf("Não é um palíndromo.\n");
}