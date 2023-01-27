#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "objects.h"

void Texture::createTexture(const char* img, SDL_Renderer* renderer, int width, int height) {
  	tex = SDL_CreateTextureFromSurface(renderer, IMG_Load(img));
	rect.w = width;
	rect.h = height;
};

void Texture::moveTexture(int x_pos, int y_pos) {
  rect.x = x_pos;
  rect.y = y_pos;
};

SDL_Texture* Texture::getTexture() { return tex; };
SDL_Rect Texture::getRect() { return rect; };
