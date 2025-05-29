#ifndef TARESTA_H
#define TARESTA_H

#include "tPonto.h"
#include "vector.h"

typedef struct tAresta tAresta;

Vector *criarArestas(Vector *pontos, int qtdCoord);
void destruirArestas(Vector *arestas);
tAresta *criarAresta(int idxPonto1, int idxPonto2, double peso);
int comparaAresta(const void *arestaA, const void *arestaB);
int retornaIdxPonto1(tAresta *a);
int retornaIdxPonto2(tAresta *a);
double retornaPeso(tAresta *a);

#endif