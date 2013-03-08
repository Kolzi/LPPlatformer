/* 
 * File:   CameraSystem.hpp
 * Author: marzena
 *
 * Created on 18 luty 2013, 23:24
 */

#ifndef CAMERASYSTEM_HPP
#define	CAMERASYSTEM_HPP

#include "System.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/CameraSourceComponent.hpp"
#include "Components/ViewportComponent.hpp"

#include <SFML/Graphics.hpp>
#include <unordered_map>
class CameraSystem : System
{
public:
	CameraSystem(sf::RenderWindow& window,
				 std::unordered_map<int,PositionComponent>& positionComponents, 
				 std::unordered_map<int,CameraSourceComponent>& cameraSourceComponents,
				 std::unordered_map<int,ViewportComponent>& viewportComponents);
	CameraSystem(const CameraSystem& orig);
	virtual ~CameraSystem();
	void applyView();
	void addEntity(int EID);
private:
	sf::RenderWindow& window;
	sf::View view;
	std::unordered_map<int,PositionComponent>& positionComponents;
	std::unordered_map<int,CameraSourceComponent>& cameraSourceComponents;
	std::unordered_map<int,ViewportComponent>& viewportComponents;
};

#endif	/* CAMERASYSTEM_HPP */

