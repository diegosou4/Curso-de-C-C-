#include <iostream>
#include <string>
#include <new>
#include <stdlib.h>

using namespace std;

void limpatela(){
    system("clear");
}

int main(){

    // Declarando varavel
    int funcaoDesejada = 1;
    while (funcaoDesejada < 10 && funcaoDesejada > 0 )
    {
    // Mostrando menu
    cout << "Operacoes \n";
    cout << "1-Insercao de um node no inicio da lista \n";
    cout << "2-Insercao de um node no fim da lista \n";
    cout << "3-Insercao de um node na posicao N \n";
    cout << "4-Retirar um node no inicio da lista \n";
    cout << "5-Retirar um node no fim da lista \n";
    cout << "6-Retirar um node na posicao N da lista \n";
    cout << "7-Procurar um node com campo N \n";
    cout << "8-Imprimir a Lista \n";
    cout << "9-Sair da Lista \n";    
    cout << "\nEscolha um numero e pressione ENTER: \n";

    // Ler a funcao desejada
    cin >> funcaoDesejada;

    
    limpatela();
    // Seleciona e executa a funcao desejada  
    switch (funcaoDesejada)
    {
    case 1:
        cout << "Funcao Escolhida 1 \n";
        break;
    case 2:
         cout << "Funcao Escolhida 2 \n";
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    
    }
    
   



    return 0;
}