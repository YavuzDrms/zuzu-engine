#pragma once

#include "AudioObject.h"
#include <unordered_map>
#include <memory>
#include <string>

namespace zuzu
{
    class AudioManager
    {
    public:
        void addSound(const std::string& name, const std::string& filePath, bool loop);
        void removeSound(const std::string& name);
        void playSound(const std::string& name);
        void stopSound(const std::string& name);
    private:
        std::unordered_map<std::string, std::unique_ptr<AudioObject>> sounds;
    };
}