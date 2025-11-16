#ifndef LOG_H
#define LOG_H

#include <spdlog/spdlog.h>
#include <memory>

namespace zuzu {
    class Log
    {
    public:
        static std::shared_ptr<spdlog::logger> getLogger() {return logger;}
        static void Init();   

    private:
        static std::shared_ptr<spdlog::logger> logger;
    };
}

#define ZUZU_LOG_TRACE(...)     zuzu::Log::getLogger()->trace(__VA_ARGS__)
#define ZUZU_LOG_INFO(...)      zuzu::Log::getLogger()->info(__VA_ARGS__)
#define ZUZU_LOG_WARN(...)      zuzu::Log::getLogger()->warn(__VA_ARGS__)
#define ZUZU_LOG_ERROR(...)     zuzu::Log::getLogger()->error(__VA_ARGS__)

#endif