/* 
 * File:   GravitySystem.cpp
 * Author: marzena
 * 
 * Created on 21 luty 2013, 16:44
 */

#include <assert.h>
#include <boost/cast.hpp>

#include "Systems/GravitySystem.hpp"
#include "Systems/System.hpp"
#include "Components/GravityComponent.hpp"
#include "Systems/GravitySystem.hpp"

GravitySystem::GravitySystem(Level::CompMap& components)
:System(components)
{
}

GravitySystem::GravitySystem(const GravitySystem& orig)
:System(orig)
{
}

GravitySystem::~GravitySystem()
{
}

void GravitySystem::update(sf::Time deltaTime)
{
	for(int EID : entities)
	{
		GravityComponent* gC=boost::polymorphic_downcast<GravityComponent*>(components.at(Level::CompKey(EID, "Gravity")));
		PhysicsComponent* pC=boost::polymorphic_downcast<PhysicsComponent*>(components.at(Level::CompKey(EID, "Physics")));;
		pC->ay+=gC->g;
	}
}

void GravitySystem::addEntity(int EID)
{
	assert( components.find(Level::CompKey(EID, "Physics")) != components.end() &&
			components.find(Level::CompKey(EID, "Gravity")) != components.end() );
    entities.push_back(EID);
}