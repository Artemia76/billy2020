#include <SFML/Graphics.hpp>
#include <fstream>      // std::ifstream
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<int> split(const std::string& s, char delim, std::vector<int>& v) {
   
    std::stringstream ss(s);
    std::string number;
    while (std::getline(ss, number, delim)) {
        v.push_back(std::stoi(number));
    }
   
}


int main()
{

    //load assets 
    //load maps 
    std::string line; 
    std::ifstream is("assets/maps/tilemap.txt");
    //lire le nombre de tuile en largeur et en hauteur stocké la taille des tuilles 
    //si la ligne commence par layer stocké dans layer rajouté dans un tableau toutes les tuiles 

    auto extract_number = [](std::string l)
    {
        int c = l.find(' '); 
        return l.substr((int)c + 1); 
    };

  


  

    int tileswide; 
    int tileshigh; 
    int tilewidth;
    int tileheight; 
    std::vector<std::vector< int >> map;
    bool isInLayer = false; 
    int layer; 

    if (is.is_open())
    {
        for (int i = 0; getline(is, line); i++)
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
                            for (size_t i = 0; i < line.size(); i++)
                            {
                               
                                if (line.substr(i, i + 2) == "-1")
                                {
                                    
                                    map[layer].push_back(-1);
                                   
                                }
                                else if (line[i] != ',')
                                {
                                    map[layer].push_back((int)line[i] - 48);
                                }
                            }
                        }

                    }

                    if (line == "" && isInLayer) {
                        isInLayer = false;
                    }



                break; 
            }


          /*  std::cout << line << '\n';
            int c = line.find(' '); 
            std::cout << "the first space found was in " << c << '\n';
            std::string str2 = line.substr((int)c + 1);
            std::cout << str2 << '\n';*/
           

        }
        is.close();
    }

    //process maps 

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}