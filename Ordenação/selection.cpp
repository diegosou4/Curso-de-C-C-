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

void selection_sort(int vetor[TAM]){
 
    int posicaoDoMenorValor, aux, i, j;
 
    for(i = 0; i < TAM; i++){
 
        //Recebe a posicao inicial para o menor valor
        posicaoDoMenorValor = i;
 
        //Analisa os elementos na frente
        for(j = i + 1; j < TAM; j++){
 
            //Caso encontre um valor menor na frente dos analisados
            if(vetor[j] < vetor[posicaoDoMenorValor]){
                posicaoDoMenorValor = j;
            }
 
        }
 
        //Verifica se houve mudança e troca os valores
        if(posicaoDoMenorValor != i){
            aux = vetor[i];
            vetor[i] = vetor[posicaoDoMenorValor];
            vetor[posicaoDoMenorValor] = aux;
        }
 
    }
 
}

int main(){
    int vetor[TAM] = {5,3,2,4,1,6,9,8,7,11};
    
    selection_sort(vetor);
    print_value(vetor);
    
    return 0;


}