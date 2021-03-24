#include "Player.h"

Player::Player(uint32_t health){
    //std::cout << "Constructed Player with health: "<< health<< std::endl;
    spdlog::info("Constructed Player with health: " + std::to_string(health));
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

void Player::DrawPlayer(sf::RenderWindow& window, Core::Timestep ts){
    sf::Texture tex = Animate(ts);
    sf::Sprite sprite;

    sprite.setTexture(tex);

    window.draw(sprite);
}

sf::Texture Player::Animate(Core::Timestep ts)
{
    sf::Texture tex;
    int32_t xCoord =  currentXSprite * spriteWidth;
    int32_t yCoord =  currentYSprite * spriteHeight;

    if(!tex.loadFromFile("../Resources/Player/Sprites/rogue.png", sf::IntRect(xCoord,yCoord,spriteWidth,spriteHeight) ))
    {
        spdlog::error("There was an error getting sprite animation!/n x = " + std::to_string(xCoord) + "\n y = " + std::to_string(yCoord));
        return tex;
    }

    float x = currentXSprite * ts;
    spdlog::info( x);
    currentXSprite = (int32_t)(currentXSprite * ts) % 1;


    if(currentXSprite >= maxXSprites - 1) {
        currentXSprite = 0;
        currentYSprite++;
    }

    if(currentYSprite >= maxYSprites - 1) currentYSprite = 0;

    return tex;
}

