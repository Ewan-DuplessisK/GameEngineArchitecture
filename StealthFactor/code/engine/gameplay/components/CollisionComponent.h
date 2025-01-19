#pragma once
#include "engine/gameplay/Component.h"
#include <ode/collision.h>
#include <engine/graphics/ShapeList.hpp>

namespace engine{

    namespace gameplay{
        
        class CollisionComponent: public Component{
        public:
            CollisionComponent(Entity& entity, std::string pShapeName, float collisionX,float collisionY,float collisionZ);
            ~CollisionComponent();

            virtual void update() override;
            void update(float inX, float inY, float inZ);

            std::string shapeListName;
            
            graphics::ShapeList shapeList;
            dGeomID collisionGeomId;
    
        };
    }
    
}


