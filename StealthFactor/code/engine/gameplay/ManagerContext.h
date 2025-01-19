#pragma once

namespace engine
{
    namespace graphics
    {
        class Manager;
    }

    namespace input
    {
        class Manager;
    }

    namespace physics
    {
        class Manager;
    }

    namespace gameplay
    {
        struct ManagerContext
        {
            graphics::Manager &graphicsManager;
            input::Manager &inputManager;
            physics::Manager &physicsManager;
        };
    }
}