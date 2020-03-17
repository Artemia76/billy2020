#include "RessourceManager.h"

void RessourceManager::load(const int& id, sf::Texture texture)
{
	_map.insert({ id, std::unique_ptr<sf::Texture>(new sf::Texture(texture)) });

}

sf::Texture& RessourceManager::get(const int& id) const
{
	// TODO: insérer une instruction return ici

	 return *(_map.at(id).get());
	 //sf::Texture* text =  _map.at(id).get();
}
