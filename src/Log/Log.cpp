#include <Log/Log.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

std::shared_ptr<spdlog::logger> zuzu::Log::logger;

void zuzu::Log::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    logger = spdlog::stdout_color_mt("Zuzu");
    logger->set_level(spdlog::level::trace);
}