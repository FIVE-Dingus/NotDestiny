    // NotDestiny.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
    //
    // inclue une bibliothèque qui contiennent des déclarations de fonctions, des définitions de classes, des constantes et d'autres 
    #include <iostream>;
    #include "game.h";
    #include "grid.h";
    #include <conio.h>;

// definit les touches directionnel 
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

// déclare la fonction restart
int restart(int result);

void main(){
    Grid* game = new Grid(4, 4);
    while (true) {
        game->randomTile();
        system("cls");
        game->display();
        int c = 0;
        int value = 0;
        bool badKey = true;
        while (badKey)
        {
            if (game->result() == 2) {
                int result = 2;
                restart(result);
            }
            else if (game->result() == 1){
                int result = 1;
                int reStart = restart(result);
                if (reStart == 0) {
                    return;
                }
            }
            badKey = false;
            c = 0;
            switch ((c = _getch()))
            {
            case KEY_UP:
                value = 4;
                break;
            case KEY_DOWN:
                value = 3;
                break;
            case KEY_RIGHT:
                value = 1;
                break;
            case KEY_LEFT:
                value = 2;
                break;
            default:
                badKey = true;
                break;
            }
            if (value == 1) {
                game->move(value);
                game->fusion(value);
                game->move(value);
            }
            else if(value == 2){
                game->move(value);
                game->fusion(value);
                game->move(value);
            }
            else if (value == 3) {
                game->move(value);
                game->fusion(value);
                game->move(value);
            }
            else if (value == 4) {
                game->move(value);
                game->fusion(value);
                game->move(value);
            }
        }
    }
    delete game;
}

//fonction restart 
int restart(int result) {
    if (result == 1) {
        std::cout << "Bravo vous avez gagné. Voulez-vous rejouer ? (O/N): ";
    }
    else if (result == 2) {
        std::cout << "Malheureusement vous avez perdu. Voulez-vous prendre votre revanche ? (O/N): ";
    }

    char choice;
    std::cin >> choice;

    if (choice == 'O' || choice == 'o') {
        main();
    }
    else {
        return 0;
    }
}
