#ifndef FRAGMENTGAME_H
#define FRAGMENTGAME_H

#include <SDL2/SDL.h>

class FragmentGame
{
    public:
        virtual bool Init() = 0;
        virtual bool Exit() = 0;
        virtual void Update(float dt) = 0;
        virtual void Render() = 0;
    protected:
        SDL_Renderer* m_Ctxt;
};

#endif // FRAGMENTGAME_H
