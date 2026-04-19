#include "Stack.h"
#include <stdio.h>

void main() {
    Stack* P = createStack();

    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++){
        stackPush(P, v[i]);
    }

    printStack(P);

    invertStack(P);

    printStack(P);
}