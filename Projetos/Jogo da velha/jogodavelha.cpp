#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>

// Area de definicicao de cabecarios
void menuInicial();


using namespace std;

void limpatela(){
   #if defined(__linux__) || defined(__unix__) 
           system("clear");
    #else defined(_WIN32) || defined(_WIN64)
            system("CLS");
    #endif
}

void imprimeTabuleiro(char tabuleiro[3][3],int linha,int coluna){


    for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            
           cout << tabuleiro[linha][coluna];
          
        }   
        
        cout << "\n";
    }

}

void gabaritoTabuleiro(){

    cout <<"Mapa de Posicoes:";
    cout << "\n 7 | 8 | 9";
    cout << "\n 4 | 5 | 6";
    cout << "\n 1 | 2 | 3";
}

void iniciaTabuleiro(char tabuleiro[3][3],int linha,int coluna){

     for(linha = 0; linha < 3; linha++){
        for(coluna = 0; coluna < 3; coluna++){
            tabuleiro[linha][coluna] = '-';
        }   
    }
   
}


int confereJogo(char tabuleiro[3][3],int linha,int coluna){


        // Verificando Linha
        
        for(linha = 0;linha < 3;linha++){
        if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
            return 1;
        }else if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
            return 2;
        }
        }

        // Verificando Coluna
          for(coluna   = 0;coluna < 3;coluna++){
        if(tabuleiro[0][coluna] != '-' && tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
            if(tabuleiro[0][coluna] == 'X'){
                 return 1;
            }else if(tabuleiro[0][coluna] == 'O'){
                 return 2;
            }
        }
        }
        // Verificando Diagonal
        if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[2][2] == tabuleiro[1][1]){
            if(tabuleiro[0][0] == 'X'){
                return 1;
            }else if(tabuleiro[0][0] == 'O'){
                 return 2;
            }
        }
        // Verificando a digital inversa
           if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
            if(tabuleiro[0][2] == 'X'){
                return 1;
            }else if(tabuleiro[0][2] == 'O'){
                 return 2;
            
            }
        }
    return 0;
}



void jogo(string jogadorUm, string jogadorDois, int pontuacaoJogadorUm, int pontuacaoJogadorDois){


    // Variaveis Gerais
    char tabuleiro[3][3];                                   // Tabuleiro
    int linha, coluna, posicao;                             // variaveis auxiliares para funcoes    
    int linhaJogada, colunaJogada,posicaoJogada;            // variaveis auxiliares para ler e alterar o tabuleiro
    int turnodoJogador = 1;                                 // Turno do jogador
    int estadoJogo = 1;                                     // Estado do jogo
    int rodada = 1;                                         // rodada
    int escolha = 0;                                        // Reiniciar jogo 
    bool posicionouJogada;
    string jogadorAtual;                                    // Nomes dos jogadores 
  
    iniciaTabuleiro(tabuleiro,linha,coluna);


  

    while (rodada < 10 && estadoJogo == 1){
    
    limpatela();


    imprimeTabuleiro(tabuleiro,linha,coluna);
    gabaritoTabuleiro();

   cout << "\nRodada:" << rodada << "\n" ;
   cout << "Pontuacao: " << jogadorUm << " " << pontuacaoJogadorUm ;
   cout << "\nPontuacao: " << jogadorDois << " " << pontuacaoJogadorDois ;
   cout << "\n";
        // Verifica quem é o proximo
     if (turnodoJogador == 1) {
            jogadorAtual = jogadorUm;
        }else{
           jogadorAtual = jogadorDois;
        }

    posicionouJogada = false;

    


    while (posicionouJogada == false){
      int posicoes[9][2] = {{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};
    
    cout << jogadorAtual << " sua vez \n";
    cout << "Digite uma posicao conforme o mapa:";
    cin >> posicaoJogada;
            
            linhaJogada = posicoes[posicaoJogada-1][0];
            colunaJogada = posicoes[posicaoJogada-1][1];
       
      // verfifica se a posicao jogada existe
         while (posicaoJogada > 9 || posicaoJogada < 1)
         {
                limpatela();
                imprimeTabuleiro(tabuleiro,linha,coluna);
                gabaritoTabuleiro(); 
                cout << "\n";
                cout << jogadorAtual << " o numero digitado é invalido \n";
                cout << "Digite uma posicao conforme o mapa:";
                cin >> posicaoJogada;
                linhaJogada = posicoes[posicaoJogada-1][0];
                colunaJogada = posicoes[posicaoJogada-1][1];
         }
         
         // Verifica se a posicao jogada esta vazia
        if(tabuleiro[linhaJogada][colunaJogada] == '-'){
            if(turnodoJogador == 1){
            tabuleiro[linhaJogada][colunaJogada] = 'X';
            turnodoJogador++;
        } else {
             tabuleiro[linhaJogada][colunaJogada] = 'O';
             turnodoJogador--;
        }
        posicionouJogada = true;
        } 
        }

        // verifica quem ganhou
       if(confereJogo(tabuleiro,linha,coluna) == 1){
        cout << jogadorUm << " ganhou \n";
        pontuacaoJogadorUm++;
           estadoJogo = 0;
       }else if(confereJogo(tabuleiro,linha,coluna) == 2){
        cout << jogadorDois << " ganhou \n";
         pontuacaoJogadorDois++;
          estadoJogo = 0;
       } 

          rodada++;
     }
  
    imprimeTabuleiro(tabuleiro,linha,coluna);  
       if(rodada == 10 && estadoJogo == 1){
        cout << "O jogo deu velha";
     }

    cout << "\nFim de jogo ";
    cout << "\nDeseja jogar novamente?";
    cout << "\n1-Continuar Jogando";
    cout << "\n2-Menu Inicial";
    cout << "\n3-Sair\n";
    cin >> escolha;
    if(escolha == 1){
        jogo(jogadorUm,jogadorDois,pontuacaoJogadorUm,pontuacaoJogadorDois);
    }else if(escolha == 2){
        menuInicial();
        }else{
            estadoJogo == 0; 
        }
        
}

void menuInicial(){

    string jogadorUm , jogadorDois;                          // Nome do jogador
    int opcao = 0;
    int pontuacaoJogadorUm,pontuacaoJogadorDois = 0;
    string gitHub = "https://github.com/diegosou4";           // Meu github
    while (opcao < 1 || opcao > 3)
    {
        limpatela();
        cout << "Bem vindo ao Jogo da velha: ";
        cout << "\n1-Jogar";
        cout << "\n2-Sobre";
        cout << "\n3-Sair";
        cout << "\nEscolha uma opção e aperte ENTER \n";
        cin >> opcao;
        if(opcao > 3){
            limpatela();
            cout << "Comando Invalido \n";
        }
    }
    switch (opcao)
    {
    case 1:
    limpatela();
    cout << "Jogo iniciado: \n";
      //  Coleta nomes dos jogadores
    cout << "Digite o nome do jogador numero 1:";
    cin >> jogadorUm;
    cout << "Digite o nome do jogador numero 2:";
    cin >> jogadorDois;
    jogo(jogadorUm,jogadorDois,pontuacaoJogadorUm,pontuacaoJogadorDois);
        break;
    case 2:
    limpatela();
        cout << "Informacoes do jogo:\n";
        cout << "Jogo desenvolvido com curso de C++ do professor John Haste\n";
        cout << "Foram feitos alguns updates e correçoes de bugs por mim mesmo \n";
        cout << "Feito por Diego, acesse meu github: ";
        cout << gitHub;
        cout << "\n1- Voltar";
        cout << "\n2- Sair";
        cin >> opcao;
        if(opcao == 1){
            menuInicial();
        }
        
        break;
    case 3:
        limpatela();
        cout << "Ate mais";
        break;
    default:
        cout << "Comando Invalido";
        break;
    }
}

int main(){

    menuInicial();
    
    return 0;
}