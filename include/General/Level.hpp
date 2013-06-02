/* 
 * File:   Level.hpp
 * Author: kolzi
 *
 * Created on 24 kwiecień 2013, 22:13
 */

#ifndef LEVEL_HPP
#define	LEVEL_HPP

#include <unordered_map>
#include <list>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>

#include "TechnicalShit/PairIntStringHash.hpp"
#include "SimpleIDGenerator.hpp"

class Component;
class System;
class ArchetypesManager;

class Level
{
public:
	typedef std::pair<int, std::string> CompKey;
	typedef std::unordered_map <CompKey, Component*, PairIntStringHash> CompMap;
	typedef std::unordered_map <std::string, System*> SysMap;
	
	Level(sf::RenderWindow& app, ArchetypesManager& archetypesManager);
	Level(const Level& orig);
	virtual ~Level();
	
	int getNextID();
	void addComponent(int EID, std::string compName, Component* comp);
	void addEntityToSystem(int EID, std::string system);
	void read(std::istream& str);
	void update(sf::Time deltaTime);
	//returns new entity ID
	int addArchetype(std::string archetype);
	void removeEntity(int EID);
private:
	sf::RenderWindow& app;
	ArchetypesManager& archetypesManager;
	std::unique_ptr<IDGenerator> idGenerator;
	std::list <System*> systems;
	std::unordered_map <std::string, System*> systemsMap;
	CompMap components;
};

#endif	/* LEVEL_HPP */

