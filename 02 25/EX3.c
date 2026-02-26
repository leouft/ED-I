#include <stdio.h>
#define MAX 10

void vefNum(int *, int V[], int);

void printV(int V[])
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", V[i]);
    }
}

void main()
{
    int V[MAX];
    for (int i = 0; i < MAX; i++)
    {
        int temp;
        scanf("%d", &temp);
        vefNum(&temp, V, i);
    }

    printV(V);
}

void vefNum(int *temp, int V[], int i)
{
    for (int j = 0; j <= i; j++)
    {
        if (*temp == V[j])
        {
            printf("Número já existente, insira outro: ");
            scanf("%d", temp);
            vefNum(temp, V, i);
            return;
        }
    }
    V[i] = *temp;
}