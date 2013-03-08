/* 
 * File:   GravitySystem.hpp
 * Author: marzena
 *
 * Created on 21 luty 2013, 16:44
 */

#ifndef GRAVITYSYSTEM_HPP
#define	GRAVITYSYSTEM_HPP

#include <unordered_map>

#include "Systems/System.hpp"
#include "Components/PhysicsComponent.hpp"
#include "Components/GravityComponent.hpp"

class GravitySystem : System
{
public:
	GravitySystem(std::unordered_map<int,PhysicsComponent>& physicsComponents,
					std::unordered_map<int,GravityComponent>& gravityComponents);
	GravitySystem(const GravitySystem& orig);
	virtual ~GravitySystem();
	void apply();
    void addEntity(int EID);
private:
	std::unordered_map<int,PhysicsComponent>& physicsComponents;
	std::unordered_map<int,GravityComponent>& gravityComponents;
};

#endif	/* GRAVITYSYSTEM_HPP */

