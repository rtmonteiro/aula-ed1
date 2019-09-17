#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

typedef struct celula TCelula;

struct aluno {
  char* nome;
  int mat;
};

struct lista {
  TCelula* inicio;
  TCelula* fim;
};

struct celula {
  TAluno* item;
  TCelula* prox;
};

TLista* InicializaLista() {
  TLista* lista = (TLista*)malloc(sizeof(TLista));
  lista->fim = lista->inicio = NULL;

  return lista;
}

TAluno* InicializaAluno(char* nome, int matricula) {
  TAluno* aluno = (TAluno*)malloc(sizeof(TAluno));
  aluno->nome = malloc((strlen(nome)+1)*sizeof(char));
  strcpy(aluno->nome, nome);
  aluno->mat = matricula;
  
  return aluno;
}