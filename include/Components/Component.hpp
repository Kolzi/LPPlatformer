/* 
 * File:   Component.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 19:49
 */

#ifndef COMPONENT_HPP
#define	COMPONENT_HPP

#include <list>
#include <Systems/System.hpp>

class Component
{
public:
    Component(int EID);
    Component(const Component& orig);
    virtual ~Component();
 //   std::list<System&> attachedTo;
	int EID;
private:

};

#endif	/* COMPONENT_HPP */

