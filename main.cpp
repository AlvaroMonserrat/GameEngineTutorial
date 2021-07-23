#include <iostream>
#include "Engine.h"
#include "Timer.h"

using namespace std;


int main()
{
    Engine* gameEngine = Engine::GetInstance();
    Timer* gameTimer = Timer::GetInstance();

    gameEngine->Init();

    while(gameEngine->isRunning())
    {
        gameEngine->Events();
        gameEngine->Update();
        gameEngine->Render();
        gameTimer->Tick();
    }

    gameEngine->Clean();

    return 0;
}

