#include <AudioSystem/AudioSystem.h>
#include <stdexcept>

namespace zuzu
{
    void AudioManager::addSound(const std::string& name, const std::string& filePath, bool loop)
    {
        sounds[name] = std::make_unique<AudioObject>(filePath, loop);
    }
    void AudioManager::removeSound(const std::string& name)
    {
        sounds.erase(name);
    }
    void AudioManager::playSound(const std::string& name)
    {
        if(sounds.find(name) == sounds.end()) {
            throw std::runtime_error("can not found sound: " + name);
        }
        sounds[name]->play();
    }
    void AudioManager::stopSound(const std::string& name)
    {
        if(sounds.find(name) == sounds.end()) {
            throw std::runtime_error("can not found sound: " + name);
        }
        sounds[name]->stop();
    }
}