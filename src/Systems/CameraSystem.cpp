/* 
 * File:   CameraSystem.cpp
 * Author: marzena
 * 
 * Created on 18 luty 2013, 23:24
 */

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "Systems/CameraSystem.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/CameraSourceComponent.hpp"
#include <assert.h>
#include <iostream>

CameraSystem::CameraSystem(sf::RenderWindow& window,
				 std::unordered_map<int, PositionComponent>& positionComponents, 
				 std::unordered_map<int, CameraSourceComponent>& cameraSourceComponents,
				 std::unordered_map<int, ViewportComponent>& viewportComponents)
:window(window), positionComponents(positionComponents),
		cameraSourceComponents(cameraSourceComponents),
		viewportComponents(viewportComponents)
{}

CameraSystem::CameraSystem(const CameraSystem& orig)
:window(orig.window), positionComponents(orig.positionComponents),
		cameraSourceComponents(orig.cameraSourceComponents),
		viewportComponents(orig.viewportComponents)
{
}

CameraSystem::~CameraSystem()
{
}

void CameraSystem::applyView()
{
    for(auto it=entities.begin();it!=entities.end();it++)
    {
        PositionComponent& pC=positionComponents.at(*it);
        CameraSourceComponent& csC=cameraSourceComponents.at(*it);
		ViewportComponent& vC=viewportComponents.at(*it);
        view.setCenter(pC.x+csC.offsetX, pC.y+csC.offsetY);
		view.setSize(csC.sourceWidth, csC.sourceHeight);
		//std::cerr<<view.GetCenter().x<<" "<<view.GetCenter().y<<"\n";
		//std::cerr<<view.GetHalfSize().x<<" "<<view.GetHalfSize().y<<"\n";
		//FIXME SFML2 viewport
        window.setView(view);
    }
}

void CameraSystem::addEntity(int EID)
{
	assert( positionComponents.find(EID) != positionComponents.end() &&
			cameraSourceComponents.find(EID) != cameraSourceComponents.end() &&
			viewportComponents.find(EID) != viewportComponents.end() );
    entities.push_back(EID);
}