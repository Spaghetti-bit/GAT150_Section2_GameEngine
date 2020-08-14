#include "pch.h"
#include "Components/PhysicsComponent.h"
#include "Components/SpriteComponent.h"
#include "Graphics/Texture.h"
#include "Objects/GameObject.h"
#include "Engine.h"
#include "Components/PlayerComponent.h"
#include "Core/Json.h"

nc::Engine engine;
nc::GameObject player;

int main(int, char**)
{
	

	rapidjson::Document document;


	engine.Startup();

	player.Create(&engine);
	nc::json::Load("player.txt", document);
	player.Read(document);

	//PhysicsC
	nc::Component* component = new nc::PhysicsComponent;
	//player.m_transform.position = { 400, 300 };
	player.AddComponent(component);
	component->Create();


	//SpriteC
	component = new nc::SpriteComponent;
	player.AddComponent(component);


	nc::json::Load("sprite.txt", document);
	component->Read(document);
	component->Create();

	// PlayerC
	component = new nc::PlayerComponent;
	player.AddComponent(component);
	component->Create();



	nc::Texture* background = engine.GetSystem<nc::ResourceManager>()->Get<nc::Texture>("Background.png", engine.GetSystem<nc::Renderer>());

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
		player.Update();
		engine.GetSystem<nc::Renderer>()->BeginFrame();
		background->Draw({ 0, 0 }, { 1, 1 }, 0);
		player.Draw();
		engine.GetSystem<nc::Renderer>()->EndFrame();
	}

	engine.Shutdown();

	return 0;
}


//nc::json::Load("json.txt", document);
//
//std::string str;
//nc::json::Get(document, "string", str);
//std::cout << str << std::endl;
//
//bool b;
//nc::json::Get(document, "bool", b);
//std::cout << b << std::endl;
//
//int i1;
//nc::json::Get(document, "integer1", i1);
//std::cout << i1 << std::endl;
//
//int i2;
//nc::json::Get(document, "integer2", i2);
//std::cout << i2 << std::endl;
//
//float f;
//nc::json::Get(document, "float", f);
//std::cout << f << std::endl;
//
//nc::Vector2 v2;
//nc::json::Get(document, "vector2", v2);
//std::cout << v2 << std::endl;
//
//nc::Color color;
//nc::json::Get(document, "color", color);
//std::cout << color << std::endl;