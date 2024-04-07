#pragma once

#include "Menu.h"

#include "vendor/IMGUI/imstb_textedit.h"
#include "SFML/Window.hpp"
#include "SFML/Window/Keyboard.hpp"

namespace GameBoyEmulator {

	class StartMenu;

	class EmulationErrorMenu : public MenuState
	{
	public:

		void Update() override
		{
			ImGui::Begin("EMULATION ERROR");
			ImGui::TextColored(ImVec4(1, 0, 0, 1), "FATAL EMULATION ERROR, UNKNOWN OPCODE!");
			ImGui::Text("Invalid ROM");

			if (ImGui::Button("OK"))
			{
				SwitchMenus = true;
				NextMenuID = GetMenuID<StartMenu>();
			}

			ImGui::End();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				SwitchMenus = true;
				NextMenuID = GetMenuID<StartMenu>();
			}
		}

		void Sleep() override
		{
			SwitchMenus = false;
		}
	};
}