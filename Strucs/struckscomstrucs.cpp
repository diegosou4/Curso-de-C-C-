#include <stdio.h>


typedef struct Data
{
    int dia;
    int mes;
    int ano;
}Data;




struct Aluno
{
    int id;
    Data nascimento;
};


int main(){

    // Criando aluno

    struct Aluno aluno1;

    aluno1.id = 15;

    aluno1.nascimento.dia = 26;
    aluno1.nascimento.mes = 05;
    aluno1.nascimento.ano = 2000;
    

    printf("Nascido em %d/%d/%d ", aluno1.nascimento.dia ,aluno1.nascimento.mes ,aluno1.nascimento.ano);

    return 0;
}