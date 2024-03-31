#include "GameBoy.h"

#include <vendor/IMGUI/imgui.h>
#include <vendor/IMGUI/IMGUI-SFML/imgui-SFML.h>

#include <SFML/System/Clock.hpp>


namespace GameBoyEmulator {

	sf::Clock deltaClock;

	GameBoy::GameBoy()
		: Window(sf::VideoMode(1120, 1008), "Prototype", sf::Style::Titlebar | sf::Style::Close)
	{
		ImGui::SFML::Init(Window);
		m = new StartMenu();
	}

	bool GameBoy::LoadROM(std::string& filePath)
	{
		return true;
	}

	void GameBoy::PoolEvents()
	{
		sf::Event event;
		while (Window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(event);

			if (event.type == sf::Event::Closed)
			{
				Window.close();
			}
		}
	}

	void GameBoy::UpdateImGui()
	{
		ImGui::SFML::Update(Window, deltaClock.restart());

		ImGui::Begin("Prototype Emulator");

		//ImGui::SetWindowPos(ImVec2(140, 126));
		//ImGui::SetWindowSize(ImVec2(840, 756));

		m->Update();

		ImGui::End();
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


			if (!Window.isOpen())
			{
				KeepRuning = false;
			}
		}

		ImGui::SFML::Shutdown();
	}

}