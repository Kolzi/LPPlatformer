/* 
 * File:   PositionComponent.cpp
 * Author: marzena
 * 
 * Created on 17 luty 2013, 22:51
 */

#include "Components/PositionComponent.hpp"

PositionComponent::PositionComponent(double x, double y, double z, int EID) 
:Component(EID),x(x),y(y),z(z)
{
    
}

PositionComponent::PositionComponent(const PositionComponent& orig) 
:Component(orig.EID),x(orig.x),y(orig.y),z(orig.z)
{
}

PositionComponent::~PositionComponent() {
}

