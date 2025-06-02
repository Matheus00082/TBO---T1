#include "tAresta.h"
#include "tPonto.h"
#include "unionFind.h"
#include "vector.h"
#include "auxiliares.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  Vector *pontos = vector_construct();
  int qtdCoordAlocadas = 2, qtdCoord = 0;
  int kGrupos = atoi(argv[2]);

  char nomeArquivo[50];
  strncpy(nomeArquivo, argv[1], sizeof(nomeArquivo));

  FILE *arquivo = fopen(nomeArquivo, "r");

  char *linha = NULL;
  size_t len = 0;

  while (getline(&linha, &len, arquivo) != -1) {
    char *token = strtok(linha, ",");
    vector_push_back(pontos, criarPonto(token, &qtdCoord));
  }

  fclose(arquivo);
  free(linha);

  vector_sort(pontos, comparaPonto);

  int qtdPontos = vector_size(pontos);
  Vector *arestas = criarArestas(pontos, qtdCoord);
  vector_sort(arestas, comparaAresta);

  agrupamentoMaximo(arestas, pontos, kGrupos, argv[3]);

  destruirPontos(pontos);
  destruirArestas(arestas);

  return 0;
}