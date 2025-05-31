#ifndef TPONTO_H
#define TPONTO_H

#include "vector.h"

typedef struct tPonto tPonto;

tPonto *ponto(char *nome, double *coordenadas, int qtdCoord);
int comparaPontos(const void *pontoA, const void *pontoB);
void destruirPonto(tPonto *p);
void destruirPontos(Vector *p);
char *nomePonto(tPonto *p);
double *coordenadasPonto(tPonto *p);
double distanciaEuclidiana(tPonto *p1, tPonto *p2, int qtdCoord);

#endif