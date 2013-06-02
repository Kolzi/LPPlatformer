/* 
 * File:   ParticleComponent.hpp
 * Author: kolzi
 *
 * Created on 2 czerwiec 2013, 16:40
 */

#ifndef PARTICLECOMPONENT_HPP
#define	PARTICLECOMPONENT_HPP

#include "Component.hpp"
#include "rapidxml/rapidxml.hpp"


struct ParticleComponent : public Component
{
	ParticleComponent(int EID);
	ParticleComponent(rapidxml::xml_node<>* componentNode);
	virtual ~ParticleComponent();
	
	Component* clone(int newEID);
	void read(rapidxml::xml_node<>* componentNode);

	double timeSinceLastParticle;
	
	double minV, maxV;
	double minAngle, maxAngle;
	double minWidth, maxWidth;
	double minHeight, maxHeight;
	double minAngularV, maxAngularV;
	double minGravity, maxGravity;
	double minLifeTime, maxLifeTime;
	int minParticlesPerSec, maxParticlesPerSec;
	std::string emitsArchetype;
	
	static const double defaultMinV, defaultMaxV;
	static const double defaultMinAngle, defaultMaxAngle;
	static const double defaultMinWidth, defaultMaxWidth;
	static const double defaultMinHeight, defaultMaxHeight;
	static const double defaultMinAngularV, defaultMaxAngularV;
	static const double defaultMinLifeTime, defaultMaxLifeTime;
	static const double defaultMinGravity, defaultMaxGravity;
	static const int defaultMinParticlesPerSec, defaultMaxParticlesPerSec;
};

#endif	/* PARTICLECOMPONENT_HPP */

