#pragma once
#include <miniaudio.h>

#include <string>

namespace zuzu 
{
    class AudioObject
    {
    public:
        AudioObject(const std::string& filePath, bool loop);
        ~AudioObject();
    
        void play();
        void stop();
        bool isPlaying() const;
    private:
        ma_engine* engine;
        ma_sound sound;
        bool loop;
    };
}