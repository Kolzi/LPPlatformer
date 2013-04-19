/* 
 * File:   SpriteComponent.cpp
 * Author: marzena
 * 
 * Created on 17 luty 2013, 23:24
 */

#include "Components/SpriteComponent.hpp"

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
	///FIXME: ImageManager!
}

Component* SpriteComponent::clone()
{
	return new SpriteComponent(*this);
}
