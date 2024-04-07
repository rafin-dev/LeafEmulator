#pragma once

#include <string>
#include <functional>
#include "Log.h"

namespace GameBoyEmulator {

	// static only class that will be used as a bridge between the system and the GUI
	class SystemManager
	{
	public:
		static bool LoadROM(std::string& path);
		static void CallEmulationErrorMenu();

	private:
		static std::function<bool(std::string&)> LoadRomEvent;
		static std::function<void(void)> CallEmulationErrorMenuEvent;

		friend class GameBoy;
	};
}
