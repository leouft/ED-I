#ifndef FRAC_H
#define FRAC_H
typedef struct _frac Frac;
/** 
 * @param int numerador da fração
 * @param int denominador da fração
 * @return Frac* ponteiro para a fração criada
 */

Frac* Frac_create(int, int);

Frac* Frac_soma(Frac*, Frac*);

Frac* Frac_mult(Frac*, Frac*);

int Frac_equals(Frac*, Frac*);

#endif