#include "platform/input.hpp"

namespace platform {

bool eventHandler(SDL_Event* event) {
	return SDL_PollEvent(event);
}

} //namespace platform
