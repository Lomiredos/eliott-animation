#pragma once

#include "ecs/System.hpp"
#include "ecs/World.hpp"

namespace ee::animation
{
    class AnimationSystem : public ee::ecs::UpdateSystem
    {
    public:
        void update(ee::ecs::World &_world, float _dt) override;
    };
}
