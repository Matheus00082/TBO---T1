#ifndef TARESTA_H
#define TARESTA_H

#include "tPonto.h"

typedef struct tAresta tAresta;

tAresta **arestas(tPonto **pontos, int qtdPontos, int qtdCoord);
void destruirArestas(tAresta **arestas, int qtdArestas);
tAresta *aresta(int idxPonto1, int idxPonto2, double peso);
void destruirAresta(tAresta *a);
int comparaAresta(const void *arestaA, const void *arestaB);
int retornaIdxPonto1(tAresta *a);
int retornaIdxPonto2(tAresta *a);
double retornaPeso(tAresta *a);

#endif