/* Versão beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmosww*/
#include <iostream>
#include <windows.h>
#include <conio.h>
///Função para gerar números randomicos com time
#include<time.h>
///para o getch()
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

using namespace std;


/**
    F L A P B I R D (M2 Algoritmos)
    - Lembrando: não permitido o uso de funções e variáveis compostas como structs, vetores e matrizes
    - Corrigir os rastros (pássaro e obstáculos)
    - Implementar colisão
    - Implementar pontuação (mais um ponto para cada obstáculo superado)
    - Fazer 2 obstáculos simultâneos (obstaculo1 e obstaculo2)
    - Deixar a pontuação visível durante todo o jogo
    - Definir marcos para acelerar a velocidade
*/



int main()
{
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.

    ///DECLARAÇÂO DE VARIAVEIS
    int bird_x=30, bird_y=10; //posição inicila do pássaro
    int obstaculo_x=119, obstaculo_y;//posição inicial do obstaculo 1
    int tecla;
    int vao_obs_pos, vao_obs_pos2; //variavel posição do vão
    int tamanhovao, tamanhovao2;// variavel tamanho do vão
    int pontos = 0; // pontos recebe 0 para evital lixo na menoria
    int obstaculo_x2=70, obstaculo_y2;//posição inicial do obstaculo 2
    int tempo=0;//váriavel da velocidade recebe 0 para evital lixo na menoria

    ///GERA POSIÇÃO INICIAL ALEATORIA PARA O OBSTACULO 2
         vao_obs_pos2 = 1 + rand() % 25 ;// gera um número aleatório entre 1 e 26
         tamanhovao2 = 3 + rand() % 5;// gera um número aleatório entre 3 e 8

    ///DESENHO DO CENÁRIO
    //foi diminuido para caber na tela
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    //cria uma parede no x 10 para pontuação
    for(int n=1; n<=27;n++) //n é a quantidade de vezes a ser repetida o cout por 27 vezes
    cout<<"          |\n";
        //foi diminuido para caber na tela
    cout<<"------------------------------------------------------------------------------------------------------------------------";


    while (true) { //esse laço faz o jogo rodar para sempre

        ///POSICIONA O PÁSSARO
        coord.X = bird_x;    coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<char(190);

        ///POSICIONA O OBSTÁCULO 1
        obstaculo_y=1 ;
        while(obstaculo_y<28){
            coord.X = obstaculo_x;    coord.Y = obstaculo_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y < vao_obs_pos || obstaculo_y > vao_obs_pos +  tamanhovao){ //o vão e somado com tamanho para que as posições não se sobrepõam
                cout<<char(219);
            }
            obstaculo_y++;
        }

        ///POSICIONA O OBSTÁCULO 2
        obstaculo_y2=1 ;
        while(obstaculo_y2<28){
            coord.X = obstaculo_x2;    coord.Y = obstaculo_y2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y2 < vao_obs_pos2 || obstaculo_y2 > vao_obs_pos2 +  tamanhovao2){ //o vão e somado com tamanho para que as posições não se sobrepõam
                cout<<char(219);
            }
            obstaculo_y2++;
        }

        ///POSICIONA PONTUAÇÃO.
        coord.X = 1; //Coordenada x e y fixa
        coord.Y = 4;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "PONTOS:\n " << pontos;

        ///CONTAGEM DA PONTUAÇÂO
        if((bird_x == obstaculo_x) || (bird_x == obstaculo_x2)) //se o x do passaro for igual do obstáculo conta +1 na pontuação
        pontos++; //Igual se escrever pontos = ponros + 1

        ///GERA UM NÚMERO ALEATÓRIO PARA O TAMANHO DO VÃO
        if (obstaculo_x == 119) { // se o obstaculo está em sua posição inicial
        ///GERADOR DE NUMEROS ALEATORIOS
         srand(time(NULL));//semente randomica gerada a partir da hora do sistema
         vao_obs_pos = 1 + rand() % 25 ;// gera um número aleatório entre 1 e 26
         tamanhovao = 3 + rand() % 5;// gera um número aleatório entre 3 e 8
        }

        if (obstaculo_x2 == 119) { // se o obstaculo está em sua posição inicial
        ///GERADOR DE NUMEROS ALEATORIOSb
         vao_obs_pos2 = 1 + rand() % 25 ;// gera um número aleatório entre 1 e 26
         tamanhovao2 = 3 + rand() % 5;// gera um número aleatório entre 3 e 8
        }

        ///VERIFICA COLISÃO COM O TETO
        if (bird_y == 0  || bird_y == 28  ) //se posição y do pássaro e igual a altura y do teto (1) ou igual a altura y do chão (30)
            break;

        ///VERIFICA COLISÃO COM O OBSTÁCULO
        // se a posição x do passáro for igual a do obstaculo e
        //a posição y do passáro for menor que a posição do vão ou maior que a posiçaõ do vão mais seu tamanho
        if((bird_x == obstaculo_x) && // x do pássaro tem que ser igual do obstáculo
            (bird_y < vao_obs_pos || bird_y > vao_obs_pos +  tamanhovao))// são as partes do obstaculo sem contar o vão
            break;

        if((bird_x == obstaculo_x2) && // x do pássaro tem que ser igual do obstáculo
            (bird_y < vao_obs_pos2 || bird_y > vao_obs_pos2 +  tamanhovao2))// são as partes do obstaculo sem contar o vão
            break;

        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { //verifica se uma tecla foi pressionada
            tecla=getch(); //verifica comando do jogador
        }
        if ( tecla==' ' || tecla== 'w' || tecla=='W' ){ //se tecla w,W ou espaço pressionada passáro sobe uma posição
            bird_y--; // pássaro sobe
            tecla='0';
        }
        else {
            bird_y++;//passáro cai 1 posição se não for precionado para subir
        }

        ///OBSTÁCULO AVANÇA UMA POSIÇÃO PARA ESQUERDA
        obstaculo_x=obstaculo_x-1;
        obstaculo_x2=obstaculo_x2-1;

        ///TEMPO DE ESPERA.
        tempo=(100-(10*(pontos/5))); //Tempo dividido por 5 e multiplicado por 10 e se diminui o tempo inicial de 100
        Sleep(tempo);

        ///APAGA OS RASTROS DO PÁSSARO
        coord.X = bird_x  ;    coord.Y = bird_y -1 ; //a coordenada y para apagar e o y do pássaro -1
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<" ";
        coord.X = bird_x  ;    coord.Y = bird_y +1 ;//a coordenada y para apagar e o y do pássaro +1
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<" ";

        ///APAGA OS RASTROS DO OBSTÁCULO 1
        obstaculo_y=1;
        while(obstaculo_y<28){
            coord.X = obstaculo_x +1;    coord.Y = obstaculo_y;//a coordenada x para apagar e o x do obstaculo +1
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y > vao_obs_pos || obstaculo_y < vao_obs_pos +  tamanhovao){// são as partes do obstaculo sem contar o vão
                cout<<" ";
            }
            obstaculo_y++;
        }
        ///APAGA OS RASTROS DO OBSTÁCULO 2
        obstaculo_y2=1 ;
        while(obstaculo_y2<28){
            coord.X = obstaculo_x2 +1;    coord.Y = obstaculo_y2;//a coordenada x para apagar e o x do obstaculo +1
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y2 > vao_obs_pos2 || obstaculo_y2 < vao_obs_pos2 +  tamanhovao2){// são as partes do obstaculo sem contar o vão
                cout<<" ";
            }
            obstaculo_y2++;
        }

        ///SE O OBSTACULO CHEGA A POSIÇÃO 10 VOLTA PARA POSIÇÂO INICIAL
        if ( obstaculo_x <=10 ) //obstaculo 1
            obstaculo_x = 119;
        if ( obstaculo_x2 <=10) //obstaculo 2
            obstaculo_x2 = 119;

    }

    return 0;
}
