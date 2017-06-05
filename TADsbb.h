#ifndef _SBB_H_
#define _SBB_H_

#include "TADaluno.h"

#define FALSE 0
#define TRUE 1
#define SBB_VERTICAL 0
#define SBB_HORIZONTAL 1

typedef Aluno Elemento;

typedef struct ArvoreSBB {
  Elemento *reg;
  struct ArvoreSBB *esq;
  struct ArvoreSBB *dir;
  int esqtipo;
  int dirtipo;
} ArvoreSBB;

ArvoreSBB* criaArvoreSBB(Elemento *r);
void ee(ArvoreSBB **ptr);
void dd(ArvoreSBB **ptr);
void ed(ArvoreSBB **ptr);
void de(ArvoreSBB **ptr);
void iInsereAqui (Elemento *r, ArvoreSBB **ptr, int *incli, int *fim);
void iInsere (Elemento *r, ArvoreSBB **ptr, int *incli, int *fim);
void insereElementoSBB(ArvoreSBB **t, Elemento *n);
void imprimeArvoreSBB(ArvoreSBB *t, FILE *arq);
void apagaArvoreSBB(ArvoreSBB *t);

#endif
