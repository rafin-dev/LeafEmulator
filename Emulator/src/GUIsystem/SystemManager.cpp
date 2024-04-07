#include "SystemManager.h"

namespace GameBoyEmulator {

	std::function<bool(std::string&)> SystemManager::LoadRomEvent;
	std::function<void(void)> SystemManager::CallEmulationErrorMenuEvent;

	bool SystemManager::LoadROM(std::string& path)
	{
#ifdef DEBUG
		if (!LoadRomEvent)
		{
			SYS_LOG_ERROR("CRITICAL ERROR, UNINTIALIZED LOAD ROM EVENT");
		}
#endif // DEBUG

		return LoadRomEvent(path);
	}

	void SystemManager::CallEmulationErrorMenu()
	{
#ifdef DEBUG
		if (!CallEmulationErrorMenuEvent)
		{
			SYS_LOG_ERROR("CRITICAL ERROR, UNINTIALIZED CALL EMULATION ERROR MENU EVENT");
		}
#endif // DEBUG

		CallEmulationErrorMenuEvent();
	}
}