#include "application.hpp"

namespace core {

	Application::Application(ApplicationSpecs specs) {
		Log::Init();
		platform::Init();
		fixedLogicStep = specs.fixedLogicStep;


		window = std::make_shared<platform::Window>();
		window->windowInit(specs.windowArgs);
	}

	Application::~Application() {
		window->windowClear();
		platform::Exit();
	}

	void Application::Run() {
		isRunning = true;
		//glfwSetKeyCallback(window, key_callback);

		float accumulator = 0.0f;

		while(isRunning) {
			glfwPollEvents();

			if(glfwWindowShouldClose(window->window))
				Stop();

			while (accumulator >= fixedLogicStep) {
				TE_INFO("Tick");
				TE_INFO("FPS: {}", clock.Fps());
				accumulator -= fixedLogicStep;
			}

			accumulator += clock.Tick();
		}
	}

	void Application::Stop() {
		isRunning = false;
	}
} //namespace core
