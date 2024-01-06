#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "LoadMap.h"
#include "TilesMap.h"


class Game 
    {
    public:
        //non copyable class
        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;

        Game(); //< constructor

        void init(); 
        void run(int frame_per_seconds);
     
        void runWithFixedTimeSteps(int frame_per_seconds = 60);
        void runWithVariableTimeSteps();
        void runWithMinimumTimeSteps(int minimum_frame_per_seconds = 30);
        


    private:

        void processEvents();//< Process events
        void update(sf::Time deltaTime); 
        void render();//< draw all the stuff

        sf::RenderWindow _window; //< the window use to display the game
       

        Player _player; 
        LoadMap map;
        TilesMap tMap; 
       

    };

#endif

