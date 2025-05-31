#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
#include "utils.h"

int main(int argc, char const *argv[]) {
  Vector *pontos = vector_construct();
  int qtdCoord = 0;
  // Receber de argv
  int kGrupos = 3;

  // abrir arquivo argv[n]
  char nomeArquivo[50] = "2.txt";

  FILE *arquivo = fopen(nomeArquivo, "r");

  char *linha = NULL;
  size_t len = 0;

  while (getline(&linha, &len, arquivo) != -1) {
    char *token = strtok(linha, ",");
    vector_push_back(pontos, criarPonto(token, &qtdCoord));
  }
  vector_sort(pontos, comparaPontos);

  fclose(arquivo);
  free(linha);

  Vector *arestas = criarArestas(pontos, qtdCoord);
  vector_sort(arestas, comparaAresta);
  agrupamentoMaximo(arestas, pontos, kGrupos);
  destruirPontos(pontos);
  destruirArestas(arestas);
  return 0;
}