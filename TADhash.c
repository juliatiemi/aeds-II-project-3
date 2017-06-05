#include "TADhash.h"

int funcaoHash(Elemento *x){
  int a;
  a = x->matricula % 10;
  return a;
}

Hash* criaHash(int t, int tipo) {
  Hash *hash;
  hash = calloc(1 , sizeof(Hash));
  hash->tam = t;
  if(tipo == 0) {
    hash->hash = calloc(t , sizeof(Arvore));
    hash->bin_or_sbb = 0;
  }
  else if(tipo == 1) {
    hash->hashSBB = calloc(t , sizeof(ArvoreSBB));
    hash->bin_or_sbb = 1;
  }
  return hash;
}

void apagaHash(Hash *h) {
  if(h != NULL) {
    int i;
    if(h->bin_or_sbb == 1) {
      for(i = 0; i < h->tam; i++) {
        if(h->hashSBB[i] != NULL) {
          apagaArvoreSBB(h->hashSBB[i]);
        }
      }
      free(h->hashSBB);
    }
    else {
      for(i = 0; i < h->tam; i++) {
        if(h->hash[i] != NULL) {
          apagaArvore(h->hash[i]);
        }
      }
      free(h->hash);
    }
    free(h);
  }
}

void insereNaHash(Hash *h, Elemento *x) {
  int pos;
  if(h == NULL) {
    printf("Hash inexistente.\n");
    return;
  }
  else {
    pos = funcaoHash(x);
    if(h->bin_or_sbb == 0) {
      if(h->hash[pos] == NULL) {
        h->hash[pos] = criaArvore(x);
      }
      else {
        insereElemento(h->hash[pos], x);
      }
    }
    else {
      if(h->hashSBB[pos] == NULL) {
        h->hashSBB[pos] = criaArvoreSBB(x);
      }
      else {
        insereElementoSBB(&h->hashSBB[pos], x);
      }
    }
  }
}

void imprime(Hash *h, FILE *arq) {
  int i;
  if(h->bin_or_sbb == 0) {
    for(i = 0; i < h->tam; i++) {
      if(h->hash[i] != NULL) {
        fprintf(arq, "%d:\n", i);
      }
      imprimeArvore(h->hash[i], arq);
    }
  }
  else {
    for(i = 0; i < h->tam; i++) {
      if(h->hashSBB[i] != NULL) {
        fprintf(arq, "%d:\n", i);
      }
      imprimeArvoreSBB(h->hashSBB[i], arq);
    }
  }
}
