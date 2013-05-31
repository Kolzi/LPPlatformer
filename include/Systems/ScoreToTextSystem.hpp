/* 
 * File:   ScoreToTextSystem.hpp
 * Author: kolzi
 *
 * Created on 31 maj 2013, 16:16
 */

#ifndef SCORETOTEXTSYSTEM_HPP
#define	SCORETOTEXTSYSTEM_HPP

#include <unordered_map>

#include "Systems/System.hpp"
#include "Components/PhysicsComponent.hpp"
#include "Components/GravityComponent.hpp"

class ScoreToTextSystem : public System
{
public:
	ScoreToTextSystem(Level::CompMap& components);
	ScoreToTextSystem(const ScoreToTextSystem& orig);
	virtual ~ScoreToTextSystem();
	void update(sf::Time deltaTime);
    void addEntity(int EID);
};

#endif	/* SCORETOTEXTSYSTEM_HPP */

