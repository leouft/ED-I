#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>

typedef struct _queue Queue;

Queue* createQueue();

bool enqueue(Queue*, int);

bool dequeue(Queue*, int*);

bool queueAcess(Queue*, int*);

void queueDestroy(Queue*);

unsigned int queueQtd(Queue*);

bool queueIsEmpty(Queue*);

bool queueIsFull(Queue*);

bool queueHead(Queue*, int*);

bool queueTail(Queue*, int*);

#endif