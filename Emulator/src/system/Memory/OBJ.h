#pragma once

#include <string>

namespace GameBoyEmulator {

	struct OBJ
	{
		uint8_t Y = 0;
		uint8_t X = 0;
		uint8_t Tile = 0;

		bool Priotity = false;
		bool Yflip = false;
		bool Xflip = false;
		bool Pallete = 0;
	};
}