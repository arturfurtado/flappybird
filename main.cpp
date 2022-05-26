/*Versão beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmos*/
#include <iostream>
#include <windows.h>
#include <conio.h> ///para o getch()
#include <time.h> ///para habilitar a função time

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

    srand(time(NULL));///SEMENTE RANDOMICA GERADA A PARTIR DA HORA DO SISTEMA

    int numeroAleatorio1, numeroAleatorio2;
    int bird_x=5, bird_y=10;
    int obstaculo_x1=50, obstaculo_y1, obstaculo_x2=100, obstaculo_y2;
    int tecla;
    int i = 1;
    int escolha;
    int point = 0;
    int time = 200;

    while (true) { //esse laço faz o jogo rodar para sempre

        ///DEFINIÇÃO DA ALEATORIEDADE DOS OBSTACULOS
        if(obstaculo_x1 <= 0)///QUANDO O OBSTACULO PASSA A BORDA NO EIXO X GERA UM NOVO OBSTACULO ALEATORIO
            numeroAleatorio1 = rand()%10; ///DEFINE UM NUMERO ALEATORIO

        if(numeroAleatorio1 < 2){ ///VERIFICA UM VALOR MINIMO PARA ESSE NUMERO ALEATORIO
            numeroAleatorio1 = 2;
        }else if(numeroAleatorio1 >14){ ///VERIFICA UM VALOR MAXIMO
            numeroAleatorio1 = 14;
        }

        if(obstaculo_x2 <= 0)///QUANDO O OBSTACULO PASSA A BORDA NO EIXO X GERA UM NOVO OBSTACULO ALEATORIO
            numeroAleatorio2 = rand()%10; ///DEFINE UM NUMERO ALEATORIO

        if(numeroAleatorio2 < 2){ ///VERIFICA UM VALOR MINIMO PARA ESSE NUMERO ALEATORIO
                numeroAleatorio2 = 2;
        }else if(numeroAleatorio2 > 14){ ///VERIFICA UM VALOR MAXIMO
                numeroAleatorio2 = 14;
        }

        ///DESENHO DO CENÁRIO
        system("cls");///CORRIGE RASTRO DO PASSÁRO
        cout<<"-----------------------------------------------------------------------------------------------------";
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"-----------------------------------------------------------------------------------------------------";
        cout<< endl <<"Score: " << point;///PONTUAÇÃO APARECE NA TELA

        ///POSICIONA O PÁSSARO
        coord.X = bird_x;    coord.Y = bird_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        cout<<"><>";

        ///POSICIONA O OBSTÁCULO 1
        obstaculo_y1=1;
        while(obstaculo_y1<20){
            coord.X = obstaculo_x1;    coord.Y = obstaculo_y1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y1 < numeroAleatorio1 || obstaculo_y1 > numeroAleatorio1 + 3){///DEFINE CONDIÇÃO E TAMANHO DO VÃO DO OBSTÁCULO
                cout<<char(219);
            }

            obstaculo_y1++;
        }

        ///POSICIONA O OBSTÁCULO 2
        obstaculo_y2=1;
        while(obstaculo_y2<20){
            coord.X = obstaculo_x2;    coord.Y = obstaculo_y2;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y2 < numeroAleatorio2 || obstaculo_y2 > numeroAleatorio2 + 3){///DEFINE CONDIÇÃO E TAMANHO DO VÃO DO OBSTÁCULO
                cout<<char(219);
            }

            obstaculo_y2++;
        }



        ///VERIFICA COLISÃO

        ///ESTE "IF" VERIFICA A COLISÃO DO OBSTÁCULO 1 E 2
        if (bird_x  == obstaculo_x1 && (bird_y >= numeroAleatorio1 && bird_y <= numeroAleatorio1 + 3) || bird_x == obstaculo_x2 && (bird_y >= numeroAleatorio2 && bird_y <= numeroAleatorio2 + 3)){
           point++; ///SE O PASSÁRO PASSAR NO VÃO ENTRE OS CANOS, ACRECENTA 1 PONTO

        }else if (bird_x  == obstaculo_x1 || bird_x == obstaculo_x2){///SE O "IF" DE CIMA FOR "FALSE", VERIFICA SE A COORDENADA X É IGUAL COORDENADA X DO OBSTACULO, ASSIM COLIDINDO.
            break;
        }
        if(bird_y < 0 || bird_y > 20) ///COLISÃO NAS BORDAS DO MAPA
            break;


        ///VERIFICA COMANDO DO JOGADOR
        if (kbhit()) { ///VERIFICA SE UMA TECLA FOI PRESSIONADA
            tecla=getch(); //verifica comando do jogador
        }

        if ( tecla=='w' || tecla=='W' ){
            bird_y--;
            tecla='0';
        }else {
            bird_y++;///PÁSSARO CAI 1 POSIÇÃO SE NÃO FOI PRESSIONADO PARA SUBIR
        }

        ///OBSTÁCULO 1 AVANÇA UMA POSIÇÃO PARA ESQUERDA
        if (obstaculo_x1 <= 0) {///CONDIÇÃO PARA O OBSTACULO RESETAR
            obstaculo_x1 = 119;
        }
        obstaculo_x1--;

        ///OBSTÁCULO 2 AVANÇA UMA POSIÇÃO PARA ESQUERDA
        if (obstaculo_x2 <= 0) {///CONDIÇÃO PARA O OBSTACULO RESETAR
            obstaculo_x2 = 119;
        }
        obstaculo_x2--;

        ///ACELERAÇÃO DE VELOCIDADE
        if(point % 2 == 0 && i % 2 == 0 && time > 100){ ///QUANDO A PONTUAÇÃO FOR MULTIPLO DE 5 E O CONTADOR "i" FOR PAR PARA NÃO OCORRER BUGS (sleep(time) MAXIMO 100)
            time = time - 50; ///VELOCIDADE AUMENTA EM 25
            i++;
        }else if((point + 1) % 5 == 0 && i % 2 != 0 && time > 100){ ///CONDIÇÃO PARA NÃO DIMINUIR A VELOCIDADE DE FORMA INFINITA.
            i++;
        }

        ///TEMPO DE ESPERA
        Sleep(time);



    }

    system("cls");///LIMPA O CONSOLE

    ///MENU
    cout << "GAME OVER" << endl;
    cout << endl << "Seu Score foi de " << point << " pontos." << endl;
    cout << endl << "1 - Restart" << endl;
    cout << "2 - Quit" << endl;
    cin >> escolha;

    ///SWITCH DO MENU
    switch (escolha)
    {
    case 1:
        main();///REINICIA O JOGO
    break;

    case 2:
        system("cls");///LIMPA O CONSOLE
        cout<< "Obrigado por Jogar" << endl;
        return(0);
    }


    return 0;
}
