#include "Character.hpp"

#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>

#include "engine/gameplay/components/CollisionComponent.h"
#include "engine/gameplay/components/drawComponent.h"

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Character::Character(ManagerContext& pContext):Entity(pContext)
			{
				//collision_component_ = new CollisionComponent(entity,"",0.f,0.f,0.f);
			}

			Character::~Character()
			{
			}

			void Character::update(){
				auto &position = getPosition();
				collision_component_->update(position.x, position.y, 0);
			}

			void Character::draw()
			{
				draw_Component_->draw(getTransform());
			}
		}
	}
}
