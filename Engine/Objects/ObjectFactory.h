#pragma once
#include "Core/Factory.h"
#include "Core/Singleton.h"
#include "Object.h"
//#include <string>

namespace nc
{
	class ObjectFactoryImpl : public Factory <Object, std::string>
	{
	public:
		void Initialize();
	};

	class ObjectFactory : public Singleton<ObjectFactoryImpl>
	{
	protected:
		ObjectFactory() {};
	};
}