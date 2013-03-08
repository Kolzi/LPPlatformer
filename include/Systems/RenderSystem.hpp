/* 
 * File:   RenderSystem.hpp
 * Author: marzena
 *
 * Created on 17 luty 2013, 23:29
 */

#ifndef RENDERSYSTEM_HPP
#define	RENDERSYSTEM_HPP

#include "Components/SpriteComponent.hpp"
#include "Components/PositionComponent.hpp"
#include "Systems/System.hpp"

#include <unordered_map>


class RenderSystem : public System
{
public:
    RenderSystem(	sf::RenderWindow& window, 
					std::unordered_map<int,PositionComponent>& positionComponents,
					std::unordered_map<int,SpriteComponent>& spriteComponents);
    RenderSystem(const RenderSystem& orig);
    virtual ~RenderSystem();
    void render();
    void addEntity(int EID);
private:
    sf::RenderWindow& window;
	std::unordered_map<int,PositionComponent>& positionComponents;
	std::unordered_map<int,SpriteComponent>& spriteComponents;
};

#endif	/* RENDERSYSTEM_HPP */

