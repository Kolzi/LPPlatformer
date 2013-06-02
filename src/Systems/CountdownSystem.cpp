/* 
 * File:   CountdownSystem.cpp
 * Author: kolzi
 * 
 * Created on 2 czerwiec 2013, 21:34
 */

#include <assert.h>
#include <boost/cast.hpp>

#include "Systems/CountdownSystem.hpp"
#include "Components/ScoreComponent.hpp"


CountdownSystem::CountdownSystem(Level::CompMap& components, Level& level)
:System(components), level(level)
{
    
}

CountdownSystem::CountdownSystem(const CountdownSystem& orig)
:System(orig), level(level)
{
	
}

CountdownSystem::~CountdownSystem()
{
}

void CountdownSystem::update(sf::Time deltaTime)
{
	std::list<int> toRemove;
    for(auto it=entities.begin();it!=entities.end();it++)
    {
        ScoreComponent& scoreC=*boost::polymorphic_downcast<ScoreComponent*>(components.at(Level::CompKey(*it, "Score")));
		scoreC.score-=deltaTime.asSeconds();
		if(scoreC.score<=0)
		{
			toRemove.push_back(*it);
		}
	}
	for(int id:toRemove)
	{
		level.removeEntity(id);
	}
}

void CountdownSystem::addEntity(int EID)
{
	assert( components.find(Level::CompKey(EID, "Score")) != components.end() );
    entities.push_back(EID);
}

