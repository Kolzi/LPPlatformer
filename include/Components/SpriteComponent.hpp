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

class SpriteComponent : Component
{
public:
    SpriteComponent(sf::Sprite sprite, int EID);
    SpriteComponent(const SpriteComponent& orig);
    virtual ~SpriteComponent();

    sf::Sprite getSprite() const
    {
        return sprite;
    }

    void setSprite(sf::Sprite sprite)
    {
        this->sprite = sprite;
    }

    sf::Sprite sprite;
};

#endif	/* SPRITECOMPONENT_HPP */

