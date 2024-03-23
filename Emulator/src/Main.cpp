#include "system/GameBoy.h"

int main()
{
	GameBoyEmulator::GameBoy* gb = new GameBoyEmulator::GameBoy();

	gb->Run("Test");

	delete gb;
}