#include "Menu.h"

namespace GameBoyEmulator {

	int IDcounter = 0;

	template<typename T>
	int GetMenuID()
	{
		int MenuID = IDcounter + 1;
		return MenuID;
	}
}