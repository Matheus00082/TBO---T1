#include "tAresta.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tAresta {
  int idxPonto1, idxPonto2;
  double peso;
} tAresta;

Vector *criarArestas(Vector *pontos, int qtdCoord) {
  int qtdPontos = vector_size(pontos);
  Vector *arestas = vector_construct();

  for (int i = 0; i < qtdPontos; i++) {
    for (int j = i + 1; j < qtdPontos; j++) {
      vector_push_back(arestas, criarAresta(i, j, distanciaEuclidiana(vector_get(pontos, i), vector_get(pontos, j), qtdCoord)));
    }
  }

  return arestas;
}

void destruirArestas(Vector *arestas) {
  int qtdArestas = vector_size(arestas);

  for (int i = 0; i < qtdArestas; i++) {
    free(vector_pop_back(arestas));
  }
  vector_destroy(arestas);
}

tAresta *criarAresta(int idxPonto1, int idxPonto2, double peso) {
  tAresta *a = (tAresta *)calloc(1, sizeof(tAresta));
  a->idxPonto1 = idxPonto1;
  a->idxPonto2 = idxPonto2;
  a->peso = peso;
  return a;
}

int comparaAresta(const void *arestaA, const void *arestaB) {
  const tAresta *a = *(const tAresta**)arestaA;
  const tAresta *b = *(const tAresta**)arestaB;
  double pesoA = a->peso;
  double pesoB = b->peso;

  if (pesoA < pesoB) {
    return -1;
  }

  else if (pesoA > pesoB) {
    return 1;
  }

  return 0;
}

int retornaIdxPonto1(tAresta *a) { return a->idxPonto1; }

int retornaIdxPonto2(tAresta *a) { return a->idxPonto2; }

double retornaPeso(tAresta *a) { return a->peso; }