#pragma once

#include <memory>
#include <spdlog/spdlog.h>

class Log
{
public:

	static void Init();

	inline static std::shared_ptr<spdlog::logger>& GetEmulatorLogger() { return s_EmuLogger; }
	inline static std::shared_ptr<spdlog::logger>& GetSystemLogger() { return s_SysLogger; }

private:

	static std::shared_ptr<spdlog::logger> s_EmuLogger;
	static std::shared_ptr<spdlog::logger> s_SysLogger;
};

#define EMU_LOG_ERROR(...)   ::Log::GetEmulatorLogger()->error(__VA_ARGS__)
#define EMU_LOG_WARN(...)    ::Log::GetEmulatorLogger()->warn(__VA_ARGS__)
#define EMU_LOG_INFO(...)    ::Log::GetEmulatorLogger()->info(__VA_ARGS__)
#define EMU_LOG_TRACE(...)   ::Log::GetEmulatorLogger()->trace(__VA_ARGS__)

#define SYS_LOG_ERROR(...)   ::Log::GetSystemLogger()->error(__VA_ARGS__)
#define SYS_LOG_WARN(...)    ::Log::GetSystemLogger()->warn(__VA_ARGS__)
#define SYS_LOG_INFO(...)    ::Log::GetSystemLogger()->info(__VA_ARGS__)
#define SYS_LOG_TRACE(...)   ::Log::GetSystemLogger()->trace(__VA_ARGS__)

