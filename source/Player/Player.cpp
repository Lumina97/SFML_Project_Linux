#include "Player.h"


Player::Player(uint32_t health){
    std::cout << "Constructed Player with health: "<< health<< std::endl;
    
    this->health = new EntityHealth();
    this->health->SetHealth(health);  
} 

Player::~Player(){
    std::cout << "Destructed Player" << std::endl;
    delete this->health;
}

uint32_t Player::GetHealth(){
    
    return this->health->GetHealth();
}
