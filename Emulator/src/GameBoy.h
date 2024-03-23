#pragma once

#include <string>

namespace GameBoyEmulator {

	class GameBoy
	{
	public:

		GameBoy();

		void Run(std::string filepath);

	private:

		bool LoadROM(std::string& filePath);
	};

}
