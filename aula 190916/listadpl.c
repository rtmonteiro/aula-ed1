#include "listadpl.h"

struct tipoitem {
  char* nome;
  char* endereco;
  int mat;
};

struct tipolistadpl {
  TipoItem* item;
  TipoListaDpl* prox; 
  TipoListaDpl* ant;
};

TipoListaDpl* Insere (TipoItem* aluno, TipoListaDpl* lista){
  TipoListaDpl *nova;

  nova = (TipoListaDpl*) malloc(sizeof(TipoListaDpl));
  nova->item = aluno;
  nova->prox = lista;
  nova->ant = NULL;
  if (lista == NULL) {
    return nova;
  }
  else {
    lista->ant = nova;
  }
  return nova;
}

// TipoListaDpl* Retira (TipoListaDpl* lista, char* nome){
//   TipoListaDpl* p;
//   int boolean = 0;
//   for(p=lista; p!=NULL; p = p->prox){
//     if(strcmp(p->item->nome, nome) == 0) {
//       if(p->ant == NULL && p->prox != NULL) {
//         p->prox->ant = p->ant;
//         boolean = 1;
//       } 
//       else if (p->ant != NULL && p->prox == NULL){
//         p->ant->prox = p->prox;  
//         boolean = 1;
//       }
//       else if (p->ant != NULL && p->prox != NULL){
//         p->ant->prox = p->prox;
//         p->prox->ant = p->ant;
//         boolean = 1;
//       }
//       if (boolean == 1) {
//         free(p->item->nome);
//         free(p->item->endereco);
//         free(p->item);
//         free(p);
//       }
//     }
//   }
//   return lista;
// }

TipoListaDpl *Retira(TipoListaDpl *lista, char *nome){
  TipoListaDpl *p;
  int bool = 0;
  for (p = lista; p != NULL && bool == 0; p = p->prox) {
    if (strcmp(p->item->nome, nome) == 0) {
      if (p->ant == NULL && p->prox != NULL) {
        p->prox->ant = p->ant;
        bool = 1;
      }
      if (p->ant != NULL && p->prox == NULL) {
        p->ant->prox = p->prox;
        bool = 1;
      }
      if (p->ant != NULL && p->prox != NULL) {
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        bool = 1;
      }
      if (bool == 1) {
        free(p->item->nome);
        free(p->item->endereco);
        free(p->item);
        free(p);
      }
    }
  }
  return lista;
}

void Imprime (TipoListaDpl* lista){
  TipoListaDpl* p;

  for (p=lista; p!=NULL; p=p->prox) {
    printf("%s ", p->item->nome);
    printf("%d ", p->item->mat);
    printf("%s ", p->item->endereco);
    printf("\n");
  }
}

TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco){
  TipoItem* i;
  i = (TipoItem*) malloc(sizeof(TipoItem));
  // alocar o nome
  i->nome = (char*) malloc((strlen(nome)+1)*(sizeof(char)));
  // alocar o endereço
  i->endereco = (char*) malloc((strlen(endereco)+1)*(sizeof(char)));

  strcpy(i->nome, nome);
  strcpy(i->endereco, endereco);
  i->mat = matricula;
  
  return i;
}

TipoListaDpl* libera (TipoListaDpl* lista){
  TipoListaDpl* p;
  for (p=0; p!=NULL; p=p->prox) {
    free(p->item->nome);
    free(p->item->endereco);
    free(p->item);
    free(p);
  }
}