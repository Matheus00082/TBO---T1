#ifndef TPONTO_H
#define TPONTO_H

typedef struct tPonto tPonto;

tPonto *ponto(char *nome, double *coordenadas, int qtdCoord);
void destruirPonto(tPonto *p);
char *nomePonto(tPonto *p);
double *coordenadasPonto(tPonto *p);
double distanciaEuclidiana(tPonto *p1, tPonto *p2, int qtdCoord);

#endif