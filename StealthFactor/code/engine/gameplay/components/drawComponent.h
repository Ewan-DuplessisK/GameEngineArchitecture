#pragma once
#include <string>

#include "engine/gameplay/Component.h"
#include "engine/graphics/ShapeList.hpp"

namespace sf{
    class Transform;
}

namespace engine{
    namespace gameplay{
        class drawComponent:public Component{
        public:
            drawComponent(Entity& entity,std::string pShapeName);
            virtual void update() override;
            void draw(sf::Transform transform);
            
            std::string shapeListName;
            
            graphics::ShapeList shapeList;
        };
    }
}

