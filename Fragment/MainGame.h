#ifndef MAINGAME_H
#define MAINGAME_H

#include <vector>
#include "Engine.h"
#include "Input.h"
#include "TextureManager.h"
#include "MapParser.h"
#include "GameObject.h"
#include "ObjectFactory.h"
#include "GameMap.h"
#include "FragmentGame.h"
#include "Camera.h"

class MainGame : public FragmentGame
{
    public:
        virtual bool Init();
        virtual bool Exit();
        virtual void Update(float dt);
        virtual void Render();

    private:
        GameMap* m_LevelMap;
        std::vector<GameObject*> m_GameObjects;

};

#endif // MAINGAME_H
