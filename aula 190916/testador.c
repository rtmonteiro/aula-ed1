#include "listadpl.h"

int main() {
  TipoListaDpl* lista;
  lista = NULL;
  // TipoItem* item;
  TipoItem* joao = InicializaTipoItem("joao", 123, "jc");

  lista = Insere(joao, lista);

  Imprime(lista);
  return 0;
}