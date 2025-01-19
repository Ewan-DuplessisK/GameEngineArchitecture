#include "Target.hpp"

#include <engine/gameplay/GameplayManager.hpp>

#include "engine/gameplay/ManagerContext.h"
#include "engine/gameplay/components/CollisionComponent.h"
#include "engine/gameplay/components/drawComponent.h"
#include "engine/graphics/GraphicsManager.hpp"

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Target::Target(ManagerContext& pContext):Entity(pContext){
				collision_component_ = new CollisionComponent(*this,"target",gameplay::Manager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f, 1.f);
				draw_component_ = new drawComponent(*this,"target");
			}

			Target::~Target()
			{
			}

			void Target::update()
			{
				auto &position = getPosition();
				collision_component_->update(position.x, position.y, 0);
			}

			void Target::draw()
			{
				draw_component_->draw(getTransform());
			}
		}
	}
}
