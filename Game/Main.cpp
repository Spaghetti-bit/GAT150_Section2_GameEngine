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
	nc::ObjectFactory::Instance().Register("PlayerComponent", nc::Object::Instantiate<nc::PlayerComponent>);
	

	
	rapidjson::Document document;
	nc::json::Load("scene.txt", document);
	scene.Read(document);
	//nc::GameObject* player = nc::ObjectFactory::Instance().Create<nc::GameObject>("GameObject");

	//player->Create(&engine);

	////rapidjson::Document document;
	//nc::json::Load("player.txt", document);
	//player->Read(document);

	//nc::Component* component;


	////PhysicsC
	//component = nc::ObjectFactory::Instance().Create<nc::Component>("PhysicsComponent");
	//component->Create(player);
	//player->AddComponent(component);


	////SpriteC
	//component = nc::ObjectFactory::Instance().Create<nc::Component>("SpriteComponent");
	//nc::json::Load("sprite.txt", document);
	//component->Create(player);
	//component->Read(document);
	//player->AddComponent(component);



	//// PlayerC
	//component = nc::ObjectFactory::Instance().Create<nc::Component>("PlayerComponent");
	//component->Create(player);
	//player->AddComponent(component);



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
		scene.Update();
		//player->Update();
		
		
		
		engine.GetSystem<nc::Renderer>()->BeginFrame();
		
		
		background->Draw({ 0, 0 }, { 1, 1 }, 0);
		scene.Draw();
		
		
		engine.GetSystem<nc::Renderer>()->EndFrame();
	}

	scene.Destroy();
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