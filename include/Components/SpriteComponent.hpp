/* 
 * File:   SpriteComponent.hpp
 * Author: marzena
 *
 * Created on 17 luty 2013, 23:24
 */

#ifndef SPRITECOMPONENT_HPP
#define	SPRITECOMPONENT_HPP

#include <SFML/Graphics.hpp>
#include "Components/Component.hpp"
#include "rapidxml/rapidxml.hpp"

struct SpriteComponent : public Component
{
    SpriteComponent(sf::Sprite sprite, int EID);
    SpriteComponent(const SpriteComponent& orig);
    SpriteComponent(rapidxml::xml_node<>* componentNode);
    virtual ~SpriteComponent();
	
	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);
    sf::Sprite sprite;
};

#endif	/* SPRITECOMPONENT_HPP */

