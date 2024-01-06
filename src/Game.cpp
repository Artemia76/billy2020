#include "Game.h"
#include "ResourceDispatcher.h"

///
/// \brief Game::Game
///
Game::Game() : _window(sf::VideoMode(1200, 800), "Plateformer 0.1")
{

}

///
/// \brief Game::init
///
void Game::init()
{
    ResourceDispatcher::initTextures();
    map.createMap("assets/maps/tilemap.txt");
    tMap.init(map, ResourceDispatcher::rDispatcherTexture.get(TextureName::map));
    tMap.load();
    tMap.loadLayer1();
    _player.init();
}

///
/// \brief Game::run
/// \param frame_per_seconds
///
void Game::run(int frame_per_seconds)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / frame_per_seconds);

	while (_window.isOpen())
	{
		processEvents();
		bool repaint = false;
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			repaint = true;
			update(TimePerFrame);
		}
		if (repaint)
			render();
	}

}

///
/// \brief Game::runWithFixedTimeSteps
/// \param frame_per_seconds
///
void Game::runWithFixedTimeSteps(int frame_per_seconds)
{
}

///
/// \brief Game::runWithVariableTimeSteps
///
void Game::runWithVariableTimeSteps()
{
}

///
/// \brief Game::runWithMinimumTimeSteps
/// \param minimum_frame_per_seconds
///
void Game::runWithMinimumTimeSteps(int minimum_frame_per_seconds)
{
}

///
/// \brief Game::processEvents
///
void Game::processEvents()
{

    sf::Event event;
	while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
        }
        /*else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {
                _player.moveLeft(1.0f);
            }

        }*/
    }

}

///
/// \brief Game::update
/// \param deltaTime
///
void Game::update(sf::Time deltaTime)
{
    _player.update(deltaTime);
}

///
/// \brief Game::render
///
void Game::render()
{
    _window.clear();
    _window.draw(_player);
    _window.draw(tMap);
    _window.display();
}
