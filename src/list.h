#ifndef _DOUBLE_LINKED_LISTA_H_
#define _DOUBLE_LINKED_LISTA_H_

#include "node.h"

typedef unsigned int bool;

typedef struct tLista tLista;

typedef struct tIterador
{
  tNode *current;
} tIterador;

tLista *construtorLista();

int tamanhoLista(tLista *l);

void dec_tLista_size(tLista *l);

void insereListaFrente(tLista *l, informacao data);

void insereListaAtras(tLista *l, informacao data);

void imprimiLista(tLista *l, void (*print_fn)(informacao));

informacao retornaItem(tLista *l, int i);

informacao removeUltimoItem(tLista *l);

void ordenaLista(tLista *l);

void destroiLista(tLista *l);

/*tIterador *tLista_front_iterator(tLista *l);

tIterador *tLista_back_iterator(tLista *l);

informacao *tLista_iterator_next(tIterador *it);

informacao *tLista_iterator_previous(tIterador *it);

bool tLista_iterator_is_over(tIterador *it);

void tLista_iterator_destroy(tIterador *it);*/

#endif