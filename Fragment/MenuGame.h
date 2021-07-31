#ifndef MENUGAME_H
#define MENUGAME_H

#include <vector>
#include "SDL2/SDL.h"
#include "Engine.h"
#include "FragmentGame.h"
#include "Input.h"
#include "Button.h"
#include "Widget.h"

enum{
    START,
    OPTIONS
};

class MenuGame : public FragmentGame
{
    public:
        virtual bool Init();
        virtual bool Exit();
        virtual void Update(float dt);
        virtual void Render();

    private:
        //std::vector<Widget*> m_Widgets;

};

#endif // MENUGAME_H
