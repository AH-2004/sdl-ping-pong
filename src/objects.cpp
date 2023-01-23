#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class ball() {
 private:
  const char* ball_img = "./assets/ball.png";
  SDL_Texture* ball_texture;
  SDL_Rect ball_rect;

 public:
  void createBall(int width, int height) {
	ball_texture = SDL_CreateTextureFromSurface(renderer, IMG_Load(ball_img));
	ball_rect.w = width;
	ball_rect.h = height;
  };

  void moveBall(int x_pos, int y_pos) {
	ball_rect.x = x_pos;
	ball_rect.y = y_pos;
  };
};
