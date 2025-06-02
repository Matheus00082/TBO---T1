#include "tPonto.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tPonto {
  char *nome;
  double *coordenadas;
  tPonto *proximo;
} tPonto;

tPonto *ponto(char *nome, double *coordenadas, int qtdCoord) {

  tPonto *p = (tPonto *)calloc(1, sizeof(tPonto));
  p->nome = (char *)calloc(strlen(nome) + 1, sizeof(char));
  strcpy(p->nome, nome);
  p->coordenadas = (double *)calloc(qtdCoord, sizeof(double));

  for (int i = 0; i < qtdCoord; i++) {
    p->coordenadas[i] = coordenadas[i];
  }

  return p;
}

void destruirPonto(tPonto *p) {
  if (p == NULL) return;

  free(p->nome);
  free(p->coordenadas);
  free(p);
}

void destruirPontos(Vector *pontos) {
  int qtdPontos = vector_size(pontos);

  for (int i = 0; i < qtdPontos; i++) {
    destruirPonto(vector_pop_back(pontos));
  }
  vector_destroy(pontos);
}

char *nomePonto(tPonto *p) { return p->nome; }

double *coordenadasPonto(tPonto *p) { return p->coordenadas; }

double distanciaEuclidiana(tPonto *p1, tPonto *p2, int qtdCoord) {
  double somatorio = 0;

  for (int i = 0; i < qtdCoord; i++) {
    somatorio += pow(p1->coordenadas[i] - p2->coordenadas[i], 2);
  }

  return somatorio;
}

int comparaPonto(const void *a, const void *b) {
  tPonto *p1 = *(tPonto **)a;
  tPonto *p2 = *(tPonto **)b;

  return strcmp(p1->nome, p2->nome);
}
