#ifndef TVECTOR_H
#define TVECTOR_H

typedef void* informacao;
typedef struct tVector tVector;
#include <stdio.h>

/**
 * @brief Constrói um vetor com uma quantidade inicial de elementos.
 * 
 * @param qtdElementos Quantidade inicial de elementos a serem alocados.
 * @return tVector* Ponteiro para o vetor criado.
 */
tVector *constroiVector(int qtdElementos);

/**
 * @brief Insere um elemento no final do vetor.
 * 
 * @param v Ponteiro para o vetor.
 * @param val Valor a ser inserido no vetor.
 */
void insereAtrasVector(tVector *v, informacao val);

/**
 * @brief Obtém um elemento do vetor em uma posição específica.
 * 
 * @param v Ponteiro para o vetor.
 * @param i Índice do elemento a ser obtido.
 * @return informacao Elemento na posição especificada.
 */
informacao getElementoVector(tVector *v, int i);

/**
 * @brief Retorna o tamanho atual do vetor.
 * 
 * @param v Ponteiro para o vetor.
 * @return int Tamanho do vetor.
 */
int tamanhoVector(tVector *v);

/**
 * @brief Remove um elemento do vetor em uma posição específica.
 * 
 * @param v Ponteiro para o vetor.
 * @param i Índice do elemento a ser removido.
 * @return informacao Elemento removido.
 */
informacao removeElementoVector(tVector *v, int i);

/**
 * @brief Remove o último elemento do vetor.
 * 
 * @param v Ponteiro para o vetor.
 * @return informacao Último elemento removido.
 */
informacao removeAtrasVector(tVector *v);

/**
 * @brief Ordena os elementos do vetor usando uma função de comparação.
 * 
 * @param v Ponteiro para o vetor.
 * @param compare Função de comparação para ordenar os elementos.
 */
void ordenaVector(tVector *v, int (*compare)(const void *, const void *));

/**
 * @brief Imprime os elementos do vetor em um arquivo de saída.
 * 
 * @param v Ponteiro para o vetor.
 * @param funcaoImpressao Função para imprimir cada elemento.
 * @param arquivoSaida Ponteiro para o arquivo onde os elementos serão impressos.
 */
void imprimeVector(tVector *v, void (*funcaoImpressao)(informacao, FILE*), FILE *arquivoSaida);

/**
 * @brief Libera a memória alocada para o vetor.
 * 
 * @param v Ponteiro para o vetor a ser destruído.
 */
void destroiVector(tVector *v);

#endif