#include "Queue.h"
#include <stdio.h>

void main()
{
    Queue *queue = createQueue();
    printf("\nFila criada.\n");
    int info;
    char op;
    do
    {
        printf("\n");
        scanf(" %c", &op);
        switch (op)
        {
        case 'I':
        case 'i':
            scanf("%d", &info);
            enqueue(queue, info);
            break;
        case 'R':
        case 'r':
            dequeue(queue, &info);
            break;
        case 'A':
        case 'a':
            if(queueAcess(queue, &info)) {
                printf("\nPrimeiro da fila: %d\n", info);
                break;
            }
            printf("\nFila vazia.\n");
            break;
        case 'D':
        case 'd':
            queueDestroy(queue);
            printf("\nFila destruída.\n");
            break;

        /* Mesma coisa do case A
        case 'h':
        case 'H':
            if(queueHead(queue, &info)) {
                printf("\nPrimeiro da fila: %d\n", info);
                break;
            }
            printf("\nFila vazia.\n");
            break;
        */

        case 'T':
        case 't':
            if(queueTail(queue, &info)) {
                printf("\nÚltimo da fila: %d\n", info);
                break;
            }
            printf("\nFila vazia.\n");
            break;
        case 'Q':
        case 'q':
            printf("\nQuantidades de elementos na fila: %d\n", queueQtd(queue));
            break;
        }
    } while (op != 's' && op != 'S');
}