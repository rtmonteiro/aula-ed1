#include <stdlib.h>
#include <stdio.h>

#include "matriz.h"

struct matriz {
    int nLinhas;
    int nColunas;
    int** mat;
};

Matriz* inicializaMatriz(int nlinhas, int ncolunas) {
    Matriz *mat;
    mat = (Matriz*) malloc(sizeof (Matriz));
    mat->mat = (int**) malloc(nlinhas * sizeof (int*));
    for (int x; x < nlinhas; x++) {
        mat->mat[x] = (int*) malloc((ncolunas * sizeof (int)));
    }
    mat->nColunas = ncolunas;
    mat->nLinhas = nlinhas;
    return mat;
}

void modificaElemento(Matriz* mat, int linha, int coluna, int elem) {
    mat->mat[linha][coluna] = elem;
}

void imprimeMatriz(Matriz* mat) {
    for (int x = 0; x < mat->nLinhas; x++) {
        printf("|");
        for (int y = 0; y < mat->nColunas; y++) {
            printf("%d", mat->mat[x][y]);
            if (y != mat->nColunas - 1) {
                printf(" ");
            }
        }
        printf("|\n");
    }
}

int recuperaElemento(Matriz* mat, int linha, int coluna) {
    return mat->mat[linha][coluna];
}

int recuperaNColunas(Matriz* mat) {
    return mat->nColunas;
}

int recuperaNLinhas(Matriz* mat) {
    return mat->nLinhas;
}

Matriz* transposta(Matriz* mat) {
    Matriz *trans;
    trans = inicializaMatriz(mat->nColunas, mat->nLinhas);
    for (int x = 0; x < trans->nLinhas; x++) {
        for (int y = 0; y < trans->nColunas; y++) {
            trans->mat[x][y] = mat->mat[y][x];
        }
    }
    return trans;
}
Matriz* preencheMat(Matriz *mat){
    for(int x=0;x<mat->nLinhas;x++){
        for(int y=0;y<mat->nColunas;y++){
            mat->mat[x][y]=0;
        }
    }
}
Matriz* multiplicacao(Matriz* mat1, Matriz* mat2) {
    Matriz *mat = inicializaMatriz(mat1->nLinhas, mat2->nColunas);
    mat=preencheMat(mat);
    for (int x = 0; x < mat1->nLinhas; x++) {
        for (int y = 0; y < mat2->nColunas; y++) {
            for (int z = 0; z < mat2->nLinhas; z++) {
                mat->mat[x][y]+=mat1->mat[x][z]*mat2->mat[z][y];
            }
        }
    }
    return mat;
}
void destroiMatriz(Matriz* mat){
    for (int x = 0; x < mat->nLinhas; x++) {
        free(mat->mat[x]);
    }
    free(mat->mat);
    free(mat);
}