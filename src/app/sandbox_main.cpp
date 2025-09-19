#include <core/Log.hpp>
#include <core/time/Clock.hpp>
#include <platform/platform.hpp>
#include <cstdio>

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods){
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


int main() {
  core::time::Clock clock;
  core::Log::Init();

  platform::windowArg args {
	"sandbox window",
	800,
	800
  };

  platform::window mainWindow;
  mainWindow.windowInit(args);


  glfwSetKeyCallback(mainWindow.window, key_callback);

  while(!glfwWindowShouldClose(mainWindow.window)) {
	  glfwPollEvents();
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
