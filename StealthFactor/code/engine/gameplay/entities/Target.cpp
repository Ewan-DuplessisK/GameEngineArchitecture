#include "Target.hpp"

//#include <engine/gameplay/GameplayManager.hpp>

#include "engine/gameplay/ManagerContext.h"
#include "engine/gameplay/components/CollisionComponent.h"

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Target::Target(ManagerContext& pContext):Entity(pContext){
				collision_component_ = new CollisionComponent(*this,"target",context.graphicsManager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f, 1.f);
			}

			Target::~Target()
			{
				collision_component_.~CollisionComponent();
			}

			void Target::update()
			{
				auto &position = getPosition();
				collision_component_->update(position.x, position.y, 0);
			}

			void Target::draw()
			{
				graphics::Manager::getInstance().draw(shapeList, getTransform());
			}
		}
	}
}
