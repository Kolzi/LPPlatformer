/* 
 * File:   StandsOnSystem.cpp
 * Author: kolzi
 * 
 * Created on 8 czerwiec 2013, 14:09
 */

#include "Systems/StandsOnSystem.hpp"

/* 
 * File:   CollisionSystem.cpp
 * Author: marzena
 * 
 * Created on 20 luty 2013, 00:06
 */

#include "Systems/CollisionSystem.hpp"
#include "Components/BoundingBoxComponent.hpp"
#include "Components/StandsOnComponent.hpp"
#include "Components/StandableComponent.hpp"
#include "Components/HasScoreComponent.hpp"
#include "Components/ScoreComponent.hpp"
#include "Components/DamageComponent.hpp"

#include <iostream>
#include <algorithm>
#include <assert.h>
#include <boost/cast.hpp>

StandsOnSystem::StandsOnSystem(Level::CompMap& components)
: System(components)
{
}

StandsOnSystem::StandsOnSystem(const StandsOnSystem& orig)
: System(orig)
{
}

StandsOnSystem::~StandsOnSystem()
{
}

void StandsOnSystem::addEntity(int EID)
{
	assert(components.find(Level::CompKey(EID, "StandsOn")) != components.end() &&
		components.find(Level::CompKey(EID, "BoundingBox")) != components.end());
	entities.push_back(EID);
}

void StandsOnSystem::update(sf::Time deltaTime)
{
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		if (components.find(Level::CompKey(*it, "StandsOn")) != components.end())
			boost::polymorphic_downcast<StandsOnComponent*>(components.at(Level::CompKey(*it, "StandsOn")))->standing = false;
	}
	for (auto it = entities.begin(); it != entities.end(); it++)
	{
		PositionComponent& posCi = *boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(*it, "Position")));
		BoundingBoxComponent& bbCi = *boost::polymorphic_downcast<BoundingBoxComponent*>(components.at(Level::CompKey(*it, "BoundingBox")));

		//	bool iCanStand = components.find(Level::CompKey(*it, "StandsOn")) != components.end();
		//	bool iStandable = components.find(Level::CompKey(*it, "Standable")) != components.end();

		//	bool iHasScore = components.find(Level::CompKey(*it, "HasScore")) != components.end();
		//	bool iDamage = components.find(Level::CompKey(*it, "Damage")) != components.end();
		for (BoundingBoxComponent::CollisionData collWith : bbCi.collidedWith)
		{
			PositionComponent& posCj = *boost::polymorphic_downcast<PositionComponent*>(components.at(Level::CompKey(collWith.EID, "Position")));
			BoundingBoxComponent& bbCj = *boost::polymorphic_downcast<BoundingBoxComponent*>(components.at(Level::CompKey(collWith.EID, "BoundingBox")));

			//	bool jCanStand = components.find(Level::CompKey(*jt, "StandsOn")) != components.end();
			//	bool jStandable = components.find(Level::CompKey(*jt, "Standable")) != components.end();

			//	bool jHasScore = components.find(Level::CompKey(*jt, "HasScore")) != components.end();
			//	bool jDamage = components.find(Level::CompKey(*jt, "Damage")) != components.end();

			sf::Rect<double> bbi = bbCi.boundingBox;
			sf::Rect<double> bbj = bbCj.boundingBox;

			bbi.left += posCi.x;
			bbi.top += posCi.y + 1;
			bbj.left += posCj.x;
			bbj.top += posCj.y;

			if (bbi.intersects(bbj) && bbCj.topSolid)
			{
				StandsOnComponent& standsOn = *boost::polymorphic_downcast<StandsOnComponent*>(components.at(Level::CompKey(*it, "StandsOn")));
				StandableComponent empty(-1);
				StandableComponent& standable = (components.find(Level::CompKey(collWith.EID, "Standable"))!= components.end() ? 
						*boost::polymorphic_downcast<StandableComponent*>(components.at(Level::CompKey(collWith.EID, "Standable"))):
					empty);
				standsOn.jumpingTimeLeft = standsOn.baseJumpingTime * standable.jumpingTimeMultiplier;
				standsOn.standing = true;
				standsOn.standsOn = collWith.EID;
				break;
			}
		}	
	}
}