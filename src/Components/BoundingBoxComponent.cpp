/* 
 * File:   BoundingBoxComponent.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 22:20
 */

#include "Components/BoundingBoxComponent.hpp"

BoundingBoxComponent::BoundingBoxComponent(sf::Rect<double> boundingBox, int EID)
:Component(EID), boundingBox(boundingBox)
{
}

