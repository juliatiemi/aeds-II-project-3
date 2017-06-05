#ifndef _BT_H_
#define _BT_H_

#include "TADaluno.h"

typedef Aluno Elemento;

typedef struct Arvore{
  struct Arvore *esq;
  struct Arvore *dir;
  Elemento *reg;
} Arvore;

Arvore* criaArvore(Elemento *r);
void insereElemento(Arvore *t, Elemento *n);
void imprimeArvore(Arvore *t, FILE *arq);
void apagaArvore(Arvore *t);

#endif
