#include "tAresta.h"
#include "tPonto.h"
#include "unionFind.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tPonto *criarPonto(char *token, int *qtdCoord);
void agrupamentoMaximo(Vector *arestas, Vector *pontos, int kGrupos);

int main(int argc, char const *argv[]) {
  Vector *pontos = vector_construct();
  int qtdCoordAlocadas = 2, qtdCoord = 0;
  // Receber de argv
  int kGrupos = 3;

  // abrir arquivo argv[n]
  char nomeArquivo[100] = "2.txt";
  FILE *arquivo = fopen(nomeArquivo, "r");

  char *linha = NULL;
  size_t len = 0;

  while (getline(&linha, &len, arquivo) != -1) {
    char *token = strtok(linha, ",");
    vector_push_back(pontos, criarPonto(token, &qtdCoord));
  }

  fclose(arquivo);
  free(linha);

  int qtdPontos = vector_size(pontos);
  Vector *arestas = criarArestas(pontos, qtdCoord);
  vector_sort(arestas, comparaAresta);
  agrupamentoMaximo(arestas, pontos, kGrupos);
  destruirPontos(pontos);
  destruirArestas(arestas);

  return 0;
}

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
  int qtdPontos = vector_size(pontos), *vetorMapa = iniciarVetorMapa(qtdPontos), arestasPercorridas = 0;

  if (kGrupos < qtdPontos) {
    while (kGrupos - 1) {
      int idxPonto1 = retornaIdxPonto1(vector_get(arestas, arestasPercorridas));
      int idxPonto2 = retornaIdxPonto2(vector_get(arestas, arestasPercorridas));
  
      if (!verificaSePontosConectados(vetorMapa, idxPonto1, idxPonto2)) {
        uniao(vetorMapa, idxPonto1, idxPonto2);
        tPonto *ponto1 = vector_get(pontos, idxPonto1);
        tPonto *ponto2 = vector_get(pontos, idxPonto2);
        printf("CONECTEI OS PONTOS: %s e %s\n", nomePonto(ponto1), nomePonto(ponto2));
      }
      else {
        kGrupos--;
      }
      arestasPercorridas++;
    }
  }

  for (int i = 0; i < qtdPontos; i++) {
    printf("RAIZ: %d\n", vetorMapa[i]);
  }
  destruirVetorMapa(vetorMapa);
}