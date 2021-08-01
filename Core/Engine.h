#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "FragmentGame.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

enum{MENU, GAME};

class Engine
{
public:
    static Engine* GetInstance()
    {
        return s_Instance = (s_Instance != nullptr) ? s_Instance : new Engine();
    }

    bool Init();
    bool Clean();
    void Quit();

    void Update();
    void Render();
    void Events();

    //void PopFragment();
    //void PushFragment(FragmentGame* current);
    void ChangeFragment(int fragment);

    //inline GameMap* GetMap(){ return m_LevelMap; }

    inline bool isRunning(){ return m_IsRunning; }
    inline bool ExitGame(){ m_IsRunning = false; }

    inline SDL_Renderer* GetRenderer(){ return m_Renderer; }

private:
    Engine();
    bool m_IsRunning;

    SDL_Window* m_Window;
    SDL_Renderer* m_Renderer;
    SDL_Surface* m_SurfaceScreen;

    static Engine* s_Instance;

    std::vector<FragmentGame*> m_FragmentGames;
    int currentFragment;


};

#endif // ENGINE_H
