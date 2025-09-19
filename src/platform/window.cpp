#include "platform/window.hpp"

namespace platform {

void window::windowInit(windowArg args) {
	if(!glfwInit()){}

	window = glfwCreateWindow(args.width, args.height, args.title, NULL, NULL);
	if(!window){
		glfwTerminate();
	}
}

void window::windowClear() {
	if(window)
		glfwDestroyWindow(window);

	glfwTerminate();
}

} //namespace platform
