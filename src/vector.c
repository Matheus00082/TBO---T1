#include <stdio.h>
#include <stdlib.h>

#include "vector.h"

struct Vector
{
    data_type *data;
    int size;
    int allocated;
};

Vector *vector_construct() {
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->data = (data_type *)malloc(sizeof(data_type));
    v->size = 0;
    v->allocated = 1;

    return v;
}

void vector_push_back(Vector *v, data_type val) {
    if (v->size >= v->allocated) {
        v->allocated *= 2;
        v->data = (data_type *)realloc(v->data, v->allocated * sizeof(data_type));
    }
    v->data[v->size] = val;
    v->size++;
}

data_type vector_get(Vector *v, int i) {
    if (i >= 0 && i < v->size) {
        return v->data[i];
    }
    exit(printf("Erro ao acessar a posicao %d no vetor\n", i));
}

int vector_size(Vector *v) {
    return v->size;
}

void vector_sort(Vector *v, int (*compare)(const void*, const void*)) {
    qsort(v->data, v->size, sizeof(data_type), compare);
}

void vector_destroy(Vector *v) {
    if (v != NULL) {
        if (v->data != NULL) {
            free(v->data);
        }
        free(v);
    }
}
