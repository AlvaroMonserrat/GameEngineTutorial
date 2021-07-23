#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include "SDL2/SDL.h"

class Animation
{
public:
    Animation(){}

    void Update();
    void Draw(float x, float y, int spriteWidth, int spriteHeight, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void SetPros(std::string textureID, int spriteRow,  int frameCount, int animSpeed);

private:
    int m_AnimSpeed;
    int m_SpriteRow;
    int m_FrameCount;
    int m_CurrentFrame;
    std::string m_TextureID;

};

#endif // ANIMATION_H
