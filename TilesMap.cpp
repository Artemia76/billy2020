#include "TilesMap.h"



TilesMap::TilesMap() 
{

}



void TilesMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	// on applique la transformation
	states.transform *= getTransform();

	// on applique la texture du tileset
	states.texture = &_texture;


	// et on dessine enfin le tableau de vertex
	target.draw(_vertices, states);
	target.draw(_verticesLayer1, states); 
}

bool TilesMap::load()
{
	_vertices.setPrimitiveType(sf::Quads); 
	_vertices.resize(_map.tileswide * _map.tileheight * 4); 


	for (unsigned int i = 0; i < _map.tileswide; ++i)
	{
		for (unsigned int j = 0; j < _map.tileshigh; ++j)
		{
		//	int tileNumber = _map.map[i + j * _map.tileswide]; 
			int tileNumber = _map.map[0][i + j * _map.tileswide];
			std::cout << tileNumber << '\n'; 

			int tu = tileNumber % (_texture.getSize().x / _map.tileheight);
			int tv = tileNumber / (_texture.getSize().x / _map.tileheight);
			

			sf::Vertex* quad = &_vertices[(i + j * _map.tileswide) * 4];

			// on définit ses quatre coins
			quad[0].position = sf::Vector2f(i * _map.tilewidth, j * _map.tilewidth);
			quad[1].position = sf::Vector2f((i + 1) * _map.tilewidth, j * _map.tilewidth);
			quad[2].position = sf::Vector2f((i + 1) * _map.tilewidth, (j + 1) * _map.tilewidth);
			quad[3].position = sf::Vector2f(i * _map.tilewidth, (j + 1) * _map.tilewidth);

			// on définit ses quatre coordonnées de texture
			quad[0].texCoords = sf::Vector2f(tu * _map.tilewidth, tv * _map.tilewidth);
			quad[1].texCoords = sf::Vector2f((tu + 1) * _map.tilewidth, tv * _map.tilewidth);
			quad[2].texCoords = sf::Vector2f((tu + 1) * _map.tilewidth, (tv + 1) * _map.tilewidth);
		    quad[3].texCoords = sf::Vector2f(tu * _map.tilewidth, (tv + 1) * _map.tilewidth);
		}
	}





	return false;
}

bool TilesMap::loadLayer1()
{

	_verticesLayer1.setPrimitiveType(sf::Quads);
	_verticesLayer1.resize(_map.tileswide * _map.tileheight * 4);


	for (unsigned int i = 0; i < _map.tileswide; ++i)
	{
		for (unsigned int j = 0; j < _map.tileshigh; ++j)
		{
			//	int tileNumber = _map.map[i + j * _map.tileswide]; 
			int tileNumber = _map.map[1][i + j * _map.tileswide];
			std::cout << tileNumber << '\n';

			int tu = tileNumber % (_texture.getSize().x / _map.tileheight);
			int tv = tileNumber / (_texture.getSize().x / _map.tileheight);


			sf::Vertex* quad = &_verticesLayer1[(i + j * _map.tileswide) * 4];

			// on définit ses quatre coins
			quad[0].position = sf::Vector2f(i * _map.tilewidth, j * _map.tilewidth);
			quad[1].position = sf::Vector2f((i + 1) * _map.tilewidth, j * _map.tilewidth);
			quad[2].position = sf::Vector2f((i + 1) * _map.tilewidth, (j + 1) * _map.tilewidth);
			quad[3].position = sf::Vector2f(i * _map.tilewidth, (j + 1) * _map.tilewidth);

			// on définit ses quatre coordonnées de texture
			quad[0].texCoords = sf::Vector2f(tu * _map.tilewidth, tv * _map.tilewidth);
			quad[1].texCoords = sf::Vector2f((tu + 1) * _map.tilewidth, tv * _map.tilewidth);
			quad[2].texCoords = sf::Vector2f((tu + 1) * _map.tilewidth, (tv + 1) * _map.tilewidth);
			quad[3].texCoords = sf::Vector2f(tu * _map.tilewidth, (tv + 1) * _map.tilewidth);
		}
	}


	return false;
}

void TilesMap::init(LoadMap map, sf::Texture texture)
{
	_map = map;
	_texture = texture; 
}

void TilesMap::getTileAt(int x, int y)
{
}
