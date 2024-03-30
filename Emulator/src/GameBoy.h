#pragma once

#include <string>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"

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
	};

}
