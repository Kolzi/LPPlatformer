/* 
 * File:   System.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 19:51
 */

#include <list>

#include "Systems/System.hpp"

System::System()
{
}

System::System(const System& orig)
{
}

System::~System()
{
}

void System::removeEntity(int EID)
{
	entities.remove(EID);
}