/* 
 * File:   StringComponentConverter.h
 * Author: kolzi
 *
 * Created on 19 kwiecień 2013, 18:55
 */

#ifndef STRINGCOMPONENTCONVERTER_H
#define	STRINGCOMPONENTCONVERTER_H

#include <string>
#include "rapidxml/rapidxml.hpp"

class StringComponentConverter
{
public:
    static Component* stringToComponent(std::string componentName, rapidxml::xml_node<>* archetypeNode);

};

#endif	/* STRINGCOMPONENTCONVERTER_H */

