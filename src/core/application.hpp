#pragma once

#include "platform/window.hpp"
#include "core/time/Clock.hpp"

namespace core {

	struct ApplicationSpecs {
		float fixedLogicStep;
		platform::windowArg windowArgs;
	};

	class Application {
	public:
		Application(ApplicationSpecs specs);
		~Application();

		void Run();

		void Stop();

		void Update();

		std::shared_ptr<platform::Window> window;
	private:
		float fixedLogicStep;
		bool isRunning = false;

		core::time::Clock clock;
	};

} //namespace core
