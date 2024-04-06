#pragma once

#include "menu.h"
#include "GUIsystem/SystemManager.h"
#include "vendor/IMGUI/imgui.h"

namespace GameBoyEmulator {

	class StartMenu : public MenuState
	{
		void Update()
		{
			ImGui::Begin("Prototype Emulator");

			ImGui::Text("Select a ROM to play!");
			ImGui::InputTextWithHint(" ", "ROM file path", PathBuffer, IM_ARRAYSIZE(PathBuffer));

			if (ImGui::Button("Load ROM"))
			{
				PathBuffer[127] = '\n';
				std::string fp(PathBuffer);
				SystemManager::LoadROM(std::string(fp));
			}

			ImGui::End();
		}

	private:

		char PathBuffer[128];
	};
}