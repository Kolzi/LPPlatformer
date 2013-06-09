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
#include "Components/CountdownComponent.hpp"
#include "Exceptions/NoSuchSystem.hpp"


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
	sf::Clock timer;
	std::list<int> toRemove;
	std::list<std::pair<int, std::string> > toRemoveFromSystems;
	std::list<std::pair<int, std::string> > componentsToRemove;
	
    for(auto it=entities.begin();it!=entities.end();it++)
    {
        CountdownComponent& countC=*boost::polymorphic_downcast<CountdownComponent*>(components.at(Level::CompKey(*it, "Countdown")));
		countC.timeLeft-=deltaTime.asSeconds();
		while(!countC.actions.empty() && countC.timeLeft<=countC.actions.top().time)
		{
			if(countC.actions.top().name=="Remove")
			{
				countC.actions.pop();
				toRemove.push_back(*it);
			}
			else if(countC.actions.top().name=="AddToSystem")
			{
				level.addEntityToSystem(*it, countC.actions.top().target);
				countC.actions.pop();
			}
			else if(countC.actions.top().name=="RemoveFromSystem")
			{
				toRemoveFromSystems.push_back(std::make_pair(*it, countC.actions.top().target));				
				countC.actions.pop();
			}
			else if(countC.actions.top().name=="RemoveComponent")
			{
				componentsToRemove.push_back(std::make_pair(*it, countC.actions.top().target));
				countC.actions.pop();
			}
		}
		
		if(countC.timeLeft<=0 && countC.restart)
		{
			countC.timeLeft=countC.startTime;
			countC.actions=countC.startActions;
		}			
	}
	for(auto p:toRemoveFromSystems)
	{
		level.removeEntityFromSystem(p.first, p.second);
	}
	for(auto p:componentsToRemove)
	{
		level.removeComponent(p.first, p.second);
	}
	for(int id:toRemove)
	{
		level.removeEntity(id);
	}
	std::cerr<<"Countdown system: "<<timer.getElapsedTime().asMilliseconds()<<"\n";
}

void CountdownSystem::addEntity(int EID)
{
	assert( components.find(Level::CompKey(EID, "Countdown")) != components.end() );
    entities.insert(EID);
}

