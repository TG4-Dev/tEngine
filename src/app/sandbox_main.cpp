#include "core/Log.hpp"
#include "core/time/Clock.hpp"
#include "platform/platform.hpp"
#include <cstdio>

int main() {
  core::time::Clock clock;
  core::Log::Init();

  platform::windowArg args {
	"sandbox window",
	800,
	800
  };

  platform::window mainWindow;
  mainWindow.windowInit(args);

  for (size_t i = 0; i < 10000; i++) {
    TE_TRACE("Tick: {}", clock.Tick());
    TE_TRACE("Last Delta: {}", clock.LastDelta());
    TE_TRACE("FPS: {}", clock.Fps());
    TE_TRACE("Since start: {}", clock.SinceStart());
  }

  mainWindow.windowClear();

	//int* p = nullptr; *p = 5; //Можешь затестить санитайзер)
	
  return 0;
}
