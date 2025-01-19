#pragma once

#include <engine/gameplay/entities/Character.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			class Player : public Character
			{
			public:
				Player(ManagerContext& pContext);
				Player(ManagerContext& pContext,float pCellSize);

				virtual void update() override;

				bool hasJustMoved() const;

			private:
				bool justMoved{ false };
				float CellSize = 1.f;
			};
		}
	}
}
