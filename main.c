#include "tAresta.h"
#include "tPonto.h"
#include "unionFind.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int tamanhoAlocado = 100, qtdPontos = 0, qtdCoordAlocadas = 2, qtdCoord = 0;
  tPonto **pontos = (tPonto **)calloc(tamanhoAlocado, sizeof(tPonto *));

  // abrir arquivo argv[n]
  char nomeArquivo[100] = "1.txt";
  FILE *arquivo = fopen(nomeArquivo, "r");

  char linha[1000];
  while (fgets(linha, sizeof(linha), arquivo)) {
    char *token = strtok(linha, ",");
    qtdCoord = 0;

    // criar ponto
    char *nome = token;
    token = strtok(NULL, ",");

    double *coordenadas = (double *)calloc(qtdCoordAlocadas, sizeof(double));

    while (token != NULL) {
      if (qtdCoord >= qtdCoordAlocadas) {
        qtdCoordAlocadas *= 2;
        coordenadas =
            (double *)realloc(coordenadas, qtdCoordAlocadas * sizeof(double));
      }

      coordenadas[qtdCoord++] = atof(token);
      token = strtok(NULL, ",");
    }

    pontos[qtdPontos] = ponto(nome, coordenadas, qtdCoord, qtdPontos);
    qtdPontos++;

    free(coordenadas);

    if (qtdPontos >= tamanhoAlocado) {
      tamanhoAlocado *= 2;
      pontos = (tPonto **)realloc(pontos, tamanhoAlocado * sizeof(tPonto *));
    }
  }

  fclose(arquivo);

  int qtdArestas = qtdPontos * (qtdPontos - 1) / 2;
  tAresta **a = arestas(pontos, qtdPontos, qtdCoord);

  qsort(a, qtdArestas, sizeof(tAresta *), comparaAresta);

  int pontosConectados = 0, arestasPercorridas = 0,
      *vetorMapa = iniciarVetorMapa(qtdPontos);
  double custoTotal = 0.00;

  for (int i = 0; i < qtdArestas && pontosConectados < qtdPontos - 1; i++) {
    int idxPonto1 = retornaIdxPonto1(a[arestasPercorridas]);
    int idxPonto2 = retornaIdxPonto2(a[arestasPercorridas]);

    if (!verificaSePontosConectados(vetorMapa, idxPonto1, idxPonto2)) {
      uniao(vetorMapa, idxPonto1, idxPonto2, &pontosConectados);
      custoTotal += retornaPeso(a[arestasPercorridas]);
      pontosConectados++;
    }

    arestasPercorridas++;
  }

  printf("Custo total: %.2lf\n", custoTotal);
  printf("Arestas percorridas: %d\n", arestasPercorridas);
  printf("Pontos conectados: %d\n", pontosConectados);
  for (int i = 0; i < qtdPontos; i++) {
    printf("%d\n", vetorMapa[i]);
  }

  destruirVetorMapa(vetorMapa);
  destruirArestas(a, qtdArestas);

  for (int i = 0; i < qtdPontos; i++) {
    destruirPonto(pontos[i]);
  }

  free(pontos);
  return 0;
}