#pragma once

#include <SDL.h>

class GameObject {
public:
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual ~GameObject() = default;
};
