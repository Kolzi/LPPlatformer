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
#include "rapidxml/rapidxml.hpp"

struct BoundingBoxComponent : public Component
{
	BoundingBoxComponent(sf::Rect<double> boundingBox, int EID);
    BoundingBoxComponent(rapidxml::xml_node<>* componentNode);
	Component* clone();
	void read(rapidxml::xml_node<>* componentNode);
	
    sf::Rect<double> boundingBox;
};

#endif	/* BOUNDINGBOXCOMPONENT_HPP */

