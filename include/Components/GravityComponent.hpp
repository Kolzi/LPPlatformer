/* 
 * File:   GravityComponent.hpp
 * Author: marzena
 *
 * Created on 21 luty 2013, 16:40
 */

#ifndef GRAVITYCOMPONENT_HPP
#define	GRAVITYCOMPONENT_HPP

#include <Components/Component.hpp>
#include "rapidxml/rapidxml.hpp"

struct GravityComponent : public Component
{
public:
	GravityComponent(int EID);
	GravityComponent(int EID, double g);
    GravityComponent(rapidxml::xml_node<>* componentNode);
	
	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);
	
	static constexpr double defaultG=500;
	double g;
};

#endif	/* GRAVITYCOMPONENT_HPP */

