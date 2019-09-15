#include <stdlib.h>
#include <stdio.h>

typedef struct No {
  int val;
  struct No *prox;
} tNo;

typedef struct Lista {
  tNo *inicio;
  tNo *fim;
} tLista;

tLista *criarLista();

void destroiLista(tLista **T);

tNo *criarNo(int val);

void insereNoInicio(tLista *L, int val);

void insereNoFimManeiraRuim(tLista *L, int val);

void insereNoFim(tLista *L, int val);

void imprimeLista(tLista *L);
