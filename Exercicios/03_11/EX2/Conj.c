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

    /*
    printf("\nConjunto:\n");
    for (int i = 0; i < c->size; i++)
    {
        printf("%d ", c->v[i]);
    }
    printf("\nSize do conjunto: %d\n", c->size);
    */
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
                c->v = (int *)realloc(c->v, (c->size + 1) * sizeof(int));
            }
            else
            {
                if (i == 0)
                {
                    for (int j = 0; j < c->size; j++)
                    {
                        c->v[j] = c->v[j + 1];
                        c->size--;
                        c->v = (int *)realloc(c->v, (c->size + 1) * sizeof(int));
                    }
                }
                else
                {
                    for (int j = i; j < c->size; j++)
                    {
                        c->v[j] = c->v[j + 1];
                        c->size--;
                        c->v = (int *)realloc(c->v, (c->size + 1) * sizeof(int));
                    }
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("\nElemento não encontrado no conjunto.\n");
    }

    /*
    printf("\nConjunto:\n");
    for (int i = 0; i < c->size; i++)
    {
        printf("%d ", c->v[i]);
    }
    printf("\nSize do conjunto: %d\n", c->size);
    */
    // mema fita de antes, so pa ve se funciona
}

Conj *Conj_intersection(Conj *c1, Conj *c2)
{
    Conj *c3 = Conj_create();
    for (int i = 0; i < c1->size; i++)
    {
        for (int j = 0; j < c2->size; j++)
        {
            if (c1->v[i] == c2->v[j])
            {
                Conj_insert(c3, c1->v[i]);
            }
        }
    }

    printf("\nConjunto interseção:\n");
    for (int i = 0; i < c3->size; i++)
    {
        printf("%d ", c3->v[i]);
    }
    printf("\nSize do conjunto interseção: %d\n", c3->size);
    return c3;
}

Conj *Conj_difference(Conj *c1, Conj *c2)
{
    Conj *c3 = Conj_create();
    int flag = 0;
    for (int i = 0; i < c1->size; i++)
    {
        for (int j = 0; j < c1->size; j++)
        {
            if (c1->v[i] == c2->v[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            Conj_insert(c3, c1->v[i]);
        }
        flag = 0;
    }

    printf("\nConjunto diferença:\n");
    for (int i = 0; i < c3->size; i++)
    {
        printf("%d ", c3->v[i]);
    }
    printf("\nSize do conjunto diferença: %d\n", c3->size);
    return c3;
}

Conj *Conj_union(Conj *c1, Conj *c2)
{
    Conj *c3 = Conj_create();
    for (int i = 0; i < c1->size; i++)
    {
        Conj_insert(c3, c1->v[i]);
    }
    for (int i = 0; i < c2->size; i++)
    {
        Conj_insert(c3, c2->v[i]);
    }

    printf("\nConjunto união:\n");
    for (int i = 0; i < c3->size; i++)
    {
        printf("%d ", c3->v[i]);
    }
    printf("\nSize do conjunto união: %d\n", c3->size);
    return c3;
}

int Conj_maior(Conj *c)
{
    if (c->size == 0)
    {
        printf("\nConjunto vazio.\n");
        return -1;
    }
    else
    {
        int maior = c->v[0];
        for (int i = 1; i < c->size; i++)
        {
            if (c->v[i] > maior)
            {
                maior = c->v[i];
            }
        }
        return maior;
    }
}

int Conj_menor(Conj *c)
{
    if (c->size == 0)
    {
        printf("\nConjunto vazio.\n");
        return -1;
    }
    else
    {
        int menor = c->v[0];
        for (int i = 1; i < c->size; i++)
        {
            if (c->v[i] < menor)
            {
                menor = c->v[i];
            }
        }
        return menor;
    }
}

int Conj_equals(Conj *c1, Conj *c2)
{
    if (c1->size != c2->size)
    {
        return 0;
    }
    for (int i = 0; i < c1->size; i++)
    {
        int flag = 0;
        for (int j = 0; j < c2->size; j++)
        {
            if (c1->v[i] == c2->v[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return 0;
        }
    }
    return 1;
}

int Conj_size(Conj *c)
{
    return c->size;
}

int Conj_null(Conj *c)
{
    if (c->size == 0)
    {
        return 1;
    }
    return 0;
}