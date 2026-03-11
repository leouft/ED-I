#include "Frac.h"
#include <stdio.h>

void main()
{
    int num[2], den[2];
    printf("\nDigite o numerador e denominador da primeira fração: ");
    scanf("%d %d", &num[0], &den[0]);
    printf("\nDigite o numerador e denominador da segunda fração: ");
    scanf("%d %d", &num[1], &den[1]);

    Frac* f1 = Frac_create(num[0], den[0]);
    Frac* f2 = Frac_create(num[1], den[1]);

    Frac* soma = Frac_soma(f1, f2);
    Frac* mult = Frac_mult(f1, f2);

    if (Frac_equals(f1, f2)) {
        printf("\nAs frações resultantes são iguais.\n");
    }
    else
    {
        printf("\nAs frações resultantes são diferentes.\n");
    }
}