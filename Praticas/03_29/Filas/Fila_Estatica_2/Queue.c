#include "Queue.h"
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

struct _queue {
    int qty;
    int info[MAX];
};

Queue* createQueue() {
    Queue* novo = malloc(sizeof(*novo));
    if (!novo) return NULL;
    novo->qty = 0;
    return novo;
}

bool enqueueEnd(Queue* queue, int info) {
    if (!queueIsFull(queue) && queue != NULL) {
        queue->info[queue->qty] = info;
        queue->qty++;
        return true;
    }
    return false;
}

bool enqueueHead(Queue* queue, int info) {
    if (!queueIsFull(queue) && queue != NULL) {
        for(int i = queue->qty; i > 0; i--) {
            queue->info[i] = queue->info[i-1];
        }
        queue->info[0] = info;
        queue->qty++;
        return true;
    }
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

unsigned int queueQtd(Queue* queue) {
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