#include <iostream>
#include <string>
#include <new>
#define TAM 3

using namespace std;

/*
int* allocaVetor(int tam){

    // Cria um ponteiro auxiliar
    int *v;

    //Alloca memoria para o novo vetor

    v = (int *) malloc(tam * sizeof(int));



    return v;


}
*/


void sequencial_print(int vetor[TAM], int lengthVetor){

    int cont;

    for(cont = 0; cont < lengthVetor; cont++){
        cout << "O valor na posicao:" << cont << " é " <<vetor[cont] << "\n";
    }

}



int main(){

    int vetor[TAM] = {1,2,3};
    int tamanhodaLista,cont;
    sequencial_print(vetor, 3);
 

    int *vetorlidonahora;
    cout << "Informe o novo tamanho da nova lista: ";
    cin >> tamanhodaLista;
    cout << "\n";



    vetorlidonahora = new int(tamanhodaLista);

    for(cont = 0; cont < tamanhodaLista;cont++){
        cout << "Informe o valor que sera inserido na posicao " << cont << ": ";
        cin >> vetorlidonahora[cont];

    }

    sequencial_print(vetorlidonahora,tamanhodaLista);
    return 0;
}