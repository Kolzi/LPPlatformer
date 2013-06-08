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
#include "General/ArchetypesManager.h"
#include "Exceptions/NoSuchComponentName.hpp"
#include "Exceptions/RequiredAttributeNotFound.hpp"
#include <iostream>
#include <fstream>
#include "States/GameState.hpp"

int main(int argc, char** argv)
{
try
{
	ArchetypesManager archMan;
	std::ifstream file("resources/archetypes.xml");
	archMan.read(file);
	std::cerr<<"Archetypes read!\n";
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "SFML Graphics");
	
	GameState gameS(app, archMan, "testlevel.xml");
	
    std::cerr << "Loop\n";
    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }
		app.clear(sf::Color(128,128,255));
		gameS.update();
		app.display();
    }

    return EXIT_SUCCESS;
} catch(const std::exception& e)
{
	std::cerr<<"CATCH\n";
	std::cerr<<e.what()<<"\n";
}
}

