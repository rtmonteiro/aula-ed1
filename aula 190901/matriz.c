#include <stdlib.h>
#include "matriz.h"

typedef struct matriz{
	int nLinhas;
	int nColunas;
	int** mat;
} Matriz;

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
	Matriz* mat;
  mat = (Matriz*) malloc(sizeof(Matriz));
  mat -> nLinhas = nlinhas;
  mat -> nColunas = ncolunas;
  mat -> mat = (int**) malloc(nlinhas * sizeof(int*));
  for (int i; i < nlinhas; i++)
      mat -> mat[i] = (int*) malloc((ncolunas * sizeof(int)));
  return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
	mat -> mat[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
	int recuperado = mat -> mat[linha][coluna];
	return recuperado;
}

int recuperaNColunas (Matriz* mat){
	int ncolunas;
	ncolunas = mat -> nColunas;
	return ncolunas;
}

int recuperaNLinhas (Matriz* mat){
	int nlinhas;
	nlinhas = mat -> nLinhas;
	return nlinhas;
}

Matriz* transposta (Matriz* mat){
	Matriz* trp;
	trp = (Matriz*) malloc(sizeof(Matriz));
  trp -> nLinhas = mat -> nColunas;
  trp -> nColunas = mat -> nLinhas;
  trp -> mat = (int**) malloc(trp -> nLinhas * sizeof(int*));
  for (int i; i < trp -> nLinhas; i++)
      trp -> mat[i] = (int*) malloc(trp -> nColunas * sizeof(int));
      trp -> mat[i] = mat -> mat[mat -> nColunas - i];
  return mat; 
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
	
}

void imprimeMatriz(Matriz* mat){
	
}

void destroiMatriz(Matriz* mat){
	
}

int main()
{
	return 0;
}
    