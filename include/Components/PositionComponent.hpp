/* 
 * File:   PositionComponent.hpp
 * Author: marzena
 *
 * Created on 17 luty 2013, 22:51
 */

#ifndef POSITIONCOMPONENT_HPP
#define	POSITIONCOMPONENT_HPP

#include "Components/Component.hpp"

class PositionComponent : Component
{
public:
    PositionComponent(double x, double y, double z, int EID);
    PositionComponent(const PositionComponent& orig);
    virtual ~PositionComponent();



    double x, y, z;
    int EID;
};

#endif	/* POSITIONCOMPONENT_HPP */

