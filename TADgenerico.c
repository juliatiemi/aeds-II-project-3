#include "TADgenerico.h"

int charParaInt (char const *entrada) {
  int i;
  i = atoi (entrada);
  return i;
}

void organizaAluno(char const *par_1, char const *par_2, char const *par_3, char const *par_4) {
  FILE *entrada, *saida;
  int matricula;
  char nome[100];
  Hash *hash;
  Aluno *aluno;
  entrada = fopen(par_1, "r");
  saida = fopen(par_2, "w");
  if(entrada == NULL || saida == NULL) {
      printf("Erro ao abrir arquivo.\n");
      exit(1);
  }
  hash = criaHash(charParaInt(par_3), charParaInt(par_4));
  while(!feof(entrada)) {
    fscanf(entrada, "%d\n", &matricula);
    fflush(entrada);
    fgets(nome, 100, entrada);
    nome[strlen(nome) - 1] = '\0';
    aluno = criaAluno(nome, matricula);
    insereNaHash(hash, aluno);
    free(aluno);
  }
  imprime(hash, saida);
  apagaHash(hash);
  fclose(entrada);
  fclose(saida);
}
