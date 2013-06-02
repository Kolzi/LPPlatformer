/* 
 * File:   StringComponentConverter.cpp
 * Author: kolzi
 * 
 * Created on 19 kwiecień 2013, 18:55
 */

#include <vector>

#include "Components/Component.hpp"
#include "General/StringComponentConverter.h"
#include "Components/BoundingBoxComponent.hpp"
#include "Components/CameraSourceComponent.hpp"
#include "Components/GravityComponent.hpp"
#include "Components/PhysicsComponent.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/ViewportComponent.hpp"
#include "Components/StandsOnComponent.hpp"
#include "Components/StandableComponent.hpp"
#include "Components/MusicComponent.hpp"
#include "Exceptions/NoSuchComponentName.hpp"
#include "Components/ScoreComponent.hpp"
#include "Components/HasScoreComponent.hpp"
#include "Components/TextComponent.hpp"
#include "Components/DamageComponent.hpp"
#include "Components/ParticleComponent.hpp"

std::vector<std::string> StringComponentConverter::componentNames={"BoundingBox", 
	"CameraSource", "Gravity", "Physics", "Position", "Sprite", "Viewport", "StandsOn",
	"Standable", "Music", "Score", "HasScore", "Text", "Damage","Particle"};

Component* StringComponentConverter::stringToComponent(std::string componentName, 
                                                       rapidxml::xml_node<>* archetypeNode)
{
    if(componentName=="BoundingBox")
        return new BoundingBoxComponent(archetypeNode);
    if(componentName=="CameraSource")
        return new CameraSourceComponent(archetypeNode);
    if(componentName=="Gravity")
        return new GravityComponent(archetypeNode);
    if(componentName=="Physics")
        return new PhysicsComponent(archetypeNode);
    if(componentName=="Position")
        return new PositionComponent(archetypeNode);
    if(componentName=="Sprite")
        return new SpriteComponent(archetypeNode);
    if(componentName=="Viewport")
        return new ViewportComponent(archetypeNode);
    if(componentName=="StandsOn")
        return new StandsOnComponent(archetypeNode);
	if(componentName=="Standable")
        return new StandableComponent(archetypeNode);
	if(componentName=="Music")
		return new MusicComponent(archetypeNode);
	if(componentName=="Score")
		return new ScoreComponent(archetypeNode);
	if(componentName=="HasScore")
		return new HasScoreComponent(archetypeNode);
	if(componentName=="Text")
		return new TextComponent(archetypeNode);
	if(componentName=="Damage")
		return new DamageComponent(archetypeNode);
	if(componentName=="Particle")
		return new ParticleComponent(archetypeNode);
	
	
	throw NoSuchComponentName(componentName);
}

