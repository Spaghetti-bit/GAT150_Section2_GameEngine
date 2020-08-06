// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Graphics/Texture.h"
#include "Graphics/Renderer.h"
#include "Resources/ResourceManager.h"

nc::ResourceManager resourceManager;
nc::Renderer renderer;

int main(int, char**)
{
	renderer.Startup();
	renderer.Create("GAT150", 800, 600);
	
	
	nc::Texture* texture = resourceManager.Get<nc::Texture>("birb.png", &renderer);
	float angle{ 0.0f };





	

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

	

		//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		
		//BEGIN
		renderer.BeginFrame();

		// draw

		texture->Draw({ 300, 300 }, { 1, 1 }, angle);
		texture->Draw({ 600, 300 }, { 1, 1 }, angle + .5f);
		angle += .02f;

		
		//END
		renderer.EndFrame();
		
	}
	

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
