/* 
 * File:   PhysicsSystem.cpp
 * Author: marzena
 * 
 * Created on 19 luty 2013, 22:44
 */

#include "Systems/MovementSystem.hpp"
#include "Components/StandsOnComponent.hpp"
#include "Components/StandableComponent.hpp"
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
			components.find(Level::CompKey(EID, "Physics")) != components.end() ); 
		//	components.find(Level::CompKey(EID, "StandsOn")) != components.end() );
	entities.push_back(EID);
}

void MovementSystem::update(sf::Time time)
{
	std::cerr<<"Movement\n";
    double deltaT=time.asSeconds();
	for(auto it=entities.begin();it!=entities.end();it++)
    {
        PositionComponent& posC = *boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(*it, "Position")));
        PhysicsComponent& physC = *boost::polymorphic_downcast<PhysicsComponent*>(components.at(Level::CompKey(*it, "Physics")));
        
		StandsOnComponent empty(*it);
		StandsOnComponent& standsOnC=
		(components.find(Level::CompKey(*it, "StandsOn")) != components.end() ?
			*boost::polymorphic_downcast<StandsOnComponent*>(components.at(Level::CompKey(*it, "StandsOn"))) : empty);
		
		//StandsOnComponent& standsOnC = *boost::polymorphic_downcast<StandsOnComponent*>(components.at(Level::CompKey(*it, "StandsOn")));
		
		StandableComponent groundC(-1, 0, 1000, 0,0, 0);
		if(standsOnC.standing)
			groundC = *boost::polymorphic_downcast<StandableComponent*>(components.at(Level::CompKey(standsOnC.standsOn, "Standable")));
		else
			groundC=StandableComponent(-1);
		
		double oldVx=physC.vx;
		physC.vx+=physC.ax*deltaT;
		physC.vy+=physC.ay*deltaT;
		physC.vz+=physC.az*deltaT;
		
		if(oldVx*physC.vx<0)
		{
			physC.vx=0;
		}
		
		if(physC.vx > physC.maxSpeed*groundC.maxSpeedMultiplier)
		{
			physC.vx=physC.maxSpeed*groundC.maxSpeedMultiplier;
		}
		
		posC.x+=deltaT*physC.vx;
		posC.y+=deltaT*physC.vy;
		posC.z+=deltaT*physC.vz;
	}
	std::cerr<<"Movement end\n";
}