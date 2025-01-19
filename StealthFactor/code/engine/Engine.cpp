#include "engine/Engine.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include <pugixml/pugixml.hpp>
#include <SFML/System.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/input/InputManager.hpp>

namespace engine
{
	Engine::Engine():graphicsManager{*this,gameplayManager},inputManager{},physicsManager{},gameplayManager{graphicsManager,inputManager,physicsManager}{}

	void Engine::loadConfiguration()
	{
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_file("configuration.xml");

		if (result)
		{
			assert(!doc.empty());
			auto configuration = doc.first_child();
			startMap = configuration.child_value("start_map");
		}
		else
		{
			std::cerr << "Configuration parsed with errors." << std::endl;
			std::cerr << "Error description: " << result.description() << std::endl;
			std::cerr << "Error offset: " << result.offset << std::endl;
		}
	}

	void Engine::run()
	{
		running = true;

		gameplayManager.loadMap(startMap);

		sf::Clock clock;
		while (running)
		{
			deltaTime = clock.restart().asSeconds();

			physicsManager.update();
			gameplayManager.update();
			
			inputManager.clear();
			graphicsManager.update();

			graphicsManager.clear();

			gameplayManager.draw();

			graphicsManager.display();
		}
	}

	float Engine::getDeltaTime() const
	{
		return deltaTime;
	}

	void Engine::exit()
	{
		running = false;
	}

	void Engine::onEvent(const sf::Event& event){
		switch (event.type){
			case sf::Event::Closed: running = false; break;
			case sf::Event::LostFocus: inputManager.setFocus(false); break;
			case sf::Event::GainedFocus: inputManager.setFocus(true); break;
			case sf::Event::KeyPressed: inputManager.onKeyPressed(event.key); break;
			case sf::Event::KeyReleased: inputManager.onKeyReleased(event.key); break;
			default: break;
		}
	}
}
