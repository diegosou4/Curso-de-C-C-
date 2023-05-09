#include <iostream>
#include <new>
#include <string>
#include <stdlib.h>

using namespace std;
struct pessoa{
    string nome;
    int rg;
    struct pessoa *proximo;

};


int retornaTamanho(pessoa *ponteiroEncadeada){
    

    // se a lista tiver vazia
      if(ponteiroEncadeada->nome == ""){
        return 0;
    }
    
    // Criar tamanho 
    int tamanho = 0;

    // Cursor auxiliar
  
    pessoa *p = ponteiroEncadeada;

    while (p != NULL)
    {
        // Atualiza o cursor
        p = p->proximo;

        // contador de tamanho
        tamanho++;
        
    }
    
    return tamanho;
}

void imprimeEncadeada(pessoa *ponteiroEncadeada){

    
    // ponteiro auxiliar
    pessoa *p = ponteiroEncadeada;
    cout << "--------------Lista Atual---------------- \n";
    while (p != NULL)
    {
        cout << "Nome:" << p->nome << " Rg: " << p->rg;
        cout << "\n";
        p = p->proximo;
    }


}
void adComecoEncadeada(pessoa *&ponteiroEncadedado, string nome, int rg){

   
    // Cria uma nova estrutura
    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;


     if(ponteiroEncadedado->nome == ""){
        novoValor->proximo = NULL;
    }else{
        novoValor->proximo = ponteiroEncadedado;
    }

    // Redireciona o ponteiro

    ponteiroEncadedado = novoValor;

}

void adFinalEncadeada(pessoa *&ponteiroEncadeado, string nome, int rg){

    //Cria uma nova estrutura

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *p = ponteiroEncadeado;
    while (p != NULL)
    {
        // Se o proximo for nulo
       if(p->proximo == NULL){
       // Pega o novo valor  
        p->proximo = novoValor;
        // Quando ele encontra ele retorna para nao mexer nos outros valores
        return;
       }
         p = p->proximo;
       
    }
    // Libera a memoria
    free(p);
    free(novoValor);

}

void adPosicaoEncadeada(pessoa *&ponteiroEncadeado, string nome, int rg, int posicao){

    // Cria uma nova estrutura;

    pessoa *novoValor = new pessoa;
    novoValor->nome = nome;
    novoValor->rg = rg;
    novoValor->proximo = NULL;

    pessoa *p = ponteiroEncadeado;
    
    // Contador de posicao
    int tamanho = 0;
    while (tamanho <= posicao )
    {
        if(tamanho == posicao - 1){
            
            // auxiliar do valor
            pessoa *aux = new pessoa;
            aux->proximo = p->proximo;
            
            // Coloca o novo valor como o proximo
            p->proximo = novoValor;

            // Faz com que o novo valor aponte para o proximo
            novoValor->proximo = aux->proximo;

            free(aux);
        }
        // Atualiza cursor
        p = p->proximo;
        tamanho++;
    }
    
}
void removeComecoEncadeada(pessoa *&ponteiroEncadeada){

    if(ponteiroEncadeada->proximo == NULL){

            // cria uma estrutura
            pessoa *novoValor = new pessoa;
            novoValor->nome = "";
            novoValor->rg = 0;
            novoValor->proximo = NULL;
            
            ponteiroEncadeada = novoValor;
    }else{
        ponteiroEncadeada = ponteiroEncadeada->proximo;
    }
    //Faz o ponteiro principal apontar para o proximo valor

}

void removeFinalEncadeada(pessoa *&ponteiroEncadeada){
        // auxiliar
        int cont, tamanho;

        tamanho = retornaTamanho(ponteiroEncadeada);
        pessoa *p = ponteiroEncadeada;
        while(cont <= tamanho){
            if(cont == tamanho - 1){

                p->proximo = NULL;

            }
            p = p->proximo;
            cont++;
        }
}    

void removePosicaoEncadeada(pessoa *&ponteiroEncadeada, int posicao){

        // ponteiro aux
        pessoa *p = ponteiroEncadeada;
        // contador de posicao
        int cont = 0;

        while (cont <= posicao)
        {
            if(cont == posicao - 1){
                pessoa *aux = new pessoa;
                // recebe o elemento que sera eliminado 
                aux = p->proximo;

                p->proximo = aux->proximo;
                
                free(aux);
            }
            p = p->proximo;
            cont++;

              
        }
}


string buscaRG(pessoa *ponteiroEncadeada,int rg){
    
    string nome = "Não encontrado";


    pessoa *p = ponteiroEncadeada;
    while (p != NULL)
    {
        if(p->rg == rg){
            nome = p->nome;
            return nome;
        }
        p = p->proximo;
    }
    
    return nome;


}

void limpatela(){
    system("clear");
}
int main(){

    // Variaveis
    int funcaoDesejada;
    
    funcaoDesejada = 1;

    // Cria o inicio da lista encadeada

    pessoa *ponteiroEncadeada = new pessoa;
    ponteiroEncadeada->nome = "";
    ponteiroEncadeada->rg = 0;
    ponteiroEncadeada->proximo = NULL;

    // transforma o ponteiro do inicio da lista no novo valor


    while (funcaoDesejada < 10 && funcaoDesejada > 0)
    {      
    
    cout << "Operacoes \n";
    cout << "1-Insercao de um node no inicio da lista \n";
    cout << "2-Insercao de um node no fim da lista \n";
    cout << "3-Insercao de um node na posicao N \n";
    cout << "4-Retirar um node no inicio da lista \n";
    cout << "5-Retirar um node no fim da lista \n";
    cout << "6-Retirar um node na posicao N da lista \n";
    cout << "7-Procurar um node com campo Rg \n";
    cout << "8-Imprimir a Lista \n";
    cout << "9-Sair da Lista \n";    
    cout << "\nEscolha um numero e pressione ENTER: \n";
    cin >> funcaoDesejada;
    

   
    limpatela();
  
    // Variaveis para os novos valores
    string nome;
    int rg,posicao;
    switch (funcaoDesejada)
    {
    case 1:
        cout << "Função escolhida 1 - Insercao de um node no inicio da lista \n";
        cout << "Informe o nome:";
        cin >> nome;
        cout << "Informe o Rg:";
        cin >> rg;
        
        adComecoEncadeada(ponteiroEncadeada,nome,rg);
    break;
    case 2:
        cout << "Função escolhida 2 - Insercao de um node no fim da lista \n";
        cout << "Informe o nome:";
        cin >> nome;
        cout << "Informe o Rg:";
        cin >> rg;
        if(retornaTamanho(ponteiroEncadeada) == 0){
            adComecoEncadeada(ponteiroEncadeada,nome,rg);
        } else{
            adFinalEncadeada(ponteiroEncadeada,nome,rg);
        }
    break;
    case 3:
        cout << "Função escolhida 3 - Insercao de um node na posicao N \n";
        cout << "Informe o nome:";
        cin >> nome;
        cout << "Informe o Rg:";
        cin >> rg;
        cout << "Informe a posicao";
        cin >> posicao;
        if(posicao == 0){
            adComecoEncadeada(ponteiroEncadeada,nome,rg);
        } else if(posicao == retornaTamanho(ponteiroEncadeada) - 1){
            adFinalEncadeada(ponteiroEncadeada, nome, rg);
        } else{
            adPosicaoEncadeada(ponteiroEncadeada, nome, rg, posicao);
        }
    break;
    case 4:
        cout << "Função escolhida 4 - Retirar um node no inicio da lista  \n";
        removeComecoEncadeada(ponteiroEncadeada);
        break;
    case 5:
        cout << "Função escolhida 5 -R etirar um node no fim da lista  \n";
        if(retornaTamanho(ponteiroEncadeada) == 0){
            removeComecoEncadeada(ponteiroEncadeada);
        }else{
             removeFinalEncadeada(ponteiroEncadeada);
        }
        break;
   
    case 6:
           cout << "Função escolhida 6 - Retirar um node na posicao N da lista \n";
           cout << "Informe a posicao:";
           cin >> posicao;
           if(posicao == 0){
            removeComecoEncadeada(ponteiroEncadeada);
           } else if(posicao == retornaTamanho(ponteiroEncadeada) - 1){
            removeFinalEncadeada(ponteiroEncadeada);
           } else {
            removePosicaoEncadeada(ponteiroEncadeada,posicao);
           }
    break;
    case 7:
        cout << "Função escolhda 7 - Procurar um node com campo Rg \n";
        cout << "Informe o Rg:";
        cin >> rg;
        cout  << "O nome do Rg buscado é" buscaRG(ponteiroEncadeada,rg) << "\n";
    break;
    case 8:
        cout << "Função escolhda  8 - Imprimir a Lista \n";
        cout << "\nTamanho Atual:" << retornaTamanho(ponteiroEncadeada) << "\n";
        if(retornaTamanho(ponteiroEncadeada) == 0){
        cout << "Lista Vazia \n";
        }else{
        imprimeEncadeada(ponteiroEncadeada);
    }
    default:
    break;

    }
     }
    return 0;
}