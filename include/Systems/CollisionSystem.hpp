/* 
 * File:   CollisionSystem.hpp
 * Author: marzena
 *
 * Created on 20 luty 2013, 00:06
 */

#ifndef COLLISIONSYSTEM_HPP
#define	COLLISIONSYSTEM_HPP

#include "Components/PositionComponent.hpp"
#include "Components/BoundingBoxComponent.hpp"
#include "Components/PhysicsComponent.hpp"
#include "Systems/System.hpp"
#include <unordered_map>

class CollisionSystem : System
{
public:
	CollisionSystem(std::unordered_map<int,PositionComponent>& positionComponents,
		std::unordered_map<int,PhysicsComponent>& physicsComponents,
		std::unordered_map<int,BoundingBoxComponent>& boundingBoxComponents);
	CollisionSystem(const CollisionSystem& orig);
	virtual ~CollisionSystem();
	void addEntity(int EID);
	void detectCollisions();
private:
	std::unordered_map<int,PositionComponent>& positionComponents;
	std::unordered_map<int,PhysicsComponent>& physicsComponents;
	std::unordered_map<int,BoundingBoxComponent>& boundingBoxComponents;	
};

#endif	/* COLLISIONSYSTEM_HPP */

