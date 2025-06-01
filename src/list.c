#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct List {
  Node *head;
  Node *last;
  int size;
};

List *list_construct() {
  List *list = (List *)malloc(sizeof(List));

  list->head = NULL;
  list->last = NULL;
  list->size = 0;

  return list;
}

int list_size(List *l) {
  return l->size;
}

void dec_list_size(List *l) {
  l->size--;
}

void list_print(List *l, void (*print_fn)(data_type)) {
  Node *node = l->head;

  printf("[");

  while (node != NULL) {
    print_fn(node->value);

    if (node->next != NULL) {
      printf(", ");
    }
    node = node->next;
  }

  printf("]");
}

void list_destroy(List *l) {
  if (l) {
    while (l->head != NULL) {
      Node *node_destruct = l->head;
      l->head = l->head->next;
      node_destroy(node_destruct);
    }

    free(l);
  }
}

void list_push_front(List *l, data_type data) {
  Node *new_node = node_construct(data, NULL, l->head);

  if (l->head == NULL) {
    l->last = l->head = new_node;
  }
  else {
    l->head = l->head->prev = new_node;
  }

  l->size++;
}

data_type list_pop_front(List *l) {
  Node *node_destruct = l->head;

  if (node_destruct == NULL) {
    exit(printf("A lista está vazia\n"));
  }

  data_type data = node_destruct->value;
  l->head = l->head->next;

  if (l->head != NULL) {
    l->head->prev = NULL;
  }
  else {
    l->last = l->head;
  }

  node_destroy(node_destruct);
  l->size--;
  return data;
}

void list_push_back(List *l, data_type data) {
  Node *new_node = node_construct(data, l->last, NULL);

  if (l->last == NULL) {
    l->head = l->last = new_node;
  }
  else {
    l->last = l->last->next = new_node;
  }

  l->size++;
}

data_type list_pop_back(List *l) {
  Node *node_destruct = l->last;

  if (l->head == NULL) {
    exit(printf("A lista está vazia\n"));
  }
  data_type data = node_destruct->value;
  l->last = l->last->prev;

  if (l->last != NULL) {
    l->last->next = NULL;
  }
  else {
    l->head = l->last;
  }

  node_destroy(node_destruct);
  l->size--;
  return data;
}

Node *list_get_node(List *l, int i) {
  if (i < 0 && i < l->size) {
    exit(printf("Índice inválido\n"));
  }

  Node *node = l->head;

  for (int idx = 0; idx < i; idx++) {
    node = node->next;
  }

  return node;
}

void list_cat(List *l1, List *l2) {
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

ListIterator *list_front_iterator(List *l) {
  ListIterator *iterator = (ListIterator *)malloc(sizeof(ListIterator));
  iterator->current = l->head;
  return iterator;
}

ListIterator *list_back_iterator(List *l) {
  ListIterator *iterator = (ListIterator *)malloc(sizeof(ListIterator));
  iterator->current = l->last;
  return iterator;
}

bool list_iterator_is_over(ListIterator *it) {
  if (it->current == NULL) {
    return 1;
  }

  return 0;
}

data_type *list_iterator_previous(ListIterator *it) {
  if (!list_iterator_is_over(it)) {
    data_type *data = &(it->current->value);
    it->current = it->current->prev;
    return data;
  }

  return NULL;
}

data_type *list_iterator_next(ListIterator *it) {
  if (!list_iterator_is_over(it)) {
    data_type *data = &(it->current->value);
    it->current = it->current->next;
    return data;
  }

  return NULL;
}

void list_iterator_destroy(ListIterator *it) {
  if (it) {
    free(it);
  }
}