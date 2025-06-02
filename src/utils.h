#include "tAresta.h"
#include "tPonto.h"
#include "unionFind.h"
#include "tVector.h"
#include "tLista.h"

tPonto *criarPonto(char *token, int *qtdCoord);
void agrupamentoMaximo(tVector *arestas, tVector *pontos, int kGrupos);
tVector *inicializaGrupos(tVector *pontos);
void imprimeGrupos(tVector *grupos);
void destruirGrupos(tVector *grupos);