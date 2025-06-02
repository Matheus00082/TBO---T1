#ifndef TPONTO_H
#define TPONTO_H

#include "tVector.h"

typedef struct tPonto tPonto;

tPonto *ponto(char *nome, double *coordenadas, int qtdCoord);
int comparaPontos(const void *pontoA, const void *pontoB);
void destroiPonto(tPonto *p);
void destroiPontos(tVector *pontos);
char *nomePonto(tPonto *p);
double *coordenadasPonto(tPonto *p);
double distanciaEuclidiana(tPonto *p1, tPonto *p2, int qtdCoord);
void imprimeNomePonto(void *p);

#endif