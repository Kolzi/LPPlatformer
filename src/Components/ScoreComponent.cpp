/* 
// * File:   ScoreComponent.cpp
 * Author: kolzi
 * 
 * Created on 28 maj 2013, 03:39
 */

#include "Components/ScoreComponent.hpp"

#include <boost/lexical_cast.hpp>


const double ScoreComponent::defaultScore=100000;

ScoreComponent::ScoreComponent(int EID)
:Component(EID), score(defaultScore)
{
}

ScoreComponent::ScoreComponent(int EID, double score)
:Component(EID), score(score)
{
}

ScoreComponent::ScoreComponent(rapidxml::xml_node<>* componentNode)
:ScoreComponent(-1)
{
	read(componentNode);
}

void ScoreComponent::read(rapidxml::xml_node<>* componentNode)
{
	if(componentNode->first_attribute("score")!=0)
		score=boost::lexical_cast<double>(componentNode->first_attribute("score")->value());
}

Component* ScoreComponent::clone(int newEID)
{
	Component* comp= new ScoreComponent(*this);
	comp->EID=newEID;
	return comp;
}
