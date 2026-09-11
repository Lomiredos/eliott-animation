#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace ee::animation
{

    struct AnimationClip
    {
        float frameTime = 0.1f;
        std::vector<int> frames;
        bool loop = true;
    };

    // Ressource partagee (tout Archer.json sauf la texture).
    struct AnimationSet
    {
        int frameWidth = 0;
        int frameHeight = 0;
        std::unordered_map<std::string, AnimationClip> clips;
    };

    // Composant ECS : etat de lecture par entite.
    struct Animation
    {
        std::shared_ptr<AnimationSet> set;
        std::string current;
        size_t cursor = 0;
        float elapsed = 0.0f;
        bool playing = true;

        void play(const std::string &_clip)
        {
            if (current == _clip)
                return;
            current = _clip;
            cursor = 0;
            elapsed = 0.0f;
            playing = true;
        }
    };

}
