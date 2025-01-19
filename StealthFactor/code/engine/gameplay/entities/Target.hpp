#pragma once


#include <engine/gameplay/Entity.hpp>

namespace engine
{
	namespace gameplay
	{
		class CollisionComponent;
		class drawComponent;
		namespace entities
		{
			class Target : public Entity
			{
			public:
				Target(ManagerContext& pContext);
				~Target();

				virtual void update() override;

				virtual void draw() override;

			private:
				CollisionComponent* collision_component_ = nullptr;
				drawComponent* draw_component_ = nullptr;
			};
		}
	}
}
