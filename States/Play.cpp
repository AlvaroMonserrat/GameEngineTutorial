#include "Play.h"
#include "Engine.h"

Play::Play()
{
    //ctor
}

bool Play::Init()
{
    m_EditMode = false;
    m_Ctxt = Engine::GetInstance()->GetInstance()->GetRenderer();

}

void Play::Events()
{

}



bool Play::Exit()
{

}

void Play::Update()
{

}

void Play::Render()
{

}

void Play::OpenMenu()
{

}

void Play::PauseGame()
{

}
