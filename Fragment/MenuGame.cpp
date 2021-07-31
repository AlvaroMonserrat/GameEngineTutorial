#include "MenuGame.h"
#include "PackManager.h"

bool MenuGame::Init()
{
    //Obtener Render principal
    m_Ctxt = Engine::GetInstance()->GetRenderer();

    //Agregar Boton
    PackManager::GetInstance()->AddWidget(new Button("btn_start", 0, 0, 300, 200, 0.5), MENU);
    PackManager::GetInstance()->AddWidget(new Button("btn_start", 0, 200, 300, 200, 0.5), MENU);

    return true;
}

bool MenuGame::Exit()
{
    return true;
}

void MenuGame::Update(float dt)
{
    if(Input::GetInstance()->GetKeyDown(SDL_SCANCODE_M))
    {
        Engine::GetInstance()->ChangeFragment(GAME);
        SDL_Delay(200);
    }

    if(PackManager::GetInstance()->GetButton(MENU, START)->isClicked())
    {
        Engine::GetInstance()->ChangeFragment(GAME);
        SDL_Delay(200);
    }

    PackManager::GetInstance()->UpdateAllWidget(MENU);


}
void MenuGame::Render()
{
    SDL_SetRenderDrawColor(m_Ctxt, 69, 90, 100, 255);
    SDL_RenderClear(m_Ctxt);

    PackManager::GetInstance()->DrawAllWidget(MENU);

}
