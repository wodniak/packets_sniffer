#include "logger.hpp"

namespace gw 
{

std::shared_ptr<spdlog::logger> Logger::s_Logger;

void Logger::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_Logger = spdlog::stdout_color_mt("HAZEL");
    s_Logger->set_level(spdlog::level::trace);
}

}