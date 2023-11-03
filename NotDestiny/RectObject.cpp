#include "RectObject.h"

void RectObject::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, objColor.r, objColor.g, objColor.b, objColor.a);
    SDL_Rect rect = { x, y, width, height };
    SDL_RenderFillRect(renderer, &rect);
}
