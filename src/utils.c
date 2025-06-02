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

void agrupamentoMaximo(tVector *arestas, tVector *pontos, int kGrupos, const char *nomeArquivoSaida) {
  int qtdPontos = tamanhoVector(pontos), arestasPercorridas = 0, conexoesFeitas = 0;
  tUnionFind *uf = criarUnionFind(qtdPontos);
  tVector *grupos = inicializaGrupos(pontos);

  if (kGrupos < qtdPontos) {
    while (conexoesFeitas  < qtdPontos - kGrupos) {
      int idxPonto1 = retornaIdxPonto1(getElementoVector(arestas, arestasPercorridas));
      int idxPonto2 = retornaIdxPonto2(getElementoVector(arestas, arestasPercorridas));
  
      if (!verificaSePontosConectados(uf, idxPonto1, idxPonto2)) {
        uniao(uf, idxPonto1, idxPonto2, grupos);
        conexoesFeitas++;
      }

      arestasPercorridas++;
    }
  }

  imprimeGrupos(grupos, nomeArquivoSaida);
  destruirUnionFind(uf);
  destruirGrupos(grupos);
}

tVector *inicializaGrupos(tVector *pontos) {
  tVector *grupos = constroiVector();
  int qtdPontos = tamanhoVector(pontos);
  
  for (int i = 0; i < qtdPontos; i++) {
    tLista *lista = constroiLista();
    insereAtrasLista(lista, getElementoVector(pontos, i));
    insereAtrasVector(grupos, lista);
  }

  return grupos;
}

void imprimeGrupos(tVector *grupos, const char *nomeArquivoSaida) {
  int qtdPontos = tamanhoVector(grupos);

  FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");

  for (int i = 0; i < qtdPontos; i++) {
    tLista *l = getElementoVector(grupos, i);

    if (tamanhoLista(l) > 0) {
      tVector *v = listaParaVector(l);
      ordenaVector(v, comparaPontos);
      imprimeVector(v, imprimeNomePonto, arquivoSaida);
      destroiVector(v);
    }
  }

  fclose(arquivoSaida);
}

void destruirGrupos(tVector *grupos) {
  int qtdGrupos = tamanhoVector(grupos);

  for (int i = 0; i < qtdGrupos; i++) {
    destroiLista(getElementoVector(grupos, i));
  }

  destroiVector(grupos);
}