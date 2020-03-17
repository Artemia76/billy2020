#ifndef _MAP_H
#define _MAP_H

#include <fstream>      // std::ifstream
#include <iostream>
#include <string>
#include <vector>
#include <sstream>


class Map
{
private:
	void split_insert(const std::string& s, char delim, std::vector<int>& v); 
	std::string line;
	std::ifstream* is;
    int tileswide;
    int tileshigh;
    int tilewidth;
    int tileheight;  
    bool isInLayer = false;
    int layer;

public: 
    void createMap(std::string mapName); 
    std::vector<std::vector< int >> map;

    Map(); 
	



};



#endif // !_MAP

