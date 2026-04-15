#include "Queue.h"
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct _no {
    int info;
    struct _no *prox;
} No;

struct _queue {
    int qty;
    No* head;
    No* tail;
};

Queue* createQueue() {
    Queue* novo = malloc(sizeof(Queue));
    if (!novo) return NULL;
    novo->qty = 0;
    novo->head = NULL;
    novo->tail = NULL;
    return novo;
}

bool enqueue(Queue* queue, int info) {
    if (!queueIsFull(queue)) {
        No* new = malloc(sizeof(No));
        if (!new) return false;

        new->info = info;
        new->prox = NULL;

        if (queue->head == NULL) {
            queue->head = new;
            queue->tail = new;

        } else {
            queue->tail->prox = new;
            queue->tail = new;
        }
        queue->qty++;
        return true;
    }
    return false;
}

bool dequeue(Queue* queue, int* retorno) {
    if (!queueIsEmpty(queue)) {
        No* temp = queue->head;
        queue->head = queue->head->prox;
        queue->qty--;
        *retorno = temp->info;
        free(temp);
        return true;
    }
    return false;
}

bool queueAcess(Queue* queue, int *retorno) {
    if (!queueIsEmpty(queue)) {
        *retorno = queue->head->info;
        return true;
    }
    return false;
}

void queueDestroy(Queue* queue) {
    int temp;
    while(dequeue(queue, &temp));
    free(queue);
}

unsigned int queueQtd(Queue* queue) {
    return queue->qty;
}

bool queueIsEmpty(Queue* queue) {
    if (queue->head == NULL)
        return true;
    return false;
}

bool queueIsFull(Queue* queue) {
    if (queue->qty == MAX)
        return true;
    return false;
}

// Faz a mesma coisa que o queueAcess()
/*
bool queueHead(Queue* queue, int* head) {
    if (!queueIsEmpty(queue)){
        *head = queue->head->info;
        return true;
    }
    return false;
}
*/

bool queueTail(Queue* queue, int* tail) {
    if (!queueIsEmpty(queue)){
        *tail = queue->tail->info;
        return true;
    }
    return false;
}