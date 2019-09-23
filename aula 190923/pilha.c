#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "pilha.h"

#define MAX_TAM 10

struct pessoa {
  char* nome;
  int idade;
  char* endereco;
};

struct pilha {
  Pessoa* pessoas[MAX_TAM];
  int topo;
};

Pilha* cria_pilha(){
  Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
  pilha->topo = 0;
  
  return pilha;
}

void push(Pessoa* pessoa, Pilha* pilha) {
  if(pilha->topo == MAX_TAM){
    return;
  }
  pilha->pessoas[pilha->topo] = pessoa;
  pilha->topo++;
}

Pessoa* pop(Pilha* pilha) {
  if(pilha->topo == 0) {
    return NULL;
  }
  Pessoa* pessoa = pilha->pessoas[pilha->topo-1];
  pilha->topo--;
  
  return pessoa;
}

void imprime_pilha(Pilha* pilha) {
  for (int i = 0; i < pilha->topo; i++){
    printf("Nome: %s", pilha->pessoas[i]->nome);
    printf(" | ");
    printf("Idade: %d", pilha->pessoas[i]->idade);
    printf(" | ");
    printf("Endereco: %s", pilha->pessoas[i]->endereco);
    printf("\n");
  }
  printf("\n");
}

Pilha* destroi_pilha(Pilha* pilha) {
  for (int i = 0; i < pilha->topo; i++) {
    free(pilha->pessoas[i]->endereco);
    free(pilha->pessoas[i]->nome);
    free(pilha->pessoas[i]);
  }
  free(pilha);
  return NULL;
}

Pessoa* inicializaPessoa(char* nome, int idade, char* endereco) {
  Pessoa* pessoa = (Pessoa*) malloc(sizeof(Pessoa));
  pessoa->nome = (char*) malloc(strlen(nome));
  strcpy(pessoa->nome, nome);
  pessoa->endereco = (char*) malloc(strlen(endereco));
  strcpy(pessoa->endereco, endereco);
  pessoa->idade = idade;

  return pessoa;
}

