#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;



// Caso a pilha esteja cheia
bool full_pilha(int topo){

    if(topo == TAM - 1){
        return true;
    }
    else
    {
        return false;
    }
};

// Caso a pilha esteja vazia

bool leak_pilha(int topo){

    if(topo == -1)
    {
        return true;
    }else
    {
        return false;
    }
};

int pilha_get(int pilha[TAM], int *topo){
    if(leak_pilha(*topo)){
        cout << "A pilha esta vazia";
        return 0;
    }else{
        return pilha[*topo];

    }

}
void print_value(int vetor[TAM]){
     int cont;
   
  for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
   
    };
     cout << "\n";
};
     // Empilhar
    // Recebe o vetor, o valor para ser adicionado


void pilha_push(int pilha[TAM],int valor, int *topo){

    // Se o topo for igual o tamanho da pilha vai informar que esta cheia
    if(full_pilha(*topo)){
        cout << "Pilha Cheia \n";
    }else
    // Caso contrario vai adicionar a pilha e o topo va receber mais 1
    {
        *topo = *topo + 1;
        pilha[*topo] =  valor;
    };
}

void pilha_pop(int vetor[TAM], int *topo){

    // Verificar se esta vazia

    if(leak_pilha(*topo)){
        cout << "A pilha esta vazia \n";
    }else{
        // Se nao ele mostra o valor removido
        cout << "Valor removido: " << vetor[*topo] << "\n" ;
        // A posicao aonde tinha o numero recebe 0
        vetor[*topo] = 0;
        // topo e igual ele -1
        *topo = *topo - 1;
    }
}


// Coloca os valores padroes na pilha

void constructor_pilha(int pilha[TAM], int *topo)
{
    *topo = -1;
      
    // Auxiliar contador 
    int cont;

     for(cont = 0; cont < TAM; cont++){
        pilha[cont] = 0;
    };
   
};

int length_pilha(int topo){
    return topo + 1;
    };
    
    
int main(){

    int pilha[TAM];
    int topo = -1;                 
    // Topo da pilha
    // print_value(pilha);

    
    constructor_pilha(pilha,&topo);
    print_value(pilha);
   
    pilha_push(pilha,3, &topo);
    pilha_push(pilha,2, &topo);
    pilha_push(pilha,1, &topo);
    pilha_push(pilha,3, &topo);
    pilha_push(pilha,2, &topo);

    cout << "Ultimo numero adicionado: " <<  pilha_get(pilha,&topo);

    pilha_push(pilha,1, &topo);
    pilha_push(pilha,3, &topo);
    pilha_push(pilha,2, &topo);
    pilha_push(pilha,1, &topo);
    pilha_push(pilha,1, &topo);
    cout << "\n";
    cout << "Tamanho da pilha: " << length_pilha(topo) << "\n";
    pilha_push(pilha,3, &topo);
    pilha_push(pilha,2, &topo);

    print_value(pilha);
    pilha_pop(pilha,&topo);
    cout << "Tamanho da pilha: " << length_pilha(topo) << "\n";
    print_value(pilha);
    if(full_pilha(topo)){
        cout << "A pilha esta cheia";
    }
};
