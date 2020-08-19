#include "pch.h"
#include "ObjectFactory.h"
#include "Components/PhysicsComponent.h"
#include "Components/SpriteComponent.h"

#include "Objects/GameObject.h"

namespace nc 
{
	void ObjectFactoryImpl::Initialize()
	{
		ObjectFactory::Instance().Register("GameObject", Object::Instantiate<GameObject>);
		ObjectFactory::Instance().Register("PhysicsComponent", Object::Instantiate<PhysicsComponent>);
		ObjectFactory::Instance().Register("SpriteComponent", Object::Instantiate<SpriteComponent>);	}

}
