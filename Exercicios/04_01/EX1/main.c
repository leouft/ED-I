#include "Queue.h"
#include <stdio.h>

void main()
{
    Queue *queue = createQueue();
    printf("\nFila criada.\n");
    int info1, info2;

    printf("\n");
    int vetor[] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        enqueue(queue, vetor[i]);
    }

    queueAcess(queue, &info1);
    queueTail(queue, &info2);

    printf("\nHead: %d\nTail: %d\n", info1, info2);

    queueInvert(queue);

    queueAcess(queue, &info1);
    queueTail(queue, &info2);

    printf("\nInvertidos:\nHead: %d\nTail: %d\n", info1, info2);
}