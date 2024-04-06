#include "MenuManager.h"

#define InsertMenu(x) Menus.insert(std::make_pair<int, MenuState*>(MenuID(x), new x()))

namespace GameBoyEmulator {

	MenuManager::MenuManager()
	{
		// Sets all the Menu States
		InsertMenu(StartMenu);

		// Set the inital menu
		CurrentMenu = Menus[MenuID(StartMenu)];
	}

	MenuManager::~MenuManager()
	{
		// Freeing all the MenuStates stored in memory
		for (auto i : Menus)
		{
			delete i.second;
		}
	}

	void MenuManager::Update()
	{
		// Updates the current menu
		CurrentMenu->Update();

		// Checks if the current menu called for a menu change
		if (CurrentMenu->ShouldSwitchMenus())
		{
			SYS_LOG_TRACE("Switching Menus, New Menu ID: {}", CurrentMenu->GetNextmenuID());
			// Searches for the new menu
			auto m = Menus.find(CurrentMenu->GetNextmenuID());

#ifdef DEBUG
			// Asserts the existance of the menu (in debug mode)
			if (m == Menus.end())
			{
				SYS_LOG_ERROR("CRITICAL ERROR, ATEMPT TO WAKE UNKNOWN MENU! STOPING EXECUTION");
				throw std::exception("Unknow Menu");
			}
#endif

			// Changes the menu
			CurrentMenu->Sleep();
			CurrentMenu = m->second;
			CurrentMenu->WakeUp();
		}
	}
}