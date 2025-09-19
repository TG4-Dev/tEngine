#pragma once

#include <GLFW/glfw3.h>

namespace platform {

struct windowArg {
	const char *title;
	int width;
	int height;
};

class window {
public:
	void windowInit(windowArg args);
	void windowClear();
	GLFWwindow *window;
};

} //namespace platform
