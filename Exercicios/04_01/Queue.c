#include "Queue.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 10

struct _queue {
    int qty;
    int info[MAX];
};

Queue* createQueue() {
    Queue* novo = malloc(sizeof(Queue));
    if (!novo) return NULL;
    novo->qty = 0;
    return novo;
}

bool enqueue(Queue* queue, int info) {
    if (!queueIsFull(queue)) {
        queue->info[queue->qty] = info;
        queue->qty++;
        return true;
    }
    printf("\nOverflow.\n");
    return false;
}

bool dequeue(Queue* queue, int *retorno) {
    if (!queueIsEmpty(queue)) {
        int copia = queue->info[0];
        *retorno = copia;
        queue->qty--;
        for(int i = 0; i < queue->qty; i++) {
            queue->info[i] = queue->info[i+1];
        }
        return true;
    }
    printf("\nUnderflow.\n");
    return false;
}

bool queueAcess(Queue* queue, int *retorno) {
    if (!queueIsEmpty(queue)) {
        int copia = queue->info[0];
        *retorno = copia;
        return true;
    }
    return false;
}

void queueDestroy(Queue* queue) {
    free(queue);
}

int queueQtd(Queue* queue) {
    return queue->qty;
}

bool queueIsEmpty(Queue* queue) {
    return queue->qty == 0;
}

bool queueIsFull(Queue* queue) {
    return queue->qty == MAX;
}

// Faz a mesma coisa que o queueAcess()
/*
bool queueHead(Queue* queue, int* head) {
    if (!queueIsEmpty(queue)){
        int copia = queue->info[0];
        *head = copia;
        return true;
    }
    return false;
}
*/

bool queueTail(Queue* queue, int* tail) {
    if (!queueIsEmpty(queue)){
        int copia = queue->info[queue->qty-1];
        *tail = copia;
        return true;
    }
    return false;
}