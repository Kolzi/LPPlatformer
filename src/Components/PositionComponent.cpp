/* 
 * File:   PositionComponent.cpp
 * Author: marzena
 * 
 * Created on 17 luty 2013, 22:51
 */

#include "Components/PositionComponent.hpp"

#include <boost/lexical_cast.hpp>

PositionComponent::PositionComponent(double x, double y, double z, int EID) 
:Component(EID),x(x),y(y),z(z)
{
    
}

PositionComponent::PositionComponent(const PositionComponent& orig) 
:Component(orig.EID),x(orig.x),y(orig.y),z(orig.z)
{
}

PositionComponent::~PositionComponent() {
}

PositionComponent::PositionComponent(rapidxml::xml_node<>* componentNode)
:Component(-1)
{
	read(componentNode);
}

void PositionComponent::read(rapidxml::xml_node<>* componentNode)
{
	x=y=z=0;
	if(componentNode->first_attribute("x")!=0)
		x=boost::lexical_cast<double>(componentNode->first_attribute("x")->value());
	if(componentNode->first_attribute("y")!=0)
		y=boost::lexical_cast<double>(componentNode->first_attribute("y")->value());
	if(componentNode->first_attribute("z")!=0)
		z=boost::lexical_cast<double>(componentNode->first_attribute("z")->value());
}

Component* PositionComponent::clone()
{
	return new PositionComponent(*this);
}