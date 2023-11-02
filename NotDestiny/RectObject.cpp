#include "RectObject.h"

RectObject::RectObject(int x, int y, int w, int h, SDL_Color c) : color(c) {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

void RectObject::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);
}
