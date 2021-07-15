#include "Engine.h"
#include "TextureManager.h"

Engine* Engine::s_Instance = nullptr;

bool Engine::Init()
{
    //Bandera de inicialización
    m_IsRunning = true;

    if( SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0){
        SDL_Log("Error al iniciar SDL libraries: %s", SDL_GetError());
        m_IsRunning = false;
    }else{
        //Crear la ventana
        m_Window = SDL_CreateWindow("GameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if( m_Window == nullptr){
            SDL_Log("La ventana no pudo ser creada: %s", SDL_GetError());
            m_IsRunning = false;
        }else{
            //Obtener Renderer
            m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

            if(m_Renderer == nullptr)
            {
                SDL_Log("El Renderer no pudo ser creado: %s", SDL_GetError());
                m_IsRunning = false;
            }
        }
    }

    if(!TextureManager::GetInstance()->Load("homer", "assets/images/homer.bmp"))
    {
        m_IsRunning = false;
    }

    return m_IsRunning;
}

bool Engine::Clean()
{
    TextureManager::GetInstance()->Clean();
    SDL_DestroyRenderer(m_Renderer);
    SDL_DestroyWindow(m_Window);
    m_Renderer = nullptr;
    m_Window = nullptr;

    IMG_Quit();
    SDL_Quit();
}

void Engine::Quit()
{
    m_IsRunning = false;

}

void Engine::Update()
{

}

void Engine::Render()
{
    SDL_SetRenderDrawColor(m_Renderer, 124, 210, 254, 255);
    SDL_RenderClear(m_Renderer);

    TextureManager::GetInstance()->Draw("homer", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_RenderPresent(m_Renderer);
}

void Engine::Events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            Quit();
            break;
    }
}

Engine::Engine()
{

}

