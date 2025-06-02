#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tNo.h"

tNo *constroiNo(informacao value, tNo *anterior, tNo *proximo) {
  tNo *n = (tNo *)calloc(1, sizeof(tNo));
  n->value = value;
  n->proximo = proximo;
  n->anterior = anterior;
  return n;
}

void destroiNo(tNo *n) {
  if (n) {
    free(n);
  }
}