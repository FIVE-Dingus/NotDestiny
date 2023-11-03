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

const int WINDOW_WIDTH = 400;
const int WINDOW_HEIGHT = 400;
const int GRID_SIZE = 4; // Taille de la grille 4x4

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;


// definit les touches directionnel 
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

// déclare la fonction restart
int restart(int result);
void automatique(Grid* game);



void drawGrid() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Couleur de fond blanche
    SDL_RenderClear(renderer);

    // Dessiner une grille de 4x4 (carrés vides)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Couleur des lignes
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            SDL_Rect rect = { i * (WINDOW_WIDTH / GRID_SIZE), j * (WINDOW_HEIGHT / GRID_SIZE), WINDOW_WIDTH / GRID_SIZE, WINDOW_HEIGHT / GRID_SIZE };
            SDL_RenderDrawRect(renderer, &rect);
        }
    }

    SDL_RenderPresent(renderer);
}

int main(int argc, char** argv){
    
    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Création de la fenêtre
    window = SDL_CreateWindow("2048 Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Création du rendu
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    RectObject rect(100, 100, 50, 50, { 255, 0, 0, 255 }); // Exemple de création d'un objet rectangulaire rouge
    bool quit = false;
    SDL_Event event;

    while (!quit) {
        // Gestion des événements
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
         
        }
        drawGrid();
    }
    
    // Nettoyage et fermeture de SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
   
    return 0;
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
        return 0;
    }
}

void automatique(Grid* game) {
    int value = rand()%4;
    game->move(value);
    game->fusion(value);
    game->move(value);
}


