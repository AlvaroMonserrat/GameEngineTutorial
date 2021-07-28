#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>
#include <iostream>
#include "GameState.h"

class Menu : public GameState
{
    public:
        Menu();
        virtual bool Init();
        virtual bool Exit();
        virtual void Update();
        virtual void Render();

    private:
        static void StartGame();
        static void Settings();
        static void Editor();
        static void Quit();

    private:
        SDL_Renderer* m_Ctxt;

};

#endif // MENU_H
