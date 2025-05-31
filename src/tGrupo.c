#include "tGrupo.h"
#include <string.h> 
#include <stdio.h> 

typedef struct {
    Vector* pontosGrupo; 
    char* primeiroElementoNome;
} tGrupo;


tGrupo* criarGrupo() {
    tGrupo* novoGrupo = (tGrupo*) malloc(sizeof(tGrupo));

    novoGrupo->pontosGrupo = vector_construct();
    novoGrupo->primeiroElementoNome = NULL;
    return novoGrupo;
}

void adicionarPontoGrupo(tGrupo* grupo, tPonto* ponto) {
    vector_push_back(grupo->pontosDoGrupo, ponto);
}

void destruirGrupo(tGrupo* grupo) {
    if (grupo == NULL) {
        return;
    }

    if (grupo->primeiroElementoNome != NULL) {
        free(grupo->primeiroElementoNome);
        grupo->primeiroElementoNome = NULL;
    }

    vector_destroy(grupo->pontosDoGrupo);
    grupo->pontosDoGrupo = NULL;

    free(grupo);
}