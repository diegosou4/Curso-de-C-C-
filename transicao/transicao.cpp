#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

/* void limpaTela(){
    system("CLS");

}
*/

int main(){


    int a = 10;
    char palavra[3];

    palavra[0] = 'g';
    palavra[1] = 'o';
    palavra[2] = 'l';

    printf("%c%c%c \n", palavra[0], palavra[1], palavra[2]);


    printf("O valor de %d eh maior que 0 \n", a);

    cout << "\nO valor de " << a << " eh maior que 0 \n";

    string outraPalavra = "gol \n";
    cout << outraPalavra;


    return 0;
}