#include "tengine.hpp"
#include "core/Log.hpp"
#include <cstdio>

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

const float FIXED_LOGIC_STEP = 1.0f/60.0f; //60 fps logic

void update() {
	TE_INFO("Update Tick");
}

int main() {
  core::time::Clock clock;
  core::Log::Init();
  platform::Init();

  platform::windowArg args {
	"sandbox window",
	800,
	800
  };

  platform::window mainWindow;
  mainWindow.windowInit(args);


  glfwSetKeyCallback(mainWindow.window, key_callback);

  float accumulator = 0.0f;

  while(!glfwWindowShouldClose(mainWindow.window)) {
	  glfwPollEvents();

	  while (accumulator >= FIXED_LOGIC_STEP) {
		  update();
		  TE_INFO("FPS: {}", clock.Fps());
		  accumulator -= FIXED_LOGIC_STEP;
	  }

	  accumulator += clock.Tick();
  }

  //for (size_t i = 0; i < 10000; i++) {
  //  TE_TRACE("Tick: {}", clock.Tick());
  //  TE_TRACE("Last Delta: {}", clock.LastDelta());
  //  TE_TRACE("FPS: {}", clock.Fps());
  //  TE_TRACE("Since start: {}", clock.SinceStart());
  //}

  mainWindow.windowClear();

	//int* p = nullptr; *p = 5; //Можешь затестить санитайзер)
	
  return 0;
}
