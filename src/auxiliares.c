#include "auxiliares.h"

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

void agrupamentoMaximo(Vector *arestas, Vector *pontos, int kGrupos, const char *arquivoSaida) {
  int qtdPontos = vector_size(pontos), *vetorMapa = iniciarVetorMapa(qtdPontos), arestasPercorridas = 0, conexoesFeitas = 0;

    while ((conexoesFeitas  < qtdPontos - kGrupos) && (arestasPercorridas < vector_size(arestas))) {
      int idxPonto1 = retornaIdxPonto1(vector_get(arestas, arestasPercorridas));
      int idxPonto2 = retornaIdxPonto2(vector_get(arestas, arestasPercorridas));
  
      if (!verificaSePontosConectados(vetorMapa, idxPonto1, idxPonto2)) {
        uniao(vetorMapa, idxPonto1, idxPonto2);
        conexoesFeitas++;
      }

      arestasPercorridas++;
    }

  // imprimeGRupos(vetorMapa, pontos, kGrupos, arquivoSaida);
  destruirVetorMapa(vetorMapa);
}

void imprimeGrupos(int *vetorMapa, Vector *pontos, int kGrupos, const char *arquivoSaida) {
    FILE *saida = fopen(arquivoSaida, "w");

    tPonto **atualCadaGrupo = (tPonto **)calloc(kGrupos, sizeof(tPonto *));
    int tamanhoMapa = vector_size(pontos);
    for (int i = 0; i < tamanhoMapa; i++)
    {
        
    }
    

    fclose(saida);
}