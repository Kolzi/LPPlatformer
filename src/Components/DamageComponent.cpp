/* 
 * File:   DamageComponent.cpp
 * Author: kolzi
 * 
 * Created on 31 maj 2013, 13:45
 */

#include "Components/DamageComponent.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

#include <boost/lexical_cast.hpp>

const double DamageComponent::defaultDamage = 100000;

DamageComponent::DamageComponent(int EID)
:Component(EID), damagePerSecond(defaultDamage)
{
}

DamageComponent::DamageComponent(int EID, double damagePerSecond)
:Component(EID), damagePerSecond(defaultDamage)
{
}

DamageComponent::DamageComponent(rapidxml::xml_node<>* componentNode)
:DamageComponent(-1)
{
	read(componentNode);
}

void DamageComponent::read(rapidxml::xml_node<>* componentNode)
{
	if(componentNode->first_attribute("damagePerSecond")!=0)
		damagePerSecond=boost::lexical_cast<double>(componentNode->first_attribute("damagePerSecond")->value());
}

Component* DamageComponent::clone(int newEID)
{
	Component* comp= new DamageComponent(*this);
	comp->EID=newEID;
	return comp;
}
