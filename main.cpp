#include <iostream>
#include "Engine.h"

using namespace std;


int main(){

    Engine::GetInstance()->Init();

    while(Engine::GetInstance()->isRunning())
    {
        Engine::GetInstance()->Events();
        Engine::GetInstance()->Update();
        Engine::GetInstance()->Render();
    }

    Engine::GetInstance()->Clean();

    return 0;
}

