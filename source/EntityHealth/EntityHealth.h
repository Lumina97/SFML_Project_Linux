#pragma once
#include <iostream>


class EntityHealth
{
public:
    EntityHealth();
    ~EntityHealth();
    
    void SetHealth(uint32_t health);
    uint32_t GetHealth();
    
private:
    uint32_t health;
    
};
