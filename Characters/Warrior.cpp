#include "Warrior.h"
#include "TextureManager.h"
#include "SDL2/SDL.h"



Warrior::Warrior(Properties* props) : Character(props)
{
    m_Row = 1;
    m_FrameCount = 6;
    m_AnimSpeed = 60;
}

void Warrior::Draw()
{
    TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Row, m_Frame);
}

void Warrior::Update(float dt)
{
    m_Frame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount;
}

void Warrior::Clean()
{
    TextureManager::GetInstance()->Clean();
}
