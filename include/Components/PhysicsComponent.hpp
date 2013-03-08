/* 
 * File:   PhysicsComponent.hpp
 * Author: marzena
 *
 * Created on 19 luty 2013, 22:38
 */

#ifndef PHYSICSCOMPONENT_HPP
#define	PHYSICSCOMPONENT_HPP

#include "Components/Component.hpp"

struct PhysicsComponent : Component
{
	PhysicsComponent(int EID);
	
	double vx, vy, vz;
	double ax, ay, az;
};

#endif	/* PHYSICSCOMPONENT_HPP */

