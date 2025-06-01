#include "unionFind.h"
#include "tPonto.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct tUnionFind {
  int *vetorMapa;
  int *tamanhoArvore;
} tUnionFind;

tUnionFind *criarUnionFind(int qtdPontos) {
  tUnionFind *uf = (tUnionFind *)calloc(1, sizeof(tUnionFind));
  uf->vetorMapa = (int *)calloc(qtdPontos, sizeof(int));
  uf->tamanhoArvore = (int *)calloc(qtdPontos, sizeof(int)); 

  for (int i = 0; i < qtdPontos; i++) {
    uf->vetorMapa[i] = i;
    uf->tamanhoArvore[i] = 1;
  }
  return uf;
}

void destruirUnionFind(tUnionFind *uf) {
  if (uf) {
    if (uf->vetorMapa) {
      free(uf->vetorMapa);
    }
    if (uf->tamanhoArvore) {
      free(uf->tamanhoArvore);
    }
    free(uf);
  }
}

void uniao(tUnionFind *uf, int idxPonto1, int idxPonto2) {
  int raizPonto1 = encontra(uf, idxPonto1);
  int raizPonto2 = encontra(uf, idxPonto2);

  if (raizPonto1 != raizPonto2) {
    if (uf->tamanhoArvore[raizPonto1] < uf->tamanhoArvore[raizPonto2]) {
      uf->vetorMapa[raizPonto1] = uf->vetorMapa[raizPonto2];
      uf->tamanhoArvore[raizPonto2] += uf->tamanhoArvore[raizPonto1];
    }
    else {
      uf->vetorMapa[raizPonto2] = uf->vetorMapa[raizPonto1];
      uf->tamanhoArvore[raizPonto1] += uf->tamanhoArvore[raizPonto2];
    }
    printf("Unindo %d e %d\n", raizPonto1, raizPonto2);
  }
}

int encontra(tUnionFind *uf, int idxPonto) {
  while (idxPonto != uf->vetorMapa[idxPonto]) {
    idxPonto = uf->vetorMapa[idxPonto];
  }
  return idxPonto;
}

int verificaSePontosConectados(tUnionFind *uf, int idxPonto1, int idxPonto2) {
  return encontra(uf, idxPonto1) == encontra(uf, idxPonto2);
}

int getVetorMapa(tUnionFind *uf, int i) {
  return uf->vetorMapa[i];
}