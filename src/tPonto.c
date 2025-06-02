#include "tPonto.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tPonto {
  char *nome;
  double *coordenadas;
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

int comparaPontos(const void *pontoA, const void *pontoB) {
  const tPonto *a = *(const tPonto**)pontoA;
  const tPonto *b = *(const tPonto**)pontoB;
  char *nomePontoA = a->nome;
  char *nomePontoB = b->nome;

  if (nomePontoA < nomePontoB) {
    return -1;
  }

  else if (nomePontoA > nomePontoB) {
    return 1;
  }

  return 0;
}

void destroiPonto(tPonto *p) {
  if (p == NULL) return;

  free(p->nome);
  free(p->coordenadas);
  free(p);
}

void destroiPontos(tVector *pontos) {
  int qtdPontos = tamanhoVector(pontos);

  for (int i = 0; i < qtdPontos; i++) {
    destroiPonto(removeAtrasVector(pontos));
  }
  destroiVector(pontos);
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

void imprimeNomePonto(void *p) {
  tPonto *ponto = (tPonto *)p;
  printf("%s", ponto->nome);
}