#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <iostream>
 
using namespace std;

int main(){

    // Dizer qual arquivo sera lido

    ifstream input("Texto.txt");

    // String que receberar o texto lido
    string textoLido;


    // Passa o texto para o textolido

    for(string line ; getline(input,line);){
        textoLido += line;
    }

    // mostrar o conteudo
    cout << textoLido;

    return 0;
}