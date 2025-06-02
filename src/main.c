#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tVector.h"
#include "utils.h"

int main(int argc, char const *argv[]) {
  tVector *pontos = constroiVector();
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
    insereAtrasVector(pontos, criarPonto(token, &qtdCoord));
  }
  ordenaVector(pontos, comparaPontos);

  fclose(arquivo);
  free(linha);

  tVector *arestas = criarArestas(pontos, qtdCoord);
  ordenaVector(arestas, comparaAresta);
  agrupamentoMaximo(arestas, pontos, kGrupos);
  destroiPontos(pontos);
  destroiArestas(arestas);
  return 0;
}