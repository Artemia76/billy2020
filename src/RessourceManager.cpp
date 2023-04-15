#include "RessourceManager.h"

void RessourceManager::load(const int& id, std::string textureName)
{
	
	sf::Texture texture;
	if (!texture.loadFromFile(textureName)) {
		return;
	}
	_map.insert({ id, std::make_unique<sf::Texture>(texture) });

}



sf::Texture& RessourceManager::get(const int& id) const
{
	// TODO: insérer une instruction return ici
	//auto t = _map.at(id); 
	 sf::Texture* text =  _map.at(id).get();
	 return *(_map.at(id).get());
	 //
}
