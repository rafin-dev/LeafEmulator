#include "WindowData.h"

#include "GameBoyMemory.h"

uint8_t GameBoyEmulator::WindowData::GetTile(int tile) const
{
	if (!mem->GetGraphicsControl().Window_TileMap_Selected)
	{
		return mem->ReadData(BeginTileMap1 + tile);
	}
	else
	{
		return mem->ReadData(BeginTileMap2 + tile);
	}
}
