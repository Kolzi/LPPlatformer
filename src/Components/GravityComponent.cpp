/* 
 * File:   GravityComponent.cpp
 * Author: marzena
 * 
 * Created on 21 luty 2013, 16:40
 */

#include "Components/GravityComponent.hpp"

#include <boost/lexical_cast.hpp>
#include <iostream>

GravityComponent::GravityComponent(int EID)
:Component(EID)
{
	g=defaultG;
}

GravityComponent::GravityComponent(int EID, double g)
:Component(EID), g(g)
{
}

GravityComponent::GravityComponent(rapidxml::xml_node<>* componentNode)
:Component(-1), g(defaultG)
{
	g=defaultG;
	read(componentNode);
}

void GravityComponent::read(rapidxml::xml_node<>* componentNode)
{
	if(componentNode->first_attribute("g")!=0)
		g=boost::lexical_cast<double>(componentNode->first_attribute("g")->value());
}

Component* GravityComponent::clone(int newEID)
{
	Component* comp= new GravityComponent(*this);
	comp->EID=newEID;
	return comp;
}
