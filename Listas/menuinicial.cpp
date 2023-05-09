#include <iostream>
#include <string>
#include <new>
#include <stdlib.h>

using namespace std;

struct pessoa
{
    string nome;
    int rg;
};

void imprimeSequencial(pessoa *ponteiroSequencial, int tamanhodaLista){

    int cont;

    for(cont = 0;cont < tamanhodaLista; cont++){
        cout << "Nome:" << ponteiroSequencial[cont].nome << ", RG:" <<  ponteiroSequencial[cont].rg << "\n";
    }

}
    
void limpatela(){
    system("clear");
}
void adComecoSequencial(pessoa *&ponteiroSequencial, string nome, int rg, int *tamanhodaLista){
     if(*tamanhodaLista == 0){

        pessoa *novaListaSequencial = new pessoa[1];
        novaListaSequencial[0].nome = nome;
        novaListaSequencial[0].rg = rg;
        ponteiroSequencial = novaListaSequencial;
       
    }else
    {
     pessoa *novaListaSequencial = new pessoa[*tamanhodaLista + 1];

    int cont;



    novaListaSequencial[0].nome = nome;
    novaListaSequencial[0].rg = rg;

    for(cont = 0;cont < *tamanhodaLista; cont++ ){
        novaListaSequencial[cont + 1].nome = ponteiroSequencial[cont].nome;
        novaListaSequencial[cont + 1].rg = ponteiroSequencial[cont].rg;
    }
    // Atualiza o ponteiro para nova lista
    ponteiroSequencial = novaListaSequencial;
    }
     *tamanhodaLista = *tamanhodaLista + 1;
}

void adFimSequencial(pessoa *&ponteiroSequencial,string nome, int rg, int *tamanhodaLista){
    

    pessoa *novaListaSequencial = new pessoa[*tamanhodaLista + 1];

    int cont;
    // Posicionar o ultimo elemento
    novaListaSequencial[*tamanhodaLista].nome = nome;
    novaListaSequencial[*tamanhodaLista].rg = rg;

    for(cont = 0;cont < *tamanhodaLista; cont++ ){
        novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
        novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
    }
    // Atauliza o ponteiro para nova lista
    ponteiroSequencial = novaListaSequencial;
     *tamanhodaLista = *tamanhodaLista + 1;
}

void  adcPosicaoSequencial(pessoa *&ponteiroSequencial,string nome, int rg, int *tamanhodaLista,int posicao){
    // Cria uma lista com tamanho maior
    pessoa *novaListaSequencial = new pessoa[*tamanhodaLista + 1];
      
    int cont;
    for(cont = 0;cont < posicao; cont++ ){
        novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
        novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
    }

    // Adiciona registro na posicao correta
     novaListaSequencial[posicao].nome = nome;
    novaListaSequencial[posicao].rg = rg;
    
    // coloca o resto dos valores
     for(cont = posicao + 1;cont < *tamanhodaLista + 1; cont++ ){
        novaListaSequencial[cont].nome = ponteiroSequencial[cont - 1].nome;
        novaListaSequencial[cont].rg = ponteiroSequencial[cont - 1].rg;
    }

    // Atualizo minha lista
        ponteiroSequencial = novaListaSequencial;
     *tamanhodaLista = *tamanhodaLista + 1;
}

void removeComecoSequencial(pessoa *&ponteiroSequencial, int *tamanhodaLista){

     pessoa *novaListaSequencial = new pessoa[*tamanhodaLista - 1];

     int cont;

     for(cont = 1; cont < *tamanhodaLista;cont++){
         novaListaSequencial[cont - 1].nome = ponteiroSequencial[cont].nome;
        novaListaSequencial[cont - 1].rg = ponteiroSequencial[cont].rg;
     }
      ponteiroSequencial = novaListaSequencial;

        // Reduz o tamanho da lista  
     *tamanhodaLista = *tamanhodaLista - 1;



}

void removeFinalSequencial(pessoa *&ponteiroSequencial, int *tamanhodaLista){

     pessoa *novaListaSequencial = new pessoa[*tamanhodaLista - 1];

     int cont;

     for(cont = 0; cont < *tamanhodaLista - 1;cont++){
         novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
        novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
     }
      ponteiroSequencial = novaListaSequencial;

        // Reduz o tamanho da lista  
     *tamanhodaLista = *tamanhodaLista - 1;



}

void removeNSequencial(pessoa *&ponteiroSequencial, int *tamanhodaLista, int posicao){

     pessoa *novaListaSequencial = new pessoa[*tamanhodaLista - 1];
      
    int cont;
    for(cont = 0; cont < *tamanhodaLista - 1; cont++ ){
    
      if(cont < posicao){
            // se tiver antes da possicao passa
        novaListaSequencial[cont].nome = ponteiroSequencial[cont].nome;
        novaListaSequencial[cont].rg = ponteiroSequencial[cont].rg;
        } else{
            novaListaSequencial[cont].nome = ponteiroSequencial[cont + 1].nome;
            novaListaSequencial[cont].rg = ponteiroSequencial[cont + 1].rg;
        }
        
    }
    


    // Atualizo minha lista
        ponteiroSequencial = novaListaSequencial;
     *tamanhodaLista = *tamanhodaLista  - 1;


}

string retornaNomeSequencial(pessoa *&ponteiroSequencial, int *tamanhodaLista, int rg){
        // Busca pelo nome com rg digitado
    int cont;
    string nome = "Não encontrado";


    for(cont = 0; cont < *tamanhodaLista; cont++){
        if(ponteiroSequencial[cont].rg == rg){
            nome = ponteiroSequencial[cont].nome;
        } 

    }
    return nome;
}
int main(){

    // Declarando varavel
    int funcaoDesejada = 1;
    
    // Ponteiro para lista sequencial

    pessoa *ponteiroSequencial;

    // Tamanho da lista

    int tamanhodaLista = 2;


    // Exemeplo

    pessoa *exemploListaSequencial =  new pessoa[tamanhodaLista];

    // Dois registros de exemplos
    
    exemploListaSequencial[0].nome= "Joao";
    exemploListaSequencial[0].rg= 375122;
    exemploListaSequencial[1].nome= "Diego";
    exemploListaSequencial[1].rg= 587565;


    // Faz o ponteiro principal apontar para o novo vetor
    
    ponteiroSequencial = exemploListaSequencial;
    

    
    while (funcaoDesejada < 9 && funcaoDesejada > 0 )
    {
        
      
    
    // Mostrando menu
    cout << "Operacoes \n";
    cout << "1-Insercao de um node no inicio da lista \n";
    cout << "2-Insercao de um node no fim da lista \n";
    cout << "3-Insercao de um node na posicao N \n";
    cout << "4-Retirar um node no inicio da lista \n";
    cout << "5-Retirar um node no fim da lista \n";
    cout << "6-Retirar um node na posicao N da lista \n";
    cout << "7-Procurar um node com campo RG\n";
    cout << "8-Imprimir a Lista \n";
    cout << "9-Sair do Sistema \n";    
    cout << "\nEscolha um numero e pressione ENTER: \n";
    
    // Ler a funcao desejada
    cin >> funcaoDesejada;

    
    limpatela();


    // Variaveis que vao ser usadas nas funcoes
    string nome;
    int rg,posicao;



    // Seleciona e executa a funcao desejada  
    switch (funcaoDesejada)
    {
    case 1:
        cout << "Funcao Escolhida 1 - Insercao de um node no inicio da lista \n";
        cout << "Digite um nome:";
        cin >> nome;
        cout << "Digite o RG:";
        cin >> rg;
        adComecoSequencial(ponteiroSequencial,nome,rg, &tamanhodaLista);
        
        break;
    case 2:
        
        cout << "Funcao Escolhida 2- Insercao de um node no fim da lista \n";
        cout << "Digite um nome:";
        cin >> nome;
        cout << "Digite o RG:";
        cin >> rg;
        // Se a lista for vazia usamos a função de criar lista
        if(tamanhodaLista == 0){
            adComecoSequencial(ponteiroSequencial,nome,rg, &tamanhodaLista);
        } else{
             adFimSequencial(ponteiroSequencial,nome,rg, &tamanhodaLista);   
        }
        break;
    case 3:
        cout << "3-Insercao de um node na posicao N \n";
        cout << "Digite um nome:";
        cin >> nome;
        cout << "Digite o RG:";
        cin >> rg;
        cout << "Digite a posicao:";
        cin >> posicao;
        
        // Verificar se a primeira ou ultimo
        if(posicao == 0){
            adComecoSequencial(ponteiroSequencial,nome,rg, &tamanhodaLista);
        } else if(posicao == tamanhodaLista){
             adFimSequencial(ponteiroSequencial,nome,rg, &tamanhodaLista);   
        } else{
             adcPosicaoSequencial(ponteiroSequencial,nome,rg, &tamanhodaLista, posicao);
        }
        break;
    case 4:
    cout << "Funcao Escolhida 4 - Retirar um node no inicio da lista \n";

    // Verificar se a lista e vazia
        if(tamanhodaLista == 0){
            cout << "Lista vazia \n";
        } else{
              removeComecoSequencial(ponteiroSequencial,&tamanhodaLista);
        }
        break;
    case 5:
      cout << "Funcao Escolhida 5 - Retirar um node no fim da lista \n";
          // Verificar se a lista e vazia
        if(tamanhodaLista == 0){
            cout << "Lista vazia \n";
        } else{
              removeFinalSequencial(ponteiroSequencial,&tamanhodaLista);
        }
    break;
    case 6:
         cout << "Funcao Escolhida 6 - Retirar um node na posicao N da lista \n";
          // Verificar se a lista e vazia
        if(tamanhodaLista == 0){
            cout << "Lista vazia \n";
        }else{
            cout << "Informe a posicao que deve ser retirada:";
            cin >> posicao;
            if(posicao == 0){
                removeComecoSequencial(ponteiroSequencial,&tamanhodaLista);
            } else if(posicao == tamanhodaLista){
                 removeFinalSequencial(ponteiroSequencial,&tamanhodaLista);
            } else{
               removeNSequencial(ponteiroSequencial,&tamanhodaLista, posicao);
            };
        }

    break;
    case 7:
         cout << "Funcao Escolhida 7 - Procurar um node com campo RG \n";
         if(tamanhodaLista == 0){
            cout << "Lista vazia \n";
        }else{
            cout << "Digite o RG";
            cin >> rg;
            cout << "Nome: " << retornaNomeSequencial(ponteiroSequencial,&tamanhodaLista, rg) << "\n";
        }
    break;
    case 8:
        cout << "Funcao Escolhida 8 - Imprimir a Lista \n";
      // Imprime sequencial
        if(tamanhodaLista > 0){
               imprimeSequencial(ponteiroSequencial, tamanhodaLista); 
        }else {
              cout << "Lista vazia \n";
        }
     break;
    default:
        break;
    }    
    }
    
    return 0;
}