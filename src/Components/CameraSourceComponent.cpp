/* 
 * File:   CameraSourceComponent.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 22:38
 */

#include "Components/CameraSourceComponent.hpp"
#include <boost/lexical_cast.hpp>

CameraSourceComponent::CameraSourceComponent(float offsetX, float offsetY, float offsetZ, 
						float sourceWidth, float sourceHeight,  int EID)
:Component(EID),offsetX(offsetX), offsetY(offsetY), offsetZ(offsetZ), 
	sourceHeight(sourceHeight), sourceWidth(sourceWidth) 
{}

CameraSourceComponent::CameraSourceComponent(rapidxml::xml_node<>* componentNode)
:Component(-1)
{
	read(componentNode);
}

void CameraSourceComponent::read(rapidxml::xml_node<>* componentNode)
{
	offsetX=boost::lexical_cast<float>(componentNode->first_attribute("offsetX"));
	offsetY=boost::lexical_cast<float>(componentNode->first_attribute("offsetY"));
	offsetZ=boost::lexical_cast<double>(componentNode->first_attribute("offsetZ"));
	sourceWidth=boost::lexical_cast<float>(componentNode->first_attribute("w"));
	sourceHeight=boost::lexical_cast<float>(componentNode->first_attribute("h"));
	
}

Component* CameraSourceComponent::clone()
{
	return new CameraSourceComponent(*this);
}