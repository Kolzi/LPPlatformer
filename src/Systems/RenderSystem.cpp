/* 
 * File:   RenderSystem.cpp
 * Author: marzena
 * 
 * Created on 17 luty 2013, 23:29
 */

#include "Systems/RenderSystem.hpp"
#include "Components/PositionRelativeToComponent.hpp"
#include <assert.h>
#include <boost/cast.hpp>


RenderSystem::RenderSystem(	sf::RenderWindow& window,Level::CompMap& components)
:System(components),window(window)
{
    
}

RenderSystem::RenderSystem(const RenderSystem& orig)
:System(orig), window(orig.window)
{
}

RenderSystem::~RenderSystem()
{
}

void RenderSystem::update(sf::Time deltaTime)
{
	std::cerr<<"Render\n";
    for(auto it=entities.begin();it!=entities.end();it++)
    {
        PositionComponent* pC=boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(*it, "Position")));
        SpriteComponent* sC=boost::polymorphic_downcast<SpriteComponent*>(components.at(Level::CompKey(*it, "Sprite")));
        int x=pC->x;
		int y=pC->y;
		if(components.find(Level::CompKey(*it, "PositionRelativeTo"))!=components.end())
		{
			PositionRelativeToComponent& prtC=*boost::polymorphic_downcast<PositionRelativeToComponent*>(components.at(Level::CompKey(*it, "PositionRelativeTo")));
			PositionComponent& ppC =*boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(prtC.relativeTo, "Position")));
			x+=ppC.x;
			y+=ppC.y;
		}
		sC->sprite.setPosition(x, y);
		sC->currentFrameTime+=deltaTime.asSeconds();
		int i=0;
		while(sC->currentFrameTime>sC->loopTime/double(sC->numberOfFrames))
		{
			i++;
			sC->currentFrameTime-=sC->loopTime/double(sC->numberOfFrames);
		}
		sf::IntRect textRect=sC->sprite.getTextureRect();	
		textRect.left = (textRect.left+i*textRect.width) % int(sC->sprite.getTexture()->getSize().x);
		sC->sprite.setTextureRect(textRect);
        window.draw(sC->sprite);
    }
	std::cerr<<"Render end\n";
}

void RenderSystem::addEntity(int EID)
{
	assert( components.find(Level::CompKey(EID, "Position")) != components.end() &&
			components.find(Level::CompKey(EID, "Sprite")) != components.end() );
    entities.push_back(EID);
}