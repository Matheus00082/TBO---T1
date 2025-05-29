#include "tAresta.h"
#include "tPonto.h"
#include "unionFind.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tPonto *criarPonto(char *token, int *qtdCoord);
void gerarMst(Vector *arestas, int qtdPontos, Vector *pontos);

int main(int argc, char const *argv[]) {
  Vector *pontos = vector_construct();
  int qtdCoordAlocadas = 2, qtdCoord = 0;

  // abrir arquivo argv[n]
  char nomeArquivo[100] = "1.txt";
  FILE *arquivo = fopen(nomeArquivo, "r");

  char *linha = NULL;
  size_t len = 0;

  while (getline(&linha, &len, arquivo) != -1) {
    char *token = strtok(linha, ",");
    vector_push_back(pontos, criarPonto(token, &qtdCoord));
  }

  fclose(arquivo);

  int qtdPontos = vector_size(pontos);
  Vector *arestas = criarArestas(pontos, qtdCoord);
  vector_sort(arestas, comparaAresta);
  gerarMst(arestas, qtdPontos, pontos);
  vector_destroy(pontos);

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

void gerarMst(Vector *arestas, int qtdPontos, Vector *pontos) {
  int pontosConectados = 0, arestasPercorridas = 0, *vetorMapa = iniciarVetorMapa(qtdPontos);
  double custoTotal = 0;
  int qtdArestas = qtdPontos * (qtdPontos - 1) / 2; // Fórmula para calcular a quantidade de arestas em um grafo completo

  for (int i = 0; i < qtdArestas && pontosConectados < qtdPontos - 1; i++) {
    int idxPonto1 = retornaIdxPonto1(vector_get(arestas, arestasPercorridas));
    int idxPonto2 = retornaIdxPonto2(vector_get(arestas, arestasPercorridas));

    if (!verificaSePontosConectados(vetorMapa, idxPonto1, idxPonto2)) {
      uniao(vetorMapa, idxPonto1, idxPonto2, &pontosConectados);
      custoTotal += retornaPeso(vector_get(arestas, arestasPercorridas));
      pontosConectados++;
    }

    arestasPercorridas++;
  }

  printf("Custo total: %.2lf\n", custoTotal);
  printf("Arestas percorridas: %d\n", arestasPercorridas);
  printf("Pontos conectados: %d\n", pontosConectados);

  destruirVetorMapa(vetorMapa);
  destruirArestas(arestas);
}