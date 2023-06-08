#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;


int main(){

    // Cursor para percorrer cada letra
    int c;
    int cont = 0;
    char conteudotexto[255];


    // Arquivo a ser lindo

    FILE *file;

    // Abre o arquivo no ditorio escolhido

    file =  fopen("Texto.txt", "r");


    //se o arquivo foi encontrado
    if(file){

        // contador

        // Enquanto ele tiver encontrando uma letra ele vai imprimir a letra na tela
        // enquanto ( c é igual ao getc que ler o byte do arquivo na posição que ta enquanto
        // for diferente de numero)

        while((c = getc(file)) != EOF){
            //Imprimindo na tela
            printf("%c", c);
            
            // foi criado um char para receber as palavras que contem no arquivo
            // usando o while ali mesmo
            conteudotexto[cont] = c;

            cont++;
        }
    } 
        // usamos o for para imprimir os dados que foram adicionados
        // A variavel conteudoTexto
        for(cont = 0; cont < strlen(conteudotexto); cont++){
            printf("%c", conteudotexto[cont - 1]);
        }

    fclose(file);
    return 0;
}