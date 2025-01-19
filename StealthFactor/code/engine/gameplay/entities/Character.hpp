#pragma once

#include <ode/collision.h>
#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/Entity.hpp>

namespace engine
{
	namespace gameplay
	{
		class CollisionComponent;
		class drawComponent;
		namespace entities
		{
			class Character : public Entity
			{
			public:
				Character(ManagerContext& pContext);
				virtual ~Character();

				virtual void update() override;

				virtual void draw() override;

			protected:
				CollisionComponent* collision_component_ = nullptr;
				drawComponent* draw_Component_ = nullptr;

				bool isWalking{ false };
			};
		}
	}
}
