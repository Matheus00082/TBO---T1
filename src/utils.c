#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

tPonto *criarPonto(char *token, int *qtdCoord) {
  int qtdCoordAlocadas = 2;
  *qtdCoord = 0;
  char *nome = token;
  token = strtok(NULL, ",");

  double *coordenadas = (double *)calloc(qtdCoordAlocadas, sizeof(double));

  while (token != NULL) {
    if (*qtdCoord >= qtdCoordAlocadas) {
      qtdCoordAlocadas *= 2;
      coordenadas = (double *)realloc(coordenadas, qtdCoordAlocadas * sizeof(double));
    }

    coordenadas[(*qtdCoord)++] = atof(token);
    token = strtok(NULL, ",");
  }

  tPonto *pontoAtual = ponto(nome, coordenadas, *qtdCoord);
  free(coordenadas);

  return pontoAtual;
}

void agrupamentoMaximo(Vector *arestas, Vector *pontos, int kGrupos) {
  int qtdPontos = vector_size(pontos), arestasPercorridas = 0, conexoesFeitas = 0;
  tUnionFind *uf = criarUnionFind(qtdPontos);
  Vector *grupos = inicializaGrupos(pontos);

  if (kGrupos < qtdPontos) {
    while (conexoesFeitas  < qtdPontos - kGrupos) {
      int idxPonto1 = retornaIdxPonto1(vector_get(arestas, arestasPercorridas));
      int idxPonto2 = retornaIdxPonto2(vector_get(arestas, arestasPercorridas));
  
      if (!verificaSePontosConectados(uf, idxPonto1, idxPonto2)) {
        uniao(uf, idxPonto1, idxPonto2);
        conexoesFeitas++;
      }

      arestasPercorridas++;
    }
  }

  for (int i = 0; i < qtdPontos; i++) {
    printf("RAIZ: %d\n", getVetorMapa(uf, i));
  }

  destruirUnionFind(uf);
  destruirGrupos(grupos);
}

Vector *inicializaGrupos(Vector *pontos) {
  Vector *grupos = vector_construct();
  int qtdPontos = vector_size(pontos);
  
  for (int i = 0; i < qtdPontos; i++) {
    List *list = list_construct();
    list_push_back(list, vector_get(pontos, i));
    vector_push_back(grupos, list);
  }

  return grupos;
}

void destruirGrupos(Vector *grupos) {
  int qtdGrupos = vector_size(grupos);

  for (int i = 0; i < qtdGrupos; i++) {
    list_destroy(vector_get(grupos, i));
  }

  vector_destroy(grupos);
}