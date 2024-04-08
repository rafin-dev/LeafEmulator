#pragma once

#include "menu.h"
#include "GUIsystem/SystemManager.h"

#include <sstream>
#include <iostream>
#include "SFML/Window.hpp"

namespace GameBoyEmulator {

	class StartMenu : public MenuState
	{

	public:
		void Update()
		{
			ImGui::Begin("Prototype Emulator");

			ImGui::SetWindowSize(ImVec2(600, 500));

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

		void Sleep() override
		{
			memset(PathBuffer, 0, sizeof(PathBuffer));
			SwitchMenus = false;
		}

	private:

		char PathBuffer[128];
	};
}