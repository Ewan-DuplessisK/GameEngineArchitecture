#pragma once

namespace engine{
    
    namespace gameplay{

        class Entity;

        class Component{
        public:
            virtual ~Component()=default;

            virtual void update()=0;

        protected:
            Component(Entity &entity);
            Entity* entity = nullptr;
        };
    }
    
}