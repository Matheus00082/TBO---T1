#include "tAresta.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tAresta {
  int idxPonto1, idxPonto2;
  double peso;
} tAresta;

tAresta **arestas(tPonto **pontos, int qtdPontos, int qtdCoord) {
  int qtdMaxArestas = qtdPontos * (qtdPontos - 1) / 2;
  tAresta **arestas = (tAresta **)calloc(qtdMaxArestas, sizeof(tAresta *));
  int idxAresta = 0;

  for (int i = 0; i < qtdPontos; i++) {
    for (int j = i + 1; j < qtdPontos; j++) {
      arestas[idxAresta++] =
          aresta(i, j, distanciaEuclidiana(pontos[i], pontos[j], qtdCoord));
    }
  }

  return arestas;
}

void destruirArestas(tAresta **arestas, int qtdArestas) {
  for (int i = 0; i < qtdArestas; i++) {
    destruirAresta(arestas[i]);
  }
  free(arestas);
}

tAresta *aresta(int idxPonto1, int idxPonto2, double peso) {
  tAresta *a = (tAresta *)calloc(1, sizeof(tAresta));
  a->idxPonto1 = idxPonto1;
  a->idxPonto2 = idxPonto2;
  a->peso = peso;
  return a;
}

void destruirAresta(tAresta *a) { free(a); }

int comparaAresta(const void *arestaA, const void *arestaB) {
  double pesoA = (*(const tAresta **)arestaA)->peso;
  double pesoB = (*(const tAresta **)arestaB)->peso;

  if (pesoA < pesoB) {
    return -1;
  }

  if (pesoA > pesoB) {
    return 1;
  }

  return 0;
}

int retornaIdxPonto1(tAresta *a) { return a->idxPonto1; }

int retornaIdxPonto2(tAresta *a) { return a->idxPonto2; }

double retornaPeso(tAresta *a) { return a->peso; }