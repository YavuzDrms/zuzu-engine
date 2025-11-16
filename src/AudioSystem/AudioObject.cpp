#include <AudioSystem/AudioSystem.h>
#include <stdexcept>

#include <miniaudio.h>

namespace zuzu
{
    AudioObject::AudioObject(const std::string& filePath, bool loop)
        : engine(nullptr), loop(loop)
    {
        static ma_engine sharedEngine;
        static bool initialized = false;
        if (!initialized) {
            if(ma_engine_init(nullptr, &sharedEngine) != MA_SUCCESS) {
                throw std::runtime_error("can not init sound engine");
            }
            initialized = true;
        }
        engine = &sharedEngine;

        if(ma_sound_init_from_file(engine, filePath.c_str(),loop ? MA_SOUND_FLAG_LOOPING : 0, nullptr, nullptr, &sound) != MA_SUCCESS) {
            throw std::runtime_error("can not download audio file: " + filePath);
        }
    }
    AudioObject::~AudioObject() 
    {
        ma_sound_uninit(&sound);
    }
    void AudioObject::play() 
    {
        ma_sound_start(&sound);
    }
    void AudioObject::stop()
    {
        ma_sound_stop(&sound);
    }
    bool AudioObject::isPlaying() const {
        return ma_sound_is_playing(&sound);
    }
}