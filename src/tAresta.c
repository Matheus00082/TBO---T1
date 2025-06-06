#include "tAresta.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tAresta {
  int idxPonto1, idxPonto2;
  double peso;
} tAresta;

tVector *criarArestas(tVector *pontos, int qtdCoord) {
  int qtdPontos = tamanhoVector(pontos);
  int qtdArestas = qtdPontos * (qtdPontos - 1) / 2; // Fórmula para calcular o número de arestas em um grafo completo
  tVector *arestas = constroiVector(qtdArestas);

  for (int i = 0; i < qtdPontos; i++) {
    for (int j = i + 1; j < qtdPontos; j++) {
      insereAtrasVector(arestas, criarAresta(i, j, distanciaEuclidiana(getElementoVector(pontos, i), getElementoVector(pontos, j), qtdCoord)));
    }
  }

  return arestas;
}

void destroiArestas(tVector *arestas) {
  int qtdArestas = tamanhoVector(arestas);

  for (int i = 0; i < qtdArestas; i++) {
    free(removeAtrasVector(arestas));
  }
  destroiVector(arestas);
}

tAresta *criarAresta(int idxPonto1, int idxPonto2, double peso) {
  tAresta *a = (tAresta *)malloc(sizeof(tAresta));
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
  return pesoA - pesoB;
}

int retornaIdxPonto1(tAresta *a) { return a->idxPonto1; }

int retornaIdxPonto2(tAresta *a) { return a->idxPonto2; }

double retornaPeso(tAresta *a) { return a->peso; }