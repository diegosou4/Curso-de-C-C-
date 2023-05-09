#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <new>


using namespace std;

struct estrutura {
    int valorNumerico;
    struct estrutura *proximo;

};


int main(){

    //Cria o inicio da lista
    estrutura *ponteiroEncadeada;


    // Cria um novo valor

    estrutura *novoPrimeiroValor = new estrutura;
    novoPrimeiroValor->valorNumerico = 1;
    novoPrimeiroValor->proximo = NULL;

    cout << novoPrimeiroValor->valorNumerico << "\n";

    // Faz o ponteiro da encadeada apontar para o primeiro valor
    ponteiroEncadeada = novoPrimeiroValor;

    // Cria um segundo valor;
    
    estrutura *novoSegundoValor = new estrutura;
    novoSegundoValor->valorNumerico = 21;
    novoSegundoValor->proximo = NULL;
     // junta os valores com um encadeamneto
    ponteiroEncadeada->proximo = novoSegundoValor;
    
    // Cria um terceiro valor      // Malloc em
    estrutura *novoTerceiroValor = (estrutura *) malloc(sizeof(estrutura));
    novoTerceiroValor->valorNumerico = 32;
    novoTerceiroValor->proximo = NULL;
    
    novoSegundoValor->proximo = novoTerceiroValor;
   

    while (ponteiroEncadeada != NULL)
    {
        cout << "Valor: " << ponteiroEncadeada->valorNumerico << "\n";
        
        ponteiroEncadeada = ponteiroEncadeada->proximo;
    }
    




    return 0;
}