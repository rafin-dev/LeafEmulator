#pragma once

#include <string>

#include "system/Memory/GameBoyMemory.h"
#include "cpu/CPU.h"
#include "ppu/PPU.h"

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

namespace GameBoyEmulator {

	class Emulator
	{
	public:
		Emulator(sf::RenderWindow* w);
		~Emulator();

		bool LoadROM();

		void Update();

	private:

		sf::RenderWindow* Window;

		GameBoyMemory GBMemory;

		CPU processor;
		PPU pixelProcessor;

		sf::RectangleShape Pixels[144][160];

		const sf::Color& GetRenderColor(int x, int y);
	};
}