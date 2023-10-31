#include <iostream>
#include <vector>
#include <SDL.h>;

class GameObject {
public:
    virtual void render(SDL_Renderer* renderer) const = 0;
};

class GeometricObject : public GameObject {
protected:
    int x, y, width, height;
    SDL_Color color;

public:
    GeometricObject(int x, int y, int width, int height, SDL_Color color)
        : x(x), y(y), width(width), height(height), color(color) {}

    void render(SDL_Renderer* renderer) const override {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect rect = { x, y, width, height };
        SDL_RenderFillRect(renderer, &rect);
    }
};

class ImageObject : public GameObject {
protected:
    int x, y;
    SDL_Surface* imageSurface;
    SDL_Texture* imageTexture;

public:
    ImageObject(int x, int y, const char* imagePath, SDL_Renderer* renderer)
        : x(x), y(y) {
        imageSurface = SDL_LoadBMP(imagePath);
        imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
        SDL_FreeSurface(imageSurface);
    }

    void render(SDL_Renderer* renderer) const override {
        SDL_Rect dstRect = { x, y, 0, 0 };
        SDL_QueryTexture(imageTexture, NULL, NULL, &dstRect.w, &dstRect.h);
        SDL_RenderCopy(renderer, imageTexture, NULL, &dstRect);
    }
};