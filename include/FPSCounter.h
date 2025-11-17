#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include <chrono>

namespace zuzu 
{
    using clock = std::chrono::steady_clock;

    class FPSCounter
    {
    public:
        static void Init();
        static float GetFPS();
        static float GetDeltaTime() { return m_DeltaTime; }

    private:
        static float m_Fps;
        static float m_DeltaTime;
        static clock::time_point m_LastTime;
    };
}

#endif
