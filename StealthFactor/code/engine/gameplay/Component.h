#pragma once

namespace engine{
    
    namespace gameplay{

        class Entity;

        class Component{
        public:
            virtual ~Component()=default;

            virtual void update();

        protected:
            Component(Entity &entity);
        };
    }
    
}