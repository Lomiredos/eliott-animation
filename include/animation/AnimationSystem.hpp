#pragma once

#include "ecs/System.hpp"

namespace ee::animation
{
    class AnimationSystem : public ee::ecs::System
    {
    public:
        void update(ee::ecs::World &_world, float _dt) override {}
    };
}
