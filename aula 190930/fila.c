#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#include "fila.h"

struct fila {
  Pilha* p;
  Pilha* aux;
};

Fila* cria_fila(void) {
  Fila* f = (Fila*)malloc(sizeof(Fila));
  f->p = cria_pilha();
  f->aux = cria_pilha();

  return f;
}

void insere (Pessoa* pessoa, Fila* f) {
  if (tamanho_pilha(f->p) == 10) {
    return;
  }
  push(pessoa, f->p); //o topo da pilha p será o final da minha fila
}

Pessoa* retira (Fila* f) {
  if (vazia_pilha(f->p)) {
    return NULL;
  }
  while (!vazia_pilha(f->p)) {
    push(pop(f->p), f->aux);
  }
  Pessoa* p = pop(f->aux);
  while (!vazia_pilha(f->aux)) {
    push(pop(f->aux), f->p);
  }

  return p;
}

void imprime_fila (Fila* f) {
  if(vazia_pilha(f->p)) {
    return;
  }
  while (!vazia_pilha(f->p)) {
    push(pop(f->p), f->aux);
  }
  imprime_pilha(f->aux);
  while(!vazia_pilha(f->aux)) {
    push(pop(f->aux), f->p);
  }
}

void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores) {
  Pessoa* p;
  while(!vazia_fila(f)) {
    p = retira(f);
    if(retorna_idade(p) >= 60) {
      insere(p, f_maiores);
    } else {
      insere(p, f_menores);
    }
}

Fila* destroi_fila (Fila* f) {
  destroi_pilha(f->p);
  destroi_pilha(f->aux);
  free(f);

  return NULL;
}