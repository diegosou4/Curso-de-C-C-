#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>
#include <iostream>
 
using namespace std;

int main(){

    // Criando o objeto do arquivo
    ofstream meuArquivo;

    //Abre o arquivo
    meuArquivo.open("Texto.txt");

    // Esvaziar arquivo

    meuArquivo << "";

    // fecha arquivo

    meuArquivo.close();

    return 0;

}