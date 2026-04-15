#include "Queue.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct _no {
    int info;
    struct _no* prox;
} No;

struct _queue {
    int qty;
    No* tail;
    No* head;
};

Queue* createQueue() {
    Queue* novo = malloc(sizeof(*novo));
    if (!novo) return NULL;
    novo->qty = 0;
    novo->tail = NULL;
    novo->head = NULL;
    return novo;
}

bool enqueue(Queue* queue, int info) {
    if (!queueIsFull(queue)) {
        No* new = malloc(sizeof(new));

        new->info = info;
        if (queueIsEmpty(queue)) {
            new->prox = new;
            queue->head = new;
            queue->tail = new;
        } else {
            new->prox = queue->head;
            queue->tail->prox = new;
            queue->tail = new;
        }
        queue->qty++;
        return true;
    }
    return false; // nunca ocorre enquanto nao tiver limite definido btw
}

bool dequeue(Queue* queue, int *retorno) {
    if (!queueIsEmpty(queue)) {
        No* oldBegin = queue->head;
        *retorno = oldBegin->info;

        if (queue->head == queue->tail) {
            queue->head = NULL;
            queue->tail = NULL;
        }
        else {
            queue->head = oldBegin->prox;
            queue->tail->prox = queue->head;
        }

        free(oldBegin);
        queue->qty--;
        return true;
    }
    return false;
}

bool queueAcess(Queue* queue, int *retorno) {
    if (!queueIsEmpty(queue)) {
        int copia = queue->tail->prox->info;
        *retorno = copia;
        return true;
    }
    return false;
}

/* Destrói e some com essa bomba aí fr
void queueDestroy(Queue** queue) {
    int temp;
    while(dequeue(*queue, &temp));
    free(*queue);
    *queue = NULL;
}
*/

void queueDestroy(Queue* queue) {
    int temp;
    while(dequeue(queue, &temp));
    free(queue);
}

unsigned int queueQtd(Queue* queue) {
    return queue->qty;
}

bool queueIsEmpty(Queue* queue) {
    return queue->head == NULL;
}

bool queueIsFull(Queue* queue) {
    return false; // Nenhum limite maximo definido nesse exercicio.
}

bool queueTail(Queue* queue, int* tail) {
    if (!queueIsEmpty(queue)){
        int copia = queue->tail->info;
        *tail = copia;
        return true;
    }
    return false;
}

void queueInvert(Queue* queue) {
    Queue* auxiliar = createQueue();
    int tamanho = queueQtd(queue);
    int temp;

    for (int i = 0; i < tamanho ; i++) {
        for (int j = 0; j< tamanho - i - 1; j++) {
            dequeue(queue, &temp);
            enqueue(queue, temp); // dá uma volta na fila (basicamente 1, 2, 3 vira 3, 1, 2)
        }

        dequeue(queue, &temp); // tira dessa fila o primeiro elemento (antigo último elemento) e joga pra outra, então a fila volta para ordem original mas sem o antigo final.
        enqueue(auxiliar, temp);
    }

    while(!queueIsEmpty(auxiliar)) {
        dequeue(auxiliar, &temp); // agora vai tirar tudo da auxiliar e mandando de volta pra original
        enqueue(queue, temp);
    }

    free(auxiliar);
}