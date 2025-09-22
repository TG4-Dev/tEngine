#pragma once

#include <GLFW/glfw3.h>

namespace platform {

	struct windowArg {
		const char *title = nullptr;
		int width;
		int height;
	};

	class Window {
	public:
		Window();
		~Window();

		void windowInit(windowArg args);
		void windowClear();

		void windowUpdate();

		GLFWwindow *window = nullptr;
	};

} //namespace platform
