#include "Engine.h"
#include "TextureManager.h"
#include "Input.h"
#include "Warrior.h"
#include "Timer.h"
#include "MapParser.h"
#include "Camera.h"

Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{

    //Bandera de inicialización
    m_IsRunning = true;

    if( SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
    {
        SDL_Log("Error al iniciar SDL libraries: %s", SDL_GetError());
        m_IsRunning = false;

    }
    else
    {

        SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
        //Crear la ventana
        m_Window = SDL_CreateWindow("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);

        if( m_Window == nullptr)
        {
            SDL_Log("La ventana no pudo ser creada: %s", SDL_GetError());
            m_IsRunning = false;
        }
        else
        {
            //Obtener Renderer
            m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if(m_Renderer == nullptr)
            {
                SDL_Log("El Renderer no pudo ser creado: %s", SDL_GetError());
                m_IsRunning = false;
            }
        }
    }


    if(!MapParser::GetInstance()->Load())
    {
        std::cout << "Error al cargar el mapa" << std::endl;
        m_IsRunning = false;
    }


    m_LevelMap = MapParser::GetInstance()->GetMaps("map");

    if(!TextureManager::GetInstance()->ParseTexture("assets/texture.tml")) m_IsRunning = false;


    Warrior* player = new Warrior(new Properties("player", 100, 200, 136, 96));

    m_GameObjects.push_back(player);

    Camera::GetInstance()->SetTarget(player->GetOrigin());

    return m_IsRunning;
}

bool Engine::Clean()
{

    for(unsigned int i=0; i!=m_GameObjects.size(); i++)
    {
        m_GameObjects[i]->Clean();
    }

    TextureManager::GetInstance()->Clean();
    MapParser::GetInstance()->Clean();

    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    m_Renderer = nullptr;
    m_Window = nullptr;

    IMG_Quit();
    SDL_Quit();

    return true;
}

void Engine::Quit()
{
    m_IsRunning = false;

}

void Engine::Update()
{
    float dt = Timer::GetInstance()->GetDeltaTime();
    m_LevelMap->Update();

    for(unsigned int i=0; i!=m_GameObjects.size(); i++)
    {
        m_GameObjects[i]->Update(dt);
    }

    Camera::GetInstance()->Update(dt);
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, 124, 210, 254, 255);
    SDL_RenderClear(m_Renderer);

    TextureManager::GetInstance()->Draw("bg", 0, 0, 1980, 1080, 1.5, 1.5, 0.4);
    m_LevelMap->Render();

    for(unsigned int i=0; i!=m_GameObjects.size(); i++)
    {
        m_GameObjects[i]->Draw();
    }



    SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
    Input::GetInstance()->Listen();
}

Engine::Engine()
{

}

