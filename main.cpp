/* 
 * File:   main.cpp
 * Author: marzena
 *
 * Created on 17 luty 2013, 22:43
 */

#include <unordered_map>
#include "Components/SpriteComponent.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/ViewportComponent.hpp"
#include "Components/CameraSourceComponent.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/PlayerInputSystem.hpp"
#include "Systems/CameraSystem.hpp"
#include "Systems/MovementSystem.hpp"
#include "Components/BoundingBoxComponent.hpp"
#include "Systems/CollisionSystem.hpp"
#include "Systems/GravitySystem.hpp"
#include <iostream>

int main(int argc, char** argv) 
{
	sf::RenderWindow app(sf::VideoMode(800, 600, 32), "SFML Graphics");
	
    std::unordered_map <int, SpriteComponent> spriteComponents;
    std::unordered_map <int, PositionComponent> positionComponents;
	std::unordered_map <int, ViewportComponent> viewportComponents;
    std::unordered_map <int, CameraSourceComponent> cameraSourceComponents;
	std::unordered_map <int, PhysicsComponent> physicsComponents;
	std::unordered_map <int, BoundingBoxComponent> boundingBoxComponents;
	std::unordered_map <int, GravityComponent> gravityComponents;
	
	
    sf::Image image1(50, 50, sf::Color(0, 255, 0));
	sf::Image image2(100, 100, sf::Color(0, 0, 255));
    sf::Sprite sprite1;
    sprite1.SetImage(image1);
    sf::Sprite sprite2;
    sprite2.SetImage(image2);
	
	RenderSystem rs(app, positionComponents, spriteComponents);
    PlayerInputSystem ps(app.GetInput(), positionComponents, physicsComponents);
	CameraSystem cs(app, positionComponents, cameraSourceComponents, viewportComponents);
	MovementSystem ms(positionComponents, physicsComponents);
	CollisionSystem colls(positionComponents, physicsComponents, boundingBoxComponents);
	GravitySystem gs(physicsComponents, gravityComponents);
	
    positionComponents.insert(std::pair<int, PositionComponent>(1, PositionComponent(125,125,0,1)));
    spriteComponents.insert(std::pair<int, SpriteComponent>(1,SpriteComponent(sprite1, 1)));
	viewportComponents.insert(std::pair<int, ViewportComponent>(1, 
					ViewportComponent(0,0, app.GetWidth(), app.GetHeight(),1)));
	cameraSourceComponents.insert(std::pair<int, CameraSourceComponent>(1, 
					CameraSourceComponent(100,100, 0, app.GetWidth(), app.GetHeight(),1)));
	physicsComponents.insert(std::pair<int, PhysicsComponent>(1, 
					PhysicsComponent(1)));
	boundingBoxComponents.insert(std::pair<int, BoundingBoxComponent>(1, 
					BoundingBoxComponent(sf::Rect<double>(0, 0,50,50),1)));
	gravityComponents.insert(std::pair<int, GravityComponent>(1, 
					GravityComponent(1)));
	
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			positionComponents.insert(std::pair<int, PositionComponent>(2+i*10+j, PositionComponent(-200+i*200,-200+j*200,0,1+i*10+j)));
			spriteComponents.insert(std::pair<int, SpriteComponent>(2+i*10+j,SpriteComponent(sprite2, 1+i*10+j)));
			boundingBoxComponents.insert(std::pair<int, BoundingBoxComponent>(2+i*10+j, 
					BoundingBoxComponent(sf::Rect<double>(0, 0,100,100),2+i*10+j)));
	//		std::cerr<<(positionComponents.find(2+i*10+j)!=positionComponens.end())<<" ";
	//		std::cerr<<(spriteComponents.find(2+i*10+j) != spriteComponents.end())<<"\n";
			rs.addEntity(2+i*10+j);
			colls.addEntity(2+i*10+j);
		}
	}
	
	
	
	
    
    
    rs.addEntity(1);
    ps.addEntity(1);
    cs.addEntity(1);
	ms.addEntity(1);
	colls.addEntity(1);
	gs.addEntity(1);
	
    std::cerr<<"Loop\n";
    while (app.IsOpened())
    {
        sf::Event Event;
        while (app.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                app.Close();
        }
		ps.handleInput();
		gs.apply();
		ms.move(app.GetFrameTime());
		colls.detectCollisions();
        // Clear the screen (fill it with black color)
        cs.applyView();
		app.Clear();
		rs.render();
      
        
        // Display window contents on screen
        app.Display();
		std::cout<<app.GetFrameTime()<<"\n";
    }

    return EXIT_SUCCESS;
}

