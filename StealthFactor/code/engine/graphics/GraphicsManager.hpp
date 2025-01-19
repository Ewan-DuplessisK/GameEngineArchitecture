#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace engine
{
	class Engine;

	namespace gameplay{class Manager;}
	
	namespace graphics
	{
		class ShapeList;

		class Manager
		{
		public:
			Manager(Engine& pEngine,gameplay::Manager& pGameplay);
			~Manager();

			void update();

			void clear();
			void draw(const ShapeList &shapeList, const sf::Transform &transform);
			void display();

			bool hasFocus() const;

			//static Manager &getInstance();

		private:
			sf::RenderWindow window;

			static const sf::Int16 WINDOW_WIDTH = 800;
			static const sf::Int16 WINDOW_HEIGHT = 600;

			//static Manager *instance;
			Engine& engine;
			gameplay::Manager& gameplayManager;
		};
	}
}
