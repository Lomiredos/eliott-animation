#pragma once

#include <memory>

#include "ecs/World.hpp"
#include "animation/AnimationSystem.hpp"
#include "animation/Animation.hpp"
#include "renderer/Sprite.hpp"

namespace ee::animation
{
    // Pilote (comme SpriteRenderer) : fait avancer les animations et ecrit
    // le srcRect de la frame courante dans le Sprite de chaque entite.
    class Animator
    {
    private:
        ee::ecs::World &m_world;
        std::shared_ptr<AnimationSystem> m_system;

    public:
        Animator(ee::ecs::World &_world) : m_world(_world)
        {
            m_system = m_world.registerSystem<AnimationSystem>();

            ee::ecs::Signature sig;
            sig.set(ee::ecs::getComponentID<Animation>());
            sig.set(ee::ecs::getComponentID<ee::renderer::Sprite>());

            m_world.setSystemSignature<AnimationSystem>(sig);
        }

        void update(float _dt);
    };
}
