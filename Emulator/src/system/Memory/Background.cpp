#include "Background.h"

#include "GameBoyMemory.h"

uint8_t GameBoyEmulator::Background::GetTile(int tile) const
{
	if (!mem->GetGraphicsControl().BG_TileMap_Selected)
	{
		return mem->ReadData(BeginTileMap1 + tile);
	}
	else
	{
		return mem->ReadData(BeginTileMap2 + tile);
	}
}
