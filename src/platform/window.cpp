#include "platform/window.hpp"
#include "core/Log.hpp"

namespace platform {

	Window::Window(){}

	Window::~Window() {
		windowClear();
	}

	void Window::windowInit(windowArg args) {
		window = glfwCreateWindow(args.width, args.height, args.title, NULL, NULL);
		if(!window){
			TE_ERROR("ERROR: Window init");
			glfwTerminate();
		}
	}

	void Window::windowClear() {
		if(window)
			glfwDestroyWindow(window);
	}

} //namespace platform
