#pragma once

#include <string>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include "GUIsystem/menus/StartMenu.h"

namespace GameBoyEmulator {

	class GameBoy
	{
	public:

		GameBoy();

		void Run(std::string filepath);

	private:

		bool LoadROM(std::string& filePath);

		void PoolEvents();

		void UpdateImGui();

		bool KeepRuning = true;

		sf::RenderWindow Window;
		Menu* m;
	};

}
