#pragma once
#include "engine/gameplay/Component.h"
#include <ode/collision.h>
#include <engine/graphics/ShapeList.hpp>

namespace engine{

    namespace gameplay{
        
        class CollisionComponent: public Component{
        public:
            CollisionComponent(Entity& entity ,std::string pShapeName);
            ~CollisionComponent();

            std::string shapeListName;
            
            graphics::ShapeList shapeList;
            dGeomID collisionGeomId;
    
        };
    }
    
}


