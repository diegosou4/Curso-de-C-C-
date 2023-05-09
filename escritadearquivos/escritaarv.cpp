#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace  std;

int main(){

    // Cria o objeto de arquivo

    ofstream outfile;

    //Abre o arquivo ou cria caso nao exista

    outfile.open("Texto.txt", std::ios_base::app);

    // Escreve algo
    
    outfile << "\n Hello Word";

    // Fecha arquivo

    outfile.close();

    return 0;
}