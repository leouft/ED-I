#include "TPonto.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct _ponto {
    float x;
    float y;
};

TPonto* TPonto_create(float x, float y)
{
    TPonto *novo = malloc(sizeof(TPonto));
    if (novo != NULL)
    {
        novo->x = x;
        novo->y = y;
    }
    return novo;

}

void TPonto_print(TPonto* ponto)
{
    if (ponto != NULL)
    {
        printf("(%0.2f , %0.2f)\n", ponto->x, ponto->y);
    }
}

void TPonto_destroy(TPonto* ponto)
{
    if (ponto != NULL)
    {
        free(ponto);
    }
}

void TPonto_set_x(TPonto* ponto, float x)
{
    if (ponto != NULL)
    {
        ponto->x = x;
    }
}

void TPonto_set_y(TPonto* ponto, float y)
{
    if (ponto != NULL)
    {
        ponto->y = y;
    }
}

float TPonto_dist(TPonto* ponto1, TPonto* ponto2)
{
    if (ponto1 != NULL && ponto2 != NULL)
    {
        float dist = sqrtf(powf(ponto2->x - ponto1->x, 2) + powf(ponto2->y - ponto1->y, 2));
        return dist;
    }
}
