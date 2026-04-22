#include "Stack.h"
#include <stdio.h>

void main() {
    Stack* P1 = createStack();
    Stack* P2 = createStack();
    int v1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < sizeof(v1)/sizeof(v1[0]); i++){
        stackPush(P1, v1[i]);
    }

    int v2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < sizeof(v2)/sizeof(v2[0]); i++){
        stackPush(P2, v2[i]);
    }

    if (stacksAreEquals(P1, P2))
        printf("\nAs duas pilhas são iguais\n");
    else
        printf("\nAs duas pilhas são diferentes\n");
}