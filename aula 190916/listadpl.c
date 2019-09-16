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
  nova->ant = NULL;
  nova->prox = lista;

  if (lista == NULL) {
    return nova;
  }
  else {
    nova->prox = lista;
    nova->ant = NULL;
    return nova;
  }
  
  
}

TipoListaDpl* Retira (TipoListaDpl* lista, char* nome){
  strcmp(lista->item->nome, nome);
  if(p->prox == NULL){
    return lista;
  }
  p->ant->prox = p->prox;
  p->prox->ant = p->ant;

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


/*Inicializa um TipoItem aluno
* inputs: o nome, a matricula e o endereco do aluno
* output: um ponteiro para o tipo item criado
* pre-condicao: nome, matricula e endereco validos
* pos-condicao: tipo item criado, com os campos nome, matricula e endereco copiados
*/
TipoItem* InicializaTipoItem(char* nome, int matricula, char* endereco){
  TipoItem* i = (TipoItem*) malloc(sizeof(TipoItem));
  
  // alocar o nome
  i->nome = (char*)malloc((strlen(nome)+1)*(sizeof(char)));
  strcpy(i->nome, nome);
  // alocar o endereço
  i->endereco = (char*)malloc((strlen(endereco)+1)*(sizeof(char)));
  strcpy(i->endereco, endereco);
  // alocar a matrícula
  i->mat = matricula;

  return i;
}


/*Libera toda a memória alocada para a lista (lembre-se de tambem liberar a memoria para o aluno)
* inputs: a lista duplamente encadeada de alunos
* output: Lista vazia (NULL)
* pre-condicao: lista não é nula
* pos-condicao: memória alocada é liberada
*/
TipoListaDpl* libera (TipoListaDpl* lista){

}