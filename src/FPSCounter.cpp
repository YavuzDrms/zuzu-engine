#include <FPSCounter.h>

namespace zuzu
{
    float FPSCounter::m_Fps;
    float FPSCounter::m_DeltaTime;
    clock::time_point FPSCounter::m_LastTime;

    void FPSCounter::Init()
    {
        m_LastTime = clock::now();
        m_DeltaTime = 0.0f;
        m_Fps = 0.0f;
    }

    float FPSCounter::GetFPS()
    {
        auto currentTime = clock::now();
        std::chrono::duration<float> elapsed = currentTime - m_LastTime;
        m_LastTime = currentTime;

        m_DeltaTime = elapsed.count();
        m_Fps = 1.0f / m_DeltaTime;

        return m_Fps;
    }
}
