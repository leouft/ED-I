#include "Conj.h"
#include <stdio.h>
#include <stdlib.h>

struct _conj
{
    int size;
    int *v;
};

Conj *Conj_create()
{
    Conj *c = (Conj *)malloc(sizeof(Conj));
    c->size = 0;
    c->v = (int *)malloc((c->size + 1) * sizeof(int));
    return c;
}

void Conj_insert(Conj *c, int x)
{
    c->v = (int *)realloc(c->v, (c->size + 1) * sizeof(int));
    if (c->size == 0)
    {
        c->v[0] = x;
        c->size++;
    }
    else
    {
        int flag = 0;
        for (int i = 0; i < c->size; i++)
        {
            if (c->v[i] == x)
            {
                flag = 1;
                printf("\nElemento já existe no conjunto.\n");
                break;
            }
        }
        if (flag == 0)
        {
            c->v[c->size] = x;
            c->size++;
        }
    }

    printf("\nConjunto:\n");
    for (int i = 0; i < c->size; i++)
    {
        printf("%d ", c->v[i]);
    }
    printf("\nSize do conjunto: %d\n", c->size);
    // Apenas retorno pra saber se tá funcionando certo essa parada aí
}

void Conj_remove(Conj *c, int x)
{
    int flag = 0;
    for (int i = 0; i < c->size; i++)
    {
        if (c->v[i] == x)
        {
            flag = 1;
            if (i == c->size - 1)
            {
                c->size--;
                c->v = (int *)realloc(c->v, (c->size+1) * sizeof(int));
            }
            else
            {
                if (i == 0)
                {
                    for (int j = 0; j < c->size; j++)
                    {
                        c->v[j] = c->v[j + 1];
                        c->size--;
                        c->v = (int *)realloc(c->v, (c->size+1) * sizeof(int));
                    }
                }
                else
                {
                    for (int j = i; j < c->size; j++)
                    {
                        c->v[j] = c->v[j + 1];
                        c->size--;
                        c->v = (int *)realloc(c->v, (c->size+1) * sizeof(int));
                    }
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("\nElemento não encontrado no conjunto.\n");
    }

    printf("\nConjunto:\n");
    for (int i = 0; i < c->size; i++)
    {
        printf("%d ", c->v[i]);
    }
    printf("\nSize do conjunto: %d\n", c->size);
    // mema fita de antes, so pa ve se funciona
}
