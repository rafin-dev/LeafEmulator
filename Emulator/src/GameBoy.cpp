#include "GameBoy.h"

#include <vendor/IMGUI/imgui.h>
#include <vendor/IMGUI/IMGUI-SFML/imgui-SFML.h>

#include <SFML/System/Clock.hpp>

#include "GUIsystem/menus/EmulationErrorMenu.h"


namespace GameBoyEmulator {

	sf::Clock deltaClock;

	GameBoy::GameBoy()
		: Window(sf::VideoMode(1120, 1008), "Prototype", sf::Style::Titlebar | sf::Style::Close),
		MenuStateMachine(new MenuManager)
	{
		SYS_LOG_TRACE("Prototype GameBoy emulator. Version: Alpha 0.0.0");

		SYS_LOG_TRACE("Initialized window");

		ImGui::SFML::Init(Window);
		SYS_LOG_TRACE("Initialized ImGui");

		SYS_LOG_TRACE("Initializing Menu-System connector");

		SystemManager::LoadRomEvent = std::bind(&GameBoy::LoadROM, this, std::placeholders::_1);
		SystemManager::CallEmulationErrorMenuEvent = std::bind(&GameBoy::CallEmuErrorMenu, this);

		SYS_LOG_TRACE("Menu-System connector initialized");
	}

	GameBoy::~GameBoy()
	{
		delete MenuStateMachine;
	}

	bool GameBoy::LoadROM(std::string& filePath)
	{
		SYS_LOG_INFO("Loading ROM at: {}", filePath);
		return true;
	}

	void GameBoy::CallEmuErrorMenu()
	{
		MenuStateMachine->SwitchMenu(GetMenuID<EmulationErrorMenu>());
	}

	void GameBoy::PoolEvents()
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed)
			{
				KeepRuning = false;
			}
		}
	}

	void GameBoy::UpdateImGui()
	{
		ImGui::SFML::Update(Window, deltaClock.restart());

		MenuStateMachine->Update();
	}

	void GameBoy::Run(std::string filePath)
	{
		while (KeepRuning)
		{
			PoolEvents();



			UpdateImGui();

			Window.clear();
			ImGui::SFML::Render(Window);
			Window.display();
		}

		SYS_LOG_TRACE("ShuttingDown");
		ImGui::SFML::Shutdown();
		Window.close();
	}

}