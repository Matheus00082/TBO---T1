#include "tAresta.h"
#include "tPonto.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  tPonto **pontos = (tPonto **)calloc(2, sizeof(tPonto *));
  double coord1[] = {0, 0};
  double coord2[] = {3, 4};
  double coord3[] = {6, 8};
  double coord4[] = {9, 12};
  double coord5[] = {12, 16};
  pontos[0] = ponto("A", coord1, 2);
  pontos[1] = ponto("B", coord2, 2);
  pontos[2] = ponto("C", coord3, 2);
  pontos[3] = ponto("D", coord4, 2);
  pontos[4] = ponto("E", coord5, 2);

  for (int i = 0; i < 5; i++) {
    destruirPonto(pontos[i]);
  }

  free(pontos);
  return 0;
}