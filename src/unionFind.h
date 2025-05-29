#ifndef UNIONFIND_H
#define UNIONFIND_H

int *iniciarVetorMapa(int qtdPontos);
void destruirVetorMapa(int *vetorMapa);
void uniao(int *vetorMapa, int idxPonto1, int idxPonto2, int *qtdConexoes);
int encontra(int *vetorMapa, int idxPonto);
int verificaSePontosConectados(int *vetorMapa, int idxPonto1, int idxPonto2);

#endif