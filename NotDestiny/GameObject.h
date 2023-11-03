#pragma once

#include <SDL.h>

class GameObject {
public:
    GameObject(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) {}
    virtual void render(SDL_Renderer* renderer) = 0; // Méthode virtuelle pure

protected:
    int x;
    int y;
    int width;
    int height;
};
