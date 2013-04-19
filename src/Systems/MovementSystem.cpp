/* 
 * File:   PhysicsSystem.cpp
 * Author: marzena
 * 
 * Created on 19 luty 2013, 22:44
 */

#include "Systems/MovementSystem.hpp"
#include <iostream>
#include <unordered_map>
#include <assert.h>
#include <SFML/System/Time.hpp>


MovementSystem::MovementSystem(
	std::unordered_map<int,PositionComponent>& positionComponents,
	std::unordered_map<int,PhysicsComponent>& physicsComponents)
:positionComponents(positionComponents),
	physicsComponents(physicsComponents)
{
}

MovementSystem::MovementSystem(const MovementSystem& orig)
:positionComponents(orig.positionComponents),
	physicsComponents(orig.physicsComponents)
{
}

MovementSystem::~MovementSystem()
{
}

void MovementSystem::addEntity(int EID)
{
	assert( positionComponents.find(EID) != positionComponents.end() &&
			physicsComponents.find(EID) != physicsComponents.end());
	entities.push_back(EID);
}

void MovementSystem::move(sf::Time time)
{
    double deltaT=time.asSeconds();
	for(auto it=entities.begin();it!=entities.end();it++)
    {
        PositionComponent& posC=positionComponents.at(*it);
        PhysicsComponent& physC=physicsComponents.at(*it);
        physC.vx+=physC.ax*deltaT;
		physC.vy+=physC.ay*deltaT;
		physC.vz+=physC.az*deltaT;
		posC.x+=deltaT*physC.vx;
		posC.y+=deltaT*physC.vy;
		posC.z+=deltaT*physC.vz;
	}
	
}