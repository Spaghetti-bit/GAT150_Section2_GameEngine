#pragma once
#include "Objects/GameObject.h"

namespace nc
{

	//forward declaration
	class GameObject;

	class Component : public Object
	{
	public:
		// pure virtual
		virtual void Update() = 0; 

		friend class GameObject;

	protected:
		GameObject* m_owner{ nullptr };
	};
}