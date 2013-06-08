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
#include "Components/StandsOnComponent.hpp"
#include "Components/StandableComponent.hpp"

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
		PhysicsComponent& pC=*boost::polymorphic_downcast<PhysicsComponent*>(components.at(Level::CompKey(eid, "Physics")));
		StandsOnComponent soEmpty(-1);
		StandsOnComponent& soC = components.find(Level::CompKey(eid, "StandsOn"))!=components.end()?
			*boost::polymorphic_downcast<StandsOnComponent*>(components.at(Level::CompKey(eid, "StandsOn"))) : soEmpty;
		
		StandableComponent sEmpty(-1);
		StandableComponent sC = components.find(Level::CompKey(soC.standsOn, "Standable"))!=components.end()?
			*boost::polymorphic_downcast<StandableComponent*>(components.at(Level::CompKey(soC.standsOn, "Standable"))) : sEmpty;
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
				pC.ax=-pC.acceleration*sC.accelerationMultiplier;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
				pC.ax=pC.acceleration*sC.accelerationMultiplier;
		}
		else
		{
			if(soC.standing)
			{
				double sign;
				if(pC.vx>0)
					sign=-1;
				else if(pC.vx<0)
					sign=1;
				else
					sign=0; //direction of decceleration
				pC.ax=sign*pC.stoppingSpeed*sC.stoppingMultiplier;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && soC.jumpingTimeLeft>0)
		{
				pC.ax=0;
				pC.vy=-soC.baseJumpingPower*sC.jumpingAccelerationMultiplier;
				soC.jumpingTimeLeft-=deltaTime.asSeconds();
		}
		else
		{
			soC.jumpingTimeLeft=0;
		}
    }
}