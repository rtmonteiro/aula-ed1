#include "listadpl.h"

int main() {
  TipoListaDpl* lista = NULL;

  TipoItem* joao = InicializaTipoItem("joao", 123, "jc");
  TipoItem* maria = InicializaTipoItem("maria", 456, "jp");
  TipoItem* well = InicializaTipoItem("well", 987, "pdc");

  lista = Insere(joao, lista);
  lista = Insere(maria, lista);
  lista = Insere(well, lista);

  Imprime(lista);

  lista = Retira(lista, "joao");

  Imprime(lista);

  libera(lista);
  return 0;
}