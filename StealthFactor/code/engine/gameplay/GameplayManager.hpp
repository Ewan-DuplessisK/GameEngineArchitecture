#pragma once

#include <memory>
#include <set>
#include <string>
#include <SFML/System/Vector2.hpp>

#include "ManagerContext.h"

namespace engine
{
	namespace gameplay
	{
		class Entity;

		namespace entities
		{
			class Player;
		}

		class Manager
		{
		public:
			Manager(graphics::Manager &graphicsManager, input::Manager &inputManager, physics::Manager &physicsManager);
			
			void update();
			void draw();

			void gameOver();

			sf::Vector2f getViewCenter() const;

			void loadMap(const std::string &mapName);
			void loadNextMap();

			const entities::Player &getPlayer() const;

			static const float CELL_SIZE;

		private:
			ManagerContext context;
			
			std::set<std::unique_ptr<Entity>> entities;
			entities::Player *playerEntity{};

			// Map
			std::string currentMapName;
			std::string nextMapName;
			int rows{ 0 };
			int columns{ 0 };

			bool preventMapCompletion{ false };
			bool nextMapRequested{ false };
		};
	}
}
