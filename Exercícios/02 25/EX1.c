#include <stdio.h>

#define MAX 10

void main()
{
    int V[MAX], x;
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &V[i]);
    }

    scanf("%d", &x);

    for (int i = 0; i < MAX; i++)
    {
        if (V[i] % x == 0)
        {
            printf("%d ", V[i]);
        }
    }
}
