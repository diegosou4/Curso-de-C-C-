#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void print_value(int vetor[TAM]){
     int cont;
   
  for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
   
    };
     cout << "\n";
};

void quick_sort(int vetor[TAM],int inicio, int fim){

   
    // Limites da esquerda e direita da regiao analisada
    int pivo,esq, dir;
    esq = inicio;
    dir = fim;
    int aux, meio;

    // Ajustando os auxiliares do centro
    meio = (int) ((esq + dir) / 2);
    pivo = vetor[meio];

    while(dir > esq){
         while(vetor[esq] < pivo){
        esq = esq + 1;
    }
       while(vetor[dir] > pivo){
        dir = dir - 1;
    }
    if(esq <= dir){
    
        // realiza uma troca 
        aux = vetor[esq];
        vetor[esq] = vetor[dir];
        vetor[dir] = aux;
        // faz os limites laterais caminharem para o centro
        esq = esq + 1;
        dir = dir - 1;  
    }
    }
    if(inicio < dir){
        quick_sort(vetor,inicio,dir);
    }
    if(esq < fim){
        quick_sort(vetor,esq,fim);

    }




}
   
int main(){
    int vetor[TAM] = {2,4,5,3,1,6,9,8,13,11};
    print_value(vetor);
    quick_sort(vetor,0 , TAM);
    print_value(vetor);
    return 0;






}