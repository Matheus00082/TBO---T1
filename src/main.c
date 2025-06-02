#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tVector.h"
#include "utils.h"
#include <time.h>

int main(int argc, char const *argv[]) {

  /*clock_t inicio = clock();
  clock_t fim;
  double tempoExecucao;*/

  tVector *pontos = constroiVector();
  int qtdCoord = 0;
  int kGrupos = atoi(argv[2]);

  char nomeArquivo[50];
  strcpy(nomeArquivo, argv[1]);

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
  agrupamentoMaximo(arestas, pontos, kGrupos, argv[3]);
  destroiPontos(pontos);
  destroiArestas(arestas);

  /*fim = clock();
  tempoExecucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("Tempo de execução: %.2f segundos\n", tempoExecucao);*/
 
  return 0;
}