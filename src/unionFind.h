#ifndef UNIONFIND_H
#define UNIONFIND_H

typedef struct tUnionFind tUnionFind;

tUnionFind *criarUnionFind(int qtdPontos);
void destruirUnionFind(tUnionFind *uf);
void uniao(tUnionFind *uf, int idxPonto1, int idxPonto2);
int encontra(tUnionFind *uf, int idxPonto);
int verificaSePontosConectados(tUnionFind *uf, int idxPonto1, int idxPonto2);
int getVetorMapa(tUnionFind *uf, int i);

#endif