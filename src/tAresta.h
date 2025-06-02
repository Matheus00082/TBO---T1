#ifndef TARESTA_H
#define TARESTA_H

#include "tPonto.h"
#include "tVector.h"

typedef struct tAresta tAresta;

tVector *criarArestas(tVector *pontos, int qtdCoord);
void destroiArestas(tVector *arestas);
tAresta *criarAresta(int idxPonto1, int idxPonto2, double peso);
int comparaAresta(const void *arestaA, const void *arestaB);
int retornaIdxPonto1(tAresta *a);
int retornaIdxPonto2(tAresta *a);
double retornaPeso(tAresta *a);

#endif