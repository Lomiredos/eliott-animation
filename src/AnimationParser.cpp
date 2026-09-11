#include "animation/AnimationParser.hpp"

#include <nlohmann/json.hpp>
#include <fstream>

std::optional<ee::animation::AnimationSet> ee::animation::AnimationParser::load(const std::string &_path)
{
    std::ifstream file(_path);
    if (!file.is_open())
        return std::nullopt;

    nlohmann::json data;
    try
    {
        file >> data;
    }
    catch (...)
    {
        return std::nullopt;
    }

    AnimationSet set;

    if (data.contains("frame_size"))
    {
        set.frameWidth = data["frame_size"].value("width", 0);
        set.frameHeight = data["frame_size"].value("height", 0);
    }

    if (data.contains("animations"))
    {
        for (auto &[name, clipJson] : data["animations"].items())
        {
            AnimationClip clip;
            clip.frameTime = clipJson.value("frame_time", 0.1f);
            clip.loop = clipJson.value("loop", true);
            if (clipJson.contains("frames"))
                clip.frames = clipJson["frames"].get<std::vector<int>>();
            set.clips[name] = clip;
        }
    }

    return set;
}
