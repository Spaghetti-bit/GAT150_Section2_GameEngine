#pragma once
#include "Component.h"
#include "Math/Vector2.h"

namespace nc
{
	class PhysicsComponent : public Component
	{
	public:
		// Inherited via Component
		virtual bool Create(void* data = nullptr) override;
		virtual void Destroy() override;
		virtual void Update() override;
		virtual Object* Clone() override { return  new PhysicsComponent{ *this }; }


		virtual void ApplyForce(const Vector2& force) { m_force = force; }
		virtual Vector2& GetVelocity() { return m_velocity; }

		

	protected:
		Vector2 m_velocity{ 0,0 };
		Vector2 m_force{ 0,0 };
		float m_dampening{ 1 };


	};
}