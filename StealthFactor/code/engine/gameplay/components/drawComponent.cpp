#include "drawComponent.h"

#include "engine/gameplay/Entity.hpp"
#include "engine/gameplay/ManagerContext.h"
#include "engine/graphics/GraphicsManager.hpp"

namespace engine{
    namespace gameplay{

        drawComponent::drawComponent(Entity& entity,std::string pShapeName):Component(entity){
            shapeListName=pShapeName;
            if(!shapeListName.empty())shapeList.load(shapeListName);
        }

        void drawComponent::update(){
            
        }

        void drawComponent::draw(sf::Transform transform){
            entity->getContext().graphicsManager.draw(shapeList, transform);
        }
    }
}
