#include "SystemManager.h"

namespace GameBoyEmulator {

	std::function<bool(std::string&)> SystemManager::LoadRomEvent;

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
}