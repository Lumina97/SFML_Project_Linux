#include <iostream>
#include <string>

#include "SFML/Graphics.hpp"
#include "spdlog/spdlog.h"
#include "../EntityHealth/EntityHealth.h"
#include "../Core/Timestep.h"

#pragma once


class Player{

public:  
    Player(uint32_t health);
    ~Player();

public:
    uint32_t GetHealth();
    void DrawPlayer(sf::RenderWindow& window, Core::Timestep ts);
    
    
private:

    sf::Texture Animate(Core::Timestep ts);


    EntityHealth* health;


    /// SpriteSheet
    int32_t maxYSprites = 10;
    int32_t maxXSprites = 10;
    int32_t currentXSprite = 0;
    int32_t currentYSprite = 0;
    int32_t spriteWidth = 32;
    int32_t spriteHeight = 32;
};
