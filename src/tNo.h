#ifndef TNO_H
#define TNO_H

typedef void* informacao;

/**
 * @brief Estrutura que representa um nó de uma lista duplamente encadeada.
 * 
 * Contém um valor genérico, um ponteiro para o nó anterior e um ponteiro para o próximo nó.
 */
typedef struct tNo {
  informacao value;      
  struct tNo *anterior;   
  struct tNo *proximo;  
} tNo;

/**
 * @brief Constrói um nó com o valor e os ponteiros fornecidos.
 * 
 * @param value Valor a ser armazenado no nó.
 * @param anterior Ponteiro para o nó anterior.
 * @param proximo Ponteiro para o próximo nó.
 * @return tNo* Ponteiro para o nó criado.
 */
tNo *constroiNo(informacao value, tNo *anterior, tNo *proximo);

/**
 * @brief Libera a memória alocada para um nó.
 * 
 * @param n Ponteiro para o nó a ser destruído.
 */
void destroiNo(tNo *n);

#endif