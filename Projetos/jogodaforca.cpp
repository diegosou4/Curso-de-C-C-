#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpatela(){
   #if defined(__linux__) || defined(__unix__) 
           system("clear");
    #else defined(_WIN32) || defined(_WIN64)
            system("CLS");
    #endif
}

string lowerCaso(string palavra, int tamanhoPalavra){         // Coloca a palavra em minusculo

    int cont;
    string novapalavra;
    for(cont = 0; cont < tamanhoPalavra; cont++){
        if(palavra[cont] >= 65 && palavra[cont] <= 90 ){   // Verifica conforme a table ASCII
            palavra[cont] = palavra[cont] + 32;
        }
        novapalavra = palavra;
    }
     return novapalavra;
}



string retornaPalavraAleatoria(){                                 // Banco de dados de Palavras aleatorias  
      // vetor palavras disponiveis
    string palavrasfrutas[8] = {"abacaxi", "manga", "morango", "laranja",
    "melancia","limao","banana", "pera"};

    // indique gera no intervalo de {0,1,2,3,4,5,6,7}
    int indiceAleatorio = rand() % 8;

  return palavrasfrutas[indiceAleatorio];

}

char verificaTamanhoLetra(int tamanhoLetra,char letra, string letrasp){
      while (tamanhoLetra > 1){
            cout << "\nVoce adicionou mais de uma letra por favor tente novamente:";
            cin >> letrasp;
            tamanhoLetra = letrasp.size();                  // Foi feita essa função porque quando era passado
                                                            // duas letras ele fazia o loop duas vezes
        } 
            letra = letrasp[0];
    
        return letra;
}

string retornaPalavraComMascara(string palavra, int tamanhodaPalavra){

    int cont = 0;
    string palavraComMascara;                           // Retorna a palavra ___
    // Coloca uma mascara 
    while (cont < tamanhodaPalavra)
    {
        palavraComMascara += "_";
        cont++;
    }
    return palavraComMascara;

}
void exibeStatus(string palavraComMascara, int tamanhodaPalavra, int tentativasRestantes,string letrasjaAriscadas, string mensagem){
    
    cout << mensagem;
    cout << "A palavra: "<< palavraComMascara << "(Tamanho:" << tamanhodaPalavra << ")\n" ;
    cout << "Tentativas restantes:" << tentativasRestantes << "\n";
    int cont;
    // Adiciona virgula
    cout << "\nLetras já ariscadas: " ;
    for(cont = 0;cont < letrasjaAriscadas.size(); cont++){
        cout << letrasjaAriscadas[cont] << ", ";
    }
}

void exibeStatusFinal(int numerodeJogadores,string jogadorUm, string jogadorDois, int status,int verificaJogador){

    if(status == 1){
        if(verificaJogador == 1){                                                   // função para ser exibida no final do jogo
            cout << "Parabens " << jogadorUm <<  " Voce venceu \n";
        } else{
            cout << "Parabens " << jogadorDois <<  " Voce venceu \n";
        }
    } else if(status == 2){
        if(verificaJogador == 1){
            cout << jogadorUm <<  " Voce perdeu \n";
        } else{
            cout << jogadorDois << " Voce perdeu \n";
        }
    }
}



int jogar(int numerodeJogadores, string *jogadorUm, string *jogadorDois, int *verificaJogador){


    string palavra;                                           // Palavra
    if(numerodeJogadores == 1){
        palavra = retornaPalavraAleatoria();
    }else{
        
        int indiceAleatorio = rand() % 2;                    // Gerando indice aleatorio
    
         cout << "Digite o nome do jogador numero 1: ";
         cin >> *jogadorUm;
         cout << "Digite o nome do jogador numero 2: ";
         cin >> *jogadorDois;
       
        limpatela();
        if(indiceAleatorio == 1){
            cout <<  "O jogador: " << *jogadorUm << " Deve informar a palavra \n";
            cout <<  "O jogador: " << *jogadorDois << " Deve advinhar a palavra \n";
            *verificaJogador = 1;
        }else{
            cout <<  "O " << *jogadorDois << " deve informar a palavra\n";
            cout <<  "O " << *jogadorUm << " deve advinhar a palavra \n";
            *verificaJogador = 2;
        }
       cout << "Digite uma palavra (tecle 1 se quiser que o sistema gere uma palavra aleatoria) ";
       cin >> palavra;
        if(palavra == "1"){
        palavra = retornaPalavraAleatoria();
    }
    }
    
    int tamanhodaPalavra = palavra.size();          // tamanho da palavra

    palavra = lowerCaso(palavra, tamanhodaPalavra);  // Caso o usuario passe alguma letra maiscula
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhodaPalavra);
    

    char letra;                                   // Letra arriscada pelo usuario
    int tentativas = 0,maximoDeTentativas = 10;   // Numero de tentativas
    int cont = 0;                                // auxiliar para laço de repeticao
    int opcao;                                   // Opcoes finais
    int tamanhoLetra;                            // Tamanho da letra
    string palavraArriscada;                     // Palavra completa que jogador arriscou
    string letrasjaAriscadas;                    // Acumula as palavras ariscadas
    string mensagem;                             // Feedback do jogador
    string stringLetra;                          // letra passada pelo usuario
    bool jaDigitouletra = false;                 // Auxiliar para saber se ja foi digitada
    bool acertouLetra = false;                
    
    mensagem = "Bem vindo ao jogo \n";
   
    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){
                     
        limpatela();

        exibeStatus(palavraComMascara, tamanhodaPalavra, maximoDeTentativas - tentativas, letrasjaAriscadas, mensagem);
        
        // Le um palpite
        cout << "\nDigite uma letra (Ou digite 1 para arriscar a palavra)";
        cin >> stringLetra;

        tamanhoLetra = stringLetra.size();
      
        letra = verificaTamanhoLetra(tamanhoLetra,letra,stringLetra);
        if(letra == '1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                mensagem = "Voce acertou a palavra\n";
                palavraComMascara = palavraArriscada;
            }else{
                tentativas = maximoDeTentativas;
            }
        }    
        for(cont = 0; cont < tentativas;cont++){
            if(letrasjaAriscadas[cont] == letra){
                mensagem = "Essa letra já foi adicionada\n";
                jaDigitouletra = true;
            }
        }
        if(jaDigitouletra == false){
            letrasjaAriscadas += tolower(letra);
            // Percorre a palavra real 
               for(cont = 0; cont < tamanhodaPalavra;cont++){
                      //  se a letra existir muda a palavra com mascara
                          if(palavra[cont] == tolower(letra)){
        
                           palavraComMascara[cont] = palavra[cont];
                          
                            acertouLetra = true;
                             }
                         }
                // aumenta uma tentativa realizada
        
            if(acertouLetra == false){
            mensagem = "Voce errou uma letra \n";
            } else {
                  mensagem = "Acertou uma letra \n";
                  
            }
     tentativas++;  
        
  }
    acertouLetra = false;                   // Reinicia auxiliares
    jaDigitouletra = false;      
         
}
    int status = 0;                  // Informa vitoria ou derrota para o multiplayer
    if(palavra == palavraComMascara){
    limpatela();
         if(numerodeJogadores == 1){
            cout <<  "Parabens voce venceu \n";
        }
        else{
            status = 1;                   // Vitoria = 1
            exibeStatusFinal(numerodeJogadores,*jogadorUm,*jogadorDois,status, *verificaJogador);
        }
        cout << "Deseja jogar denovo?\n";
        cout << "1-Sim\n";
        cout << "2-Nao\n";
        cin >> opcao;
        return opcao;
    } else {
    limpatela();
          if(numerodeJogadores == 1){
            cout << "Infelizmente voce perdeu \n";
        }
        else{
            status = 2;
         exibeStatusFinal(numerodeJogadores,*jogadorUm,*jogadorDois,status, *verificaJogador);
        }
        cout << "Deseja tentar denovo?\n";
        cout << "1-Sim\n";
        cout << "2-Nao\n";
        cin >> opcao;
        return opcao;
    }
}




void menuInicial(){
    
    // Opcao escolhida pelo usuario
    int opcao = 0;
    string jogadorUm, jogadorDois = "";
    int verificaJogador;
     while (opcao < 1 || opcao > 3)
    {
    limpatela();
    cout << "Bem vindo ao Jogo!!";
    cout << "\n1- Jogar";
    cout << "\n2- Jogar em Dupla";
    cout << "\n3- Sobre";
    cout << "\n4- Sair";
    cout << "\nEscolha uma opçao e aperte ENTER \n";
   
    // Leitura da opcao
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        //Inicia o jogo
        cout << "Jogo Iniciado \n";
        if(jogar(1, &jogadorUm,&jogadorDois, &verificaJogador) == 1){
            menuInicial();
        };
    break;
    case 2:
           //Inicia o jogo
        cout << "Jogo Iniciado \n";
        if(jogar(2, &jogadorUm, &jogadorDois,&verificaJogador) == 1){
            menuInicial();
        };
    break;
    case 3:
        limpatela();
        cout << "Informacoes do jogo:\n";
        cout << "Jogo desenvolvido com curso de C++ do professor John Haste\n";
        cout << "Foram feitos alguns updates e correçoes de bugs por mim mesmo \n";
        cout << "Feito por Diego, acesse meu github:https://github.com/diegosou4 \n";
        cout << "\n1- Voltar";
        cout << "\n2- Sair";
        cin >> opcao;
        if(opcao == 1){
            menuInicial();
        }
    break;
    case 4:
        limpatela();
        cout << "Ate mais!!";
        exit(0);
       
    break;
    default:
        break;
    }
    }
}


int main(){

    // gera um numero aleatorio
    srand( (unsigned)time(NULL));
    menuInicial();
    return 0;
}