#include "platform/platform.hpp"

namespace platform {

void window::windowInit(windowArg args) {
	if(!SDL_INIT_VIDEO){}

	window = SDL_CreateWindow(args.title, args.width, args.height, SDL_WINDOW_VULKAN);
	if(!window){}
}

void window::windowClear() {
	if(window)
		SDL_DestroyWindow(window);
			
}

} //namespace platform
