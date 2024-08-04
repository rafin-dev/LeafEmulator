#include "Emulator.h"

#define PixelSize 5

namespace GameBoyEmulator {

	Emulator::Emulator(sf::RenderWindow* w)
		: processor(&GBMemory), pixelProcessor(&GBMemory), Window(w)
	{
		for (int y = 0; y < 144; y++)
		{
			for (int x = 0; x < 160; x++)
			{
				Pixels[y][x] = sf::RectangleShape(sf::Vector2f(PixelSize, PixelSize));
				Pixels[y][x].setFillColor(sf::Color::Black);
				Pixels[y][x].setPosition(sf::Vector2f(x * PixelSize, y * PixelSize));
			}
		}
	}

	Emulator::~Emulator()
	{

	}

	void Emulator::Update()
	{
		// TODO: update the GameBoy
		

		// For every pixel, update the color andd draw onto the screen
		for (int y = 0; y < 144; y++)
		{
			for (int x = 0; x < 160; x++)
			{
				Pixels[y][x].setFillColor(GetRenderColor(x, y));
				Window->draw(Pixels[y][x]);
			}
		}
	}

	const sf::Color& Emulator::GetRenderColor(int x, int y)
	{
		static sf::Color White = sf::Color(155, 188, 15, 255);
		static sf::Color LightGrey = sf::Color(139, 172, 15, 255);
		static sf::Color DarkGrey = sf::Color(48, 98, 48, 255);
		static sf::Color Black = sf::Color(15, 56, 15, 255);

		switch (pixelProcessor.GetPixel(x, y))
		{
		case 0b00:
			return White;

			break;

		case 0b01:
			return LightGrey;

			break;

		case 0b10:
			return DarkGrey;

			break;

		case 0b11:
			return Black;

			break;

		default:
			return White;

			break;
		}
	}

}
