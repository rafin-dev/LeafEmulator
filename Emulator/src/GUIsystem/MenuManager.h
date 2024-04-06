#pragma once

#include "menus/Menu.h"
#include "menus/StartMenu.h"
#include <map>

#define MenuID(x) GetMenuID<x>()

namespace GameBoyEmulator {

	class MenuManager
	{
	public:
		MenuManager();
		~MenuManager();

		void Update();

	private:

		// Map that holds a all the menus and correlates them to their IDs
		std::map<int, MenuState*> Menus;
		MenuState* CurrentMenu;
	};
}