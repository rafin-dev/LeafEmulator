#include "MenuManager.h"

#include "menus/EmulationErrorMenu.h"

#define InsertMenu(x) Menus.insert(std::make_pair<int, MenuState*>(MenuID(x), new x()))

namespace GameBoyEmulator {

	MenuManager::MenuManager()
	{
		// Sets all the Menu States
		InsertMenu(StartMenu);
		InsertMenu(EmulationErrorMenu);

		// Set the inital menu
		CurrentMenu = Menus[MenuID(StartMenu)];
		CurrentMenu->WakeUp();
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
			SwitchMenu(CurrentMenu->GetNextmenuID());
		}
	}

	void MenuManager::SwitchMenu(int mID)
	{
		SYS_LOG_TRACE("Switching Menus, New Menu ID: {}", mID);
		// Searches for the new menu
		auto m = Menus.find(mID);

#ifdef DEBUG
		// Asserts the existance of the menu (in debug mode)
		if (m == Menus.end())
		{
			SYS_LOG_ERROR("CRITICAL ERROR, ATEMPT TO WAKE UNKNOWN MENU OF ID: {}! STOPING EXECUTION", mID);
			throw std::exception("Unknow Menu");
		}
#endif

		// Changes the menu
		CurrentMenu->Sleep();
		CurrentMenu = m->second;
		CurrentMenu->WakeUp();
	}
}