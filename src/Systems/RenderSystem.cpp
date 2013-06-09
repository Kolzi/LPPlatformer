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
	sf::Clock timer;
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
		int orX=sC->sprite.getLocalBounds().width/2.0;
		int orY=sC->sprite.getLocalBounds().height/2.0;
		sC->sprite.setOrigin(orX, orY);
		sC->sprite.setPosition(x+orX, y+orY);
		sC->sprite.setRotation(pC->angle);
		
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
	std::cerr<<"Render system: "<<timer.getElapsedTime().asMilliseconds()<<"\n";
}

void RenderSystem::addEntity(int EID)
{
	assert( components.find(Level::CompKey(EID, "Position")) != components.end() &&
			components.find(Level::CompKey(EID, "Sprite")) != components.end() );
    entities.insert(EID);
}