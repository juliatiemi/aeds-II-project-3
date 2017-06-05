#include "TADbt.h"

Arvore* criaArvore(Elemento *r) {
  Arvore *nova;
  nova = calloc(1 , sizeof(Arvore));
  nova->esq = NULL;
  nova->dir = NULL;
  nova->reg = criaAluno(r->nome, r->matricula);
  return nova;
}

void insereElemento(Arvore *t, Elemento *n) {
  Arvore *novo;
  if(n->matricula < t->reg->matricula) {
    if(t->esq) {
      insereElemento(t->esq, n);
    }
    else {
      novo = criaArvore(n);
      t->esq = novo;
    }
  }
  else if(n->matricula > t->reg->matricula) {
    if(t->dir) {
      insereElemento(t->dir, n);
    }
    else {
      novo = criaArvore(n);
      t->dir = novo;
    }
  }
}

void imprimeArvore(Arvore *t, FILE *arq) {
  if(t != NULL) {
    imprimeArvore(t->esq, arq);
    imprimeAluno(t->reg, arq);
    imprimeArvore(t->dir, arq);
  }
}

void apagaArvore(Arvore *t) {
  if(t != NULL) {
    apagaArvore(t->esq);
    apagaAluno(t->reg);
    apagaArvore(t->dir);
    free(t);
  }
}
