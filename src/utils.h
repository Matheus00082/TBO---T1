#include "tAresta.h"
#include "tPonto.h"
#include "unionFind.h"
#include "tVector.h"
#include "tLista.h"

tPonto *criarPonto(char *token, int *qtdCoord);
void agrupamentoMaximo(tVector *arestas, tVector *pontos, int kGrupos, const char *nomeArquivoSaida );
tVector *inicializaGrupos(tVector *pontos);
void imprimeGrupos(tVector *grupos, const char *nomeArquivoSaida);
void destruirGrupos(tVector *grupos);