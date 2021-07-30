#ifndef MENUGAME_H
#define MENUGAME_H

#include "SDL2/SDL.h"
#include "Engine.h"
#include "FragmentGame.h"
#include "Input.h"
#include "Button.h"

class MenuGame : public FragmentGame
{
    public:
        virtual bool Init();
        virtual bool Exit();
        virtual void Update(float dt);
        virtual void Render();

    private:
        Button* btnStart;
        Button* btnOption;
};

#endif // MENUGAME_H
