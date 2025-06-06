#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/**
 * @brief Cria um ponto a partir de um token e suas coordenadas.
 * 
 * O token contém o nome do ponto e suas coordenadas separadas por vírgulas.
 * As coordenadas são extraídas e armazenadas em um vetor dinâmico.
 */
tPonto *criarPonto(char *token, int *qtdCoord) {
  int qtdCoordAlocadas = 2;
  *qtdCoord = 0;
  char *nome = token; // O primeiro token é o nome do ponto.
  token = strtok(NULL, ","); // Avança para o próximo token.
  double *coordenadas = (double *)calloc(qtdCoordAlocadas, sizeof(double));

  while (token != NULL) {
    if (*qtdCoord >= qtdCoordAlocadas) {
      qtdCoordAlocadas *= 2;
      coordenadas = (double *)realloc(coordenadas, qtdCoordAlocadas * sizeof(double));
    }

    // Converte o token para double e armazena no vetor de coordenadas.
    coordenadas[(*qtdCoord)++] = atof(token);
    token = strtok(NULL, ",");
  }

  // Cria o ponto com o nome e as coordenadas extraídas.
  tPonto *pontoAtual = ponto(nome, coordenadas, *qtdCoord);
  free(coordenadas); // Libera o vetor de coordenadas temporário.
  return pontoAtual;
}

/**
 * @brief Realiza o agrupamento máximo de pontos em k grupos.
 * 
 * Utiliza a estrutura Union-Find para conectar os pontos com base nas arestas.
 */
void agrupamentoMaximo(tVector *arestas, tVector *pontos, int kGrupos, const char *nomeArquivoSaida) {
  int qtdPontos = tamanhoVector(pontos), arestasPercorridas = 0, conexoesFeitas = 0;
  tUnionFind *uf = criarUnionFind(qtdPontos); // Inicializa a estrutura Union-Find.
  tVector *grupos = inicializaGrupos(pontos); // Inicializa cada ponto em um grupo separado.

  // Conecta os pontos até que restem k grupos.
  while (conexoesFeitas < qtdPontos - kGrupos) {
    int idxPonto1 = retornaIdxPonto1(getElementoVector(arestas, arestasPercorridas));
    int idxPonto2 = retornaIdxPonto2(getElementoVector(arestas, arestasPercorridas));

    // Verifica se os pontos já estão conectados.
    if (!verificaSePontosConectados(uf, idxPonto1, idxPonto2)) {
      uniao(uf, idxPonto1, idxPonto2, grupos); // Conecta os pontos.
      conexoesFeitas++;
    }

    arestasPercorridas++;
  }

  // Imprime os grupos resultantes no arquivo de saída.
  imprimeGrupos(grupos, nomeArquivoSaida, kGrupos);
  destruirUnionFind(uf);
  destruirGrupos(grupos); 
}

/**
 * @brief Inicializa os grupos com cada ponto em um grupo separado.
 * 
 * Cada ponto é colocado em uma lista separada, que é armazenada em um vetor.
 */
tVector *inicializaGrupos(tVector *pontos) {
  int qtdPontos = tamanhoVector(pontos);
  tVector *grupos = constroiVector(qtdPontos); // Cria um vetor para armazenar os grupos.
  
  for (int i = 0; i < qtdPontos; i++) {
    tLista *lista = constroiLista(); // Cria uma lista para o grupo.
    insereAtrasLista(lista, getElementoVector(pontos, i)); // Adiciona o ponto à lista.
    insereAtrasVector(grupos, lista); // Adiciona a lista ao vetor de grupos.
  }

  return grupos;
}

/**
 * @brief Compara os primeiros pontos de dois grupos.
 * 
 * A comparação é feita com base nos nomes dos pontos.
 */
int comparaPrimeiroPontoDoGrupo(const void *grupoA, const void *grupoB) {
  tVector *grupoAVector = *(tVector **)grupoA;
  tVector *grupoBVector = *(tVector **)grupoB;
  tPonto *primeiroPontoA = (tPonto *)getElementoVector(grupoAVector, 0);
  tPonto *primeiroPontoB = (tPonto *)getElementoVector(grupoBVector, 0);
  return comparaPontos(&primeiroPontoA, &primeiroPontoB);
}

/**
 * @brief Imprime os grupos em um arquivo de saída.
 * 
 * Os grupos são ordenados e seus elementos são impressos no arquivo.
 */
void imprimeGrupos(tVector *grupos, const char *nomeArquivoSaida, int kGrupos) {
  int qtdGrupos = tamanhoVector(grupos);
  tVector *gruposParaImprimir = constroiVector(kGrupos);

  // Converte as listas de grupos em vetores e ordena os elementos.
  for (int i = 0; i < qtdGrupos; i++) {
    tLista *l = (tLista *)getElementoVector(grupos, i);

    if (tamanhoLista(l) > 0) {
      tVector *v = listaParaVector(l);
      ordenaVector(v, comparaPontos); // Ordena os pontos no grupo.
      insereAtrasVector(gruposParaImprimir, v);
    }
  }

  // Ordena os grupos com base no primeiro ponto de cada grupo.
  ordenaVector(gruposParaImprimir, comparaPrimeiroPontoDoGrupo);
  FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");

  // Imprime os grupos no arquivo de saída.
  for (int i = 0; i < kGrupos; i++) {
    imprimeVector(getElementoVector(gruposParaImprimir, i), imprimeNomePonto, arquivoSaida);
    destroiVector(getElementoVector(gruposParaImprimir, i)); // Libera a memória do vetor do grupo.
  }

  fclose(arquivoSaida);
  destroiVector(gruposParaImprimir); // Libera a memória do vetor de grupos.
}

/**
 * @brief Destroi os grupos, liberando a memória alocada.
 * 
 * Cada lista de grupo é destruída, seguida pela destruição do vetor de grupos.
 */
void destruirGrupos(tVector *grupos) {
  int qtdGrupos = tamanhoVector(grupos);

  for (int i = 0; i < qtdGrupos; i++) {
    destroiLista(getElementoVector(grupos, i)); // Libera a memória de cada lista.
  }

  destroiVector(grupos); // Libera a memória do vetor de grupos.
}