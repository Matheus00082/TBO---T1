#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct tLista {
  tNode *head;
  tNode *last;
  int size;
};

tLista *tLista_construct() {
  tLista *lista = (tLista *)malloc(sizeof(tLista));

  lista->head = NULL;
  lista->last = NULL;
  lista->size = 0;

  return lista;
}

int tLista_size(tLista *l) {
  return l->size;
}

void dec_tLista_size(tLista *l) {
  l->size--;
}

void tLista_print(tLista *l, void (*print_fn)(informacao)) {
  tNode *tNode = l->head;

  printf("[");

  while (tNode != NULL) {
    print_fn(tNode->value);

    if (tNode->next != NULL) {
      printf(", ");
    }
    tNode = tNode->next;
  }

  printf("]");
}

void tLista_destroy(tLista *l) {
  if (l) {
    while (l->head != NULL) {
      tNode *tNode_destruct = l->head;
      l->head = l->head->next;
      tNode_destroy(tNode_destruct);
    }

    free(l);
  }
}

void tLista_push_front(tLista *l, informacao data) {
  tNode *new_tNode = tNode_construct(data, NULL, l->head);

  if (l->head == NULL) {
    l->last = l->head = new_tNode;
  }
  else {
    l->head = l->head->prev = new_tNode;
  }

  l->size++;
}

informacao tLista_pop_front(tLista *l) {
  tNode *tNode_destruct = l->head;

  if (tNode_destruct == NULL) {
    exit(printf("A tListaa está vazia\n"));
  }

  informacao data = tNode_destruct->value;
void tLista_iterator_destroy(tIterador *it);

  tNode_destroy(tNode_destruct);
  l->size--;
  return data;
}

void tLista_push_back(tLista *l, informacao data) {
  tNode *new_tNode = tNode_construct(data, l->last, NULL);

  if (l->last == NULL) {
    l->head = l->last = new_tNode;
  }
  else {
    l->last = l->last->next = new_tNode;
  }

  l->size++;
}

informacao tLista_pop_back(tLista *l) {
  tNode *tNode_destruct = l->last;

  if (l->head == NULL) {
    exit(printf("A tListaa está vazia\n"));
  }
  informacao data = tNode_destruct->value;
  l->last = l->last->prev;

  if (l->last != NULL) {
    l->last->next = NULL;
  }
  else {
    l->head = l->last;
  }

  tNode_destroy(tNode_destruct);
  l->size--;
  return data;
}

tNode *tLista_get_tNode(tLista *l, int i) {
  if (i < 0 && i < l->size) {
    exit(printf("Índice inválido\n"));
  }

  tNode *tNode = l->head;

  for (int idx = 0; idx < i; idx++) {
    tNode = tNode->next;
  }

  return tNode;
}

void tLista_cat(tLista *l1, tLista *l2) {
  if (l2->head == NULL) {
    return;
  }

  if (l1->head == NULL) {
    l1->head = l2->head;
    l1->last = l2->last;
    l1->size = l2->size;
  }
  else {
    l1->last->next = l2->head;
    l1->last = l2->last;
    l1->size += l2->size;
  }

  l2->head = NULL;
  l2->last = NULL;
  l2->size = 0;
}

/*tIterador *tLista_front_iterator(tLista *l) {
  tIterador *iterator = (tIterador *)malloc(sizeof(tIterador));
  iterator->current = l->head;
  return iterator;
}

tIterador *tLista_back_iterator(tLista *l) {
  tIterador *iterator = (tIterador *)malloc(sizeof(tIterador));
  iterator->current = l->last;
  return iterator;
}

bool tLista_iterator_is_over(tIterador *it) {
  if (it->current == NULL) {
    return 1;
  }

  return 0;
}

informacao *tLista_iterator_previous(tIterador *it) {
  if (!tLista_iterator_is_over(it)) {
    informacao *data = &(it->current->value);
    it->current = it->current->prev;
    return data;
  }

  return NULL;
}

informacao *tLista_iterator_next(tIterador *it) {
  if (!tLista_iterator_is_over(it)) {
    informacao *data = &(it->current->value);
    it->current = it->current->next;
    return data;
  }

  return NULL;
}

void tLista_iterator_destroy(tIterador *it) {
  if (it) {
    free(it);
  }
}*/