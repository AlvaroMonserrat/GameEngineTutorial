#include "Engine.h"
#include "TextureManager.h"
#include "Input.h"
#include "Warrior.h"
#include "Enemy.h"
#include "Timer.h"
#include "MapParser.h"
#include "Camera.h"
#include "ObjectFactory.h"
#include "MainGame.h"
#include "MenuGame.h"

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


    //Cargar Mapas
    if(!MapParser::GetInstance()->Load())
    {
        std::cout << "Error al cargar el mapa" << std::endl;
        m_IsRunning = false;
    }

    //Cargar todas las texturas
    if(!TextureManager::GetInstance()->ParseTexture("assets/texture.tml")) return false;

    //Iniciar con Menu
    currentFragment = MENU;

    m_FragmentGames.push_back(new MenuGame());
    m_FragmentGames.push_back(new MainGame());

    for(unsigned int i=0; i != m_FragmentGames.size(); i++)
    {
        if(!m_FragmentGames[i]->Init())
        {
            std::cout << "Error al Iniciar el Juego: " << i <<"\n";
            m_IsRunning = false;

        }
    }


    return m_IsRunning;
}

bool Engine::Clean()
{

    for(unsigned int i=0; i != m_FragmentGames.size(); i++)
    {
        m_FragmentGames[i]->Exit();
    }

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
    //Actualizar tiempo
    float dt = Timer::GetInstance()->GetDeltaTime();

    m_FragmentGames[currentFragment]->Update(dt);

}

void Engine::Render()
{
    //Color de Fondo del juego
    SDL_SetRenderDrawColor(m_Renderer, 124, 210, 254, 255);
    SDL_RenderClear(m_Renderer);

    m_FragmentGames[currentFragment]->Render();

    SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
    //Gestionar Eventos del Juego
    Input::GetInstance()->Listen();
}

void Engine::ChangeFragment(int fragment)
{
    currentFragment = fragment;
}

Engine::Engine()
{
    std::cout << "El motor de Juego se ha iniciado\n";
}

