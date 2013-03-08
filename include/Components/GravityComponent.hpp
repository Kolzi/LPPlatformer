/* 
 * File:   GravityComponent.hpp
 * Author: marzena
 *
 * Created on 21 luty 2013, 16:40
 */

#ifndef GRAVITYCOMPONENT_HPP
#define	GRAVITYCOMPONENT_HPP

#include <Components/Component.hpp>

struct GravityComponent : Component
{
public:
	GravityComponent(int EID);
	GravityComponent(int EID, double g);
	double g;
};

#endif	/* GRAVITYCOMPONENT_HPP */

