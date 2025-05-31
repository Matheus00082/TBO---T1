#include "tAresta.h"
#include "tPonto.h"
#include "tGrupo.h"
#include "unionFind.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

tPonto *criarPonto(char *token, int *qtdCoord);
int comparaNomePontos(const void* a, const void* b);
int comparaGruposPrimeiroElemento(const void* a, const void* b);
void agrupamentoMaximo(Vector *arestas, Vector *pontos, int kGrupos);
void escreverGruposOrdenados(const char* arqNome, Vector* pontos, int* vetorMapa, int qtdPontos);


int main(int argc, char const *argv[]) {
  Vector *pontos = vector_construct();
  int qtdCoordAlocadas = 2, qtdCoord = 0;
  int idxPonto = 0;
  // Receber de argv
  int kGrupos = 3;

  // abrir arquivo argv[n]
  char nomeArquivo[50] = "1.txt";

  FILE *arquivo = fopen(nomeArquivo, "r");

  char *linha = NULL;
  size_t len = 0;

  while (getline(&linha, &len, arquivo) != -1) {
    char *token = strtok(linha, ",");
    vector_push_back(pontos, criarPonto(token, &qtdCoord, &idxPonto));
    idxPonto++;
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

tPonto *criarPonto(char *token, int *qtdCoord, int* idxPontoPont) {
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

  tPonto *pontoAtual = ponto(nome, coordenadas, *qtdCoord, *idxPontoPont);
  free(coordenadas);

  return pontoAtual;
}

int comparaNomePontos(const void* a, const void* b) {
    tPonto* p1 = (tPonto*)a; 
    tPonto* p2 = (tPonto*)b;
    return strcmp(getNomePonto(p1), getNomePonto(p2));
}

int comparaGruposPrimeiroElemento(const void* a, const void* b) {
    tGrupo* g1 = (tGrupo*)a;
    tGrupo* g2 = (tGrupo*)b;
    return strcmp(g1->primeiroElementoNome, g2->primeiroElementoNome);
}

void agrupamentoMaximo(Vector *arestas, Vector *pontos, int kGrupos) {
  int qtdPontos = vector_size(pontos), *vetorMapa = iniciarVetorMapa(qtdPontos), arestasPercorridas = 0, conexoesFeitas = 0;

  if (kGrupos < qtdPontos) {
    while (conexoesFeitas  < qtdPontos - kGrupos) {
      int idxPonto1 = retornaIdxPonto1(vector_get(arestas, arestasPercorridas));
      int idxPonto2 = retornaIdxPonto2(vector_get(arestas, arestasPercorridas));
  
      if (!verificaSePontosConectados(vetorMapa, idxPonto1, idxPonto2)) {
        uniao(vetorMapa, idxPonto1, idxPonto2);
        conexoesFeitas++;
      }

      arestasPercorridas++;
    }
  }

  escreverGruposOrdenados(arqNome, pontos, vetorMapa, qtdPontos);
  destruirVetorMapa(vetorMapa);
}

void escreverGruposOrdenados(const char* arqNome, Vector* pontos, int* vetorMapa, int qtdPontos) {
    //FILE* arqSaida = fopen(arqNomeAq, "w"); escrever em um arquivo

    Vector* listaGrupos = vector_construct();
    tGrupo** mapeamentoRaizGrupo = (tGrupo**) calloc(qtdPontos, sizeof(tGrupo*));
     for (int i = 0; i < qtdPontos; i++) {
        mapeamentoRaizGrupo[i] = NULL; 
    }

    for (int i = 0; i < qtdPontos; i++) {
      tPonto* p = (tPonto*)vector_get(pontos, i);
      int raiz = encontra(vetorMapa, getIdxPonto(p));

      if(mapeamentoRaizGrupo[raiz] == NULL) {
        tGrupo* novoGrupo = criarGrupo();
        mapeamentoRaizGrupo[raiz] = novoGrupo;
        vector_push_back(listaGrupos, novoGrupo);
        }

        adicionarPontoGrupo(mapeamentoRaizGrupo[raiz], p);
      }
      free(mapeamentoRaizGrupo);

      for (int i = 0; i < vector_size(listaGrupos); i++) {
        tGrupo* grupo = (tGrupo*)vector_get(listaGrupos, i);

        vector_sort(grupo->pontosGrupo, comparaNomePontos);
        tPonto* primeiroPonto = (tPonto*)vector_get(grupo->pontosGrupo, 0);
        grupo->primeiroElementoNome = strdup(getNomePonto(primeiroPonto));
  }

  vector_sort(listaGrupos, comparaGruposPrimeiroElemento);

  //escrever a saída aqqq
  for (int i = 0; i < vector_size(listaGrupos); i++) {
        tGrupo* grupo = (tGrupo*)vector_get(listaGrupos, i);
        for (int j = 0; j < vector_size(grupo->pontosGrupo); j++) {
            tPonto* p = (tPonto*)vector_get(grupo->pontosGrupo, j);
           // fprintf     getNomePonto(p)n lembro o formato
        }
        fprintf(arqSaida, "\n");
    }

  for (int i = 0; i < vector_size(listaGrupos); i++) {
        destruirGrupo((tGrupo*)vector_get(listaGrupos, i));
    }
  
      vector_destroy(listaGrupos);
   // fclose(arqSaida);
  }