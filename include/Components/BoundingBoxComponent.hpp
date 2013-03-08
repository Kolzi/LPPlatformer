/* 
 * File:   BoundingBoxComponent.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 22:20
 */

#ifndef BOUNDINGBOXCOMPONENT_HPP
#define	BOUNDINGBOXCOMPONENT_HPP

#include "Component.hpp"
#include "SFML/Graphics/Rect.hpp"

struct BoundingBoxComponent : Component
{
	BoundingBoxComponent(sf::Rect<double> boundingBox, int EID);
	sf::Rect<double> boundingBox;
};

#endif	/* BOUNDINGBOXCOMPONENT_HPP */

