/* 
 * File:   PlayerInputSystem.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 21:19
 */

#include <assert.h>
#include <SFML/Window/Keyboard.hpp>

#include "Systems/PlayerInputSystem.hpp"

PlayerInputSystem::PlayerInputSystem(std::unordered_map<int,PositionComponent>& positionComponents,
					std::unordered_map<int,PhysicsComponent>& physicsComponents)
:positionComponents(positionComponents),
	physicsComponents(physicsComponents)
{
}

PlayerInputSystem::PlayerInputSystem(const PlayerInputSystem& orig)
:positionComponents(orig.positionComponents),
	physicsComponents(orig.physicsComponents)
{
}

PlayerInputSystem::~PlayerInputSystem()
{
}

void PlayerInputSystem::addEntity(int EID)
{
    assert( positionComponents.find(EID) != positionComponents.end() &&
			physicsComponents.find(EID) != physicsComponents.end());
	entities.push_back(EID);
}

void PlayerInputSystem::handleInput()
{
    for(auto eid: entities)
    {
		PhysicsComponent& pC=physicsComponents.at(eid);
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			pC.ax=-200;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			pC.ax=200;
		}
		else
			pC.ax=0;

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			pC.ay=-200;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			pC.ay=200;
		}
		else
			pC.ay=0;
    }
}