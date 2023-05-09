#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>
#define TAM 10

using namespace std; // para utilizar cout;



// Funcao int que faz um loop para verificar se o numero que deseja encontrar tem
// Apos feita procura caso seja verdadeiro vai ser devolvido o numero da posicao pelo ponteiro
// e quando for chamada a função o find position vai ser passado como paramentro o endereco da
// memoria 



int vetor_search(int vetor[TAM],int valueSearch, int *findPosition){

        int cont;
        bool valueFind;

    for(cont = 0;cont < TAM; cont++){
        if(vetor[cont] == valueSearch){
            valueFind = true;
            *findPosition = cont;
        };
    };
    if(valueFind == true){
        return 1;
    } else{
        return -1;
    };
};


int main(){

    int vetor[TAM] = {1,23,44,56,63,72,84,90,98};
    int valueSearch;
   
    int findPosition;
    // Imprime o vetor
  
    print_value(vetor);


    cout << "Qual valor deseja encontrar?";
    cin >> valueSearch;


    if(vetor_search(vetor,valueSearch,&findPosition) == 1){
          cout << "O valor foi encontrado na posicao: " << findPosition;
    }else{
        cout << "O valor não foi encontrado";
    };
   
    return 0;
    }