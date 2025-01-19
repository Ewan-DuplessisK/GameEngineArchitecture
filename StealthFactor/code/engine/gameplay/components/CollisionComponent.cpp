#include "CollisionComponent.h"

#include "engine/gameplay/Entity.hpp"
#include "engine/gameplay/ManagerContext.h"
#include "engine/physics/PhysicsManager.hpp"

namespace engine{
    namespace gameplay{

        CollisionComponent::CollisionComponent(Entity& entity, std::string pShapeName, float collisionX,float collisionY,float collisionZ):Component(entity),shapeListName(pShapeName){
            if(shapeListName!="")shapeList.load(shapeListName);

            collisionGeomId = dCreateBox(entity.getContext().physicsManager.getSpaceId(), collisionX,collisionY,collisionZ);
            dGeomSetData(collisionGeomId, this);
        }

        CollisionComponent::~CollisionComponent(){
            dGeomDestroy(collisionGeomId);
        }

        void CollisionComponent::update(){}

        void CollisionComponent::update(float inX,float inY,float inZ){
            dGeomSetPosition(collisionGeomId, inX, inY, inZ);
        }
    }
}
