/* 
 * File:   ArchetypesManager.h
 * Author: kolzi
 *
 * Created on 19 kwiecień 2013, 17:35
 */

#ifndef ARCHETYPESMANAGER_H
#define	ARCHETYPESMANAGER_H

#include <istream>
#include <unordered_map>

class Archetype;

class ArchetypesManager
{
public:
    ArchetypesManager();
    ArchetypesManager(const ArchetypesManager& orig);
    virtual ~ArchetypesManager();
    void read(std::istream& str);
private:
    std::unordered_map<std::string, Archetype*> archetypes;
};

#endif	/* ARCHETYPESMANAGER_H */

