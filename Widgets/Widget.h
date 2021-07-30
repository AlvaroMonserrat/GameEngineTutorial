#ifndef WIDGET_H
#define WIDGET_H

#include <SDL2/SDL.h>

class Widget
{
    public:
        virtual void Draw()=0;
        virtual void Update()=0;
        virtual void Clean()=0;

    protected:
        SDL_Rect m_Box;

};

#endif // WIDGET_H
