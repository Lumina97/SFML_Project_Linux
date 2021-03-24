#include "EntityHealth.h"

EntityHealth:: EntityHealth(){
    std::cout << "Constructed health" << std::endl;
}
    
EntityHealth::~EntityHealth(){
    std::cout << "Destructed health" << std::endl;
}


void EntityHealth::SetHealth(uint32_t health){
    this->health = health;
}
    
uint32_t EntityHealth::GetHealth(){
    return this->health;
}
