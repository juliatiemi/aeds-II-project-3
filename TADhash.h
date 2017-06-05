#ifndef _HASH_H_
#define _HASH_H_

#include "TADbt.h"
#include "TADsbb.h"

typedef struct Hash {
  Arvore **hash;
  ArvoreSBB **hashSBB;
  int tam;
  int bin_or_sbb;
} Hash;

int funcaoHash(Elemento *x);
Hash* criaHash(int t, int tipo);
void apagaHash(Hash *h);
void insereNaHash(Hash *h, Elemento *x);
void imprime(Hash *h, FILE *arq);

#endif
