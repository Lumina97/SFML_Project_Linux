#include "Player.h"
#include "../Core/Log.h"

Player::Player(uint32_t health){
    LOG_INFO( "Constructed Player with health: " + std::to_string(health) );
    this->health = new EntityHealth();
    this->health->SetHealth(health);  
} 

Player::~Player(){
    LOG_INFO( "Destructed Player");
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
    int32_t xCoord =  (int32_t) currentXSprite * spriteWidth;
    int32_t yCoord =  (int32_t) currentYSprite * spriteHeight;

    if(!tex.loadFromFile("../Resources/Player/Sprites/rogue.png", sf::IntRect(xCoord,yCoord,spriteWidth,spriteHeight) ))
    {
        LOG_ERROR("There was an error getting sprite animation!/n x = " + std::to_string(xCoord) + "\n y = " + std::to_string(yCoord));
        return tex;
    }

    accumulator += ts;

    while(accumulator > 1.0/15.0)
    {
        currentXSprite++;

        if(currentXSprite >= maxXSprites ) {
            currentXSprite = 0;
            currentYSprite++;
        }

        if(currentYSprite >= maxYSprites) currentYSprite = 0;
        accumulator -= 1.0/15.0;
        if(accumulator < 0) accumulator  =0;
    }

    return tex;
}

