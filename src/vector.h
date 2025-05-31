
#ifndef _DATA_STRUCTURES_VECTOR_H_
#define _DATA_STRUCTURES_VECTOR_H_

typedef void* data_type;
typedef struct Vector Vector;

// Cria um vetor vazio
Vector *vector_construct();

// Adiciona um elemento no final do vetor
void vector_push_back(Vector *v, data_type val);

// Retorna o i-ésimo elemento do vetor
data_type vector_get(Vector *v, int i);

// Retorna o tamanho do vetor
int vector_size(Vector *v);

// Ordena o vetor in-place (sem criar um novo vetor)
void vector_sort(Vector *v, int (*compare)(const void*, const void*));

// Libera a memoria alocada para o vetor
void vector_destroy(Vector *v);

#endif