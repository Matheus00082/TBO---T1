#ifndef NO_H
#define NO_H

typedef void* informacao;

typedef struct tNo {
  informacao value;
  struct tNo *anterior;
  struct tNo *proximo;
} tNo;

tNo *constroiNo(informacao value, tNo *anterior, tNo *proximo);
void destroiNo(tNo *n);

#endif