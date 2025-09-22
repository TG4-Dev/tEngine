#include "tengine.hpp"
#include <cstdio>
#include "core/application.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


int main() {
	core::ApplicationSpecs specs;
	specs.windowArgs.title = "test";
	specs.windowArgs.height = 800;
	specs.windowArgs.width = 800;
	specs.fixedLogicStep = 1.0f/128.0f; //128 logic ticks

	core::Application app(specs);
	glfwSetKeyCallback(app.window->window, key_callback);
	app.Run();
	return 0;
}

