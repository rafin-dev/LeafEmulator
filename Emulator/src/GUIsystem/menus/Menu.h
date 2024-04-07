#pragma once
#include "Log.h"
#include "GUIsystem/SystemManager.h"
#include "vendor/IMGUI/imgui.h"

namespace GameBoyEmulator {

	extern int IDcounter;

	// Neat little trick to easily asign an ID for a type using templates
	template<class T>
	int GetMenuID()
	{
		static int MenuID = IDcounter++;
		return MenuID;
	}

	// Parent class for the menus
	// Will be used as part of a semi "finite state machine" for the menus
	class MenuState
	{
	public:

		// Method called every frame on the current menu
		virtual void Update() {}

		// Method called to "alert" the menu that it will be the current menu in the next frame
		virtual void WakeUp() {}

		// Method called to "alert the menu that it will no longer be the current menu
		virtual void Sleep() {}

		// Methods and menbers used for controlling the menu switching
		bool ShouldSwitchMenus() { return SwitchMenus; }

		int GetNextmenuID() { return NextMenuID; }

	protected:

		int NextMenuID;
		bool SwitchMenus;
	};

}
