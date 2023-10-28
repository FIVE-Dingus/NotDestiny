    // NotDestiny.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
    //

    //#include <SDL.h>;
    #include <iostream>;
    #include "game.h";
    #include "grid.h";
    #include <conio.h>;

    #define KEY_UP 72
    #define KEY_DOWN 80
    #define KEY_LEFT 75
    #define KEY_RIGHT 77

    void restart(int result);

int main(){
    Grid* bruh = new Grid(4, 4);
    while (true) {
        bruh->randomTile();
        bruh->display();
        int c = 0;
        int value = 0;
        bool badKey = true;
        while (badKey)
        {
            if (bruh->result() == 2) {
                int result = 2;
                restart(result);
            }
            else if (bruh->result() == 1){
                int result = 1;
                restart(result);
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
                bruh->move(value);
                bruh->fusion(value);
                bruh->move(value);
            }
            else if(value == 2){
                bruh->move(value);
                bruh->fusion(value);
                bruh->move(value);
            }
            else if (value == 3) {
                bruh->move(value);
                bruh->fusion(value);
                bruh->move(value);
            }
            else if (value == 4) {
                bruh->move(value);
                bruh->fusion(value);
                bruh->move(value);
            }
        }
    }
    delete bruh;
}

void restard(int result) {
    if (result == 1) {
        std::cout << "Bravo vous avez gagnez souhaitez vous rejouez ?";
    }
    else if (result == 2) {
        std::cout << "Malheuresement vous avez perdu, souhaitez vous prendre votre revanche ?";
    }

}