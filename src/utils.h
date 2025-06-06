#include "tAresta.h"
#include "tPonto.h"
#include "tUnionFind.h"
#include "tVector.h"
#include "tLista.h"

/**
 * @brief Cria um ponto a partir de um token e suas coordenadas.
 * 
 * @param token String contendo o nome do ponto e suas coordenadas separadas por vírgulas.
 * @param qtdCoord Ponteiro para armazenar a quantidade de coordenadas do ponto.
 * @return tPonto* Ponteiro para o ponto criado.
 */
tPonto *criarPonto(char *token, int *qtdCoord);

/**
 * @brief Realiza o agrupamento máximo de pontos em k grupos.
 * 
 * @param arestas Vetor contendo as arestas entre os pontos.
 * @param pontos Vetor contendo os pontos a serem agrupados.
 * @param kGrupos Número de grupos desejados.
 * @param nomeArquivoSaida Nome do arquivo onde os grupos serão salvos.
 */
void agrupamentoMaximo(tVector *arestas, tVector *pontos, int kGrupos, const char *nomeArquivoSaida);

/**
 * @brief Inicializa os grupos com cada ponto em um grupo separado.
 * 
 * @param pontos Vetor contendo os pontos a serem agrupados.
 * @return tVector* Vetor contendo os grupos inicializados.
 */
tVector *inicializaGrupos(tVector *pontos);

/**
 * @brief Imprime os grupos em um arquivo de saída.
 * 
 * @param grupos Vetor contendo os grupos a serem impressos.
 * @param nomeArquivoSaida Nome do arquivo onde os grupos serão salvos.
 * @param kGrupos Número de grupos a serem impressos.
 */
void imprimeGrupos(tVector *grupos, const char *nomeArquivoSaida, int kGrupos);

/**
 * @brief Compara os primeiros pontos de dois grupos.
 * 
 * @param grupoA Ponteiro para o primeiro grupo.
 * @param grupoB Ponteiro para o segundo grupo.
 * @return int Resultado da comparação: negativo, zero ou positivo.
 */
int comparaPrimeiroPontoDoGrupo(const void *grupoA, const void *grupoB);

/**
 * @brief Destroi os grupos, liberando a memória alocada.
 * 
 * @param grupos Vetor contendo os grupos a serem destruídos.
 */
void destruirGrupos(tVector *grupos);