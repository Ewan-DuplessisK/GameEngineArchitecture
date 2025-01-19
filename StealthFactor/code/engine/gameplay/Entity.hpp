#pragma once

#include <memory>
#include <set>
#include <SFML/Graphics/Transform.hpp>
#include "Component.h"

namespace engine
{
	namespace gameplay
	{
		struct ManagerContext;
		
		class Entity
		{
		public:
			Entity(ManagerContext& pContext);
			
			virtual ~Entity();

			virtual void update();
			virtual void draw();

			const sf::Vector2f &getPosition() const;
			void setPosition(const sf::Vector2f &newPosition);

			float getRotation() const;
			void setRotation(float newRotation);

			const sf::Transform &getTransform() const;

			ManagerContext& getContext() const{return context;}
			//void addComponent(Component pComp);
			template <typename Component>Component &addComponent();
			template <typename Component>Component *getComponent() const;

		protected:

		private:
			sf::Vector2f _position{};
			float _rotation{ 0.f };
			sf::Transform _transform;

			void updateTransform();

			
			ManagerContext& context;
			std::set<std::unique_ptr<Component>> components;
		};
		
	}
}
