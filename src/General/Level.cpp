/* 
 * File:   Level.cpp
 * Author: kolzi
 * 
 * Created on 24 kwiecień 2013, 22:13
 */

#include <vector>
#include <istream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "rapidxml/rapidxml.hpp"

#include "Components/Component.hpp"
#include "General/ArchetypesManager.h"
#include "General/Level.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/CameraSystem.hpp"
#include "Systems/CollisionSystem.hpp"
#include "Systems/GravitySystem.hpp"
#include "Systems/MovementSystem.hpp"
#include "Systems/PlayerInputSystem.hpp"

Level::Level(sf::RenderWindow& app, ArchetypesManager& archetypesManager)
:app(app), archetypesManager(archetypesManager), idGenerator(new SimpleIDGenerator())
{
	systemsMap.insert(std::pair<std::string, System*>("PlayerInput", new PlayerInputSystem(components)));
	systems.push_back(systemsMap.at("PlayerInput"));
	
	systemsMap.insert(std::pair<std::string, System*>("Gravity", new GravitySystem(components)));
	systems.push_back(systemsMap.at("Gravity"));
	
	systemsMap.insert(std::pair<std::string, System*>("Movement", new MovementSystem(components)));
	systems.push_back(systemsMap.at("Movement"));
	
	systemsMap.insert(std::pair<std::string, System*>("Collision", new CollisionSystem(components)));
	systems.push_back(systemsMap.at("Collision"));
	
	systemsMap.insert(std::pair<std::string, System*>("Camera", new CameraSystem(app, components)));
	systems.push_back(systemsMap.at("Camera"));
	
	systemsMap.insert(std::pair<std::string, System*>("Render", new RenderSystem(app, components)));
	systems.push_back(systemsMap.at("Render"));
	
	
	
}

Level::Level(const Level& orig)
:app(app),archetypesManager(orig.archetypesManager), idGenerator(orig.idGenerator), 
		systems(orig.systems),systemsMap(orig.systemsMap), components(orig.components)
{
}

Level::~Level()
{
}

void Level::read(std::istream& str)
{
    rapidxml::xml_document<> doc;

    std::vector<char> buffer((std::istreambuf_iterator<char>(str)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    for (rapidxml::xml_node<> * objectNode = doc.first_node("Object"); objectNode; objectNode = objectNode->next_sibling("Object"))
    {
		int EID=idGenerator->nextID();
        archetypesManager.addEntity(EID, objectNode->name(), components, systemsMap);
		for(rapidxml::xml_node<> * componentNode = objectNode->first_node(); componentNode; componentNode = componentNode->next_sibling())
		{
			components[CompKey(EID,componentNode->name())]->read(componentNode);
		}
    }
}

void Level::update(sf::Time deltaTime)
{
	for(auto system:systems)
	{
		system->update(deltaTime);
	}
}