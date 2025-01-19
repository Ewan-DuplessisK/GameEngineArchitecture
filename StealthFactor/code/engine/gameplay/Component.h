#pragma once

namespace engine{
    
    namespace gameplay{

        class Entity;

        class Component{
        public:
            virtual ~Component()=default;

        protected:
            Component(Entity &entity);
        };
    }
    
}