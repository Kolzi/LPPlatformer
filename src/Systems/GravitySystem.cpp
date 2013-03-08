/* 
 * File:   GravitySystem.cpp
 * Author: marzena
 * 
 * Created on 21 luty 2013, 16:44
 */

#include <assert.h>

#include "Systems/GravitySystem.hpp"
#include "Systems/System.hpp"
#include "Components/GravityComponent.hpp"
#include "Systems/GravitySystem.hpp"

GravitySystem::GravitySystem(std::unordered_map<int,PhysicsComponent>& physicsComponents,
					std::unordered_map<int,GravityComponent>& gravityComponents)
:physicsComponents(physicsComponents), gravityComponents(gravityComponents)
{
}

GravitySystem::GravitySystem(const GravitySystem& orig)
:physicsComponents(orig.physicsComponents), gravityComponents(orig.gravityComponents)
{
}

GravitySystem::~GravitySystem()
{
}

void GravitySystem::apply()
{
	for(int EID : entities)
	{
		GravityComponent& gC= gravityComponents.at(EID);
		PhysicsComponent& pC=physicsComponents.at(EID);
		pC.ay+=gC.g;
	}
}

void GravitySystem::addEntity(int EID)
{
	assert( physicsComponents.find(EID) != physicsComponents.end() &&
			gravityComponents.find(EID) != gravityComponents.end() );
    entities.push_back(EID);
}