#ifndef RESSOURCEDISPATCHER_H
#define RESSOURCEDISPATCHER_H

//stock toutes les ressources 

#include "RessourceManager.h"
#include <SFML/Graphics.hpp>


enum TextureName { player, map };

class ResourceDispatcher
{
public : 
	
	static RessourceManager rDispatcherTexture ; 
	

	static void initialize(); 
	static void initTextures();


	

};


//TextureName ResourceDispatcher::textureName; 


#endif

