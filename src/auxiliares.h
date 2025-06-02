#ifndef AUXILIARES_H
#define AUXILIARES_H

#include "vector.h"
#include "tPonto.h"
#include "unionFind.h"
#include "tAresta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


tPonto *criarPonto(char *token, int *qtdCoord);
void agrupamentoMaximo(Vector *arestas, Vector *pontos, int kGrupos, const char *arquivoSaida);
void imprimeGrupos(int *vetorMapa, Vector *pontos, int kGrupos, const char *arquivoSaida);

#endif