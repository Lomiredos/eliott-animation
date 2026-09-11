#include "animation/Animator.hpp"
#include "math/Rect.hpp"

void ee::animation::Animator::update(float _dt)
{
    for (ee::ecs::EntityID id : m_system->m_entities)
    {
        Animation *anim = m_world.getComponent<Animation>(id);
        ee::renderer::Sprite *sprite = m_world.getComponent<ee::renderer::Sprite>(id);

        if (anim == nullptr || sprite == nullptr || anim->set == nullptr || !sprite->texture)
            continue;

        auto it = anim->set->clips.find(anim->current);
        if (it == anim->set->clips.end() || it->second.frames.empty())
            continue;
        const AnimationClip &clip = it->second;

        if (anim->playing)
        {
            anim->elapsed += _dt;
            while (anim->elapsed >= clip.frameTime)
            {
                anim->elapsed -= clip.frameTime;
                anim->cursor++;
                if (anim->cursor >= clip.frames.size())
                {
                    if (clip.loop)
                        anim->cursor = 0;
                    else
                    {
                        anim->cursor = clip.frames.size() - 1;
                        anim->playing = false;
                    }
                }
            }
        }

        if (anim->set->frameWidth <= 0 || anim->set->frameHeight <= 0)
            continue;

        int frameIndex = clip.frames[anim->cursor];
        int cols = static_cast<int>(sprite->texture->getWidth()) / anim->set->frameWidth;
        if (cols <= 0)
            cols = 1;

        int col = frameIndex % cols;
        int row = frameIndex / cols;

        sprite->srcRect = ee::math::Rect<float>(
            static_cast<float>(col * anim->set->frameWidth),
            static_cast<float>(row * anim->set->frameHeight),
            static_cast<float>(anim->set->frameWidth),
            static_cast<float>(anim->set->frameHeight));
    }
}
