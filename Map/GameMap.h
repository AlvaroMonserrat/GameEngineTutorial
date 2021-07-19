#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "Layer.h"

class GameMap
{
    public:
        void Render()
        {
            for(unsigned int = 0; i < m_MapLayers.size(); i++)
            {
                m_MapLayers[i]->Render();
            }
        }

        void Update()
        {
            for(unsigned int = 0; i < m_MapLayers.size(); i++)
            {
                m_MapLayers[i]->Update();
            }
        }

        std::vector<Layer*> GetMapLayers(){return m_MapLayers;}

    private:
        std::vector<Layer*> m_MapLayers;
};

#endif // GAMEMAP_H
