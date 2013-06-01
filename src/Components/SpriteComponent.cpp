/* 
 * File:   SpriteComponent.cpp
 * Author: marzena
 * 
 * Created on 17 luty 2013, 23:24
 */

#include <boost/lexical_cast.hpp>

#include "Components/SpriteComponent.hpp"
#include "General/ImageManager.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"
#include "Exceptions/IncorrentFrameWidth.hpp"


SpriteComponent::SpriteComponent(sf::Sprite sprite, int EID)
:Component(EID),sprite(sprite)
{
}

SpriteComponent::SpriteComponent(const SpriteComponent& orig)
:Component(orig.EID),sprite(orig.sprite), loopTime(orig.loopTime), numberOfFrames(orig.numberOfFrames),
		currentFrameTime(orig.currentFrameTime)
{
}

SpriteComponent::~SpriteComponent()
{
}


SpriteComponent::SpriteComponent(rapidxml::xml_node<>* componentNode)
:Component(-1), loopTime(1), numberOfFrames(1), currentFrameTime(0)
{
	read(componentNode);
}

void SpriteComponent::read(rapidxml::xml_node<>* componentNode)
{
	if(componentNode->first_attribute("file")==0)
		throw RequiredAttributeNotFound("file", "SpriteComponent");
	sprite=ImageManager::getSprite(componentNode->first_attribute("file")->value());
	if(componentNode->first_attribute("frameWidth")!=0)
	{
		int frameWidth=boost::lexical_cast<int>(componentNode->first_attribute("frameWidth")->value());
		if(int(sprite.getTexture()->getSize().x) % frameWidth != 0)
			throw IncorrectFrameWidth(componentNode->first_attribute("frameWidth")->value(), "Sprite");
		sprite.setTextureRect(sf::IntRect(0,0,frameWidth, sprite.getTexture()->getSize().y));
		numberOfFrames=sprite.getTexture()->getSize().x/frameWidth;
		std::cerr<<numberOfFrames<<"\n";
	}
	if(componentNode->first_attribute("loopTime")!=0)
	{
		loopTime=boost::lexical_cast<double>(componentNode->first_attribute("loopTime")->value());
	}
	std::cerr<<loopTime<<" "<<numberOfFrames<<" "<<currentFrameTime<<"\n";
}

Component* SpriteComponent::clone(int newEID)
{
	Component* comp= new SpriteComponent(*this);
	comp->EID=newEID;
	return comp;
}
