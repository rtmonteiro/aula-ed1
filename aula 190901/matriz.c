#include <stdlib.h>
#include <stdio.h>
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
  for (int i = 0; i < nlinhas; i++){
    mat -> mat[i] = (int*) malloc(ncolunas * sizeof(int));
		for (int j = 0; j < ncolunas; j++){
			mat -> mat[i][j] = 0;
		}
	}
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
	int ncolunas = mat -> nColunas;
	return ncolunas;
}

int recuperaNLinhas (Matriz* mat){
	int nlinhas = mat -> nLinhas;
	return nlinhas;
}

Matriz* transposta (Matriz* mat){
	Matriz* trp;
	trp = inicializaMatriz(mat -> nColunas, mat -> nLinhas);
	for (int i = 0; i < trp -> nLinhas; i++){
		for (int j = 0; j < trp -> nColunas; j++){
			trp -> mat[i][j] = mat -> mat[j][i];
		}
	}
  return trp; 
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
	Matriz *mat = inicializaMatriz(mat1->nLinhas, mat2->nColunas);
  	for (int i = 0; i < mat1->nLinhas; i++) {
    	for (int j = 0; j < mat2->nColunas; j++) {
      		for (int k = 0; k < mat2->nLinhas; k++) {
				mat -> mat[i][j]+=mat1 -> mat[i][k] * mat2 -> mat[k][j];
      		}
    	}
  	}
  return mat;
}

void imprimeMatriz(Matriz* mat){
	for (int i = 0; i < mat -> nLinhas; i++){
		for (int j = 0; j < mat -> nColunas; j++){
			printf("%2d ", mat -> mat[i][j]);
		}
		printf("\n");
	}
}

void destroiMatriz(Matriz* mat){
	for (int i = 0; i < mat -> nLinhas; i++){
    free(mat -> mat[i]);
  }
  free(mat -> mat);
  free(mat);
}