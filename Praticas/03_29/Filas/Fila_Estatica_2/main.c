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
            scanf(" %c", &op);
            scanf("%d", &info);
            if (op == 'h' || op == 'H')
                if (enqueueHead(queue, info))
                    printf("\nElemento inserido no início.\n");
                else
                    printf("\nOverflow.\n");
            else if (op == 'T' || op == 't')
                if (enqueueEnd(queue, info))
                    printf("\nElemento inserido no final.\n");
                else
                    printf("\nOverflow.\n");
            break;
        case 'R':
        case 'r':
            if(dequeue(queue, &info))
                printf("\nElemento removido.\n");
            else
                printf("\nUnderflow.\n");
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
    } while (op != 's' && op != 'S' && op != 'd' && op != 'D');
}