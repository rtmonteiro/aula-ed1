#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846

/* Implemente funções em C para cada um dos problemas abaixo (todas as funções devem estar em um único arquivo aula1_2.c). Para cada uma das funções, implemente uma função main diferente (comente as outras para conseguir rodar): */

void calc_esfera(float r, float* area, float* volume){
    /* Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio r. A área da superfície e o volume são dados, respectivamente, por 4*PI*r² e 4*PI*r³/3 . Essa função deve obedecer ao seguinte protótipo: void calc_esfera (float r, float* area, float* volume); */

    *area = (4*(PI)*pow(r, 2));
    *volume = ((4*(PI)*pow(r, 3))/3);   
}

void fatorial(int n, int* f){
    /* Implemente uma função que calcule o fatorial de um dado número. Protótipo: void fatorial (int n, int* f); */

    for (int i=1; i<=n; i++){
        *f *= i;
        // printf("%d \n", *f);
    }
}

int negativos (int n, float* vet){
    /* Implemente uma função que receba como parâmetro um vetor de números reais (vet) de tamanho n e retorne quantos números negativos estão armazenados nesse vetor. Essa função deve obedecer ao protótipo: int negativos (int n, float* vet); */
    int tristes = 0;

    for (int i = 0; i<n; i++){
        if (vet[i]<0){
            tristes ++;
        }
    }
    return tristes;
}

void inverte (int n, int* vet){
    /* Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de tamanho n e inverta a ordem dos elementos armazenados nesse vetor. Essa função deve obedecer ao protótipo: void inverte (int n, int* vet) */
    
    int auxiliar = 0;
    for (int j=0; j<ceil(n/2); j++){
        auxiliar = vet[j];
        vet[j] = vet[n-(1+j)];
        vet[n-(1+j)] = auxiliar;
    }
}

/* void main (void) {
    float r, area, volume;

    printf("Digite o raio da esfera: ");
    scanf("%f", &r);

    calc_esfera(r, &area, &volume);
    printf("A área e o volume da esfera serão %f e %f, respectivamente\n", area, volume);
} */

/* void main (void) {
    int n, f = 1;

    printf("Digite o número que deseja saber seu fatorial: ");
    scanf("%d", &n);
    fatorial(n, &f);
    printf("o fatorial de %d é %d\n", n, f);
} */

/* void main (void) {
    int n = 10;
    float vet[n];
    
    int tristes = 0;

    srand(time(NULL));

    for (int i=0; i<n; i++){
        vet[i] = pow(-1, rand()%100)*(rand()%10);
        // printf("%f \n", vet[i]);
    }

    tristes = negativos(n, vet);
    printf("%d \n", tristes);
} */

void main (void) {
    int n = 5;
    int vet[n];

    srand(time(NULL));

    for (int i=0; i<n; i++){
        vet[i] = (int) pow(-1, rand()%100)*(rand()%10);
        // printf("%d \n", vet[i]);
    }

    printf("\n");   

    inverte(n, vet);

    /* for (int i = 0; i < n; i++){
        printf("%d \n", vet[i]);
    } */
}