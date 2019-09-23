#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"

#define MAX_PESSOAS 10

struct pessoa
{
  char* nome;
  int idade;
  char* endereco;
};

struct pilha
{
  Pessoa pessoas[MAX_PESSOAS];
};

Pilha* cria_pilha(){
  
}

