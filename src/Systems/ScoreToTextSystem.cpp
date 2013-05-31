/* 
 * File:   ScoreToTextSystem.cpp
 * Author: kolzi
 * 
 * Created on 31 maj 2013, 16:16
 */

#include <assert.h>
#include <boost/lexical_cast.hpp>
#include <boost/cast.hpp>

#include "Systems/ScoreToTextSystem.hpp"
#include "Components/TextComponent.hpp"
#include "Components/ScoreComponent.hpp"

ScoreToTextSystem::ScoreToTextSystem(Level::CompMap& components)
:System(components)
{
}

ScoreToTextSystem::ScoreToTextSystem(const ScoreToTextSystem& orig)
:System(orig)
{
}

ScoreToTextSystem::~ScoreToTextSystem()
{
}

void ScoreToTextSystem::update(sf::Time deltaTime)
{
	for(int EID : entities)
	{
		ScoreComponent* sC=boost::polymorphic_downcast<ScoreComponent*>(components.at(Level::CompKey(EID, "Score")));
		TextComponent* tC=boost::polymorphic_downcast<TextComponent*>(components.at(Level::CompKey(EID, "Text")));;
		tC->text.setString(boost::lexical_cast<std::string> (sC->score));
	}
}

void ScoreToTextSystem::addEntity(int EID)
{
	assert( components.find(Level::CompKey(EID, "Score")) != components.end() &&
			components.find(Level::CompKey(EID, "Text")) != components.end() );
    entities.push_back(EID);
}

