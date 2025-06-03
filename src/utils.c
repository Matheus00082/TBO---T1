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

  while (conexoesFeitas  < qtdPontos - kGrupos) {
    int idxPonto1 = retornaIdxPonto1(getElementoVector(arestas, arestasPercorridas));
    int idxPonto2 = retornaIdxPonto2(getElementoVector(arestas, arestasPercorridas));

    if (!verificaSePontosConectados(uf, idxPonto1, idxPonto2)) {
      uniao(uf, idxPonto1, idxPonto2, grupos);
      conexoesFeitas++;
    }

    arestasPercorridas++;
  }

  imprimeGrupos(grupos, nomeArquivoSaida, kGrupos);
  destruirUnionFind(uf);
  destruirGrupos(grupos);
}

tVector *inicializaGrupos(tVector *pontos) {
  int qtdPontos = tamanhoVector(pontos);
  tVector *grupos = constroiVector(qtdPontos);
  
  for (int i = 0; i < qtdPontos; i++) {
    tLista *lista = constroiLista();
    insereAtrasLista(lista, getElementoVector(pontos, i));
    insereAtrasVector(grupos, lista);
  }

  return grupos;
}

int comparaPrimeiroPontoDoGrupo(const void *grupoA_void, const void *grupoB_void) {
    tVector *grupoA_vetor = *(tVector **)grupoA_void;
    tVector *grupoB_vetor = *(tVector **)grupoB_void;

    tPonto *pontoA_primeiro = (tPonto *)getElementoVector(grupoA_vetor, 0);
    tPonto *pontoB_primeiro = (tPonto *)getElementoVector(grupoB_vetor, 0);

    return comparaPontos(&pontoA_primeiro, &pontoB_primeiro);
}

void imprimeGrupos(tVector *grupos, const char *nomeArquivoSaida, int kGrupos) {
  int qtdGrupos = tamanhoVector(grupos); //qtd grupos nn?
  tVector *gruposParaImprimir = constroiVector(kGrupos);
  int grupoIdx = 0;

  for (int i = 0; i < qtdGrupos; i++) {
    tLista *l = (tLista *) getElementoVector(grupos, i);

    if (tamanhoLista(l) > 0) {
      tVector *v = listaParaVector(l);
      ordenaVector(v, comparaPontos);
      insereAtrasVector(gruposParaImprimir, v);
    }
  }

  ordenaVector(gruposParaImprimir, comparaPrimeiroPontoDoGrupo);
  FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");

  for (int i = 0; i < kGrupos; i++) {
    imprimeVector(getElementoVector(gruposParaImprimir, i), imprimeNomePonto, arquivoSaida);
    destroiVector(getElementoVector(gruposParaImprimir, i));
  }

  fclose(arquivoSaida);
  destroiVector(gruposParaImprimir);
}

void destruirGrupos(tVector *grupos) {
  int qtdGrupos = tamanhoVector(grupos);

  for (int i = 0; i < qtdGrupos; i++) {
    destroiLista(getElementoVector(grupos, i));
  }

  destroiVector(grupos);
}