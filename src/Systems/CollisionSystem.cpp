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

CollisionSystem::CollisionSystem(std::unordered_map<int,PositionComponent>& positionComponents,
		std::unordered_map<int,PhysicsComponent>& physicsComponents,
		std::unordered_map<int,BoundingBoxComponent>& boundingBoxComponents)
:positionComponents(positionComponents), physicsComponents(physicsComponents),
		boundingBoxComponents(boundingBoxComponents)
{
}

CollisionSystem::CollisionSystem(const CollisionSystem& orig)
:positionComponents(orig.positionComponents), physicsComponents(orig.physicsComponents),
		boundingBoxComponents(orig.boundingBoxComponents)
{
}

CollisionSystem::~CollisionSystem()
{
}

void CollisionSystem::addEntity(int EID)
{
	assert( positionComponents.find(EID) != positionComponents.end() &&
			boundingBoxComponents.find(EID) != boundingBoxComponents.end() );
    entities.push_back(EID);
}

void CollisionSystem::detectCollisions()
{
	for(auto it=entities.begin();it!=entities.end();it++)
	{
		auto jt=it;
		jt++;
		for(jt;jt!=entities.end();jt++)
		{
	//		std::cerr<<*it<<" "<<*jt<<"\n";
			PositionComponent& posCi=positionComponents.find(*it)->second;
			PhysicsComponent empty(*it);
			PhysicsComponent& physCi=
			physicsComponents.find(*it) != physicsComponents.end() ?
				physicsComponents.find(*it)->second : empty;
			BoundingBoxComponent& bbCi=boundingBoxComponents.find(*it)->second;
			
			PositionComponent& posCj=positionComponents.find(*jt)->second;
			PhysicsComponent& physCj=
			physicsComponents.find(*jt) != physicsComponents.end() ?
				physicsComponents.find(*jt)->second : empty;
			BoundingBoxComponent& bbCj=boundingBoxComponents.find(*jt)->second;
			
			sf::Rect<double> bbi=bbCi.boundingBox;
			sf::Rect<double> bbj=bbCj.boundingBox;
			
			bbi.Offset(posCi.x, posCi.y);
			bbj.Offset(posCj.x, posCj.y);
		
			
			if(bbi.Intersects(bbj))
			{
				std::cerr<<"Collision!\n";
			//	std::cerr<<bbi.Left<<" "<<bbi.Top<<" "<<bbi.Right<<" "<<bbi.Bottom<<"\n";
			//	std::cerr<<bbj.Left<<" "<<bbj.Top<<" "<<bbj.Right<<" "<<bbj.Bottom<<"\n";
				double tx=999999;
				double ty=999999;
				double relVx=physCi.vx-physCj.vx;
				if(relVx>0)
					tx=(bbi.Right-bbj.Left)/relVx;
				if(relVx<0)
					tx=(bbi.Left-bbj.Right)/relVx;
				double relVy=physCi.vy-physCj.vy;
				if(relVy>0)
					ty=(bbi.Bottom-bbj.Top)/relVy;
				if(relVy<0)
					ty=(bbi.Top-bbj.Bottom)/relVy;
				std::cerr<<tx<<" "<<ty<<"\n";
				std::cerr<<physCi.ax<<" "<<physCi.ay<<"\n";
				std::cerr<<physCi.vx<<" "<<physCi.vy<<"\n";
				double t=std::min(tx,ty);

				if(t==tx)
				{
					std::cerr<<"x\n";
					posCi.x-=(t*physCi.vx);
					posCj.x-=(t*physCj.vx);
					physCi.vx=0;
					physCi.ax=0;
					physCj.ax=0;
					physCj.vx=0;posCi.x-=(t*physCi.vx);
				}
				else if(t==ty)
				{
					std::cerr<<"y\n";
					posCi.y-=(t*physCi.vy);
					posCj.y-=(t*physCj.vy);
					physCi.ay=0;
					physCi.vy=0;
					physCj.vy=0;
					physCj.ay=0;
				}
			}
		}
	}
}