#ifndef TPONTO_H
#define TPONTO_H

#include "tVector.h"
#include <stdio.h>

typedef struct tPonto tPonto;

/**
 * @brief Cria um ponto com nome e coordenadas.
 * 
 * @param nome Nome do ponto.
 * @param coordenadas Vetor de coordenadas do ponto.
 * @param qtdCoord Quantidade de coordenadas.
 * @return tPonto* Ponteiro para o ponto criado.
 */
tPonto *ponto(char *nome, double *coordenadas, int qtdCoord);

/**
 * @brief Compara dois pontos com base em seus nomes.
 * 
 * @param pontoA Ponteiro para o primeiro ponto.
 * @param pontoB Ponteiro para o segundo ponto.
 * @return int Resultado da comparação: negativo, zero ou positivo.
 */
int comparaPontos(const void *pontoA, const void *pontoB);

/**
 * @brief Libera a memória alocada para um ponto.
 * 
 * @param p Ponteiro para o ponto a ser destruído.
 */
void destroiPonto(tPonto *p);

/**
 * @brief Libera a memória alocada para um vetor de pontos.
 * 
 * @param pontos Ponteiro para o vetor de pontos a ser destruído.
 */
void destroiPontos(tVector *pontos);

/**
 * @brief Obtém o nome de um ponto.
 * 
 * @param p Ponteiro para o ponto.
 * @return char* Nome do ponto.
 */
char *nomePonto(tPonto *p);

/**
 * @brief Obtém as coordenadas de um ponto.
 * 
 * @param p Ponteiro para o ponto.
 * @return double* Vetor de coordenadas do ponto.
 */
double *coordenadasPonto(tPonto *p);

/**
 * @brief Calcula a distância euclidiana entre dois pontos.
 * 
 * @param p1 Ponteiro para o primeiro ponto.
 * @param p2 Ponteiro para o segundo ponto.
 * @param qtdCoord Quantidade de coordenadas.
 * @return double Distância euclidiana entre os dois pontos.
 */
double distanciaEuclidiana(tPonto *p1, tPonto *p2, int qtdCoord);

/**
 * @brief Imprime o nome de um ponto em um arquivo de saída.
 * 
 * @param p Ponteiro para o ponto.
 * @param arquivoSaida Ponteiro para o arquivo onde o nome será impresso.
 */
void imprimeNomePonto(void *p, FILE *arquivoSaida);

#endif