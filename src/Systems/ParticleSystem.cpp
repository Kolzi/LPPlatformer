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
#include "Components/GravityComponent.hpp"
#include "Components/ScoreComponent.hpp"
#include "Components/PositionRelativeToComponent.hpp"

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
		double timePerParticle=1.0/double(parC.minParticlesPerSec + rand()%(parC.maxParticlesPerSec-parC.minParticlesPerSec));
		
		int particlesToEmit=0;
		parC.timeSinceLastParticle+=deltaTime.asSeconds();
		while(parC.timeSinceLastParticle>timePerParticle)
		{
			particlesToEmit++;
			parC.timeSinceLastParticle-=timePerParticle;
		}
		
		for(int i=0;i<particlesToEmit;i++)
		{			
			//FIXME: speed must be relative to particle emiter speed
			int newID=level.addArchetype(parC.emitsArchetype);
			
			double ratio = double(rand())/double(RAND_MAX);
			double angle = parC.minAngle + ratio*(parC.maxAngle-parC.minAngle);
			ratio = double(rand())/double(RAND_MAX);
			double v = parC.minV+ratio*(parC.maxV-parC.minV);
			PhysicsComponent& partPhysComp=*boost::polymorphic_downcast<PhysicsComponent*>(components.at(Level::CompKey(newID, "Physics")));
			partPhysComp.vx = cos(angle/180.0*M_PI)*v;
			partPhysComp.vy = sin(angle/180.0*M_PI)*v;
			
			PositionComponent& partPosComp=*boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(newID, "Position")));
			partPosComp.x=posC.x;
			partPosComp.y=posC.y;
			if(components.find(Level::CompKey(*it, "PositionRelativeTo"))!=components.end())
			{
				PositionRelativeToComponent& prtC=*boost::polymorphic_downcast<PositionRelativeToComponent*>(components.at(Level::CompKey(*it, "PositionRelativeTo")));
				PositionComponent& ppC =*boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(prtC.relativeTo, "Position")));
				partPosComp.x+=ppC.x;
				partPosComp.y+=ppC.y;
			}
			
			
			if(components.find(Level::CompKey(newID, "Gravity"))!=components.end())
			{
				GravityComponent& partGravComp=*boost::polymorphic_downcast<GravityComponent*>(components.at(Level::CompKey(newID, "Gravity")));
				ratio = double(rand())/double(RAND_MAX);
				partGravComp.g=parC.minGravity + ratio*(parC.maxGravity-parC.minGravity);
			}
			
			if(components.find(Level::CompKey(newID, "Score"))!=components.end())
			{
				ScoreComponent& partScoreComp=*boost::polymorphic_downcast<ScoreComponent*>(components.at(Level::CompKey(newID, "Score")));
				ratio = double(rand())/double(RAND_MAX);
				partScoreComp.score=parC.minLifeTime + ratio*(parC.maxLifeTime-parC.minLifeTime);
			}			
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
