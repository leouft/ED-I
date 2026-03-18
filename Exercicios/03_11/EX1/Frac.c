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
    printf("\nMultiplicação: %d/%d\n", f1->num * f2->num, f1->den * f2->den);
    return Frac_create(f1->num * f2->num, f1->den * f2->den);
}

int Frac_equals(Frac* f1, Frac* f2) {
    return f1->num * f2->den == f2->num * f1->den;
}