#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Animation.h"

class Player : public sf::Drawable
{

public:
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    Player() ;

    void processEvents(float sec);

    void init();
    void update(sf::Time deltaTime);

    void moveLeft(float mvt); 
    

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void animatePlayer();

    sf::Sprite _character;
    sf::Vector2f _velocity;
    sf::Vector2f _position;
    Animation _animateRight; 
    Animation _animateIdle;
    Animation _animateLeft; 

    bool _is_moving;
    
};

#endif

