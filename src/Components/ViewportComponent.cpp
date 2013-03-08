/* 
 * File:   ViewportComponent.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 22:28
 */

#include "Components/ViewportComponent.hpp"

ViewportComponent::ViewportComponent(int x1, int y1, int x2, int y2, int EID)
:Component(EID), destination(x1,y1,x2,y2)
{    
}

ViewportComponent::ViewportComponent(const sf::Rect<int>& rectangle, int EID)
:Component(EID), destination(rectangle)
{}
