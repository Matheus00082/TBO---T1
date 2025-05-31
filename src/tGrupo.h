#ifndef TGRUPO_H
#define TGRUPO_H

#include "vector.h" 
#include "tPonto.h"


tGrupo* criarGrupo();
void adicionarPontoGrupo(tGrupo* grupo, tPonto* ponto);
void destruirGrupo(tGrupo* grupo);

#endif