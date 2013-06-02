/* 
 * File:   ParticleSystem.cpp
 * Author: kolzi
 * 
 * Created on 2 czerwiec 2013, 17:15
 */

#include "Systems/ParticleSystem.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/ParticleComponent.hpp"
#include "Components/PhysicsComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "General/ImageManager.hpp"

#include <assert.h>
#include <boost/cast.hpp>


ParticleSystem::ParticleSystem(	Level::CompMap& components, Level& level)
:System(components), level(level)
{
    
}

ParticleSystem::ParticleSystem(const ParticleSystem& orig)
:System(orig), level(level)
{
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::update(sf::Time deltaTime)
{
    for(auto it=entities.begin();it!=entities.end();it++)
    {
        PositionComponent& posC=*boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(*it, "Position")));
        ParticleComponent& parC=*boost::polymorphic_downcast<ParticleComponent*>(components.at(Level::CompKey(*it, "Particle")));
        int particlesToEmit=deltaTime.asSeconds()*(parC.minParticlesPerSec + rand()%(parC.maxParticlesPerSec-parC.minParticlesPerSec));
		particlesToEmit=1;
		for(int i=0;i<particlesToEmit;i++)
		{
			int newEID=level.getNextID();
			level.addComponent(newEID, "Position", posC.clone(newEID));
			
			//FIXME: speed must be relative to particle emiter speed
			
			PhysicsComponent* partPhysComp=new PhysicsComponent(newEID, 0,parC.maxV,0);
			double ratio = double(rand())/double(RAND_MAX);
			double angle = parC.minAngle + ratio*(parC.maxAngle-parC.minAngle);
			ratio = double(rand())/double(RAND_MAX);
			double v = parC.minV+ratio*(parC.maxV-parC.minV);
			partPhysComp->vx = cos(angle/180.0*M_PI)*v;
			partPhysComp->vy = sin(angle/180.0*M_PI)*v;
			level.addComponent(newEID, "Physics", partPhysComp);
			
			SpriteComponent* sprComp = new SpriteComponent(ImageManager::getSprite(parC.particleImage), newEID);
			level.addComponent(newEID, "Sprite", sprComp);
			
			level.addEntityToSystem(newEID, "Movement");
			level.addEntityToSystem(newEID, "Render");
			std::cerr<<"Added particle\n";
		}
	}
	std::cerr<<"Particle system end\n";
}

void ParticleSystem::addEntity(int EID)
{
	assert( components.find(Level::CompKey(EID, "Position")) != components.end() &&
			components.find(Level::CompKey(EID, "Particle")) != components.end() );
    entities.push_back(EID);
}

