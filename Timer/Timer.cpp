#include "Timer.h"
#include "SDL2/SDL.h"

Timer* Timer::s_Instance = nullptr;

void Timer::Tick()
{
    m_DeltaTime = (SDL_GetTicks() - m_LastTimer) * (TARGET_FPS / 1000.0f);

    if(m_DeltaTime > TARGET_DELTATIME)
    {
        m_DeltaTime = TARGET_DELTATIME;
    }

    m_LastTimer =  SDL_GetTicks();

}

