#include "engine/input/InputManager.hpp"

#include <iterator>
//#include <engine/graphics/GraphicsManager.hpp>

namespace engine
{
	namespace input
	{
		Manager::Manager() = default;

		bool Manager::isKeyPressed(sf::Keyboard::Key key) const
		{
			if (!hasFocus)
				return false;

			return sf::Keyboard::isKeyPressed(key);
		}

		bool Manager::isKeyJustPressed(sf::Keyboard::Key key) const
		{
			if (!hasFocus)
				return false;

			return justPressedKeys.find(key) != std::end(justPressedKeys);
		}

		bool Manager::isKeyJustReleased(sf::Keyboard::Key key) const
		{
			if (!hasFocus)
				return false;

			return justReleasedKeys.find(key) != std::end(justReleasedKeys);
		}

		void Manager::clear()
		{
			justPressedKeys.clear();
			justReleasedKeys.clear();
		}

		void Manager::onKeyPressed(const sf::Event::KeyEvent &event)
		{
			justPressedKeys.insert(event.code);
		}

		void Manager::onKeyReleased(const sf::Event::KeyEvent &event)
		{
			justReleasedKeys.insert(event.code);
		}
	}
}
