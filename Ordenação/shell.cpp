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
void shell_sort(int vetor[TAM]){
 
    int i, j, atual;
    int h = 1;
 
    //Quantos pulos sera pulado de analise em analise
    while(h < TAM){
        h = 3*h+1;
    }
 
    while(h > 1){
 
        // diminui a distancia entre as analises
        h = h / 3;
 
        for(i = h; i < TAM; i++){
            // Elemento que ta sendo analisado no momento
            atual = vetor[i];
 
            //Elemento anterior do analisado
            j = i - h;
 
          
            while( (j >=0) && (atual < vetor[j])){
 
                //Posiciona os elmeentos uma posição para frente
                vetor[j + h] = vetor[j];
 
                //Faz o j andar para trás
                j = j - h;
 
            }
 
            //Agora que o espaço foi aberto, colocamos o atual (Menor número) na posição correta
            vetor[j + h] = atual;
        }
 
    }
 
}
int main(){
    int vetor[TAM] = {2,4,5,3,1,6,9,8,13,11};
    shell_sort(vetor);
    print_value(vetor);
    return 0;
}