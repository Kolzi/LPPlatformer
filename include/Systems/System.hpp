/* 
 * File:   System.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 19:51
 */

#ifndef SYSTEM_HPP
#define	SYSTEM_HPP

#include <list>

class System
{
public:
    System();
    System(const System& orig);
    virtual ~System();
    void removeEntity(int EID);
	virtual void addEntity(int EID)=0;
protected:
    std::list<int> entities;
};

#endif	/* SYSTEM_HPP */

