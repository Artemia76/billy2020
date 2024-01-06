#include "Player.h"
#include "ResourceDispatcher.h"

Player::Player()
{
    //auto sf(ResourceDispatcher::rDispatcherTexture.get(0));
    /*sf::Texture texture;
    if (!texture.loadFromFile("assets/images/billyanim.png")) {
        return;
    }*/
    //_character.setTexture(ResourceDispatcher::rDispatcherTexture.get(0));
    //_character.setPosition(_position);




    //_character.setColor(sf::Color(255, 255, 255, 200));
}

void Player::init()
{
    _position = sf::Vector2f(300,15);
    _animateRight.Init(0,0,36,61,5, ResourceDispatcher::rDispatcherTexture.get(0));
    _animateIdle.Init(0,61,36,61,2, ResourceDispatcher::rDispatcherTexture.get(0));
    _animateLeft.Init(0,122,36,61,5, ResourceDispatcher::rDispatcherTexture.get(0));
    _character.setPosition(_position);
}

void Player::processEvents( float sec)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

        _position.x -= 50.0f * sec;
        _character.setPosition(_position);
        _animateLeft.Update(sec);
        _animateLeft.ApplyToSprite(_character);

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

        _position.x += 50.0f * sec;
        _character.setPosition(_position);
        _animateRight.Update(sec);
        _animateRight.ApplyToSprite(_character);

    }
    else {
        _animateIdle.Update(sec);
        _animateIdle.ApplyToSprite(_character);
    }

}

void Player::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();


    processEvents(seconds );


}

void Player::moveLeft(float mvt)
{
    _position.x -= mvt;
    _character.setPosition(_position);
}

void Player::animatePlayer()
{
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_character, states);
}
