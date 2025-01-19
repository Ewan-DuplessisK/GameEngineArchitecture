#include "Character.hpp"

#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>

#include "engine/gameplay/components/CollisionComponent.h"

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Character::Character(Entity& entity):Entity(entity)
			{
				//collision_component_ = new CollisionComponent(entity,"",0.f,0.f,0.f);
			}

			Character::~Character()
			{
				collision_component_.~CollisionComponent();
			}

			void Character::update(){
				auto &position = getPosition();
				collision_component_->update(position.x, position.y, 0);
			}

			void Character::draw()
			{
				graphics::Manager::getInstance().draw(shapeList, getTransform());
			}
		}
	}
}
