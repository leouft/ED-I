#ifndef TPONTO_H
#define TPONTO_H
typedef struct _ponto TPonto;
/**
 * @param float x da coordenada do ponto
 * @param float y da coordenada do ponto
 * @return TPonto* ponteiro para o ponto criado
 */
TPonto* TPonto_create(float, float);

void TPonto_print(TPonto*);

void TPonto_destroy(TPonto*);

void TPonto_set_x(TPonto*, float);

void TPonto_set_y(TPonto*, float);

float TPonto_dist(TPonto*, TPonto*);

#endif