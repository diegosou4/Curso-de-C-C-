#include <stdio.h>
#include <stdlib.h>

int main(){


    /// Definindo variaveis
    int linhas = 3, colunas = 3, i, j ;
    int **matriz;

    printf("Digite o numero de linhas:");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas:");
    scanf("%d", &colunas);

 
    // Alocando memoria para linha da matriz
    // o conceito é matriz é igual ponteiro de ponteiro de int utilizando malloc que 
    // que vai multiplicar as o tamanho das linhas pelo tamanho que vai ocupar na memoria
    matriz = (int **) malloc(linhas * sizeof(int *));

    // Alocando memoria para as colunas 
    for(i = 0; i < linhas; i++){
        matriz[i] = (int *) malloc(colunas * sizeof(int));

    }
    
    // Preenchedos valores e exibindo as matrizes
    for(i = 0; i < linhas ; i++){
        for(j = 0; j <  colunas; j++){
            matriz[i][j] = i;
            printf("%d", matriz[i][j]);
        };
        printf("\n");

    };
    // Libera a memoria
    free(matriz);
    return 0; 

};