#pragma once

// local
#include "Object.h"
#include "Engine.h"
#include "Math\Transform.h"

// system
#include <vector>

namespace nc
{
	//forward declaration
	class Component;

	class GameObject : public Object
	{
	public:
		// Inherited via Object
		virtual bool Create(void* data = nullptr) override;
		virtual void Destroy() override;


		void Update();
		void Draw();

		template<typename T>
		T* GetComponent()
		{
			T* result{ nullptr };
			for (auto component : m_components)
			{
				result = dynamic_cast<T*>(component);
				if (result) break;

			}

			return result;

		}

		void AddComponent(Component* component);
		void RemoveComponent(Component* component);
		void RemoveAllComponents();

		friend class Component;
		friend class PhysicsComponent;
	public:
		Transform m_transform;
		Engine* m_engine;

	protected:
		std::vector<Component*> m_components;
	};
}