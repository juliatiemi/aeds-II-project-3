#include "TADaluno.h"

Aluno* criaAluno(char *n, Chave mat) {
  Aluno *aluno;
  aluno = (Aluno*)calloc(1 , sizeof(Aluno));
  aluno->nome = (char*)calloc((strlen(n)+1) , sizeof(char));
  strcpy(aluno->nome, n);
  aluno->matricula = mat;
  return aluno;
}

void apagaAluno(Aluno *a) {
  free(a->nome);
  free(a);
}

void imprimeAluno(Aluno *a, FILE *arq) {
  fprintf(arq, "(%06d) %s\n", a->matricula, a->nome);
}
