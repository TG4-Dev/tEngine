#include "platform/window.hpp"
#include "core/Log.hpp"

namespace platform {

void window::windowInit(windowArg args) {
	window = glfwCreateWindow(args.width, args.height, args.title, NULL, NULL);
	if(!window){
		TE_ERROR("ERROR: Window init");
		glfwTerminate();
	}
}

void window::windowClear() {
	if(window)
		glfwDestroyWindow(window);

	glfwTerminate();
}

} //namespace platform
