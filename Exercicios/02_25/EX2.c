#include <stdio.h>
#define MAX 50

void printV(float V[])
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%g ", V[i]);
    }
}

void main()
{
    float V[MAX];
    for (int i = 0; i < MAX; i++)
    {
        V[i] = (i + 5 * i) % (i + 1);
    }

    printV(V);
}