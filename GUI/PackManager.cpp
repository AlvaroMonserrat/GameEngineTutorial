#include "PackManager.h"

PackManager* PackManager::s_Instance = nullptr;

void PackManager::AddWidget(Widget* widget, int FRAGMENT)
{
    //Agregar cada widget asociado a una KEY (0: MENU)
    m_Widgets[FRAGMENT].push_back(widget);
}

Widget* PackManager::GetButton(int FRAGMENT, int BUTTON)
{
    return m_Widgets.at(FRAGMENT).at(BUTTON);
}

void PackManager::UpdateAllWidget(int FRAGMENT)
{
    for(int i = 0; i < m_Widgets.at(FRAGMENT).size(); i++)
    {
        m_Widgets.at(FRAGMENT).at(i)->Update();
    }
}

void PackManager::DrawAllWidget(int FRAGMENT)
{
        for(int i = 0; i < m_Widgets.at(FRAGMENT).size(); i++)
    {
        m_Widgets.at(FRAGMENT).at(i)->Draw();
    }
}

