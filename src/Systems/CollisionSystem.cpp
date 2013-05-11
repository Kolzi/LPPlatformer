/* 
 * File:   CollisionSystem.cpp
 * Author: marzena
 * 
 * Created on 20 luty 2013, 00:06
 */

#include "Systems/CollisionSystem.hpp"
#include "Components/BoundingBoxComponent.hpp"

#include <iostream>
#include <algorithm>
#include <assert.h>
#include <boost/cast.hpp>

CollisionSystem::CollisionSystem(Level::CompMap& components)
:System(components)
{
}

CollisionSystem::CollisionSystem(const CollisionSystem& orig)
:System(orig)
{
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::addEntity(int EID)
{
	assert( components.find(Level::CompKey(EID, "Position")) != components.end() &&
			components.find(Level::CompKey(EID, "BoundingBox")) != components.end() );
    entities.push_back(EID);
}

void CollisionSystem::update(sf::Time deltaTime)
{
	for(auto it=entities.begin();it!=entities.end();it++)
	{
		auto jt=it;
		jt++;
		for(jt;jt!=entities.end();jt++)
		{
			PositionComponent* posCi=boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(*it, "Position")));
			PhysicsComponent empty(*it);
			PhysicsComponent* physCi=
			(components.find(Level::CompKey(*it, "Physics")) != components.end() ?
				boost::polymorphic_downcast<PhysicsComponent*>(components.at(Level::CompKey(*it, "Physics"))) : &empty);
			
			BoundingBoxComponent* bbCi=boost::polymorphic_downcast<BoundingBoxComponent*>(components.at(Level::CompKey(*it, "BoundingBox")));
			
			PositionComponent* posCj=boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(*jt, "Position")));
			PhysicsComponent* physCj=
			(components.find(Level::CompKey(*jt, "Physics")) != components.end() ?
				boost::polymorphic_downcast<PhysicsComponent*>(components.at(Level::CompKey(*jt, "Physics"))) : &empty);
			
			BoundingBoxComponent* bbCj=boost::polymorphic_downcast<BoundingBoxComponent*>(components.at(Level::CompKey(*jt, "BoundingBox")));
			
			sf::Rect<double> bbi=bbCi->boundingBox;
			sf::Rect<double> bbj=bbCj->boundingBox;
			
            bbi.left+=posCi->x;
            bbi.top +=posCi->y;
            bbj.left+=posCj->x;
            bbj.top +=posCj->y;
			
			if(bbi.intersects(bbj))
			{
				double tx=999999;
				double ty=999999;
				double relVx=physCi->vx-physCj->vx;
				if(relVx>0)
					tx=(bbi.left+bbi.width-bbj.left)/relVx;
				if(relVx<0)
					tx=(bbi.left-bbj.left-bbj.width)/relVx;
				double relVy=physCi->vy-physCj->vy;
				if(relVy>0)
					ty=(bbi.top+bbi.height-bbj.top)/relVy;
				if(relVy<0)
					ty=(bbi.top-bbj.top-bbj.height)/relVy;
				double t=std::min(tx,ty);

				if(t==tx)
				{
					posCi->x-=(t*physCi->vx);
					posCj->x-=(t*physCj->vx);
					physCi->vx=0;
					physCi->ax=0;
					physCj->ax=0;
					physCj->vx=0;
				}
				else if(t==ty)
				{
					posCi->y-=(t*physCi->vy);
					posCj->y-=(t*physCj->vy);
					physCi->ay=0;
					physCi->vy=0;
					physCj->vy=0;
					physCj->ay=0;
				}
			}
		}
	}
}