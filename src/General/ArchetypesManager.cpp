/* 
 * File:   ArchetypesManager.cpp
 * Author: kolzi
 * 
 * Created on 19 kwiecień 2013, 17:35
 */

#include "General/Archetype.h"
#include "General/ArchetypesManager.h"
#include "rapidxml/rapidxml.hpp"
#include <vector>

ArchetypesManager::ArchetypesManager()
{
}

ArchetypesManager::ArchetypesManager(const ArchetypesManager& orig)
{
}

ArchetypesManager::~ArchetypesManager()
{
}

void ArchetypesManager::read(std::istream& str)
{
    rapidxml::xml_document<> doc;

    std::vector<char> buffer((std::istreambuf_iterator<char>(str)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    for (rapidxml::xml_node<> * archetypeNode = doc.first_node("Archetype"); archetypeNode; archetypeNode = archetypeNode->next_sibling("Archetype"))
    {
        archetypes[archetypeNode->first_attribute("name")->value()]=new Archetype(archetypeNode);
    }
}