#include "unionFind.h"
#include "tPonto.h"
#include <stdio.h>
#include <stdlib.h>

int *iniciarVetorMapa(int qtdPontos) {
  int *vetorMapa = (int *)calloc(qtdPontos, sizeof(int));

  for (int i = 0; i < qtdPontos; i++) {
    vetorMapa[i] = i;
  }
  return vetorMapa;
}

void destruirVetorMapa(int *vetorMapa) {
  if (vetorMapa == NULL)
    return;
  free(vetorMapa);
}

void uniao(int *vetorMapa, int idxPonto1, int idxPonto2) {
  int raizPonto1 = encontra(vetorMapa, idxPonto1);
  int raizPonto2 = encontra(vetorMapa, idxPonto2);

  if (raizPonto1 != raizPonto2) {
    if (idxPonto2 != raizPonto2) {
      vetorMapa[raizPonto1] = raizPonto2;
    }
    else {
      vetorMapa[raizPonto2] = raizPonto1;
    }

    printf("Unindo %d e %d\n", raizPonto1, raizPonto2);
  }
}

int encontra(int *vetorMapa, int idxPonto) {
  if (vetorMapa[idxPonto] != idxPonto) {
    vetorMapa[idxPonto] = encontra(vetorMapa, vetorMapa[idxPonto]);
  }
  return vetorMapa[idxPonto];
}

int verificaSePontosConectados(int *vetorMapa, int idxPonto1, int idxPonto2) {
  return encontra(vetorMapa, idxPonto1) == encontra(vetorMapa, idxPonto2);
}