/* 
 * File:   PhysicsComponent.cpp
 * Author: marzena
 * 
 * Created on 19 luty 2013, 22:38
 */

#include "Components/PhysicsComponent.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

#include <boost/lexical_cast.hpp>

PhysicsComponent::PhysicsComponent(int EID, double acceleration, double maxSpeed, double stoppingSpeed)
:Component(EID),vx(0), vy(0), vz(0), ax(0), ay(0), az(0), acceleration(acceleration),
		maxSpeed(maxSpeed), stoppingSpeed(stoppingSpeed)
{
}

PhysicsComponent::PhysicsComponent(rapidxml::xml_node<>* componentNode)
:Component(-1), vx(0), vy(0), vz(0), ax(0), ay(0), az(0)
{
	read(componentNode);
}

void PhysicsComponent::read(rapidxml::xml_node<>* componentNode)
{
	if(componentNode->first_attribute("vx")!=0)
		vx=boost::lexical_cast<double>(componentNode->first_attribute("vx")->value());
	if(componentNode->first_attribute("vy")!=0)
		vy=boost::lexical_cast<double>(componentNode->first_attribute("vy")->value());
	if(componentNode->first_attribute("vz")!=0)
		vz=boost::lexical_cast<double>(componentNode->first_attribute("vz")->value());
	if(componentNode->first_attribute("ax")!=0)
		ax=boost::lexical_cast<double>(componentNode->first_attribute("ax")->value());
	if(componentNode->first_attribute("ay")!=0)
		ay=boost::lexical_cast<double>(componentNode->first_attribute("ay")->value());
	if(componentNode->first_attribute("az")!=0)
		az=boost::lexical_cast<double>(componentNode->first_attribute("az")->value());
	
	if(componentNode->first_attribute("acceleration")!=0)
		acceleration=boost::lexical_cast<double>(componentNode->first_attribute("acceleration")->value());
	else
		throw RequiredAttributeNotFound("acceleration", "Physics");
	if(componentNode->first_attribute("maxSpeed")!=0)
		maxSpeed=boost::lexical_cast<double>(componentNode->first_attribute("maxSpeed")->value());
	else
		throw RequiredAttributeNotFound("maxSpeed", "Physics");
	if(componentNode->first_attribute("stoppingSpeed")!=0)
		stoppingSpeed=boost::lexical_cast<double>(componentNode->first_attribute("stoppingSpeed")->value());
	else
		throw RequiredAttributeNotFound("stoppingSpeed", "Physics");
}

Component* PhysicsComponent::clone(int newEID)
{
	Component* comp= new PhysicsComponent(*this);
	comp->EID=newEID;
	return comp;
}
