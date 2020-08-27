#include "pch.h"
#include "Graphics/Texture.h"
#include "Engine.h"
#include "Core/Json.h"
#include "Objects/ObjectFactory.h"
#include "Components/PlayerComponent.h"
#include "Objects/Scene.h"

nc::Scene scene;
nc::Engine engine;

int main(int, char**)
{
	engine.Startup();
	scene.Create(&engine);

	nc::ObjectFactory::Instance().Initialize();
	nc::ObjectFactory::Instance().Register("PlayerComponent", new nc::Creator<nc::PlayerComponent, nc::Object>);
	
	rapidjson::Document document;
	nc::json::Load("scene.txt", document);
	scene.Read(document);

	for (size_t i = 0; i < 10; i++)
	{
		nc::GameObject* gameObject = nc::ObjectFactory::Instance().Create<nc::GameObject>("ProtoBox");
		if (gameObject)
		{
			gameObject->m_transform.position = nc::Vector2{ nc::random(0, 800), nc::random(0,200) };
			gameObject->m_transform.angle = nc::random(0, 360);
			scene.AddGameObject(gameObject);
		}
	}

	SDL_Event event;
	bool quit = false;
	while (!quit)
	{
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		if (engine.GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_ESCAPE) == nc::InputSystem::eButtonState::PRESSED)
		{
			quit = true;
		}

		//Frame

		//update
		engine.Update();
		scene.Update();
		
		
		
		engine.GetSystem<nc::Renderer>()->BeginFrame();
		
		scene.Draw();
				
		engine.GetSystem<nc::Renderer>()->EndFrame();
	}

	scene.Destroy();
	engine.Shutdown();

	return 0;
}