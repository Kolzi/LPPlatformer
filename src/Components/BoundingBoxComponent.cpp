/* 
 * File:   BoundingBoxComponent.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 22:20
 */

#include "Components/BoundingBoxComponent.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

#include <boost/lexical_cast.hpp>

BoundingBoxComponent::BoundingBoxComponent(sf::Rect<double> boundingBox, int EID)
:Component(EID), boundingBox(boundingBox)
{
}

BoundingBoxComponent::BoundingBoxComponent(rapidxml::xml_node<>* componentNode)
:Component(-1)
{
	read(componentNode);
}

void BoundingBoxComponent::read(rapidxml::xml_node<>* componentNode)
{
	boundingBox.left=0;
	boundingBox.top=0;
	if(componentNode->first_attribute("x")!=0)
		boundingBox.left=boost::lexical_cast<double>(componentNode->first_attribute("x")->value());
	if(componentNode->first_attribute("y")!=0)
		boundingBox.top=boost::lexical_cast<double>(componentNode->first_attribute("y")->value());
	if(componentNode->first_attribute("w")!=0)
		boundingBox.width=boost::lexical_cast<double>(componentNode->first_attribute("w")->value());
	else
		throw RequiredAttributeNotFound("w", "BoundingBox");
	if(componentNode->first_attribute("h")!=0)
		boundingBox.width=boost::lexical_cast<double>(componentNode->first_attribute("h")->value());
	else
		throw RequiredAttributeNotFound("h", "BoundingBox");
}

Component* BoundingBoxComponent::clone()
{
	return new BoundingBoxComponent(*this);
}
