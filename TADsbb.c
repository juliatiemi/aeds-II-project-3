#include "TADsbb.h"

ArvoreSBB* criaArvoreSBB(Elemento *r) {
  ArvoreSBB *nova;
  nova = calloc(1 , sizeof(ArvoreSBB));
  nova->reg = r;
  nova->esq = NULL;
  nova->dir = NULL;
  nova->esqtipo = SBB_VERTICAL;
  nova->dirtipo = SBB_VERTICAL;
  return nova;
}

void ee(ArvoreSBB **ptr){
  ArvoreSBB *novo;
  ArvoreSBB *esq;
  novo = *ptr;
  esq = novo->esq;
  novo->esq = esq->dir;
  esq->dir = novo;
  esq->esqtipo = SBB_VERTICAL;
  novo->esqtipo = SBB_VERTICAL;
  *ptr = esq;
}

void dd(ArvoreSBB **ptr){
  ArvoreSBB *novo;
  ArvoreSBB *dir;
  novo = *ptr;
  dir = novo->dir;
  novo->dir = dir->esq;
  dir->esq = novo;
  dir->dirtipo = SBB_VERTICAL;
  novo->dirtipo = SBB_VERTICAL;
  *ptr = dir;
}

void ed(ArvoreSBB **ptr){
  ArvoreSBB *novo;
  ArvoreSBB *esq;
  ArvoreSBB *dir;
  novo = *ptr;
  esq = novo->esq;
  dir = esq->dir;
  esq->dir = dir->esq;
  dir->esq = esq;
  novo->esq = dir->dir;
  dir->dir = novo;
  esq->dirtipo = SBB_VERTICAL;
  novo->esqtipo = SBB_VERTICAL;
  *ptr = dir;
}

void de(ArvoreSBB **ptr){
  ArvoreSBB *novo;
  ArvoreSBB *dir;
  ArvoreSBB *esq;
  novo = *ptr;
  dir = novo->dir;
  esq = dir->esq;
  dir->esq = esq->dir;
  esq->dir = dir;
  novo->dir = esq->esq;
  esq->esq = novo;
  dir->esqtipo = SBB_VERTICAL;
  novo->dirtipo = SBB_VERTICAL;
  *ptr = esq;
}

void iInsereAqui (Elemento *r, ArvoreSBB **ptr, int *incli, int *fim){
  ArvoreSBB *novo;
  novo = calloc(1 , sizeof(ArvoreSBB));
  novo->reg = r;
  novo->esq = NULL;
  novo->dir = NULL;
  novo->esqtipo = SBB_VERTICAL;
  novo->dirtipo = SBB_VERTICAL;
  *ptr = novo;
  *incli = SBB_HORIZONTAL;
  *fim = FALSE;
}

void iInsere (Elemento *r, ArvoreSBB **ptr, int *incli, int *fim){
  if(*ptr == NULL) {
    iInsereAqui(r, ptr, incli, fim);
  }
  else if(r->matricula < (*ptr)->reg->matricula) {
    iInsere(r, &(*ptr)->esq, &(*ptr)->esqtipo, fim);
    if(*fim) {
      return;
    }
    if((*ptr)->esqtipo == SBB_VERTICAL) {
      *fim = TRUE;
    }
    else if((*ptr)->esq->esqtipo == SBB_HORIZONTAL) {
      ee(ptr);
      *incli = SBB_HORIZONTAL;
    }
    else if((*ptr)->esq->dirtipo == SBB_HORIZONTAL) {
      ed(ptr);
      *incli = SBB_HORIZONTAL;
    }
  }
  else if(r->matricula > (*ptr)->reg->matricula) {
    iInsere(r, &(*ptr)->dir, &(*ptr)->dirtipo, fim);
    if(*fim) {
      return;
    }
    if((*ptr)->dirtipo == SBB_VERTICAL) {
      *fim = TRUE;
    }
    else if((*ptr)->dir->dirtipo == SBB_HORIZONTAL) {
      dd(ptr);
      *incli = SBB_HORIZONTAL;
    }
    else if((*ptr)->dir->esqtipo == SBB_HORIZONTAL) {
      de(ptr);
      *incli = SBB_HORIZONTAL;
    }
    else if(r->matricula == (*ptr)->reg->matricula) {
      printf("A chave ja esta na arvore.\n");
      *fim = TRUE;
    }
  }
}

void insereElementoSBB(ArvoreSBB **t, Elemento *n) {
  int fim;
  int incli;
  fim = FALSE;
  incli = SBB_VERTICAL;
  iInsere(n, t, &incli, &fim);
}

void imprimeArvoreSBB(ArvoreSBB *t, FILE *arq){
  if(t != NULL) {
    imprimeArvoreSBB(t->esq, arq);
    imprimeAluno(t->reg, arq);
    imprimeArvoreSBB(t->dir, arq);
  }
}

void apagaArvoreSBB(ArvoreSBB *t){
  if(t != NULL) {
    apagaArvoreSBB(t->esq);
    apagaArvoreSBB(t->dir);
    apagaAluno(t->reg);
    free(t);
  }
}
