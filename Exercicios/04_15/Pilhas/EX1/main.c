#include <stdio.h>
#include "Stack.h"
#include <string.h>

void main() {
    char frase[256];

    printf("Insira a frase: ");
    scanf(" %[^\n]s", frase);
    printf("\nFrase original: %s\n", frase);

    fraseInvert(frase);

    printf("\nFrase com palavras invertidas: %s\n", frase);
}