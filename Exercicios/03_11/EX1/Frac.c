#include "Frac.h"
#include <stdio.h>
#include <stdlib.h>

struct _frac {
    int num;
    int den;
};

Frac* Frac_create(int num, int den) {
    Frac* f = (Frac*)malloc(sizeof(Frac));
    f->num = num;
    f->den = den;
    return f;
}

Frac* Frac_soma(Frac* f1, Frac* f2) {
    int nums = f1->num * f2->den + f2->num * f1->den;
    int dens = f1->den * f2->den;
    printf("\nSoma: %d/%d\n", nums, dens);
    return Frac_create(nums, dens);
}

Frac* Frac_mult(Frac* f1, Frac* f2) {
    int numm = f1->num * f2->num;
    int denm = f1->den * f2->den;
    printf("\nMultiplicação: %d/%d\n", numm, denm);
    return Frac_create(numm, denm);
}

int Frac_equals(Frac* f1, Frac* f2) {
    if (f1->num * f2->den == f2->num * f1->den) {
        return 1;
    }
    else
    {
        return 0;
    }
}