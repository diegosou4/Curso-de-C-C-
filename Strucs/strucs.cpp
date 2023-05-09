#include <stdio.h>
#include <string.h>

struct palavra
{
    int ordem;
    char letra;
    char texto[255];
};




int main(){

    // Criar uma palavra
    struct  palavra primeirapalavra;

    // Modificando os campos
    primeirapalavra.ordem = 0;
    primeirapalavra.letra = 'c';
    strcpy(primeirapalavra.texto, "Palavra grande");
    // Mostrando valores do structs

    printf("Ordem %d, palavra %c, texto %s", primeirapalavra.ordem, primeirapalavra.letra, primeirapalavra.texto);
    printf("\n");
    

    // Fazendo uma lista de vetor

    struct palavra listadepalavras[3];

    listadepalavras[0].ordem = 0;
    listadepalavras[1].ordem = 1;
    listadepalavras[2].ordem = 2;

    listadepalavras[0].letra = 'a';
    listadepalavras[1].letra = 'b';
    listadepalavras[2].letra = 'c';

    stpcpy(listadepalavras[0].texto, "First");
    stpcpy(listadepalavras[1].texto, "Second");
    stpcpy(listadepalavras[2].texto, "Third");

    printf("%s", listadepalavras[0].texto);
    printf("\n");
    
    int num;

    for(num = 0; num < 3; num++){
        printf("Numero da ordem: %d, Letra %c, texto %s \n", listadepalavras[num].ordem, listadepalavras[num].letra, listadepalavras[num].texto);
         }

    return 0;
}