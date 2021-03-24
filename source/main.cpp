#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player/Player.h"
#include "Core/Timestep.h"
#include "Core/Log.h"

int main()
{
    Log::Init();
   // LOG::Log::GetLogger()->warn("Version " + std::to_string(myproject_VERSION_MAJOR) + "." + std::to_string(myproject_VERSION_MINOR) );
    std::cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << std::endl;
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML game");
    
    Player* player = new Player((uint32_t)10);
    std::cout <<"Player health: " << player->GetHealth() << std::endl;    

    //Clock
    sf::Clock clock;
    float lastFrameTime = 0.0f;

    while (window.isOpen())
    {
        //timer
        float time = clock.getElapsedTime().asSeconds();
        Core::Timestep timestep = time - lastFrameTime;
        lastFrameTime = time;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        player->DrawPlayer(window,timestep);
        window.display();
    }

    delete player;

    return 0;
}
