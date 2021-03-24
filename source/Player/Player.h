#include <iostream>
#include <string>

#include "SFML/Graphics.hpp"
#include "../EntityHealth/EntityHealth.h"

#pragma once


class Player{
public:  
    Player(uint32_t health);
    ~Player();   
    

    uint32_t GetHealth();
    
    
private:
    EntityHealth* health;
    
    
};
