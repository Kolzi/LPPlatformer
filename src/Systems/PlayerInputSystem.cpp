/* 
 * File:   PlayerInputSystem.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 21:19
 */

#include <SFML/Window/Input.hpp>
#include <assert.h>

#include "Systems/PlayerInputSystem.hpp"

PlayerInputSystem::PlayerInputSystem(const sf::Input& input,
					std::unordered_map<int,PositionComponent>& positionComponents,
					std::unordered_map<int,PhysicsComponent>& physicsComponents)
:input(input),positionComponents(positionComponents),
	physicsComponents(physicsComponents)
{
}

PlayerInputSystem::PlayerInputSystem(const PlayerInputSystem& orig)
:input(orig.input),positionComponents(orig.positionComponents),
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
		if(input.IsKeyDown(sf::Key::Left))
		{
			pC.ax=-200;
		}
		else if(input.IsKeyDown(sf::Key::Right))
		{
			pC.ax=200;
		}
		else
			pC.ax=0;

		if(input.IsKeyDown(sf::Key::Up))
		{
			pC.ay=-200;
		}
		else if(input.IsKeyDown(sf::Key::Down))
		{
			pC.ay=200;
		}
		else
			pC.ay=0;
    }
}