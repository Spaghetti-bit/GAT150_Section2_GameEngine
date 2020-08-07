// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Graphics/Texture.h"
#include "Graphics/Renderer.h"
#include "Resources/ResourceManager.h"
#include "Input/InputSystem.h"
#include "Math/Math.h"

nc::ResourceManager resourceManager;
nc::Renderer renderer;
nc::InputSystem inputSystem;

int main(int, char**)
{
	renderer.Startup();
	inputSystem.Startup();
	renderer.Create("GAT150", 800, 600);
	
	
	nc::Texture* texture = resourceManager.Get<nc::Texture>("birb.png", &renderer);
	float angle{ 0.0f };

	nc::Vector2 position{ 400, 300 };





	

	SDL_Event event;
	bool quit{ false };
	while (!quit)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		default:
			break;
		}

		// Key states and inputs

		// Left and Right
		if (inputSystem.GetButtonState(SDL_SCANCODE_LEFT) == nc::InputSystem::eButtonState::HELD)
		{
			position.x = position.x - 1.0f;
		}
		if (inputSystem.GetButtonState(SDL_SCANCODE_RIGHT) == nc::InputSystem::eButtonState::HELD)
		{
			position.x = position.x + 1.0f;
		}

		// Up and Down
		if (inputSystem.GetButtonState(SDL_SCANCODE_UP) == nc::InputSystem::eButtonState::HELD)
		{
			position.y -= 1.0f;
		}
		if (inputSystem.GetButtonState(SDL_SCANCODE_DOWN) == nc::InputSystem::eButtonState::HELD)
		{
			position.y += 1.0f;
		}
		// Rotation Counter Clockwise and Clockwise
		if (inputSystem.GetButtonState(SDL_SCANCODE_A) == nc::InputSystem::eButtonState::HELD)
		{
			angle -= nc::math::DegreesToRadians(10.0f);
		}
		if (inputSystem.GetButtonState(SDL_SCANCODE_D) == nc::InputSystem::eButtonState::HELD)
		{
			angle += nc::math::DegreesToRadians(10.0f);
		}

		//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		
		//BEGIN
		inputSystem.Update();
		renderer.BeginFrame();

		// draw

		texture->Draw(position, { .25f, .25f }, angle);
		//texture->Draw({ 600, 300 }, { 1, 1 }, angle + .5f);
		//angle += .02f;

		
		//END
		renderer.EndFrame();


		
	}
	
	inputSystem.Shutdown();
	renderer.Shutdown();
	SDL_Quit();


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
