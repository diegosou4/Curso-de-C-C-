#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

//Cabeçarios funcoes
void menuInicial();


void limpatela(){
   #if defined(__linux__) || defined(__unix__) 
           system("clear");
    #elif(_WIN32) || defined(_WIN64)
            system("CLS");
    #endif
 
}

void imprimeTabuleiros(char tabuleiro[10][10]){
    
    //Mapa indicador de colunas
    int cont;
    for(cont= 0;cont <10;cont++){
        if(cont == 0){
            cout << "    ";
            cout << cont;
            cont++;
        }
        cout << "  "<< cont;
    }
    cout << "\n";
    
     int linha, coluna; 
    
        for(linha = 0; linha < 10; linha++){         // Imprime os valores
        cout << linha << "- ";
        for(coluna = 0; coluna < 10; coluna++){
            cout << "|" << tabuleiro[linha][coluna] << "|";
        }
        cout << "\n";
    }
}

void iniciaTabuleiro(char tabuleiro[10][10],char mascara[10][10] ){

    int linha, coluna;                          // auxiliares
    
    for(linha = 0; linha < 10; linha++){         // Percorrendo a matriz e adicionando valores
        for(coluna = 0; coluna < 10; coluna++){
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
    }
}

void posicionaBarcos(char tabuleiro[10][10]){
    
    int quantidade = 20;                            //Quantidade de barcos
    int quantidadePocisionada = 0;
    while (quantidadePocisionada < quantidade)
    {
        // gera numeros aleatorios
        int linhaBarco = rand() % 10;               // gera numero aleatorio de 0 a 9
        int colunaBarco= rand() % 10;               // gera numero aleatorio de 0 a 9
        // confere se a coluna e a linha já tem um barco
        if(tabuleiro[linhaBarco][colunaBarco] == 'A'){
        // posiciona o barco
        tabuleiro[linhaBarco][colunaBarco] = 'P';
        quantidadePocisionada++;
        }
      
    }
    
}
void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem){


switch (tabuleiro[linhaJogada][colunaJogada])
        {
        case 'P':
            *pontos = *pontos + 10;
            *mensagem = "Boa, acertou um barco pequeno";
            break;
        case 'A':
             *mensagem = "Acertou a agua :/";
            break;
        default:
            break;
        }
}

void verificaLinhaColuna(int *colunaJogada, int *linhaJogada, string nomeJogador){

    while (*colunaJogada >= 10 || *linhaJogada >= 10){
        if(*linhaJogada >= 10){
            cout <<  "Linha não encontrada \n" << nomeJogador <<" informe uma nova linha:" ;    
            cin >> *linhaJogada;
        }
        if(*colunaJogada >= 10){
            cout <<  "Coluna não encontrada \n" << nomeJogador <<" informe uma nova coluna:" ;    
            cin >>  *colunaJogada;
        }
    }
}

void jogo(string nomeJogador){

    char tabuleiro[10][10], mascara[10][10] ;                     //Matriz com duas dimensoes
    int linhaJogada, colunaJogada;
    int estadoDejogo = 1;                                          // 1= Acontecendo 0= fim de jogo
    int maximodeTentativas = 10;                                  // Maximo de tentativas
    int tentativas = 0;                                          // tentativas
    int pontos = 0;                                             // Responsavel pelo pontos do jogador
    int opcaoFim = 0;                                          // Opção para o usuario decidir o que fazer quando terminar o jogo 
    string mensagem = "Bem vindo ao Jogo";                     // Mensagem de feedback para o jogador
   
    
   

    iniciaTabuleiro(tabuleiro, mascara);

    posicionaBarcos(tabuleiro);

    while (tentativas < maximodeTentativas || pontos < 10) {
          
            
        limpatela();
        imprimeTabuleiros(mascara);

        cout << "\nPontos:" << pontos << " Tentativas Restantes:" << maximodeTentativas - tentativas;
        cout << "\n" << mensagem;

        cout << "\n" << nomeJogador << ", digite uma linha:";
        cin >> linhaJogada;
        cout << nomeJogador << ", digite uma coluna:";
        cin >> colunaJogada;

        verificaLinhaColuna(&colunaJogada,&linhaJogada, nomeJogador);

        while(mascara[linhaJogada][colunaJogada] == 'A' || mascara[linhaJogada][colunaJogada] == 'P'){
            cout <<"Voce ja abriu essa casa, tente novamente";
            cout << "\n" << nomeJogador << ", digite uma linha:";
            cin >> linhaJogada;
            cout << nomeJogador << ", digite uma coluna:";
            cin >> colunaJogada;

        }

        while(mascara[linhaJogada][colunaJogada] == '*'){
        verificaTiro(tabuleiro,linhaJogada,colunaJogada, &pontos, &mensagem);
        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];
        tentativas++;
        }
        limpatela();
    }
        
        
        cout << "Fim de jogo, o que deseja fazer?";
        cout << "\n1-Jogar Novamente";
        cout << "\n2-Ir para o menu";
        cout << "\n3-Sair do jogo \n";  
        cin >> opcaoFim;    
        switch (opcaoFim)
        {
        case 1:
            jogo(nomeJogador);
        break;
        case 2:
            menuInicial();
        break;
        case 3:
        break;
        default:
            break;
        }  
}
void menuInicial(){
    
                                                 
    int opcao = 0;                                              // Opcao escolhida pelo usuario
    string nomeJogador;                                        // nome do jogador
    string gitHub = "https://github.com/diegosou4";           // Meu github
    
     while (opcao < 1 || opcao > 3)
    {
    limpatela();
    cout << "Bem vindo ao Jogo de Batalha Naval!!";
    cout << "\n1- Jogar";
    cout << "\n2- Sobre";
    cout << "\n3- Sair";
    cout << "\nEscolha uma opção e aperte ENTER \n";
   
    // Leitura da opcao
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        //Inicia o jogo
         cout << "Digite seu nome:";
         cin >> nomeJogador;
        jogo(nomeJogador);
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
        cout << "Ate mais";
    break;
    default:
        break;
    }


    }
    
}





int main(){
    // escolhe um aleatorio 
    srand((unsigned)time(NULL));
    menuInicial();


    return 0;
}