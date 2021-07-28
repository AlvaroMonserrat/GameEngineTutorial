#ifndef PLAY_H
#define PLAY_H

#include "GameState.h"
#include "GameMap.h"
#include "GameObject.h"
#include "Engine.h"

class Play : public GameState
{
    public:
        Play();
        void Events();
        virtual bool Init();
        virtual bool Exit();
        virtual void Update();
        virtual void Render();

    private:
        static void OpenMenu();
        static void PauseGame();

    private:
        bool m_EditMode;
        GameMap* m_LevelMap;
        std::vector<GameObject*> m_GameObjects;

};

#endif // PLAY_H
