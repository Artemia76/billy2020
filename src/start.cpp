#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "ResourceDispatcher.h"
#include "Game.h"




int main()
{

    //load assets 
    //load maps 
    //std::string line; 
    //std::ifstream is("assets/maps/tilemap.txt");
    //lire le nombre de tuile en largeur et en hauteur stock� la taille des tuilles 
    //si la ligne commence par layer stock� dans layer rajout� dans un tableau toutes les tuiles 
  
    
    ResourceDispatcher::initTextures();

    Game* game = new Game(); 

    game->init(); 
   
    game->run(60); 

    //affichez la carte a l ecran 

    return 0;
}