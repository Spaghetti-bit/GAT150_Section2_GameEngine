#include "pch.h"
#include "PlayerComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components\RigidBodyComponent.h"
#include <Components\AudioComponent.h>

namespace nc
{
    bool PlayerComponent::Create(void* data)
    {
		m_owner = static_cast<GameObject*>(data);

        return true;
    }

    void PlayerComponent::Destroy()
    {
    }

    void PlayerComponent::Update()
    {
		auto contacts = m_owner->GetContactWithTag("Floor");
		bool onGround = !contacts.empty();


		//Player Controller	
		nc::Vector2 force{ 0, 0 };
		if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_A) == nc::InputSystem::eButtonState::HELD)
		{
			force.x = -300;
		}
		if (m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_D) == nc::InputSystem::eButtonState::HELD)
		{
			force.x = 300;
		}
		if (onGround && m_owner->m_engine->GetSystem<nc::InputSystem>()->GetButtonState(SDL_SCANCODE_SPACE) == nc::InputSystem::eButtonState::PRESSED)
		{
			force.y = -1200;
			AudioComponent* audioComponent = m_owner->GetComponent<AudioComponent>();
			if (audioComponent)
			{
				audioComponent->Play();
			}
		}

		force = nc::Vector2::Rotate(force, nc::math::DegreesToRadians(m_owner->m_transform.angle));


		PhysicsComponent* pComponent = m_owner->GetComponent<RigidBodyComponent>();

		if (pComponent)
		{
			pComponent->ApplyForce(force);
		}


		auto coinContacts = m_owner->GetContactWithTag("Coin");
		for (GameObject* contact : coinContacts)
		{
			contact->m_flags[GameObject::eFlags::DESTROY] = true;
		}
    }

}

