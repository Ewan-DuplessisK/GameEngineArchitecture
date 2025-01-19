#include "Component.h"
#include "Entity.hpp"

namespace engine{
    namespace gameplay{
        Component::Component(Entity& pentity):entity(&pentity){}

    }
}