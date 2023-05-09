#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void print_value(int vetor[TAM]){
     int cont;
   
  for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
   
    };
     cout << "\n";
};

void bubble_sort(int vetor[TAM]){
     int x,y;
     
      for(x = 0;x < TAM;x++){
        for(y = x + 1;y < TAM;y++){
         if(vetor[x] > vetor[y])
            {
            int temp;
            temp = vetor[x];
            vetor[x] = vetor[y];
            vetor[y] = temp;
            };
        } ;
    } ;
};
   
int main(){
    int vetor[TAM] = {5,3,2,4,1,6,9,8,7,11};
    print_value(vetor);
    bubble_sort(vetor);
    print_value(vetor);
    return 0;






}