/* 
 * File:   NoSuchComponentName.hpp
 * Author: kolzi
 *
 * Created on 19 kwiecień 2013, 20:37
 */

#ifndef NOSUCHCOMPONENTNAME_HPP
#define	NOSUCHCOMPONENTNAME_HPP

#include <exception>

class NoSuchComponentName :public std::exception
{
	std::string name;
public:
	const char* what(){return ("No such component name: "+name).c_str();}
	NoSuchComponentName(std::string name):name(name){}
};

#endif	/* NOSUCHCOMPONENTNAME_HPP */

