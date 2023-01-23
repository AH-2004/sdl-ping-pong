#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <SDL.h> for windows.

using namespace std;

struct {
	const char* title = "My Application";
	const int width = 800, height = 600;
	const int x = SDL_WINDOWPOS_CENTERED, y = SDL_WINDOWPOS_CENTERED;
	const vector<int> bg = { 0, 128, 128, 255 };
	const char* icon = "./assets/icon.png";
	const int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
} data;

struct assets {
  const char* ball "./assets/ball.png";
  const char* plate "./assets/plate.png";
} assets;

class Application {
private:
  SDL_Window* win;
  SDL_Renderer* renderer;
  // SDL_Surface* surface;

  const int fps = 60;
  const int frame_delay = 1000/fps;
  Uint32 frame_ticks;
  int frame_time;
  
  bool status = false;
  bool counter_status = true;
  int counter = 0;
    
  void count() { if (counter_status) { counter++; cout << counter << endl; }; };

public:
  void createWindow(const char* title, int w, int h, int x, int y, vector<int> bg, const char* icon, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
	  win = SDL_CreateWindow(title, x, y, w, h, flags);

	  SDL_SetWindowIcon(win, IMG_Load(icon));
	  if (win) { cout << "Window Created!" << endl; };
	
	  renderer = SDL_CreateRenderer(win, -1, 0);
	  if (renderer) { cout << "Renderer Created!" << endl; };
	  SDL_SetRenderDrawColor(renderer, bg[0], bg[1], bg[2], bg[3]);	

	  status = true;
	  
	} else {
	  cout << "SDL Failed to Initialise." << endl;
	};
  };

  void frameStart() { frame_ticks = SDL_GetTicks(); };
  void frameEnd() {
	frame_time = SDL_GetTicks() - frame_ticks; 
	if (frame_delay > frame_time) { SDL_Delay(frame_delay - frame_time); };
  };
  
  void events() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
	  switch (e.type) {
	  case SDL_QUIT:
		cout << "Quitting..." << endl;
		status = false;
		clean();
		break;
	  };
	  
	};
  };

  void initTextures() {
	cout << "Nothing here. (I-Tex)" << endl;
  };

  void renderTextures() {
	cout << "Nothing here. (R-Tex)" << endl;
  };
  
  void render() {
	SDL_RenderClear(renderer);
	this->renderTextures();
	// SDL_RenderCopy(renderer, ballTex, NULL, &ball_rect);
	SDL_RenderPresent(renderer);
  };

  void update() { this->count(); };

  bool getStatus() { return status; };
  
  void clean() {
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Cleaned Successfully!" << endl;
  };
  
};

int main() {  
  Application* app = new Application();
  
  app->createWindow(data.title, data.width, data.height, data.x, data.y, data.bg, data.icon, data.flags);
  app->initTextures();

  while (app->getStatus()) {
	app->frameStart();
	app->render();
	app->update();
	app->events();
	app->frameEnd();
  };
  
};
