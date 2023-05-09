    #include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#define TAM 10

using namespace std; // para utilizar cout;


void print_value(int vetor[TAM]){
     int cont;
  for(cont = 0; cont < TAM - 1; cont++){
        cout << vetor[cont] << " - ";
    };
    

};

int binary_search(int vetor[TAM],int valueSearch, int *findPosition){

        int left = 0; // Limite da Esquerda
        int right = TAM - 1; // Limite da Direita 
        int quite; // O meio do cursor

        while (left <= right)
        {
                    
            quite = (left + right) / 2;

              // Se o valor estiver na posicao do meio
        if(valueSearch == vetor[quite]){
            *findPosition = quite;
            return 1;

        };
        // Se o valor for menor
        if(vetor[quite] < valueSearch){
            left = quite + 1;
        }
        // Se o valor for maior
        else{
            right = quite - 1;
        }
        };
        return -1;
};
   

int main(){

    int vetor[TAM] = {1,23,44,56,63,72,84,90,98};
    int valueSearch;
   
    int findPosition;
    // Imprime o vetor
  
    print_value(vetor);

    cout << "Qual valor deseja encontrar?";
    cin >> valueSearch;


    if(binary_search(vetor,valueSearch,&findPosition) == 1){
          cout << "O valor foi encontrado na posicao: " << findPosition;
    }else{
        cout << "O valor não foi encontrado";
    };
   
    return 0;
    }