#include "Menu.h"

Menu::Menu()
{
    //ctor
}
bool Menu::Init()
{
    m_Ctxt = Engine::GetInstance()->GetRenderer();
    std::cout << "Menu Iniciado!" << std::endl;
    return true;
}

void Menu::Render()
{
    SDL_SetRenderDrawColor(m_Ctxt, 16, 45, 70, 255);
    SDL_RenderClear(m_Ctxt);

    SDL_RenderPresent(m_Ctxt);
}

void Menu::Update()
{

}

bool Menu::Exit()
{
    std::cout << "Exit Menu!" << std::endl;
    return true;
}

void Menu::StartGame()
{
    std::cout << "start game!\n";
}

void Menu::Settings()
{
    std::cout << "Options mode!\n";
}

void Menu::Editor()
{
    std::cout << "Editor mode!\n";
}

void Menu::Quit()
{
    std::cout << "Quit game!\n";
}
