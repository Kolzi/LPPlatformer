/* 
 * File:   RenderSystem.cpp
 * Author: marzena
 * 
 * Created on 17 luty 2013, 23:29
 */

#include "Systems/RenderSystem.hpp"
#include <assert.h>

RenderSystem::RenderSystem(	sf::RenderWindow& window,
							std::unordered_map<int,PositionComponent>& positionComponents,
							std::unordered_map<int,SpriteComponent>& spriteComponents)
:window(window), positionComponents(positionComponents), 
		spriteComponents(spriteComponents)
{
    
}

RenderSystem::RenderSystem(const RenderSystem& orig)
:window(orig.window), positionComponents(orig.positionComponents), 
		spriteComponents(orig.spriteComponents)
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::render()
{
    for(auto it=entities.begin();it!=entities.end();it++)
    {
        PositionComponent& pC=positionComponents.at(*it);
        SpriteComponent& sC=spriteComponents.at(*it);
        sC.sprite.setPosition(pC.x,pC.y);
        window.draw(sC.getSprite());
    }
}

void RenderSystem::addEntity(int EID)
{
//	std::cerr<<(positionComponents.find(EID)!=positionComponents.end())<<" ";
//			std::cerr<<(spriteComponents.find(EID) != spriteComponents.end())<<"\n";
	assert( positionComponents.find(EID) != positionComponents.end() &&
			spriteComponents.find(EID) != spriteComponents.end() );
    entities.push_back(EID);
}