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


int main()
{
    Grid* bruh = new Grid(4, 4);
    while (true) {
        bruh->value(1, 2);
        bruh->tile();
        bruh->display();
        int c = 0;
        int value = 0;
        bool badKey = true;
        while (badKey)
        {
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
        }
    }
    delete bruh;
}
/*
int main()
{
    //afficher les nombres de 1 à 100
    int i = 0;
    for (i = 0; i < 101; i++) {
        printf(" %d ", i);
    };
    i = 0;
    //créer un tableau de 20 cases
    int * tab = (int*) malloc(sizeof(int) * (20));
    //mettre 1 dans chaque cases
    for (i = 0; i < 20; i++)
    {
        tab[i] = 1;
    };
    i = 0;
    //mettre 5 à chaque index pair du tableau
    for (i = 0; i < 19; i++)
    {
            i = i + 1;
            tab[i] = 5;
    };

    i = 0;
    //afficher le tableau
    for (i = 0; i < 20; i ++)
    {
        printf(" %d ", tab[i]);
    };
    free(tab);
}*/
// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
