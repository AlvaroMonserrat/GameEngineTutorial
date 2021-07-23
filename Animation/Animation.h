#ifndef ANIMATION_H
#define ANIMATION_H

#include <string>
#include "SDL2/SDL.h"

class Animation
{
public:
    Animation(bool repeat=true){ m_IsEnded = false;}

    virtual void Update(float dt)=0;
    inline bool isEnded(){return m_IsEnded;}

    protected:
        bool m_Repeat;
        bool m_IsEnded;
        int m_CurrentFrame;
};

#endif // ANIMATION_H
