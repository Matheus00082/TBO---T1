#ifndef TVECTOR_H
#define TVECTOR_H

typedef void* informacao;
typedef struct tVector tVector;

tVector *constroiVector();

void insereAtrasVector(tVector *v, informacao val);

informacao getElementoVector(tVector *v, int i);

int tamanhoVector(tVector *v);

informacao removeElementoVector(tVector *v, int i);

informacao removeAtrasVector(tVector *v);

void ordenaVector(tVector *v, int (*compare)(const void *, const void *));

void imprimeVector(tVector *v, void (*funcaoImpressao)(informacao));

void destroiVector(tVector *v);

#endif