/* 
 * File:   PlayerInputSystem.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 21:19
 */

#ifndef PLAYERINPUTSYSTEM_HPP
#define	PLAYERINPUTSYSTEM_HPP

#include "Systems/System.hpp"
#include "SFML/System.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/PhysicsComponent.hpp"

#include <unordered_map>

class PlayerInputSystem : System
{
public:
    PlayerInputSystem(	const sf::Input& input,
						std::unordered_map<int,PositionComponent>& positionComponents,
						std::unordered_map<int,PhysicsComponent>& physicsComponents);
    PlayerInputSystem(const PlayerInputSystem& orig);
    virtual ~PlayerInputSystem();
	void handleInput();
    void addEntity(int entity);
private:
	const sf::Input& input;
	std::unordered_map<int,PositionComponent>& positionComponents;
	std::unordered_map<int,PhysicsComponent>& physicsComponents;
};

#endif	/* PLAYERINPUTSYSTEM_HPP */

