#include "pch.h"
#include "PlayerComponent.h"
#include "Components/PhysicsComponent.h"

namespace nc
{
    bool PlayerComponent::Create(void* data)
    {
        return true;
    }

    void PlayerComponent::Destroy()
    {
    }

    void PlayerComponent::Update()
    {
		//Player Controller	
		nc::Vector2 force{ 0, 0 };
		
		if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_W) == nc::InputSystem::eButtonState::HELD)
		{


			force = nc::Vector2::forward * 1500.0f;
		}
		if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_S) == nc::InputSystem::eButtonState::HELD)
		{
			m_owner->m_transform.position.y += 200.0f * m_owner->m_engine->GetTimer().DeltaTime();
		}
		if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == nc::InputSystem::eButtonState::HELD)
		{
			m_owner->m_transform.angle -= 90.0f * m_owner->m_engine->GetTimer().DeltaTime();
		}
		if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_D) == nc::InputSystem::eButtonState::HELD)
		{
			m_owner->m_transform.angle += 90.0f * m_owner->m_engine->GetTimer().DeltaTime();
		}
		force = nc::Vector2::Rotate(force, nc::math::DegreesToRadians(m_owner->m_transform.angle));


		PhysicsComponent* pComponent = m_owner->GetComponent<PhysicsComponent>();

		if (pComponent)
		{
			pComponent->ApplyForce(force);
		}

    }

}

