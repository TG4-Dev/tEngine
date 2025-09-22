#include "platform/platform.hpp"
#include "core/Log.hpp"

namespace platform {

void Init() {
	if(!glfwInit())
		TE_ERROR("ERROR: GLFW init");
}

void Exit() {
	glfwTerminate();
}

} //namespace platform

