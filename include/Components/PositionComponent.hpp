/* 
 * File:   PositionComponent.hpp
 * Author: marzena
 *
 * Created on 17 luty 2013, 22:51
 */

#ifndef POSITIONCOMPONENT_HPP
#define	POSITIONCOMPONENT_HPP

#include "Components/Component.hpp"
#include "rapidxml/rapidxml.hpp"

class PositionComponent : public Component
{
public:
    PositionComponent(double x, double y, double z, int EID);
    PositionComponent(const PositionComponent& orig);
    PositionComponent(rapidxml::xml_node<>* componentNode);
    virtual ~PositionComponent();

	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);
	
    double x, y, z;
    int EID;
};

#endif	/* POSITIONCOMPONENT_HPP */

