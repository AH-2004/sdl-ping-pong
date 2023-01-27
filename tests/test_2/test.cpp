#include <iostream>

struct dots { // Type
	const char* ball = "I am ball";
	const char* call = "I am car";
	const char* wall = "I am wall";
} data; // Name

class App {
public:
  void printStuff(dots d) {
	std::cout << d.ball << std::endl;
  };
};

int main() {
  App* app = new App();
  std::cout << data.ball << std::endl;
  app->printStuff(data);
};
