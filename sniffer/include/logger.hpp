#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>
#include "common.hpp"
namespace gw {

class Logger
{
public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
    static status_t save_to_file(statistics_t & data, std::time_t ts);
private:
    static std::shared_ptr<spdlog::logger> s_Logger;
    static const file_name;
};

} //namespace gw

// Log macros
#define LOG_TRACE(...)         ::gw::Logger::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)          ::gw::Logger::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)          ::gw::Logger::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)         ::gw::Logger::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)      ::gw::Logger::GetLogger()->critical(__VA_ARGS__)

#endif //LOGGER_H