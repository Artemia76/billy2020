#include "ResourceDispatcher.h"

RessourceManager ResourceDispatcher::rDispatcherTexture;

void ResourceDispatcher::initialize()
{
	initTextures(); 

}

void ResourceDispatcher::initTextures()
{
	
	rDispatcherTexture.load(TextureName::player,"assets/images/billyanim.png"); 
	rDispatcherTexture.load(TextureName::map, "assets/images/tilemap.png");
}
