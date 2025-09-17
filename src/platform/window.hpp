#pragma once

#include <SDL3/SDL.h>

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

private:
	SDL_Window *window;
};

} //namespace platform
