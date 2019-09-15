#include "lista.h"

int main() {
  tLista *L = criarLista();

  insereNoFim(L, 10);
  insereNoFim(L, 2);
  insereNoFim(L, 4);
  insereNoFim(L, 5);
  insereNoFim(L, 7);

  imprimeLista(L);

  destroiLista(&L);

  return 0;
}
