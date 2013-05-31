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

class GravitySystem : public System
{
public:
	GravitySystem(Level::CompMap& components);
	GravitySystem(const GravitySystem& orig);
	virtual ~GravitySystem();
	void update(sf::Time deltaTime);
    void addEntity(int EID);
};

#endif	/* GRAVITYSYSTEM_HPP */

