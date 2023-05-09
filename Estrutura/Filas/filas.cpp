#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

bool full_fila(int tras){

    if(tras == TAM - 1){
        return true;
    }
    else
    {
        return false;
    }
};

bool leak_fila(int tras, int frente){

    if(frente < tras)
    {
        return true;
    }else
    {
        return false;
    }
};


void print_value(int vetor[TAM], int tamanho){
     int cont;
   
  for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
   
    };
     cout << "\n";
};
   

void constructor_fila(int *frente,int *tras){
     *frente = 0;
    *tras = -1;
}

void enfilerar_fila(int fila[TAM], int valor, int *tras){
     if(full_fila(*tras)){
        cout << "A fila esta cheia \n" ;
     }else{
    *tras = *tras + 1;
    fila[*tras] = valor;
     }
}

void desifilerar_fila(int fila[TAM], int *frente , int tras){
    if(leak_fila(*frente , tras)){
         cout << "Impossivel pois a fila esta vazia \n";
    }else{
    cout << "O valor " << fila[*frente] << " foi removido \n";
    fila[*frente] = 0;
    *frente = *frente + 1;
   
}
}


int length_fila(int tras, int frente){
    return (tras - frente) + 1;
    };
    
    

int main(){

    int fila[TAM]  = {0,0,0,0,0,0,0,0,0,0};
    int frente,tras;
    int value;
    
    constructor_fila(&frente,&tras);

    enfilerar_fila(fila,2,&tras);
    enfilerar_fila(fila,1,&tras);
    enfilerar_fila(fila,12,&tras);
    print_value(fila, length_fila(tras, frente));
    desifilerar_fila(fila,&frente, tras); 
    enfilerar_fila(fila,18,&tras);
    enfilerar_fila(fila,12,&tras);

    print_value(fila, length_fila(tras, frente));
    return 0;
}