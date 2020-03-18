#include "Player.h"

Player::Player()
{
	auto sf(ResourceDispatcher::rDispatcherTexture.get(0)); 
	/*sf::Texture texture;
	if (!texture.loadFromFile("assets/images/billyanim.png")) {
		return; 
	}*/
	_character.setTexture(ResourceDispatcher::rDispatcherTexture.get(0));
	_character.setPosition(300, 15); 
	//_character.setTextureRect(sf::IntRect(10, 10, 50, 30));
	//_character.setColor(sf::Color(255, 255, 255, 200));
}

void Player::processEvents()
{
}

void Player::update(sf::Time deltaTime)
{
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_character, states);
}
