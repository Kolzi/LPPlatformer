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
#include <boost/cast.hpp>


MovementSystem::MovementSystem(Level::CompMap& components)
:System(components)
{
}

MovementSystem::MovementSystem(const MovementSystem& orig)
:System(orig)
{
}

MovementSystem::~MovementSystem()
{
}

void MovementSystem::addEntity(int EID)
{
	assert( components.find(Level::CompKey(EID, "Position")) != components.end() &&
			components.find(Level::CompKey(EID, "Physics")) != components.end());
	entities.push_back(EID);
}

void MovementSystem::update(sf::Time time)
{
    double deltaT=time.asSeconds();
	for(auto it=entities.begin();it!=entities.end();it++)
    {
        PositionComponent* posC=boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(*it, "Position")));
        PhysicsComponent* physC=boost::polymorphic_downcast<PhysicsComponent*>(components.at(Level::CompKey(*it, "Physics")));
        physC->vx+=physC->ax*deltaT;
		physC->vy+=physC->ay*deltaT;
		physC->vz+=physC->az*deltaT;
		posC->x+=deltaT*physC->vx;
		posC->y+=deltaT*physC->vy;
		posC->z+=deltaT*physC->vz;
	}
	
}