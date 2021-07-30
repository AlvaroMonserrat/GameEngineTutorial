#include "MainGame.h"


bool MainGame::Init()
{
    //Obtener Render principal
    m_Ctxt = Engine::GetInstance()->GetRenderer();
    m_LevelMap = MapParser::GetInstance()->GetMaps("map");

    //Mapa del Nivel 1
    //m_LevelMap = MapParser::GetInstance()->GetMaps("map");

    Properties* propsPlayer = new Properties("player", 100, 200, 136, 96);
    GameObject* player = ObjectFactory::GetInstance()->CreateObject("PLAYER", propsPlayer);
    GameObject* boss = ObjectFactory::GetInstance()->CreateObject("BOSS",
    new Properties("boss_idle", 800, 100, 600, 500, SDL_FLIP_HORIZONTAL));

    m_GameObjects.push_back(player);
    m_GameObjects.push_back(boss);

    Camera::GetInstance()->SetTarget(player->GetOrigin());

    return true;
}

void MainGame::Update(float dt)
{
    //Actualizar mapa del juego
    m_LevelMap->Update();

    //Actualizar objetos del juego
    for(unsigned int i=0; i!=m_GameObjects.size(); i++)
    {
        m_GameObjects[i]->Update(dt);
    }

    //Actualizar Cámara
    Camera::GetInstance()->Update(dt);

    if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_M))
    {
        Engine::GetInstance()->ChangeFragment(MENU);
        SDL_Delay(200);
    }

}

void MainGame::Render()
{
    //Renderizar Fondo
    TextureManager::GetInstance()->Draw("bg", 0, 0, 1980, 1080, 1.5, 1.5, 0.4);

    //Renderizar Mapa
    m_LevelMap->Render();

    //Rendizar objetos del Mapa
    for(unsigned int i=0; i!=m_GameObjects.size(); i++)
    {

        m_GameObjects[i]->Draw();

    }
}


bool MainGame::Exit()
{
    //Limpiar objectos de del juego
    for(unsigned int i=0; i!=m_GameObjects.size(); i++)
    {
        m_GameObjects[i]->Clean();
    }

    //Limpiar Gestor de Texturas
    TextureManager::GetInstance()->Clean();

    //Limmpiar Mapas
    MapParser::GetInstance()->Clean();

    return true;
}
