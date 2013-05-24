/* 
 * File:   PhysicsComponent.hpp
 * Author: marzena
 *
 * Created on 19 luty 2013, 22:38
 */

#ifndef PHYSICSCOMPONENT_HPP
#define	PHYSICSCOMPONENT_HPP

#include "Components/Component.hpp"
#include "rapidxml/rapidxml.hpp"

struct PhysicsComponent : public Component
{
	PhysicsComponent(int EID, double acceleration, double maxSpeed, double stoppingSpeed);
	PhysicsComponent(rapidxml::xml_node<>* componentNode);
    
	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);
	
	double vx, vy, vz;
	double ax, ay, az;
	
	double acceleration;
	double maxSpeed;
	double stoppingSpeed;
};

#endif	/* PHYSICSCOMPONENT_HPP */

