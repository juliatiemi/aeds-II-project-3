#ifndef _ALUNO_H_
#define _ALUNO_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef int Chave;

typedef struct Aluno {
  char *nome;
  Chave matricula;
} Aluno;

Aluno* criaAluno(char *n, Chave mat);
void apagaAluno(Aluno *a);
void imprimeAluno(Aluno *a, FILE *arq);

#endif
