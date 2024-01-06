#include "Animation.h"

Animation::Animation()
{
    
}

void Animation::Init(int x, int y, int width, int height,int nFrames,  sf::Texture texture)
{
    _texture = texture ;
    _nFrames = nFrames;
    for (int i = 0; i < nFrames; i++)
    {
        frames.push_back({ x + i * width, y,x + width , height });
        // frames[i] = { x + i * width, y,x + width , height };
    }

}

void Animation::ApplyToSprite(sf::Sprite& s) const
{
    s.setTexture(_texture);
    s.setTextureRect(frames[_iFrame]);
}

void Animation::Update(float dt)
{
    time += dt;
    while (time >= _holdTime)
    {
        time -= _holdTime;
        Advance();
    }
}

void Animation::Advance()
{
    if (++_iFrame >= _nFrames)
    {
        _iFrame = 0;
    }
}
