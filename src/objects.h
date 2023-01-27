#pragma once

class Texture {
 private:
  SDL_Texture* tex;
  SDL_Rect rect;

 public:
  void createTexture(const char* img, SDL_Renderer* renderer, int width, int height);
  void moveTexture(int x_pos, int y_pos);
  SDL_Texture* getTexture();
  SDL_Rect getRect();
};
