/* 
 * File:   Archetype.cpp
 * Author: kolzi
 * 
 * Created on 19 kwiecień 2013, 16:56
 */

#include <list>
#include <iostream>

#include "General/Archetype.h"
#include "Components/Component.hpp"
#include "General/StringComponentConverter.h"


Archetype::Archetype(rapidxml::xml_node<>* archetypeNode)
{
    read(archetypeNode);
}

Archetype::Archetype(const Archetype& orig)
{
}

Archetype::~Archetype()
{
}

void Archetype::read(rapidxml::xml_node<>* archetypeNode)
{
	if(archetypeNode->first_node("Components")!=0)
	{
		for (rapidxml::xml_node<> * componentNode = 
				archetypeNode->first_node("Components")->first_node(); 
				componentNode; componentNode = componentNode->next_sibling())
		{
			std::cerr<<componentNode->name()<<"\n";
			StringComponentConverter conv;
			components.push_back(std::pair<std::string, Component*>(componentNode->name(), conv.stringToComponent(componentNode->name(), componentNode)));
		}
	}
	if(archetypeNode->first_node("Systems")!=0)
	{
		for (rapidxml::xml_node<> * systemNode = 
				archetypeNode->first_node("Systems")->first_node(); 
				systemNode; systemNode = systemNode->next_sibling())
		{
			std::cerr<<systemNode->name()<<"\n";
			systems.push_back(systemNode->name());
		}
	}
}