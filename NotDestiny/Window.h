

#include "GameObject.h"

class WindowObject : public GameObject {
private:
    SDL_Texture* texture;
    SDL_Rect rect;

public:
    WindowObject(SDL_Texture* tex, int x, int y, int w, int h);

    void render(SDL_Renderer* renderer) override;
};
