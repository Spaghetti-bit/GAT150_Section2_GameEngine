#include "pch.h"
#include "PhysicsComponent.h"
#include "Objects/GameObject.h"

namespace nc
{
    bool PhysicsComponent::Create(void* data)
    {
        m_owner = static_cast<GameObject*>(data);
        m_dampening = 0.98f;
        return true;
    }

    void PhysicsComponent::Destroy()
    {
    }

    void PhysicsComponent::Update()
    {
        //physics
        m_velocity += m_force * m_owner->m_engine->GetTimer().DeltaTime();
        m_velocity *= m_dampening;
        m_owner->m_transform.position += m_velocity * m_owner->m_engine->GetTimer().DeltaTime();

    }

}

