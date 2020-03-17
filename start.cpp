#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "Game.h"
#include "Map.h"




int main()
{

    //load assets 
    //load maps 
    //std::string line; 
    //std::ifstream is("assets/maps/tilemap.txt");
    //lire le nombre de tuile en largeur et en hauteur stocké la taille des tuilles 
    //si la ligne commence par layer stocké dans layer rajouté dans un tableau toutes les tuiles 

    Map map; 
    map.createMap("assets/maps/tilemap.txt"); 
    Game game; 
    game.run(60); 

    //affichez la carte a l ecran 

    return 0;
}