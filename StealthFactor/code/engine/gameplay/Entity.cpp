#include "Entity.hpp"

namespace engine
{
	namespace gameplay
	{
		Entity::~Entity(){}

		void Entity::update(){
		}

		const sf::Vector2f & Entity::getPosition() const
		{
			return _position;
		}

		void Entity::setPosition(const sf::Vector2f &newPosition)
		{
			_position = newPosition;
			updateTransform();
		}

		float Entity::getRotation() const
		{
			return _rotation;
		}

		void Entity::setRotation(float newRotation)
		{
			_rotation = newRotation;
			updateTransform();
		}

		const sf::Transform & Entity::getTransform() const
		{
			return _transform;
		}

		void Entity::updateTransform()
		{
			_transform = sf::Transform::Identity;
			_transform.translate(_position);
			_transform.rotate(_rotation);
		}

		template <typename Component>
		Component& Entity::addComponent(){
			if(!getComponent<Component>()){
				Component component{new Component(*this)};
				components.insert(std::unique_ptr<Component>(component));
				return *component;
			}
		}

		template <typename Component>
		Component* Entity::getComponent() const{
			auto it = std::find_if(
				std::begin(components),
				std::end(components),
				[](const std::unique_ptr<Component>(&component))
			{
				return dynamic_cast<Component *>(component.get()) != nullptr;
			});

			if (it != std::end(components))
			{
				return reinterpret_cast<Component *>(it->get());
			}

			return nullptr;
		}

	}
}
