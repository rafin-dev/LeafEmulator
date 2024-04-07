#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"

#include <functional>
#include <string>

#include "GUIsystem/menus/StartMenu.h"
#include "GUIsystem/MenuManager.h"


namespace GameBoyEmulator {

	class GameBoy
	{
	public:

		GameBoy();
		~GameBoy();

		void Run(std::string filepath);

	private:

		bool LoadROM(std::string& filePath);
		void CallEmuErrorMenu();

		void PoolEvents();

		void UpdateImGui();

		bool KeepRuning = true;

		sf::RenderWindow Window;
		MenuManager* MenuStateMachine;
		
	};

}
