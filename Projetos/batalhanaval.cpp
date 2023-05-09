#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

void limpatela(){
   #if defined(__linux__) || defined(__unix__) 
           system("clear");
    #else defined(_WIN32) || defined(_WIN64)
            system("CLS");
    #endif
 
}
void menuInicial(){
    
    // Opcao escolhida pelo usuario
    int opcao = 0;
    
     while (opcao < 1 || opcao > 3)
    {
    limpatela();
    cout << "Bem vindo ao Jogo!!";
    cout << "\n1- Jogar";
    cout << "\n2- Sobre";
    cout << "\n3- Sair";
    cout << "\nEscolha uma opção e aperte ENTER \n";
   
    // Leitura da opcao
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        //Inicia o jogo
        cout << "Jogo Iniciado";
    break;
    case 2:
        cout << "Informacoes do jogo";
    break;
    case 3:
        cout << "Ate mais";
    break;
    default:
        break;
    }


    }
    
}





int main(){
    
    menuInicial();


    return 0;
}