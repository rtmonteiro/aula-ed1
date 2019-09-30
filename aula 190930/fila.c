#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#include "fila.h"

struct fila {
  Pilha* p;
  Pilha* aux;
}

Fila* cria_fila(void) {
  Fila* f = (Fila*)malloc(sizeof(Fila));
  f->p = cria_pilha();
  f->aux = cria_pilha();

  return f;
}