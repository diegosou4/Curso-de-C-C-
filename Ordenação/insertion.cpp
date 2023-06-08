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

void insertion_sort(int vetor[TAM]){

    int i,j, atual;

    for(i = 1; i < TAM;i++){

        // o atual sempre vai amarzenar o que vai ser comparado
        atual = vetor[i];

        // Elemento anterior ao analisado
        j = i - 1;
        // ELe sai desse quando o atual e menor
        while((j >= 0) && (atual < vetor[j]))        
        {
            // Posiciona os elementos uma posicao para frente
            vetor[j + 1] = vetor[j];
            // se o valor for menor o j + 1 vai receber o valor j, o valor da direita recebe o da esquerda

            // depois o jota perde 1 para ele voltar a casa
            j = j - 1;



        }

        // Agora que o espaco foi aberto ele coloca o valor na esquerda
        vetor[j + 1] = atual;
    }

}
   
int main(){
    int vetor[TAM] = {5,3,2,4,1,6,9,8,7,11};
    print_value(vetor);
    return 0;

}