#ifndef TLISTA_H
#define TLISTA_H

#include "tNo.h"
#include "tVector.h"

typedef unsigned int bool;

typedef struct tLista tLista;

/**
 * @brief Constrói uma lista duplamente encadeada vazia.
 * 
 * @return tLista* Ponteiro para a lista criada.
 */
tLista *constroiLista();

/**
 * @brief Retorna o tamanho atual da lista.
 * 
 * @param l Ponteiro para a lista.
 * @return int Tamanho da lista.
 */
int tamanhoLista(tLista *l);

/**
 * @brief Insere um elemento no início da lista.
 * 
 * @param l Ponteiro para a lista.
 * @param dado Valor a ser inserido na lista.
 */
void insereFrenteLista(tLista *l, informacao dado);

/**
 * @brief Insere um elemento no final da lista.
 * 
 * @param l Ponteiro para a lista.
 * @param dado Valor a ser inserido na lista.
 */
void insereAtrasLista(tLista *l, informacao dado);

/**
 * @brief Retorna o nó em uma posição específica da lista.
 * 
 * @param l Ponteiro para a lista.
 * @param i Índice do nó a ser retornado.
 * @return tNo* Ponteiro para o nó na posição especificada.
 */
tNo *retornaNo(tLista *l, int i);

/**
 * @brief Obtém o primeiro item da lista.
 * 
 * @param l Ponteiro para a lista.
 * @return informacao Primeiro item da lista.
 */
informacao getPrimeiroItem(tLista *l);

/**
 * @brief Remove o último item da lista.
 * 
 * @param l Ponteiro para a lista.
 * @return informacao Último item removido da lista.
 */
informacao removeUltimoItem(tLista *l);

/**
 * @brief Concatena duas listas, adicionando os elementos da segunda lista ao final da primeira.
 * 
 * @param l1 Ponteiro para a primeira lista.
 * @param l2 Ponteiro para a segunda lista.
 */
void concatenaListas(tLista *l1, tLista *l2);

/**
 * @brief Converte uma lista em um vetor.
 * 
 * @param l Ponteiro para a lista.
 * @return tVector* Ponteiro para o vetor criado a partir da lista.
 */
tVector *listaParaVector(tLista *l);

/**
 * @brief Libera a memória alocada para a lista e seus nós.
 * 
 * @param l Ponteiro para a lista a ser destruída.
 */
void destroiLista(tLista *l);

#endif