#ifndef TARESTA_H
#define TARESTA_H

#include "tPonto.h"
#include "tVector.h"

typedef struct tAresta tAresta;

/**
 * @brief Cria as arestas entre todos os pontos fornecidos.
 * 
 * @param pontos Vetor contendo os pontos.
 * @param qtdCoord Quantidade de coordenadas de cada ponto.
 * @return tVector* Vetor contendo as arestas criadas.
 */
tVector *criarArestas(tVector *pontos, int qtdCoord);

/**
 * @brief Libera a memória alocada para as arestas.
 * 
 * @param arestas Vetor contendo as arestas a serem destruídas.
 */
void destroiArestas(tVector *arestas);

/**
 * @brief Cria uma aresta entre dois pontos com um peso associado.
 * 
 * @param idxPonto1 Índice do primeiro ponto.
 * @param idxPonto2 Índice do segundo ponto.
 * @param peso Peso da aresta.
 * @return tAresta* Ponteiro para a aresta criada.
 */
tAresta *criarAresta(int idxPonto1, int idxPonto2, double peso);

/**
 * @brief Compara duas arestas com base em seus pesos.
 * 
 * @param arestaA Ponteiro para a primeira aresta.
 * @param arestaB Ponteiro para a segunda aresta.
 * @return int Resultado da comparação: negativo, zero ou positivo.
 */
int comparaAresta(const void *arestaA, const void *arestaB);

/**
 * @brief Retorna o índice do primeiro ponto de uma aresta.
 * 
 * @param a Ponteiro para a aresta.
 * @return int Índice do primeiro ponto.
 */
int retornaIdxPonto1(tAresta *a);

/**
 * @brief Retorna o índice do segundo ponto de uma aresta.
 * 
 * @param a Ponteiro para a aresta.
 * @return int Índice do segundo ponto.
 */
int retornaIdxPonto2(tAresta *a);

/**
 * @brief Retorna o peso de uma aresta.
 * 
 * @param a Ponteiro para a aresta.
 * @return double Peso da aresta.
 */
double retornaPeso(tAresta *a);

#endif