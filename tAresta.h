#ifndef TARESTA_H
#define TARESTA_H

#include "tPonto.h"

typedef struct tAresta tAresta;

tAresta **arestas(tPonto **pontos, int qtdPontos, int qtdCoord);
tAresta *aresta(int idxPonto1, int idxPonto2, double peso);
void destruirAresta(tAresta *a);

#endif