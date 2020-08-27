#pragma once

// local
#include "Object.h"
#include "Engine.h"
#include "Math\Transform.h"

// system
#include <vector>
#include <bitset>

namespace nc
{
	//forward declaration
	class Component;

	class GameObject : public Object
	{
	public:
		enum eFlags
		{
			ACTIVE,
			VISIBLE,
			DESTROY,
			TRANSIENT
		};

	public:
		GameObject() = default;
		GameObject(const GameObject& other);

		virtual bool Create(void* data = nullptr) override;
		virtual void Destroy() override;
		virtual Object* Clone() { return new GameObject{ *this }; }

		void Read(const rapidjson::Value& value) override;
		void ReadComponents(const rapidjson::Value& value);

		void Update();
		void Draw();

		void BeginContact(GameObject* other);
		void EndContact(GameObject* other);

		template<typename T>
		T* GetComponent()
		{
			T* result = nullptr;
			for (auto c : m_components)
			{
				result = dynamic_cast<T*>(c);
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
		std::string m_name;
		std::string m_tag;
		float m_lifetime{ 0 };

		std::bitset<32> m_flags;

		Transform m_transform;
		Engine* m_engine{ nullptr };

	protected:
		std::vector<Component*> m_components;


	};
}