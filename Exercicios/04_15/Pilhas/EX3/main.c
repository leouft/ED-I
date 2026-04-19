#include "Stack.h"
#include <stdio.h>
#include <string.h>

void main() {
    Stack* stack = createStack();

    printf("\nInsira a entrada: \n");

    char info[128];
    char temp;
    bool flag = false;

    scanf("%[^\n]s", info);

    for(int i = 0; i < strlen(info); i++) {
        if(info[i] == '(') {
            stackPush(stack, info[i]);
        }
        else if(info[i] == ')') {
            if(!stackPop(stack, &temp)) {
                flag = true;
                break;
            }
        }
    }

    if (flag == true || !stackIsEmpty(stack))
        printf("\nIncorreto.\n");
    else if (stackIsEmpty(stack))
        printf("\nCorreto.\n");
}