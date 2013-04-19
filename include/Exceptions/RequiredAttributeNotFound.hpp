/* 
 * File:   RequiredAttributeNotFound.hpp
 * Author: kolzi
 *
 * Created on 19 kwiecień 2013, 20:33
 */

#ifndef REQUIREDATTRIBUTENOTFOUND_HPP
#define	REQUIREDATTRIBUTENOTFOUND_HPP

#include <exception>

class RequiredAttributeNotFound : public std::exception
{
	std::string name;
	std::string compName;
public:
	const char* what(){return ("Required attribute "+name+" of component "+compName+" not found!").c_str();}
	RequiredAttributeNotFound(std::string name, std::string compName):name(name), compName(compName){}
};

#endif	/* REQUIREDATTRIBUTENOTFOUND_HPP */

