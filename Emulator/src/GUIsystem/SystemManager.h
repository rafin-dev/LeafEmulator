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

	private:
		static std::function<bool(std::string&)> LoadRomEvent;

		friend class GameBoy;
	};
}
