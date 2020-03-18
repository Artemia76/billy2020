#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "ResourceDispatcher.h"


class Player : public sf::Drawable
{

public:
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    Player();

    void processEvents();

    void update(sf::Time deltaTime);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::Sprite _character;
    sf::Vector2f _velocity;
    sf::Texture texture;
   // sf::CircleShape _circle;

    bool _is_moving;
    int _rotation;
};

#endif

