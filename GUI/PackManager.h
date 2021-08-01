#ifndef PACKMANAGER_H
#define PACKMANAGER_H

#include <map>
#include <vector>
#include <SDL2/SDL.h>
#include "Widget.h"

class PackManager
{
    public:
        static PackManager* GetInstance()
        {
            return s_Instance = (s_Instance != nullptr) ? s_Instance : new PackManager();
        }

        void AddWidget(Widget*, int FRAGMENT);
        Widget* GetButton(int FRAGMENT, int BUTTON);

        void UpdateAllWidget(int FRAGMENT);
        void DrawAllWidget(int FRAGMENT);

    private:
        PackManager(){};

        static PackManager* s_Instance;
        std::map<int, std::vector<Widget*>> m_Widgets;

};

#endif // PACKMANAGER_H
