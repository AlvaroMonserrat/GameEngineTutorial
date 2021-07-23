#include "Animation.h"
#include "TextureManager.h"
#include <iostream>

void Animation::Update()
{
    m_CurrentFrame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
}

void Animation::Draw(float x, float y, int spriteWidth, int spriteHeight, SDL_RendererFlip flip)
{

    TextureManager::GetInstance()->DrawFrame(m_TextureID, x, y, spriteWidth, spriteHeight, m_SpriteRow, m_CurrentFrame, flip);
}

void Animation::SetPros(std::string textureID, int spriteRow, int frameCount, int animSpeed)
{
    m_AnimSpeed = animSpeed;
    m_TextureID = textureID;
    m_SpriteRow = spriteRow;
    m_FrameCount = frameCount;
}
