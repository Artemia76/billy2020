#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "ResourceDispatcher.h"

class Animation {

public : 

    Animation(int x, int y, int width, int height,int nFrames,  sf::Texture texture) {
        _texture = texture ;
        _nFrames = nFrames; 
        for (int i = 0; i < nFrames; i++) {
            frames.push_back({ x + i * width, y,x + width , height });
           // frames[i] = { x + i * width, y,x + width , height }; 
        }

    }

    void ApplyToSprite(sf::Sprite& s) const {
        s.setTexture(_texture); 
        s.setTextureRect(frames[_iFrame]);
    }

    void Update(float dt) {
        time += dt; 
        while (time >= _holdTime) {
            time -= _holdTime; 
            Advance(); 
        }
    }

private : 
    void Advance() {
        if (++_iFrame >= _nFrames) {
            _iFrame = 0; 
        }
    }

    int _nFrames ;
    int _iFrame = 0; 
    const float _holdTime = 0.15; 
    sf::Texture _texture; 
    std::vector<sf::IntRect> frames; 
    float time = 0.0f; 
};


class Player : public sf::Drawable
{

public:
    Player(const Player&) = delete;
    Player& operator=(const Player&) = delete;

    Player() ;

    void processEvents(float sec);
    void update(sf::Time deltaTime);

    void moveLeft(float mvt); 
    

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void animatePlayer();

    sf::Sprite _character;
    sf::Vector2f _velocity;
    sf::Vector2f _position;
    Animation _animateRight; 
    Animation _animateIdle;
    Animation _animateLeft; 

    bool _is_moving;
    
};

#endif

