#include "Map.h"


void Map::split_insert(const std::string& s, char delim, std::vector<int>& v)
{

    std::stringstream ss(s);
    std::string number;
    while (std::getline(ss, number, delim)) {
        v.push_back(std::stoi(number));
    }
}

void Map::createMap(std::string mapName)
{
    is = new std::ifstream(mapName);

    auto extract_number = [](std::string l)
    {
        int c = l.find(' ');
        return l.substr((int)c + 1);
    };


    if (is->is_open())
    {
        for (int i = 0; getline(*is, line); i++)
        {

            //cas 1
            switch (i)
            {
            case 0:
                tileswide = std::stoi(extract_number(line));
                break;
            case 1:
                tileshigh = std::stoi(extract_number(line));
                break;
            case 2:
                tilewidth = std::stoi(extract_number(line));
                break;
            case 3:
                tileheight = std::stoi(extract_number(line));
                break;

            default:
                if (line != "") {
                    if (!isInLayer)
                    {
                        layer = std::stoi(extract_number(line));
                        map.push_back(std::vector<int>());
                        isInLayer = true;
                    }
                    else {

                        std::cout << line << '\n';
                        split_insert(line, ',', map[layer]);

                    }

                }

                if (line == "" && isInLayer) {
                    isInLayer = false;
                }



                break;
            }


        }
        is->close();
    }
    
}

Map::Map()
{
   
}
