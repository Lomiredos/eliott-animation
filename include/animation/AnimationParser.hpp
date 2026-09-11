#pragma once

#include <optional>
#include <string>
#include "animation/Animation.hpp"

namespace ee::animation
{
    class AnimationParser
    {
    public:
        static std::optional<AnimationSet> load(const std::string &_path);
    };
}
