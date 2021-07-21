#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "SDL2/SDL.h"
#include <vector>
#include "TileLayer.h"
#include "GameMap.h"

class CollisionHandler
{
    public:
        bool CheckCollision(SDL_Rect a, SDL_Rect b);
        bool MapCollision(SDL_Rect a);

        inline static CollisionHandler* GetInstance(){ return s_Instance = (s_Instance != nullptr) ? s_Instance : new CollisionHandler();}

    private:
        CollisionHandler();
        static CollisionHandler* s_Instance;

        TileMap m_CollisionTileMap;
        TileLayer* m_CollisionLayer;

};

#endif // COLLISIONHANDLER_H
