#pragma once

#include <string>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/input/InputManager.hpp>

namespace engine
{
	class Engine
	{
	public:
		Engine();
		void loadConfiguration();

		void run();
		float getDeltaTime() const;

		void exit();

		void onEvent(const sf::Event &event);

	private:
		bool running;
		float deltaTime;

		// Configuration
		std::string startMap;

		//static Engine *instance;
		gameplay::Manager gameplayManager;
		graphics::Manager graphicsManager;
		input::Manager inputManager;
		physics::Manager physicsManager;
	};
}
