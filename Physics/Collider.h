#ifndef COLLIDER_H
#define COLLIDER_H

#include "SDL2/SDL.h"
#include "Camera.h"
#include "CollisionHandler.h"

using Box = SDL_Rect;

class Collider
{
    public:
        inline Box Get(){ return m_Box;}
        inline void SetBuffer(int x, int y, int w, int h){m_Buffer = {x, y, w, h};}

        void Set(int x, int y, int w, int h)
        {
            m_Box = { x - m_Buffer.x, y - m_Buffer.y, w - m_Buffer.w, h - m_Buffer.h};
        }

        bool ColliderWithMap()
        {
            return CollisionHandler::GetInstance()->MapCollision(m_Box);
        }

        void Draw()
        {
            Vector2D cam = Camera::GetInstance()->GetPosition();
            Box box = {(int)(m_Box.x - cam.X), (int)(m_Box.y - cam.Y),  m_Box.w, m_Box.h};
            SDL_RenderDrawRect(Engine::GetInstance()->GetRenderer(), &box);
        }

    private:
        Box m_Box;
        Box m_Buffer;
};

#endif // COLLIDER_H
