/* 
 * File:   ViewportComponent.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 22:28
 */

#ifndef VIEWPORTCOMPONENT_HPP
#define	VIEWPORTCOMPONENT_HPP

#include "Components/Component.hpp"
#include <SFML/Graphics/Rect.hpp>

struct ViewportComponent : Component
{
	ViewportComponent(int x1, int y1, int x2, int y2, int EID);
	ViewportComponent(const sf::Rect<int>& rectangle, int EID);
	sf::Rect<int> destination;
};

#endif	/* VIEWPORTCOMPONENT_HPP */

