/* 
 * File:   GravityComponent.cpp
 * Author: marzena
 * 
 * Created on 21 luty 2013, 16:40
 */

#include "Components/GravityComponent.hpp"

GravityComponent::GravityComponent(int EID)
:Component(EID), g(500)
{
}

GravityComponent::GravityComponent(int EID, double g)
:Component(EID), g(g)
{
}