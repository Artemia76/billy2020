#ifndef TILES_MAP_H
#define TILES_MAP_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "LoadMap.h"

class TilesMap : public sf::Drawable, public sf::Transformable
{
public : 
	LoadMap _map; 
	sf::Texture _texture; 

	TilesMap() ;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	sf::VertexArray _vertices;
	sf::VertexArray _verticesLayer1;

	bool load(); 
	bool loadLayer1();

	void init(LoadMap map, sf::Texture texture); 
	 

	void getTileAt(int x, int y); 
	



};

#endif // !TILES_MAP_H