#pragma once

#include "menu.h"
#include "GUIsystem/SystemManager.h"
#include "vendor/IMGUI/imgui.h"

namespace GameBoyEmulator {

	class StartMenu : public Menu
	{
		void Update()
		{
			ImGui::Text("Select a ROM to play!");
			ImGui::InputText(" ", PathBuffer, IM_ARRAYSIZE(PathBuffer));

			if (ImGui::Button("Load ROM"))
			{
				PathBuffer[127] = '\n';
				std::string fp(PathBuffer);
				SystemManager::LoadROM(std::string(fp));
			}
		}

	private:

		char PathBuffer[128];
	};
}