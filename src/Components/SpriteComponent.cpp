/* 
 * File:   SpriteComponent.cpp
 * Author: marzena
 * 
 * Created on 17 luty 2013, 23:24
 */

#include "Components/SpriteComponent.hpp"
#include "General/ImageManager2.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"

SpriteComponent::SpriteComponent(sf::Sprite sprite, int EID)
:Component(EID),sprite(sprite)
{
}

SpriteComponent::SpriteComponent(const SpriteComponent& orig)
:Component(orig.EID),sprite(orig.sprite)
{
}

SpriteComponent::~SpriteComponent()
{
}


SpriteComponent::SpriteComponent(rapidxml::xml_node<>* componentNode)
:Component(-1)
{
	read(componentNode);
}

void SpriteComponent::read(rapidxml::xml_node<>* componentNode)
{
	if(componentNode->first_attribute("file")==0)
		throw RequiredAttributeNotFound("file", "SpriteComponent");
	sprite=ImageManager::getSprite(componentNode->first_attribute("file")->value());
}

Component* SpriteComponent::clone(int newEID)
{
	Component* comp= new SpriteComponent(*this);
	comp->EID=newEID;
	return comp;
}
