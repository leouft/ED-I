#include "Conj.h"
#include <stdlib.h>

struct _conj {
    int size;
    int* v;
};

Conj* Conj_create(int size) {
    Conj* c = (Conj*)malloc(sizeof(Conj));
    c->size = size;
    c->v = (int*)malloc(size * sizeof(int));
    return c;
}

void Conj_insert(Conj* c, int x)
{
    for (int i = 0; i < c->size; i++)
    {
        if (c->v[i] == x)
        {
            printf("Elemento já existe no conjunto.\n");
        }
        else
        {
            if (c->v[i] == 0)
            {
                c->v[i] = x;
            }
        }
    }
}