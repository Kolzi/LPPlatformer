/* 
 * File:   PhysicsSystem.hpp
 * Author: marzena
 *
 * Created on 19 luty 2013, 22:44
 */

#ifndef PHYSICSSYSTEM_HPP
#define	PHYSICSSYSTEM_HPP

#include "Systems/System.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/PhysicsComponent.hpp"

#include <SFML/System/Time.hpp>
#include <unordered_map>

class MovementSystem : System
{
public:
	MovementSystem(	std::unordered_map<int,PositionComponent>& positionComponents,
					std::unordered_map<int,PhysicsComponent>& physicsComponents);
	MovementSystem(const MovementSystem& orig);
	virtual ~MovementSystem();
	void move(sf::Time time);
    void addEntity(int entity);
private:
	std::unordered_map<int,PositionComponent>& positionComponents;
	std::unordered_map<int,PhysicsComponent>& physicsComponents;
};

#endif	/* PHYSICSSYSTEM_HPP */

