

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
