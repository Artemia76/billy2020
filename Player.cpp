#include "Player.h"

Player::Player()
{
	_circle.setRadius(150);
	_circle.setOutlineColor(sf::Color::Red);
	_circle.setOutlineThickness(5);
	_circle.setPosition(10, 20);
}

void Player::processEvents()
{
}

void Player::update(sf::Time deltaTime)
{
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_circle, states);
}
