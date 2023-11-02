#pragma once

#include "GameObject.h"

class RectObject : public GameObject {
private:
    SDL_Rect rect;
    SDL_Color color;

public:
    RectObject(int x, int y, int w, int h, SDL_Color c);

    void render(SDL_Renderer* renderer) override;
};
