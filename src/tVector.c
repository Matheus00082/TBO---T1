#include <stdio.h>
#include <stdlib.h>

#include "tVector.h"

struct tVector {
  informacao *dados;
  int tamanho;
  int alocado;
};

tVector *constroiVector() {
  tVector *v = (tVector *)malloc(sizeof(tVector));
  v->dados = (informacao *)malloc(50 * sizeof(informacao));
  v->tamanho = 0;
  v->alocado = 50;
  return v;
}

void insereAtrasVector(tVector *v, informacao val) {
  if (v->tamanho >= v->alocado) {
    v->alocado *= 2;
    v->dados = (informacao *)realloc(v->dados, v->alocado * sizeof(informacao));
  }

  v->dados[v->tamanho] = val;
  v->tamanho++;
}

informacao getElementoVector(tVector *v, int i) {
  if (i >= 0 && i < v->tamanho) {
    return v->dados[i];
  }

  exit(printf("Erro ao acessar a posicao %d no vetor\n", i));
}

int tamanhoVector(tVector *v) {
  return v->tamanho;
}

informacao removeAtrasVector(tVector *v) {
  informacao element_back = removeElementoVector(v, v->tamanho - 1);
  return element_back;
}

void ordenaVector(tVector *v, int (*compare)(const void *, const void *)) {
  qsort(v->dados, v->tamanho, sizeof(informacao), compare);
}

informacao removeElementoVector(tVector *v, int i) {
  if (i < v->alocado) {
    informacao element_remove = v->dados[i];

    for (; i < v->tamanho - 1; i++) {
      v->dados[i] = v->dados[i + 1];
    }

    v->tamanho--;
    return element_remove;
  }
  else {
    printf("Indice de remocao invalido\n");
    exit(1);
  }
}

void destroiVector(tVector *v) {
  if (v != NULL) {
    if (v->dados != NULL) {
      free(v->dados);
    }

    free(v);
  }
}
