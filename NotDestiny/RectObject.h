#include "GameObject.h"

class RectObject : public GameObject {
public:
    RectObject(int x, int y, int w, int h, SDL_Color color) : GameObject(x, y, w, h), objColor(color) {}
    void render(SDL_Renderer* renderer) override;

private:
    SDL_Color objColor;
};
