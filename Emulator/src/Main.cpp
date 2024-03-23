#include "GameBoy.h"
#include "Log.h"

int main()
{
	Log::Init();

	GameBoyEmulator::GameBoy* gb = new GameBoyEmulator::GameBoy();
	gb->Run("Test");

	delete gb;
}