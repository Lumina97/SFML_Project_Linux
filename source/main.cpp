#include "config.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player/Player.h"

int main(int argc, char* argv[])
{
    std::cout << "Version " << myproject_VERSION_MAJOR << "." << myproject_VERSION_MINOR << std::endl;
    
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    
    uint32_t health = 10;
    Player* player = new Player(health);
    std::cout <<"Player health: " << player->GetHealth() << std::endl;    
    delete player;  
    
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
