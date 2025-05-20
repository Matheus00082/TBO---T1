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

void destruirPonto(tPonto *p) {
  if (p == NULL)
    return;

  // printf("Destruindo ponto %s\n", p->nome);
  free(p->nome);
  free(p->coordenadas);
  free(p);
}

char *nomePonto(tPonto *p) { return p->nome; }

double *coordenadasPonto(tPonto *p) { return p->coordenadas; }

double distanciaEuclidiana(tPonto *p1, tPonto *p2, int qtdCoord) {
  double somatorio = 0;

  for (int i = 0; i < qtdCoord; i++) {
    somatorio += pow(p1->coordenadas[i] - p2->coordenadas[i], 2);
  }

  return sqrt(somatorio);
}
