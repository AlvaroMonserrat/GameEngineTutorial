#include "Warrior.h"
#include "TextureManager.h"
#include "SDL2/SDL.h"
#include "Input.h"


Warrior::Warrior(Properties* props) : Character(props)
{
    m_RigidBody = new RigidBody();
    m_Animation = new Animation();
    m_Animation->SetPros(m_TextureID, 1, 8, 80);
}

void Warrior::Draw()
{
    m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Warrior::Update(float dt)
{
    m_Animation->SetPros("player", 1, 6, 80);
    m_RigidBody->UnSetForce();

    if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A))
    {
        m_RigidBody->ApplyForceX(5*BACKWARD);
        m_Animation->SetPros("player_run", 1, 8, 80, SDL_FLIP_HORIZONTAL);
    }

    if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D))
    {
        m_RigidBody->ApplyForceX(5*FORWARD);
        m_Animation->SetPros("player_run", 1, 8, 80);
    }

    m_RigidBody->Update(dt);

    m_Transform->TranslateX(m_RigidBody->Position().X);
    //m_Transform->TranslateY(m_RigidBody->Position().Y);


    m_Animation->Update();
}

void Warrior::Clean()
{
    TextureManager::GetInstance()->Clean();
}
