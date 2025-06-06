#ifndef TUNIONFIND_H
#define TUNIONFIND_H

#include "tVector.h"
#include "tLista.h"

typedef struct tUnionFind tUnionFind;

/**
 * @brief Cria uma estrutura de Union-Find para gerenciar conjuntos disjuntos.
 * 
 * @param qtdPontos Número de pontos a serem gerenciados.
 * @return tUnionFind* Ponteiro para a estrutura de Union-Find criada.
 */
tUnionFind *criarUnionFind(int qtdPontos);

/**
 * @brief Libera a memória alocada para a estrutura de Union-Find.
 * 
 * @param uf Ponteiro para a estrutura de Union-Find a ser destruída.
 */
void destruirUnionFind(tUnionFind *uf);

/**
 * @brief Realiza a união de dois conjuntos disjuntos.
 * 
 * @param uf Ponteiro para a estrutura de Union-Find.
 * @param idxPonto1 Índice do primeiro ponto.
 * @param idxPonto2 Índice do segundo ponto.
 * @param grupos Vetor contendo os grupos de pontos.
 */
void uniao(tUnionFind *uf, int idxPonto1, int idxPonto2, tVector *grupos);

/**
 * @brief Encontra o representante (raiz) do conjunto ao qual um ponto pertence.
 * 
 * @param uf Ponteiro para a estrutura de Union-Find.
 * @param idxPonto Índice do ponto a ser buscado.
 * @return int Índice do representante do conjunto.
 */
int encontra(tUnionFind *uf, int idxPonto);

/**
 * @brief Verifica se dois pontos pertencem ao mesmo conjunto.
 * 
 * @param uf Ponteiro para a estrutura de Union-Find.
 * @param idxPonto1 Índice do primeiro ponto.
 * @param idxPonto2 Índice do segundo ponto.
 * @return int Retorna 1 se os pontos estão conectados, 0 caso contrário.
 */
int verificaSePontosConectados(tUnionFind *uf, int idxPonto1, int idxPonto2);

#endif