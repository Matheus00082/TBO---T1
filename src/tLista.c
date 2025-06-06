#include <stdio.h>
#include <stdlib.h>
#include "tLista.h"

struct tLista {
  tNo *primeiro;
  tNo *ultimo;
  int tamanho;
};

tLista *constroiLista() {
  tLista *l = (tLista *)malloc(sizeof(tLista));
  l->primeiro = NULL;
  l->ultimo = NULL;
  l->tamanho = 0;
  return l;
}

int tamanhoLista(tLista *l) {
  return l->tamanho;
}

void insereFrenteLista(tLista *l, informacao dado) {
  tNo *novoNo = constroiNo(dado, NULL, l->primeiro);

  if (l->primeiro == NULL) {
    l->ultimo = l->primeiro = novoNo;
  }
  else {
    l->primeiro = l->primeiro->anterior = novoNo;
  }

  l->tamanho++;
}

void insereAtrasLista(tLista *l, informacao dado) {
  tNo *novoNo = constroiNo(dado, l->ultimo, NULL);

  if (l->ultimo == NULL) {
    l->primeiro = l->ultimo = novoNo;
  }
  else {
    l->ultimo = l->ultimo->proximo = novoNo;
  }

  l->tamanho++;
}

tNo *retornaNo(tLista *l, int i) {
  if (i < 0 && i < l->tamanho) {
    exit(printf("Índice inválido\n"));
  }

  tNo *no = l->primeiro;

  for (int idx = 0; idx < i; idx++) {
    no = no->proximo;
  }

  return no;
}

informacao getPrimeiroItem(tLista *l) {
  if (l->primeiro) {
    return l->primeiro;
  }

  return NULL;
}

informacao removeUltimoItem(tLista *l) {
  tNo *tNode_destruct = l->ultimo;

  if (l->primeiro == NULL) {
    exit(printf("A tListaa está vazia\n"));
  }
  informacao data = tNode_destruct->value;
  l->ultimo = l->ultimo->anterior;

  if (l->ultimo != NULL) {
    l->ultimo->proximo = NULL;
  }
  else {
    l->primeiro = l->ultimo;
  }

  destroiNo(tNode_destruct);
  l->tamanho--;
  return data;
}

void concatenaListas(tLista *l1, tLista *l2) {
  if (l2->primeiro == NULL) {
    return;
  }

  if (l1->primeiro == NULL) {
    l1->primeiro = l2->primeiro;
    l1->ultimo = l2->ultimo;
    l1->tamanho = l2->tamanho;
  }
  else {
    l1->ultimo->proximo = l2->primeiro;
    l1->ultimo = l2->ultimo;
    l1->tamanho += l2->tamanho;
  }

  l2->primeiro = NULL;
  l2->ultimo = NULL;
  l2->tamanho = 0;
}

tVector *listaParaVector(tLista *l) {
  if (!l || l->tamanho == 0) {
    return NULL;
  }

  tVector *v = constroiVector(l->tamanho);
  tNo *atual = l->primeiro;

  for (int i = 0; i < l->tamanho; i++) {
    insereAtrasVector(v, atual->value);
    atual = atual->proximo;
  }

  return v;
}

void destroiLista(tLista *l) {
  if (l) {
    while (l->primeiro != NULL) {
      tNo *noDestruido = l->primeiro;
      l->primeiro = l->primeiro->proximo;
      destroiNo(noDestruido);
    }

    free(l);
  }
}

