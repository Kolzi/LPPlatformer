/* 
 * File:   PhysicsComponent.cpp
 * Author: marzena
 * 
 * Created on 19 luty 2013, 22:38
 */

#include "Components/PhysicsComponent.hpp"

PhysicsComponent::PhysicsComponent(int EID)
:Component(EID),vx(0), vy(0), vz(0), ax(0), ay(0), az(0)
{
}