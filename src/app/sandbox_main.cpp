#include "core/Log.hpp"
#include "core/time/Clock.hpp"
#include <cstdio>

int main() {
  core::time::Clock clock;
  core::Log::Init();

  for (size_t i = 0; i < 100; i++) {
    TE_TRACE("Tick: {}", clock.Tick());
    TE_TRACE("Last Delta: {}", clock.LastDelta());
    TE_TRACE("FPS: {}", clock.Fps());
    TE_TRACE("Since start: {}", clock.SinceStart());
  }

	//int* p = nullptr; *p = 5; //Можешь затестить санитайзер)

  return 0;
}
