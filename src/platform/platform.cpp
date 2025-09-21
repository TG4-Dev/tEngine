#include "platform/platform.hpp"
#include "core/Log.hpp"

void platform::Init() {
	if(!glfwInit())
		TE_ERROR("ERROR: GLFW init");
}
