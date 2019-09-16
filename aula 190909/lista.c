#include "lista.h"

struct No {
  int val; // poderia ser de outro tipo: Alunos, Livros, float. char*, ...
  struct No *prox; // ponteiro para o próximo elemento da lista
};

struct Lista {
  tNo *inicio; // ponteiro para o primeiro item da lista
  tNo *fim; // ponteiro para o último item da lista
};

tLista *criarLista() {
  tLista *L = (tLista *) calloc(1, sizeof(tLista));
  L->inicio = L->fim = NULL;

  return L;
}

void destroiLista(tLista **T) {
  tLista *L = *T;

  tNo *p = NULL;
  tNo *q = NULL;

  // apaga todos os nós da lista
  p = L->inicio;
  while (p != NULL) {
    q = p;
    p =  p->prox;
    free(q);
  }

  // apaga/desaloca a lista
  free(L);
  *T = NULL;
}

tNo *criarNo(int val){
  tNo *no = (tNo*) calloc(1, sizeof(tNo));
  no->val = val;
  no->prox = NULL;

  return no;
}

void insereNoInicio(tLista *L, int val) {
  tNo *p = criarNo(val);
  p->prox = L->inicio;

  if (L->inicio == NULL) {
    L->fim = p;
  }
  L->inicio;
}

void insereNoFimManeiraRuim(tLista *L, int val) {
  tNo *q = criarNo(val);

  // caso 1: lista está vazia
  if (L->inicio == NULL) {
    L->inicio = q;
  }
  // caso 2: lista possui elementos 
  else {
    tNo *p = L->inicio;

    // enquanto p não é o último nó da lista
    while (p->prox != NULL) {
      p = p->prox;
    }
    p->prox = q;
  }
}

void insereNoFim(tLista *L, int val) {
  tNo *q = criarNo(val);

  // se a lista está vazia
  if (L->inicio == NULL) {
    L->inicio = q;
    L->fim = q;
  }

  // se a lista possui elementos
  else {
    L->fim->prox = q;
    L->fim = q;
  }
  
}

void imprimeLista(tLista *L){
  printf("L -> ");

  tNo *p = L->inicio;

  while (p != NULL) {
    printf("%d -> ", p->val);
    p = p->prox;
  }
  printf("NULL\n");
}
