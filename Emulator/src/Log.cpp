#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"


std::shared_ptr<spdlog::logger> Log::s_EmuLogger;
std::shared_ptr<spdlog::logger> Log::s_SysLogger;

void Log::Init()
{
	spdlog::set_pattern("%^[%T]%n %v%$");

	s_EmuLogger = spdlog::stdout_color_mt("Emulator: ");
	s_EmuLogger->set_level(spdlog::level::trace);

	s_SysLogger = spdlog::stdout_color_mt("System: ");
	s_SysLogger->set_level(spdlog::level::trace);
}

