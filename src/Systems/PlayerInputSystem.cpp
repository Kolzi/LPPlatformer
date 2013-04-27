/* 
 * File:   PlayerInputSystem.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 21:19
 */

#include <assert.h>
#include <SFML/Window/Keyboard.hpp>
#include <boost/cast.hpp>

#include "Systems/PlayerInputSystem.hpp"

PlayerInputSystem::PlayerInputSystem(Level::CompMap& components)
:System(components)
{
}

PlayerInputSystem::PlayerInputSystem(const PlayerInputSystem& orig)
:System(orig)
{
}

PlayerInputSystem::~PlayerInputSystem()
{
}

void PlayerInputSystem::addEntity(int EID)
{
    assert(components.find(Level::CompKey(EID, "Physics")) != components.end());
	entities.push_back(EID);
}

void PlayerInputSystem::update(sf::Time deltaTime)
{
    for(auto eid: entities)
    {
		PhysicsComponent* pC=boost::polymorphic_downcast<PhysicsComponent*>(components.at(Level::CompKey(eid, "Physics")));
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			pC->ax=-200;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			pC->ax=200;
		}
		else
			pC->ax=0;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			pC->ay=-200;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			pC->ay=200;
		}
		else
			pC->ay=0;
    }
}