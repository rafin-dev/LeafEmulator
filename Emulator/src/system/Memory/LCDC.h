#pragma once

namespace GameBoyEmulator {

	struct LCDC
	{
		bool LCD_PPU_Enabled = false;
		bool Window_TileMap_Selected = 0;
		bool Window_Enabled = false;
		bool TileData_AddresingMode_Selected = 0;
		bool BG_TileMap_Selected = 0;
		bool OBJ_DoubleSize_Enabled = false;
		bool OBJ_Enabled = false;
		bool LCDC_0 = false;
	};
}