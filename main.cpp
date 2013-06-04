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

int main(int argc, char** argv)
{
try
{
	ArchetypesManager archMan;
	std::ifstream file("resources/archetypes.xml");
	archMan.read(file);
	std::cerr<<"Archetypes read!\n";
    sf::RenderWindow app(sf::VideoMode(800, 600, 32), "SFML Graphics");

	std::ifstream levelFile("resources/testlevel.xml");
	Level level(app, archMan);
	std::cerr<<"Level created\n";
	level.read(levelFile);
	std::cerr<<"Level read\n";
  /*  sf::Texture texture1, texture2;
    texture1.loadFromFile("resources/player.png");
    texture2.loadFromFile("resources/ground.png");
    sf::Sprite sprite1;
    sprite1.setTexture(texture1);
    sf::Sprite sprite2;
    sprite2.setTexture(texture2);*/

    sf::Clock clock;
    clock.restart();
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
		app.clear();
		level.update(clock.restart());
		app.display();
    }

    return EXIT_SUCCESS;
} catch(const std::exception& e)
{
	std::cerr<<"CATCH\n";
	std::cerr<<e.what()<<"\n";
}
}

