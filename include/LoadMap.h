#ifndef _MAP_H
#define _MAP_H

#include <fstream>      // std::ifstream
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <SFML/Graphics.hpp>


class LoadMap 
{
private:
	void split_insert(const std::string& s, char delim, std::vector<int>& v); 
	std::string line;
    std::ifstream* is;
    bool isInLayer = false;
    int layer;



public:
    void createMap(std::string mapName);
    std::vector<std::vector< int >> map;

    int tileswide;
    int tileshigh;
    int tilewidth;
    int tileheight;

    LoadMap();




};



#endif // !_MAP

