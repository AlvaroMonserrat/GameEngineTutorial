#ifndef WIDGET_H
#define WIDGET_H

#include <SDL2/SDL.h>


//y: top, bottom, center
//x: left, right, center
struct Parameters
{

    public:
        Parameters(std::string layoutGravityX="left", std::string layoutGravityY="top")
        {
            m_LayoutGravityX = layoutGravityX;
            m_LayoutGravityY = layoutGravityY;
        }

    public:
        std::string m_LayoutGravityX;
        std::string m_LayoutGravityY;
};

class Widget
{
    public:
        virtual void Draw()=0;
        virtual void Update()=0;
        virtual void Clean()=0;
        virtual bool isClicked()=0;

    protected:
        SDL_Rect m_Box;

};

#endif // WIDGET_H
