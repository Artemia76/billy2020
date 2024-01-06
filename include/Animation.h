#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>

class Animation {

public :

    Animation();

    void ApplyToSprite(sf::Sprite& s) const;

    void Init(int x, int y, int width, int height,int nFrames,  sf::Texture texture);
    void Update(float dt);

private :
    void Advance();

    int _nFrames ;
    int _iFrame = 0;
    const float _holdTime = 0.15;
    sf::Texture _texture;
    std::vector<sf::IntRect> frames;
    float time = 0.0f;
};

#endif // ANIMATION_H
