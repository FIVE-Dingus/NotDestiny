// NotDestiny.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
// inclue une bibliothèque qui contiennent des déclarations de fonctions, des définitions de classes, des constantes et d'autres 
#include <SDL.h>;
#include <iostream>;
#include "game.h";
#include "grid.h";
#include <conio.h>;
#include "RectObject.h"
#include "Window.h"

// definit les touches directionnel 
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

// déclare la fonction restart
int restart(int result);
void automatique(Grid* game);

int main(int argc, char** argv){
    
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Erreur d'initialisation de SDL : " << SDL_GetError() << std::endl;
        return 1;
    }

    // Création de la fenêtre
    SDL_Window* window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Erreur de création de la fenêtre : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }


    // Création du rendu
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Erreur de création du rendu : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialisation de votre grille de jeu(Grid)
    Grid* game = new Grid(4, 4);

    bool quit = false;
    while (!quit) {
        // Gestion des événements
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                // Gérez les entrées du clavier (mouvement, etc.)
            }
        }

        // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Dessinez votre grille de jeu (Grid) et ses tuiles ici

        // Mise à jour de l'affichage
        SDL_RenderPresent(renderer);
    }

    // Nettoyage et fermeture de SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    std::cout << "test ou vrai jeu: t/j";
    char choice;
    std::cin >> choice;
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
                int reStart = restart(result);
                if (reStart == 58572) {
                    return 0;
                }
            }
            else if (game->result() == 1){
                int result = 1;
                int reStart = restart(result);
                if (reStart == 58572) {
                    return 0;
                }
            }
            if (choice == 't' || 'T') {
                automatique(game);
                break;
                badKey = true;
            }
            else if (choice == 'j' || 'J') {
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
                else if (value == 2) {
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
    }
    delete game;
}

void SDL_main() {

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
        
    }
    else {
        return 58572;
    }
}

void automatique(Grid* game) {
    int value = rand()%4;
    game->move(value);
    game->fusion(value);
    game->move(value);
}


