#pragma once

namespace GameBoyEmulator {

	enum ScreenColors : uint8_t
	{
		Black = 0,
		DarkGray = 1,
		LightGray = 2,
		White = 3
	};

	struct Tile
	{
	public:

		Tile()
		{
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					Pixels[i][j] = ScreenColors::White;
				}
			}
		}

		ScreenColors Pixels[8][8];
	};
}