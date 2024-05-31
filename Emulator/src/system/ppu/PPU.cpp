#include "system/ppu/PPU.h"

namespace GameBoyEmulator {

    PPU::PPU(GameBoyMemory* mem)
        : Memory(mem)
    {
    }

    void PPU::Render()
    {
        const LCDC& GraphicsSettings = Memory->GetGraphicsControl();
        
        
    }

}