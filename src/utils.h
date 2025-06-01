#include "tAresta.h"
#include "tPonto.h"
#include "unionFind.h"
#include "vector.h"
#include "list.h"

tPonto *criarPonto(char *token, int *qtdCoord);
void agrupamentoMaximo(Vector *arestas, Vector *pontos, int kGrupos);
Vector *inicializaGrupos(Vector *pontos);
void destruirGrupos(Vector *grupos);