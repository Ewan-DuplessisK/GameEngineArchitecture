#include "engine/gameplay/entities/Player.hpp"

#include <ode/collision.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <engine/gameplay/entities/Target.hpp>
#include <engine/input/InputManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/Engine.hpp>

#include "engine/gameplay/components/CollisionComponent.h"

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Player::Player(Entity& entity):Character(entity)
			{
				collision_component_ = new CollisionComponent(entity,"player",CellSize * 0.9f, CellSize * 0.9f, 1.f);
			}

			Player::Player(Entity& entity,float pCellSize):CellSize(pCellSize),Character(entity){
				collision_component_ = new CollisionComponent(entity,"player",CellSize * 0.9f, CellSize * 0.9f, 1.f);
			}

			void Player::update()
			{
				justMoved = false;
				auto position = getPosition();
				float rotation = getRotation();

				if (getContext().inputManager.isKeyJustPressed(sf::Keyboard::Left))
				{
					justMoved = true;
					position.x -= CellSize;
					rotation = 180.f;
				}

				if (getContext().inputManager.isKeyJustPressed(sf::Keyboard::Right))
				{
					justMoved = true;
					position.x += CellSize;
					rotation = 0.f;
				}

				if (getContext().inputManager.isKeyJustPressed(sf::Keyboard::Up))
				{
					justMoved = true;
					position.y -= CellSize;
					rotation = -90.f;
				}

				if (getContext().inputManager.isKeyJustPressed(sf::Keyboard::Down))
				{
					justMoved = true;
					position.y += CellSize;
					rotation = 90.f;
				}

				if (justMoved)
				{
					setPosition(position);
					setRotation(rotation);

					Character::update();
				}

				auto collisions = getContext().physicsManager.getCollisionsWith(collision_component_->collisionGeomId);
				for (auto &geomId : collisions)
				{
					auto entity = reinterpret_cast<Entity *>(dGeomGetData(geomId));
					auto targetEntity = dynamic_cast<entities::Target *>(entity);
					if (targetEntity)
					{
						gameplay::Manager::getInstance().loadNextMap();
					}
				}
			}

			bool Player::hasJustMoved() const
			{
				return justMoved;
			}
		}
	}
}
