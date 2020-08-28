#pragma once
#include "PhysicsComponent.h"
#include "box2d/box2d.h"

namespace nc
{
	class RigidBodyComponent : public PhysicsComponent 
	{
	public:

		// Inherited via Component
		virtual bool Create(void* data = nullptr) override;
		virtual void Destroy() override;
		virtual void Update() override;
		virtual Object* Clone() override { return  new RigidBodyComponent{ *this }; }

		void Read(const rapidjson::Value& value);

		void ApplyForce(const Vector2& force) override;

	protected:
		PhysicsSystem::RigidBodyData m_data;
		b2Body* m_body{ nullptr };

	};
}