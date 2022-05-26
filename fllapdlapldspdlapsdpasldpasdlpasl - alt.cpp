/* Vers�o beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmosww*/
#include <iostream>
#include <windows.h>
#include <conio.h>
///Fun��o para gerar n�meros randomicos com time
#include<time.h>
///para o getch()
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

using namespace std;


/**
    F L A P B I R D (M2 Algoritmos)
    - Lembrando: n�o permitido o uso de fun��es e vari�veis compostas como structs, vetores e matrizes
    - Corrigir os rastros (p�ssaro e obst�culos)
    - Implementar colis�o
    - Implementar pontua��o (mais um ponto para cada obst�culo superado)
    - Fazer 2 obst�culos simult�neos (obstaculo1 e obstaculo2)
    - Deixar a pontua��o vis�vel durante todo o jogo
    - Definir marcos para acelerar a velocidade
*/



int main()
{
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.

    ///DECLARA��O DE VARIAVEIS
    int bird_x=30, bird_y=10; //posi��o inicila do p�ssaro
    int obstaculo_x=119, obstaculo_y;//posi��o inicial do obstaculo 1
    int tecla;
    int vao_obs_pos, vao_obs_pos2; //variavel posi��o do v�o
    int tamanhovao, tamanhovao2;// variavel tamanho do v�o
    int pontos = 0; // pontos recebe 0 para evital lixo na menoria
    int obstaculo_x2=70, obstaculo_y2;//posi��o inicial do obstaculo 2
    int tempo=0;//v�riavel da velocidade recebe 0 para evital lixo na menoria

    ///GERA POSI��O INICIAL ALEATORIA PARA O OBSTACULO 2
         vao_obs_pos2 = 1 + rand() % 25 ;// gera um n�mero aleat�rio entre 1 e 26
         tamanhovao2 = 3 + rand() % 5;// gera um n�mero aleat�rio entre 3 e 8

    ///DESENHO DO CEN�RIO
    //foi diminuido para caber na tela
    cout<<"------------------------------------------------------------------------------------------------------------------------";
    //cria uma parede no x 10 para pontua��o
    for(int n=1; n<=27;n++) //n � a quantidade de vezes a ser repetida o cout por 27 vezes
    cout<<"          |\n";
        //foi diminuido para caber na tela
    cout<<"------------------------------------------------------------------------------------------------------------------------";


    while (true) { //esse la�o faz o jogo rodar para sempre

        ///POSICIONA O P�SSARO
        coord.X = bird_x;    coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<char(190);

        ///POSICIONA O OBST�CULO 1
        obstaculo_y=1 ;
        while(obstaculo_y<28){
            coord.X = obstaculo_x;    coord.Y = obstaculo_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y < vao_obs_pos || obstaculo_y > vao_obs_pos +  tamanhovao){ //o v�o e somado com tamanho para que as posi��es n�o se sobrep�am
                cout<<char(219);
            }
            obstaculo_y++;
        }

        ///POSICIONA O OBST�CULO 2
        obstaculo_y2=1 ;
        while(obstaculo_y2<28){
            coord.X = obstaculo_x2;    coord.Y = obstaculo_y2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y2 < vao_obs_pos2 || obstaculo_y2 > vao_obs_pos2 +  tamanhovao2){ //o v�o e somado com tamanho para que as posi��es n�o se sobrep�am
                cout<<char(219);
            }
            obstaculo_y2++;
        }

        ///POSICIONA PONTUA��O.
        coord.X = 1; //Coordenada x e y fixa
        coord.Y = 4;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout << "PONTOS:\n " << pontos;

        ///CONTAGEM DA PONTUA��O
        if((bird_x == obstaculo_x) || (bird_x == obstaculo_x2)) //se o x do passaro for igual do obst�culo conta +1 na pontua��o
        pontos++; //Igual se escrever pontos = ponros + 1

        ///GERA UM N�MERO ALEAT�RIO PARA O TAMANHO DO V�O
        if (obstaculo_x == 119) { // se o obstaculo est� em sua posi��o inicial
        ///GERADOR DE NUMEROS ALEATORIOS
         srand(time(NULL));//semente randomica gerada a partir da hora do sistema
         vao_obs_pos = 1 + rand() % 25 ;// gera um n�mero aleat�rio entre 1 e 26
         tamanhovao = 3 + rand() % 5;// gera um n�mero aleat�rio entre 3 e 8
        }

        if (obstaculo_x2 == 119) { // se o obstaculo est� em sua posi��o inicial
        ///GERADOR DE NUMEROS ALEATORIOSb
         vao_obs_pos2 = 1 + rand() % 25 ;// gera um n�mero aleat�rio entre 1 e 26
         tamanhovao2 = 3 + rand() % 5;// gera um n�mero aleat�rio entre 3 e 8
        }

        ///VERIFICA COLIS�O COM O TETO
        if (bird_y == 0  || bird_y == 28  ) //se posi��o y do p�ssaro e igual a altura y do teto (1) ou igual a altura y do ch�o (30)
            break;

        ///VERIFICA COLIS�O COM O OBST�CULO
        // se a posi��o x do pass�ro for igual a do obstaculo e
        //a posi��o y do pass�ro for menor que a posi��o do v�o ou maior que a posi�a� do v�o mais seu tamanho
        if((bird_x == obstaculo_x) && // x do p�ssaro tem que ser igual do obst�culo
            (bird_y < vao_obs_pos || bird_y > vao_obs_pos +  tamanhovao))// s�o as partes do obstaculo sem contar o v�o
            break;

        if((bird_x == obstaculo_x2) && // x do p�ssaro tem que ser igual do obst�culo
            (bird_y < vao_obs_pos2 || bird_y > vao_obs_pos2 +  tamanhovao2))// s�o as partes do obstaculo sem contar o v�o
            break;

        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { //verifica se uma tecla foi pressionada
            tecla=getch(); //verifica comando do jogador
        }
        if ( tecla==' ' || tecla== 'w' || tecla=='W' ){ //se tecla w,W ou espa�o pressionada pass�ro sobe uma posi��o
            bird_y--; // p�ssaro sobe
            tecla='0';
        }
        else {
            bird_y++;//pass�ro cai 1 posi��o se n�o for precionado para subir
        }

        ///OBST�CULO AVAN�A UMA POSI��O PARA ESQUERDA
        obstaculo_x=obstaculo_x-1;
        obstaculo_x2=obstaculo_x2-1;

        ///TEMPO DE ESPERA.
        tempo=(100-(10*(pontos/5))); //Tempo dividido por 5 e multiplicado por 10 e se diminui o tempo inicial de 100
        Sleep(tempo);

        ///APAGA OS RASTROS DO P�SSARO
        coord.X = bird_x  ;    coord.Y = bird_y -1 ; //a coordenada y para apagar e o y do p�ssaro -1
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<" ";
        coord.X = bird_x  ;    coord.Y = bird_y +1 ;//a coordenada y para apagar e o y do p�ssaro +1
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<" ";

        ///APAGA OS RASTROS DO OBST�CULO 1
        obstaculo_y=1;
        while(obstaculo_y<28){
            coord.X = obstaculo_x +1;    coord.Y = obstaculo_y;//a coordenada x para apagar e o x do obstaculo +1
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y > vao_obs_pos || obstaculo_y < vao_obs_pos +  tamanhovao){// s�o as partes do obstaculo sem contar o v�o
                cout<<" ";
            }
            obstaculo_y++;
        }
        ///APAGA OS RASTROS DO OBST�CULO 2
        obstaculo_y2=1 ;
        while(obstaculo_y2<28){
            coord.X = obstaculo_x2 +1;    coord.Y = obstaculo_y2;//a coordenada x para apagar e o x do obstaculo +1
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y2 > vao_obs_pos2 || obstaculo_y2 < vao_obs_pos2 +  tamanhovao2){// s�o as partes do obstaculo sem contar o v�o
                cout<<" ";
            }
            obstaculo_y2++;
        }

        ///SE O OBSTACULO CHEGA A POSI��O 10 VOLTA PARA POSI��O INICIAL
        if ( obstaculo_x <=10 ) //obstaculo 1
            obstaculo_x = 119;
        if ( obstaculo_x2 <=10) //obstaculo 2
            obstaculo_x2 = 119;

    }

    return 0;
}
