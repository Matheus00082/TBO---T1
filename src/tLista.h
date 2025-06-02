#ifndef TLISTA_H
#define TLISTA_H

#include "tNo.h"
#include "tVector.h"

typedef unsigned int bool;

typedef struct tLista tLista;

// typedef struct tIterador {
//   tNo *current;
// } tIterador;

tLista *constroiLista();

int tamanhoLista(tLista *l);

void decListaTamanho(tLista *l);

void insereFrenteLista(tLista *l, informacao dado);

void insereAtrasLista(tLista *l, informacao dado);

void imprimeLista(tLista *l, void (*funcaoImpressao)(informacao));

tNo *retornaNo(tLista *l, int i);

informacao removeUltimoItem(tLista *l);

void concatenaListas(tLista *l1, tLista *l2);

tVector *listaParaVector(tLista *l);

void destroiLista(tLista *l);

/*tIterador *tLista_front_iterator(tLista *l);

tIterador *tLista_back_iterator(tLista *l);

informacao *tLista_iterator_next(tIterador *it);

informacao *tLista_iterator_previous(tIterador *it);

bool tLista_iterator_is_over(tIterador *it);

void tLista_iterator_destroy(tIterador *it);*/

#endif