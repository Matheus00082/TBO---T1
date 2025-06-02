#ifndef UNIONFIND_H
#define UNIONFIND_H

#include "tVector.h"
#include "tLista.h"
#include <stdio.h>

typedef struct tUnionFind tUnionFind;

tUnionFind *criarUnionFind(int qtdPontos);
void destruirUnionFind(tUnionFind *uf);
void uniao(tUnionFind *uf, int idxPonto1, int idxPonto2, tVector *grupos);
int encontra(tUnionFind *uf, int idxPonto);
int verificaSePontosConectados(tUnionFind *uf, int idxPonto1, int idxPonto2);
int getVetorMapa(tUnionFind *uf, int i);

#endif